#pragma once
#include "v8tree/Verb.h"

class CRobloxView;
namespace RBX { class DataModel; }

// Original 458ec0 (constructor), vtable 00819090, size 0x20. Verb base ends at 0xc.
// The double after the data model pointer is aligned to 8, which explains +0x14.
// doIt and the other virtuals are not recovered here.
class ToggleToolboxVerb : public RBX::Verb {
    CRobloxView* view;      // +0x0c
    RBX::DataModel* model;  // +0x10
    double createdAt;       // +0x18, G3D::System::getLocalTime at construction
public:
    ToggleToolboxVerb(CRobloxView*, RBX::DataModel*);
    virtual void doIt(RBX::IDataState*);
};
