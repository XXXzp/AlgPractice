#include<vector>
bool Filter3by1(std::vector<BYTE>* image, std::vector<double>* ifilter, const WORD&height, const WORD &width) {

    std::vector<double> &filter = *ifilter;
    std::vector<BYTE> &input = *image;
    //Ϊ�˼򻯣�������߽�
    for (size_t i = 1; i < height - 1; i++) {
        for (size_t j = 1; j < width - 1; j++) {
            input[i*width + j] = filter[0] * input[i*width + j - 1] + filter[1] * input[i*width + j] + filter[2] * input[i*width + j + 1];
        }
    }
    return true;
}
bool Filter3by3(std::vector<BYTE>* image,std::vector<double>* ifilter, const WORD&height, const WORD &width) {
    
    std::vector<double> &filter = *ifilter;
    std::vector<BYTE> &input = *image;
    std::vector<BYTE> copyOfInput = *image;
    
    double temp = 0;
    //Ϊ�˼򻯣�������߽�
    for (size_t i = 1; i < height - 1; i++) {
        for (size_t j = 1; j < width - 1; j++) {
            temp =
                filter[0] * input[(i - 1)*width + j - 1] + filter[1] * input[(i - 1)*width + j] + filter[2] * input[(i - 1)*width + j + 1] +
                filter[3] * input[i*width + j - 1] + filter[4] * input[i*width + j] + filter[5] * input[i*width + j + 1] +
                filter[6] * input[(i + 1)*width + j - 1] + filter[7] * input[(i + 1)*width + j] + filter[8] * input[(i + 1)*width + j + 1];
            //��֤�������ڷ�Χ��
            if (temp < 0) {
                copyOfInput[i*width + j] = 0;
            }else {
                if (temp > 255) {
                    copyOfInput[i*width + j] = 255;
                } else {
                    copyOfInput[i*width + j] = temp;
                }
            }
        }
    }
    input.assign(copyOfInput.begin(), copyOfInput.end());
    return true;
}