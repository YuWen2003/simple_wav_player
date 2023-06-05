#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>

void printMenu() {
    printf("歡迎使用簡易播放程式!!!\n");
    printf("目前有 <1>試聽 <2>離開\n");
    printf("請選擇：");
}

void printSongList() {
    printf("顯示目前有的歌曲!!!如下\n");
    printf("1. haunted.wav\n");
    printf("2. blacksky.wav\n");
    printf("3. rainielove.wav\n");
    printf("請選擇：");
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
                printf("無效的選擇\n");
                return 0;
        }

        printf("聆聽時間 - <1>試聽秒數 <2>任意\n");
        printf("請選擇：");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("請輸入秒數：");
            scanf("%d", &duration);

            printf("播放 %d 秒後停止!!!\n", duration);
            playSong(filename);
            Sleep(duration * 1000);
            stopSong();
            printf("時間到囉!!!歡迎繼續使用!!!");
        } else if (choice == 2) {
            printf("按任意鍵停止播放\n");
            playSong(filename);
            waitForKeypress();
            stopSong();
        } else {
            printf("無效的選擇\n");
            return 0;
        }
    } else if (choice == 2) {
        printf("結束\n");
    } else {
        printf("無效的選擇\n");
    }

    return 0;
}

/*THIS CODE IS MY OWN WORK. IT WAS WRITTEN WITHOUT CONSULTING CODE WRITTEN BY OTHER STUDENTS OR ANY ONE WHO IS NOT AWARE OF MY REFERENCE. 410125034 陳俞妏*/
