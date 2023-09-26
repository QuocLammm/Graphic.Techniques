#include <graphics.h>
#include <bits/stdc++.h>
int x=439,y=125, x1=440, yy=125, ll;
using namespace std;
void love()
{
int iloveyou[22]={x,y,x+22,y-15,x+44,y-27,x+88,y-12,x+102,y,x+117,y+22,x+125,y+44,x+125,y+47,x+120,y+66,x+105,y+88,x,y+220};
int iloveyou2[22]={x1,yy,x1-22,yy-15,x1-44,yy-27,x1-88,yy-12,x1-102,yy,x1-117,yy+22,x1-125,yy+44,x1-125,yy+47,x1-120,yy+66,x1-105,yy+88,x1,yy+220};
    setcolor(0); setfillstyle(1,0);
    fillpoly(11,iloveyou);
    fillpoly(11,iloveyou2);
    if(ll==0){x++; x1--;} else if(ll==1){x--; x1++;}
int ily[22]={x,y,x+22,y-15,x+44,y-27,x+88,y-12,x+102,y,x+117,y+22,x+125,y+44,x+125,y+47,x+120,y+66,x+105,y+88,x,y+220};
int ily2[22]={x1,yy,x1-22,yy-15,x1-44,yy-27,x1-88,yy-12,x1-102,yy,x1-117,yy+22,x1-125,yy+44,x1-125,yy+47,x1-120,yy+66,x1-105,yy+88,x1,yy+220};
    if(x==440)  {   setcolor(15); setfillstyle(1,15);}
    else{setcolor(12); setfillstyle(1,12);}
    fillpoly(11,ily);
    fillpoly(11,ily2);
}
void Loang(int x, int y)
{
    int mht=getpixel(x,y);
    if(mht==15)
    {
        putpixel(x,y,12);
        for(int i=0;i<200000;i++);
        Loang(x-1, y);
        Loang(x+1, y);
        Loang(x, y-1);
        Loang(x, y+1);
    }
}
void broken()
{
    setlinestyle(0,1,2); setcolor(15);
    int xx=440,yy=125,xx1=445,yy1=137,i=0;
    line(xx,yy,xx1,yy1);
    do{
        line(xx,yy,xx1,yy1);
        i++; 
        if(i%2==1)  {
            xx=445;xx1=440;
        }
        else{
            xx=440;xx1=445;
        }
        yy+=13;yy1+=13;
        delay(500);
    }while(yy1<357);
}

void boy()
{
    int d1x1=420,d1y1=500,d1x2=420,d1y2=500;
    int d2x1=460,d2y1=500,d2x2=460,d2y2=500;
    int j=0;
    for(int i=0;i<2;i++)
    {
        d1x1=420,d1y1=500,d1x2=420,d1y2=500;
        d2x1=460,d2y1=500,d2x2=460,d2y2=500;
        do
        {
            setcolor(0);
            line(d1x1,d1y1,d1x2,d1y2);
            line(d2x1,d2y1,d2x2,d2y2);
            if(i==0)
				setcolor(15);
            else 
				setcolor(12);
            	j++;
            	d1x2--;
				d1y2--; 
				d2x2++;
				d2y2--;
            if(j%9==0)
			{
				d1y2--; 
				d2y2--;
			} 
			
            line(d1x1,d1y1,d1x2,d1y2);
            line(d2x1,d2y1,d2x2,d2y2);
            if(j%2==0) 
				for(int i=0;i<1000;i++);
            if(i==0) 
				for(int j=0;j<100;j++);
            else  
				for(int j=0;j<3000000;j++);
        }while(d1x2>150);
    }
    int x1=440, y1=500;
    d1y1=550;
	d2y1=550;
    d1x1=420;  
	d2x1=460;
    do{
        //Day
        setcolor(0);
        line(d1x1,d1y1,d1x2,d1y2);
        line(d2x1,d2y1,d2x2,d2y2);
        d1y1--;;d2y1--;
        setcolor(12);setlinestyle(0,0,1); 
        line(d1x1,d1y1,d1x2,d1y2);
        line(d2x1,d2y1,d2x2,d2y2);
        //Boy
        setlinestyle(0,0,3); setcolor(0);
        line(x1,y1,x1,y1+100); circle(x1,y1-20,20); //Than va dau
        line(x1,y1+15,x1-20,y1+30); line(x1,y1+15,x1+20,y1+30);//2 tay
        line(x1-20,y1+30,x1-30,y1+50); line(x1+20,y1+30,x1+30,y1+50);
        y1--;
        setlinestyle(0,0,3); setcolor(6);
        line(x1,y1,x1,y1+100); circle(x1,y1-20,20); //Than va dau
        line(x1,y1+15,x1-20,y1+30); line(x1,y1+15,x1+20,y1+30);//2 tay
        line(x1-20,y1+30,x1-30,y1+50); line(x1+20,y1+30,x1+30,y1+50);
    }while(y1>150);
    int lan=0;
    delay(2000);
    do{
        ll=1;
        love();
        if(lan==0){
            setlinestyle(0,0,3);
			setcolor(0);line(x1-20,y1+30,x1-20,y1+50); 
			line(x1+20,y1+30,x1+20,y1+50);//xoa
            setlinestyle(0,0,3); 
			setcolor(6);line(x1-20,y1+30,x1-30,y1+50); 
			line(x1+20,y1+30,x1+30,y1+50);//init
            lan=1;
        }
        else{
            setlinestyle(0,0,3); 
			setcolor(0);line(x1-20,y1+30,x1-30,y1+50); 
			line(x1+20,y1+30,x1+30,y1+50);//xoa
            setlinestyle(0,0,3); setcolor(6);line(x1-20,y1+30,x1-20,y1+50); 
			line(x1+20,y1+30,x1+20,y1+50);//init
            lan=0;
        }
        delay(100);
    }while(x>550);
}
int main()
{
    initwindow(890,500);
    setcolor(10); settextstyle(6,0,1); outtextxy(580,460,"~~code by quoclemcute~~");
    love();
    Loang(440,300);
    delay(3000);
    broken();
    while(x1>150)
    {
        love();
        delay(1);
    }
    delay(2000);
    boy();
    setcolor(13); settextstyle(1,0,2);
    outtextxy(250,100,"Met roi!! deo keo nua!!");
getch();
}
