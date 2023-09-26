#include<stdio.h>
#include<graphics.h>
#include<limits.h>
// khai bao bien
int xwmin =100;
int xwmax = 300;
int ywmin = 100;
int ywmax= 300; 
int x0,y0,x1,y1;// toa do giao diem cua duong thang
int xgd, ygd;// luu tru giao diem hoanh do va tung do
float m;

void khoitaowindow(){
	setcolor(10);
	setlinestyle(1,1,2);// width =2 
	rectangle(xwmin , ywmax, xwmax, ywmin);
}

int mahoa(int x, int y){
	if(x>=xwmin && x<=xwmax && y>=ywmin && y<=ywmax){
		return 0;// 0000
	}
	if(x>=xwmin && x<=xwmax && y<ywmin ){
		return 4;// 0100
	}
	if(x>=xwmin && x<=xwmax && y>ywmax ){
		return 8;// 1000
	}
	if(x<xwmin && y>=ywmin && y<=ywmax){
		return 1;// 0001
	}
	if(x>xwmax && y>=ywmin && y<=ywmax){
		return 2;// 0010
	}
	if(x<xwmin && y<ywmin ){ // vua duoi vua trai
		return 5;// 0101
	}
	if(x<xwmin && y>ywmax ){ // vua tren vua trai
		return 9;// 1001
	}
	if(x>xwmax && y>ywmax ){ // vua duoi vua phai
		return 10;// 1010
	}
	if(x>xwmax && y<ywmin ){ // vua tren vua phai
		return 6;// 0110
	}
	
}

void findgd(int x, int y){// tim giao diem cua diem dang xet
	switch(mahoa(x,y)){
		case 0:{
			//\diem nam trong cua so cut
			xgd=x; 
			ygd=y;
			break;
		}
		case 2:{
			xgd=xwmax;
			ygd= y +(xgd -x)*m;
			break;
		}
		case 1:{
			xgd=xwmin;
			ygd= y +(xgd -x)*m;
			break;
		}
		case 4:{
			ygd=ywmin;
			xgd= x +(ygd - y)/m;
			break;
		}
		case 8:{
			ygd=ywmax;
			xgd= x +(ygd - y)/m;
			break;
		}
		case 5:{// B==L==1
			// Xet bit B=1
			ygd=ywmin;
			xgd= x +(ygd -y)/m;
			if(xgd <xwmin){
				// Xet bit L==1
				xgd=xwmin;
				ygd=y+(xgd-x)*m;
			}
			break;
		}
		case 6:{// B==R==1
			// Xet bit B=1
			ygd=ywmin;
			xgd= x +(ygd -y)/m;
			if(xgd > xwmax){
				// Xet bit R==1
				xgd=xwmax;
				ygd=y+(xgd-x)*m;
			}
			break;
		}
		case 9:{
			ygd=ywmax;
			xgd= x +(ygd -y)/m;
			if(xgd < xwmin){
				// Xet bit L==1
				xgd=xwmin;
				ygd=y+(xgd-x)*m;
			}
			break;
		}
		case 10:{//A==R==1
			ygd=ywmax;
			xgd= x +(ygd -y)/m;
			if(xgd > xwmax){
				// Xet bit R==1
				xgd=xwmax;
				ygd=y+(xgd-x)*m;
			}
			break;
		}
	}
}
void Cohen(int xa, int ya, int xb, int yb){
	// tim he so goc
	if(xa==xb){
		m=INT_MAX;
	}
	if(ya==yb){
		m=0;
	}
	else{ //xa!=xb va ya!=yb
		m=(float)(yb-ya)/(xb-xa);
	}
	printf("Doan thang di qua Xa=%d, Ya=%d, Xb=%d, Yb=%d",xa,ya,xb,yb);
	// ve doan thang noi 2 diem A va B
	setcolor(4);
	line(xa,ya,xb,yb);
	// in ket qua ma hoa
	printf("\n Ma hoa diem (A) = %d, Ma hoa diem (B) = %d",mahoa(xa,ya), mahoa(xb,yb));
	// lap luan tim giao diem
	if(mahoa(xa,ya) !=0 && mahoa(xb,yb) !=0 && (mahoa(xa,ya) & mahoa(xb,yb)) !=0){
		printf("\n Doan thang khong bi gioi han boi cua so cat");
		return;
	}
	// nguoc lai, doan thang có 1 hoac 2 giao diem
	findgd(xa,ya);
	x0=xgd;
	y0=ygd;
	findgd(xb,yb);
	x1=xgd;
	y1=ygd;
	// in ra man hinh 2 diem moi sau khi xen tia
	if(x0 < xwmin || y0 < ywmin || x0>xwmax || y0>ywmax || x1 < xwmin || y1 < ywmin || x1>xwmax || y1>ywmax){
		printf("\nDoan thang khong bi gioi han boi cua so cat");
	}
	else{
		setcolor(3);
		printf("\n Toa do X0= %d, Toa do Y0= %d, Toa do X1=%d, Toan do Y1=%d",x0,y0,x1,y1);
		line(x0,y0,x1,y1);
	}
}
int main(){
	initwindow(400,400); 
	khoitaowindow();
	//Cohen(50,150,50,250);
	//Cohen(150,150,250,250);
	//Cohen(150,150,350,250);// case 2
	//Cohen(150,50,250,350);// case 1
	//Cohen(200,140,200,70); //case 4
	// A trong B ngoai
	//Cohen(360,150,150,280);//
	//Cohen(150,450,150,140);//
	//Cohen(60,140,200,140);//
	//Cohen(200,70,200,140);//
	//Cohen(70,200,350,200);// A trai B phai
	//Cohen(200,40,200,360);// A tren B duoi
	//Cohen(70,200,240,400);// A trai B tren
	//Cohen(70,200,240,35);//A trai B duoi
	//Cohen(370,200,140,320);// A phai B tren
	//Cohen(370,200,160,400);// A phai B duoi
	// Case 5: A goc tren, trai + B ben trong
	Cohen(50,30,150,140);//B trong, A tren, trai
	Cohen(10,80,150,140);//B trong, A tren, trai
	
	//Case 6: A goc duoi, trai + B ben trong
	Cohen(80,430,150,140);//B trong, A duoi, trai
	Cohen(10,430,150,140);//B trong, A duoi, trai
	// Case 6: A goc duoi trai B trong
	Cohen(450,30,200,170);
	Cohen(330,10,200,170);
	// Case 9: A goc duoi, phai + B ben trong
	Cohen(450,430,200,170);//B trong, A duoi, phai
	Cohen(330,410,200,170);//B trong, A duoi, phai
	getch();
}
