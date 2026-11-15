#pragma once

namespace RBX {
// Original DataModel RTTI has no StateStack base beneath IDataState.
// Vtable 0083030c has exactly setDirty/isDirty before the next RTTI locator.
class __declspec(novtable) IDataState {
public:
    virtual void setDirty(bool) = 0;
    virtual bool isDirty() const = 0;
};
}
