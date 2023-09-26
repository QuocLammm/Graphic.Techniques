#include<stdio.h>
#include<graphics.h>

void Brem1(int xa, int ya, int xb, int yb, int color){
	int dx=(xb-xa);
	int dy=(yb-ya);
	int Q=dx-2*dy;    //Q0
	int x=xa;// hoành do
	int y=ya;// tung do
	for(;x<=xb;x++){
		printf("x=%d, y=%d, Q=%d \n", x,y,Q);
		putpixel(x,y,color);
		if(Q<0){
			y++;
			Q=Q+2*dx-2*dy;
		}
		else{
			Q=Q-2*dy;
		}
		delay(10);
	}
}

void Brem2(int xa, int ya, int xb, int yb, int color){
	int dx=(xb-xa);
	int dy=(yb-ya);
	int Q=dx-2*dy;    //Q0
	int x=xa;// hoành do
	int y=ya;// tung do
	for(;x>=xb;x--){
		printf("x=%d, y=%d, Q=%d \n", x,y,Q);
		putpixel(x,y,color);
		if(Q<0){
			y--;
			Q=Q-2*dx+2*dy;
		}
		else{
			Q=Q+2*dy;
		}
		delay(10);
	}
}

void Brem3( int xa, int ya, int xb, int yb, int color){
	int dx=(xb-xa);
	int dy=(yb-ya);
	int Q=-dx-2*dy;    //Q0
	int x=xa;// hoành do
	int y=ya;// tung do
	for(;x<=xb;x++){
		printf("x=%d, y=%d, Q=%d \n", x,y,Q);
		putpixel(x,y,color);
		if(Q>0){
			y--;
			Q=Q-2*dx-2*dy;
		}
		else{
			Q=Q-2*dy;
		}
		delay(10);
	} 
	
}

void Brem4( int xa, int ya, int xb, int yb, int color){
	int dx=(xb-xa);
	int dy=(yb-ya);
	int Q=(-dx-2*dy);    //Q0
	int x=xa;// hoành do
	int y=ya;// tung do
	for(;x>=xb;x--){
		printf("x=%d, y=%d, Q=%d \n", x,y,Q);
		putpixel(x,y,color);
		if(Q>0){
			y++;
			Q=Q+2*dx+2*dy;
		}
		else{
			Q=Q+2*dy;
		}
		delay(10);
	} 
	
}

void Brem5( int xa, int ya, int xb, int yb, int color){
	int dx=(xb-xa);
	int dy=(yb-ya);
	int q=2*dx-dy;
	int x=xa;
	int y;
	for(y=ya;y<=yb;y++){
		printf("\n X=%d, Y=%d, Q=%d",x,y,q);
		putpixel(x,y,color);
		delay(5);
		if(q>0){
			x++;
			q=q+2*dx-2*dy;
		}
		else{
			q=q+2*dx;
		}
	}


}


void Brem6(int xa,int ya, int xb, int yb, int color){
	int dx=xb-xa;
	int dy=yb-ya;
	int q = -2*dx+dy;
	int x=xa;
	int y;
	for(y=ya;y>=yb;y--){
		printf("\nx = %d ,y = %d, Q = %d",x,y,q);
		putpixel(x,y,color);
		delay(100);
		if(q>0){
			x--; 
			q=q-2*dx+2*dy;
		}
		else{
			q=q-2*dx;
		}
	}
}
void Brem7(int xa,int ya, int xb, int yb, int color){
	int dx=xb-xa;
	int dy=yb-ya;
	int q = dx-2*dy;
	int x=xa;
	int y=ya;
	for(y=ya;y >=yb;y--){
		printf("\nx = %d ,y = %d, Q = %d",x,y,q);
		putpixel(x,y,color);
		delay(10);
		if(q>0){
			x++;
			q=q+2*dx+2*dy;
		}
		else{
			q=q+2*dx;
		}
	}
}
void Brem8(int xa,int ya, int xb, int yb, int color){
	int dx=xb-xa;
	int dy=yb-ya;
	int q = 2*dx+dy;
	int x=xa;
	int y;
	for(y=ya;y <=yb;y++){
		printf("\nx = %d ,y = %d, Q = %d",x,y,q);
		putpixel(x,y,color);
		delay(10);
		if(q>0){
			x--;
			q=q-2*dx-2*dy;
		}
		else{
			q=q-2*dx;
		}
	}
}



int main(){
	initwindow(200,200);
	//Brem1(20,30,120,80,2);
	//Brem2(120,80,20,30,4);
	//Brem3(20,80,120,30,7);
//	Brem4(120,30,20,80,9);
	//Brem5(30,20,80,120,3);
	//Brem6(80,120,30,20,5);
	//Brem7(30,120,80,20,8);
	//Brem8(80,20,30,120,10);
	getch();
	
}
