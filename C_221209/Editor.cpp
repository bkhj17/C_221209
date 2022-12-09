#include "Editor.h"
#include "Dictionary.h"
#include <Windows.h>
#include <conio.h>

void Editor::Select()
{
    int select;
    printf("1. �ܾ� Ȯ��\n"
        "2. �ܾ� �߰�\n"
        "�� ��. ���� �޴���\n"
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
    printf("\n�ܾ� �߰� : %s\n", addStr);
    Sleep(1000);
}

void Editor::PrintTitle(std::string& renderTarget)
{
    if (Dictionary::GetInstance()->GetNumWords() == Dictionary::MAX_WORD_NUM) {
        message += "�ܾ��� �� á��!\n";
    }
    renderTarget += "[ �ܾ� ���� ]\n";

}

void Editor::PrintList(std::string& renderTarget)
{
    renderTarget += "[ �ܾ� ��� ]\n";
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
