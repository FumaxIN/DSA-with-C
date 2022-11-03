#include "stdio.h"
// sample expression : [A+(B*(C-D)]
struct Stack{
    char st[50];
    int top;
}S;

int main(){
    int i,j,chk=0;
    char k;
    char exp[50];
    S.top=-1;
    printf("Enter the Expression: ");
    scanf("%s",exp);
    for(i=0;exp[i]!='\0';i++){
        chk=0;
        if(exp[i]=='{' || exp[i]=='[' || exp[i]=='(')
        {
            switch(exp[i]){
                case '{':
                    k = '{';
                    break;
                case '[':
                    k = '[';
                    break;
                case '(':
                    k = '(';
                    break;
            }
            S.top++;
            S.st[S.top]=k;
        }

        else if(exp[i]=='}' || exp[i]==']' || exp[i]==')')
        {
            char temp = S.st[S.top];
            //printf("%c",temp);
            switch(exp[i]){
                case '}':
                    if(temp == '{')
                        S.top--;
                    else
                        chk=1;
                    //printf("%d",chk);
                    break;
                case ']':
                    if(temp == '[')
                        S.top--;
                    else
                        chk=1;
                    //printf("%d",chk);
                    break;
                case ')':
                    if(temp == '(')
                        S.top--;
                    else
                        chk=1;
                    //printf("%d",chk);
                    break;
            }


        }
        if(chk==1){
            printf("\nUnbalanced");
            chk=3;
            break;
        }

    }

    if(chk!=3){
        if(S.top!=-1)
            printf("Unbalanced");
        else
            printf("Balanced");
    }



    return 0;
}
