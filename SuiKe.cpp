/*头文件部分*/
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<cstring>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<easyx.h>
#include<Windows.h>
#include<time.h>
#include<io.h>
#include<direct.h>
#include <sapi.h> //导入语音头文件
#include <string>
#pragma comment(lib,"sapi.lib") //导入语音头文件库
#pragma comment(lib,"Winmm.lib")
/*标准声明部分*/
using namespace std;
#define PI 3.1415926535
/*函数声明部分*/
void drawButton(struct Button* pB);//画按钮函数
int mouseInButton(struct Button* pB,MOUSEMSG m);//鼠标敲击函数
void zhuce();
void findnumber1();
void first();
void second();
void third();
void third2();
void fourth();
void fourth2(double Ai);
int fourth3(double Ai);
void fourth4();
int fourth5();
void fifth();
void six();
void modify();
void Replace();
void printstudents();
void setstudents();
void tips(); 
void tips2();
void music();
void Append(char c);
void Empty();// 清空输入的字符串
void Draw(int x1,int y1,int x2,int y2);// 绘制文本框
char Input();// 获取用户输入
void Out(int x1,int y1,int x2,int y2,char number[]);
void tubiaoshengming();
void tubiao();
void Time();
void markmessage();
/*全局变量声明部分*/
int i;//用于控制for循环
IMAGE img;//声明一个调用照片的变量
IMAGE t1,t2,t3,t4,t5,t6;
IMAGE g1,g2,g3,g4,g5,g6,g7,g8,g9;
char number1[200]={0};
char number2[200]={0};
char key[200]={0};
char Choice[200]={0};//选择的课程
char path[400]={0};
char path1[400]={0};
char path2[400]={0};
char path3[400]={0};
char path4[400]={0};
char messagetime[400]={0};
char messageout[600]={0};
char set[400]={0};
char printname[200]={0};
char address2[200]={0};
char ControlMusic[5]={0};
char ControlVideo[5]={0};
char ControlReduce[5]={0};
double mark[1000]={0};
int keep;//存放输出名字的呢一个地址
int control = 1;//控制下一次打开的功能
int change=0;//更换账号的条件
char text[100]={0};					// 用户输入的字符串
int	m_textlen;					// 用户输入字符串的长度
int	m_fps=50;	// 每秒调用多少次（决定了光标闪烁速度）
bool out1=true;
int sett[3]={1,1,1};
bool controlmusic=true;
bool controlvideo=true;
bool controlreduce=true;
double reduce=0.8;
/*颜色色值变量*/
float R1=244;//189,236,220
float G1=249;//215,207,231
float B1=252;//247,254,177
float R2=12;
float G2=138;
float B2=219;
float R3=97;
float G3=181;
float B3=230;
float R4=0;
float G4=168;
float B4=243;
/*声明结构体部分*/
typedef void (*Dllfun)(char *a);
typedef double (*SKWork3)(double a,double b,double c);
typedef double (*SKWork2)(double a,double b,double c,double d,double e,double f);
typedef double (*SKWork1)(double a,double b,double c);
Dllfun speech;
SKWork1 skwork1;
SKWork2 skwork2;
SKWork3 skwork3;
HINSTANCE hdll,hdll2,hdll3,hdll4;
/*显式调用动态链接库*/
struct classname
{
	char name[100];
}Classname[200];
struct information
{ 
	char number[30];//学号
	char name[50];//名字
	int di;//总答题次数
	int ci;//得分评价
	int ii;//缺勤次数
	int II;//考勤抽到次数
	double pi;//被提问概率
	double yinzi;//被提问的影响因子
}student[200];
struct Button//声明一个按钮信息的结构体
{
	int x;
	int y;
	int width;
	int height;
	COLORREF inColor;
	COLORREF outColor;
	COLORREF curColor;
	char* text;
	COLORREF textColor;
	void (*pDrawButton)(struct Button*);
	int (*pMouseInButton)(struct Button*,MOUSEMSG m);
};
struct Button* createButton(int x,int y,int width,int height,COLORREF inColor,COLORREF outColor,
	const char* text,COLORREF textColor)//声明一个按钮的相关内容的结构体
{
	struct Button* pButton = (struct Button*)malloc(sizeof(struct Button));
	//assert(pButton);
	pButton->x=x;
	pButton->y=y;
	pButton->width=width;
	pButton->height=height;
	pButton->outColor=outColor;
	pButton->curColor=outColor;
	pButton->inColor=inColor;
	pButton->text=(char*)malloc(strlen(text)+1);
	strcpy(pButton->text,text);
	pButton->textColor=textColor;
	pButton->pDrawButton=drawButton;
	pButton->pMouseInButton=mouseInButton;
	return pButton;
};
//绘制按钮
int main(void)
{
	hdll=LoadLibrary("speech.dll");
	hdll2=LoadLibrary("SKWork.dll");
	hdll3=LoadLibrary("SKWork.dll");
	hdll4=LoadLibrary("SKWork.dll");
	if(hdll==NULL)
	{
		FreeLibrary(hdll);
	}
	if(hdll2==NULL)
	{
		FreeLibrary(hdll2);
	}
	if(hdll3==NULL)
	{
		FreeLibrary(hdll3);
	}
	if(hdll4==NULL)
	{
		FreeLibrary(hdll4);
	}
	speech=(Dllfun)GetProcAddress(hdll,"speech");
	skwork1=(SKWork1)GetProcAddress(hdll2,"kaoqin");
	skwork2=(SKWork2)GetProcAddress(hdll3,"nandu");
	skwork3=(SKWork3)GetProcAddress(hdll4,"timu");
	if(speech==NULL)
	{
		FreeLibrary(hdll);
	}
	if(skwork1==NULL)
	{
		FreeLibrary(hdll2);
	}
	if(skwork2==NULL)
	{
		FreeLibrary(hdll3);
	}
	if(skwork3==NULL)
	{
		FreeLibrary(hdll4);
	}
	Time();
	sprintf(messageout,"%s程序开启!\n",messagetime);
	cout<<messageout;
	markmessage();
	strcpy(ControlMusic,"ON");
	strcpy(ControlVideo,"ON");
	strcpy(ControlReduce,"ON");
	strcpy(number1,"0");
	mciSendString("open music//anniu.mp3 alias mymusic",NULL,0,NULL);//bkmusic是自己定义的别名
	for(i=0;i<1000;i++)
	{
		mark[i]=1;
	}
loop2:
	FILE *fp;
	strcpy(address2,"picture");
	char outnumber2[200]={0};
	srand(time(NULL));
	//sprintf(path,"C:\\skuser\\%s\\cache",number1);
	//sprintf(path1,"C:\\skuser\\%s\\messages",number1);
	//sprintf(path2,"C:\\skuser\\%s\\keys",number1);
	_mkdir("C:\\skuser");
	system("attrib +h +s C:\\skuser");
	initgraph(1000,600);
	out1=true;
	_mkdir("C:\\skuser\\0");
	if ((fp = fopen("C:\\skuser\\0\\cache", "w+")) == NULL)
	{
		RECT r = {0, 0, 600, 350};
		drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		_rmdir(path);
		Sleep(3000);
		exit(0);
	}
	fclose(fp);
	if ((fp = fopen("C:\\skuser\\0\\messages", "w+")) == NULL)
	{
		RECT r = {0, 0, 600, 350};
		drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		_rmdir(path);
		Sleep(3000);
		exit(0);
	}
	fclose(fp);
	if ((fp = fopen("C:\\skuser\\0\\keys", "w+")) == NULL)
	{
		RECT r = {0, 0, 600, 350};
		drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		_rmdir(path);
		Sleep(3000);
		exit(0);
	}
	fclose(fp);
	if ((fp = fopen("C:\\skuser\\0\\setting", "w+")) == NULL)
	{
		RECT r = {0, 0, 600, 350};
		drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		_rmdir(path);
		Sleep(3000);
		exit(0);
	}
	fclose(fp);
	putimage(0,0,&img);
	while(1)
	{
		if(control==1)
		{
			music();
			FlushBatchDraw();
			EndBatchDraw();
			first();
			EndBatchDraw();
			//closegraph();
			//cleardevice();
			continue;
		}
		if(control==2)
		{
			music();
			FlushBatchDraw();
			EndBatchDraw();
			second();
			//closegraph();
			//cleardevice();
			continue;
		}
		if(control==3)
		{
			music();
			FlushBatchDraw();
			EndBatchDraw();
			third();
			//closegraph();
			//cleardevice();
			continue;
		}
		if(control==4)
		{
			music();
			FlushBatchDraw();
			EndBatchDraw();
			fourth();
			//closegraph();
			//cleardevice();
			continue;
		}
		if(control==5)
		{
			music();
			FlushBatchDraw();
			EndBatchDraw();
			fifth();
			//closegraph();
			//cleardevice();
			continue;
		}
		if(control=6)
		{
			music();
			FlushBatchDraw();
			EndBatchDraw();
			six();
			//closegraph();
			//cleardevice();
			continue;
		}
	}
	/*while(1)
	{
	setlinecolor(BLACK);
	/*line(0,0,0,600);
	line(0,0,1000,0);
	line(1000,0,1000,600);
	line(0,600,1000,600);
	line(220,0,220,600);
	line(9,0,9,600);
	line(211,0,211,600);
	line(0,0,220,0);
	line(10,0,210,0);
	line(10,100,210,100);
	line(10,200,210,200);
	line(10,300,210,300);
	line(10,400,210,400);
	line(10,500,210,500);*/
	/*First->pDrawButton(First);
	Second->pDrawButton(Second);
	Third->pDrawButton(Third);
	Fourth->pDrawButton(Fourth);
	Fifth->pDrawButton(Fifth);
	EXIT->pDrawButton(EXIT);
	MOUSEMSG m=GetMouseMsg();
	BeginBatchDraw();
	if(First->pMouseInButton(First,m)&&m.uMsg==WM_LBUTTONDOWN || control== 1)
	{
	music();
	FlushBatchDraw();
	EndBatchDraw();
	first();
	if(change==1)//主要是为了重置账号密码，防止不输入账号密码但能直接登录的问题
	{
	change=0;
	char Ch[10]={0};
	strcpy(number1,Ch);
	strcpy(number2,Ch);
	FlushBatchDraw();
	//closegraph();
	//cleardevice();
	goto loop2;
	}
	EndBatchDraw();
	//closegraph();
	//cleardevice();
	goto loop;       
	}
	if(Second->pMouseInButton(Second,m)&&m.uMsg==WM_LBUTTONDOWN || control==2)
	{
	music();
	FlushBatchDraw();
	EndBatchDraw();
	second();
	//closegraph();
	//cleardevice();
	goto loop;
	}
	if(Third->pMouseInButton(Third,m)&&m.uMsg==WM_LBUTTONDOWN || control ==3)
	{
	music();
	FlushBatchDraw();
	EndBatchDraw();
	third();
	//closegraph();
	//cleardevice();
	goto loop;
	}
	if(Fourth->pMouseInButton(Fourth,m)&&m.uMsg==WM_LBUTTONDOWN || control==4)
	{
	music();
	FlushBatchDraw();
	EndBatchDraw();
	fourth();
	//closegraph();
	//cleardevice();
	goto loop;
	}
	if(Fifth->pMouseInButton(Fifth,m)&&m.uMsg==WM_LBUTTONDOWN || control==5)
	{
	music();
	FlushBatchDraw();
	EndBatchDraw();
	fifth();
	//closegraph();
	//cleardevice();
	goto loop;
	}
	if(EXIT->pMouseInButton(EXIT,m)&&m.uMsg==WM_LBUTTONDOWN || control==6)
	{
	music();
	exit(0);
	}
	FlushBatchDraw();
	}
	EndBatchDraw();
	closegraph();*/
	FreeLibrary(hdll);
	FreeLibrary(hdll2);
	FreeLibrary(hdll3);
	FreeLibrary(hdll4);
	return 0;
}
int mouseInButton(struct Button* pB,MOUSEMSG m)//鼠标响应函数
{
	if(m.x>=pB->x&&m.x<=pB->x+pB->width&&m.y>=pB->y&&m.y<=pB->y+pB->height)
	{
		pB->curColor=pB->inColor;
		return 1;
	}
	pB->curColor=pB->outColor;
	return 0;
}
void tips()
{
	setbkmode(TRANSPARENT);
	if(Choice[0]==0)
	{
		LOGFONT f,g;
		gettextstyle(&f);
		gettextstyle(&g);
		f.lfHeight =40;
		_tcscpy(f.lfFaceName,_T("黑体"));
		f.lfQuality =ANTIALIASED_QUALITY;
		settextcolor(RED);
		settextstyle(&f);
		outtextxy(200,330,_T("您还未选择课程，请回首页选择课程！"));
		settextstyle(&g);
	}
}
void tips2()
{
	setbkmode(TRANSPARENT);
	if(strcmp(number1,"0")==0)
	{
		LOGFONT f,g;
		gettextstyle(&f);
		gettextstyle(&g);
		f.lfHeight =40;
		_tcscpy(f.lfFaceName,_T("黑体"));
		f.lfQuality =ANTIALIASED_QUALITY;
		settextcolor(RED);
		settextstyle(&f);
		outtextxy(200,330,_T("您还未登陆账号，请在首页登陆账号！"));
		settextstyle(&g);
	}
}
void music()
{
	if(controlmusic)
		mciSendString("play mymusic from 0", NULL, 0, NULL);
	//mciSendString("close mymusic", NULL, 0, NULL);
}
void drawButton(struct Button* pB)//鼠标显示函数
{
	setfillcolor(pB->curColor);
	if(pB->curColor==pB->inColor)
	{
		setlinecolor(BLACK);
		setlinestyle(PS_SOLID,2);
		solidrectangle(pB->x,pB->y,pB->x+pB->width,pB->y+pB->height);
	}
	else
	{
		solidrectangle(pB->x,pB->y,pB->x+pB->width,pB->y+pB->height);
	}
	solidrectangle(pB->x,pB->y,pB->x + pB->width,pB->y+pB->height);
	int textWidth=textwidth(pB->text);
	int textHeight=textheight(pB->text);
	int x=pB->x+(pB->width-textWidth)/2;
	int y=pB->y+(pB->height-textHeight)/2;
	setbkmode(TRANSPARENT);//去文字beijing
	settextcolor(pB->textColor);
	outtextxy(x,y,pB->text);
}
void first()
{
	int page=1;
loop4:
	int print=100;
	char classout[200];
	int n=0;
	char out[100];
	FILE *fp;
	struct Button* First=createButton(10,40,100,75,RGB(R3,G3,B3),RGB(R3,G3,B3),"",BLACK);
	struct Button* Second=createButton(110,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* Third=createButton(210,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* Fourth=createButton(310,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* Fifth=createButton(410,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* EXIT=createButton(510,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* over=createButton(880,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* replace=createButton(180,230,250,250,RGB(R3,G3,B3),RGB(R1,G1,B1),"",BLACK);
	struct Button* choice=createButton(570,230,250,250,RGB(R3,G3,B3),RGB(R1,G1,B1),"",BLACK);
	/*struct Button* fbefore=createButton(840,95,150,40,RGB(R3,G3,B3),RGB(R1,G1,B1),"上一页",BLACK);
	struct Button* fafter=createButton(840,155,150,40,RGB(R3,G3,B3),RGB(R1,G1,B1),"下一页",BLACK);
	struct Button* ffirst=createButton(840,345,150,40,RGB(R3,G3,B3),RGB(R1,G1,B1),"首  页",BLACK);
	struct Button* fend=createButton(840,405,150,40,RGB(R3,G3,B3),RGB(R1,G1,B1),"尾  页",BLACK);*/
	//initgraph(1000,600);
	BeginBatchDraw();
	//setbkcolor(WHITE);
	cleardevice();
	loadimage(&img, _T("photo\\背景3.png"),1000,600);
	loadimage(&g1,_T("photo\\修改信息.png"),230,230);
	loadimage(&g2,_T("photo\\testdl.png"),60,75);
	loadimage(&g3,_T("photo\\选择这节课课程.png"),230,230);
	putimage(0,0,&img);
	tubiaoshengming();
	tips2();
	setbkmode(TRANSPARENT);
	/*LOGFONT f,g;
	gettextstyle(&f);
	gettextstyle(&g);
	f.lfHeight =30;
	_tcscpy(f.lfFaceName,_T("黑体"));
	f.lfQuality =ANTIALIASED_QUALITY;
	settextcolor(RED);
	settextstyle(&f);
	outtextxy(230,5,_T("欢迎用户"));
	outtextxy(650,5,_T("使用"));
	outtextxy(230,50,_T("您需要上的课为:"));
	settextcolor(BLUE);
	outtextxy(365,5,_T(number1));*/
	sprintf(path,"C:\\skuser\\%s",number1);
	sprintf(path1,"%s\\messages",path);
	if ((fp = fopen(path1, "r")) == NULL)
	{
		RECT r = {0, 0, 600, 350};
		drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		Sleep(3000);
		exit(0);
	}
	while(fscanf(fp,"%s",classout)!=EOF)
	{
		strcpy(Classname[n].name,classout);
		n++;
		settextcolor(CYAN);
		if(n<=7*page&&n>7*(page-1))
		{
			//outtextxy(230,print,_T(classout));
			print+=50;
		}
	}
	fclose(fp);
	setlinecolor(BLUE);
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 3);
	if(strcmp(number1,"0")!=0)
		line(499,200,499,500);
	while(1)
	{
		First->pDrawButton(First);
		Second->pDrawButton(Second);
		Third->pDrawButton(Third);
		Fourth->pDrawButton(Fourth);
		Fifth->pDrawButton(Fifth);
		EXIT->pDrawButton(EXIT);
		over->pDrawButton(over);
		if(strcmp(number1,"0")!=0)
		{
			replace->pDrawButton(replace);
			choice->pDrawButton(choice);
			putimage(190,240,&g1);
			putimage(580,240,&g3);
		}
		/*if(n>7)
		{
		fbefore->pDrawButton(fbefore);
		fafter->pDrawButton(fafter);
		ffirst->pDrawButton(ffirst);
		fend->pDrawButton(fend);
		}*/
		MOUSEMSG m=GetMouseMsg();
		tubiao();
		putimage(900,40,&g2);
		/*if(n>7)
		{
		if(fbefore->pMouseInButton(fbefore,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
		music();
		page--;
		if(page<=0)
		page=1;
		goto loop4;
		}
		if(fafter->pMouseInButton(fafter,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
		music();
		page++;
		if(page>=(n/7)+1)
		page=(n/7)+1;
		goto loop4;
		}
		if(ffirst->pMouseInButton(ffirst,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
		music();
		page=1;
		goto loop4;
		}
		if(fend->pMouseInButton(fend,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
		music();
		page=(n/7)+1;
		goto loop4;
		}
		}*/
		if(First->pMouseInButton(First,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control =1;
			break;
		}
		if(Second->pMouseInButton(Second,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=2;
			break;
		}
		if(Third->pMouseInButton(Third,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=3;
			break;
		}
		if(Fourth->pMouseInButton(Fourth,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=4;
			break;
		}
		if(Fifth->pMouseInButton(Fifth,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=5;
			break;
		}
		if(EXIT->pMouseInButton(EXIT,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=6;
			break;
		}
		if(over->pMouseInButton(over,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			char cachenumber[100]={0};
			int n=0;
			FILE *fp;
			music();
			Choice[0]=0;
			if ((fp = fopen("cache", "w+")) == NULL)
			{
				exit(0);
			}
			fprintf(fp,"%s",number1);
			fclose(fp);
			system("land.exe");
			if ((fp = fopen("cache", "r")) == NULL)
			{
				exit(0);
			}
			fscanf(fp,"%s",cachenumber);
			fclose(fp);
			strcpy(number1,cachenumber);
			sprintf(path,"C:\\skuser\\%s\\keys",number1);
			if ((fp = fopen(path, "r")) == NULL)
			{
				exit(0);
			}
			fscanf(fp,"%s",number2);
			fclose(fp);
			sprintf(set,"C:\\skuser\\%s\\setting",number1);
			if ((fp = fopen(set, "r")) == NULL)
			{
				exit(0);
			}
			for(i=0;i<3;i++)
			{
				fscanf(fp,"%d",&sett[i]);
			}
			fclose(fp);
			if(sett[0]==1)
			{
				controlmusic=true;
				strcpy(ControlMusic,"ON");
			}
			else
			{
				controlmusic=false;
				strcpy(ControlMusic,"OFF");
			}
			if(sett[1]==1)
			{
				controlvideo=true;
				strcpy(ControlVideo,"ON");
			}
			else
			{
				controlvideo=false;
				strcpy(ControlVideo,"OFF");
			}
			if(sett[2]==1)
			{
				controlreduce=true;
				strcpy(ControlReduce,"ON");
			}
			else
			{
				controlreduce=false;
				strcpy(ControlReduce,"OFF");
			}
			if(strcmp(number1,"0")!=0)
			{
				Time();
				sprintf(messageout,"%s用户 %s 登陆成功!\n",messagetime,number1);
				cout<<messageout;
				markmessage();
			}
			break;
		}
		if(strcmp(number1,"0")!=0)
		{
			if(replace->pMouseInButton(replace,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				Replace();
				FlushBatchDraw();
				EndBatchDraw();
				//closegraph();
				//cleardevice();
				goto loop4;
			}
			if(choice->pMouseInButton(choice,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				bool cc=true;
				//TCHAR c1[]=_T("请输入这节课:");
				//InputBox(Choice,100,c1,NULL,0,100,0,false);
				system("choice.exe");
				if ((fp = fopen("cache2", "r")) == NULL)
				{
					exit(0);
				} 
				fscanf(fp,"%s",Choice);
				fclose(fp);
				if(strcmp(Choice," ")==0)
				{
					Choice[0]=0;
				}
				if(Choice[0]!=0)
				{
					Time();
					sprintf(messageout,"%s选择课程为'%s'\n",messagetime,Choice);
					cout<<messageout;
					markmessage();
				}
				/*for(i=0;i<=n;i++)
				{
				if(!strcmp(Classname[i].name,Choice))
				{
				cc=false;
				break;
				}
				else
				{
				continue;
				}
				}
				if(strlen(Choice)==0)
				{
				LOGFONT f;
				gettextstyle(&f);
				settextcolor(RED);
				settextstyle(30, 0, _T("Consolas"));
				outtextxy(540,540,"请输入这节课的名字");
				settextstyle(&f);
				FlushBatchDraw();
				EndBatchDraw();
				Sleep(1500);
				goto loop4;
				}
				if(cc)
				{
				Choice[0]=0;
				LOGFONT f;
				gettextstyle(&f);
				settextcolor(RED);
				settextstyle(30, 0, _T("Consolas"));
				outtextxy(540,540,"查无此课！");
				settextstyle(&f);
				FlushBatchDraw();
				EndBatchDraw();
				Sleep(1500);
				goto loop4;
				}*/
			}
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
	//closegraph();
}
void second()
{
	IMAGE pic1,pic2,pic3;
loop5:
	struct Button* First=createButton(10,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* Second=createButton(110,40,100,75,RGB(R3,G3,B3),RGB(R3,G3,B3),"",BLACK);
	struct Button* Third=createButton(210,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* Fourth=createButton(310,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* Fifth=createButton(410,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* EXIT=createButton(510,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* LOOKstudents=createButton(720,160,200,200,RGB(R3,G3,B3),RGB(R1,G1,B1),"具体信息",BLACK);
	struct Button* SETstudents=createButton(720,380,200,200,RGB(R3,G3,B3),RGB(R1,G1,B1),"编辑学生",BLACK);
	//initgraph(1000,600);
	BeginBatchDraw(); 
	//setbkcolor(WHITE);
	cleardevice();
	loadimage(&img, _T("photo\\背景3.png"),1000,600);
	loadimage(&pic1,_T("photo\\具体信息.png"),180,180);
	loadimage(&pic2,_T("photo\\编辑学生.png"),180,180);
	loadimage(&pic3,_T("photo\\框.png"),650,480);
	putimage(0,0,&img);
	tubiaoshengming();
	tips();
	if(Choice[0]!=0)
	{
		putimage(0,120,&pic3);
		FILE *fp;
		int n=0;int num=0;
		char out[300];
		char out1[300];
		char out2[300];
		sprintf(path,"C:\\skuser\\%s",number1);
		sprintf(path1,"%s\\%s",path,Choice);
		if ((fp = fopen(path1, "r")) == NULL)
		{
			RECT r = {0, 0, 600, 350};
			drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			Sleep(3000);
			exit(0);
		}
		while(fscanf(fp,"%s",student[n].number)!=EOF&&fscanf(fp,"%s",student[n].name)!=EOF&&fscanf(fp,"%d",&student[n].ci)!=EOF
			&&fscanf(fp,"%d",&student[n].di)!=EOF&&fscanf(fp,"%d",&student[n].ii)!=EOF&&fscanf(fp,"%d",&student[n].II)!=EOF)
		{
			n++;
		}
		for(i=0;i<n;i++)
			if(student[i].ci<=59)
				num++;
		float fn=n;
		float fnum=num;
		fclose(fp);
		sprintf(out,"本节课共有%d名学生，根据以往数据可得",n);
		sprintf(out1,"其中及格有%d名同学，不及格有%d名同学",n-num,num);
		sprintf(out2,"不及格的同学占全班的%f%%",(fnum/n)*100);
		setfillcolor(LIGHTRED);
		solidcircle(220,280,150);
		solidrectangle(435,155,460,180);
		setfillcolor(LIGHTBLUE);
		solidpie(70,130,370,430,0,2*PI-2*PI*fnum/fn);
		solidrectangle(435,230,460,255);
		LOGFONT f,g;
		gettextstyle(&f);
		gettextstyle(&g);
		f.lfHeight =23;
		_tcscpy(f.lfFaceName,_T("宋体"));
		f.lfQuality =ANTIALIASED_QUALITY;
		settextcolor(BLACK);
		settextstyle(&f);
		outtextxy(470,155,"不及格的人数");
		outtextxy(470,230,"及格的人数");
		outtextxy(50,470,out);
		outtextxy(50,520,out1);
		outtextxy(50,570,out2);
		settextstyle(&g);
		setlinecolor(BLUE);
		setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 3);
		line(679,180,679,520);
		line(715,369,925,369);
	}
	while(1)
	{
		setlinecolor(BLACK);
		First->pDrawButton(First);
		Second->pDrawButton(Second);
		Third->pDrawButton(Third);
		Fourth->pDrawButton(Fourth);
		Fifth->pDrawButton(Fifth);
		EXIT->pDrawButton(EXIT);
		if(Choice[0]!=0)
		{
			LOOKstudents->pDrawButton(LOOKstudents); 
			SETstudents->pDrawButton(SETstudents);
			putimage(730,170,&pic1);
			putimage(730,390,&pic2);
		}
		MOUSEMSG m=GetMouseMsg();
		tubiao();
		if(First->pMouseInButton(First,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=1;
			break;
		}
		if(Second->pMouseInButton(Second,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=2;
			break;
		}
		if(Third->pMouseInButton(Third,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=3;
			break;
		}
		if(Fourth->pMouseInButton(Fourth,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=4;
			break;
		}
		if(Fifth->pMouseInButton(Fifth,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=5;
			break;
		}
		if(EXIT->pMouseInButton(EXIT,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=6;
			break;
		}
		if(Choice[0]!=0)
		{
			if(LOOKstudents->pMouseInButton(LOOKstudents,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				printstudents();
				FlushBatchDraw();
				EndBatchDraw();
				//closegraph();
				//cleardevice();
				goto loop5;
			}
			if(SETstudents->pMouseInButton(SETstudents,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				setstudents();
				FlushBatchDraw();
				EndBatchDraw();
				//closegraph();
				//cleardevice();
				goto loop5;
			}
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
	//closegraph();
}
void third()
{
	IMAGE pic1,pic2;
loop10:
	char outname[200];
	int n=0;
	FILE *fp;
	struct Button* First=createButton(10,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* Second=createButton(110,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* Third=createButton(210,40,100,75,RGB(R3,G3,B3),RGB(R3,G3,B3),"",BLACK);
	struct Button* Fourth=createButton(310,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* Fifth=createButton(410,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* EXIT=createButton(510,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* tGo=createButton(180,230,250,250,RGB(R3,G3,B3),RGB(R1,G1,B1),"开  始  抽  取",BLACK);
	struct Button* tadd=createButton(570,230,250,250,RGB(R3,G3,B3),RGB(R1,G1,B1),"添  加  缺  勤",BLACK);
	//initgraph(1000,600);
	BeginBatchDraw();
	//setbkcolor(WHITE);
	cleardevice();
	loadimage(&img, _T("photo\\背景3.png"),1000,600);
	loadimage(&pic1, _T("photo\\缺勤抽取.png"),230,230);
	loadimage(&pic2, _T("photo\\添加缺勤.png"),230,230);
	putimage(0,0,&img);
	tubiaoshengming();
	tips();
	sprintf(path,"C:\\skuser\\%s",number1);
	sprintf(path1,"%s\\%s",path,Choice);
	if(Choice[0]!=0)
	{
		if ((fp = fopen(path1, "r")) == NULL)
		{
			RECT r = {0, 0, 600, 350};
			drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			Sleep(3000);
			exit(0);
		}
		while(fscanf(fp,"%s",student[n].number)!=EOF&&fscanf(fp,"%s",student[n].name)!=EOF&&fscanf(fp,"%d",&student[n].ci)!=EOF
			&&fscanf(fp,"%d",&student[n].di)!=EOF&&fscanf(fp,"%d",&student[n].ii)!=EOF&&fscanf(fp,"%d",&student[n].II)!=EOF)
			n++;
		fclose(fp);
		setlinecolor(BLUE);
		setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 3);
		line(499,200,499,500);
	}
	while(1)
	{
		setlinecolor(BLACK);
		First->pDrawButton(First);
		Second->pDrawButton(Second);
		Third->pDrawButton(Third);
		Fourth->pDrawButton(Fourth);
		Fifth->pDrawButton(Fifth);
		EXIT->pDrawButton(EXIT);
		if(Choice[0]!=0)
		{
			tGo->pDrawButton(tGo);
			tadd->pDrawButton(tadd);
			putimage(190,240,&pic1);
			putimage(580,240,&pic2);
		}
		MOUSEMSG m=GetMouseMsg();
		tubiao();
		if(First->pMouseInButton(First,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=1;
			break;
		}
		if(Second->pMouseInButton(Second,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=2;
			break;
		}
		if(Third->pMouseInButton(Third,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=3;
			break;
		}
		if(Fourth->pMouseInButton(Fourth,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=4;
			break;
		}
		if(Fifth->pMouseInButton(Fifth,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=5;
			break;
		}
		if(EXIT->pMouseInButton(EXIT,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=6;
			break;
		}
		if(Choice[0]!=0)
		{
			if(tGo->pMouseInButton(tGo,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				third2();
				FlushBatchDraw();
				EndBatchDraw();
				//closegraph();
				//cleardevice();
				goto loop10;
			}
			if(tadd->pMouseInButton(tadd,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				TCHAR c1[]=_T("请输入缺勤同学的名字:");
				InputBox(outname,100,c1,NULL,0,100,0,false);
				if(strlen(outname)==0)
				{
					LOGFONT f;
					gettextstyle(&f);
					settextcolor(RED);
					settextstyle(30, 0, _T("Consolas"));
					RECT r={220,150,999,599};
					drawtext(_T("请输入缺勤同学的名字"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					settextstyle(&f);
					FlushBatchDraw();
					EndBatchDraw();
					Sleep(1500);
					goto loop10;
				}
				for(i=0;i<n;i++)
				{
					if(strcmp(outname,student[i].name))
						continue;
					else
					{
						student[i].ii++;
						student[i].II++;
					}
				}
				if ((fp = fopen(path1, "w")) == NULL)
				{
					RECT r = {0, 0, 600, 350};
					drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					Sleep(3000);
					exit(0);
				}
				for(i=0;i<n;i++)
				{
					fprintf(fp,"%s\t",student[i].number);
					fprintf(fp,"%s\t",student[i].name);
					fprintf(fp,"%d\t",student[i].ci);
					fprintf(fp,"%d\t",student[i].di);
					fprintf(fp,"%d\t",student[i].ii);
					fprintf(fp,"%d\n",student[i].II);
				}
				fclose(fp);
				Time();
				sprintf(messageout,"%s添加学生'%s'缺勤成功!\n",messagetime,outname);
				cout<<messageout;
				markmessage();
				goto loop10;
			}
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
	//closegraph();
}
void third2()
{
	IMAGE pic1,pic2,pic3;
	int n=0;
	long num=0;
	long num2=0;
	long temp=0;
	long temp2=0;
	long all=0;
	FILE *fp;
	sprintf(path,"C:\\skuser\\%s",number1);
	sprintf(path1,"%s\\%s",path,Choice);
	if ((fp = fopen(path1, "r")) == NULL)
	{
		RECT r = {0, 0, 600, 350};
		drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		Sleep(3000);
		exit(0);
	}
	while(fscanf(fp,"%s",student[n].number)!=EOF&&fscanf(fp,"%s",student[n].name)!=EOF&&fscanf(fp,"%d",&student[n].ci)!=EOF
		&&fscanf(fp,"%d",&student[n].di)!=EOF&&fscanf(fp,"%d",&student[n].ii)!=EOF&&fscanf(fp,"%d",&student[n].II)!=EOF)
		n++;
	fclose(fp);
	if(n!=0)
	{
	for(i=0;i<n;i++)
	{
		student[i].pi=skwork1((double)student[i].II,(double)student[i].ii,(double)student[i].di);
	}
	for(i=0;i<n;i++)
			all=all+student[i].pi*10*mark[i];
	num=(rand()*rand())%(all+n);
	for(i=0;i<n;i++)
	{
		temp2=(temp+student[i].pi*10*mark[i]);
		if(num>temp&&num<=temp2)
		{
			strcpy(printname,student[i].name);
			mark[i]=0.1;
			keep=i;
			/*if ((fp2 = fopen("1.txt", "w")) == NULL)
			{
				exit(0);
			}	
			fprintf(fp2,"%s",student[i].number);
			fclose(fp2);*/
			if(controlvideo)
				speech(student[i].number);
			break;
		}
		temp=temp2;
		if(i==n-1)
		{
			i=0;
			temp=0;
			temp2=0;
			num=(rand()*rand())%(all+n);
		}
	}
	}
	struct Button* buzai=createButton(100,500,150,60,RGB(R3,G3,B3),RGB(R1,G1,B1),"缺  勤",BLACK);
	struct Button* zai=createButton(750,500,150,60,RGB(R3,G3,B3),RGB(R1,G1,B1),"出  勤",BLACK);
	struct Button* tback=createButton(750,500,150,60,RGB(R3,G3,B3),RGB(R1,G1,B1),"返  回",BLACK);
	//initgraph(1000,600);
	BeginBatchDraw();
	//setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
	cleardevice();
	loadimage(&img, _T("photo\\背景4.jpg"),1000,600);
	loadimage(&pic1, _T("photo\\缺勤.png"),140,50);
	loadimage(&pic2, _T("photo\\出勤.png"),140,50);
	loadimage(&pic3, _T("photo\\返回.png"),140,50);
	putimage(0,0,&img);
	if(n!=0)
	{
		LOGFONT f,g;
		gettextstyle(&f);
		gettextstyle(&g);
		f.lfHeight=48;
		_tcscpy(f.lfFaceName,_T("楷体"));
		f.lfQuality=ANTIALIASED_QUALITY;
		settextstyle(&f);
		settextcolor(BLUE);
		RECT r={0,0,1000,600};
		drawtext(_T(student[keep].name),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		settextstyle(&g);
	}
	if(n==0)
	{
		setbkmode(TRANSPARENT);
		LOGFONT f,g;
		gettextstyle(&f);
		gettextstyle(&g);
		f.lfHeight =32;
		_tcscpy(f.lfFaceName,_T("黑体"));
		f.lfQuality =ANTIALIASED_QUALITY;
		settextcolor(RED);
		settextstyle(&f);
		outtextxy(260,280,_T("您还未添加学生，快去添加学生吧！"));
		settextstyle(&g);
	}
	while(1)
	{
		if(n!=0)
		{
			buzai->pDrawButton(buzai);
			zai->pDrawButton(zai);
			putimage(105,505,&pic1);
			putimage(755,505,&pic2);
		}
		if(n==0)
		{
			tback->pDrawButton(tback);
			putimage(755,505,&pic3);
		}
		MOUSEMSG m=GetMouseMsg();
		if(n!=0)
		{
			if(buzai->pMouseInButton(buzai,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				student[keep].ii++;
				student[keep].II++;
				if ((fp = fopen(path1, "w")) == NULL)
				{
					RECT r = {0, 0, 600, 350};
					drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					Sleep(3000);
					exit(0);
				}
				for(i=0;i<n;i++)
				{
					fprintf(fp,"%s\t",student[i].number);
					fprintf(fp,"%s\t",student[i].name);
					fprintf(fp,"%d\t",student[i].ci);
					fprintf(fp,"%d\t",student[i].di);
					fprintf(fp,"%d\t",student[i].ii);
					fprintf(fp,"%d\n",student[i].II);
				}
				fclose(fp);
				Time();
				sprintf(messageout,"%s抽到的学生为'%s'，该同学的状态为'缺勤'\n",messagetime,student[keep].name);
				cout<<messageout;
				markmessage();
				//	outtextxy(300,500,"记录完成");
				break;
			}
			if(zai->pMouseInButton(zai,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				student[keep].II++;
				if ((fp = fopen(path1, "w")) == NULL)
				{
					RECT r = {0, 0, 600, 350};
					drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					Sleep(3000);
					exit(0);
				}
				for(i=0;i<n;i++)
				{
					fprintf(fp,"%s\t",student[i].number);
					fprintf(fp,"%s\t",student[i].name);
					fprintf(fp,"%d\t",student[i].ci);
					fprintf(fp,"%d\t",student[i].di);
					fprintf(fp,"%d\t",student[i].ii);
					fprintf(fp,"%d\n",student[i].II);
				}
				fclose(fp);
				Time();
				sprintf(messageout,"%s抽到的学生为'%s'，该同学的状态为'出勤'\n",messagetime,student[keep].name);
				cout<<messageout;
				markmessage();
				break;
			}
		}
		if(n==0)
		{
			if(tback->pMouseInButton(tback,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				break;
			}
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
}
void fourth()
{
	IMAGE pic1,pic2,pic3,pic4,pic5,pic6;
	FILE *fp;
	double ai;
loop8:
	struct Button* First=createButton(10,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* Second=createButton(110,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* Third=createButton(210,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* Fourth=createButton(310,40,100,75,RGB(R3,G3,B3),RGB(R3,G3,B3),"",BLACK);
	struct Button* Fifth=createButton(410,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* EXIT=createButton(510,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* easy=createButton(85,230,150,150,RGB(R3,G3,B3),RGB(R1,G1,B1),"简  单",BLACK);
	struct Button* only=createButton(265,230,150,150,RGB(R3,G3,B3),RGB(R1,G1,B1),"一  般",BLACK);
	struct Button* littledifficut=createButton(85,410,150,150,RGB(R3,G3,B3),RGB(R1,G1,B1),"较  难",BLACK);
	struct Button* difficult=createButton(265,410,150,150,RGB(R3,G3,B3),RGB(R1,G1,B1),"困  难",BLACK);
	struct Button* input=createButton(540,250,200,200,RGB(R3,G3,B3),RGB(R1,G1,B1),"导 入 题 目",BLACK);
	struct Button* init=createButton(760,250,200,200,RGB(R3,G3,B3),RGB(R1,G1,B1),"进 入 提 问",BLACK);
	//initgraph(1000,600);
	BeginBatchDraw();
	//setbkcolor(WHITE);
	cleardevice();
	loadimage(&img, _T("photo\\背景3.png"),1000,600);
	loadimage(&pic1, _T("photo\\简单.png"),130,130);
	loadimage(&pic2, _T("photo\\一般.png"),130,130);
	loadimage(&pic3, _T("photo\\较难.png"),130,130);
	loadimage(&pic4, _T("photo\\困难.png"),130,130);
	loadimage(&pic5, _T("photo\\导入题目.png"),180,180);
	loadimage(&pic6, _T("photo\\进入提问.png"),180,180);
	putimage(0,0,&img);
	tubiaoshengming();
	setbkmode(TRANSPARENT);
	tips();
	if(Choice[0]!=0)
	{
		LOGFONT f,g;
		gettextstyle(&f);
		gettextstyle(&g);
		f.lfHeight =30;
		_tcscpy(f.lfFaceName,_T("黑体"));
		f.lfQuality =ANTIALIASED_QUALITY;
		settextcolor(BLUE);
		settextstyle(&f);
		//	roundrect(270,50,530,480,15,15);
		RECT r = {0, 0, 500, 360};
		drawtext(_T("按难度抽取"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//	roundrect(680,50,940,480,15,15);
		RECT t = {500, 0, 1000, 360};
		drawtext(_T("按题目抽取"), &t, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		settextstyle(&g);
		setlinecolor(BLUE);
		setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 3);
		line(499,200,499,500);
		line(249,240,249,370);
		line(249,420,249,550);
		line(95,394,225,394);
		line(275,394,405,394);
		line(749,260,749,440);
	}
	while(1)
	{
		setlinecolor(BLACK);
		First->pDrawButton(First);
		Second->pDrawButton(Second);
		Third->pDrawButton(Third);
		Fourth->pDrawButton(Fourth);
		Fifth->pDrawButton(Fifth);
		EXIT->pDrawButton(EXIT);
		if(Choice[0]!=0)
		{
			easy->pDrawButton(easy);
			only->pDrawButton(only);
			littledifficut->pDrawButton(littledifficut);
			difficult->pDrawButton(difficult);
			input->pDrawButton(input);
			init->pDrawButton(init);
			putimage(95,240,&pic1);
			putimage(275,240,&pic2);
			putimage(95,420,&pic3);
			putimage(275,420,&pic4);
			putimage(550,260,&pic5);
			putimage(770,260,&pic6);
		}
		MOUSEMSG m=GetMouseMsg();
		tubiao();
		if(First->pMouseInButton(First,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=1;
			break;
		}
		if(Second->pMouseInButton(Second,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=2;
			break;
		}
		if(Third->pMouseInButton(Third,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=3;
			break;
		}
		if(Fourth->pMouseInButton(Fourth,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=4;
			break;
		}
		if(Fifth->pMouseInButton(Fifth,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=5; 
			break;
		}
		if(EXIT->pMouseInButton(EXIT,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=6;
			break;
		}
		if(Choice[0]!=0)
		{
			if(easy->pMouseInButton(easy,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				ai=-1;
				fourth2(ai);
				FlushBatchDraw();
				EndBatchDraw();
				//closegraph();
				//cleardevice();
				goto loop8;
			}
			if(only->pMouseInButton(only,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				ai=-0.5;
				fourth2(ai);
				FlushBatchDraw();
				EndBatchDraw();
				//closegraph();
				//cleardevice();
				goto loop8;
			}
			if(littledifficut->pMouseInButton(littledifficut,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				ai=0.5;
				fourth2(ai);
				FlushBatchDraw();
				EndBatchDraw();
				//closegraph();
				//cleardevice();
				goto loop8;
			}
			if(difficult->pMouseInButton(difficult,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				ai=1;
				fourth2(ai);
				FlushBatchDraw();
				EndBatchDraw();
				//closegraph();
				//cleardevice();
				goto loop8;
			}
			if(input->pMouseInButton(input,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				TCHAR c1[]=_T("请输入要导入的题目所在文件夹的地址:");
				InputBox(address2,100,c1,NULL,0,100,0,false);
				if(strlen(address2)==0)
				{
					sprintf(address2,"picture");
					RECT r = {600, 400, 1000, 600};
					drawtext(_T("请输入地址!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					FlushBatchDraw();
					EndBatchDraw();
					Sleep(1000);
					goto loop8;
				}
				//if ((fp = fopen(address2, "r")) == NULL)
				//{
				//sprintf(address2,"picture\\");
				//RECT r = {600, 400, 1000, 600};
				//drawtext(_T("访问不到地址名单，请重新输入！"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				//FlushBatchDraw();
				//EndBatchDraw();
				//Sleep(1000);
				//goto loop8;
				//}
				Time();
				sprintf(messageout,"%s题目文档导入成功,导入地址为'%s'\n",messagetime,address2);
				cout<<messageout;
				markmessage();
				goto loop8;
			}
			if(init->pMouseInButton(init,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				fourth4();
				goto loop8;
			}
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
	//closegraph();
}
void fourth2(double Ai)
{
	IMAGE pic1,pic2,pic3;
	FILE *fp;
	char c[10];
	int cii;
	int n=fourth3(Ai);
	sprintf(path,"C:\\skuser\\%s",number1);
	sprintf(path1,"%s\\%s",path,Choice);
	struct Button* fenshu=createButton(50,420,150,60,RGB(R3,G3,B3),RGB(R1,G1,B1),"进行得分评价",BLACK);
	struct Button* jixu=createButton(820,500,100,60,RGB(R3,G3,B3),RGB(R1,G1,B1),"继续抽取",BLACK);
	struct Button* fback=createButton(820,500,100,60,RGB(R3,G3,B3),RGB(R1,G1,B1),"返  回",BLACK);
	//initgraph(1000,600);
loop11:
	BeginBatchDraw();
	//setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
	cleardevice();
	loadimage(&img, _T("photo\\背景4.jpg"),1000,600);
	loadimage(&pic1, _T("photo\\得分评价.png"),140,50);
	loadimage(&pic2, _T("photo\\继续抽取.png"),90,50);
	loadimage(&pic3, _T("photo\\返回.png"),90,50);
	putimage(0,0,&img);
	LOGFONT f,g;
	gettextstyle(&f);
	gettextstyle(&g);
	f.lfHeight=48;
	_tcscpy(f.lfFaceName,_T("楷体"));
	f.lfQuality=ANTIALIASED_QUALITY;
	settextstyle(&f);
	settextcolor(BLUE);
	RECT r={0,0,1000,600};
	if(n==0)
		drawtext(_T("您还未添加学生，请先添加学生！"),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	else
	{
		drawtext(_T(printname),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	settextstyle(&g);
	while(1)
	{
		if(n==0)
		{
			fback->pDrawButton(fback);
			putimage(825,505,&pic3);
		}
		else
		{
			fenshu->pDrawButton(fenshu);
			jixu->pDrawButton(jixu);
			putimage(55,425,&pic1);
			putimage(825,505,&pic2);
		}
		MOUSEMSG m=GetMouseMsg();
		if(n==0)
		{
			if(fback->pMouseInButton(fback,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				break;
			}
		}
		else
		{
			if(fenshu->pMouseInButton(fenshu,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				TCHAR c1[]=_T("请输入该学生的得分");
				InputBox(c,100,c1,NULL,0,100,0,false);
				if(strlen(c)==0)
				{
					LOGFONT f;
					gettextstyle(&f);
					settextcolor(RED);
					settextstyle(30, 0, _T("Consolas"));
					RECT r={0,300,999,599};
					drawtext(_T("请输入分数"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					settextstyle(&f);
					FlushBatchDraw();
					EndBatchDraw();
					Sleep(1500);
					goto loop11;
				}
				cii=atoi(c);//把字符串c转换为长整型数cii
				if(cii<0||cii>100)
				{
					MessageBox(NULL,TEXT("请输入0-100之间的整数"),TEXT("数值错误"),MB_ICONEXCLAMATION|MB_OK);
				}
				else
				{
				student[keep].ci=reduce * (double)student[keep].ci+(1-reduce)*(double)cii;
				student[keep].di++; 
				if ((fp = fopen(path1, "w")) == NULL)
				{
					RECT r = {0, 0, 600, 350};
					drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					Sleep(3000);
					exit(0);
				}
				for(i=0;i<n;i++)
				{
					fprintf(fp,"%s\t",student[i].number);
					fprintf(fp,"%s\t",student[i].name);
					fprintf(fp,"%d\t",student[i].ci);
					fprintf(fp,"%d\t",student[i].di);
					fprintf(fp,"%d\t",student[i].ii);
					fprintf(fp,"%d\n",student[i].II);
				}
				fclose(fp);
				setbkmode(TRANSPARENT);
				LOGFONT f,g;
				gettextstyle(&f);
				gettextstyle(&g);
				f.lfHeight =40;
				_tcscpy(f.lfFaceName,_T("黑体"));
				f.lfQuality =ANTIALIASED_QUALITY;
				settextcolor(RED);
				settextstyle(&f);
				RECT r = {0, 0, 1000, 1000};
				drawtext(_T("记录完成"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				settextstyle(&g);
				//outtextxy(300,500,"记录完成");
				Time();
				sprintf(messageout,"%s抽到的学生为'%s',本次得分为%ld分\n",messagetime,printname,cii);
				cout<<messageout;
				markmessage();
				}
			}
			if(jixu->pMouseInButton(jixu,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				break;
			}
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
	//closegraph();
}
int fourth3(double Ai)
{
	FILE *fp,*fp2;
	long all=0;
	double allg=0;
	double temp=0;
	double temp2=0;
	long num;//随机数
	int n=0;
	sprintf(path,"C:\\skuser\\%s",number1);
	sprintf(path1,"%s\\%s",path,Choice);
	if ((fp = fopen(path1, "r")) == NULL)
	{
		RECT r = {0, 0, 600, 350};
		drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		Sleep(3000);
		exit(0);
	}
	while(fscanf(fp,"%s",student[n].number)!=EOF&&fscanf(fp,"%s",student[n].name)!=EOF&&fscanf(fp,"%d",&student[n].ci)!=EOF
		&&fscanf(fp,"%d",&student[n].di)!=EOF&&fscanf(fp,"%d",&student[n].ii)!=EOF&&fscanf(fp,"%d",&student[n].II)!=EOF)
		n++;
	fclose(fp);
	if(n!=0)
	{
	for(i=0;i<n;i++)
	{
		allg+=student[i].ci;
	}
	for(i=0;i<n;i++)
	{
		student[i].pi=skwork2((double)student[i].ci,(double)student[i].ii,(double)student[i].di,Ai,allg,(double)n);
	}
	for(i=0;i<n;i++)
			all=all+student[i].pi;
	num=(rand()*rand())%(all+n);
	for(i=0;i<n;i++)
	{
		temp2=(temp+student[i].pi);
		if(num>temp&&num<=temp2)
		{
			strcpy(printname,student[i].name);
			keep=i;
			/*if ((fp2 = fopen("1.txt", "w")) == NULL)
			{
				exit(0);
			}	
			fprintf(fp2,"%s",student[i].number);
			fclose(fp2);*/
			if(controlvideo)
				speech(student[i].number);
			break;
		}
		temp=temp2;
		if(i==n-1)
		{
			i=0;
			temp=0;
			temp2=0;
			num=(rand()*rand())%(all+n);
		}
	}
	}
	return n;
}
void fourth4()
{
	IMAGE pic1,pic2,pic3,pic4,pic5;
	bool dafen=false;
	char c[10];
	int cii;
	double deca=0.8;
	int tihao=1;
	char address3[200];
	FILE *fp;
	int n=0;
	int N=0;
loop10:
	sprintf(path,"C:\\skuser\\%s",number1);
	sprintf(path1,"%s\\%s",path,Choice);
	sprintf(address3,"%s\\%d.jpg",address2,tihao);
	struct Button* up=createButton(30,520,150,60,RGB(R3,G3,B3),RGB(R1,G1,B1),"上 一 题",BLACK);
	struct Button* down=createButton(200,520,150,60,RGB(R3,G3,B3),RGB(R1,G1,B1),"下 一 题",BLACK);
	struct Button* gogogo=createButton(420,520,150,60,RGB(R3,G3,B3),RGB(R1,G1,B1),"开 始 抽 取",BLACK);
	struct Button* giveit=createButton(590,520,150,60,RGB(R3,G3,B3),RGB(R1,G1,B1),"进行得分评价",BLACK);
	struct Button* goback=createButton(830,520,150,60,RGB(R3,G3,B3),RGB(R1,G1,B1),"返  回",BLACK);
	cleardevice();
	loadimage(&img, _T("photo\\背景4.jpg"),1000,600);
	loadimage(&pic1, _T("photo\\上一页.png"),140,50);
	loadimage(&pic2, _T("photo\\下一页.png"),140,50);
	loadimage(&pic3, _T("photo\\随机抽取.png"),140,50);
	loadimage(&pic4, _T("photo\\得分评价.png"),140,50);
	loadimage(&pic5, _T("photo\\返回.png"),140,50);
	putimage(0,0,&img);
	IMAGE timu;
	loadimage(&timu, _T(address3),900,420);
	putimage(50,30,&timu);
	setbkmode(TRANSPARENT);
	LOGFONT f,g;
	gettextstyle(&f);
	gettextstyle(&g);
	f.lfHeight=48;
	_tcscpy(f.lfFaceName,_T("楷体"));
	f.lfQuality=ANTIALIASED_QUALITY;
	settextstyle(&f);
	settextcolor(BLUE);
	RECT r={0,370,1000,600};
	if(n==0)
		drawtext(_T("点击抽取学生"),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	else
	{
		drawtext(_T(printname),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	settextstyle(&g);
	while(1)
	{
		if(Choice[0]!=0)
		{
			up->pDrawButton(up);
			down->pDrawButton(down);
			gogogo->pDrawButton(gogogo);
			goback->pDrawButton(goback);
			putimage(35,525,&pic1);
			putimage(205,525,&pic2);
			putimage(425,525,&pic3);
			putimage(835,525,&pic5);
			if(dafen)
			{
				giveit->pDrawButton(giveit);
				putimage(595,525,&pic4);
			}
		}
		MOUSEMSG m=GetMouseMsg();
		BeginBatchDraw();
		if(up->pMouseInButton(up,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			n=0;
			tihao-=1;
			if(tihao<1)
				tihao=1;
			dafen=false;
			goto loop10;
		}
		if(down->pMouseInButton(down,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			n=0;
			tihao+=1;
			dafen=false;
			goto loop10;
		}
		if(gogogo->pMouseInButton(gogogo,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			N=fourth5();
			n=N;
			if(N==0)
				dafen=false;
			else
			dafen=true;
			goto loop10;
		}
		if(giveit->pMouseInButton(giveit,m)&&m.uMsg==WM_LBUTTONDOWN&&dafen)
		{
			music();
			TCHAR c1[]=_T("请输入该学生的得分评价");
			InputBox(c,100,c1,NULL,0,100,0,false);
			if(strlen(c)==0)
			{
				LOGFONT f;
				gettextstyle(&f);
				settextcolor(RED);
				settextstyle(30, 0, _T("Consolas"));
				RECT r={0,300,999,599};
				drawtext(_T("请输入分数"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				settextstyle(&f);
				FlushBatchDraw();
				EndBatchDraw();
				Sleep(1500);
				goto loop10;
			}
			cii=atoi(c);//把字符串c转换为长整型数cii
			if(cii<0||cii>100)
				{
					MessageBox(NULL,TEXT("请输入0-100之间的整数"),TEXT("数值错误"),MB_ICONEXCLAMATION|MB_OK);
				}
			else
			{
			student[keep].ci=deca * (double)student[keep].ci+(1-deca)*(double)cii;
			student[keep].di++; 
			if ((fp = fopen(path1, "w")) == NULL)
			{
				RECT r = {0, 0, 600, 350};
				drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				Sleep(3000);
				exit(0);
			}
			for(i=0;i<n;i++)
			{
				fprintf(fp,"%s\t",student[i].number);
				fprintf(fp,"%s\t",student[i].name);
				fprintf(fp,"%d\t",student[i].ci);
				fprintf(fp,"%d\t",student[i].di);
				fprintf(fp,"%d\t",student[i].ii);
				fprintf(fp,"%d\n",student[i].II);
			}
			fclose(fp);
			outtextxy(742,550,"记录完成");
			Time();
			sprintf(messageout,"%s抽到的学生为'%s',本次得分为%ld分\n",messagetime,printname,cii);
			cout<<messageout;
			markmessage();
			}
		}
		if(goback->pMouseInButton(goback,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			break;
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
}
int fourth5()
{
	FILE *fp,*fp2;
	double s=0.5;
	double all=0;
	double temp=0;
	double temp2;
	int num;//随机数
	int n=0;
	sprintf(path,"C:\\skuser\\%s",number1);
	sprintf(path1,"%s\\%s",path,Choice);
	if ((fp = fopen(path1, "r")) == NULL)
	{
		RECT r = {0, 0, 600, 350};
		drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		Sleep(3000);
		exit(0);
	}
	while(fscanf(fp,"%s",student[n].number)!=EOF&&fscanf(fp,"%s",student[n].name)!=EOF&&fscanf(fp,"%d",&student[n].ci)!=EOF
		&&fscanf(fp,"%d",&student[n].di)!=EOF&&fscanf(fp,"%d",&student[n].ii)!=EOF&&fscanf(fp,"%d",&student[n].II)!=EOF)
		n++;
	fclose(fp);
	for(i=0;i<n;i++)
	{
		student[i].yinzi=skwork3((double)student[i].di,(double)student[i].ci,student[i].ii);
		all=all+exp(student[i].yinzi);
	}
	for(i=0;i<n;i++)
		student[i].pi=exp(student[i].yinzi)/all;
	num=rand()%10000;
	for(i=0;i<n;i++)
	{
		temp2=(temp+student[i].pi*10000);
		if(num>temp&&num<=temp2)
		{
			strcpy(printname,student[i].name);
			keep=i;
			/*if ((fp2 = fopen("1.txt", "w")) == NULL)
			{
				exit(0);
			}	
			fprintf(fp2,"%s",student[i].number);
			fclose(fp2);*/
			if(controlvideo)
				speech(student[i].number);
			break;
		}
		temp=temp2;
		if(i==n-1)
		{
			i=0;
			temp=0;
			temp2=0;
			num=rand()%10000;
		}
	}
	return n;
}
void fifth()
{
	IMAGE pic;
	FILE *fp2;
	int num=-1;
loop9:	
	int n=0;
	struct Button* First=createButton(10,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* Second=createButton(110,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* Third=createButton(210,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* Fourth=createButton(310,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* Fifth=createButton(410,40,100,75,RGB(R3,G3,B3),RGB(R3,G3,B3),"",BLACK);
	struct Button* EXIT=createButton(510,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* Go=createButton(300,430,400,150,RGB(R3,G3,B3),RGB(R1,G1,B1),"开  始  抽  取",BLACK);
	//initgraph(1000,600);
	BeginBatchDraw();
	//setbkcolor(WHITE);
	cleardevice();
	loadimage(&img, _T("photo\\背景3.png"),1000,600);
	loadimage(&pic, _T("photo\\随机抽取.png"),380,130);
	putimage(0,0,&img);
	tubiaoshengming();
	tips();
	if(Choice[0]!=0)
	{
		FILE *fp;
		sprintf(path,"C:\\skuser\\%s",number1);
		sprintf(path1,"%s\\%s",path,Choice);
		if ((fp = fopen(path1, "r")) == NULL)
		{
			RECT r = {0, 0, 600, 350};
			drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			Sleep(3000);
			exit(0);
		}
		while(fscanf(fp,"%s",student[n].number)!=EOF&&fscanf(fp,"%s",student[n].name)!=EOF&&fscanf(fp,"%d",&student[n].ci)!=EOF
			&&fscanf(fp,"%d",&student[n].di)!=EOF&&fscanf(fp,"%d",&student[n].ii)!=EOF&&fscanf(fp,"%d",&student[n].II)!=EOF)
			n++;
		fclose(fp); 
		if(n==0)
		{
			setbkmode(TRANSPARENT);
			LOGFONT f,g;
			gettextstyle(&f);
			gettextstyle(&g);
			f.lfHeight =30;
			_tcscpy(f.lfFaceName,_T("黑体"));
			f.lfQuality =ANTIALIASED_QUALITY;
			settextcolor(RED);
			settextstyle(&f);
			RECT r={0,0,1000,600};
			drawtext("您还未添加学生，快去添加学生吧！",&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			settextstyle(&g);
		}
	}
	if(n!=0&&num==-1) 
	{
		LOGFONT f,g;
		gettextstyle(&f);
		gettextstyle(&g);
		f.lfHeight=48;
		_tcscpy(f.lfFaceName,_T("宋体"));
		f.lfQuality=ANTIALIASED_QUALITY;
		settextstyle(&f);
		settextcolor(BLUE);
		RECT r={0,0,1000,550};
		drawtext("点击开始抽取",&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		settextstyle(&g);
	}
	if(n!=0&&num!=-1)
	{
		LOGFONT f,g;
		gettextstyle(&f);
		gettextstyle(&g);
		f.lfHeight=48;
		_tcscpy(f.lfFaceName,_T("宋体"));
		f.lfQuality=ANTIALIASED_QUALITY;
		settextstyle(&f);
		settextcolor(BLUE);
		RECT r={0,0,1000,550};
		drawtext(_T(student[num].name),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		settextstyle(&g);
	}
	while(1)
	{
		setlinecolor(BLACK);
		First->pDrawButton(First);
		Second->pDrawButton(Second);
		Third->pDrawButton(Third);
		Fourth->pDrawButton(Fourth);
		Fifth->pDrawButton(Fifth);
		EXIT->pDrawButton(EXIT);
		if(Choice[0]!=0)
			if(n!=0)
			{
				Go->pDrawButton(Go);
				putimage(310,440,&pic);
			}
			MOUSEMSG m=GetMouseMsg();
			tubiao();
			if(First->pMouseInButton(First,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				control=1;
				break;
			}
			if(Second->pMouseInButton(Second,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				control=2;
				break;
			}
			if(Third->pMouseInButton(Third,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				control=3;
				break;
			}
			if(Fourth->pMouseInButton(Fourth,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				control=4;
				break;
			}
			if(Fifth->pMouseInButton(Fifth,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				control=5;
				break;
			}
			if(EXIT->pMouseInButton(EXIT,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				control=6;
				break;
			}
			if(Choice[0]!=0)
			{
				if(n!=0)
				{
					if(Go->pMouseInButton(Go,m)&&m.uMsg==WM_LBUTTONDOWN)
					{
						music();
						if(n!=0)
							num=rand()%n;
						FlushBatchDraw();
						/*if ((fp2 = fopen("1.txt", "w")) == NULL)
						{
							exit(0);
						}
						fprintf(fp2,"%s",student[num].number);
						fclose(fp2);*/
						if(controlvideo)
							speech(student[num].number);
						Time();
						sprintf(messageout,"%s随机抽到的学生为'%s'\n",messagetime,student[num].name);
						cout<<messageout;
						markmessage();
						goto loop9; 
					}
				}
			}
			FlushBatchDraw();
	}
	EndBatchDraw();
	//closegraph();
}
void six()
{
	FILE *fp;
	IMAGE pic1,pic2,pic3;
loop11:
	struct Button* First=createButton(10,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* Second=createButton(110,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* Third=createButton(210,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* Fourth=createButton(310,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* Fifth=createButton(410,40,100,75,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	struct Button* Six=createButton(510,40,100,75,RGB(R3,G3,B3),RGB(R3,G3,B3),"",BLACK);
	struct Button* Music=createButton(660,210,100,80,RGB(R3,G3,B3),RGB(R4,G4,B4),ControlMusic,BLACK);
	struct Button* Reduce=createButton(660,350,100,80,RGB(R3,G3,B3),RGB(R4,G4,B4),ControlReduce,BLACK);
	struct Button* Video=createButton(660,490,100,80,RGB(R3,G3,B3),RGB(R4,G4,B4),ControlVideo,BLACK);
	//initgraph(1000,600);
	BeginBatchDraw();
	//setbkcolor(WHITE);
	cleardevice();
	loadimage(&img, _T("photo\\背景3.png"),1000,600);
	loadimage(&pic1, _T("photo\\Music.png"),580,100);
	loadimage(&pic2, _T("photo\\Reduce.png"),580,100);
	loadimage(&pic3, _T("photo\\Video.png"),580,100);
	putimage(0,0,&img);
	tubiaoshengming();
	tips2();
	while(1)
	{
		setlinecolor(BLACK);
		First->pDrawButton(First);
		Second->pDrawButton(Second);
		Third->pDrawButton(Third);
		Fourth->pDrawButton(Fourth);
		Fifth->pDrawButton(Fifth);
		Six->pDrawButton(Six);
		if(strcmp(number1,"0")!=0)
		{
			putimage(210,200,&pic1);
			putimage(210,340,&pic2);
			putimage(210,480,&pic3);
			Music->pDrawButton(Music);
			Video->pDrawButton(Video);
			Reduce->pDrawButton(Reduce);
		}
		MOUSEMSG m=GetMouseMsg();
		tubiao();
		if(First->pMouseInButton(First,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=1;
			break;
		}
		if(Second->pMouseInButton(Second,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=2;
			break;
		}
		if(Third->pMouseInButton(Third,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=3;
			break;
		}
		if(Fourth->pMouseInButton(Fourth,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=4;
			break;
		}
		if(Fifth->pMouseInButton(Fifth,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=5;
			break;
		}
		if(Six->pMouseInButton(Six,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			control=6;
			break;
		}
		if(strcmp(number1,"0")!=0)
		{
			if(Music->pMouseInButton(Music,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				if ((fp = fopen(set, "w")) == NULL)
				{
					exit(0);
				}
				if(controlmusic)
				{
					strcpy(ControlMusic,"OFF");
					controlmusic=false;
					sett[0]=0;
				}
				else
				{
					strcpy(ControlMusic,"ON");
					controlmusic=true;
					sett[0]=1;
				}
				for(i=0;i<3;i++)
					fprintf(fp,"%d\t",sett[i]);
				fclose(fp);
				Time();
				sprintf(messageout,"%s当前音效状态'%s'\n",messagetime,ControlMusic);
				cout<<messageout;
				markmessage();
				goto loop11;
			}
			if(Video->pMouseInButton(Video,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				if ((fp = fopen(set, "w")) == NULL)
				{
					exit(0);
				}
				if(controlvideo)
				{
					strcpy(ControlVideo,"OFF");
					controlvideo=false;
					sett[1]=0;
				}
				else
				{
					strcpy(ControlVideo,"ON");
					controlvideo=true;
					sett[1]=1;
				}
				for(i=0;i<3;i++)
					fprintf(fp,"%d\t",sett[i]);
				fclose(fp);
				Time();
				sprintf(messageout,"%s当前播报状态'%s'\n",messagetime,ControlVideo);
				cout<<messageout;
				markmessage();
				goto loop11;
			}
			if(Reduce->pMouseInButton(Reduce,m)&&m.uMsg==WM_LBUTTONDOWN)
			{
				music();
				if ((fp = fopen(set, "w")) == NULL)
				{
					exit(0);
				}
				if(controlreduce)
				{
					strcpy(ControlReduce,"OFF");
					controlreduce=false;
					reduce=0.2;
					sett[2]=0;
				}
				else
				{
					strcpy(ControlReduce,"ON");
					controlreduce=true;
					reduce=0.8;
					sett[2]=1;
				}
				for(i=0;i<3;i++)
					fprintf(fp,"%d\t",sett[i]);
				fclose(fp);
				Time();
				sprintf(messageout,"%s当前关注状态'%s'\n",messagetime,ControlReduce);
				cout<<messageout;
				markmessage();
				goto loop11;
			}
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
}
void Replace()
{
	IMAGE pic1,pic2,pic3,pic4,pic5;
	char addclass[200];
	char deleteclass[200];
	char modifyclass[200];
	FILE *fp,*fp2;
loop4:
	struct Button* Modify=createButton(250,50,230,230,RGB(R3,G3,B3),RGB(R1,G1,B1),"修   改   密   码",BLACK);
	struct Button* radd=createButton(520,50,230,230,RGB(R3,G3,B3),RGB(R1,G1,B1),"添   加   课   程",BLACK);
	struct Button* rdelete=createButton(250,320,230,230,RGB(R3,G3,B3),RGB(R1,G1,B1),"删   除   课   程",BLACK);
	struct Button* rdeleteall=createButton(520,320,230,230,RGB(R3,G3,B3),RGB(R1,G1,B1),"清   空   课   程",BLACK);
	struct Button* rback=createButton(800,500,160,80,RGB(R3,G3,B3),RGB(R1,G1,B1),"返   回",BLACK);
	//initgraph(1000,600);
	BeginBatchDraw();
	//setbkcolor(WHITE);
	cleardevice();
	loadimage(&img, _T("photo\\背景4.jpg"),1000,600);
	loadimage(&pic1, _T("photo\\修改密码.png"),210,210);
	loadimage(&pic2, _T("photo\\添加课程.png"),210,210);
	loadimage(&pic3, _T("photo\\删除课程.png"),210,210);
	loadimage(&pic4, _T("photo\\清空课程.png"),210,210);
	loadimage(&pic5, _T("photo\\返回.png"),150,70);
	putimage(0,0,&img);
	setlinecolor(BLUE);
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 3);
	line(499,60,499,270);
	line(499,330,499,540);
	line(260,299,470,299);
	line(530,299,740,299);
	while(1)
	{
		Modify->pDrawButton(Modify);
		radd->pDrawButton(radd);
		rdelete->pDrawButton(rdelete);
		rdeleteall->pDrawButton(rdeleteall);
		rback->pDrawButton(rback);
		putimage(260,60,&pic1);
		putimage(530,60,&pic2);
		putimage(260,330,&pic3);
		putimage(530,330,&pic4);
		putimage(805,505,&pic5);
		MOUSEMSG m=GetMouseMsg();
		if(Modify->pMouseInButton(Modify,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			modify();
			FlushBatchDraw();
			EndBatchDraw();
			//closegraph();
			//cleardevice();
			goto loop4;
		}
		if(radd->pMouseInButton(radd,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			TCHAR c1[]=_T("请输入要添加的课程:");
			InputBox(addclass,100,c1,NULL,0,100,false);
			if(strlen(addclass)==0)
			{
				RECT r = {0, 0, 1000, 600};
				drawtext(_T("请输入课程！"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE); 
				FlushBatchDraw();
				EndBatchDraw();
				//closegraph();
				//cleardevice();
				Sleep(1000);
				goto loop4;
			}
			FILE *fp3;
			sprintf(path,"C:\\skuser\\%s",number1);
			sprintf(path1,"%s\\messages",path);
			sprintf(path2,"%s\\%s",path,addclass);
			if ((fp3 = fopen(path2, "r")) != NULL)
			{
				RECT r = {0, 0, 1000, 600};
				drawtext(_T("已添加此课程！"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE); 
				fclose(fp3);
				FlushBatchDraw();
				EndBatchDraw();
				//closegraph();
				//cleardevice();
				Sleep(1000);
				goto loop4;
			}
			else
			{ 
				//fclose(fp3);
				if ((fp = fopen(path1, "a")) == NULL)
				{
					RECT r = {0, 0, 600, 350};
					drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					Sleep(3000);
					exit(0);
				}
				fprintf(fp,"%s\t\n",addclass);
				fclose(fp);
				if ((fp = fopen(path2, "w+")) == NULL)
				{
					RECT r = {0, 0, 600, 350};
					drawtext(_T("名单创建失败，将自动退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					Sleep(3000);
					exit(0);
				}
				fclose(fp);
				RECT r = {0, 0, 1000, 600};
				drawtext(_T("添加成功"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE); 
				FlushBatchDraw();
				EndBatchDraw();
				Sleep(1000);
				Time();
				sprintf(messageout,"%s添加课程'%s'成功\n",messagetime,addclass);
				cout<<messageout;
				markmessage();
				//closegraph();
				//cleardevice();
				goto loop4;
			}
		}
		if(rdelete->pMouseInButton(rdelete,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			char cache[50];
			TCHAR c1[]=_T("请输入要删除的课程:");
			InputBox(deleteclass,100,c1,NULL,0,100,false);
			if(strlen(deleteclass)==0)
			{
				RECT r = {0, 0, 1000, 600};
				drawtext(_T("请输入课程！"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE); 
				FlushBatchDraw();
				EndBatchDraw();
				//closegraph();
				//cleardevice();
				Sleep(1000);
				goto loop4;
			}
			sprintf(path,"C:\\skuser\\%s",number1);
			sprintf(path1,"%s\\messages",path);
			sprintf(path2,"%s\\%s",path,deleteclass);
			sprintf(path3,"%s\\cache",path);
			sprintf(path4,"%s\\null",path);
			if ((fp = fopen(path1, "r")) == NULL)
			{
				RECT r = {0, 0, 600, 350};
				drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				Sleep(3000);
				exit(0);
			}
			if ((fp2 = fopen(path3, "w")) == NULL)
			{
				RECT r = {0, 0, 600, 350};
				drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				Sleep(3000);
				exit(0);
			}
			while(fscanf(fp,"%s",cache)!=EOF)
				if(strcmp(deleteclass,cache))
					fprintf(fp2,"%s\t\n",cache);
			fclose(fp);
			fclose(fp2);
			remove(path2);
			rename(path1,path4);
			rename(path3,path1);
			rename(path4,path3);
			RECT r = {0, 0, 1000, 600};
			drawtext(_T("删除成功"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE); 
			FlushBatchDraw();
			EndBatchDraw();
			Sleep(1000);
			Time();
			sprintf(messageout,"%s删除课程'%s'成功\n",messagetime,deleteclass);
			cout<<messageout;
			markmessage();
			//closegraph();
			//cleardevice();
			goto loop4;
		}
		if(rdeleteall->pMouseInButton(rdeleteall,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			char clearclass[200];
			char clearclasskey[200];
			sprintf(path,"C:\\skuser\\%s",number1);
			sprintf(path1,"%s\\messages",path);
			TCHAR c1[]=_T("清空信息将不可逆，请输入密码来确定清空！！！");
			InputBox(clearclasskey,100,c1,NULL,0,100,0,false);
			if(strlen(clearclasskey)==0)
			{
				RECT r = {0, 0, 1000, 600};
				drawtext(_T("请输入密码！"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE); 
				FlushBatchDraw();
				EndBatchDraw();
				//closegraph();
				//cleardevice();
				Sleep(1000);
				goto loop4;
			}
			if(strcmp(clearclasskey,number2))
			{
				RECT r = {0, 0, 1000, 600};
				drawtext(_T("密码错误，请重新输入"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				FlushBatchDraw();
				EndBatchDraw();
				Sleep(1000);
				goto loop4;
			}
			else
			{
				if ((fp = fopen(path1, "r")) == NULL)
				{
					RECT r = {0, 0, 600, 350};
					drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					Sleep(3000);
					exit(0);
				}
				while(fscanf(fp,"%s",clearclass)!=EOF)
				{
					sprintf(path2,"%s\\%s",path,clearclass);
					remove(path2);
				}
				fclose(fp);
				if ((fp = fopen(path1, "w")) == NULL)
				{
					RECT r = {0, 0, 600, 350};
					drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					Sleep(3000);
					exit(0);
				}
				fclose(fp);
				Choice[0]=0;
				RECT r = {0, 0, 1000, 600};
				drawtext(_T("清空完成"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				FlushBatchDraw();
				EndBatchDraw();
				Sleep(1000);
				Time();
				sprintf(messageout,"%s清空课程成功\n",messagetime);
				cout<<messageout;
				markmessage();
				goto loop4;
			}
		}
		if(rback->pMouseInButton(rback,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			break;
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
	//closegraph();
}
void modify()
{
	char nextpasswordnumber[100]={0};
	char newpasswordnumber[100]={0};
	char againpasswordnumber[100]={0};
	char outnextpasswordnumber[100]={0};
	char outnewpasswordnumber[100]={0};
	char outagainpasswordnumber[100]={0};
	out1=true;
loop3:
	FILE *fp;
	struct Button* mnextpassword=createButton(480,180,240,40,RGB(R3,G3,B3),RGB(R3,G3,B3),outnextpasswordnumber,BLACK);
	struct Button* mnewpassword=createButton(480,240,240,40,RGB(R3,G3,B3),RGB(R3,G3,B3),outnewpasswordnumber,BLACK);
	struct Button* magainpassword=createButton(480,300,240,40,RGB(R3,G3,B3),RGB(R3,G3,B3),outagainpasswordnumber,BLACK);
	struct Button* moutnumber=createButton(310,350,85,20,RGB(R3,G3,B3),RGB(R4,G4,B4),"显示密码",BLACK);
	struct Button* mOK=createButton(425,510,150,60,RGB(R3,G3,B3),RGB(R4,G4,B4),"确   定",BLACK);
	struct Button* mback=createButton(700,510,150,60,RGB(R3,G3,B3),RGB(R4,G4,B4),"返   回",BLACK);
	//initgraph(1000,600);
	BeginBatchDraw();
	//setbkcolor(WHITE);
	cleardevice();
	//loadimage(&img, _T("背景.jpg"),1000,600); 
	putimage(0,0,&img);
	LOGFONT f;
	gettextstyle(&f);
	settextcolor(BLACK);
	settextstyle(30, 0, _T("Consolas"));
	outtextxy(285,185,"请输入原密码:");
	outtextxy(285,245,"请输入现密码:");
	outtextxy(285,305,"请确认现密码:");
	settextstyle(&f);
	if(out1)
		setfillcolor(RGB(R1,G1,B1));
	else
		setfillcolor(RGB(R2,G2,B2));
	fillcircle(295,360,5);
	while(1)
	{
		mnextpassword->pDrawButton(mnextpassword);
		mnewpassword->pDrawButton(mnewpassword);
		magainpassword->pDrawButton(magainpassword);
		moutnumber->pDrawButton(moutnumber);
		mOK->pDrawButton(mOK);
		mback->pDrawButton(mback);
		MOUSEMSG m=GetMouseMsg();
		if(mnextpassword->pMouseInButton(mnextpassword,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			//TCHAR c1[]=_T("请输入原密码:");
			//InputBox(nextpasswordnumber,100,c1,NULL,0,100,0,false);
			Out(480,180,720,220,nextpasswordnumber);
			if(out1)
				for(i=0;i<strlen(nextpasswordnumber);i++)
					outnextpasswordnumber[i]='*';
			else
				strcpy(outnextpasswordnumber,nextpasswordnumber);
			FlushBatchDraw();
			EndBatchDraw();
			goto loop3;
		}
		if(mnewpassword->pMouseInButton(mnewpassword,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			//TCHAR c1[]=_T("请输入修改的密码:");
			//InputBox(newpasswordnumber,100,c1,NULL,0,100,0,false);
			Out(480,240,720,280,newpasswordnumber);
			if(out1)
				for(i=0;i<strlen(newpasswordnumber);i++)
					outnewpasswordnumber[i]='*';
			else
				strcpy(outnewpasswordnumber,newpasswordnumber);
			FlushBatchDraw();
			EndBatchDraw();
			goto loop3;
		}
		if(magainpassword->pMouseInButton(magainpassword,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			//TCHAR c1[]=_T("请确认修改的密码:");
			//InputBox(againpasswordnumber,100,c1,NULL,0,100,0,false);
			Out(480,300,720,340,againpasswordnumber);
			if(out1)
				for(i=0;i<strlen(againpasswordnumber);i++)
					outagainpasswordnumber[i]='*';
			else
				strcpy(outagainpasswordnumber,againpasswordnumber);
			FlushBatchDraw();
			EndBatchDraw();
			goto loop3;
		}
		if(moutnumber->pMouseInButton(moutnumber,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			if(out1)
				out1=false;
			else
				out1=true;
			if(out1)
			{
				for(i=0;i<strlen(nextpasswordnumber);i++)
					outnextpasswordnumber[i]='*';
				for(i=0;i<strlen(newpasswordnumber);i++)
					outnewpasswordnumber[i]='*';
				for(i=0;i<strlen(againpasswordnumber);i++)
					outagainpasswordnumber[i]='*';
			}
			else
			{
				strcpy(outnextpasswordnumber,nextpasswordnumber);
				strcpy(outnewpasswordnumber,newpasswordnumber);
				strcpy(outagainpasswordnumber,againpasswordnumber);
			}
			FlushBatchDraw();
			EndBatchDraw();
			goto loop3;
		}
		if(mOK->pMouseInButton(mOK,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			if(strlen(nextpasswordnumber)==0||strlen(newpasswordnumber)==0||strlen(againpasswordnumber)==0)
			{
				RECT r = {0, 300, 1000, 600}; 
				drawtext(_T("三项均不能为空！"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				FlushBatchDraw();
				EndBatchDraw();
				//closegraph();
				//cleardevice();
				Sleep(1000);
				goto loop3;
			}
			sprintf(path,"C:\\skuser\\%s",number1);
			sprintf(path1,"%s\\keys",path);
			if ((fp = fopen(path1, "r")) == NULL)
			{
				RECT r = {0, 300, 1000, 600}; 
				drawtext(_T("账号不存在"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				Sleep(1000);
				FlushBatchDraw();
				EndBatchDraw();
				//closegraph();
				//cleardevice();
				goto loop3;
			}
			for(i=0;i<strlen(number2);i++)
				fscanf(fp, "%c",&key[i]);
			if(strcmp(key,nextpasswordnumber)!=0)
			{
				RECT r = {0, 300, 1000, 600};
				drawtext(_T("密码错误"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				fclose(fp);
				FlushBatchDraw();
				EndBatchDraw();
				//closegraph();
				//cleardevice();
				Sleep(1000);
				goto loop3;
			}
			else
			{
				fclose(fp);
				if(strcmp(newpasswordnumber,againpasswordnumber)!=0)
				{
					RECT r = {0, 300, 1000, 600};
					drawtext(_T("两次密码不一致"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					FlushBatchDraw();
					EndBatchDraw();
					//closegraph();
					//cleardevice();
					Sleep(1000);
					goto loop3;                           
				}
				else 
				{
					if ((fp = fopen(path1, "w")) == NULL)
					{
						RECT r = {0, 300, 1000, 600};
						drawtext(_T("账号不存在"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
						Sleep(1000);
						FlushBatchDraw();
						EndBatchDraw();
						//closegraph();
						//cleardevice();
						goto loop3;
					}
					for(i=0;i<strlen(againpasswordnumber);i++)
						fprintf(fp, "%c",againpasswordnumber[i]);
					RECT r = {0, 300, 1000, 600};
					drawtext(_T("修改成功"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					fclose(fp);
					FlushBatchDraw();
					EndBatchDraw();
					//closegraph();
					//cleardevice();
					Sleep(1000);
					Time();
					sprintf(messageout,"%s用户'%s'密码修改成功!\n",messagetime,number1);
					cout<<messageout;
					markmessage();
					goto loop3;
				}
			}
		}
		if(mback->pMouseInButton(mback,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			break;
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
} 
void printstudents()
{
	IMAGE pic1,pic2,pic3,pic4,pic5;
	FILE *fp;
	int n=0;
	int num=1;
	char out[200];
	char grade[200];
	char a[10];
	char b[10];
	sprintf(path,"C:\\skuser\\%s",number1);
	sprintf(path1,"%s\\%s",path,Choice);
	if ((fp = fopen(path1, "r")) == NULL)
	{
		RECT r = {0, 0, 600, 350};
		drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		Sleep(3000);
		exit(0);
	}
	while(fscanf(fp,"%s",student[n].number)!=EOF&&fscanf(fp,"%s",student[n].name)!=EOF&&fscanf(fp,"%d",&student[n].ci)!=EOF
		&&fscanf(fp,"%d",&student[n].di)!=EOF&&fscanf(fp,"%d",&student[n].ii)!=EOF&&fscanf(fp,"%d",&student[n].II)!=EOF)
		n++;
	fclose(fp);
loop7:
	struct Button* lbefore=createButton(150,510,100,60,RGB(R3,G3,B3),RGB(R1,G1,B1),"上一页",BLACK);
	struct Button* lafter=createButton(620,510,100,60,RGB(R3,G3,B3),RGB(R1,G1,B1),"下一页",BLACK);
	struct Button* first=createButton(280,510,100,60,RGB(R3,G3,B3),RGB(R1,G1,B1),"首   页",BLACK);
	struct Button* last=createButton(750,510,100,60,RGB(R3,G3,B3),RGB(R1,G1,B1),"末   页",BLACK);
	struct Button* lback=createButton(900,520,70,50,RGB(R3,G3,B3),RGB(R1,G1,B1),"返  回",BLACK);
	//initgraph(1000,600);
	BeginBatchDraw();
	//setbkcolor(WHITE);
	cleardevice();
	loadimage(&img, _T("photo\\背景4.jpg"),1000,600);
	loadimage(&pic1, _T("photo\\上一页.png"),90,50);
	loadimage(&pic2, _T("photo\\下一页.png"),90,50);
	loadimage(&pic3, _T("photo\\首页.png"),90,50);
	loadimage(&pic4, _T("photo\\尾页.png"),90,50);
	loadimage(&pic5, _T("photo\\返回.png"),60,40);
	putimage(0,0,&img);
	sprintf(out,"第%d页，共%d页",num,n/10+1);
	setlinecolor(BLACK);
	setbkmode(TRANSPARENT);
	LOGFONT f,g;
	gettextstyle(&f);
	gettextstyle(&g);
	f.lfHeight =25;
	_tcscpy(f.lfFaceName,_T("黑体"));
	f.lfQuality =ANTIALIASED_QUALITY;
	settextcolor(RED);
	settextstyle(&f);
	outtextxy(90,15,"学     号");
	outtextxy(320,15,"姓         名");
	outtextxy(580,15,"分 数");
	outtextxy(670,15,"提问次数");
	outtextxy(820,15,"缺勤次数");
	outtextxy(740,460,out);
	settextcolor(BLUE);
	for(i=num*10-10;i<num*10&&i<n;i++)
	{
		sprintf(grade,"%d分",student[i].ci);
		sprintf(a,"%d次",student[i].di);
		sprintf(b,"%d次",student[i].ii);
		outtextxy(55,55+40*(i-(num-1)*10),student[i].number);
		outtextxy(260,55+40*(i-(num-1)*10),student[i].name);
		outtextxy(575,55+40*(i-(num-1)*10),grade);
		outtextxy(670,55+40*(i-(num-1)*10),a);
		outtextxy(820,55+40*(i-(num-1)*10),b);
	}
	settextstyle(&g);
	for(i=0;i<12;i++)
		line(50,10+40*i,950,10+40*i);
	line(50,10,50,450);
	line(250,10,250,450);
	line(570,10,570,450);
	line(650,10,650,450);
	line(800,10,800,450);
	line(950,10,950,450);
	while(1)
	{
		if(n>=10)
		{
			lbefore->pDrawButton(lbefore);
			lafter->pDrawButton(lafter);
			first->pDrawButton(first);
			last->pDrawButton(last);
			putimage(155,515,&pic1);
			putimage(625,515,&pic2);
			putimage(285,515,&pic3);
			putimage(755,515,&pic4);
		}
		lback->pDrawButton(lback);
		putimage(905,525,&pic5);
		MOUSEMSG m=GetMouseMsg();
		if(lbefore->pMouseInButton(lbefore,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			num--;
			if(num<=0)
				num=1;
			/*FlushBatchDraw();
			EndBatchDraw();
			closegraph();*/
			//cleardevice();
			goto loop7;
		}
		if(lafter->pMouseInButton(lafter,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			num++;
			if(num>=(n/10+1))
				num=(n/10+1);
			/*FlushBatchDraw();
			EndBatchDraw();
			closegraph();*/
			//cleardevice();
			goto loop7;
		}
		if(first->pMouseInButton(first,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			num=1;
			/*FlushBatchDraw();
			EndBatchDraw();
			closegraph();
			cleardevice();*/
			goto loop7;
		}
		if(last->pMouseInButton(last,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			num=(n/10+1);
			/*FlushBatchDraw();
			EndBatchDraw();
			closegraph();*/
			//cleardevice();
			goto loop7;
		}
		if(lback->pMouseInButton(lback,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			break;
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
	//closegraph();
}
void setstudents()
{
	IMAGE pic1,pic2,pic3,pic4,pic5,pic6,pic7;
	char addstudents[200];
	char deletestudents[200];
	char clearstudents[200];
	char address[200];
	char number[200];
	FILE *fp,*fp2,*fp3;
	sprintf(path,"C:\\skuser\\%s",number1);
	sprintf(path1,"%s\\%s",path,Choice);
	sprintf(path2,"%s\\cache",path);
	sprintf(path3,"%s\\null",path);
loop6:
	int n=0;
	struct Button* sclear=createButton(195,75,170,170,RGB(R3,G3,B3),RGB(R1,G1,B1),"重 置 学 生 信 息",BLACK);
	struct Button* sclearall=createButton(195,295,170,170,RGB(R3,G3,B3),RGB(R1,G1,B1),"清 空 学 生 信 息",BLACK);
	struct Button* sadd=createButton(415,75,170,170,RGB(R3,G3,B3),RGB(R1,G1,B1),"添   加   学   生",BLACK);
	struct Button* sdelete=createButton(415,295,170,170,RGB(R3,G3,B3),RGB(R1,G1,B1),"删   除   学   生",BLACK);
	struct Button* sinto=createButton(635,75,170,170,RGB(R3,G3,B3),RGB(R1,G1,B1),"导   入   学   生",BLACK);
	struct Button* sout=createButton(635,295,170,170,RGB(R3,G3,B3),RGB(R1,G1,B1),"导   出   学   生",BLACK);
	struct Button* sback=createButton(800,500,150,80,RGB(R3,G3,B3),RGB(R1,G1,B1),"返   回",BLACK);
	BeginBatchDraw();
	cleardevice();
	loadimage(&img, _T("photo\\背景4.jpg"),1000,600);
	loadimage(&pic1, _T("photo\\重置信息.png"),150,150);
	loadimage(&pic2, _T("photo\\清空信息.png"),150,150);
	loadimage(&pic3, _T("photo\\添加学生.png"),150,150);
	loadimage(&pic4, _T("photo\\删除学生.png"),150,150);
	loadimage(&pic5, _T("photo\\导入学生.png"),150,150);
	loadimage(&pic6, _T("photo\\导出学生.png"),150,150);
	loadimage(&pic7, _T("photo\\返回.png"),140,70);
	putimage(0,0,&img);
	setlinecolor(BLUE);
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 3);
	line(200,269,360,269);
	line(420,269,580,269);
	line(640,269,800,269);
	line(389,80,389,240);
	line(389,300,389,460);
	line(609,80,609,240);
	line(609,300,609,460);
	while(1)
	{
		sclear->pDrawButton(sclear);
		sclearall->pDrawButton(sclearall);
		sadd->pDrawButton(sadd);
		sdelete->pDrawButton(sdelete);
		sinto->pDrawButton(sinto);
		sout->pDrawButton(sout);
		sback->pDrawButton(sback);
		putimage(205,85,&pic1);
		putimage(205,305,&pic2);
		putimage(425,85,&pic3);
		putimage(425,305,&pic4);
		putimage(645,85,&pic5);
		putimage(645,305,&pic6);
		putimage(805,505,&pic7);
		MOUSEMSG m=GetMouseMsg();
		if(sclear->pMouseInButton(sclear,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			TCHAR c1[]=_T("清空信息将不可逆，请输入密码来确定清空！！！");
			InputBox(clearstudents,100,c1,NULL,0,100,0,false);
			if(strlen(clearstudents)==0)
			{
				RECT r = {0, 500, 1000, 600};
				drawtext(_T("请输入密码！"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				FlushBatchDraw();
				EndBatchDraw();
				Sleep(1000);
				goto loop6;
			}
			if(strcmp(clearstudents,number2))
			{
				RECT r = {0, 500, 1000, 600};
				drawtext(_T("密码错误，请重新输入"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			}
			else
			{
				if ((fp = fopen(path1, "r")) == NULL)
				{
					RECT r = {0, 0, 600, 350};
					drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					Sleep(3000);
					exit(0);
				}
				int n=0;
				while(fscanf(fp,"%s",student[n].number)!=EOF&&fscanf(fp,"%s",student[n].name)!=EOF&&fscanf(fp,"%d",&student[n].ci)!=EOF
					&&fscanf(fp,"%d",&student[n].di)!=EOF&&fscanf(fp,"%d",&student[n].ii)!=EOF&&fscanf(fp,"%d",&student[n].II)!=EOF)
				{
					student[n].ci=60;
					student[n].di=0;
					student[n].ii=0;
					student[n].II=0;
					n++;
				}
				fclose(fp);
				if ((fp = fopen(path1, "w")) == NULL)
				{
					RECT r = {0, 0, 600, 350};
					drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					Sleep(3000);
					exit(0);
				}
				for(i=0;i<n;i++)
				{
					fprintf(fp,"%s\t",student[i].number);
					fprintf(fp,"%s\t",student[i].name);
					fprintf(fp,"%d\t",student[i].ci);
					fprintf(fp,"%d\t",student[i].di);
					fprintf(fp,"%d\t",student[i].ii);
					fprintf(fp,"%d\n",student[i].II);
				}
				fclose(fp);
				//RECT r = {0, 500, 1000, 600};
				//drawtext(_T("清空完成"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				setbkmode(TRANSPARENT);
				LOGFONT f,g;
				gettextstyle(&f);
				gettextstyle(&g);
				f.lfHeight =40;
				_tcscpy(f.lfFaceName,_T("黑体"));
				f.lfQuality =ANTIALIASED_QUALITY;
				settextcolor(RED);
				settextstyle(&f);
				RECT r = {0, 500, 1000, 600};
				drawtext(_T("重置完成"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				settextstyle(&g);
			}
			FlushBatchDraw();
			EndBatchDraw();
			Sleep(1000);
			Time();
			sprintf(messageout,"%s学生信息重置完成!\n",messagetime);
			cout<<messageout;
			markmessage();
			//closegraph();
			//cleardevice();
			goto loop6;
		}
		if(sclearall->pMouseInButton(sclearall,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			TCHAR c1[]=_T("清空信息将不可逆，请输入密码来确定清空！！！");
			InputBox(clearstudents,100,c1,NULL,0,100,0,false);
			if(strlen(clearstudents)==0)
			{
				RECT r = {0, 500, 1000, 600};
				drawtext(_T("请输入密码！"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				FlushBatchDraw();
				EndBatchDraw();
				Sleep(1000);
				goto loop6;
			}
			if(strcmp(clearstudents,number2))
			{
				RECT r = {0, 500, 1000, 600};
				drawtext(_T("密码错误，请重新输入"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			}
			else
			{
				if ((fp = fopen(path1, "w")) == NULL)
				{
					RECT r = {0, 0, 600, 350};
					drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					Sleep(3000);
					exit(0);
				}
				fclose(fp);
				//RECT r = {0, 500, 1000, 600};
				//drawtext(_T("清空完成"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				setbkmode(TRANSPARENT);
				LOGFONT f,g;
				gettextstyle(&f);
				gettextstyle(&g);
				f.lfHeight =40;
				_tcscpy(f.lfFaceName,_T("黑体"));
				f.lfQuality =ANTIALIASED_QUALITY;
				settextcolor(RED);
				settextstyle(&f);
				RECT r = {0, 500, 1000, 600};
				drawtext(_T("清空完成"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				settextstyle(&g);
			}
			FlushBatchDraw();
			EndBatchDraw();
			Sleep(1000);
			Time();
			sprintf(messageout,"%s学生信息清空完成!\n",messagetime);
			cout<<messageout;
			markmessage();
			//closegraph(); 
			//cleardevice();
			goto loop6;
		}
		if(sadd->pMouseInButton(sadd,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			TCHAR c1[]=_T("请输入学生姓名和学号(用&&来分割):");
			InputBox(addstudents,100,c1,NULL,0,100,0,true);
			if(strlen(addstudents)==0)
			{
				RECT r = {0, 500, 1000, 600};
				drawtext(_T("请输入学生姓名和学号"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				FlushBatchDraw();
				EndBatchDraw();
				Sleep(1000);
				goto loop6;
			}
			strtok(addstudents, "&");
			strcpy(number,strtok(NULL, "&"));
			if ((fp = fopen(path1, "a")) == NULL)
			{
				RECT r = {0, 0, 600, 350};
				drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				Sleep(3000);
				exit(0);
			}
			int one=0;int two=60;
			fprintf(fp,"%s\t",number);
			fprintf(fp,"%s\t",addstudents);
			fprintf(fp,"%d\t",two);
			fprintf(fp,"%d\t",one);
			fprintf(fp,"%d\t",one);
			fprintf(fp,"%d\n",one);
			fclose(fp);
			//RECT r = {0, 500, 1000, 600};
			//drawtext(_T("添加成功"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			setbkmode(TRANSPARENT);
			LOGFONT f,g;
			gettextstyle(&f);
			gettextstyle(&g);
			f.lfHeight =40;
			_tcscpy(f.lfFaceName,_T("黑体"));
			f.lfQuality =ANTIALIASED_QUALITY;
			settextcolor(RED);
			settextstyle(&f);
			RECT r = {0, 500, 1000, 600};
			drawtext(_T("添加完成"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			settextstyle(&g);
			FlushBatchDraw();
			EndBatchDraw();
			Sleep(1000);
			Time();
			sprintf(messageout,"%s成功添加学生'%s'&&学号'%s'\n",messagetime,addstudents,number);
			cout<<messageout;
			markmessage();
			//closegraph();
			//cleardevice();
			goto loop6;
		}
		if(sdelete->pMouseInButton(sdelete,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			i=0;
			TCHAR c1[]=_T("请输入要删除的学生:");
			InputBox(deletestudents,100,c1,NULL,0,100,0,true);
			if(strlen(deletestudents)==0)
			{
				RECT r = {0, 500, 1000, 600};
				drawtext(_T("请输入学生姓名！"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				FlushBatchDraw();
				EndBatchDraw();
				Sleep(1000);
				goto loop6;
			}
			if ((fp = fopen(path1, "r")) == NULL)
			{
				RECT r = {0, 0, 600, 350};
				drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				Sleep(3000);
				exit(0);
			}
			if ((fp2 = fopen(path2, "w")) == NULL)
			{
				RECT r = {0, 0, 600, 350};
				drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				Sleep(3000);
				exit(0);
			}
			while(fscanf(fp,"%s",student[i].number)!=EOF&&fscanf(fp,"%s",student[i].name)!=EOF&&fscanf(fp,"%d",&student[i].ci)!=EOF
				&&fscanf(fp,"%d",&student[i].di)!=EOF&&fscanf(fp,"%d",&student[i].ii)!=EOF&&fscanf(fp,"%d",&student[i].II)!=EOF)
			{
				if(strcmp(deletestudents,student[i].name))
				{
					fprintf(fp2,"%s\t",student[i].number);
					fprintf(fp2,"%s\t",student[i].name);
					fprintf(fp2,"%d\t",student[i].ci);
					fprintf(fp2,"%d\t",student[i].di);
					fprintf(fp2,"%d\t",student[i].ii);
					fprintf(fp2,"%d\n",student[i].II);
				}
				i++;
			}
			fclose(fp);
			fclose(fp2);
			rename(path1,path3);
			rename(path2,path1);
			rename(path3,path2);
			//RECT r = {0, 500, 1000, 600};
			//drawtext(_T("删除成功"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				setbkmode(TRANSPARENT);
				LOGFONT f,g;
				gettextstyle(&f);
				gettextstyle(&g);
				f.lfHeight =40;
				_tcscpy(f.lfFaceName,_T("黑体"));
				f.lfQuality =ANTIALIASED_QUALITY;
				settextcolor(RED);
				settextstyle(&f);
				RECT r = {0, 500, 1000, 600};
				drawtext(_T("删除完成"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				settextstyle(&g);
			FlushBatchDraw();
			EndBatchDraw();
			Sleep(1000);
			Time();
			sprintf(messageout,"%s成功删除学生'%s'\n",messagetime,deletestudents);
			cout<<messageout;
			markmessage();
			//closegraph();
			//cleardevice();
			goto loop6;
		}
		if(sinto->pMouseInButton(sinto,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			int next=0;
			music();
			//TCHAR c1[]=_T("请输入要导入学生名单的地址:");
			//InputBox(address,100,c1,NULL,0,100,0,false);
			system("ConsoleApplication3.exe");
			if ((fp3 = fopen("ConsoleApppathcache.dat", "r")) == NULL)
			{
				exit(0);
			}
			while(fscanf(fp3,"%s",address)!=EOF)
				if(strlen(address)==0)
				{
					RECT r = {0, 500, 1000, 600};
					drawtext(_T("请输入地址!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					FlushBatchDraw();
					EndBatchDraw();
					Sleep(1000);
					goto loop6;
				}
				if ((fp = fopen(address, "r")) == NULL)
				{
					//RECT r = {0, 300, 1000, 600};
					//drawtext(_T("访问不到地址名单，请重新输入！"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					FlushBatchDraw();
					EndBatchDraw();
					//Sleep(1000);
					goto loop6;
				}
				if ((fp2 = fopen(path1, "a")) == NULL)
				{
					RECT r = {0, 0, 600, 350};
					drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					Sleep(3000);
					exit(0);
				}
				while(fscanf(fp,"%s",student[i].number)!=EOF&&fscanf(fp,"%s",student[i].name)!=EOF&&fscanf(fp,"%d",&student[i].ci)!=EOF
					&&fscanf(fp,"%d",&student[i].di)!=EOF&&fscanf(fp,"%d",&student[i].ii)!=EOF&&fscanf(fp,"%d",&student[i].II)!=EOF)
				{
					fprintf(fp2,"%s\t",student[i].number);
					fprintf(fp2,"%s\t",student[i].name);
					fprintf(fp2,"%d\t",student[i].ci);
					fprintf(fp2,"%d\t",student[i].di);
					fprintf(fp2,"%d\t",student[i].ii);
					fprintf(fp2,"%d\n",student[i].II);
				}
				fclose(fp);
				fclose(fp2);
			//	RECT r = {0, 500, 1000, 600};
			//	drawtext(_T("导入成功！"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					setbkmode(TRANSPARENT);
				LOGFONT f,g;
				gettextstyle(&f);
				gettextstyle(&g);
				f.lfHeight =40;
				_tcscpy(f.lfFaceName,_T("黑体"));
				f.lfQuality =ANTIALIASED_QUALITY;
				settextcolor(RED);
				settextstyle(&f);
				RECT r = {0, 500, 1000, 600};
				drawtext(_T("导入成功"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				settextstyle(&g);
				FlushBatchDraw();
				EndBatchDraw();
				Time();
				sprintf(messageout,"%s学生名单导入成功，导入地址为'%s'\n",messagetime,address);
				cout<<messageout;
				markmessage();
				Sleep(1000);
				goto loop6;
		}
		if(sout->pMouseInButton(sout,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			char out[300]={0};
			char name[100]={0};
			strcpy(name,getenv("USERNAME"));
			sprintf(out,"C:\\Users\\%s\\Desktop\\随课名单.xls",name);
			if ((fp2 = fopen(out, "w+")) == NULL)
			{
				RECT r = {0, 500, 1000, 600};
				drawtext(_T("访问不到地址名单，请重新输入！"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				FlushBatchDraw();
				EndBatchDraw();
				Sleep(1000);
				goto loop6;
			}
			if ((fp = fopen(path1, "r")) == NULL)
			{
				RECT r = {0, 0, 600, 350};
				drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				Sleep(3000);
				exit(0);
			}
			fprintf(fp2,"学号\t");
			fprintf(fp2,"姓名\t");
			fprintf(fp2,"分数\t");
			fprintf(fp2,"提问次数\t");
			fprintf(fp2,"缺勤次数\t");
			fprintf(fp2,"考勤抽到次数\n");
			while(fscanf(fp,"%s",student[i].number)!=EOF&&fscanf(fp,"%s",student[i].name)!=EOF&&fscanf(fp,"%d",&student[i].ci)!=EOF
				&&fscanf(fp,"%d",&student[i].di)!=EOF&&fscanf(fp,"%d",&student[i].ii)!=EOF&&fscanf(fp,"%d",&student[i].II)!=EOF)
			{
				fprintf(fp2,"%s\t",student[i].number);
				fprintf(fp2,"%s\t",student[i].name);
				fprintf(fp2,"%d\t",student[i].ci);
				fprintf(fp2,"%d\t",student[i].di);
				fprintf(fp2,"%d\t",student[i].ii);
				fprintf(fp2,"%d\n",student[i].II);
			}
			fclose(fp);
			fclose(fp2);
			//RECT r = {0, 500, 1000, 600};
			//drawtext(_T("导出成功！"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				setbkmode(TRANSPARENT);
				LOGFONT f,g;
				gettextstyle(&f);
				gettextstyle(&g);
				f.lfHeight =40;
				_tcscpy(f.lfFaceName,_T("黑体"));
				f.lfQuality =ANTIALIASED_QUALITY;
				settextcolor(RED);
				settextstyle(&f);
				RECT r = {0, 500, 1000, 600};
				drawtext(_T("导出成功"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				settextstyle(&g);
			FlushBatchDraw();
			EndBatchDraw();
			Sleep(1000);
			Time();
			sprintf(messageout,"%s学生表'%s'的学生信息导出成功!\n",messagetime,Choice);
			cout<<messageout;
			markmessage();
			goto loop6;
		}
		if(sback->pMouseInButton(sback,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			music();
			break;
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
	//closegraph();
}                         
void Append(char c)
{	
	if (c != '\b')
	{
		if (m_textlen < 20)
		{
			text[m_textlen] = c;
			text[m_textlen + 1] = '\0';
			m_textlen++;
		}
	}
	else
	{
		if (m_textlen > 0)
		{
			m_textlen--;
			text[m_textlen] = '\0';
		}
	}
}
void Empty()
{
	m_textlen = 0;
	text[0] = '\0';
}
void Draw(int x1,int y1,int x2,int y2)
{
	static int fps = strlen(text);
	// 设置文字输出样式
	settextstyle(20, 0, "Verdana");
	// 画边框
	//	setlinecolor(WHITE);
	roundrect(x1, y1, x2, y2,10,10);
	// 输出用户输入的字符串
	if(out1)
		outtextxy(x1 + 30, y1 + (y2 - y1 - 20) / 2, " ");
	else
		outtextxy(x1 + 30, y1 + (y2 - y1 - 20) / 2, text);
	// 绘制光标
	fps++;
	if (fps < (m_fps / 4))
	{
		setlinecolor(BLACK);
		int sx = x1 + 31 + textwidth(text);
		line(sx, y1 + (y2 - y1 - 20) / 2, sx, y1 + (y2 - y1 - 20) / 2 + 20);
	}
	else if (fps > (m_fps / 2))
		fps = 0;
}
char Input()
{
	char c = 0;
	if (_kbhit())
	{
		c = getch();
	}
	return c;
}
void Out(int x1,int y1,int x2,int y2,char number[])
{
	char	key;					// 用户输入的英文
	memset(text,'\0',sizeof(text));
	m_textlen=0;
	strcpy(text,number);
	while (1)
	{
		HRGN rgn = CreateRectRgn(x1, y1, x2, y2);
		setcliprgn(rgn);
		key = Input();
		if(key=='\r')
		{
			strcpy(number,text);
			setcliprgn(NULL);
			break;
		}
		if (key != 0)
		{
			Append(key);
		}
		setbkcolor(WHITE);
		clearcliprgn();
		settextstyle(20, 0, "Verdana");
		setbkmode(TRANSPARENT);
		settextcolor(BLACK);
		Draw(x1, y1, x2, y2);
		FlushBatchDraw();
		Sleep(20);
	}
}
void tubiao()
{
	putimage(30,40,&t1);
	putimage(130,40,&t2);
	putimage(230,40,&t3);
	putimage(330,40,&t4);
	putimage(430,40,&t5);
	putimage(530,40,&t6);
}
void tubiaoshengming()
{
	loadimage(&t1, _T("photo\\test1.png"),60,75);
	loadimage(&t2, _T("photo\\test2.png"),60,75);
	loadimage(&t3, _T("photo\\test3.png"),60,75);
	loadimage(&t4, _T("photo\\test4.png"),60,75);
	loadimage(&t5, _T("photo\\test5.png"),60,75);
	loadimage(&t6, _T("photo\\test6.png"),60,75);
}
void Time()
{
	time_t rawtime;
	struct tm *ptminfo;
	time(&rawtime);
	ptminfo=localtime(&rawtime);
	sprintf(messagetime,"时间: %02d-%02d-%02d %02d:%02d:%02d\t",
		ptminfo->tm_year+1900,ptminfo->tm_mon+1,ptminfo->tm_mday,ptminfo->tm_hour,ptminfo->tm_min,ptminfo->tm_sec);
	//printf("时间: %02d-%02d-%02d %02d:%02d:%02d\t",
	//		ptminfo->tm_year+1900,ptminfo->tm_mon+1,ptminfo->tm_mday,ptminfo->tm_hour,ptminfo->tm_min,ptminfo->tm_sec);
}
void markmessage()
{
	FILE *fp;
	if ((fp = fopen("操作日志.txt", "a")) == NULL)
	{
		exit(0);
	} 
	fprintf(fp,"%s",messageout);
	fclose(fp);
}
