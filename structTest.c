#include <stdio.h>
#include <stdlib.h>

int num = 0;
int n = 1;

typedef struct ElementNode{
    char *data;
    struct Node *first;
    struct Node *childnode[255]; //각 노드를 하위 노드로 만들기
    struct Node *last;
    struct Node *parent;
    struct Node *nextSib;
    struct Node *prevSib;
}Node;

Node *newNode(char *text)
{
    Node *current = (Node *)malloc(sizeof(Node));
    current->data = text;
    current->first = current->last = current->parent = NULL;
    return current;
}


Node *addNode(char *text, Node *upper, int cNum)
{
    Node *adptr = (Node *)malloc(sizeof(Node));
    adptr->data = text;
    adptr->parent = upper;
    adptr->first = adptr->last = NULL;
    if(upper->first == NULL) {
        // printf("1\n");
        upper->first = adptr;
        upper->childnode[cNum] = adptr;
    }
    else if(upper->first != NULL) {
        // printf("2\n");
        upper->last = adptr;
        upper->childnode[cNum] = adptr;
    }
    return adptr;
}
//형제노드 x, 형제 노드로 이어줌
//있으면, 하위노드로, 
Node *addSib(char *text, Node *upper)
{
    Node *sibptr = (Node *)malloc(sizeof(Node));
    sibptr->data = text;
    sibptr->first = sibptr->last = sibptr->prevSib = NULL;
    sibptr->prevSib = upper;
    // printf("%d\n",cNum);
    upper->nextSib = sibptr;
    return sibptr;
}

void structTest(char* tag[]){
    Node *stp = NULL;
    Node *sstp = NULL;
    Node *test = NULL;
    Node *node[100];
    
    char *tagname;
    int c_Num = 0;
    int h_Num = 0;
    int count = 0;
    int t_Num = 0;
    
    // char *tag[100] = {"html","head","title","document","/title","/head",
                        // "body",
                        // "p","text","/p",
                        // "h2","ab","/h2",
                        // "div","abcd","/div",
                        // "img","src","\"pic_trulli.jpg\"","alt","\"Trulli\"","width","\"500\"","/img",
                        // "div","aaaa","/div",
                        // "/body","/html","\0"};
    // while(strcmp(tag[n],"\0")!=0){//마지막에 /html태그 출력 안됨
    for(int y = 0; y <30; y++){
        if(stp==NULL){
            stp = newNode(tag[n]);
            node[num] = stp;
            num++; count++;
        }
        else{
            if(strncmp(tag[n],"/",1)==0){// /만나면 상위 노드로
                    for(int i = 0; i < count; i++)
                    {
                        stp = stp->parent;
                        if(strcmp(stp->data,"body")==0)
                        {
                            count--;
                        }
                    }
                c_Num++;
                count = 0;
            }else if(strcmp(stp->data,"html")==0){
                stp = addNode(tag[n],stp,h_Num);
                node[num] = stp;
                printf("%d : %s\n",num, node[num]->data);
                num++; h_Num++; count;
                c_Num = 0;
            }else if(strcmp(stp->data,"img")==0){
                printf("imimimg\n");
                sstp=stp;
                while(1){
                    sstp = addSib(tag[n],sstp);
                    node[num] = sstp;
                    printf("11 %d : %s\n",num,sstp->data);
                    num++;n++;
                    node[num]=addNode(tag[n],sstp,0);
                    printf("11 %d : %s\n",num,node[num]->data);
                    num++; n++;
                    if(strcmp(tag[n],"/img")==0){
                        c_Num++;
                        count = 0;
                        stp = stp->parent;
                        break;
                    }
                }
            }else{
                if(count == 1){
                    stp = addNode(tag[n],stp,0);
                }else{
                    stp = addNode(tag[n],stp,c_Num);
                }
                 
                node[num] = stp;
                printf("%d : %s\n",num, node[num]->data);
                num++; count++;
            }
        }
        n++;
    }
    stp = node[0];//html
    printf("%s\n",stp->data);
    stp = stp->childnode[0];//head
    printf(" └%s\n",stp->data);
    stp = stp->childnode[0];//title
    printf(" │  └%s\n",stp->data);
    stp = stp->childnode[0];//documnet
    printf(" │      └%s\n",stp->data);
    stp = node[0]->childnode[1];//body
    printf(" └%s\n",stp->data);
    stp = stp->childnode[0];//image
    printf("    ├─%s\n",stp->data);
    printf("    │  │\n");
    stp = stp->nextSib;
    printf("    │ %s\n",stp->data);
    stp = stp->childnode[0];
    printf("    │  ├─%s\n",stp->data);
    stp = stp->nextSib;
    printf("    │ %s\n",stp->data);
    printf("    │  ├─\n");
    stp = stp->nextSib;
    printf("    │ %s\n",stp->data);
    printf("    │  ├─\n");
    stp = stp->nextSib;
    printf("    │ %s\n",stp->data);
    stp = node[4]->childnode[1];
    printf("    └─ %s\n",stp->data);
    stp = stp->childnode[0];
    printf("        └%s\n",stp->data);
    stp = node[4]->childnode[2];
    printf("    └─ %s\n",stp->data);
    stp = stp->childnode[0];
    printf("       └─%s\n",stp->data);
    stp = node[4]->childnode[3];
    printf("    └─ %s\n",stp->data);
    stp = stp->childnode[0];
    printf("       └─%s\n",stp->data);
    stp = node[4]->childnode[4];
    printf("    └─ %s\n",stp->data);
    stp = stp->childnode[0];
    printf("       └─%s\n",stp->data);
    



    // stp = node[0]->childnode[1];
    // printf("%s\n",stp->data);
    
    for(int i = 0; i < num; i++){
        free(node[i]);
    }
    // free(stp);
}