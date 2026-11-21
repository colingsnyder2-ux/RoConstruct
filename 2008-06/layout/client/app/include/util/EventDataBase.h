#pragma once

namespace RBX {
class EventDataBase {
public:
    virtual void execute() = 0;
    virtual ~EventDataBase() throw() {}
};
}
