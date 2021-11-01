//
// Created by dolly on 2021/10/10.
//

#include <iostream>
#include<queue>
#include<stack>
#include<math.h>
#define ERROR 0
#define OK 1

using namespace std;

typedef int Staus;
typedef double ElemType;

// 1 2 + 4 * 5 + 3 -

bool Get_ops(stack<ElemType>* st, ElemType* op1, ElemType* op2)
{
    if (st->size() < 2)
        return ERROR;
    *op1 = st->top();
    st->pop();
    *op2 = st->top();
    st->pop();

    return OK;
}

Staus Solve(stack<ElemType>* st, char oper)
{
    bool flag = 0;
    ElemType oper1, oper2;
    flag = Get_ops(st, &oper1, &oper2);
    if (flag)
    {
        switch (oper)
        {
            case('+'):st->push(oper2 + oper1); break;
            case('-'):st->push(oper2 - oper1); break;
            case('*'):st->push(oper2 * oper1); break;
            case('/'):if (!oper1)
                {
                    cout << "Divide by 0！" << endl;
                    return ERROR;
                }
                else st->push(oper2 / oper1);
                break;
            case('^'):st->push(pow(oper2, oper1)); break;
        }
    }
    else return ERROR;

    return OK;
}

int main()
{
    stack<ElemType> suffix;
    char c;
    ElemType t;
    c = getchar();
    while (c != '#')
    {
        switch (c)
        {
            case(' '):break;
            case('+'):;
            case('-'):;
            case('*'):;
            case('/'):;
            case('^'):Solve(&suffix, c); break;
            default:ungetc(c, stdin);
                cin >> t;
                suffix.push(t);
        }
        c = getchar();
    }
    cout << suffix.top() << endl;
    return 0;
}

