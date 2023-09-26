#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define maxdinh 20 // so dinh toi da
#define INPUT"chopcut.inp"
#define MATRANKE"chopcut.mtk"

int dinh[maxdinh][maxdinh];
int mtk[maxdinh][maxdinh];
// ma tran ket qua phep chieu xien
int Pnew[maxdinh][maxdinh];

int n;// so dinh
FILE *fp;
void printmt(int a[][maxdinh], int hang, int cot){
	for(int i=0; i<hang;i++){
		for(int j=0; j<cot;j++){
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}
}
void readfile(){
	// read file toa do dinh
	fp=fopen(INPUT,"r");
	if(fp==NULL){
		printf("File not found");
		return;
	}
	else{
		// doc so dinh da giac
		fscanf(fp,"%d",&n);
		printf("So dinh cua da giac: %d",n);
		// doc toa do cac dinh
		for(int i=0; i<n; i++){
			for(int j=0; j<3;j++){
				fscanf(fp,"%d",&dinh[i][j]);
			}
		}
		// hien thi noi fung
		printf("\nToa do cac dinh cua da giac:\n");
		printmt(dinh,n,3);
		fclose(fp);// dong tap tin
	}
	
}
// doc tap tin ma tran ke
void readfileMT(){
	fp=fopen(MATRANKE,"r");
	if(fp==NULL){
		printf("File not found");
		return;
	}
	else{
		// doc so dinh da giac
		fscanf(fp,"%d",&n);
		printf("So dinh cua da giac: %d",n);
		// doc toa do cac dinh
		for(int i=0; i<n; i++){
			for(int j=0; j<n;j++){
				fscanf(fp,"%d",&mtk[i][j]);
			}
		}
		// hien thi noi fung
		printf("\nMa tran ke cac dinh cua da giac:\n");
		printmt(mtk,n,n);
		fclose(fp);// dong tap tin
	}
}
void oxy(){
	setcolor(8);
	for(int i=0; i<n-1; i++){// cac dinh da giac
		for(int j=i+1; j<n;j++){//i+1 xet 2 dinh lien ke
			if(mtk[i][j] ==1){
				line(dinh[i][0], dinh[i][1], dinh[j][0], dinh[j][1]);// x0,y0 -> x1,y1.......
			}
		}
	}
}
void oxz(){
	setcolor(12);
	for(int i=0; i<n-1; i++){// cac dinh da giac
		for(int j=i+1; j<n;j++){//i+1 xet 2 dinh lien ke
			if(mtk[i][j] ==1){
				line(dinh[i][0], dinh[i][2], dinh[j][0], dinh[j][2]);// x0,y0 -> x1,y1.......
			}
		}
	}
}
void oyz(){
	setcolor(8);
	for(int i=0; i<n-1; i++){// cac dinh da giac
		for(int j=i+1; j<n;j++){//i+1 xet 2 dinh lien ke
			if(mtk[i][j] ==1){
				line(dinh[i][1], dinh[i][2], dinh[j][1], dinh[j][2]);// x0,y0 -> x1,y1.......
			}
		}
	}
}

void Chieuxien(float L, int theta){
	float T[3][3]= {{1,0,0}, {0,1,0}, {L*cos(theta*3.1416/180), L*sin(theta*3.1416/180)}};
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			Pnew[i][j]=0;
		}
	}
	// nhan ma tran
	for(int i=0; i<n;i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				Pnew[i][j]= round(Pnew[i][j] + dinh[i][k] * T[k][j]);
			}
		}
	}
	// in ma tran
	printf("\n Ma tran Pnew:");
	printmt(Pnew,n,12);
	setcolor(10);
	for(int i=0; i<n-1; i++){
		for(int j=i-1; j<n;j++){
			if(mtk[i][j]==1){
				line(Pnew[i][0], Pnew[i][1], Pnew[j][0], Pnew[j][1]);
				ntuedu;
				
			}
		}
	}
}

int main(){
	initwindow(600,600);
	readfile();
	readfileMT();
	//oxy();
	//oxz();
	//oyz();
	char buffer[10];
	for(int i=0; i<100;i++){
		sprintf(buffer, "%d",i);
		settextstyle(DEFAULT_FONT, HORIZ_DIR,2);
		outtextxy(0,0,buffer);
		Chieuxien(0.5,i);
		delay(300);
		cleardevice();
	}
	getch();
}
