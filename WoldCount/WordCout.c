#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int getChar(FILE* fp) {//字符计数函数
	char word;
	int number = 0;
	while ((word = fgetc(fp)) != EOF) {//读取不到字符会显示EOF
			number++;//如果读到一个字符则计数加一
		
	}
	rewind(fp);
	return number;
}
int getWord(FILE* fp) {//单词计数函数
	int flag = 0;
	int number = 1;
	char word;
	while (feof(fp) == 0)//等于0表示文件未结束
	{
		word = fgetc(fp);//读取一个字符后，光标位置会后移一个字节继续读
		if (flag==0&&((word == ',')||(word == ' ') || (word == '\n'))) {
			number++;
			flag = 1;//如果此间读到的是字符，现在读到的是分隔符号，则视为读到一个单词，同时flag置1
		}
		else if (flag == 1&& !((word == ',') || (word == ' ') || (word == '\n'))) {
				flag = 0;//如果此前读到的是个分隔符，现在读到的是个单词，则flag归0
			 }
	}
	rewind(fp);
	return number;
}
int main(int argc, char* argv[]) {
	FILE* fp;
	int number;
	if (argc == 3) {
		fp = fopen(argv[2], "r");//以只读方式打开文件
		if (fp == NULL) {
			perror("错误：无法打开%s\n", argv[2]);//无法打开时报错并且显示错误原因
			exit(1);
		}
		if (!strcmp(argv[1], "-c")) { //如果第二个参数是-c则选择字符计数
			number = getChar(fp);
			printf("字符数为%d\n", number);
		}

		else if (!strcmp(argv[1], "-w")) { //如果第二个参数是-w则选择单词计数
			number = getWord(fp);
			printf("单词数为%d\n", number);
		}
	}
	return 0;
}
