#include "MyString.h"


int stand_func(MyString& mes)
{
    //std::cout << mes << std::endl;
    mes.Print();
    return 1;
}

int case_0()
{
    MyString mes;
    stand_func(mes);
    return 1;
}

int case_1()
{
    MyString mes("1234");
    stand_func(mes);
    return 1;
}

int case_2()
{
    MyString mes({ 's','t','r','i','n','g' });
    stand_func(mes);
    return 1;
}

int case_3()
{
    std::string s = "";
    MyString mes(s);
    stand_func(mes);
    return 1;
}

int case_4()
{
    MyString mes("hello", -100);
    stand_func(mes);
    return 1;
}

int case_5()
{
    MyString mes(100,'1');
    stand_func(mes);
    return 1;
}

int case_6()
{
    MyString mes("hello", 10);
    stand_func(mes);
    mes.shrink_to_fit();
    stand_func(mes);
    MyString a1("Hello world!");
    a1.erase(5, 6);
    std::cout << a1 << " " << a1.size() << " " << a1.capacity() << std::endl;
    a1.shrink_to_fit();
    std::cout << a1 << " " << a1.size() << " " << a1.capacity() << std::endl;


    return 1;
}

int case_7()
{
    MyString mes("hello");
    stand_func(mes);
    //mes.shrink_to_fit();
    mes.insert(mes.length(), 2, 'c');
    stand_func(mes);
    MyString a1 = "aaaaa";
    a1.insert(0, 1, '!');
    std::cout << a1 << std::endl;
    a1.insert(3, 2, '@');
    std::cout << a1 << std::endl;

    mes.insert(0,"asdf");
    stand_func(mes);
    mes.insert(mes.length(), "@@",0);
    stand_func(mes);
    MyString a2 = "aaaaa";
    a2.insert(1, "@@@@@");
    std::cout << a2 << std::endl;
    MyString a3 = "aaaaa";
    a3.insert(1, "@@@@@", 2);
    std::cout << a3 << std::endl;

    MyString a4 = "aaaaa";
    std::string s1 = "@@@@@";
    a4.insert(1, s1);
    std::cout << a4 << std::endl;

    MyString a5 = "aaaaa";
    std::string s2 = "@@@@@";
    a5.insert(1, s2, 2);
    std::cout << a5 << std::endl;

    return 1;

}

int case_9()
{
    MyString mes("hellooo");
    std::string s = "gagaga";
    stand_func(mes);
    //mes.shrink_to_fit();
    mes.insert(0, s);
    stand_func(mes);
    mes.insert(mes.length(), s);
    stand_func(mes);
    return 1;
}

int case_10()
{
    MyString mes("hello");
    std::string s = "1234";
    stand_func(mes);
    //mes.shrink_to_fit();
    mes.insert(0, s, 2);
    stand_func(mes);
    mes.insert(mes.length(), s,4);
    stand_func(mes);
    return 1;
}

int case_11()
{
    MyString mes("hello");
    stand_func(mes);
    mes.erase(mes.length()-2, 1);
    stand_func(mes);
    MyString a1("Hello world!");
    a1.erase(5, 6);
    std::cout << a1 << std::endl;


    return 1;
}

int case_12()
{
    MyString mes;
    stand_func(mes);
    mes.append("hello", 0, 5);
    stand_func(mes);

    MyString a1;
    a1.clear();
    a1.append(3, '!');
    std::cout << a1 << std::endl;
    a1.append(3, '@');
    std::cout << a1 << std::endl;
    MyString a2;
    a2.clear();
    a2.append("Hello ");
    std::cout << a2 << std::endl;
    a2.append("world");
    std::cout << a2 << std::endl;
    MyString a3;
    a3.clear();
    a3.append("Hello world", 0, 6);
    std::cout << a3 << std::endl;
    a3.append("Hello world", 6, 5);
    std::cout << a3 << std::endl;
    MyString a4;
    std::string s1 = "Hello ", s2 = "world";
    a4.clear();
    a4.append(s1);
    std::cout << a4 << std::endl;
    a4.append(s2);
    std::cout << a4 << std::endl;
    MyString a5;
    std::string s3 = "Hello world";
    a5.clear();
    a5.append(s3, 0, 6);
    std::cout << a5 << std::endl;
    a5.append(s3, 6, 5);
    std::cout << a5 << std::endl;


    return 1;
}

int case_13()
{
    MyString mes;
    stand_func(mes);
    mes.append("hello");
    stand_func(mes);
    mes.append(" world");
    stand_func(mes);
    return 1;
}

int case_14()
{
    MyString mes;
    stand_func(mes);
    mes.append(3, '!');
    stand_func(mes);
    mes.append(5, 'f');
    stand_func(mes);
    return 1;
}

int case_15()
{
    MyString a4;
    std::string s1 = "Hello ", s2 = "world";
    a4.clear();
    a4.append(s1);
    std::cout << a4 << std::endl;
    a4.append(s2);
    std::cout << a4 << std::endl;
    return 1;
}



int case_16()
{
    MyString a5;
    std::string s3 = "Hello world";
    a5.clear();
    a5.append(s3, 0, 6);
    std::cout << a5 << std::endl;
    a5.append(s3, 6, 4);
    std::cout << a5 << std::endl;

    return 1;
}

int case_17()
{
    MyString a1 = "hello amazing world";
    a1.replace(6, 7, "wonderful");
    std::cout << a1 << std::endl;

    MyString a2 = "hello amazing world";
    std::string s1 = "wonderful";
    a2.replace(6, 7, s1);
    std::cout << a2 << std::endl;

    return 1;
}

int case_18()
{
    MyString a2 = "hello amazing world";
    std::string s1 = "wonderful";
    a2.replace(6, 7, s1);
    std::cout << a2 << std::endl;

    return 1;
}

int case_19()
{
    MyString a1 = "hello amazing world", a2;
    a2 = a1.substr(6);
    std::cout << a2 << std::endl;

    MyString a3 = "hello amazing world", a4;
    a4 = a3.substr(6, 7);
    std::cout << a4 << std::endl;

    return 1;
}

int case_20()
{
    //MyString a3 = "hello amazing world", a4;
    ////a4 = a3.substr(6, 7);
    //std::cout << a3.substr(6, 7).data() << std::endl;
    return 1;
}

int case_21()
{
    MyString a = "hello amazing world amazing";
    int i;
    i = a.find("amazing");
    std::cout << i << std::endl;

    return 1;
}

int case_22()
{
    MyString a = "hello amazing world amazing";
    int i;
    i = a.find("amazing", 7);
    std::cout << i << std::endl;


    return 1;
}

int case_23()
{
    MyString a = "hello amazing world amazing";
    int i;
    std::string s = "amazing";
    i = a.find(s);
    std::cout << i << std::endl;
    return 1;
}

int case_24()
{
    MyString a = "hello amazing world amazing";
    int i;
    std::string s = "amazing";
    i = a.find(s, 7);
    std::cout << i << std::endl;
    return 1;
}

int case_25()
{
    MyString a1;
    a1 = "hello111";
    std::cout << a1 << std::endl;
    return 1;
}

int case_26()
{
    MyString a2;
    std::string s1 = "hello222";
    a2 = s1;
    std::cout << a2 << std::endl;
    return 1;
}

int case_27()
{
    MyString a3;
    a3 = '!';
    std::cout << a3 << std::endl;
    return 1;
}

int case_28()
{
    MyString a1("hel"), a2("lo"), a3;
    a3 = a1 + a2;
    std::cout << a1 << " " << a2 << " " << a3 << std::endl;
    return 1;
}

int case_29()
{
    MyString a4("hel"), a5;
    a5 = a4 + "lo";
    std::cout << a4 << " " << a5 << std::endl;
    return 1;
}

int case_30()
{
    MyString a6("hel"), a7;
    std::string s1 = "lo1234";
    a7 = a6 + s1;
    std::cout << a6 << " " << a7 << std::endl;
    std::cout << a7.capacity() << " " << a7.length()  << std::endl;
    return 1;
}

int case_31()
{
    MyString a1("hel"), a2("lo");
    a1 += a2;
    std::cout << a1 << " " << a2 << std::endl;
    return 1;
}

int case_32()
{
    MyString a3("hel");
    std::string s1 = "1234lo";
    a3 += s1;
    std::cout << a3 << std::endl;
    return 1;
}

int case_33()
{
    MyString a4;
    a4 = "hello";
    std::cout << a4[2] << std::endl;
    return 1;
}

int case_34()
{
    MyString a, b;
    a = "abcd";
    b = "abcc";
    std::cout << (a == b) << (a != b) << (a > b) << (a >= b) << (a < b) << (a <= b) << std::endl;
    return 1;
}

int case_35()
{
    MyString a4;
    std::cin >> a4;
    std::cout << a4 << std::endl;
    return 1;
}

int case_36()
{
    // 010011
    MyString a, b;
    a = "abca";
    b = "abca";
    std::cout << (a == b) << (a != b) << (a > b) << (a >= b) << (a < b) << (a <= b) << std::endl;
    return 1;
}

int main()
{
    int mode = 30;
    switch (mode)
    {
    case 0:
        case_0();
        break;
    case 1:
        case_1();
        break;
    case 2:
        case_2();
        break;
    case 3:
        case_3();
        break;
    case 4:
        case_4();
        break;
    case 5:
        case_5();
        break;
    case 6:
        case_6();
        break;
    case 7:
        case_7();
        break;
    case 8:
        //case_8();
        break;
    case 9:
        case_9();
        break;
    case 10:
        case_10();
        break;
    case 11:
        case_11();
        break;
    case 12:
        case_12();
        break;
    case 13:
        case_13();
        break;
    case 14:
        case_14();
        break;
    case 15:
        case_15();
        break;
    case 16:
        case_16();
        break;
    case 17:
        case_17();
        break;
    case 18:
        case_18();
        break;
    case 19:
        case_19();
        break;
    case 20:
        case_20();
        break;
    case 21:
        case_21();
        break;
    case 22:
        case_22();
        break;
    case 23:
        case_23();
        break;
    case 24:
        case_24();
        break;
    case 25:
        case_25();
        break;
    case 26:
        case_26();
        break;
    case 27:
        case_27();
        break;
    case 28:
        case_28();
        break;
    case 29:
        case_29();
        break;
    case 30:
        case_30();
        break;
    case 31:
        case_31();
        break;
    case 32:
        case_32();
        break;
    case 33:
        case_33();
        break;
    case 34:
        case_34();
        break;
    case 35:
        case_35();
        break;
    case 36:
        case_36();
        break;

    }




    
}