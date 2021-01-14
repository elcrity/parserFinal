#include "function.h"
#include "variable.h"
char *arr[126];
int arrnum;

void saveTag(char *name, char *start, char *end, int num) {
    
    switch(num) {
        case 0 :
            memcpy(name, ++start, end - start);         //바디태그의 끝 >에서 한칸 옮긴 H ~ <까지 text에 넣음
            name[end - start] = 0;
            break;
        case 1 :
            memcpy(name, start, end - start);         //바디태그의 끝 >에서 한칸 옮긴 H ~ <까지 text에 넣음
            name[end - start] = 0;
            break;
        case 2 :
            memcpy(name, start+1, end - start);         //바디태그의 끝 >에서 한칸 옮긴 H ~ <까지 text에 넣음
            name[(end-1) - start] = 0;
            break;
    }
}

void fp_saveTag(char *name, char *start, char *end, char **current, int num) {
    char **dest = &end;
    switch(num) {
        case 0 :
            *dest = *current;
            memcpy(name, ++start, end - start);         //바디태그의 끝 >에서 한칸 옮긴 H ~ <까지 text에 넣음
            name[end - start] = 0;
            break;
        case 1 :
            *dest=*current;
            memcpy(name, start, end - start);         //바디태그의 끝 >에서 한칸 옮긴 H ~ <까지 text에 넣음
            name[end - start] = 0;
            break;
        case 2 :
            *dest=*current;
            memcpy(name, start+1, end - start);         //바디태그의 끝 >에서 한칸 옮긴 H ~ <까지 text에 넣음
            name[(end-1) - start] = 0;
            break;
    }
}

void rp_saveTag(char *name, char *start, char *end, int num) {
    switch(num){
        case 0 :
            memcpy(name, ++start, end - start);         //바디태그의 끝 >에서 한칸 옮긴 H ~ <까지 text에 넣음
            name[end - start] = 0;
            start = end;
            break;
        case 1 :
            memcpy(name, start, end - start);         //바디태그의 끝 >에서 한칸 옮긴 H ~ <까지 text에 넣음
            name[end - start] = 0;
            start=end;
            break;
        case 2 :
            memcpy(name, start+1, end - start);         //바디태그의 끝 >에서 한칸 옮긴 H ~ <까지 text에 넣음
            name[(end-1) - start] = 0;
            start=end;
            break;
    }
}

int toDom(int n, char* name) {
    char *arr[100];
    arr[n] = name;
    printf("tree %d %s\n", n, arr[n]);
    n++;
    return n;
}

char* copyChar(char* src)
{
    char *dst = NULL;
    dst = (char*)malloc(sizeof(char) * strlen(src + 1));
    strcpy(dst, src);
    arr[arrnum] = dst;
	//int cairoCount;
	//cairo_text[cairoCount] = dst;
    if(strcmp(arr[arrnum], "/img") != 0)
        printf("%s\n", arr[arrnum]);
    arrnum++;
}

const char* namePush(char* src) {
	return src;	
}

const void eliminate(char* src) {
	char msg[100];
	char msgN[100];
	sprintf(msg, src);
	int i = 0, c = 0; // 쌍따옴표 제거
	for(; i < strlen(msg); i++) {
    //if (isalnum(msg[i]))  // msg 문자(a-z, A-Z, 0-9)를 제외한 모든것 제거하고 싶은 경우 사용
    if (msg[i] != '\"') {
        msgN[c] = msg[i];
        c++;
    }
}
	msgN[c] = '\0';
	strcpy(src, msgN);
	printf("New: %s\n", src);
}


/*char msg[100];

char msgN[100];

sprintf(msg, "This is text.");

int i = 0, c = 0; // 쌍따옴표 제거
for(; i < strlen(msg); i++)
{
    //if (isalnum(msg[i]))  // msg 문자(a-z, A-Z, 0-9)를 제외한 모든것 제거하고 싶은 경우 사용
    if (msg[i] != '\"')             // msg 에서 쌍따옴표 제외
    {
        msgN[c] = msg[i];
        c++;
    }
}
msgN[c] = '\0';
char* cairoChar(char* src) {
	char *cairo_temp = NULL;
	cairo_temp = (char*)malloc(sizeof(char) * strlen(src + 1));
	strcpy(cairo_temp, src);
	cairo_text[arrnum] = cairo_temp;
	arrnum++;
}*/
/*char* copyChar_text(char* src)
{
	char *cairo_text = NULL;
    char *dst = NULL;
    dst = (char*)malloc(sizeof(char)*strlen(src+1));
	cairo_text = (char*)malloc(sizeof(char)*strlen(src+1));
    strcpy(dst, src);
	strcpy(cairo_text, src);
    arr[arrnum] = dst;
	cairo_text = dst;
    if(strcmp(arr[arrnum], "/img") != 0)
        printf("%s\n", arr[arrnum]);
		//printf("chiro_text: %s\n", cairo_text[1024]);
    arrnum++;
}

char* copyChar_value(char* src)
{
	char *cairo_value[1024];
    char *dst = NULL;
    dst = (char*)malloc(sizeof(char)*strlen(src+1));
    strcpy(dst, src);
    arr[arrnum] = dst;
	cairo_value[1024] = dst;
    if(strcmp(arr[arrnum], "/img") != 0)
        printf("%s\n", arr[arrnum]);
		printf("chiro_value: %s\n", cairo_value);
    arrnum++;
}*/
