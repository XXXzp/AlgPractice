#include<vector>

BYTE get_scale_value(std::vector<BYTE>* input_img,const WORD& height, const WORD &width, float raw_i, float raw_j)
{
    std::vector<BYTE> &inputIm = *input_img;
    int i = raw_i;
    int j = raw_j;
    float u = raw_i - i;
    float v = raw_j - j;

    //ע�⴦��߽����⣬����Խ��
    if (i + 2 >= height || j + 2 >= width) {
        return inputIm[i*width+j];
    }

    BYTE x1 = inputIm[i*width+j];  //f(i,j)
    BYTE x2 = inputIm[i*width + j+1];  //f(i,j+1)
    BYTE x3 = inputIm[(i+1)*width + j];   //(i+1,j)
    BYTE x4 = inputIm[(i+1)*width + j+1];  //f(i+1,j+1) 

                            // printf("%d %d\n", i, j);
    return ((1 - u)*(1 - v)*x1 + (1 - u)*v*x2 + u * (1 - v)*x3 + u * v*x4);
}
// ͬ����˫���Բ�ֵ��
bool bin_linear_scale(std::vector<BYTE> *input_img,const WORD &height,const WORD &width,const WORD & newHeight, const WORD & newWidth)
{
    if (input_img->size() == 0)
        return false;
    std::vector<BYTE> newIm(newHeight*newWidth,0);
    float h_scale_rate = (float)height / newHeight;
    float w_scale_rate = (float)width / newWidth;
    for (int i = 0; i < newHeight; i++) {
        //uchar* p = output_img.ptr<uchar>(i);
        for (int j = 0; j < newWidth; j++) {
            float i_scale = h_scale_rate * i;
            float j_scale = w_scale_rate * j;
            newIm[i*newWidth+j] = get_scale_value(input_img,height,width,i_scale,j_scale);
        }
    }
    input_img->clear();
    input_img->resize(newHeight*newWidth, 0);
    input_img->assign(newIm.begin(), newIm.end());
    return true;
}