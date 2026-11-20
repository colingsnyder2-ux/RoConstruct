#pragma once

namespace RBX {
// Original vtable 0080f860 and scalar destructor 00421110: no owning members.
class EventDataBase {
public:
    virtual void execute() = 0;
    virtual ~EventDataBase() throw() {}
};
}
