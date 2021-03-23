#define _CRT_SECURE_NO_WARNINGS
#include "iGraphics.h"
//#include "Block.h"
//#include "back2.h"
//#include "back3.h"
//#include<bits/stdc++.h>
//using namespace std;
struct hg_score
{
    char s[5][12];
    int x[5];
}user;
int indic=0;
double random,a,b,flag,x,t1,t2,theta,pi=3.1416,cx,cy,r,x_comp,y_comp,alpha,midax,l1,l2,l3,l4,beta,angle,targt_x,targt_y;
double success,chance,level,success_on_level2,success_on_level3,success_on_level1,acc_wind,wind_y,wind_x,time_proj;
int acv_hg_scr,length_name,input_mode,lvl2_movement,arrow_initialize=1,menu,win_lose,pause,timer_idx,target_hit,start_level2,start_level3,wind_drctn=1;//play_resume=0;
double wind_trngl_x[3],wind_trngl_y[3],rgb[3];
char show_name[12];
int frame;

char frames[110][20]={"0026.bmp","0027.bmp","0029.bmp","0030.bmp","0031.bmp","0032.bmp","0033.bmp","0034.bmp","0035.bmp","0036.bmp","0037.bmp","0038.bmp","0039.bmp","0040.bmp","0041.bmp","0042.bmp","0043.bmp","0044.bmp","0045.bmp","0046.bmp","0047.bmp","0048.bmp","0049.bmp","0050.bmp","0051.bmp","0052.bmp","0053.bmp","0054.bmp","0055.bmp","0056.bmp","0057.bmp","0058.bmp","0059.bmp","0060.bmp","0061.bmp","0062.bmp","0063.bmp","0064.bmp","0065.bmp","0066.bmp","0067.bmp","0068.bmp","0069.bmp","0070.bmp","0071.bmp","0072.bmp","0073.bmp","0074.bmp","0075.bmp","0076.bmp","0077.bmp","0078.bmp","0079.bmp","0080.bmp","0081.bmp","0082.bmp","0083.bmp","0084.bmp","0085.bmp","0086.bmp","0087.bmp","0088.bmp","0089.bmp","0090.bmp","0091.bmp","0092.bmp","0093.bmp","0094.bmp","0095.bmp","0096.bmp","0097.bmp","0098.bmp","0099.bmp","0100.bmp","0101.bmp","0102.bmp","0103.bmp","0104.bmp"};
void frame_change(void);
void line_change(void);
void lvl2(void);
void iXeonText(double leftX,double leftY,char ara[]);
void input_box(void);
//void lvl3(void);

void iDraw()
{
    iClear();
    char dis_score[]="SCORE: 0  CHANCES LEFT: 5";

    if(win_lose==1 )
    {
        if(level!=4)
            iShowBMP(0,0,"finvic.bmp");
        else
        {
            frame_change();
            iShowBMP(0,0,frames[frame]);
            iXeonText(150,300,"..THE CROWN IS YOURS..!");
        }
    }
    if(win_lose==4)
    {
        //enter your name! if high score.
        if(success>=user.x[4])
        {
            acv_hg_scr=1;
            iShowBMP(0,0,"name_inp.bmp");
            iSetColor(255, 187, 0);
            iXeonText(100,400,"CONGRATULATIONS ARCHER,");
            iXeonText(20,350,"YOU'VE ACHIEVED ONE OF THE HIGH SCORES!");
            input_box();
            if(input_mode)
            {
                iSetColor(6, 207, 146);
                iXeonText(210,210,show_name);
            }
            if(indic==0)
            {
                user.x[4]=success;
                indic++;
            }
            /*
            for(int i=3;i>=0;i--){
                int temp;
                if(user.x[i]>=success)
                    break;
                user.x[i+1]=user.x[i];
                user.x[i]=success;

            }*/
            //strcpy(user.s[4],show_name);
        }
        else
        {
            char s[4];
            itoa((int)success,s,10);

            iShowBMP(0,0,"game_over.bmp");
            iSetColor(255, 255, 255);

            iXeonText(170,320,"YOUR SCORE:");
            iXeonText(380,320,s);
            itoa(user.x[0],s,10);
            iXeonText(170,280,"HIGHEST SCORE: ");
            iXeonText(380,280,s);
        }
    }
    else if(win_lose==2)
    {
        iShowBMP(0,0,"lose.bmp");
        //no win_lose 0 value
    }
    else if(win_lose==3)
    {
        char s[3];
        s[0]=dis_score[7];
        s[1]=dis_score[8];
        s[3]='\0';

        iShowBMP(0,0,"game_over.bmp");
        iSetColor(0,255,255);

        iXeonText(220,310,"YOUR SCORE:");
        iXeonText(320,310,s);
        iXeonText(220,290,"HIGHEST SCORE: ");
    }
    if(menu==0)
    {
        iShowBMP(0,0,"Main_menu.bmp");
    }
    else if(menu==5)
    {
        FILE *fp;
        fp=fopen("score","wb");
        fwrite(&user,sizeof(struct hg_score),1,fp);
        fclose(fp);
        exit(0);
    }
    else if(menu==4)
    {
        iShowBMP(0,0,"aboutus.bmp");
    }
    else if(menu==2)
    {
        // how to play.
        iShowBMP(0,0,"HOWtoplay.bmp");
    }
    else if(menu==3)
    {
        //high score
        //sort(user.x,user.x+5,greater<int>())

        for(int i=0;i<4;i++)
        {
            int mx=user.x[i];
            int idx=i;
            char tmp[12];
            for(int j=i+1; j<5; j++)
            {
                if(user.x[j]>mx)
                {
                    mx=user.x[j];
                    idx=j;
                }
            }
            //printf("%d %d\n",user.x[idx],idx);
            user.x[idx]=user.x[i];
            user.x[i]=mx;

            strcpy(tmp,user.s[i]);
            strcpy(user.s[i],user.s[idx]);
            strcpy(user.s[idx],tmp);
        }
        FILE *fp;
        fp=fopen("score","wb");
        fwrite(&user,sizeof(struct hg_score), 1, fp);
        fclose(fp);
        //FILE *fp;
        fp=fopen("score","rb");
        fread(&user,sizeof(struct hg_score), 1, fp);
        fclose(fp);


        iShowBMP(0,0,"HAL.bmp");
        iSetColor(201, 16, 78);
        iXeonText(150,460,user.s[0]);
        iXeonText(150,420,user.s[1]);
        iXeonText(150,380,user.s[2]);
        iXeonText(150,340,user.s[3]);
        iXeonText(150,300,user.s[4]);
        //printf("%d ",user.x[0]);
        //printf("%d ",user.x[1]);
        char conversion[4];
        int t=user.x[0];
        itoa(t,conversion,10);
        iXeonText(350,460,conversion);
        t=user.x[1];
        itoa(t,conversion,10);
        iXeonText(350,420,conversion);
        t=user.x[2];
        itoa(t,conversion,10);
        iXeonText(350,380,conversion);
        t=user.x[3];
        itoa(t,conversion,10);
        iXeonText(350,340,conversion);
        t=user.x[4];
        itoa(t,conversion,10);
        iXeonText(350,300,conversion);

    }
    else if(menu==1 && pause==0)

    {
        // level wise level name and background
        if(level==1)
        {
            //iShowBMP(0,0,"lvl1.bmp");
            //draw_back(0,0);
            char lev_nm[]="Level: NOVICE";
            iSetColor(255, 255, 0);
            iText(30,40,lev_nm);
            iSetColor(240,240,240);
            iLine(490,510,570,510);
            iLine(530,470,530,550);
            iSetColor(255,255,0);
            iText(460,535,"..Wind..");
            iText(470,510,"N");
            iText(575,510,"S");
        }
        if(level==2)
        {
            //iShowBMP(0,0,"lvl2.bmp");
            //draw_back2(0,0);
            char lev_nm[]="Level: ROOKIE";
            iSetColor(255, 255, 0);
            iText(30,40,lev_nm);
            iSetColor(240,240,240);
            iLine(490,510,570,510);
            iLine(530,470,530,550);
            iSetColor(255,255,0);
            iText(460,535,"..Wind..");
            iText(480,510,"N");
            iText(575,510,"S");
        }
        if(level==3)
        {
            //iShowBMP(0,0,"lvl3.bmp");
            //draw_back3(0,0);
            char lev_nm[]="Level: LIEUTENANT";
            iSetColor(255,255,0);
            iText(30,40,lev_nm);
            iSetColor(240,240,240);
            iLine(490,510,570,510);
            iLine(530,470,530,550);
            iSetColor(255,255,0);
            iText(460,535,"..Wind..");
            iText(480,510,"N");
            iText(575,510,"S");
        }

        //Drawing the target

        if(start_level2)
        {
            iResumeTimer(1);
            //initializing level 2 movement;
        }

        if(level==3)
        {
            if(!wind_drctn)
            {
                // positive(x+)
                acc_wind=-4.9;
                wind_trngl_x[0]=550;
                wind_trngl_x[1]=550;
                wind_trngl_x[2]=560;
                wind_trngl_y[0]=518;
                wind_trngl_y[1]=502;
                wind_trngl_y[2]=510;
            }
            else
            {
                // negative(x-)
                acc_wind=4.0;
                wind_trngl_x[0]=510;
                wind_trngl_x[1]=510;
                wind_trngl_x[2]=500;
                wind_trngl_y[0]=518;
                wind_trngl_y[1]=502;
                wind_trngl_y[2]=510;
            }

            iSetColor(0,255,255);
            iFilledPolygon(wind_trngl_x,wind_trngl_y,3);
        }

        //Target
        iShowBMP(targt_x,targt_y,"target.bmp");

        //texts of point and chances and level
        int right_dig,left_dig;

        right_dig=(int)success%10;
        left_dig=((int)(success/10))%10;

        dis_score[7]=48+left_dig;
        dis_score[8]=48+right_dig;

        if(chance==5)
        {
            dis_score[24]='5';
        }
        if(chance==4)
        {
            dis_score[24]='4';
        }
        if(chance==3)
        {
            dis_score[24]='3';
        }
        if(chance==2)
        {
            dis_score[24]='2';
        }
        if(chance==1)
        {
            dis_score[24]='1';
        }

        iSetColor(255,255,0);
        iText(50,550,dis_score);

        //ends here itext

        iSetColor(250, 0, 0);
        iFilledCircle((x+100)/2, 220,30);//bow drawing circle
        if(level==1)
        {
            iSetColor(18, 18, 18);
        }
        if(level==2)
        {
            iSetColor(18,18,18);
        }
        if(level==3)
        {
            iSetColor(0,0,0);
        }
        iFilledCircle((x+100)/2, 220, 26);

        //bow hiding rectangle

        double recx[]= {100,20,20,x};
        double recy[]= {250,250,190,190};
        if(level==1)
        {
            iSetColor(0,0,0);
        }
        if(level==2)
        {
            iSetColor(0,0,0);
        }
        if(level==3)
        {
            iSetColor(0,0,0);
        }
        iFilledPolygon(recx,recy,4);

        if(x>100)
        {
            cx=((x+100)/2)+r*cos((pi/2)+theta);
            cy=(220)+r*sin((pi/2)+theta);
        }
        else
        {
            cx=((x+100)/2)-r*cos((pi/2)+theta);
            cy=(220)-r*sin((pi/2)+theta);
        }

        //Finished Drawn of triangle

        double tx[]= {((x+100)/2)+30*cos(theta),((x+100)/2)-30*cos(theta),cx};
        double ty[]= {220+30*sin(theta),220-30*sin(theta),cy};
        iSetColor(255,255,0);
        iPolygon(tx,ty,3);
        //rope triangle

        iSetColor(255,255,0);

        x_comp=atan((cy-220)/(cx-(x+100)/2));
        y_comp=atan((cy-220)/(cx-(x+100)/2));
        alpha=x_comp;

        //lpha=projecting angle

        if(flag==0)
            iLine(cx,cy,cx+35*cos(x_comp),cy+35*sin(y_comp));
        else if(level!=3)
        {
            a=tan(alpha);
            //y=ax+bx^2
            b=(0.5*9.8)/(5*r*r*cos(alpha)*cos(alpha));
            beta=atan(a-2*b*midax);
            //dy/dx
            l1=cx+17.5*cos(alpha)+midax-17.5*cos(beta);
            //(l1,l2),(l3,l4)-coordinates of arrow tail and head
            l2=cy+17.5*sin(alpha)+a*midax-b*midax*midax-17.5*sin(beta);
            l3=cx+17.5*cos(alpha)+midax+17.5*cos(beta);
            l4=cy+17.5*sin(alpha)+a*midax-b*midax*midax+17.5*sin(beta);

            //iSetColor(200,129,227);
            iLine(l1,l2,l3,l4);
            //line_change();

        }
        else if(level==3)
        {
            //Wind effect with acceleration
            wind_x=2.3*(-r)*cos(alpha)*time_proj-0.5*acc_wind*time_proj*time_proj;
            wind_y=2.3*(-r)*sin(alpha)*time_proj-0.5*9.8*time_proj*time_proj;

            beta=atan(wind_y/wind_x);

            l1=cx+17.5*cos(alpha)+wind_x-17.5*cos(beta);
            l2=cy+17.5*sin(alpha)+wind_y-17.5*sin(beta);
            l3=cx+17.5*cos(alpha)+wind_x+17.5*cos(beta);
            l4=cy+17.5*sin(alpha)+wind_y+17.5*sin(beta);

            iLine(l1,l2,l3,l4);
            //line_change();

        }

    }
}
void input_box(void)
{
    iXeonText(220,250,"Your Name:");
    iSetColor(155,150,150);
    iRectangle(200,200,200,30);

}
void iXeonText(double leftX,double leftY,char ara[])
{
    iText(leftX-0.5,leftY,ara,GLUT_BITMAP_TIMES_ROMAN_24);
    iText(leftX-0.5,leftY-0.5,ara,GLUT_BITMAP_TIMES_ROMAN_24);
    iText(leftX,leftY-0.5,ara,GLUT_BITMAP_TIMES_ROMAN_24);
    iText(leftX,leftY,ara,GLUT_BITMAP_TIMES_ROMAN_24);
}
void frame_change()
{
    frame++;
    if(frame>=68)
        frame=0;
}
void line_change()
{
    if(!(l3>=targt_x+48 && l3<=targt_x+53 && l4>=targt_y+43 && l4<=targt_y+87))
    {
        if(level!=3)
        {
            midax+=4.0;
        }
        else if(level==3)
        {
            time_proj+=0.05;
        }
        target_hit=0;
    }
    else
    {
        if(!target_hit)
        {
            iPauseTimer(1);
            target_hit=1;
            int k;
            if(level==1)
            {
                k=1;
            }
            else if(level==2)
            {
                k=2;
            }
            else if(level==3)
            {
                k=3;
            }
            if(l4>=targt_y+55 && l4<=targt_y+74)
            {
                success+=2*k;
            }
            else
            {
                success+=1*k;
            }
            if(level==1)
            {
                success_on_level1++;
            }
            if(level==2)
            {
                success_on_level2++;
            }
            if(level==3)
            {
                success_on_level3++;
            }
            start_level2=0;
        }

    }
}
void lvl2(void)
{
    if(targt_y<=280 && lvl2_movement==0)
    {
        if(level==3)
        {
            targt_y+=0.2;
        }
        else
        {
            targt_y+=0.2;
        }
        if(targt_y>280)
            lvl2_movement=1;
    }
    else if(targt_y>=120 && lvl2_movement==1)
    {
        if(level==3)
        {
            targt_y-=0.2;
        }
        else
        {
            targt_y-=0.2;
        }
        if(targt_y<160)
        {
            lvl2_movement=0;
        }
    }

}
/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
{
    //	printf("x = %d, y= %d\n",mx,my);
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/

void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if( mx>=414 && mx<=593 && my>=369 && my<=428 )
        {
            if(!menu)
            {
                menu=1;
                PlaySound((LPCSTR)"F:\\term project\\MyIGraphics\\Action Trailer - AShamaluevMusic(1).wav",NULL,SND_FILENAME|SND_ASYNC);
            }
            //start play
        }
        if( mx>=401 && mx<=578 && my>=282 && my<=335 )
        {
            if(!menu)
            {
                menu=2;
            }
            //how to play
        }
        if( mx>=392 && mx<=568 && my>=194 && my<=246 )
        {
            if(!menu)
            {
                menu=3;
            }
            // high score
        }
        if( mx>=383 && mx<=557 && my>=113 && my<=168 )
        {
            if(!menu)
            {
                menu=4;
            }
            //about us
        }
        if( mx>=372 && mx<=550 && my>=27 && my<=86)
        {
            if(!menu)
            {
                menu=5;
            }
            // exit
        }
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (win_lose == 1 && level!=4 )
        {
            if( mx>=113 && mx<=471 && my>=93 && my<=205 )
            {
                win_lose=0;
                pause=0;
                PlaySound((LPCSTR)"F:\\term project\\MyIGraphics\\Action Trailer - AShamaluevMusic(1).wav",NULL,SND_FILENAME|SND_ASYNC);
            }
        }
        if (win_lose == 2)
        {
            win_lose=3;
        }
        if(win_lose==1 && level==4)
        {
            win_lose=4;
        }
        if(win_lose==4 && acv_hg_scr)
        {
            if(mx>=200 && mx<=400 && my>=200 && my<=230)
            {
                input_mode=1;
            }
        }
    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{

    if(key=='w' && x<=200)
    {
        if(arrow_initialize)
        {
            x+=4;
            //theta+=0.05;
            theta=atan(60/(100-x));
        }
    }
    if(key=='s' && x>=10)
    {
        if(arrow_initialize)
        {
            x-=4;
            //theta-=0.05;
            theta=atan(60/(100-x));
        }
    }
    if(key =='a' && r>=-30  )
    {
        if(arrow_initialize )
        {
            r-=4;
        }
    }
    if(key=='d' && r<=30 && r<0)
    {
        if(arrow_initialize)
        {
            r+=4;
        }
    }
    if(key==' ')
    {
        if(menu!=0)
        {
            arrow_initialize=0;
            flag=1;
            iResumeTimer(0);
        }
    }
    if(key=='r' )
    {
        if(menu!=0)
        {
            iPauseTimer(0);
            if(level!=1)
            {
                iResumeTimer(1);
            }
            if(level==2 || level==3)
            {
                start_level2=1;
                if(level==3)
                {
                    int detr=rand();
                    if(detr%2==0)
                    {
                        wind_drctn=0;
                        //x(+)
                    }
                    else
                    {
                        wind_drctn=1;
                        // x(-)
                    }
                }
            }
            x=100;
            theta=angle;
            r=0;
            flag=0;
            midax=0;
            chance--;
            time_proj=0;
            arrow_initialize=1;
            if(!chance)
            {
                if(success_on_level1>=0.0 && level==1)
                {
                    level++;
                    success_on_level2=0;
                    chance=5;
                    win_lose=1;
                    PlaySound((LPCSTR)"F:\\term project\\MyIGraphics\\Energetic Sport - AShamaluevMusic.wav",NULL,SND_FILENAME|SND_ASYNC);
                }

                else if(success_on_level2>=0.0 && level==2)
                {
                    chance=5;
                    level++;
                    win_lose=1;
                    success_on_level3=0;
                    PlaySound((LPCSTR)"F:\\term project\\MyIGraphics\\Energetic Sport - AShamaluevMusic.wav",NULL,SND_FILENAME|SND_ASYNC);
                    //start_level2=0;
                }
                else if(success_on_level3>=0.0 && level==3)
                {
                    win_lose=1;
                    level++;
                    PlaySound((LPCSTR)"F:\\term project\\MyIGraphics\\Energetic Sport - AShamaluevMusic.wav",NULL,SND_FILENAME|SND_ASYNC);
                }

                else
                {
                    win_lose=2;
                    PlaySound((LPCSTR)"F:\\term project\\MyIGraphics\\Intense Blockbuster - AShamaluevMusic.wav",NULL,SND_FILENAME|SND_ASYNC);
                }
                pause=1;

            }
            //level choosing!
            if(level==1)
            {
                do
                {
                    random=rand();
                }
                while(random>=270 || random<=170);
                targt_y=random;
            }
            else if(level==2)
            {
                start_level2=1;
            }
            else if(level==3)
            {
                start_level3=1;
            }
        }
    }
    int j;
    if(input_mode)
    {
        if(key=='\r')
        {
            input_mode=0;
            show_name[length_name]='\0';
            strcpy(user.s[4],show_name);
            printf("%s\n",show_name);
            for(int i=0;i<length_name;i++)
            {
                show_name[i]='\0';
            }
            length_name=0;
            menu=0;
            acv_hg_scr=0;
        }
        else if(length_name<11)
        {
            show_name[length_name++]=key;
        }
    }
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{

    if (key == GLUT_KEY_END)
    {
        menu=0;
        x=100;
        theta=angle;
        r=0;
        flag=0;
        midax=0;
        chance=5;
        success=0.0;
        level=1;
        win_lose=0;
        pause=0;
        arrow_initialize=1;
        start_level2=0;
        indic=0;
    }
}


int main()
{
    x=100;
    t2=70;
    t1=(100+x)/2;
    r=0;
    midax=0;
    targt_x=400;
    targt_y=220;
    theta=atan(60/(100-x));//-(pi/2);//for changing the rope after pressing w,a,s,d
    angle=theta;
    success=0.0;
    chance=5;
    level=1;
    menu=0;
    win_lose=0;
    pause=0;
    lvl2_movement=0;
    success_on_level2=0;
    success_on_level3=0;
    success_on_level1=0;
    start_level2=0;
    start_level3=0;
    acc_wind=4.9;
    time_proj=0.0;
    frame=-1;
    input_mode=0;
    length_name=0;
    acv_hg_scr=0;

    FILE *fp;
    fp=fopen("score","rb");
    fread(&user,sizeof(struct hg_score), 1, fp);
    fclose(fp);
    //printf("%d\n%s",user.x[0],user.s[1]);
    //printf("%s",user[1].s);

    PlaySound((LPCSTR)"F:\\term project\\MyIGraphics\\led-zeppelin-kashmir.wav",NULL,SND_FILENAME|SND_ASYNC);

    iSetTimer(12,line_change);
    iPauseTimer(0);

    iSetTimer(10,lvl2);
    iPauseTimer(1);
    //load_back();
    //load_back2();
    //load_back3();
    iInitialize(600, 600, "archery");
    return 0;
}
