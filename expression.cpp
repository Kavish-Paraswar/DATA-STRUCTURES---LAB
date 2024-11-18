#include <iostream>
#include <cstdlib>
#include <stack>
#include <cstring>
using namespace std;

stack<char> s;

char pop2()
{
    if (s.empty())
    {
        return 0;
    }
    char a = s.top();
    s.pop();
    return a;
}
void reverse(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void inf_post(char *inf, char *post)
{
    int i = 0, j = 0;
    char token, x;
    for (i = 0; inf[i] != 0; i++)
    {
        token = inf[i];
        if (token == '(')
        {
            s.push(token);
        }
        else if (isalnum(token))
        {
            post[j++] = token;
        }
        else if (token == ')')
        {
            while ((x = pop2()) != '\0')
            {
                if (x != ')' && x != '(')
                    post[j++] = x;
            }
        }
        else
        {
            s.push(token);
        }
    }
}
void inf_pref(char *inf, char *pref)
{
    int len = strlen(inf);
    char revInf[20];
    strcpy(revInf, inf);
    reverse(revInf); 
    for (int i = 0; i < len; i++)
    {
        if (revInf[i] == ')')
            revInf[i] = '(';
        else if (revInf[i] == '(')
            revInf[i] = ')';
    }
    
    char post[20] = {};
    inf_post(revInf, post); 
    int postLen = strlen(post);
    

    for (int i = 0; i < postLen; i++)
    {
        pref[i] = post[postLen - i - 1];
    }
    pref[postLen] = '\0';
}

int main()
{

    char inf[20] = {"(a+b)^c/d*(e-f)"};
    char pref[20] = {};
    char post[20] = {};
    inf_pref(inf, pref);
    for (char x : pref)
    {
        cout << x << " ";
    }
}