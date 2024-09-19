#ifndef BMP_H
#define BMP_H
#include <cstdint>
#include <iostream>
#include <fstream>
#include <string>

#pragma pack(push, 1)
struct BITMAPFILEHEADER {
    uint16_t bfType;      // Тип файла; должно быть 'BM'
    uint32_t bfSize;      // Размер файла в байтах
    uint16_t bfReserved1; // Зарезервировано; должно быть 0
    uint16_t bfReserved2; // Зарезервировано; должно быть 0
    uint32_t bfOffBits;   // Смещение до начала данных изображения
};

// Заголовок информации о BMP
struct BITMAPINFOHEADER {
    uint32_t biSize;          // Размер этой структуры
    int32_t  biWidth;         // Ширина изображения в пикселях
    int32_t  biHeight;        // Высота изображения в пикселях
    uint16_t biPlanes;        // Количество цветовых плоскостей; должно быть 1
    uint16_t biBitCount;      // Глубина цвета
    uint32_t biCompression;   // Тип сжатия
    uint32_t biSizeImage;     // Размер изображения в байтах
    int32_t  biXPelsPerMeter;  // Горизонтальная разрешающая способность
    int32_t  biYPelsPerMeter;  // Вертикальная разрешающая способность
    uint32_t biClrUsed;       // Количество используемых цветов
    uint32_t biClrImportant;   // Количество важных цветов
};

#pragma pack(pop)

class BMP_Reader
{
private:
    uint8_t* image_data;
    int32_t width;
    int32_t height;

public:
    BMP_Reader();
    ~BMP_Reader();

    bool openBMP(const std::string &fileName);
    void displayBMP();
    void closeBMP();
};


#endif
