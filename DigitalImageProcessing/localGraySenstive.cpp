#include<vector>

bool grayLinearScale(std::vector<WORD> *inputWordIm, std::vector<BYTE> *outputBYTEIm, 
    const WORD &maxVal , const WORD &height, const WORD &width, const int &lowerPoint, const int &upperPoint
    const int &LOWER_Y, const int &UPPER_Y) {
		//ʹ��double���ڼ���
		if (upperPoint>maxVal||lowerPoint<0) {
			return false;
		}

		outputBYTEIm->resize(height*width);

		double ratio_upper = (255.0 - UPPER_Y) / (maxVal - upperPoint);

		double ratio_lower = (LOWER_Y - 0.0) / lowerPoint ;  //ֱ�߾���ԭ�㣬�ʿ��Լ�
		
		double ratio_mid = (UPPER_Y - LOWER_Y) / (upperPoint - lowerPoint);


		//���ҶȰ������ν��С�ѹ��������Ҫ��Ϊ�����м�ģ�����������Ϣ��ͼ�������
		for (size_t i = 0; i < inputWordIm->size(); i++) {
			if ((*inputWordIm)[i]<lowerPoint) {
				(*outputBYTEIm)[i] = (*inputWordIm)[i] * ratio_lower;
			} else {
				if ((*inputWordIm)[i]>lowerPoint) {
					(*outputBYTEIm)[i] = ((*inputWordIm)[i]-upperPoint) * ratio_upper + UPPER_Y;
				} else {
					(*outputBYTEIm)[i] = ((*inputWordIm)[i]-lowerPoint) * ratio_mid + LOWER_Y;
				}
			}
		}
		
		return true;

}
