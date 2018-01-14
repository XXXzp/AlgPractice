#include<vector>
const int GRAYSCALE = 256;
int gray[GRAYSCALE] = { 0 };//ͳ��ÿ���Ҷ��µ����ص����
int gray_new[GRAYSCALE] = { 0 };//����Ҷȸ���
bool histogramEql(std::vector<BYTE> *iMtx, const WORD &height, const WORD &width) {
		std::vector<BYTE> &imageMtx = *iMtx;
		double gray_distri[GRAYSCALE] = { 0.0 };//记录累计密度分布，离散CDF
		double prob[GRAYSCALE] = { 0.0 };
		int imageSize = height * width;//计算图片总像素数
		if (imageSize == 0)
			return false;
		Gdiplus::Color color_temp;
		BYTE gray_temp;
		for (size_t i = 0; i < width; i++) {
			for (size_t j = 0; j < height; j++) {
				gray[imageMtx[(width*j + i)]]++;//统计灰度
			}
		}
		for (size_t i = 0; i < GRAYSCALE; i++)
			prob[i] = (double)gray[i] / imageSize;//灰度概率nk/n

		gray_distri[0] = prob[0];//先计算一个，方便下面的循环
		for (size_t i = 1; i < GRAYSCALE; i++)
			gray_distri[i] = gray_distri[i - 1] + prob[i];//连续情况下是积分，但是这里是离散的所以是求和

		for (size_t j = 0; j < height; j++) {
			for (size_t k = 0; k < width; k++) {
				gray_temp = gray_distri[imageMtx[width*j + k]] * GRAYSCALE - 1;
				gray_new[gray_temp]++;//统计处理后的图片的灰度
				imageMtx[(width*j + k)] = gray_temp;//将image设置为新的灰度值
			}
		}
		return true;
}