//choice.exe源代码

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
using namespace std;
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
char path[400]={0};
char path1[400]={0};
char number1[200]={0};
void drawButton(struct Button* pB);//画按钮函数
int mouseInButton(struct Button* pB,MOUSEMSG m);//鼠标敲击函数
struct classname
{
	char name[100];
}Classname[200];
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
int main(void)
{
	IMAGE img;
	char outname1[200]={0};
	char outname2[200]={0};
	char outname3[200]={0};
	char outname4[200]={0};
	char outname5[200]={0};
	int page=1;
	initgraph(300,450,EW_NOCLOSE|EW_NOMINIMIZE);
	setbkmode(TRANSPARENT);
loop4:
	int n=0;
	int print=100;
	char classout[200];
	char out[100]={0};
	FILE *fp;
	if ((fp = fopen("cache", "r")) == NULL)
	{
		exit(0);
	}
	fscanf(fp,"%s",number1);
	fclose(fp);
	sprintf(path,"C:\\skuser\\%s\\messages",number1);
	if ((fp = fopen(path, "r")) == NULL)
	{
		exit(0);
	}
	while(fscanf(fp,"%s",Classname[n].name)!=EOF)
	{
		n++;
	}
	fclose(fp);
	if(5*(page-1)<=n)
		strcpy(outname1,Classname[5*(page-1)].name);
	else
		strcpy(outname1," ");
	if(5*(page-1)+1<=n)
		strcpy(outname2,Classname[5*(page-1)+1].name);
	else
		strcpy(outname2," ");
	if(5*(page-1)+2<=n)
		strcpy(outname3,Classname[5*(page-1)+2].name);
	else
		strcpy(outname3," ");
	if(5*(page-1)+3<=n)
		strcpy(outname4,Classname[5*(page-1)+3].name);
	else
		strcpy(outname4," ");
	if(5*(page-1)+4<=n)
		strcpy(outname5,Classname[5*(page-1)+4].name);
	else
		strcpy(outname5," ");
	BeginBatchDraw();
	cleardevice();
	loadimage(&img, _T("photo\\选择背景.jpg"),300,450);
	putimage(0,0,&img);
	LOGFONT g;
	gettextstyle(&g);
	settextstyle(30,0, _T("Consolas"));
	settextcolor(RED);
	sprintf(out,"第%d页，共%d页",page,n/5+1);
	outtextxy(70,310,_T(out));
	settextcolor(BLACK);
	settextstyle(&g);
	struct Button* First=createButton(10,10,280,50,RGB(R3,G3,B3),RGB(R4,G4,B4),outname1,BLACK);
	struct Button* Second=createButton(10,70,280,50,RGB(R3,G3,B3),RGB(R4,G4,B4),outname2,BLACK);
	struct Button* Third=createButton(10,130,280,50,RGB(R3,G3,B3),RGB(R4,G4,B4),outname3,BLACK);
	struct Button* Fourth=createButton(10,190,280,50,RGB(R3,G3,B3),RGB(R4,G4,B4),outname4,BLACK);
	struct Button* Fifth=createButton(10,250,280,50,RGB(R3,G3,B3),RGB(R4,G4,B4),outname5,BLACK);
	struct Button* fbefore=createButton(5,400,65,40,RGB(R3,G3,B3),RGB(R1,G1,B1),"上一页",BLACK);
	struct Button* fafter=createButton(80,400,65,40,RGB(R3,G3,B3),RGB(R1,G1,B1),"下一页",BLACK);
	struct Button* ffirst=createButton(155,400,65,40,RGB(R3,G3,B3),RGB(R1,G1,B1),"首  页",BLACK);
	struct Button* fend=createButton(230,400,65,40,RGB(R3,G3,B3),RGB(R1,G1,B1),"尾  页",BLACK);
	while(true)
	{
		First->pDrawButton(First);
		Second->pDrawButton(Second);
		Third->pDrawButton(Third);
		Fourth->pDrawButton(Fourth);
		Fifth->pDrawButton(Fifth);
		fbefore->pDrawButton(fbefore);
		fafter->pDrawButton(fafter);
		ffirst->pDrawButton(ffirst);
		fend->pDrawButton(fend);
		MOUSEMSG m=GetMouseMsg();
		if(First->pMouseInButton(First,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			if ((fp = fopen("cache2", "w+")) == NULL)
			{
				exit(0);
			}
			fprintf(fp,"%s",outname1);
			fclose(fp);
			break;
		}
		if(Second->pMouseInButton(Second,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			if ((fp = fopen("cache2", "w+")) == NULL)
			{
				exit(0);
			}
			fprintf(fp,"%s",outname2);
			fclose(fp);
			break;
		}
		if(Third->pMouseInButton(Third,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			if ((fp = fopen("cache2", "w+")) == NULL)
			{
				exit(0);
			}
			fprintf(fp,"%s",outname3);
			fclose(fp);
			break;
		}
		if(Fourth->pMouseInButton(Fourth,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			if ((fp = fopen("cache2", "w+")) == NULL)
			{
				exit(0);
			}
			fprintf(fp,"%s",outname4);
			fclose(fp);
			break;
		}
		if(Fifth->pMouseInButton(Fifth,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			if ((fp = fopen("cache2", "w+")) == NULL)
			{
				exit(0);
			}
			fprintf(fp,"%s",outname5);
			fclose(fp);
			break;
		}
		if(fbefore->pMouseInButton(fbefore,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			page--;
			if(page<=0)
				page=1;
			goto loop4;
		}
		if(fafter->pMouseInButton(fafter,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			page++;
			if(page>=(n/5)+1)
				page=(n/5)+1;
			goto loop4;
		}
		if(ffirst->pMouseInButton(ffirst,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			page=1;
			goto loop4;
		}
		if(fend->pMouseInButton(fend,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			page=(n/5)+1;
			goto loop4;
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
	closegraph();
	exit(0);
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
void drawButton(struct Button* pB)//鼠标显示函数
{
	setfillcolor(pB->curColor);
	if(pB->curColor==pB->inColor)
	{
		setlinecolor(BLACK);
		setlinestyle(PS_SOLID,2);
		solidroundrect(pB->x,pB->y,pB->x+pB->width,pB->y+pB->height,10,10);
	}
	else
	{
		solidroundrect(pB->x,pB->y,pB->x+pB->width,pB->y+pB->height,10,10);
	}
	solidroundrect(pB->x,pB->y,pB->x + pB->width,pB->y+pB->height,10,10);
	int textWidth=textwidth(pB->text);
	int textHeight=textheight(pB->text);
	int x=pB->x+(pB->width-textWidth)/2;
	int y=pB->y+(pB->height-textHeight)/2;
	setbkmode(TRANSPARENT);//去文字beijing
	settextcolor(pB->textColor);
	outtextxy(x,y,pB->text);
}
