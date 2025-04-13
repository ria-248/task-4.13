#include "../include/common.h"
#include "../include/menu.h"
#include "../include/teacher.h"
#include "../include/student.h"

struct teaInfo teaArr[100];

static int len = sizeof(teaArr) / sizeof(struct teaInfo);

static int myId;
static char myCode[32];

void welcome_tea()
{
    puts("欢迎进入教师信息系统，请输入您的教师编号和密码登录：");

    logIn_tea();
}

void logIn_tea()
{
    int count = 1;

    while (1)
    {
        myId = 0;
        bzero(myCode, 32);

        int count = 1;
        int flag = 0;

        while (1)
        {
            // 用户输入账号密码
            char *a1 = inputStrIsInt("请输入您的教师编号：");
            myId = atoi(a1);

            puts("请输入密码：");
            strcpy(myCode, inputStr());

            // 检查账号密码正确性
            for (int i = 0; i < len; i++)
            {
                if (teaArr[i].id > 0 && myId == teaArr[i].id && !strcmp(myCode, teaArr[i].code))
                {
                    flag = 1;
                    break;
                }
            }

            // 检测到不正确时给出提示，3次不正确退出
            system("clear");
            if (!flag)
            {
                switch (count)
                {
                case 1:
                    puts("本次登录失败，您还有2次机会。");
                    break;
                case 2:
                    puts("本次登录失败，您还有1次机会，本次未登录成功系统将退出！");
                    break;
                default:
                    puts("系统已强制退出！");
                    exit(0);
                    break;
                }
                count++;
                puts("请输入您的教师编号和密码登录：");
            }
            else
            {
                break;
            }
        }
        if (flag)
        {
            system("clear");
            puts("登入成功！");
            teaSel_m();
        }
    }
}

void teaInfoEntry()
{

    system("clear");
    puts("您正在进行教师信息录入：");

    int _id;
    char _name[128];
    char _code[32];
    char _clNum[100];

    int addTea_index = 0;
    for (; addTea_index < len; addTea_index++)
    {
        // printf("%d\n",teaArr[i].id);
        if (!teaArr[addTea_index].id)
            break;
    }

    while (1)
    {
        puts("请输入教师的姓名：");
        char *a1 = inputStr();
        strcpy(_name, a1);

        strcpy(_clNum, inputStrIsInt("请输入教师的班级："));

        puts("请输入教师密码：");
        char *a2 = inputStr();
        strcpy(_code, a2);

        system("clear");
        puts("您正在进行教师信息录入：");
        puts("请确认您输入的教师信息：");
        printf("教师姓名：%s\n教师班级：%s\n教师密码：%s\n", _name, _clNum, _code);
        puts("确认教师基本信息无误请按‘Y’键，否则按回车键重新输入。");

        char *a3 = inputStr();

        if (*a3 == 'y' || *a3 == 'Y')
        {
            strcpy(teaArr[addTea_index].name, _name);
            teaArr[addTea_index].clNum = atoi(_clNum);
            strcpy(teaArr[addTea_index].code, _code);
            teaArr[addTea_index].id = 2000 + addTea_index;
            break;
        }
        system("clear");
        puts("您正在进行教师信息录入：");
    }
    system("clear");
    puts("教师信息已录入！");

    printf("已为该名教师自动分配教师编号:%d\n\n", teaArr[addTea_index].id);
    puts("以下是该教师的录入信息：");
    showData_tea(addTea_index, 1);

    puts("\n请按回车键返回。");
    inputStr();
    system("clear");
}

void teaInfoDel()
{
    system("clear");
    int i = 0;
    while (1)
    {
        int flag = 0;

        puts("您正在进行教师删除操作：");
        char *a1 = inputStrIsInt("请输入教师编号：");
        int delId = atoi(a1);
        puts("请输入该教师的密码：");
        char *a2 = inputStr();

        for (i = 0; i < len; i++)
        {
            if (teaArr[i].id > 0 && teaArr[i].id == delId && !strcmp(teaArr[i].code, a2))
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {

            puts("验证通过，以下是教师信息：");
            showData_tea(i, 1);
            puts("确认删除请按'Y'键，取消删除请按回车键。");
            char *a1 = inputStr();
            if (*a1 == 'Y' || *a1 == 'y')
            {
                int j = i;
                for (; j < len - 1; j++)
                {
                    teaArr[j] = teaArr[j + 1];
                }
                initData_tea(j);
                puts("教师信息已删除！");
            }
            puts("按回车键返回。");
            inputStr();
            system("clear");
            break;
        }
        else
        {
            system("clear");
            puts("教师编号或密码输入错误，请重新输入！\n");
        }
    }
}

void teaInfoMod()
{
    system("clear");
    int i = 0;
    while (1)
    {
        char *a1 = inputStrIsInt("您正在修改教师信息，请输入要修改教师的教师编号：");
        int modId = atoi(a1);

        int flag_exit = 0;
        while (1)
        {
            int modId_index = -1;
            for (int i = 0; i < len; i++)
            {
                if (teaArr[i].id > 0 && teaArr[i].id == modId)
                {
                    modId_index = i;
                }
            }
            if (modId_index == -1)
            {
                system("clear");
                puts("未检索到该教师，请重新输入：\n");
                break;
            }
            puts("");
            puts("1）姓名");
            puts("2）班级");
            puts("3）密码");
            puts("0）返回");
            puts("请输入数字选择要修改的选项：");
            char *a2 = inputStr();

            switch (*a2)
            {
            case '1':
                puts("请输入要修改的姓名：");
                strcpy(teaArr[modId_index].name, inputStr());
                system("clear");
                puts("该教师的姓名已修改成功！\n");
                break;
            case '2':
                teaArr[modId_index].clNum = atoi(inputStrIsInt("请输入要修改的班级："));
                system("clear");
                puts("该教师的班级已修改成功！\n");
                break;
            case '3':
                puts("请输入要修改的密码：");
                strcpy(teaArr[modId_index].code, inputStr());
                system("clear");
                puts("该教师的密码已修改成功！\n");
                break;
            case '0':
                flag_exit = 1;
                break;
            default:
                break;
            }
            if (flag_exit)
                break;
            puts("您正在修改教师信息：");
        }
        if (flag_exit)
            break;
    }
    system("clear");
}

void teaInfoSearch()
{

    system("clear");
    while (1)
    {
        int flag_back = 0;
        char *a1 = NULL;

        for (int i = 0; i < len; i++)
        {
            if (teaArr[i].id > 0 && teaArr[i].id == myId)
            {
                puts("##################");
                puts("本次登录的教师信息：");
                showData_tea(i, 1);
                puts("##################");
                puts("");
            }
        }

        puts("您正在检索教师信息：");
        puts("1）按教师编号查找");
        puts("2）按姓名查找");
        puts("3）按班级查找");
        puts("0）返回");
        puts("请输入数字选择需要检索选项：");

        a1 = inputStr();

        switch (*a1)
        {
        case '1':
        {
            char *a2 = inputStrIsInt("请输入查找的教师编号：");
            int findId = atoi(a2);
            int flag1 = 0;
            for (int i = 0; i < len; i++)
            {
                if (teaArr[i].id > 0 && teaArr[i].id == findId)
                {
                    system("clear");
                    puts("已检索到教师信息：");
                    showData_tea(i, 1);
                    puts("################");
                    flag1 = 1;
                    puts("按回车键返回。");
                    inputStr();
                }
            }
            if (!flag1)
            {
                system("clear");
                puts("未检索到该教师编号，按回车键返回。");
                inputStr();
            }
            break;
        }
        case '2':
            // printf("###########################a1=%d\n",*a1);
            puts("请输入查找的姓名：");
            char *a3 = inputStr();
            char findName[128];
            strcpy(findName, a3);

            int flag2 = 0;
            for (int i = 0; i < len; i++)
            {
                if (!strcmp(teaArr[i].name, findName))
                {
                    puts("已检索到教师信息：");
                    showData_tea(i, 1);
                    puts("################");
                    flag2 = 1;
                }
            }
            if (!flag2)
            {
                system("clear");
                puts("未检索到该姓名。");
            }
            puts("回车返回。");
            inputStr();
            break;
        case '3':
        {
            char *a4 = inputStrIsInt("请输入查找的班级：");
            int findCl = atoi(a4);
            int flag3 = 0;
            for (int i = 0; i < len; i++)
            {
                if (teaArr[i].clNum == findCl)
                {
                    puts("已检索到班级信息：");
                    showData_tea(i, 1);
                    puts("################");
                    flag3 = 1;
                }
            }
            if (!flag3)
            {
                system("clear");
                puts("未检索到该班级。");
            }
            puts("按回车键返回。");
            inputStr();
            break;
        }
        case '0':
            flag_back = 1;
            break;
            break;
        default:
            break;
        }
        system("clear");
        if (flag_back)
            break;
    }
}

void teaInfoMod_toStu()
{
    system("clear");
    int i = 0;
    while (1)
    {
        char *a1 = inputStrIsInt("您正在修改学生信息，请输入要修改学生的学号：");
        int modId = atoi(a1);

        int flag_exit = 0;
        while (1)
        {
            int modId_index = -1;
            for (int i = 0; i < len; i++)
            {
                if (stuArr[i].id > 0 && stuArr[i].id == modId)
                {
                    modId_index = i;
                }
            }
            if (modId_index == -1)
            {
                system("clear");
                puts("未检索到该学生，请重新输入：\n");
                break;
            }
            puts("");
            puts("1）数学成绩");
            puts("2）语文成绩");
            puts("3）C语言成绩");
            puts("0）返回");
            puts("请输入数字选择要修改的选项：");
            char *a2 = inputStr();

            switch (*a2)
            {
            case '1':
                stuArr[modId_index].math_cs = atoi(inputStrIsInt("请输入要修改的数学成绩："));
                autoRank_stu();
                system("clear");
                puts("该学生的数学成绩已修改成功！\n");
                break;
            case '2':
                stuArr[modId_index].chinese_cs = atoi(inputStrIsInt("请输入要修改的语文成绩："));
                autoRank_stu();
                system("clear");
                puts("该学生的语文成绩已修改成功！\n");
                break;
            case '3':
                stuArr[modId_index].c_cs = atoi(inputStrIsInt("请输入要修改的C语言成绩："));
                autoRank_stu();
                system("clear");
                puts("该学生的C语言成绩已修改成功！\n");
                break;
            case '0':
                flag_exit = 1;
                break;
            default:
                break;
            }
            if (flag_exit)
                break;
            puts("您正在修改学生信息：");
        }
        if (flag_exit)
            break;
    }
    system("clear");
}

void showData_tea(int index, int showCode)
{
    printf("教师编号：%d\n", teaArr[index].id);
    printf("教师姓名：%s\n", teaArr[index].name);
    printf("教师班级：%d\n", teaArr[index].clNum);
    if (showCode)
        printf("教师密码：%s\n", teaArr[index].code);
}

void initData_tea(int index)
{
    teaArr[index].id = 0;
    teaArr[index].clNum = 0;
    bzero(teaArr[index].name, 128);
    bzero(teaArr[index].code, 32);
}
