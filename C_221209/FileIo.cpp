#include "FileIo.h"
#include <stdio.h>
#include <string>

const char FileIo::filename[] = "Test.txt";

void FileIo::Load()
{
    FILE* file = NULL;

    fopen_s(&file, filename, "r");
    if (!file) {
        printf("파일 열기 실패\n");
        return;
    }

    Weapon weapon;
    fscanf_s(file, "%s %d", weapon.name, STR_LENGTH, &weapon.price);
    printf("%s %d\n", weapon.name, weapon.price);

    fclose(file);
}

void FileIo::Save()
{
    FILE* file = NULL;
    fopen_s(&file, filename, "w");
    if (!file) {
        printf("파일 열기 실패\n");
        return;
    }

    Weapon weapon = { "sword", 500 };

    fprintf_s(file, weapon.name);
    fprintf_s(file, " ");
    fprintf_s(file, "%d", weapon.price);
    fprintf_s(file, "\n");

    fclose(file);
}

void FileIo::Run()
{
    Save();
    Load();
}
