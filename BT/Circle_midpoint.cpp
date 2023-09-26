#include<winbgim.h>
#include<stdio.h>

void circle(int xc, int yc, int x, int y, int color){
	putpixel(xc+x, yc+y, color);
    putpixel(xc-x, yc+y, color);
    putpixel(xc+x, yc-y, color);
    putpixel(xc-x, yc-y, color);
    putpixel(xc+y, yc+x, color);
    putpixel(xc-y, yc-x, color);
    putpixel(xc+y, yc-x, color);
    putpixel(xc-y, yc+x, color);
}

void midpoint( int xc, int yc, int r){
	int x=0;
	int y=r;
	circle(xc, yc, x, y, 4);
	int p=1-r;
	while(x<y){
		if(p<0){
			p=p+2*x+3;
		}
		else{
			p=p+2*(x-y)+5;
			y--;
		}
		x++;
		circle(xc,yc,x,y,3);
		delay(5);
	}
}

int main(){
	initwindow(300,300);
	midpoint(100,100,50);
	getch();
}
