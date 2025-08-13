#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma region shuffle

void update_health(int size) 
{
	for (int i = 0; i < size; i++)
	{
		printf("♥");
	}
	printf("\n");
}

//void shuffle(int list[], int size)
//{
//   for (int i = 0; i < size; i++)
//   {
//       int seed = rand() % size; 
//       int temporary = list[seed];
//       list[seed] = list[i]; // Swap the elements
//       list[i] = temporary;
//   }
//}
//
//int main()
//{
#pragma region rand 함수
   // 0 ~32767 사이의 난수 값을 반환하는 함수입니다.

   // UTC 기준으로 1970년 1월 1일 0시 0분 초부터 경과된
   // 시간을 초(sec)로 반환하는 함수입니다.

   //srand(time(NULL)); // 현재 시간을 시드값으로 설정합니다.
   //srand(5); // 시드값을 설정합니다. 같은 시드값을 사용하면 같은 난수열이 생성됩니다.
   //int random = rand(); 

   //printf("랜덤값 %d\n", random);

   //int ramdom2 = rand() % 10;
   //printf("0 ~ 9 사이의 랜덤값 %d\n", ramdom2);
   //
   //int ramdom3 = rand() % 100 + 1;
   //printf("1 ~ 100 사이의 랜덤값 %d\n",ramdom3 );
#pragma endregion
#pragma region shuffle Function
   /*int list[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
   int size = sizeof(list) / sizeof(list[0]);

   shuffle(list, size);

   for (int i = 0; i < size; i++)
   {
       printf("list[%d],%d\n ", i, list[i]);
   }*/

#pragma endregion

   


#pragma region game

int main()
{
	int life = 5; 
	int computer_number, user_number;
	srand(time(NULL)); 
	computer_number = rand() % 50 + 1;
	printf("Up & Down 게임을 시작합니다! 1부터 100 사이의 숫자를 맞춰보세요.\n");
	printf("게임을 종료하려면 0을 입력하세요.\n");
	while (life > 0)
	{
		update_health(life);
		printf("숫자를 입력하세요");
		scanf_s("%d", &user_number);
		printf("\n");

		if (user_number == 0)
		{
			printf("게임을 종료합니다.\n");
			break;
		}
		if (user_number < computer_number)
		{
			life--;
			printf("더 큰 숫자를 입력하세요\n");
		}
		else if (user_number > computer_number)
		{
			life--;
			printf("더 작은 숫자를 입력하세요\n");
		}
		else
		{
			printf("정답입니다.%d\n", computer_number);
			break;
		}
	}
	if (life == 0)
	{
		printf(" Y O U L O S E !\n");
	}
	else
	{
		printf(" Y O U W I N \n");
	}

	return 0;
}


#pragma endregion

