#include<stdio.h>
#include<graphics.h>
#include <graphics.h>
#include<math.h>
#include<stdio.h>
//ve duong thang di qua A(20,30) va B(120,80) :m<1 va xa<xb
void QL_TH1(int xa, int ya, int xb, int yb, int color){
	float m= (float)(yb-ya)/(xb-xa);
	int x;
	float y= ya;
	for(x=xa; x<=xb; x++){// x++ la vi m<1 va xa<xb
		y=y+m;
		printf("\n X= %d, Y=%.0f",x,round(y));
		putpixel(x,round(y),color);
		delay(10);
	}
	
}

//ve duong thang di qua A(120,80) va B(20,30) :m<1 va xa>xb
void QL_TH2(int xa, int ya, int xb, int yb, int color){
	float m= (float)(yb-ya)/(xb-xa);
	int x;
	float y= ya;
	for(x=xa; x>=xb; x--){// x++ la vi m<1 va xa<xb
		y=y-m;
		printf("\n X= %d, Y=%.0f",x,round(y));
		putpixel(x,round(y),color);
		delay(10);
	}
}

//ve duong thang di qua A(30,20) va B(80,120) :m>1 va xa<xb
void QL_TH3(int xa, int ya, int xb, int yb, int color){
	float m= (float)(yb-ya)/(xb-xa);
	int y;
	float x = xa;
	for(y=ya; y<=yb; y++){
		x=x+1/m;
		printf("\n X= %d, Y=%.0f",round(x),y);
		putpixel(round(x),y,color);
		delay(10);
	}
}


//ve duong thang di qua A(80,120) va B(30,20) :m>1 va xa>xb
void QL_TH4(int xa, int ya, int xb, int yb, int color){
	float m= (float)(yb-ya)/(xb-xa);
	int y;
	float x= xa;
	for(y=ya; y>=yb; y--){
		x=x-1/m;
		printf("\n X= %d, Y=%.0f",x,round(y));
		putpixel(x,round(y),color);
		delay(10);
	}
}

//ve duong thang di qua A(80,20) va B(30,120)
void QL_TH5(int xa, int ya, int xb, int yb, int color){
	float m= (float)(yb-ya)/(xb-xa);
	int x;
	float y= yb;
	for(x=xb; x<=xa; x++){// x++ la vi m<1 va xa<xb
		y=y+m;
		printf("\n X= %d, Y=%.0f",x,round(y));
		putpixel(x,round(y),color);
		delay(10);
	}
	
}

void QL_TH6(int xa, int ya, int xb, int yb, int color){
float m= (float)(yb-ya)/(xb-xa);
	int x;
	float y= yb;
	for(x=xb; x>=xa; x--){// x++ la vi m<1 va xa<xb
		y=y-m;
		printf("\n X= %d, Y=%.0f",x,round(y));
		putpixel(x,round(y),color);
		delay(10);
	}
}

void QL_TH7(int xa, int ya, int xb, int yb, int color){
	float m= (float)(yb-ya)/(xb-xa);
	int y;
	float x= xb;
	for(y=ya; y>=yb; y--){
		x=x-1/m;
		printf("\n X= %d, Y=%.0f",round(x),y);
		putpixel(round(x),y,color);
		delay(5);
	}
}

void QL_TH8(int xa, int ya, int xb, int yb, int color){
	float m= (float)(yb-ya)/(xb-xa);
	int y;
	float x = xb;
	for(y=ya; y<=yb; y++){
		x=x+1/m;
		printf("\n X= %d, Y=%.0f",round(x),y);
		putpixel(round(x),y,color);
		delay(10);
	}
}


int main()
{
	initwindow(400,400);
	QL_TH1(20,30,120,80,2);
	QL_TH2(120,80,20,30,4);
	QL_TH3(30,20,80,120,2);
	QL_TH4(80,120,30,20,4);
	QL_TH5(80,20,30,120,2);
	QL_TH6(30,120,80,20,4);
	QL_TH7(30,120,80,20,2);
	QL_TH8(80,20,30,120,4);
	getch();
}
