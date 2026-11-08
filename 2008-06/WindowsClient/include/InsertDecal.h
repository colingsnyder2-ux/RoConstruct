#pragma once
// >>> native-status (generated) -- do not edit >>>
// InsertDecal | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 83b01bae | roc native-status --write
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
