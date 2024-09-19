#include "BMP.h"
int main(int argc, char *argv[]) {
  BMP_Reader bmpImage;
  for (int i = 0; i < argc; i++) {
    if (bmpImage.openBMP(argv[i])) {
      bmpImage.displayBMP();
    }
  }
  return 0;
}
