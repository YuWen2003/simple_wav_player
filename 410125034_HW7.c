#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>

void printMenu() {
    printf("�w��ϥ�²������{��!!!\n");
    printf("�ثe�� <1>��ť <2>���}\n");
    printf("�п�ܡG");
}

void printSongList() {
    printf("��ܥثe�����q��!!!�p�U\n");
    printf("1. haunted.wav\n");
    printf("2. blacksky.wav\n");
    printf("3. rainielove.wav\n");
    printf("�п�ܡG");
}

void playSong(const char* filename) {
    PlaySound(filename, NULL, SND_FILENAME | SND_ASYNC);
}

void stopSong() {
    PlaySound(NULL, NULL, SND_ASYNC);
}

void waitForKeypress() {
    while (!kbhit()) {
        Sleep(100);
    }
    getch();
}

int main() {
    int choice;
    char filename[20];
    int duration;

    printMenu();
    scanf("%d", &choice);

    if (choice == 1) {
        printSongList();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                strcpy(filename, "haunted.wav");
                break;
            case 2:
                strcpy(filename, "blacksky.wav");
                break;
            case 3:
                strcpy(filename, "rainielove.wav");
                break;
            default:
                printf("�L�Ī����\n");
                return 0;
        }

        printf("��ť�ɶ� - <1>��ť��� <2>���N\n");
        printf("�п�ܡG");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("�п�J��ơG");
            scanf("%d", &duration);

            printf("���� %d ��ᰱ��!!!\n", duration);
            playSong(filename);
            Sleep(duration * 1000);
            stopSong();
            printf("�ɶ����o!!!�w���~��ϥ�!!!");
        } else if (choice == 2) {
            printf("�����N�䰱���\n");
            playSong(filename);
            waitForKeypress();
            stopSong();
        } else {
            printf("�L�Ī����\n");
            return 0;
        }
    } else if (choice == 2) {
        printf("����\n");
    } else {
        printf("�L�Ī����\n");
    }

    return 0;
}

/*THIS CODE IS MY OWN WORK. IT WAS WRITTEN WITHOUT CONSULTING CODE WRITTEN BY OTHER STUDENTS OR ANY ONE WHO IS NOT AWARE OF MY REFERENCE. 410125034 ���\ʹ*/
