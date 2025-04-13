#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/ioctl.h>
#include <unistd.h>

char str_int[200];
char str_inputInt[200];
char str_input[200];


//用户输入的字符串有非数字时，剔除非数字字符，输出数字字符串
char *inputlimit_int();
//判断输入字符串是否全是数字，返回字符串的地址，参数为输入时的提示文字
char* inputStrIsInt(char*);
//输入通用函数，用于替代sacnf和getchar
char* inputStr();


// 获取终端尺寸
void get_terminal_size(int *rows, int *cols);
// 绘制界面
void drawInterface(const char *str, int border_width, int border_height);



//【弃用】判断字符串是否有非数字字符，有返回0，数字字符串返回1
int strIsInt(char *);
//【弃用】当用户在getchar中上连续输入时，吸收多余的字符
void clearInput();

#endif // !__COMMON_H__
