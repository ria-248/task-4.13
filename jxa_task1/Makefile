CC=gcc	#gcc替换
CFLAGS=-c -o	#gcc选项

#执行文件
EXE=jxatask
#执行文件路径
EXE_PATH=usr/bin/

#获取项目的所有.c文件名
FILE_C=$(wildcard src/*.c)
#将.c文件名替换为.o文件名
FILE_O=$(patsubst %.c,%.o,$(FILE_C))


#默认执行项
ALL:$(EXE)

#将.o文件转换成可执行文件exe.out
$(EXE):$(FILE_O)
	@$(CC) -g $^ -o $(EXE_PATH)$@
	@chmod 777 $(EXE_PATH)$(EXE)

#将.c文件转换成.o文件
%.o:%.c
	@$(CC) $^ $(CFLAGS) $@

#伪目标
.PHONY:clean
#清理生成文件用
clean:
	@rm $(FILE_O) $(EXE_PATH)$(EXE)
	@ls
