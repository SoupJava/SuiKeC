//land.exe源码


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<graphics.h>
#include<easyx.h>
#include<Windows.h>
#include<time.h>
#include<io.h>
#include<direct.h>
#include<conio.h>
using namespace std;
void drawButton(struct Button* pB);//画按钮函数
int mouseInButton(struct Button* pB,MOUSEMSG m);//鼠标敲击函数
FILE *number;
IMAGE img;
char	text[100]={0};					// 用户输入的字符串
int		m_textlen;					// 用户输入字符串的长度
int		m_fps=50;	// 每秒调用多少次（决定了光标闪烁速度）
bool out1=true;
int i;
char number1[200]={0};
char number2[200]={0};
char key[200]={0};
char path[400]={0};
char path1[400]={0};
char path2[400]={0};
char path3[400]={0};
char path4[400]={0};
float R1=244;//189,236,220
float G1=249;//215,207,231
float B1=252;//247,254,177
float R2=12;
float G2=138;
float B2=219;
float R3=97;
float G3=181;
float B3=230;
float R4=54;
float G4=198;
float B4=233;
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
		fillrectangle(pB->x,pB->y,pB->x+pB->width,pB->y+pB->height);
	}
	else
	{
		fillrectangle(pB->x,pB->y,pB->x+pB->width,pB->y+pB->height);
	}
	fillrectangle(pB->x,pB->y,pB->x + pB->width,pB->y+pB->height);
	int textWidth=textwidth(pB->text);
	int textHeight=textheight(pB->text);
	int x=pB->x+(pB->width-textWidth)/2;
	int y=pB->y+(pB->height-textHeight)/2;
	setbkmode(TRANSPARENT);//去文字beijing
	settextcolor(pB->textColor);
	outtextxy(x,y,pB->text);
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
void zhuce()
{
	out1=true;
	char newaccountnumber[100]={0};
	char newpasswordnumber[100]={0};
	char againpasswordnumber[100]={0};
	char outnumber2[100]={0};
	char outnumber3[100]={0};
loop2:
	FILE *fp;
	struct Button* newaccount=createButton(200,20,240,40,RGB(R1,G1,B1),RGB(R1,G1,B1),newaccountnumber,BLACK);
	struct Button* newpassword=createButton(200,80,240,40,RGB(R1,G1,B1),RGB(R1,G1,B1),outnumber2,BLACK);
	struct Button* againpassword=createButton(200,140,240,40,RGB(R1,G1,B1),RGB(R1,G1,B1),outnumber3,BLACK);
	struct Button* OK=createButton(175,230,150,60,RGB(R3,G3,B3),RGB(R4,G4,B4),"确  定",BLACK);
	struct Button* back=createButton(360,210,100,60,RGB(R3,G3,B3),RGB(R4,G4,B4),"返  回",BLACK);
	struct Button* out=createButton(70,190,85,20,RGB(R3,G3,B3),RGB(R4,G4,B4),"显示密码",BLACK);
	//initgraph(1000,600);
	BeginBatchDraw();
	//setbkcolor(WHITE);
	cleardevice();
	loadimage(&img, _T("photo\\load.jpg"),500,300); 

	putimage(0,0,&img);
	if(out1==1)
		setfillcolor(RGB(R1,G1,B1));
	else
		setfillcolor(RGB(R2,G2,B2));
	fillcircle(60,200,5);
	LOGFONT f;
	gettextstyle(&f);
	settextcolor(BLACK);
	settextstyle(30, 0, _T("Consolas"));
	outtextxy(40,20,"请输入账号:");
	outtextxy(40,80,"请输入密码:");
	outtextxy(40,140,"请确认密码:");
	settextstyle(&f);
	while(1)
	{
		newaccount->pDrawButton(newaccount);
		newpassword->pDrawButton(newpassword);
		againpassword->pDrawButton(againpassword);
		OK->pDrawButton(OK);
		back->pDrawButton(back);
		out->pDrawButton(out);
		MOUSEMSG m=GetMouseMsg();
		if(newaccount->pMouseInButton(newaccount,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			out1=false;
			Out(200,20,440,60,newaccountnumber); 
			out1=true;
			FlushBatchDraw();
			EndBatchDraw();
			//closegraph();
			cleardevice();
			goto loop2; 
		}
		if(newpassword->pMouseInButton(newpassword,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			Out(200,80,440,120,newpasswordnumber);
			if(out1)
			{
				for(i=0;i<strlen(newpasswordnumber);i++)
				{
					outnumber2[i]='*';
				}
			}
			else
				strcpy(outnumber2 ,newpasswordnumber);
			FlushBatchDraw();
			EndBatchDraw();
			//closegraph();
			cleardevice();
			goto loop2; 
		}
		if(againpassword->pMouseInButton(againpassword,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			Out(200,140,440,180,againpasswordnumber);
			if(out1)
			{
				for(i=0;i<strlen(againpasswordnumber);i++)
				{
					outnumber3[i]='*';
				}
			}
			else
				strcpy(outnumber3 ,againpasswordnumber);
			FlushBatchDraw();
			EndBatchDraw();
			//closegraph();
			cleardevice();
			goto loop2; 
		}
		if(out->pMouseInButton(out,m)&&m.uMsg==WM_LBUTTONDOWN)
		{ 
			//music();
			if(out1)
				out1=false;
			else
				out1=true;
			if(out1==false)
			{
				strcpy(outnumber2 ,newpasswordnumber);
				strcpy(outnumber3 ,againpasswordnumber);
			}
			else
			{
				for(i=0;i<strlen(newpasswordnumber);i++)
				{
					outnumber2[i]='*';
				}
				for(i=0;i<strlen(againpasswordnumber);i++)
				{
					outnumber3[i]='*';
				}
			}
			FlushBatchDraw();
			EndBatchDraw();
			//closegraph();
			cleardevice();
			goto loop2;
		}
		if(OK->pMouseInButton(OK,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			//music();
			sprintf(path,"C:\\skuser\\%s",newaccountnumber);
			sprintf(path1,"%s\\keys",path);
			sprintf(path2,"%s\\messages",path);
			sprintf(path3,"%s\\cache",path);
			sprintf(path4,"%s\\setting",path);
			FILE *fp;
			if(strlen(newaccountnumber)==0||strlen(newpasswordnumber)==0||strlen(againpasswordnumber)==0)
			{
				LOGFONT f;
				gettextstyle(&f);
				settextcolor(RED);
				settextstyle(20, 0, _T("Consolas"));
				RECT r = {0, 130, 500, 300};
				drawtext(_T("请输入账号或者密码！"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				settextstyle(&f);
				FlushBatchDraw();
				EndBatchDraw();
				Sleep(1000);
				goto loop2;
			}
			if ((fp = fopen(path1, "r")) != NULL)
			{
				LOGFONT f;
				gettextstyle(&f);
				settextcolor(RED);
				settextstyle(20, 0, _T("Consolas"));
				RECT r = {0, 130, 500, 300};
				drawtext(_T("账号已存在"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				settextstyle(&f);
				fclose(fp);
				FlushBatchDraw();
				EndBatchDraw();
				Sleep(1000);
				goto loop2;
			}
			if(newaccountnumber[0]=='0'&&newpasswordnumber[0]=='0'&&againpasswordnumber[0]=='0')
			{
				LOGFONT f;
				gettextstyle(&f);
				settextcolor(RED); 
				settextstyle(20, 0, _T("Consolas"));
				RECT r = {0, 130, 500, 300};
				drawtext(_T("请按照标准重新输入"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				settextstyle(&f);
				FlushBatchDraw();
				EndBatchDraw();
				Sleep(1000);
				// closegraph();
				//cleardevice();
				goto loop2;
			}
			if(strcmp(newpasswordnumber,againpasswordnumber))
			{
				LOGFONT f;
				gettextstyle(&f);
				settextcolor(RED);
				settextstyle(20, 0, _T("Consolas"));
				RECT r = {0, 130, 500, 300};
				drawtext(_T("两次密码不一致"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				settextstyle(&f);
			}
			else
			{
				_mkdir(path);
				if ((fp = fopen(path3, "w+")) == NULL)
				{
					RECT r = {0, 0, 600, 350};
					drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					_rmdir(path);
					Sleep(3000);
					exit(0);
				}
				fclose(fp);
				if ((fp = fopen(path2, "w+")) == NULL)
				{
					RECT r = {0, 0, 600, 350};
					drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					_rmdir(path);
					Sleep(3000);
					exit(0);
				}
				fclose(fp);
				if ((fp = fopen(path1, "w+")) == NULL)
				{
					RECT r = {0, 0, 600, 350};
					drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					_rmdir(path);
					Sleep(3000);
					exit(0);
				}
				for(i=0;i<strlen(againpasswordnumber);i++)
					fprintf(fp, "%c", againpasswordnumber[i]);
				fclose(fp);
				if ((fp = fopen(path4, "w+")) == NULL)
				{
					RECT r = {0, 0, 600, 350};
					drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					_rmdir(path);
					Sleep(3000);
					exit(0);
				}
				for(i=0;i<3;i++)
					fprintf(fp, "%d\n", 1);
				fclose(fp);
				LOGFONT f;
				gettextstyle(&f);
				settextcolor(RED);
				settextstyle(20, 0, _T("Consolas"));
				RECT r = {0, 130, 500, 300};
				drawtext(_T("创建成功！"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				settextstyle(&f);
			}
			FlushBatchDraw();
			EndBatchDraw();
			Sleep(1000);
			//closegraph();
			//cleardevice();
			goto loop2;
		}
		if(back->pMouseInButton(back,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			//music();
			break;
		}
		FlushBatchDraw();
	}EndBatchDraw();
}
void findnumber1()
{
loop3:
	char accountnumber[100]={0};
	char mima[100]={0};
	FILE *fp;
	struct Button* faccountnumber=createButton(130,30,240,40,RGB(R3,G3,B3),RGB(R4,G4,B4),"点  击  输  入  账  号",BLACK);
	struct Button* fOK=createButton(175,200,150,60,RGB(R3,G3,B3),RGB(R4,G4,B4),"查  询  密  码",BLACK);
	struct Button* fback=createButton(360,210,100,60,RGB(R3,G3,B3),RGB(R4,G4,B4),"返   回",BLACK);
	//initgraph(1000,600);
	BeginBatchDraw();
	//setbkcolor(WHITE);
	cleardevice();
	loadimage(&img, _T("photo\\load.jpg"),500,300); 
	putimage(0,0,&img);
	while(1)
	{
		faccountnumber->pDrawButton(faccountnumber);
		fOK->pDrawButton(fOK);
		fback->pDrawButton(fback);
		MOUSEMSG m=GetMouseMsg();
		if(faccountnumber->pMouseInButton(faccountnumber,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			//music();
			TCHAR c1[]=_T("请输入账号:");
			InputBox(accountnumber,100,c1,NULL,0,100,0,false);
		}
		if(fOK->pMouseInButton(fOK,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			//music();
			sprintf(path,"C:\\skuser\\%s",accountnumber);
			sprintf(path1,"%s\\keys",path);
			if(strlen(accountnumber)==0)
			{
				/*LOGFONT f;
				gettextstyle(&f);
				settextcolor(RED);
				settextstyle(30, 0, _T("Consolas"));
				RECT r={0,150,999,599};
				drawtext(_T("请输入您的账号"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				settextstyle(&f);
				FlushBatchDraw();
				EndBatchDraw();
				Sleep(1500);*/
				goto loop3;
			}
			if ((fp = fopen(path1, "r")) == NULL)
			{
				LOGFONT f;
				gettextstyle(&f);
				settextcolor(RED);
				settextstyle(30, 0, _T("Consolas"));
				RECT r={0,0,500,280};
				drawtext(_T("账号不存在"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				settextstyle(&f);
				FlushBatchDraw();
				EndBatchDraw();
				Sleep(1500);
				//closegraph();
				// cleardevice();
				goto loop3;
			}
			fscanf(fp, "%s",mima);
			LOGFONT f;
			RECT r={0,50,500,280};
			RECT t={0,0,500,280};
			gettextstyle(&f);
			settextcolor(RED);
			settextstyle(30, 0, _T("Consolas"));
			drawtext(_T("密码如下，请妥善保管"),&t,DT_CENTER | DT_VCENTER |DT_SINGLELINE);
			drawtext(_T(mima),&r,DT_CENTER | DT_VCENTER |DT_SINGLELINE);
			settextstyle(&f);
			FlushBatchDraw();
			EndBatchDraw();
			Sleep(4000);
			//closegraph();
			//cleardevice();
			goto loop3;
		}
		if(fback->pMouseInButton(fback,m)&&m.uMsg==WM_LBUTTONDOWN)
		{
			//music();
			break;
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
}
int main(void)
{
	IMAGE pic;
	initgraph(500,300,EW_NOCLOSE|EW_NOMINIMIZE);
	char outnumber2[200]={0};
	loop1:
	struct Button* account=createButton(145,20,270,40,RGB(R1,G1,B1),RGB(R1,G1,B1),number1,BLACK);
	struct Button* password=createButton(145,80,270,40,RGB(R1,G1,B1),RGB(R1,G1,B1),outnumber2,BLACK);
	struct Button* out=createButton(50,130,88,23,RGB(R3,G3,B3),RGB(R4,G4,B4),"显示密码",BLACK);
	struct Button* help=createButton(380,160,90,30,RGB(R3,G3,B3),RGB(R4,G4,B4),"问题解决",BLACK);
	struct Button* setpassword=createButton(380,200,90,30,RGB(R3,G3,B3),RGB(R4,G4,B4),"忘记密码",BLACK);
	struct Button* registered=createButton(380,240,90,30,RGB(R3,G3,B3),RGB(R4,G4,B4),"注册账号",BLACK);
	struct Button* sign=createButton(175,220,150,60,RGB(R3,G3,B3),RGB(R4,G4,B4),"登   录",BLACK);
	struct Button* exit1=createButton(480,0,20,20,RGB(R3,G3,B3),RGB(R4,G4,B4),"",BLACK);
	setbkmode(TRANSPARENT);
	cleardevice();
	loadimage(&img, _T("photo\\load.jpg"),500,300);
	loadimage(&pic, _T("photo\\关闭.png"),20,21);
	putimage(0,0,&img);
	LOGFONT f;
	gettextstyle(&f);
	settextcolor(BLACK);
	settextstyle(30, 0, _T("Consolas"));
	outtextxy(75,25,"账号");
	outtextxy(75,85,"密码");
	settextstyle(&f);
	LOGFONT n;
	gettextstyle(&n);
	n.lfHeight=22;
	_tcscpy(n.lfFaceName,_T("楷体"));
	n.lfQuality=ANTIALIASED_QUALITY;
	settextstyle(&n);
	if(out1==1)
		setfillcolor(RGB(R1,G1,B1)); 
	else
		setfillcolor(RGB(R2,G2,B2));
	fillcircle(40,140,5);
	while(1)
	{
		account->pDrawButton(account);
		password->pDrawButton(password);
		out->pDrawButton(out);
		help->pDrawButton(help); 
		setpassword->pDrawButton(setpassword);
		registered->pDrawButton(registered);
		sign->pDrawButton(sign);
		exit1->pDrawButton(exit1);
		putimage(480,0,&pic);
		MOUSEMSG n=GetMouseMsg();
		BeginBatchDraw();
		if(account->pMouseInButton(account,n)&&n.uMsg==WM_LBUTTONDOWN)
		{
			out1=false;
			Out(145,20,415,60,number1);
			out1=true;
			cleardevice();
			goto loop1; 
		}
		if(password->pMouseInButton(password,n)&&n.uMsg==WM_LBUTTONDOWN)
		{ 
			Out(145,80,415,120,number2);
			if(out1)
			{
				for(i=0;i<strlen(number2);i++)
				{
					outnumber2[i]='*';
				}
			}
			else
				strcpy(outnumber2 ,number2);
			cleardevice();
			goto loop1; 
		}
		if(out->pMouseInButton(out,n)&&n.uMsg==WM_LBUTTONDOWN)
		{ 
			if(out1)
				out1=false;
			else
				out1=true;
			if(out1==false)
			{
				strcpy(outnumber2 ,number2);
			}
			else
			{
				for(i=0;i<strlen(number2);i++)
				{
					outnumber2[i]='*';
				}
			}
			//FlushBatchDraw();
			//EndBatchDraw();
			//closegraph();
			cleardevice();
			goto loop1;
		}
		if(help->pMouseInButton(help,n)&&n.uMsg==WM_LBUTTONDOWN)
		{ 
			//music();
			int result=MessageBox(NULL,TEXT("QQ:3594039708 \n作者:TCG"),"寻求帮助",MB_ICONINFORMATION);
		}
		if(setpassword->pMouseInButton(setpassword,n)&&n.uMsg==WM_LBUTTONDOWN)
		{
			//music();
			findnumber1();
			//	FlushBatchDraw();
			//	EndBatchDraw();
			//closegraph();
			cleardevice();
			goto loop1;
		}
		if(registered->pMouseInButton(registered,n)&&n.uMsg==WM_LBUTTONDOWN)
		{
			//music();
			zhuce();
			//	FlushBatchDraw();
			//	EndBatchDraw();
			//closegraph();
			cleardevice();
			goto loop1;
		}
		if(sign->pMouseInButton(sign,n)&&n.uMsg==WM_LBUTTONDOWN)
		{
			//music();
			FILE *fp;
			sprintf(path,"C:\\skuser\\%s",number1);
			sprintf(path1,"%s\\keys",path);
			if ((fp = fopen(path1, "r")) == NULL)
			{
				LOGFONT f;
				gettextstyle(&f);
				settextcolor(RED);
				settextstyle(30, 0, _T("Consolas"));
				RECT r = {0, 20, 500, 300};
				drawtext(_T("账号不存在"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				settextstyle(&f);
				FlushBatchDraw();
				//   EndBatchDraw();
				Sleep(1500);
				//closegraph();
				cleardevice();
				goto loop1; 
			}
			if(strlen(number2)==0)
			{
				LOGFONT f;
				gettextstyle(&f);
				settextcolor(RED);
				settextstyle(30, 0, _T("Consolas"));
				RECT r = {0, 20, 500, 300};
				drawtext(_T("请输入密码"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				settextstyle(&f);
				FlushBatchDraw();
				//EndBatchDraw();
				Sleep(1000);
				//closegraph();
				cleardevice();
				goto loop1; 
			}
			for(i=0;i<strlen(number2);i++)
				fscanf(fp, "%c",&key[i]);
			if(strcmp(key,number2)!=0)
			{
				LOGFONT f;
				gettextstyle(&f);
				settextcolor(RED);
				settextstyle(30, 0, _T("Consolas"));
				RECT r = {0, 20, 500, 300};
				drawtext(_T("密码错误"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				settextstyle(&f);
				FlushBatchDraw();
				//EndBatchDraw();
				Sleep(1500);
				//closegraph();
				cleardevice();
				goto loop1;
			}
			else
			{
				fclose(fp);
				break;
			}
		}
		if(exit1->pMouseInButton(exit1,n)&&n.uMsg==WM_LBUTTONDOWN)
		{
			closegraph();
			exit(0);
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
	closegraph();
	if ((number = fopen("cache", "w+")) == NULL)
	{
		RECT r = {0, 0, 600, 350};
		drawtext(_T("名单读取失败,请退出!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		_rmdir(path);
		Sleep(3000);
		exit(0);
	}
	for(i=0;i<strlen(number1);i++)
		fprintf(number, "%c",number1[i]);
	fclose(number);
	exit(0);
	return 0;
}
