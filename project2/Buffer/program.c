#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

void move(int x, int y)
{
	// x�� y���� �����ϴ� ����ü�Դϴ�.
	COORD position = { x, y };

	// �ܼ� Ŀ���� ��ǥ�� �����ϴ� �Լ��Դϴ�.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

int main()
{
	int x = 0;
	int y = 0;

	char key = 0;

	while (1)
	{
		if (_kbhit())
		{
			key = _getch();

			if (key == -32)
			{
				key = _getch();
			}

			switch (key)
			{
			case UP: y--;
				break;
			case LEFT:x -= 2;
				break;
			case RIGHT: x += 2;
				break;
			case DOWN:y++;
				break;
			default: printf("Exception");
				break;
			}

			system("cls");
		}

		move(x, y);

		printf("��");
	}

	return 0;
}