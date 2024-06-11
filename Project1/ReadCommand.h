#pragma once

#include "Command.h"
#include "NANDdevice.h"

#include <string>
#include <iostream>


class ReadCommand : public DeviceCommand {
private:
    int address = -1;

public:
    ReadCommand(NANDDevice* device)
        : DeviceCommand(device) {}

    void execute() override;

    ShellStringParserError parse(vector<string> inputCmdVec) override;
};