#include<winbgim.h>
#include<stdio.h>
#include<math.h>
#define maxdinh 20
#define INPUT "scanline.inp"


// khai bao bien
int td[maxdinh][maxdinh];// toa do cac dinh cua da giac
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
	
	// them 1 dinh thu 4 = = dinh thu 0
	td[n][0]=td[0][0];//x[n] = x[0]
	td[n][1]=td[0][1];//y[n] = x[0]
	printf("\nToa do cac dinh cua da giac: \n");
	//in ra cac dinh cua da giac
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			printf("%10d",td[i][j]);
		}
	}
	fclose(fp);
}

void minmax(){
	ymin=td[0][1];// tung do dinh 0
	ymax=td[0][1];// tung do dinh 0
	for(int i=0; i<n;i++){
		if(ymin > td[i][1]){
			ymin=td[i][1];
		}
		if(ymax < td[i][1]){
			ymax= td[i][1];
		}
	}
	printf("\nYmin = %d",ymin);
	printf("\nYmax = %d\t",ymax);
}



void vedagiac(){
	for(int i=0;i<n;i++){// hang: so dinh
		for(int j=0; j<2;j++){// cot : toa do (x) (y)
			setcolor(12);//color
			setlinestyle(1,0,3);
			line(td[i][0], td[i][1], td[i+1][0], td[i+1][1]);
		}
	}
}

void hesogoc(){
	for(int i=0; i<n; i++){
		//m=dy/dx;
		m[i]=(float)(td[i+1][1] - td[i][1])/(td[i+1][0] - td[i][0]);// yi+1-yi / xi+1 - xi
		// co 2 truong hop dac biet: dy=0 ; dx=0
		//xsau=xtrc+ (y-ytrc)/m
		if(td[i+1][1] == td[i][1]){//dy=0
			m[i]=1;// m=0 nhung do cong thuc tim gd m nen phep chia bao loi(m#0)
		}
		if(td[i+1][0] == td[i][0]){//dx=0
			m[i]=999999999;// man hinh co phan giai 400x400 nen m=999999 nen uot qua sixe ma hinhf
		}
	}
	printf("\n He so goc cac canh cua da giac: ");
	for(int i=0; i<n; i++){
		printf("%5.1f", m[i]);
	}
	
}

void scanline(){
	int xgd[maxdinh];
	for(int y=ymin; y<=ymax; y++){
		//xet xem co giao diem hya khong co giao diem tung canh cua da giac
		int dem=0;// luu giu so diem cua moi y so voi cac canh cua da giac
		//moi lan tang dong quyet thi diem se lai ce 0 hay so giao diem =0
		for(int i=0; i<n; i++){// xet ting canh cua da giac
			if((y < td[i][1] && y < td[i+1][1]) || (y > td[i][1] && y > td[i+1][1])){// dong quyet nam duoi hoac tren ca 2 tung do dinh
				printf("\n Khong co hoanh do giao diem Y=%d voi canh (%d,%d) - (%d,%d)", y, td[i][0], td[i][1],  td[i+1][0], td[i+1][1]);
			}
			else{
				printf("\n Ton tai giao diem giua y voi canh cua da giac");
				//xac dinh hoanh do giao diem
				xgd[dem]=round(td[i][0] + (y - td[i][1])/ m[i]);
				dem++;
			}
		}
		//in ra cac xgd cua y voi cac canh cua da giac
		printf("\n Cac hoanh do gia diem cua y= %d voi cac canh cua da giac: ",y);
		for(int i=0; i<dem ; i++){
			printf("(%d,%d)    ",xgd[i],y);
		}
		//xap xep dinh cua hoanh ddoo
		for(int i=0;i< dem -1; i++){
			for(int j=i+1; j<dem; j++){
				if(xgd[i] > xgd[j]){
					int tam=xgd[i];
					xgd[i]=xgd[j];
					xgd[j]=tam;
				}
			}
		}
		// noi cac dinh cua hoanh do giao diem lai voi nha
		for(int i=0; i<dem-1; i=i+2 ){
			setcolor(12);
			line(xgd[i], y ,xgd[i+1],y);// vi cung y
			delay(100);
		}
	}
}	

int main(){
	NhapDinh();
	initwindow(400,400);
	hesogoc();
	minmax();
	vedagiac();
	scanline();
	getch();
}
