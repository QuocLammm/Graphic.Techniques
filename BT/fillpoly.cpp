#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
int main()
{ int driver=0, mode = 0, maloi;
initgraph(&driver,&mode,"C:/TC/BGI");
if ( (maloi=graphresult()) !=0 )
{
printf("khong the khoi dong do hoa \n");
printf("ma loi : %d \nTran Van Nhuom %s ",maloi, grapherrormsg(maloi) );
getch();
exit(1);
}
struct viewporttype p1,p2;
getviewsettings(&p1); // l?y thông tin v? c?a s? m?c d?nh khi kh?i d?ng d? ho?
setviewport(10,10,300,200,0); // t?o m?i m?t c?a s?
getviewsettings(&p2); // l?y thông tin c?a c?a s? v?a t?o m?i
closegraph();
printf("thong tin cua man hinh khi bat dau khoi dong do hoa\n");
printf("(%d,%d) la goc tren ben trai cua so \n",p1.left,p1.top);
printf("(%d,%d) la goc duoi ben phai cua so\n",p1.right,p1.bottom);
printf("thong so clip la %d",p1.clip);
printf("\n\n thong tin cua so moi duoc tao ra \n");
printf("(%d,%d) la goc tren ben trai cua so \n",p2.left,p2.top);
printf("(%d,%d) la goc duoi ben phai cua so\n",p2.right,p2.bottom);
printf("thong so clip la %d",p2.clip);
getch();
return 0;
}
