/**
    此篇介绍C语言的另一个类型，数组
    我们知道，在C语言中，所以的数值都是以值的形式传递的，但是如果一个方法的参数是数组
    那么情况就不一样了，它实际上传递的是这个数组的指针地址，也就是说如果方法的参数是数组
    那么它就可以简单的理解为引用传递，这也叫作指针退化


    同时我们发现很有意思的一点，如果我们在testCopy方法后面定义readline和copyarray方法，那么在我们进行
    编译的时候，程序会报出编译错误，因为编译语言要求，如果在某一个函数内部调用了其他函数，则其他函数的声明必须
    放在这个函数前面，这是编译器要求的，所以此时我们解决办法很简单
    1.把这两个函数放在testCopy之前，下面就是采用的这种方法。
    2.在testCopy的前面进行声明，如 int readLine(char chars[]); void copyarray(char from[], char to[]);
        此时可以不实现它，然后再在testCopy方法之后进行具体的实现即可。

*/
#include <stdio.h>
#define MAX_LENGTH 1000


/**
    读取一段话的方法，该方法返回的是这段话的长度，如果没有，返回0
*/
int readLine(char chars[]){

    int c;
    int i = 0;

    for(int a = 0; (a < MAX_LENGTH && (c = getchar()) != '\n'); a++){
        //赋值c到字符数组中
        chars[a] = c;
        ++i;
    }
    if(c == '\n'){
        chars[i] = c;
        ++i;
    }

    //此时在chars数组最后在加上一个结束符号\0
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
    此时编写一个方法，用于读取输入的字符串放入字符数组中，然后把该数组的值复制到另一个数组
*/

void testArrayCopy(){

    char chars[MAX_LENGTH];
    char targets[MAX_LENGTH];
    int len = 0;
    while((len = readLine(chars)) > 1){
        copyArray(chars, targets);
    }
    if(len > 0){
        //把char数组以字符串方式打印
        printf("%s", targets);
    }
}

/**
    编写一个程序，使其可以进行字符串反转
    此时采用原型声明的方式来做
*/
void changeArray(char from[], char to[]);

void testArrayChange(){
    char from[MAX_LENGTH];
    char res[MAX_LENGTH];
    int len = 0;
    while((len = readLine(from)) > 1){
        //调用转换函数
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
    这里展示几个外部变量的例子
*/
int changeOutter(void);
int a;
void testOutter(){
    extern int a;//此时表示a是外部变量，实际定义的地方在该方法上面
    a = 5;
    changeOutter();

    printf("a = %d     b = %d", a, a);
}

int changeOutter(void){
    extern int a;
    a = 3;
    return a;
}
