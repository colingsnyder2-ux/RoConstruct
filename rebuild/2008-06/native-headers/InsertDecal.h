#pragma once
#include <afxwin.h>
#include "StandardVerbs.h"

namespace RBX { class Decal; }

class InsertDecal : public RBX::EditSelectionVerb {
    RBX::Instance* getTarget() const;
public:
    __declspec(noinline) InsertDecal(RBX::DataModel*, const char*);
    virtual bool isEnabled() const;
    virtual void doIt(RBX::IDataState*);
protected:
    virtual boost::shared_ptr<RBX::Decal> createInstance();
    const CString& prepareImage(const CString&);
};
