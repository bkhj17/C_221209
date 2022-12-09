#include "Editor.h"
#include "Dictionary.h"
#include <Windows.h>
#include <conio.h>

void Editor::Select()
{
    int select;
    printf("1. 단어 확인\n"
        "2. 단어 추가\n"
        "그 외. 메인 메뉴로\n"
        "-> ");
    scanf_s("%d", &select);

    if (select) {

    }
}

void Editor::Add()
{
    char addStr[Dictionary::MAX_LENGTH] = "";
    scanf_s("%s", addStr, Dictionary::MAX_LENGTH);

    Dictionary::GetInstance()->Save();
    printf("\n단어 추가 : %s\n", addStr);
    Sleep(1000);
}

void Editor::PrintTitle(std::string& renderTarget)
{
    if (Dictionary::GetInstance()->GetNumWords() == Dictionary::MAX_WORD_NUM) {
        message += "단어장 꽉 찼음!\n";
    }
    renderTarget += "[ 단어 편집 ]\n";

}

void Editor::PrintList(std::string& renderTarget)
{
    renderTarget += "[ 단어 출력 ]\n";
    Dictionary::GetInstance()->PrintWords(renderTarget);
    getchar();
    fflush(stdin);
    getchar();
}

void Editor::Init()
{
    workState = WorkState::SELECT;
    call_render = true;
}

void Editor::Update()
{
    switch (workState)
    {
    case WorkState::SELECT:
        Select();
        break;
    case Editor::WorkState::ADD:
        Add();
        workState = WorkState::SELECT;
        break;
    case Editor::WorkState::PRINT:
        break;
    case Editor::WorkState::CLOSE:
        break;
    default:
        break;
    }
}

bool Editor::Render(std::string& renderTarget)
{
    if (call_render)
        return false;

    PrintTitle(renderTarget);
    if (message != "") {
        renderTarget += "---------------------------\n";
        renderTarget += message;
    }


    call_render = false;
    return true;
}

bool Editor::IsClose()
{
    return workState == WorkState::CLOSE;
}

void Editor::BeforeClose()
{
}
