#include <stdio.h>
#include <stdlib.h>

int num = 0;
int i = 0;
int istag = 0;

typedef struct ElementNode{
    char *data;
    struct Node *first;
    struct Node *childnode[255]; //각 노드를 하위 노드로 만들기
    struct Node *last;
    struct Node *parent;
}Node;

typedef struct NodeList{
    char *data;
    struct Node *first;
    struct Node *last;
    struct Node *parent;
    struct Node *nextSib;
    struct Node *prevSib;
}List;

Node *newEnode(char *text)
{
    Node *current = (Node *)malloc(sizeof(Node));
    current->data = text;
    current->first = current->last = current->parent = NULL;
    return current;
}

Node *addEnode(char *text, Node *upper)
{
    Node *adEptr = (Node *)malloc(sizeof(Node));
    adEptr->data = text;
    adEptr->parent = upper;
    adEptr->first = adEptr->last = NULL;
    if(upper->first == NULL) {
        upper->first = adEptr;
    }
    else{
        upper->last = adEptr;
    }
    return adEptr;
}

Node *addNode(char *text, Node *upper, int cNum)
{
    Node *adptr = (Node *)malloc(sizeof(Node));
    adptr->data = text;
    adptr->parent = upper;
    adptr->first = adptr->last = NULL;
    if(upper->first == NULL) {
        printf("1\n");
        upper->first = adptr;
        upper->childnode[cNum] = adptr;
    }
    else if(upper->first != NULL) {
        printf("2\n");
        upper->last = adptr;
        upper->childnode[cNum] = adptr;
    }
    return adptr;
}

Node *addSib(char *text, Node *upper, int cNum)
{
    Node *adptr = (Node *)malloc(sizeof(Node));
    adptr->data = text;
    adptr->parent = upper;
    adptr->first = adptr->last = NULL;
    printf("%d\n",cNum);
    if(upper->first == NULL) {
        upper->first = adptr;
        upper->childnode[cNum] = adptr;
    }
    else{
        upper->last = adptr;
        upper->childnode[cNum] = adptr;
    }
    return adptr;
}

void main(){
    Node *stp = NULL;
    Node *node[100];
    
    char *tagname;
    int c_Num = 0;
    
    char *tag[100] = {"html","head","title","document","/title","/head","body","p","text","/p","p","text2","/p","/body","/html","\0"};
    // tagname = "html";
    // if(strcmp(tag[11],"\0")==0){
    //     printf("ok\n");
    // }

    while(1){//마지막에 /html태그 출력 안됨
        if(strcmp(tag[i],"\0")==0){
            break;
        }
        else if(stp==NULL){
            stp = newEnode(tag[i]);
            node[num] = stp;
            // printf("%d\n",num);
            // printf("1\n");
            // printf("%s\n",node[num]->data);
            num++;
        }
        else{
            if(strncmp(tag[i],"/",1)==0){// /만나면 상위 노드로
                stp = stp->parent;
                // printf("%d\n",num);
                // printf("2\n");
                // printf("%s\n",stp->data);
            }else{
                if(strcmp(tag[i],"document")==0 || strcmp(tag[i],"p")==0 
                    ||strcmp(tag[i],"img")==0){
                    stp = addNode(tag[i],stp,num);
                    node[num] = stp;
                    // printf("%d\n",num);
                    // printf("3\n");
                    // printf("%s\n",node[num]->data);
                    num++; 
                }else{
                    // printf("%s\n",tag[i]);
                    stp = addNode(tag[i],stp,num);
                    node[num] = stp;
                    // printf("%d\n",num);
                    // printf("3\n");
                    // printf("%s\n",node[num]->data);
                    num++;
                }
            }
        }
        i++;
    }
    int a = 1;
    stp=newEnode("body");
    node[0] = stp;
    stp=addNode("p",stp,0);
    node[1] = stp;
    stp = stp->parent;
    stp=addNode("img",stp,1);
    node[2] = stp;
    
    printf("okokok\n");
    stp = node[0]->childnode[1];
    printf("%s\n",stp->data);
    
    free(stp);
    for(int i = 0; i < num; i++){
        free(node[num]);
    }
}