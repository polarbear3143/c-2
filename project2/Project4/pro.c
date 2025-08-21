#include <stdio.h>
#include <windows.h> // Windows API �Լ��� ����ϱ� ���� �ֿ� ��� ����
#include <string.h>  // strlen �Լ��� ����ϱ� ���� ��� ����

// ���� ������ ��ũ�� ���ۿ� ���� �ε����� �����մϴ�.
int screen_index = 0;
HANDLE screen[2];

// ��ũ�� ���۸� �ʱ�ȭ�ϴ� �Լ��� �߰��߽��ϴ�.
void initialize()
{
    // �� ���� ���ο� �ܼ� ��ũ�� ���۸� �����մϴ�.
    screen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    screen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    // �ʱ� Ȱ�� ���۸� �����մϴ�.
    SetConsoleActiveScreenBuffer(screen[0]);
}

// Ȱ�� ��ũ�� ���۸� ��ȯ�ϰ� �ε����� ������Ʈ�ϴ� �Լ�
void flip()
{
    SetConsoleActiveScreenBuffer(screen[screen_index]);
    screen_index = !screen_index;
}

// ������ũ�� ���۸� ���� �Լ�
void clear()
{
    COORD position = { 0, 0 };
    DWORD dword;
    CONSOLE_SCREEN_BUFFER_INFO console;

    // ���� �������� ������ũ�� ������ ������ �����ɴϴ�.
    GetConsoleScreenBufferInfo(screen[screen_index], &console);

    // ���� ȭ�� ũ�⸦ ����մϴ�.
    int width = console.srWindow.Right - console.srWindow.Left + 1;
    int height = console.srWindow.Bottom - console.srWindow.Top + 1;

    // ���� ������ũ�� ���۸� �������� ä�� ����ϴ�.
    FillConsoleOutputCharacterA(screen[screen_index], ' ', width * height, position, &dword);
}

// ���ҽ��� �����ϴ� �Լ�
void release()
{
    CloseHandle(screen[0]);
    CloseHandle(screen[1]);
}

// ������ũ�� ���ۿ� �ؽ�Ʈ�� �׸��� �Լ�
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

        render(x++, y, "��");

        // �ʹ� ������ �������� �ʵ��� ��� ����ϴ�.
        Sleep(30);
    }

    release(); // ������ ���������� �� ���ҽ��� �����մϴ�.
    return 0;
}