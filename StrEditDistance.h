#ifndef _STR_ED_H_
#define _STR_ED_H_
#include <string>  

#define MATCH        2  
#define SUBERROR   -1
#define INSERT       -1
#define DELETE       -1


typedef struct _GridNode
{
	int rowIndex;
	int columnIndex;
	float cost;
	_GridNode* prevNode;
	_GridNode* nextNode;
	_GridNode(){
		rowIndex = 0;
		columnIndex = 0;
		cost = 0.0f;
		prevNode = NULL;
		nextNode = NULL;
	}
}GridNode;


typedef struct _EDStatistic
{
	int m_Corr;
	int m_Sub;
	int m_Del;
	int m_Ins;
	int m_Total;
	_EDStatistic(){
		m_Total = 0;
		m_Corr = 0;
		m_Ins = 0;
		m_Del = 0;
		m_Sub = 0;
	}

}EDStatistic;

class CStrEditDistance  
{  
public:  
	CStrEditDistance(std::string& vStrRow, std::string& vStrColumn);  
	~CStrEditDistance(void);  
	int  getScore()    { return m_Score;   }  
	int  getEditDis()  { return m_EditDis; }  
	void setEditDis(int vDis) { m_EditDis = vDis; }  
	void setScore(int vScore) { m_Score = vScore; }  
	EDStatistic ComputeEditDistStatistic(int corr_, int sub_,int ins_, int del_, int total_);
private:  
	void process(const std::string& vRef, const std::string& vRec);  
	float getMaxValue(float a, float b, float c)  
	{  
		if (a < b){ if (b < c) return c; return b; }  
		else { if (b > c) return a; return a < c ? c : a; }  
	}
	void maxValueAndPos(float first, float second, float third, float& maxvalue, int& pos);

private:  
	int   m_EditDis;  
	int   m_Score;  
	bool m_isComputeWER;
};  

typedef  enum _WordAlignType
{
	CORR_ALIGN=0,
	INS_ALIGN,
	SUB_ALIGN,
	DEL_ALIGN,
	END_ALIGN

}WordAlignType;


int ComputeWER(const std::string ref, const std::string hyp);

void Par_Count(const char*, char* , int* sw);
void TestCase4Par_Count();
#endif