#include<windows.h>
extern int scanf(const char* __format,...);
extern int getchar();
extern int gets(char* __str);
extern int puts(const char* __str);

POINT pt;
HWND windowHANDLE;
unsigned long long a;
char isDOING=1,s[16]={0};

size_t z_strcmp(const char *str1,const char*str2)
{
    for(size_t i=0;str1[i]&&str2[i];++i)if(str1[i]!=str2[i])return 1;
    return 0;
}

int main()
{
    puts("Welcome to use this connector.\n\
Please enter the frequency you need (unit: ms).");
    scanf("%llu",&a);
    getchar();
    puts("OK, input 'OK' to choose position of your mouse.");
    LOCK:
    gets(s);
    if(z_strcmp(s,"OK"))
    {
        puts("Please input 'OK' to choose position of your mouse.");
        goto LOCK;
    }
    
    GetCursorPos(&pt);//得到鼠标的绝对坐标
    windowHANDLE = WindowFromPoint(pt);//得到窗口句柄
    ScreenToClient(windowHANDLE,&pt);//得到鼠标的相对坐标

    puts("OK, then you can press 'F8' key to start or end.");
       
while(1)
{
    Sleep(a);
    if(GetKeyState(VK_F8)) isDOING =!isDOING;
    if(isDOING)continue;

    SendMessage(windowHANDLE,WM_LBUTTONDOWN,0,MAKELONG(pt.x,pt.y));
    SendMessage(windowHANDLE,WM_LBUTTONUP,0,MAKELONG(pt.x,pt.y));//发送点击消息
}



}