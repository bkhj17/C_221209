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

    if (select == 1)
        workState = WorkState::PRINT;
    else if (select == 2)
        workState = WorkState::ADD;
    else
        workState = WorkState::CLOSE;
}

void Editor::Add()
{
    if (Dictionary::GetInstance()->GetNumWords() == Dictionary::MAX_WORD_NUM)
        message += "�ܾ��� �� á��!\n";
    

    char addStr[Dictionary::MAX_LENGTH] = "";
    printf("�߰��� �ܾ �Է��Ͻÿ� -> ");
    scanf_s("%s", addStr, Dictionary::MAX_LENGTH);
    Dictionary::GetInstance()->AddWord(addStr);

    Dictionary::GetInstance()->Save();
    printf("\n�ܾ� �߰� : %s\n", addStr);
    Sleep(1000);
}

void Editor::PrintTitle(std::string& renderTarget)
{
    renderTarget += "[ �ܾ� ���� ]\n";
}

void Editor::PrintList()
{  
    std::string s = "";
    Dictionary::GetInstance()->PrintWords(s);
    printf("%s\n", s.c_str());
    printf("�ƹ� Ű�� ������ ���ư��ϴ�");
    while (1) {
        if (_kbhit()) {
            break;
        }
    }
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
        PrintList();
        workState = WorkState::SELECT;
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
