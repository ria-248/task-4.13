#ifndef __STUDENT_H__
#define __STUDENT_H__

//登录函数
void welcome_stu();
void logIn_stu();

////登录后的操作函数
//学生信息录入
void stuInfoEntry();
//学生信息删除
void stuInfoDel();
//学生信息修改
void stuInfoMod();
//学生信息查找
void stuInfoSearch();
//列出所有学生信息
void showStuList();

////内部调用功能函数
//打印一个学生的信息，传入数组下标
void showData_stu(int index,int showRank);
//打印所有学生信息
void showAllData_stu(int showCode,int showRank);
//初始化一个学生的信息，传入数组下标
void initData_stu(int index);
//计算出三门成绩的总分并赋值
void totalScore_cal();
//计算出所有学生的成绩排名，并从高到低排序
void autoRank_stu();
//按照不同的信息对所有学生信息进行排序，例如学号等
void sort_stu(int select);

//矩阵排序并显示所有学生信息
void matrixSort_stu(int showRank);



//学生信息结构体
struct stuInfo
{
    int id;
    char name[128];
    int age;
    char code[32];
    int clNum;

    int math_cs;
    int chinese_cs;
    int c_cs;
    int total_cs;
    int rank;
};

//全局变量
extern struct stuInfo stuArr[100];

#endif // !__STUDENT_H__