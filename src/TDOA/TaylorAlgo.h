#pragma once
#ifndef TAYLOR_ALGO_FILE
#define TAYLOR_ALGO_FILE
/**************̩���㷨��ά***************/
/***************TaylorAlgo.h**************/
/********û�������Ķ��ļ��Ĵ����Լ�*******/
/************�����Լ�д��һ��*************/
//                            _ooOoo_  
//                           o8888888o  
//                           88" . "88  
//                           (| -_- |)  
//                            O\ = /O  
//                        ____/`---'\____  
//                      .   ' \\| |// `.  
//                       / \\||| : |||// \  
//                     / _||||| -:- |||||- \  
//                       | | \\\ - /// | |  
//                     | \_| ''\---/'' | |  
//                      \ .-\__ `-` ___/-. /  
//                   ___`. .' /--.--\ `. . __  
//                ."" '< `.___\_<|>_/___.' >'"".  
//               | | : `- \`.;`\ _ /`;.`/ - ` : | |  
//                 \ \ `-. \_ __\ /__ _/ .-` / /  
//         ======`-.____`-.___\_____/___.-`____.-'======  
//                            `=---='  
//  
//         .............................................  
//                  ���汣��             ����BUG 
//          ��Ի:  
//                  д��¥��д�ּ䣬д�ּ������Ա��  
//                  ������Աд�������ó��򻻾�Ǯ��  
//                  ����ֻ���������������������ߣ�  
//                  ��������ո��գ����������긴�ꡣ  
//                  ��Ը�������Լ䣬��Ը�Ϲ��ϰ�ǰ��  
//                  ���۱������Ȥ���������г���Ա��  
//                  ����Ц��߯��񲣬��Ц�Լ���̫����  
//                  ��������Ư���ã��ĸ���ó���Ա�� 
#include <vector>

#include "Matrix.h"
using namespace std;
struct POSITION
{
	double x;
	double y;
	double z;
};

class TAYLOR_ALGO
{
public:
	TAYLOR_ALGO();
	~TAYLOR_ALGO();
	void TaylorCalcXY(double x,double y);
	void TaylorCalcXYZ(double x,double y,double z);
	void ReadTxt(double tdoa[4]);
	bool GetCalcResult(double *desX,double *desY);
	bool GetCalcResult(double *desX,double *desY,double *desZ);
private:
	POSITION resultPosition;
	MAT inputTdoaData;//��һά�еڶ�ά��
	MAT tdoaDataNodelay;
	//double MS[3];
	double BS[4][3];
	double delay[4];
	bool calcFlag ;
};
#endif