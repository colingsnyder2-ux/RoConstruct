#pragma once
#include "StandardVerbs.h"

class InsertObject : public RBX::RunStateVerb {
    RBX::Instance* target() const;
public:
    __declspec(noinline) InsertObject(RBX::DataModel*);
    virtual void doIt(RBX::IDataState*);
};
