#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int getChar(FILE* fp) {
	char word;
	int number = 0;
	while ((word = fgetc(fp)) != EOF) {//��ȡ�����ַ�����ʾEOF
			number++;
		
	}
	rewind(fp);
	return number;
}
int getWord(FILE* fp) {
	int flag = 0;
	int number = 1;
	char word;
	while (feof(fp) == 0)//����0��ʾ�ļ�δ����
	{
		word = fgetc(fp);//��ȡһ���ַ��󣬹��λ�û����һ���ֽڼ�����
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
			perror("�����޷���%s\n", argv[2]);
			exit(1);
		}
		if (!strcmp(argv[1], "-c")) { 
			number = getChar(fp);
			printf("�ַ���Ϊ%d\n", number);
		}

		else if (!strcmp(argv[1], "-w")) { 
			number = getWord(fp);
			printf("������Ϊ%d\n", number);
		}
	}
	return 0;
}
