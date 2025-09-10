#include <stdio.h>   
#include<windows.h>
#include<conio.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

int Control();
void init();
void titleDraw();
void gotoxy(int, int);
int menuDraw();



int main() {
	init();
	titleDraw();
	menuDraw();
	int menuCode = menuDraw();
	printf("%d , 선택한 메뉴는 : %d\n 입니다 ", menuCode);

	return 0;

}

int Control() {
	char temp = getch();

	if (temp == 'w' || temp == 'W') {
		return UP;
	}
	else if (temp == 'a' || temp == 'A') {
		return LEFT;
	}
	else if (temp = 's ' || temp == 'S') {
		return DOWN;
	}
	else if (temp == 'd' || temp == 'D') {
		return RIGHT;
	}
	else if (temp == ' ') {
		return SUBMIT;
	}
}





void titleDraw()

{

	printf("\n\n\n\n");

	printf("        ####  ##### ##### ####  ####   ####  ####   \n");

	printf("        #   # #     #     #     #   #   #     #      \n");

	printf("        #   # ####  ####  ####  #   #  ####  ####   \n");

	printf("        #   # #     #     #     #   #     #  #      \n");

	printf("        ####  ##### #     ####  #   #  ####  ####   \n");

}

void init()

{

	system("mode con cols=56 lines=20 | title Defense Game");

}


int menuDraw() {
	int x = 24;
	int y = 12;
	gotoxy(x - 2, y);
	printf(" > 게임시작");
	gotoxy(x, y+1);
	printf(" 게임정보");
	gotoxy(x, y+2);
	printf(" 게임종료");
	while (1) {
		int n = Control();
		switch (n) {
		case UP: {
			if (y > 12) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
	
		case DOWN: {
			if(y < 14){
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
		}
			break;
	}
		case SUBMIT:{
			return y - 12;
			}
		}
	}
}




void gotoxy(int x, int y)

{

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD pos;

	pos.X = x;

	pos.Y = y;

	SetConsoleCursorPosition(consoleHandle, pos);





}

