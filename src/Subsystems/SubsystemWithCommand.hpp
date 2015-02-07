#pragma once

#include "Commands/Subsystem.h"
#include <memory>

template<typename DefaultCommand>
class SubsystemWithCommand: public Subsystem {
private:
    DefaultCommand* m_defaultCommand;
public:
    SubsystemWithCommand(const char* name) : Subsystem(name), m_defaultCommand(0) {};

    virtual ~SubsystemWithCommand() {
        delete m_defaultCommand;
    }

    void InitDefaultCommand() {
        m_defaultCommand = new DefaultCommand();
        SetDefaultCommand(m_defaultCommand);
    }
};

template<>
class SubsystemWithCommand<void>: public Subsystem {
public:
    SubsystemWithCommand(const char* name) : Subsystem(name) {};

    virtual ~SubsystemWithCommand() {}

    void InitDefaultCommand() {}
};
