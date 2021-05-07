#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int getChar(FILE* fp) {
	char word;
	int number = 0;
	while ((word = fgetc(fp)) != EOF) {//读取不到字符会显示EOF
			number++;
		
	}
	rewind(fp);
	return number;
}
int getWord(FILE* fp) {
	int flag = 0;
	int number = 1;
	char word;
	while (feof(fp) == 0)//等于0表示文件未结束
	{
		word = fgetc(fp);//读取一个字符后，光标位置会后移一个字节继续读
		if (flag==0&&((word == ',')||(word == ' ') || (word == '\n'))) {
			number++;
			flag = 1;
		}
		else if (flag == 1&& !((word == ',') || (word == ' ') || (word == '\n'))) {
				flag = 0;
			 }
	}
	rewind(fp);
	return number;
}
int main(int argc, char* argv[]) {
	FILE* fp;
	int number;
	if (argc == 3) {
		fp = fopen("fuck.txt", "r");
		if (fp == NULL) {
			perror("错误：无法打开%s\n", argv[2]);
			exit(1);
		}
		if (!strcmp(argv[1], "-c")) { 
			number = getChar(fp);
			printf("字符数为%d\n", number);
		}

		else if (!strcmp(argv[1], "-w")) { 
			number = getWord(fp);
			printf("单词数为%d\n", number);
		}
	}
	return 0;
}
