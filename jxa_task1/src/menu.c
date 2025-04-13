#include "../include/common.h"
#include "../include/menu.h"
#include "../include/student.h"
#include "../include/teacher.h"

int stuSel_flag = 0;

void welcome_m()
{
    system("clear");
    logIn_m();
}

void logIn_m()
{
    puts("请输入数字选择对应的身份：");
    char *a1;
    while (1)
    {
        puts("1）学生");
        puts("2）教师");
        puts("0）退出系统");

        a1 = inputStr();

        switch (*a1)
        {
        case '1':
            system("clear");
            welcome_stu();
            break;
        case '2':
            system("clear");
            welcome_tea();
            break;
        case '0':
            system("clear");
            puts("系统已退出。");
            exit(0);
            break;
        default:
            system("clear");
            puts("请输入数字选择对应的身份：");
            break;
        }

    }
}

void stuSel_m()
{
    while (1)
    {
        int flag = 0;
        char *a1 = 0;
        puts("请输入对应的数字选择您需要的操作：");
        puts("1）录入学生信息");
        puts("2）删除学生信息");
        puts("3）修改学生信息");
        puts("4）查找学生信息");
        puts("5）显示所有学生信息列表");
        puts("0）返回");

        a1 = inputStr();

        switch (*a1)
        {
        case '1':
            stuInfoEntry();
            break;
        case '2':
            stuInfoDel();
            break;
        case '3':
            stuInfoMod();
            break;
        case '4':
            stuInfoSearch();
            break;
        case '5':
            showStuList();
            break;
        case '0':
            flag = 1;
            break;
        default:
            system("clear");
            puts("输入错误，请重新输入。");
            break;
        }
        if (flag)
            break;
    }
    system("clear");
    welcome_m();
}

void teaSel_m()
{
    while (1)
    {
        int flag = 0;
        char *a1 = 0;
        puts("请输入对应的数字选择您需要的操作：");
        puts("1）录入教师信息");
        puts("2）删除教师信息");
        puts("3）修改教师信息");
        puts("4）查找教师信息");
        puts("5）显示所有学生信息列表");
        puts("6）修改学生成绩");
        puts("0）返回");

        a1 = inputStr();

        switch (*a1)
        {
        case '1':
            teaInfoEntry();
            break;
        case '2':
            teaInfoDel();
            break;
        case '3':
            teaInfoMod();
            break;
        case '4':
            teaInfoSearch();
            break;
        case '5':
            showStuList();
            break;
        case '6':
            teaInfoMod_toStu();
            break;
        case '0':
            flag = 1;
            break;
        default:
            system("clear");
            puts("输入错误，请重新输入。");
            break;
        }
        if (flag)
            break;
    }
    system("clear");
    welcome_m();
}
