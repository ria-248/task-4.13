#include "../include/common.h"
#include "../include/menu.h"
#include "../include/student.h"

// struct stuInfo stuArr[100] = {[0].name = "初始账户", [0].id = 1, [0].code = "1", [1].id = 0};

struct stuInfo stuArr[100];
static int len = sizeof(stuArr) / sizeof(struct stuInfo);

void welcome_stu()
{
    puts("欢迎进入学生信息系统，请输入学号和密码登录：");

    logIn_stu();
}

void logIn_stu()
{
    int myId;
    char myCode[32];
    int count = 1;
    int flag = 0;

    while (1)
    {
        // 用户输入账号密码
        char *a1 = inputStrIsInt("请输入学号：");
        myId = atoi(a1);

        puts("请输入密码：");
        strcpy(myCode, inputStr());

        // 检查账号密码正确性
        for (int i = 0; i < len; i++)
        {
            if (stuArr[i].id > 0 & myId == stuArr[i].id && !strcmp(myCode, stuArr[i].code))
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
            puts("请输入学生号和密码登录：");
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
        stuSel_m();
    }
}

void stuInfoEntry()
{
    system("clear");
    puts("您正在进行学生信息录入：");

    // int _id;
    char _name[128];
    char _age[100];
    char _code[32];
    char _clNum[100];

    char _math_cs[100];
    char _chinese_cs[100];
    char _c_cs[100];
    // char _rank[100];

    int addStu_index = 0;
    for (; addStu_index < len; addStu_index++)
    {
        // printf("%d\n",stuArr[i].id);
        if (!stuArr[addStu_index].id)
            break;
    }

    while (1)
    {
        puts("请输入学生的姓名：");
        char *a1 = inputStr();
        strcpy(_name, a1);

        strcpy(_age, inputStrIsInt("请输入学生的年龄："));
        strcpy(_clNum, inputStrIsInt("请输入学生的班级："));

        puts("请输入学生的密码：");
        char *a2 = inputStr();
        strcpy(_code, a2);

        system("clear");
        puts("您正在进行学生信息录入：");
        puts("请确认您输入的学生基本信息：");
        printf("学生姓名：%s\n学生年龄：%s\n学生班级：%s\n学生密码：%s\n", _name, _age, _clNum, _code);
        puts("确认学生基本信息无误请按‘Y’键，或按回车键重新输入。");

        char *a3 = inputStr();

        if (*a3 == 'y' || *a3 == 'Y')
        {
            strcpy(stuArr[addStu_index].name, _name);
            stuArr[addStu_index].age = atoi(_age);
            stuArr[addStu_index].clNum = atoi(_clNum);
            strcpy(stuArr[addStu_index].code, _code);
            break;
        }
        system("clear");
        puts("您正在进行学生信息录入：");
    }
    system("clear");
    puts("学生基础信息已录入！请输入学生的成绩信息：");
    while (1)
    {
        strcpy(_math_cs, inputStrIsInt("请输入学生的数学成绩："));
        strcpy(_chinese_cs, inputStrIsInt("请输入学生的语文成绩："));
        strcpy(_c_cs, inputStrIsInt("请输入学生的C语言成绩："));

        system("clear");
        puts("学生基础信息已录入！请输入学生的成绩信息：");
        puts("请确认您输入的学生成绩信息：");
        printf("数学成绩：%s\n语文成绩：%s\nC语言成绩：%s\n", _math_cs, _chinese_cs, _c_cs);
        puts("确认学生成绩信息无误请按‘Y’键，或按回车键重新输入。");

        char *a1 = inputStr();

        if (*a1 == 'y' || *a1 == 'Y')
        {
            stuArr[addStu_index].math_cs = atoi(_math_cs);
            stuArr[addStu_index].chinese_cs = atoi(_chinese_cs);
            stuArr[addStu_index].c_cs = atoi(_c_cs);
            stuArr[addStu_index].rank = 0;
            stuArr[addStu_index].id = 1000 + addStu_index;
            break;
        }
        system("clear");
        puts("学生基础信息已录入！请输入学生的成绩信息：");
    }

    system("clear");
    puts("学习信息录入成功！");
    printf("已为该同学自动分配学号:%d\n\n", stuArr[addStu_index].id);
    puts("以下是该学生的录入信息：");

    showData_stu(addStu_index, 0);
    autoRank_stu();
    printf("该同学当前的总成绩排名：第%d名\n", stuArr[addStu_index].rank);

    puts("\n请按回车键返回。");
    inputStr();
    system("clear");
}

void stuInfoDel()
{
    system("clear");
    int i = 0;
    while (1)
    {
        int flag = 0;

        puts("您正在进行学生删除操作：");
        char *a1 = inputStrIsInt("请输入学生的学号：");
        int delId = atoi(a1);
        puts("请输入该学生的密码：");
        char *a2 = inputStr();

        for (i = 0; i < len; i++)
        {
            if (stuArr[i].id > 0 && stuArr[i].id == delId && !strcmp(stuArr[i].code, a2))
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {

            puts("验证通过，以下是学生信息：");
            showData_stu(i, 1);
            puts("确认删除请按'Y'键，取消删除请按回车键。");
            char *a1 = inputStr();
            if (*a1 == 'Y' || *a1 == 'y')
            {
                int j = i;
                for (; j < len - 1; j++)
                {
                    stuArr[j] = stuArr[j + 1];
                }
                initData_stu(j);
                autoRank_stu();
                puts("学生信息已删除！请按回车键返回。");
            }
            else
            {
                puts("已取消删除，请按回车键返回。");
            }
            inputStr();
            system("clear");
            break;
        }
        else
        {
            system("clear");
            puts("学号或密码输入错误，请重新输入！\n");
        }
    }
}

void stuInfoMod()
{
    system("clear");
    // int i = 0;
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
            puts("1）姓名");
            puts("2）年龄");
            puts("3）班级");
            puts("4）密码");
            puts("5）数学成绩");
            puts("6）语文成绩");
            puts("7）C语言成绩");
            puts("0）返回");
            puts("请输入数字选择要修改的选项：");
            char *a2 = inputStr();

            switch (*a2)
            {
            case '1':
                puts("请输入要修改的姓名：");
                strcpy(stuArr[modId_index].name, inputStr());
                system("clear");
                puts("该学生的姓名已修改成功！\n");
                break;
            case '2':
                stuArr[modId_index].age = atoi(inputStrIsInt("请输入要修改的年龄："));
                system("clear");
                puts("该学生的年龄已修改成功！\n");
                break;
            case '3':
                stuArr[modId_index].clNum = atoi(inputStrIsInt("请输入要修改的班级："));
                system("clear");
                puts("该学生的班级已修改成功！\n");
                break;
            case '4':
                puts("请输入要修改的密码：");
                strcpy(stuArr[modId_index].code, inputStr());
                system("clear");
                puts("该学生的密码已修改成功！\n");
                break;
            case '5':
                stuArr[modId_index].math_cs = atoi(inputStrIsInt("请输入要修改的数学成绩："));
                autoRank_stu();
                system("clear");
                puts("该学生的数学成绩已修改成功！\n");
                break;
            case '6':
                stuArr[modId_index].chinese_cs = atoi(inputStrIsInt("请输入要修改的语文成绩："));
                autoRank_stu();
                system("clear");
                puts("该学生的语文成绩已修改成功！\n");
                break;
            case '7':
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

void stuInfoSearch()
{
    system("clear");
    while (1)
    {
        int flag_back = 0;
        char *a1 = NULL;

        puts("您正在检索学生信息：");
        puts("1）按学号查找");
        puts("2）按姓名查找");
        puts("3）按班级群体查找");
        puts("0）返回");
        puts("请输入数字选择需要检索选项：");
        a1 = inputStr();

        switch (*a1)
        {
        case '1':
        {
            char *a2 = inputStrIsInt("请输入查找的学号：");
            int findId = atoi(a2);
            int flag1 = 0;
            system("clear");
            for (int i = 0; i < len; i++)
            {
                if (stuArr[i].id == findId && stuArr[i].id > 0)
                {
                    puts("已检索到学生信息：");
                    showData_stu(i, 1);
                    puts("################");
                    flag1 = 1;
                    puts("按回车键返回。");
                    inputStr();
                }
            }
            if (!flag1)
            {
                puts("未检索到该学号，按回车键返回。");
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
            system("clear");
            for (int i = 0; i < len; i++)
            {
                if (!strcmp(stuArr[i].name, findName))
                {
                    puts("已检索到学生信息：");
                    showData_stu(i, 1);
                    puts("################");
                    flag2 = 1;
                }
            }
            if (!flag2)
            {
                system("clear");
                puts("未检索到该姓名。");
            }
            puts("按回车键返回。");
            inputStr();
            break;
        case '3':
        {
            char *a4 = inputStrIsInt("请输入查找的班级：");
            int findCl = atoi(a4);
            int flag3 = 0;
            system("clear");
            for (int i = 0; i < len; i++)
            {
                if (stuArr[i].clNum == findCl)
                {
                    puts("已检索到班级信息：");
                    showData_stu(i, 1);
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

void showStuList()
{
    system("clear");
    while (1)
    {
        int flag = 0;
        int flag_exit = 0;
        float AverageSC = 0;

        puts("选择您希望展示所有信息的方式：");
        puts("1）按学号顺序显示");
        puts("2）按总分名次顺序显示");
        puts("3）按某学科成绩显示");
        puts("0）返回");
        puts("请输入数字选择：");
        char *a1 = inputStr();
        char *a2 = NULL;
        switch (*a1)
        {
        case '1':
            sort_stu(1);
            flag = 1;
            break;
        case '2':
            sort_stu(2);
            flag = 1;
            break;
        case '3':
        {
            int flag2 = 0;
            while (1)
            {
                system("clear");
                puts("请选择按哪种成绩显示学生信息");
                puts("1）数学");
                puts("2）语文");
                puts("3）C语言");
                puts("0）返回");
                puts("请输入数字选择：");
                a2 = inputStr();
                switch (*a2)
                {
                case '1':
                {
                    sort_stu(3);
                    flag = 1;
                    int personNum = 0;
                    for (int i = 0; i < len; i++)
                    {
                        if (stuArr[i].id > 0)
                        {
                            AverageSC += stuArr[i].math_cs;
                            personNum++;
                        }
                    }
                    AverageSC /= personNum;
                    break;
                }
                case '2':
                {
                    sort_stu(4);
                    flag = 1;
                    int personNum = 0;
                    for (int i = 0; i < len; i++)
                    {
                        if (stuArr[i].id > 0)
                        {
                            AverageSC += stuArr[i].chinese_cs;
                            personNum++;
                        }
                    }
                    AverageSC /= personNum;
                    break;
                }
                case '3':
                {
                    sort_stu(5);
                    flag = 1;
                    int personNum = 0;
                    for (int i = 0; i < len; i++)
                    {
                        if (stuArr[i].id > 0)
                        {
                            AverageSC += stuArr[i].c_cs;
                            personNum++;
                        }
                    }
                    AverageSC /= personNum;
                    break;
                }
                case '0':
                    flag2 = 1;
                    break;
                default:
                    break;
                }
                if (flag || flag2)
                    system("clear");
                break;
            }
            break;
        }
        case '0':
            flag_exit = 1;
            break;
        default:
            break;
        }

        system("clear");
        if (flag)
        {
            puts("已列出我校所有学生信息：\n");

            matrixSort_stu(1);

            if (AverageSC)
            {
                switch (*a2)
                {
                case '1':
                    printf("数学的平均成绩为：%.2f\n", AverageSC);
                    break;
                case '2':
                    printf("语文的平均成绩为：%.2f\n", AverageSC);
                    break;
                case '3':
                    printf("C语言的平均成绩为：%.2f\n", AverageSC);
                    break;
                }
            }
            puts("\n请按回车键返回。");
            inputStr();
            system("clear");
        }
        if (flag_exit)
            break;
    }
}

void totalScore_cal()
{
    for (int i = 0; i < len; i++)
    {
        if (stuArr[i].id > 0)
        {
            stuArr[i].total_cs = stuArr[i].math_cs + stuArr[i].chinese_cs + stuArr[i].c_cs;
            // printf("%d \n", stuArr[i].total_cs);
        }
    }
}
void autoRank_stu()
{
    totalScore_cal();

    for (int i = 0; i < len; i++)
    {
        int maxIndex = 0;
        for (int k = 0; k < len - i; k++)
        {
            if (stuArr[maxIndex].total_cs > stuArr[k].total_cs)
            {
                maxIndex = k;
            }
        }
        struct stuInfo t = stuArr[len - i - 1];
        stuArr[len - i - 1] = stuArr[maxIndex];
        stuArr[maxIndex] = t;
    }
    for (int i = 0; i < len; i++)
    {
        stuArr[i].rank = i + 1;
        // if (stuArr[i].id > 0)
        //     printf("s=%-5d id=%-5d rank=%-5d\n", stuArr[i].total_cs, stuArr[i].id,stuArr[i].rank);
    }
    printf("\n");
}

void sort_stu(int select)
{
    switch (select)
    {
    case 1:
    {
        for (int i = 0; i < len; i++)
        {
            int maxIndex = 0;
            for (int k = 0; k < len - i; k++)
            {
                if (stuArr[maxIndex].id < stuArr[k].id)
                {
                    maxIndex = k;
                }
            }
            struct stuInfo t = stuArr[len - i - 1];
            stuArr[len - i - 1] = stuArr[maxIndex];
            stuArr[maxIndex] = t;
        }
        break;
    }
    case 2:
    {
        for (int i = 0; i < len; i++)
        {
            int maxIndex = 0;
            for (int k = 0; k < len - i; k++)
            {
                if (stuArr[maxIndex].rank < stuArr[k].rank)
                {
                    maxIndex = k;
                }
            }
            struct stuInfo t = stuArr[len - i - 1];
            stuArr[len - i - 1] = stuArr[maxIndex];
            stuArr[maxIndex] = t;
        }
        break;
    }
    case 3:
    {
        for (int i = 0; i < len; i++)
        {
            int maxIndex = 0;
            for (int k = 0; k < len - i; k++)
            {
                if (stuArr[maxIndex].math_cs > stuArr[k].math_cs)
                {
                    maxIndex = k;
                }
            }
            struct stuInfo t = stuArr[len - i - 1];
            stuArr[len - i - 1] = stuArr[maxIndex];
            stuArr[maxIndex] = t;
        }
        break;
    }
    case 4:
    {
        for (int i = 0; i < len; i++)
        {
            int maxIndex = 0;
            for (int k = 0; k < len - i; k++)
            {
                if (stuArr[maxIndex].chinese_cs > stuArr[k].chinese_cs)
                {
                    maxIndex = k;
                }
            }
            struct stuInfo t = stuArr[len - i - 1];
            stuArr[len - i - 1] = stuArr[maxIndex];
            stuArr[maxIndex] = t;
        }
        break;
    }
    case 5:
    {
        for (int i = 0; i < len; i++)
        {
            int maxIndex = 0;
            for (int k = 0; k < len - i; k++)
            {
                if (stuArr[maxIndex].c_cs > stuArr[k].c_cs)
                {
                    maxIndex = k;
                }
            }
            struct stuInfo t = stuArr[len - i - 1];
            stuArr[len - i - 1] = stuArr[maxIndex];
            stuArr[maxIndex] = t;
        }
        break;
    }
    default:
        break;
    }
}

void initData_stu(int index)
{
    stuArr[index].id = 0;
    stuArr[index].age = 0;
    stuArr[index].clNum = 0;
    bzero(stuArr[index].name, 128);
    bzero(stuArr[index].code, 32);

    stuArr[index].math_cs = 0;
    stuArr[index].chinese_cs = 0;
    stuArr[index].c_cs = 0;
    stuArr[index].rank = 0;
}

void showAllData_stu(int showCode, int showRank)
{
    for (int i = 0; i < len; i++)
    {
        if (stuArr[i].id > 0)
        {
            printf("学号：%d\n", stuArr[i].id);
            printf("姓名：%s\n", stuArr[i].name);
            printf("年龄：%d\n", stuArr[i].age);
            printf("班级：%d\n", stuArr[i].clNum);
            if (showCode)
                printf("学生密码：%s\n", stuArr[i].code);
            printf("数学成绩：%d\n", stuArr[i].math_cs);
            printf("语文成绩：%d\n", stuArr[i].chinese_cs);
            printf("C语言成绩：%d\n", stuArr[i].c_cs);
            if (showRank)
                printf("总成绩排名：%d\n", stuArr[i].rank);
            puts("####################");
        }
    }
}

void showData_stu(int index, int showRank)
{
    printf("学生学号：%-12d\n", stuArr[index].id);
    printf("学生姓名：%-12s\n", stuArr[index].name);
    printf("学生年龄：%-12d\n", stuArr[index].age);
    printf("学生班级：%-12d\n", stuArr[index].clNum);
    printf("学生密码：%-12s\n", stuArr[index].code);
    printf("数学成绩：%-12d\n", stuArr[index].math_cs);
    printf("语文成绩：%-12d\n", stuArr[index].chinese_cs);
    printf("C语言成绩：%-12d\n", stuArr[index].c_cs);
    if (showRank)
        printf("总成绩排名：%-12d\n", stuArr[index].rank);
}

void matrixSort_stu(int showRank)
{
    int initColumn = 2;
    int initRow = 2;

    int countRow = 0;
    int countColumn = 0;

    int intervalRow = 20;
    int intervalColumn = 9;

    int fiedNum = 5;

    if (showRank)
        intervalColumn++;

    for (int i = 0; i < len; i++)
    {

        if (stuArr[i].id > 0)
        {
            printf("\033[%d;%dH", initColumn + countColumn, initRow + intervalRow * countRow);
            printf("学生学号：%-*d\n", fiedNum, stuArr[i].id);

            printf("\033[%d;%dH", initColumn + countColumn + 1, initRow + intervalRow * countRow);
            printf("学生姓名：%-*s\n", fiedNum, stuArr[i].name);

            printf("\033[%d;%dH", initColumn + countColumn + 2, initRow + intervalRow * countRow);
            printf("学生年龄：%-*d\n", fiedNum, stuArr[i].age);

            printf("\033[%d;%dH", initColumn + countColumn + 3, initRow + intervalRow * countRow);
            printf("学生班级：%-*d\n", fiedNum, stuArr[i].clNum);

            printf("\033[%d;%dH", initColumn + countColumn + 4, initRow + intervalRow * countRow);
            printf("学生密码：%-*s\n", fiedNum, stuArr[i].code);

            printf("\033[%d;%dH", initColumn + countColumn + 5, initRow + intervalRow * countRow);
            printf("数学成绩：%-*d\n", fiedNum, stuArr[i].math_cs);

            printf("\033[%d;%dH", initColumn + countColumn + 6, initRow + intervalRow * countRow);
            printf("语文成绩：%-*d\n", fiedNum, stuArr[i].chinese_cs);

            printf("\033[%d;%dH", initColumn + countColumn + 7, initRow + intervalRow * countRow);
            printf("C语言成绩：%-*d\n", fiedNum, stuArr[i].c_cs);
            if (showRank)
                printf("\033[%d;%dH", initColumn + countColumn + 8, initRow + intervalRow * countRow);
            printf("总成绩排名：%-*d\n", fiedNum, stuArr[i].rank);

            if (countRow <= 1)
            {
                countRow++;
            }
            else
            {
                countRow = 0;
                countColumn += intervalColumn;
            }
        }
    }
    puts("");
}
