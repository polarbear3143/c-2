#include <stdio.h>
#include <windows.h> // Windows API 함수를 사용하기 위한 주요 헤더 파일
#include <string.h>  // strlen 함수를 사용하기 위한 헤더 파일

// 전역 변수로 스크린 버퍼와 현재 인덱스를 선언합니다.
int screen_index = 0;
HANDLE screen[2];

// 스크린 버퍼를 초기화하는 함수를 추가했습니다.
void initialize()
{
    // 두 개의 새로운 콘솔 스크린 버퍼를 생성합니다.
    screen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    screen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    // 초기 활성 버퍼를 설정합니다.
    SetConsoleActiveScreenBuffer(screen[0]);
}

// 활성 스크린 버퍼를 전환하고 인덱스를 업데이트하는 함수
void flip()
{
    SetConsoleActiveScreenBuffer(screen[screen_index]);
    screen_index = !screen_index;
}

// 오프스크린 버퍼를 비우는 함수
void clear()
{
    COORD position = { 0, 0 };
    DWORD dword;
    CONSOLE_SCREEN_BUFFER_INFO console;

    // 현재 렌더링할 오프스크린 버퍼의 정보를 가져옵니다.
    GetConsoleScreenBufferInfo(screen[screen_index], &console);

    // 현재 화면 크기를 계산합니다.
    int width = console.srWindow.Right - console.srWindow.Left + 1;
    int height = console.srWindow.Bottom - console.srWindow.Top + 1;

    // 현재 오프스크린 버퍼를 공백으로 채워 지웁니다.
    FillConsoleOutputCharacterA(screen[screen_index], ' ', width * height, position, &dword);
}

// 리소스를 해제하는 함수
void release()
{
    CloseHandle(screen[0]);
    CloseHandle(screen[1]);
}

// 오프스크린 버퍼에 텍스트를 그리는 함수
void render(int x, int y, const char* text)
{
    DWORD dword;
    COORD position = { (SHORT)x, (SHORT)y };

    SetConsoleCursorPosition(screen[screen_index], position);
    WriteFile(screen[screen_index], text, strlen(text), &dword, NULL);
}

int main()
{
    int x = 0;
    int y = 0;

    initialize();

    while (1)
    {
        flip();
        clear();

        render(x++, y, "★");

        // 너무 빠르게 움직이지 않도록 잠시 멈춥니다.
        Sleep(30);
    }

    release(); // 루프를 빠져나왔을 때 리소스를 해제합니다.
    return 0;
}