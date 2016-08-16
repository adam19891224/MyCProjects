/**
    此篇介绍一套标准的输入输出

    在标准输入输出中，无论我们想把一段文本从哪里读入，或者放到哪里去，C语言都会把它当做字符流来处理，通常，文本流是由
    多行字符构成的字符序列，而每一行字符又是由0到多个字符加上末尾的换行符组成

    标准库中提供了基本的读一个字符/写一个字符的方法：getchar()与putchar()
    例如下面的操作c = getchar()
    表示变量c此时保存的是文本流的下一个字符，这个流通常是由键盘输入的一串字符中的一个
    而putchar则表示将此变量输出到某个地方，通常是以字符的形式打印到屏幕上，所以putchar可以和printf函数互相联用


*/

#include <stdio.h>


/*
    根据上面的介绍，我们就能写出下面的一个函数，即把输入的字符一个字一个字的放到输出中，说的更白一点，文件复制就是利用了这个原理
*/
int testIO(){

    //定义一个变量来保留读取的字符
    int c = getchar();

    //如果这个字符不为eof （eof即文件末尾的标识，即当程序读取一个文本内容时，如果读到最后，没有内容了，程序就会返回一个标识
    //, 用来告诉计算机这个文本读取完毕，在c语言标准库中，这个标识就是eof,，即end of file, 它定义在stdio.h标准库中）那么就继续读取字符流
    while(c != EOF){
        //将变量放入输出中
        putchar(c);
        //继续读取下一个字符
        c = getchar();
    }

    return 0;
}


//上面的代码看起来是不是很烦，所以我们可以通过简写，变成如下的方式：
void testIONew(){
    int c;
    while((c = getchar()) != EOF){
        putchar(c);
    }
}


//此时我们能很轻易的用下面的代码来证明getchar一次只能输入一个字符
void testIO2(){
    char c;
    printf("请输入一串字符\n");
    c = getchar();
    putchar(c);
}

//此时我们输入一串字符后，发现putchar只会打印出第一个字符这也是为什么上面的程序会把getchar放入循环中一样s



/**
    统计一行中输入了多少次空格，按下回车表示输入完毕
*/
void testIOcountChar(){

    int count = 0;
    char c;
    c = getchar();

    while(c != '\n'){
        if(c == ' '){
            ++ count;
        }
        c = getchar();
    }

    printf("按下换行符后，程序终止，此次输入过程中共有空格：%d个", count);

}

/**
    将多个空格合并为一个
*/
void testCombineBlock(){
    char c = getchar();
    int type = 0;
    while(c != '\n'){
        if(c == ' '){
            type = 1;
        }else{
            if(type == 1){
                putchar(' ');
                putchar(c);
                type = 0;
            }else{
                putchar(c);
            }
        }
        c = getchar();
    }
    printf("\n输入完毕\n");
}


/**
    此时编写一个统计一行话中有多少字符，多少单词的代码，
    由于是单词，所以这里简单的就以空格作为一个单词的结束
*/

void countString(){
    int chars = 0, words = 1, c = 0;
    while((c = getchar()) != '\n'){
        //字符数++
        ++ chars;
        if(c == ' '){
            //此时表示一个单词结束，则单词数+1
            ++ words;
        }
    }

    printf("统计完毕，这一段话中，共有单词：%d 个， 总共包含字符为：%d 个 \n", words, chars);
}


/**
    此时编写一个程序，以每一行一个单词的形式输出一段话
*/
void showWordsByLine(){
    int c;
    while((c = getchar()) != '\n'){
        if(c == ' '){
            //如果读取到空格，则说明一个单词已经读取完毕，则显示输出一个换行
            printf("\n");
        }else{
            //输出单词
            putchar(c);
        }
    }

}

