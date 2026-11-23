// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/DataModel.h"

namespace RBX { double getRealTime(); }

// INFERRED: owner class unknown; only the float at +0x1c0 and double at +0x1c8 are touched.
struct Fn554880Self {
    char pad[0x1c0];
    float step;
    int pad2;
    double elapsed;
};

extern "C" int __fastcall fn_00578e50(const RBX::DataModel* self, int unusedEdx, float a1);

extern "C" void __fastcall fn_00554880(Fn554880Self* self, int unusedEdx, boost::shared_ptr<const RBX::DataModel> dm)
{
    double start = RBX::getRealTime();
    {
        RBX::DataModel::Lock lock(dm);
        fn_00578e50(dm.get(), 0, self->step);
        self->elapsed = RBX::getRealTime() - start;
    }
}
