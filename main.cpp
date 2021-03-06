#include"threadingtree.h"
using namespace std;

int main() {
    Bitree T = NULL;
    Bitree Thrt = T;
    while(1) {
        system("cls");
        printf("====================★★★==================菜单===================★★★=====================\n");
        printf(" =========================================================================================\n");
        printf(" |          ☆☆☆                   1.建立二叉树                          ☆☆☆        |\n");
        printf(" =========================================================================================\n");
        printf(" |          ☆☆☆                   2.前序线索化二叉树                    ☆☆☆        |\n");
        printf(" =========================================================================================\n");
        printf(" |          ☆☆☆                   3.中序线索化二叉树                    ☆☆☆        |\n");
        printf(" =========================================================================================\n");
        printf(" |          ☆☆☆                   4.后序线索化二叉树                    ☆☆☆        |\n");
        printf(" =========================================================================================\n");
        printf(" |          ☆☆☆                   5.查找元素前驱和后驱                  ☆☆☆        |\n");
        printf(" =========================================================================================\n");
        printf(" |          ☆☆☆                   6.查找父母节点                        ☆☆☆        |\n");
        printf(" ========================================================================================\n");
        printf(" |          ☆☆☆                   7.插入一个节点                        ☆☆☆        |\n");
        printf(" ========================================================================================\n");
        printf(" |          ☆☆☆                   8.删除一个节点                        ☆☆☆        |\n");
        printf(" =========================================================================================\n");
        printf(" |          ☆☆☆                   9.前序遍历                            ☆☆☆        |\n");
        printf(" =========================================================================================\n");
        printf(" |          ☆☆☆                   10.中序遍历                           ☆☆☆        |\n");
        printf(" =========================================================================================\n");
        printf(" |          ☆☆☆                   11.后序遍历                           ☆☆☆        |\n");
        printf(" =========================================================================================\n");
        printf(" |          ☆☆☆                   12.移除线索                           ☆☆☆        |\n");
        printf(" =========================================================================================\n");
        printf(" |          ☆☆☆                   13.查询深度                           ☆☆☆        |\n");
        printf(" =========================================================================================\n");
        printf(" |          ☆☆☆                   14.删除树                             ☆☆☆        |\n");
        printf(" =========================================================================================\n");
        int mark;
        scanf("%d", &mark);
        switch(mark) {
        case 1: {
            system("cls");
            int step1 = BulidTree(T);
            if(step1 == 1)
                printf("=======================================The Bitree has been built now=======================================\n");
            printf("==========================================输入任意字符回到主界面===========================================\n");
            fflush(stdin);
            getchar();
            break;
        }
        case 2: {
            system("cls");
            if(T->prior || T->next) {
                printf("The threading has already been built\n");
                fflush(stdin);
                getchar();
                break;
            }
            CreatpriorThread(T);//建立先序全线索二叉树,Thrt作为线索二叉树的头节点
            printf("=======================================前序线索化完成=======================================\n");
            printf("====================================输入任意字符回到主界面==================================");
            fflush(stdin);
            getchar();
            break;
        }
        case 3: {
            system("cls");
            if(T->prior || T->next) {
                printf("The threading has already been built\n");
                fflush(stdin);
                getchar();
                break;
            }
            Thrt = CreatMiddleThread(T);//建立中序全线索二叉树,Thrt作为线索二叉树的头节点
            printf("=======================================中序线索化完成=======================================\n");
            printf("====================================输入任意字符回到主界面==================================");
            fflush(stdin);
            getchar();
            break;
        }
        case 4: {
            system("cls");
            if(T->prior || T->next) {
                printf("The threading has already been built\n");
                fflush(stdin);
                getchar();
                break;
            }
            Thrt = CreatPostThread(T);//建立后序全线索二叉树,Thrt作为线索二叉树的头节点
            //printf("!%d",Thrt->data);
            printf("=======================================后序线索化完成=======================================\n");
            printf("====================================输入任意字符回到主界面==================================");
            fflush(stdin);
            getchar();
            break;
        }
        case 5: {
            system("cls");
            Type x, y;
            FindPriorAndNext(Thrt, x, y);//查找元素的前驱和后继
            printf("====================================输入任意字符回到主界面==================================");
            fflush(stdin);
            getchar();
            break;
        }
        case 6: {
            system("cls");
            Bitree parent = NULL;
            FindParentOfX(T, parent);  //在排序二叉树中寻找元素的父亲节点并得到相应位置
            printf("====================================输入任意字符回到主界面==================================");
            fflush(stdin);
            getchar();
            break;
        }
        case 7: {
            system("cls");
            printf("Please input the number you want to insert:");
            Type e;
            cin >> e ;
            Insert(e, Thrt);
            printf("=================================The number has been inserted ==============================\n");
            printf("====================================输入任意字符回到主界面==================================\n");
            fflush(stdin);
            getchar();
            break;
        }
        case 8: {
            system("cls");
            Delete(T, Thrt);          //删除一个节点

            CreatpriorThread(T);
            Travel_prior(T);
            RemoveThread(T);

            Thrt = CreatMiddleThread(T);
            Travel_middle(Thrt);
            RemoveThread(T);

            Thrt = CreatPostThread(T);
            Travel_post(Thrt);
            RemoveThread(T);

            printf("====================================输入任意字符回到主界面==================================");
            fflush(stdin);
            getchar();
            break;
        }
        case 9: {
            system("cls");
            CreatpriorThread(T);
            Travel_prior(T);
            printf("====================================输入任意字符回到主界面==================================");
            fflush(stdin);
            getchar();
            break;
        }
        case 10: {
            system("cls");
            Thrt = CreatMiddleThread(T); //建立中序全线索二叉树,Thrt作为线索二叉树的头节点
            Travel_middle(Thrt);
            printf("====================================输入任意字符回到主界面==================================\n");
            fflush(stdin);
            getchar();
            break;
        }
        case 11: {
            system("cls");
            Thrt = CreatPostThread(T);
            Travel_post(Thrt);
            printf("====================================输入任意字符回到主界面==================================");
            fflush(stdin);
            getchar();
            break;
        }
        case 12: {
            system("cls");
            RemoveThread(T);
            printf("=========================================线索已清除=========================================\n");//去除线索
            printf("====================================输入任意字符回到主界面==================================");
            fflush(stdin);
            getchar();
            break;
        }
        case 13: {
            system("cls");
            int depth = TreeDepth(T);
            printf("The tree's depth is %d\n", depth);
            printf("====================================输入任意字符回到主界面==================================");
            fflush(stdin);
            getchar();
            break;
        }
        case 14: {
            system("cls");
            Destory(T);
            printf("=======================================二叉树已删除=========================================\n");
            printf("====================================输入任意字符回到主界面==================================");
            fflush(stdin);
            getchar();
            break;
        }
        }
    }
    return 0;
}
