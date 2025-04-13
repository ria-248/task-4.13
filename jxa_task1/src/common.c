#include "../include/common.h"

void clearInput()
{
    int c;
    while (c = getchar() != '\n' && c != EOF)
        ;
}

char *inputlimit_int()
{
    char *a1 = malloc(1);

    while (1)
    {
        *a1 = getchar();
        if (*a1 >= '0' && *a1 <= '9')
        {
            strcat(str_int, a1);
        }

        if (*a1 == '\n')
            break;
    }

    a1 = NULL;

    free(a1);

    return str_int;
}

int strIsInt(char *str)
{
    for (int i = 0; str[i] != 0; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}

char *inputStrIsInt(char *tips)
{
    while (1)
    {
        bzero(str_inputInt, 200);
        int uflag = 0;

        puts(tips);

        fgets(str_inputInt, 200, stdin);

        for (int i = 0; str_inputInt[i] != 0; i++)
        {
            if (str_inputInt[i] == '\n')
                str_inputInt[i] = '\0';
        }

        for (int i = 0; str_inputInt[i] != 0; i++)
        {
            if (str_inputInt[i] < '0' || str_inputInt[i] > '9')
            {
                puts("\n只能输入数字，请重新输入：");
                uflag = 1;
                break;
                ;
            }
            else if (str_inputInt[i] == '\n')
            {
                str_inputInt[i] = '\0';
                break;
            }
        }

        if (uflag == 1)
            continue;
        break;
    }
    return str_inputInt;
}

char *inputStr()
{
    bzero(str_input, 200);
    fgets(str_input, 200, stdin);
    for (int i = 0; str_input[i] != 0; i++)
    {
        if (str_input[i] == '\n')
            str_input[i] = '\0';
    }
    return str_input;
}



// 获取终端尺寸
void get_terminal_size(int *rows, int *cols)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    *rows = w.ws_row;
    *cols = w.ws_col;
}

void drawInterface(const char *str, int border_width, int border_height)
{
    // 获取终端尺寸
    int term_rows, term_cols;
    get_terminal_size(&term_rows, &term_cols);

    // 窗口参数
    const char *text = str;
    int text_display_len = strlen(text) / 3 * 2 + 2; // 12个汉字 * 2宽度

    // 计算居中位置
    int start_row = (term_rows - border_height) / 2;
    int start_col = (term_cols - border_width) / 2;
    int start_fix = border_height / 2;

    // 计算文字间距
    int space_total = border_width - 2 - text_display_len;
    int space_left = space_total / 2;
    // int space_right = space_total - space_left;

    // ANSI控制码：清屏并隐藏光标
    printf("\033[2J\033[?25l");

    // 绘制顶边
    printf("\033[%d;%dH", start_row, start_col);
    for (int i = 0; i < border_width; i++)
        printf("#");

    // 绘制中间部分
    for (int i = 1; i < border_height - 1; i++)
    {
        printf("\033[%d;%dH#", start_row + i, start_col);
        printf("\033[%d;%dH#", start_row + i, start_col + border_width - 1);
    }

    // 添加文字
    printf("\033[%d;%dH#", start_row + start_fix, start_col);
    printf("\033[%dC", space_left + 1); // 向右移动光标
    printf("%s", text);
    printf("\033[%d;%dH", start_row + border_height - 1, start_col);

    // 绘制底边
    for (int i = 0; i < border_width; i++)
        printf("#");

    // 重置光标位置并显示光标
    printf("\033[%d;0H\033[?25h", term_rows);
    fflush(stdout);

}
