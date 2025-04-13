#ifndef __TEACHER_H__
#define __TEACHER_H__

//登录函数
void welcome_tea();
void logIn_tea();

////登录后的操作函数
//教师信息录入
void teaInfoEntry();
//教师信息删除
void teaInfoDel();
//教师信息修改
void teaInfoMod();
//教师信息查找
void teaInfoSearch();
//教师修改学生信息
void teaInfoMod_toStu();

////内部调用功能函数
//显示一个教师的所有信息
void showData_tea(int index, int showCode);
//初始化一个教师结构体数组的数据
void initData_tea(int index);


//教师信息结构体
struct teaInfo
{
    int id;
    char name[128];
    char code[32];
    int clNum;
};

//全局变量
extern struct teaInfo teaArr[100];

#endif // !__TEACHER_H__


