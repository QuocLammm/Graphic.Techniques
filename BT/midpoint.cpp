#include<stdio.h>
#include<winbgim.h>
//----------------0<m<1-----------------//
void P1(int xa, int ya, int xb, int yb, int color){
	int A=(yb-ya);
	int B=-(xb-xa);
	float M=(float)A+B/2;
	int x=xa;
	int y=ya;
	for(;x<=xb;x++){
		printf("X= %d, Y= %d, M=%.0f\n",x,y,M);
		putpixel(x,y,color);
		delay(5);
		if(M<0){
			M=M+A;
			y=y;
		}
		else{
			y++;
			M=M+A+B;
		}
	}
}
//----------------------0<m<1---(m=0,5)--------------------------------//
void P2(int xa, int ya, int xb, int yb, int color){
	int A=(yb-ya);
	int B=-(xb-xa);
	float M=-(float)A-B/2;
	int x=xa;
	int y=ya;
	for(;x>=xb;x--){
		printf("X= %d, Y= %d, M=%.0f\n",x,y,M);
		putpixel(x,y,color);
		delay(5);
		if(M<0){
			M=M-A;
			y--;
		}
		else{
			M=M-A-B;
			y=y;
		}
	}
}
//--------------------(-1<m<0) (Xa>Xb) (Ya<Yb)----------------//
void P3(int xa, int ya, int xb, int yb, int color){
	int A=(yb-ya);
	int B=-(xb-xa);
	float M=-(float)A+B/2;
	int x=xa;
	int y=ya;
	for(;x>=xb;x--){
		printf("X= %d, Y= %d, M=%.0f\n",x,y,M);
		putpixel(x,y,color);
		delay(5);
		if(M<0){
			y=y;
			M=M-A+B;
		}
		else{
			y++;
			M=M-A;
		}
	}
}
//
void P4(int xa, int ya, int xb, int yb, int color){
	int A=(yb-ya);
	int B=-(xb-xa);
	float M=(float)A-B/2;
	int x=xa;
	int y=ya;
	for(;x<=xb;x++){
		printf("X= %d, Y= %d, M=%.0f\n",x,y,M);
		putpixel(x,y,color);
		delay(5);
		if(M<0){
			y--;
			M=M+A-B;
		}
		else{
			M=M+A;
		}
	}
}
//-----------------------(m>1) (Xa>Xb) (Ya>Yb)---------------------//
void P6(int xa, int ya, int xb, int yb, int color){
	int A=(yb-ya);
	int B=-(xb-xa);
	float M=-(float)B-A/2;
	int x=xa;
	int y=ya;
	for(;y>=yb;y--){
		printf("X= %d, Y= %d, M=%.0f\n",x,y,M);
		putpixel(x,y,color);
		delay(5);
		if(M<0){
			x--;
			M=M-B-A;
		}
		else{
			M=M-B;
		}
	}
}
//-----------(m>1) (Xa<Xb) Ya<Yb)--------------//
void P5(int xa, int ya, int xb, int yb, int color){
	int A=(yb-ya);
	int B=-(xb-xa);
	float M=(float)B+A/2;
	int x=xa;
	int y=ya;
	for(;y<=yb;y++){
		printf("X= %d, Y= %d, M=%.0f\n",x,y,M);
		putpixel(x,y,color);
		delay(5);
		if(M<0){
			x++;
			M=M+B+A;
		}
		else{
			M=M+B;
		}
	}
}
//------------(m<-1) (Xa<Xb) (Ya>Yb)-------------//
void P8(int xa, int ya, int xb, int yb, int color){
	int A=(yb-ya);
	int B=-(xb-xa);
	float M=(float)B-A/2;
	int x=xa;
	int y=ya;
	for(;y>=yb;y--){
		printf("X= %d, Y= %d, M=%.0f\n",x,y,M);
		putpixel(x,y,color);
		delay(5);
		if(M<0){
			x++;
			M=M+B-A;
		}
		else{
			M=M+B;
		}
	}
}
//------------------------(m<-1)
void P7(int xa, int ya, int xb, int yb, int color){
	int A=(yb-ya);
	int B=-(xb-xa);
	float M=-(float)B+A/2;
	int x=xa;
	int y=ya;
	for(;y<=yb;y++){
		printf("X= %d, Y= %d, M=%.0f\n",x,y,M);
		putpixel(x,y,color);
		delay(5);
		if(M<0){
			x--;
			M=M-B+A;
		}
		else{
			M=M-B;
		}
	}
}
int main(){
	initwindow(400,400);
	P1(20,30,120,80,4);
	P2(120,80,20,30,5);
	P3(120,30,20,80,7);
	P4(20,80,120,30,6);
	P5(30,20,80,120,12);
	P6(80,120,30,20,9);
	P7(80,20,30,120,10);
	P8(30,120,80,20,15);
	getch();
}
