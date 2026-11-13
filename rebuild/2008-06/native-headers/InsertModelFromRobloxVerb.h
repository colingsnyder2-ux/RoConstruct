#pragma once
// >>> native-status (generated) -- do not edit >>>
// InsertModelFromRobloxVerb | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 71207ebc | roc native-status --write
#include "v8tree/Verb.h"

class CRobloxView;
namespace RBX { class DataModel; }

// RTTI InsertModelFromRobloxVerb (vtable 00819090); its verb name is "ToggleToolbox".
// Constructor 00458ec0, size 0x20. Verb base ends at 0xc; the double after the data model
// pointer is aligned to 8, which explains +0x14.
class InsertModelFromRobloxVerb : public RBX::Verb {
    CRobloxView* view;      // +0x0c
    RBX::DataModel* model;  // +0x10
    double createdAt;       // +0x18, G3D::System::getLocalTime at construction
public:
    InsertModelFromRobloxVerb(CRobloxView*, RBX::DataModel*);
    virtual bool isEnabled() const;           // 00458f50 (slot 2)
    virtual bool isChecked() const;           // 00458f90 (slot 3)
    virtual void doIt(RBX::IDataState*);      // 00458fb0 (slot 4)
};
