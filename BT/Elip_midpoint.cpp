#include<stdio.h>
#include<math.h>
#include<winbgim.h>

void elip(int xc, int yc, int x,int y, int color){
	putpixel(xc+x, yc+y, color);
	putpixel(xc-x, yc+y, color);
	putpixel(xc+x, yc-y, color);
	putpixel(xc-x, yc-y, color);
}

// ve mien 1
void midpoint(int xc, int yc, int rx, int ry){
	int x=0;
	int y=ry;
	// ve mien 1
	
	float p1= round(ry*ry - rx*rx*ry +rx*rx/4);
	int px=0;
	int py=2*rx*rx*y;
	while(px<py){
		elip(xc, yc, x, y, 3);
		delay(5);
		px+= 2*ry*ry;
		x++;
		if(p1<0){
			p1=p1+ ry*ry+px;
		}
		else{
			y--;
			py  =py -2*rx*rx;
			p1  =p1 +ry*ry + px-py;
		}
	}
	// ve mien 2
	float p2=round(ry*ry*x*x + rx*rx*y*y - rx*rx*ry*ry);
	while(y>0){
		elip(xc, yc, x, y, 3);
		delay(5);
		py =py -2*rx*rx;
		y--;
		if(p2>0){
			p2 =p2+rx*rx- py;	
		}
		else{
			x++;
			px  =px+ 2*ry*ry;
			p2  =p2+ rx*rx - py+px;
		}
	}	
}

int main(){
	initwindow(300,300);
	midpoint(100,100,100,50); // x, y, wight, height;
	getch();
}


