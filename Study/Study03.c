/**
    ��ƪ����C���Ե���һ�����ͣ�����
    ����֪������C�����У����Ե���ֵ������ֵ����ʽ���ݵģ��������һ�������Ĳ���������
    ��ô����Ͳ�һ���ˣ���ʵ���ϴ��ݵ�����������ָ���ַ��Ҳ����˵��������Ĳ���������
    ��ô���Ϳ��Լ򵥵����Ϊ���ô��ݣ���Ҳ����ָ���˻�


    ͬʱ���Ƿ��ֺ�����˼��һ�㣬���������testCopy�������涨��readline��copyarray��������ô�����ǽ���
    �����ʱ�򣬳���ᱨ�����������Ϊ��������Ҫ�������ĳһ�������ڲ�������������������������������������
    �����������ǰ�棬���Ǳ�����Ҫ��ģ����Դ�ʱ���ǽ���취�ܼ�
    1.����������������testCopy֮ǰ��������ǲ��õ����ַ�����
    2.��testCopy��ǰ������������� int readLine(char chars[]); void copyarray(char from[], char to[]);
        ��ʱ���Բ�ʵ������Ȼ������testCopy����֮����о����ʵ�ּ��ɡ�

*/
#include <stdio.h>
#define MAX_LENGTH 1000


/**
    ��ȡһ�λ��ķ������÷������ص�����λ��ĳ��ȣ����û�У�����0
*/
int readLine(char chars[]){

    int c;
    int i = 0;

    for(int a = 0; (a < MAX_LENGTH && (c = getchar()) != '\n'); a++){
        //��ֵc���ַ�������
        chars[a] = c;
        ++i;
    }
    if(c == '\n'){
        chars[i] = c;
        ++i;
    }

    //��ʱ��chars��������ڼ���һ����������\0
    chars[i] = '\0';

    return i;
}

void copyArray(char from[], char to[]){
    int i = 0;
    while((to[i] = from[i]) != '\0'){
        ++i;
    }
}

/**
    ��ʱ��дһ�����������ڶ�ȡ������ַ��������ַ������У�Ȼ��Ѹ������ֵ���Ƶ���һ������
*/

void testArrayCopy(){

    char chars[MAX_LENGTH];
    char targets[MAX_LENGTH];
    int len = 0;
    while((len = readLine(chars)) > 1){
        copyArray(chars, targets);
    }
    if(len > 0){
        //��char�������ַ�����ʽ��ӡ
        printf("%s", targets);
    }
}

/**
    ��дһ������ʹ����Խ����ַ�����ת
    ��ʱ����ԭ�������ķ�ʽ����
*/
void changeArray(char from[], char to[]);

void testArrayChange(){
    char from[MAX_LENGTH];
    char res[MAX_LENGTH];
    int len = 0;
    while((len = readLine(from)) > 1){
        //����ת������
        changeArray(from, res);
    }
    if(len > 0){
        printf("%s", res);
    }
}

void changeArray(char from[], char to[]){
    int len = sizeof(from)/sizeof(from[0]);
    int index = 0;
    while(index < len){
        to[index] = from[len - index];
        index++;
    }
}

//===========================================================================================================================


/**
    ����չʾ�����ⲿ����������
*/
int changeOutter(void);
int a;
void testOutter(){
    extern int a;//��ʱ��ʾa���ⲿ������ʵ�ʶ���ĵط��ڸ÷�������
    a = 5;
    changeOutter();

    printf("a = %d     b = %d", a, a);
}

int changeOutter(void){
    extern int a;
    a = 3;
    return a;
}
