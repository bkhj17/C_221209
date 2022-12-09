#pragma once
#include "MenuCycle.h"
class Editor : public MenuCycle
{
	enum class WorkState {
		SELECT,
		ADD,
		PRINT,
		CLOSE
	};
	WorkState workState;

private:
	bool call_render;
	std::string message = "";

	void Select();
	void Add();
	void PrintTitle(std::string& renderTarget);
	void PrintList();
public:
	// MenuCycle을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual bool Render(std::string& renderTarget) override;
	virtual bool IsClose() override;
	virtual void BeforeClose() override;
};