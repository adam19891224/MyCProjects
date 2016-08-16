/**
    此练习介绍了C语言的基本操作，包括赋值，控制台打印等，并且后面通过一个打印华氏度与摄氏度转换表的练习来介绍C语言流程控制中
    循环流程的两种方式，while和for
*/

#include <stdio.h>


#define LENGTH 300
#define STEP   20
#define START  0.0


//C语言中，mian方法是可以带参数的，但是只能用下面的参数列表，这是由操作系统底层调用main函数时传入的参数，所以
//我们并不能根据自己的喜好随意定义参数列表
/**
int main(int a, char *b[]){
    printf("hello, world\n");
    return 0;
}
*/


//不带参数版main
/**
int main(){
    printf("hello, world!");
    return 0;
}
*/

//除此之外，其他任何参数形式的main函数都会导致编译错误



//==============================================================================================================================


//同时，由于printf函数永远不会主动换行，所以我们可以调用多个printf来完成同一行的打印，直到遇见\n，所以，下面的程序
//和printf("hello, world\n")打印的结果是一模一样的
/**
int main(){
    printf("hello");
    printf(",");
    printf("world");
    printf("\n");

    return 0;
}
*/


//===============================================================================================================================


//接下来展示一个根据公式:
//摄氏度 = (5/9) * (华氏度 - 32)
//然后打印出一个从0到300（等差为20）的等差数列中，摄氏度与华氏度分别是多少
/**
int main(){

    //定义两个变量表示摄氏度和华氏度
    int celsius, fahr;

    //将华氏度初始化为0;
    fahr = 0;

    //度数上线
    int length = 300;
    //等差区间
    int step = 20;

    while(fahr <= length){
        //计算摄氏度
        celsius = (5 * (fahr - 32)) / 9;

        printf("当前华氏度：%3d ------ 对应的摄氏度为：%5d\n", fahr, celsius);

        //然后把华氏度+20，用于下一次计算
        fahr += step;

        //特别注意，我们的公式给的是5/9 * (华氏度 - 32)，但是实际上却是先做的乘5 再除以9
        //原因是许多程序语言在做除法时，会进行舍位操作，即去掉末尾，比如1.9 最后会得出1， 2.1最后会得出2
        //所以5 / 9虽然为0.555，但是由于舍位会造成该值为0，所以这个表达式就变成了0 * (华氏度 - 32)，那么所有
        //结果自然而然就是0了。
        //celsius = (5 / 9) * (fahr - 32);

    }

    return 0;
}
*/
/**
    关于printf函数，它内部有一些特殊标识%d，这表示这句话中的%d将会用后面跟着的第二个参数，第三个参数替换，所以最后打印出的完整
    句子是把%d换成了后面的数字。不过要注意的是，这个标识必须和参数类型一致，由于这里定义的参数是int，所以用数字d来代替，如果我们
    定义的是浮点数float，那么此时编译就会报错，我们就应该换成%f。
    同时此打印有个问题就是不美观，因为数字不同，所以导致占的位置不同，那么打印出来就显得东倒西歪，此时我们就可以在%d标识里放一个数字，
    表示这个数字占几位，即上面我们分别用%3d和%5d来表示，即华氏度数字占3位，摄氏度数字占5位，那么打印出来的语句就比较美观了。

    第二个问题就比较尖锐了，我们知道，由于语言自身的特性，整数计算会导致舍位，所以实际上华氏度0对应的摄氏度是-17.8，那么解决这个问题的
    方式也很简单，我们不用int来声明不就完了吗，所以我们可以改为下面的函数

*/

/**
int main(){

    float celsius, fahr;
    fahr = 0;
    int length = 300, step = 20;

    printf("这是一个华氏度转为摄氏度的展示表格\n");

    while(fahr <= length){

        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("当前华氏度：%3.0f ------ 对应的摄氏度为：%5.1f\n", fahr, celsius);

        fahr += step;
    }

    return 0;
}
*/
/**
    此时我们声明两个温度为浮点型，同时我们不再使用5和9，而是用5.0和9.0，此时显示的表示把5和9当做浮点数来操作
    这样C语言就不会进行舍位了，此时有人会发现，那32怎么没有声明为32.0呢，那是因为C语言会自动进行转换，当一个浮点数
    与一个整数做运算操作时，它会自动把整数转为对应的浮点数，所以在实际计算中，32会被当做32.0处理，while括号内的fahr < length同理，
    计算机会把length这个整数当做浮点数来处理


    所以前面一样，把5.0 / 9.0换成5 / 9.0或者5.0 / 9都可以，但是5 / 9就不行了，会进行舍位，

    不过，我们还是推荐显示的把数字设置成我们希望的类型，即32写成32.0，因为编码有一个最基本的规范，
    就是方便人阅读，所以这样写，阅读代码的人就会第一时间知道32在这里是以浮点数来做运算的。

    最后的打印语句中，我们用3.0来标识，说明此时华氏度我们希望至少占3位，并去掉小数部分，而后面摄氏度的5.1表示我们希望摄氏度至少占5位
    同时保留1位小数

    除此之外，C语言还支持其他格式化标识:
    %d    表示这是一个整数
    %6d   表示这个整数占6位
    %f    表示这是一个浮点数
    %4f   表示这个浮点数至少占4位
    %4.2f 表示这个浮点数至少占4位，并且保留2位小数
    %.3f  表示这是一个浮点数，并且保留3位小数，但不带宽度
*/


//===================================================================================================================================


//接下来就展示一个同样功能的，但是是for循环版
/**
int main(){

    for(float fahr = START; fahr <= LENGTH; fahr = fahr + STEP){
        printf("当前华氏度：%3.0f  ----   对应摄氏度: %5.1f \n", fahr, ((5.0 / 9.0) * (fahr - 32)));
    }

    //我们发现，for循环表示方式就简单很多了，我们只显示的声明了一个变量fahr，其他由于都是常量，所以我们直接放入函数中即可


    //特别注意，这里可能会在编译时抛出一个错误： [Error] 'for' loop initial declarations are only allowed in C99 mode
    //此说明很明显，gcc由于是基于c89标准的，所以它不允许在for循环中初始化定义变量，即float fahr = 0.0，所以我们要把gcc的编译
    //标准换成c99标准，方式很简单，setting---complair--然后中间有一个other setting，里面输入-std=c99 即可。

}
*/
/**
    通过上面的两个方式，我们大致了解了C语言的循环操作，不过for循环中的0.0 300 20等数字如果不是我们从头开始编写的话，直接拿给
    其他人，他肯定不知道这是什么意思，所以我们最好把所有常量都赋予一个有具体意义的标识，这样其他人看起来也没有这么费事
    C语言中，有一个关键字#define，可以通过它来做这件事，它的格式是#define 名称 替换值，意思就是只要以后在程序中见到了这个名称，C语言
    都会把它换成对应的替换值

    特别注意，#define可以放在该方法之前的任何地方（注意是之前，如果放在之后，就会编译报错）,不过通常我们推荐放在文件顶部
    并且#define的末尾没有分号
*/

