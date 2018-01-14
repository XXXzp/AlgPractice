#include<vector>
//gamma矫正
bool gammaCorrect(std::vector<BYTE> *iMtx, const WORD &height, const WORD &width, const float &gamma) {
    std::vector<BYTE> &imageMtx = *iMtx;

    BYTE lut[256];
    BYTE lut_temp = 0;
    for (int i = 0; i < 256; i++) {
        lut[i] = pow((float)(i / 255.0), gamma) * 255.0;
    }
    //先归一化，i/255,然后进行预补偿(i/255)^fGamma,最后进行反归一化(i/255)^fGamma*255  
    for (size_t j = 0; j < height; j++) {
        for (size_t k = 0; k < width; k++) {
            lut_temp = lut[imageMtx[width*j + k]];
            imageMtx[width*j + k] = lut_temp;//将image设置为新的灰度值
        }
    }
    return true;
}