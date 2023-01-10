/*
* 名称: 命名空间和异常测试
* 
* 收获:
* 1、学会了抛出异常和接收异常
* 2、命名空间可以不连续，可以套娃
* 3、using语句
* 4、命名空间和作用域
*/

#include <iostream>
#define USING_TEST 0

#if USING_TEST == 0         //不使用

#elif USING_TEST == 1       //全局using
using namespace std;
#elif USING_TEST == 2       //只有cout
using std::cout;
#endif 

double division(int a, int b);
void value(const char * i);

void abnormal_test(void);
void abnormal_test_2(void);
void using_test(void);
void namespace_test_1(void);
void namespace_test_2(void);
void namespace_test_3_1(void);

int main()
{
    //abnormal_test();
    //abnormal_test_2();
    //using_test();
    //namespace_test_1();
    //namespace_test_2();
    namespace_test_3_1();

    std::cout << "\n测试完成\n";
    return 0;
}

double division(int a, int b)
{
    if (!a && !b)
    {
        throw 1;
    }
    if (!a)
    {
        throw 1.1;
    }
    if (!b)
    {
        throw 'e';
    }
    std::cout << "正在计算---" << std::endl;
    return (double)a / (double)b;
}

void value(const char* i)
{
    throw i;
    std::cout << "函数运行完成!" << std::endl;
}

void abnormal_test(void)
{
    double result = -1;
//    int num_1 = 1, num_2 = 1;    // 正常运行
//    int num_1 = 0, num_2 = 1;     //抛出double类型异常
//    int num_1 = 1, num_2 = 0;       //抛出char类型异常
//      int num_1 = 0, num_2 = 0;

    int num_1 = 10, num_2 = 0;

    try {
        result =  division(num_1, num_2);
    }
    catch (double temp){
        std::cerr << "被除数为0: temp = " << temp << std::endl;
        result = division(num_1, num_2);
    }
    catch(char){
        std::cerr << "除数为0!-- char " << std::endl;
        result = division(num_1, num_2 + 1);
    }
    catch (int) {
        std::cerr << "除数和被除数都为0!--int" << std::endl;
        result = division(num_1, num_2 + 1);
    }


    std::cout << "result = " << result << std::endl;
}

void abnormal_test_2(void)
{
    try
    {
        value("test");
    }
    catch (const char * str)
    {
        std::cerr << "ERROR : " << str << std::endl;
    }

}

void using_test(void)
{
#if USING_TEST == 0         //不使用
    std::cout << "不使用using" << std::endl;
#elif USING_TEST == 1       //全局using
    cout << "全局using" << endl;
#elif USING_TEST == 2       //只有cout
    cout << "只有cout" << std::endl;
#endif 

}

namespace space_1
{
    void fun_report(void) { std::cout << "report : namespace 1 " << std::endl; }
}
namespace space_2
{
    void fun_report(void) { std::cout << "report : namespace 2 " << std::endl; }
}
namespace space_1
{
    namespace space_3
    {
        void fun_report(void) { std::cout << "report : namespace 3 " << std::endl; }
    }

}

int var = 1111;
namespace space_4
{
    int var = 222;
    namespace space_5
    {
        int var = 33;
        void namespace_test_3_3(void)
        {
            std::cout << "(in space_4::space_5) var = " << var << std::endl;
            std::cout << "space_4::var = " << space_4::var << std::endl;
            //   std::cout << "space_5::var = " << space_5::var << std::endl;  //无法直接找到
            std::cout << "space_4::space_5::var = " << space_4::space_5::var << std::endl;
            std::cout << "::var = " << ::var << std::endl;
        }
    }
    void namespace_test_3_2(void)
    {
        std::cout << "(in space_4) var = " << var << std::endl;
        std::cout << "space_4::var = " << space_4::var << std::endl;
        //   std::cout << "space_5::var = " << space_5::var << std::endl;  //无法直接找到
        std::cout << "space_4::space_5::var = " << space_4::space_5::var << std::endl;
        std::cout << "::var = " << ::var << std::endl;
    }
}

void namespace_test_1(void)
{
    space_1::fun_report();
    space_2::fun_report();
}

void namespace_test_2(void)
{
    space_1::space_3::fun_report();
}

void namespace_test_3_1(void)
{
    std::cout << "(in main) var = " << var << std::endl;
    std::cout << "space_4::var = " << space_4::var << std::endl;
 //   std::cout << "space_5::var = " << space_5::var << std::endl;  //无法直接找到
    std::cout << "space_4::space_5::var = " << space_4::space_5::var << std::endl;
    std::cout << "::var = " << ::var << std::endl;

    std::cout << std::endl;

    space_4::namespace_test_3_2();

    std::cout << std::endl;

    space_4::space_5::namespace_test_3_3();

    std::cout << std::endl;
}

