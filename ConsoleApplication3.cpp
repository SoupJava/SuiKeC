//ConsoleApplication3.exe源码
#include<iostream>
#include<Windows.h>
#include<commdlg.h>
#include<string>
#include<stdlib.h>
using namespace std;
string TCHAR2STRING(TCHAR* str){
	std::string strstr;
	try
	{
		int iLen = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);

		char* chRtn = new char[iLen * sizeof(char)];

		WideCharToMultiByte(CP_ACP, 0, str, -1, chRtn, iLen, NULL, NULL);

		strstr = chRtn;
	}
	catch (exception e)
	{
	}

	return strstr;
}
int main(){
	bool control=true;
	FILE *fp;
	int n=0;
	int m=0;
	int t=0;
	char path[100];
	char pathnow[100];
	OPENFILENAME ofn = { 0 };
	TCHAR strFileName[MAX_PATH] = { 0 };
	ofn.lStructSize = sizeof(OPENFILENAME);	
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = TEXT("All\0*.*\0jpg\0*.jpg\0bmp\0*.bmp\0\0");	
	ofn.nFilterIndex = 1;	
	ofn.lpstrFile = strFileName;
	ofn.nMaxFile = sizeof(strFileName);
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrTitle = TEXT("请选择一个文件");
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY; 
	if (GetOpenFileName(&ofn)){
		string filePath = TCHAR2STRING(strFileName);
		int start = filePath.find_last_of('\\');
		int end = filePath.find_last_of('.');
		string fileName = filePath.substr(start + 1, end - start - 1);
		string exten = filePath.substr(end, filePath.length() - end);
		n=filePath.length();
		filePath.copy(path,n,0);
	}
	else
	{
		control=false;
	}
	for(t=0;;t++)
	{
		if(_pgmptr[t]=='\0')
			break;
	}
	for(int y=0;y<t-13;y++)
	{
		pathnow[y]=_pgmptr[y];
	}
	sprintf(pathnow,"%s\pathcache.dat",pathnow);
	if(control)
	{
		if ((fp = fopen(pathnow, "w+")) == NULL)
		{
			exit(0);
		}
		for(int i=0;i<n;i++)
		{
			fprintf(fp,"%c",path[i]);
		}
		fclose(fp);
	}
	else
	{
		if ((fp = fopen(pathnow, "w+")) == NULL)
		{
			exit(0);
		}
		fprintf(fp,"%d",0);
		fclose(fp);
	}
	return 0;
}
