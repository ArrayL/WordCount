#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int getChar(FILE* fp) {//�ַ���������
	char word;
	int number = 0;
	while ((word = fgetc(fp)) != EOF) {//��ȡ�����ַ�����ʾEOF
			number++;//�������һ���ַ��������һ
		
	}
	rewind(fp);
	return number;
}
int getWord(FILE* fp) {//���ʼ�������
	int flag = 0;
	int number = 1;
	char word;
	while (feof(fp) == 0)//����0��ʾ�ļ�δ����
	{
		word = fgetc(fp);//��ȡһ���ַ��󣬹��λ�û����һ���ֽڼ�����
		if (flag==0&&((word == ',')||(word == ' ') || (word == '\n'))) {
			number++;
			flag = 1;//����˼���������ַ������ڶ������Ƿָ����ţ�����Ϊ����һ�����ʣ�ͬʱflag��1
		}
		else if (flag == 1&& !((word == ',') || (word == ' ') || (word == '\n'))) {
				flag = 0;//�����ǰ�������Ǹ��ָ��������ڶ������Ǹ����ʣ���flag��0
			 }
	}
	rewind(fp);
	return number;
}
int main(int argc, char* argv[]) {
	FILE* fp;
	int number;
	if (argc == 3) {
		fp = fopen(argv[2], "r");//��ֻ����ʽ���ļ�
		if (fp == NULL) {
			perror("�����޷���%s\n", argv[2]);//�޷���ʱ��������ʾ����ԭ��
			exit(1);
		}
		if (!strcmp(argv[1], "-c")) { //����ڶ���������-c��ѡ���ַ�����
			number = getChar(fp);
			printf("�ַ���Ϊ%d\n", number);
		}

		else if (!strcmp(argv[1], "-w")) { //����ڶ���������-w��ѡ�񵥴ʼ���
			number = getWord(fp);
			printf("������Ϊ%d\n", number);
		}
	}
	return 0;
}
