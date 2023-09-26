#include<stdio.h>
#include<winbgim.h>
#include<math.h>
#define INPUT "phep1.inp"
#define maxdinh 20

// khai bao bien
int td[maxdinh][2];// toa do cac dinh cua da giac
// tung do cua da giac
int n; // so dinh cua da giac
FILE *fp;
float m[maxdinh];// he so goc cac canh
int ymin, ymax;


void NhapDinh(){
	fp=fopen(INPUT,"r");// mo tap tin de doc
	if(fp==NULL){
		printf("File not found");
	}
	fscanf(fp,"%d", &n);
	printf("So dinh cua da giac: %d",n);
	// doc cac dinh cua da giac
	for(int i=0; i<n;i++){
		for(int j=0; j<2;j++){
			fscanf(fp,"%d", &td[i][j]);
		}
	}
	
	printf("Toa do cac dinh cua da giac:");
	//in ra cac dinh cua da giac
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			printf("%10d",td[i][j]);
		printf("\n");
		}
	}
	fclose(fp);
}


void vedagiac(){
	// them 1 dinh thu 4 = = dinh thu 0
	td[n][0]=td[0][0];//x[n] = x[0]
	td[n][1]=td[0][1];//y[n] = x[0]
	for(int i=0;i<n;i++){// hang: so dinh
		for(int j=0; j<2;j++){// cot : toa do (x) (y)
			line(td[i][0], td[i][1], td[i+1][0], td[i+1][1]);
		}
	}
}

//pheo tinh tien
void tinhtien(int dx, int dy){
	//x' = x+dx; y'=y+dy
	for(int i=0; i<n; i++){
		td[i][0] +=dx;
		td[i][1] +=dy;
	}
	setcolor(5);//color
	setlinestyle(1,0,3);
	vedagiac();
}

// phep quay tam
void quaytam(int xr, int yr, float theta){
	//x'=xr +(x-xr)cos(theta) - (y-yr)sin(theta)
	//y'=xr +(x-xr)sin(theta) + (y-yr)cos(theta)
	//theta don vi g-radian: 0 - 3.1415
	int rad= theta*M_PI/180;
	for(int i=0; i<n; i++){
		int x = td[i][0];
		int y = td[i][1];
		td[i][0] = round(xr + (x - xr) * cos(rad)  - (y - yr) * sin(rad));
		td[i][1] = round(xr + (x - xr) * sin(rad)  + (y - yr) * cos(rad));
	}
	setcolor(5);//color
	setlinestyle(1,0,3);
	vedagiac();
}

// phep ti le
void tile(int Sx, int Sy){
	// x'= xr * Sx
	// y'= yr * Sy
	for(int i=0; i<n; i++){
		int x = td[i][0];
		int y = td[i][1];
		td[i][0] = x * Sx;
		td[i][1] = y * Sy;
	}
	setcolor(10);//color
	vedagiac();
}

// ti le khong dong dang theo truc X
void tileX(int shx){
	// x'= x + shx * y
	// y'= y 
	for(int i=0; i<n; i++){
		int x = td[i][0];
		int y = td[i][1];
		td[i][0] = x + shx * y;
		td[i][1] = y;
		delay(100);
	}
	setcolor(10);
	vedagiac();
}

//ti le khong dong dang theo truc Y
void tileY(int shy){
	// y'= y + shy * x
	// x'= x 
	for(int i=0; i<n; i++){
		int x = td[i][0];
		int y = td[i][1];
		td[i][0] = x;
		td[i][1] = y + shy * x;
		delay(100);
	}
	setcolor(10);
	vedagiac();
}

//phep lat theo truc X
void pheplatX(){
	for(int i=0; i<n; i++){
		int x = td[i][0];
		int y = td[i][1];
		td[i][0] = x;
		td[i][1] = -y ;
	}
	setcolor(10);
	vedagiac();
}
//phep lat theo truc Y
void pheplatY(){
	for(int i=0; i<n; i++){
		int x = td[i][0];
		int y = td[i][1];
		td[i][0] = -x;
		td[i][1] = y ;
	}
	setcolor(10);
	vedagiac();
}
int main(){
	NhapDinh();
	initwindow(800,800);
	vedagiac();
	tinhtien(50,25);
	for(int temp=0; temp<200; temp++){
		for(int goc=0; goc<180; goc++)
		quaytam(200,200,goc);
		tinhtien(temp,0);
		delay(100);
	}
//
//quay
//	for(int goc=0; goc<180; goc++){
//		quaytam(200,200,goc);
//		delay(100);
//	}
	//tile(3,3);
	//tileX(1);
	//tileY(1);
	//pheplatX();
	//pheplatY();
	getch();
}
