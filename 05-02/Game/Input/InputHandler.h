#pragma once
#include "Command/Command.h"
#include <memory>

class InputHandler {

public:
  ICommand *HandleInput();

  void AssignMoveLeftCommand();
  void AssignMoveRightCommand();

private:
  std::unique_ptr<ICommand> pressKeyD_;
  std::unique_ptr<ICommand> pressKeyA_;
};
