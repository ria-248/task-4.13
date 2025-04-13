#include "../include/common.h"
#include "../include/menu.h"
#include "../include/student.h"
#include "../include/teacher.h"

int main(int argc, char const *argv[])
{
    // 学生数据stuArr初始化
    {
        stuArr[0].id = 1;
        strcpy(stuArr[0].name, "初始账户");
        strcpy(stuArr[0].code, "1");
        stuArr[1].age = 1;
        stuArr[1].clNum = 1;
        stuArr[0].math_cs = 1;
        stuArr[0].chinese_cs = 1;
        stuArr[0].c_cs = 1;

        stuArr[1].id = 1001;
        strcpy(stuArr[1].name, "小明");
        strcpy(stuArr[1].code, "111");
        stuArr[1].age = 10;
        stuArr[1].clNum = 2025;
        stuArr[1].math_cs = 50;
        stuArr[1].chinese_cs = 70;
        stuArr[1].c_cs = 40;

        stuArr[2].id = 1002;
        strcpy(stuArr[2].name, "小红");
        strcpy(stuArr[2].code, "222");
        stuArr[2].age = 11;
        stuArr[2].clNum = 2025;
        stuArr[2].math_cs = 90;
        stuArr[2].chinese_cs = 80;
        stuArr[2].c_cs = 90;

        stuArr[3].id = 1003;
        strcpy(stuArr[3].name, "阿强");
        strcpy(stuArr[3].code, "333");
        stuArr[3].age = 12;
        stuArr[3].clNum = 2024;
        stuArr[3].math_cs = 15;
        stuArr[3].chinese_cs = 90;
        stuArr[3].c_cs = 20;

        stuArr[4].id = 1004;
        strcpy(stuArr[4].name, "阿珍");
        strcpy(stuArr[4].code, "444");
        stuArr[4].age = 9;
        stuArr[4].clNum = 2024;
        stuArr[4].math_cs = 95;
        stuArr[4].chinese_cs = 45;
        stuArr[4].c_cs = 100;

        stuArr[5].id = 1005;
        strcpy(stuArr[5].name, "小黑");
        strcpy(stuArr[5].code, "555");
        stuArr[5].age = 12;
        stuArr[5].clNum = 2025;
        stuArr[5].math_cs = 40;
        stuArr[5].chinese_cs = 65;
        stuArr[5].c_cs = 35;

        stuArr[1].rank = 0;
        stuArr[6].id = 0;
    }

    // 教师数据teaArr初始化
    {
        teaArr[0].id = 1;
        strcpy(teaArr[0].name, "初始账户");
        strcpy(teaArr[0].code, "1");
        teaArr[0].clNum = 1;

        teaArr[1].id = 2001;
        strcpy(teaArr[1].name, "郭靖");
        strcpy(teaArr[1].code, "111");
        teaArr[1].clNum = 2025;

        teaArr[2].id = 2002;
        strcpy(teaArr[2].name, "小龙女");
        strcpy(teaArr[2].code, "222");
        teaArr[2].clNum = 2025;

        teaArr[3].id = 2003;
        strcpy(teaArr[3].name, "杨过");
        strcpy(teaArr[3].code, "333");
        teaArr[3].clNum = 2024;

        teaArr[4].id = 0;
    }

    drawInterface("欢迎进入《新星幼儿园》师生信息管理系统", 56, 7);

    inputStr(); // 暂停

    autoRank_stu(); // 排一次总分名次
    welcome_m();    // 进系统

    return 0;
}
