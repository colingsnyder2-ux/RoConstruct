#pragma once
// >>> native-status (generated) -- do not edit >>>
// IDataState | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 0b8b8864 | roc native-status --write

namespace RBX {
// Original DataModel RTTI has no StateStack base beneath IDataState.
// Vtable 0083030c has exactly setDirty/isDirty before the next RTTI locator.
class __declspec(novtable) IDataState {
public:
    virtual void setDirty(bool) = 0;
    virtual bool isDirty() const = 0;
};
}
