#pragma once

namespace RBX {
class __declspec(novtable) IDataState {
public:
    virtual void setDirty(bool) = 0;
    virtual bool isDirty() const = 0;
};
}
