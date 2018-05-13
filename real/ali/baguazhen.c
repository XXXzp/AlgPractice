#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/** 请完成下面这个函数，实现题目要求的功能 **/
 /** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/

/** 防止我写不完。。。写一下我的思路，模仿图像处理的腐蚀操作，使用3*3的模板，把中心的值加到边缘，从边缘收缩迭代 **/
int* getMilitaryStrength(int A_size_row, int A_size_cols, int** A,int* result_size) {
    bool iteration_flag = true;  //无值更新则停止迭代
    bool found_outer_val_flag; //当找到第一个边缘的值的时候，就停止核内搜索
    int col,row,i,j;
    int* res =  (int*)malloc(2*sizeof(int));
    int mtx_max=0,mtx_min=INT_MAX;

    while(iteration_flag){
        for( col = 1; col<A_size_cols-1; col++){
            for( row = 1; row<A_size_row-1; row++){  //全图卷积
                //卷积核内
                if(A[col][row]>0){
                    found_outer_val_flag = false;
                    for(i=-1;i<2;i++){
                        for( j=-1;j<2;j++){
                            if(i==0&&j==0)   //跳过自身的点
                                continue;   
                            if(A[col+i][row+j]>0){
                                A[col+i][row+j] += A[col][row];   //把中心点的值移动到有值的边缘
                                iteration_flag = true;   //有值迭代，
                                found_outer_val_flag = true;  //已将值移动到边缘，进行下次“卷积”
                                break;
                            }
                        }
                        if(found_outer_val_flag)
                            break;
                    }
                }

            }
        }
    }
    //寻找最大值和最小值
    for(col=0;col<A_size_cols;col++){
        for(row=0;row<A_size_row;row++){
            if(A[col][row]>mtx_max)
                mtx_max = A[col][row];
            if(A[col][row]<mtx_min)
                mtx_min = A[col][row];
        }
    }
    res[0] = mtx_max;
    res[1] = mtx_min;
    return res;
}

int main() {
    int res_size;
    int* res;

    int _A_rows = 0;
    int _A_cols = 0;
    scanf("%d", &_A_rows);
    scanf("%d", &_A_cols);
    
    int** _A = (int**)malloc(_A_rows*sizeof(int*));
    int _A_init_i=0;
    for(_A_init_i=0 ; _A_init_i<_A_rows ; ++_A_init_i)
    {
        _A[_A_init_i] = (int*)malloc(_A_cols*(sizeof(int)));
    }
    
    int _A_i, _A_j;
    for(_A_i = 0; _A_i < _A_rows; _A_i++) {
        for(_A_j = 0; _A_j < _A_cols; _A_j++) {
            int _A_item;
            scanf("%d", &_A_item);
            
            _A[_A_i][_A_j] = _A_item;
        }
    }   
 
    res = getMilitaryStrength(_A_rows, _A_cols, _A, &res_size);
    for(int res_i=0; res_i < res_size; res_i++) {
    
        printf("%d\n", res[res_i]);
        
    }
    
    return 0;

}