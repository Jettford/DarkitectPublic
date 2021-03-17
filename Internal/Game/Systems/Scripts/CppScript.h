#pragma once

#include <string>

#include <Common/Global.h>

#include <Game/Entity.h>

// TODO: Gravity or Wren scripting

class CppScript {
private:

public:
	static CppScript* GetScriptFromPath(std::string Path);

	virtual void OnStart(Entity* Owner) {}

};