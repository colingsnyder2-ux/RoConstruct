#pragma once
// >>> native-status (generated) -- do not edit >>>
// InsertObject | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 868c5236 | roc native-status --write
#include "StandardVerbs.h"

class InsertObject : public RBX::RunStateVerb {
    RBX::Instance* target() const;
public:
    __declspec(noinline) InsertObject(RBX::DataModel*);
    virtual void doIt(RBX::IDataState*);
};
