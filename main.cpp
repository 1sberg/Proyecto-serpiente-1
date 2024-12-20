#include<windows.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
#define ESC 27

int cuerpo[200][2];
int n = 1;
int tan =4;
char tecla;
int x = 10,y=12;
int dir = 3;
int xc = 30, yc =15;
int velocidad = 100, h =1;
int score = 0;
void gotoxy(int x, int y)
{
    HANDLE hCon ;
    COORD dwPos ;
    dwPos . X = x;
    dwPos . Y = y;
    hCon = GetStdHandle ( STD_OUTPUT_HANDLE) ;
    SetConsoleCursorPosition (hCon , dwPos) ;
}
void pintar(){
    for(int i = 2 ; i < 78 ; i++){
    gotoxy(i,3); printf("%c", 205);
    gotoxy(i,23); printf("%c",205);
    }
    for(int i = 4 ; i < 23 ; i++){
    gotoxy(2,i); printf("%c",186) ;
    gotoxy(77,i); printf("%c", 186) ;
    }
    gotoxy(2,3); printf("%c",201);
    gotoxy(2,23); printf("%c",200);
    gotoxy(77,3); printf("%c",187);
    gotoxy(77,23); printf("%c",188);
}
void guardar_posicion(){
    cuerpo[n][0]=x;
    cuerpo[n][1]=y;
    n++;
    if(n == tan) n=1;
}
void dibujar_cuerpo()
{
    for(int i = 1; i < tan; i++){
        gotoxy(cuerpo[i][0], cuerpo[i][1]);printf("*");
    }
}
void borrar_cuerpo()
{
        gotoxy(cuerpo[n][0], cuerpo[n][1]);printf(" ");

}
void teclear(){
    if(kbhit()){
            tecla = getch();
            switch(tecla){
            case ARRIBA :
                if (dir != 2)
                    dir=1;
                    break;
            case ABAJO:
                if(dir != 1)
                    dir=2;
                    break;
            case DERECHA:
                if (dir !=4)
                    dir =3;
                    break;
            case IZQUIERDA:
                if (dir !=3)
                    dir=4;
                    break;
            }
        }
}
void cambiar_vel()
{
    if (score == h*20){
        velocidad -=10;
        h++;
    }
}
void comida()
{
    if(x == xc && y == yc){
        xc = (rand()%73)+4;
        yc = (rand()%19)+4;
        tan++;
        score +=10;
        gotoxy(xc,yc);printf("*");
        cambiar_vel();
    }
}
bool game_over(){
    if(y == 3 || y == 23 || x == 2 || x == 77) return false;
    for(int j = tan-1 ; j > 0 ; j--){
        if(cuerpo[j][0] == x && cuerpo[j][1] == y)
            return false;
    }
    return true;
}
void puntos()
{
    gotoxy(3,1);printf("score %d", score);
}

int main()
{
    pintar();
    gotoxy(xc,yc);printf("%c",4);
    while(tecla != ESC && game_over()){
        borrar_cuerpo();
        guardar_posicion();
        dibujar_cuerpo();
        teclear();
        puntos();
        teclear();
        comida();
        if (dir ==1) y--;
        if (dir ==2) y++;
        if (dir ==3) x++;
        if (dir ==4) x--;
        Sleep(velocidad);
    }
    pintar();
    system ("pause>null") ;
    return 0;
}
