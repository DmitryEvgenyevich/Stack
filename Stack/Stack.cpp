#include <iostream>
#include "Stack.h"
#include "User.h"

int main()
{
    /*Stack a;
    Stack b{ a };
    Stack c;
    c = a;*/


    Stack<User> a;
    a.show();

    a.push(User("aaa", 10));

    // a.setStep(10);

    a.push(User("bbb", 20));
    a.push(User("ccc", 12));
    a.push(User("ddd", 42));
    a.show();

    a.pop();
    a.pop();
    a.show();





    return 0;
}