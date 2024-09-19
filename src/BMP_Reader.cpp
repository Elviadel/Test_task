#include "BMP.h"

BMP_Reader::BMP_Reader() : image_data(nullptr), width(0), height(0) {}

BMP_Reader::~BMP_Reader() { closeBMP(); }

bool BMP_Reader::openBMP(const std::string &fileName) {
  std::ifstream file(fileName, std::ios::binary);
  if (!file) {
    std::cerr << "Не удалось найти файл: " << fileName << std::endl;
    return false;
  }

  BITMAPFILEHEADER fileHeader;
  BITMAPINFOHEADER infoHeader;

  file.read(reinterpret_cast<char *>(&fileHeader), sizeof(fileHeader));
  if (fileHeader.bfType != 0x4D42) {
    std::cerr << "Не верный формат файла." << std::endl;
    return false;
  }

  file.read(reinterpret_cast<char *>(&infoHeader), sizeof(infoHeader));

  width = infoHeader.biWidth;
  height = infoHeader.biHeight;

  file.seekg(fileHeader.bfOffBits, std::ios::beg);

  size_t pixelArraySize = width * height * (infoHeader.biBitCount / 8);
  image_data = new uint8_t[pixelArraySize];

  file.read(reinterpret_cast<char *>(image_data), pixelArraySize);
  file.close();
  return true;
}

void BMP_Reader::displayBMP() {
  if (!image_data) {
    std::cerr << "Изображение не загружено." << std::endl;
    return;
  }

  for (int y = height - 1; y >= 0; --y) {
    for (int x = 0; x < width; ++x) {
      uint8_t *pixel = image_data + (y * width + x) * (3);
      uint8_t blue = pixel[0];
      uint8_t green = pixel[1];
      uint8_t red = pixel[2];
      if (red <= 10 && green <= 10 && blue <= 10) {
        std::cout << "#";
      } else if (red >= 240 && green >= 240 && blue >= 240) {
        std::cout << " ";
      } else {
        std::cerr << pixel[2] << std::endl;
        std::cerr << "Изображение цветное" << std::endl;
        return;
      }
    }
    std::cout << std::endl;
  }
}
void BMP_Reader::closeBMP() {
  if (image_data) {
    delete[] image_data;
    image_data = nullptr;
    width = height = 0;
  }
}
