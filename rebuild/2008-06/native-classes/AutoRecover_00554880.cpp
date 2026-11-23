// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <boost/shared_ptr.hpp>
#include "v8datamodel/DataModel.h"

namespace RBX {
    double getRealTime();
}

extern "C" int __fastcall fn_00578e50(void* self, int unusedEdx, float a1);

// INFERRED: the owner object is only touched through raw offsets
// (float at +0x1c0, double at +0x1c8), since no class header was available.
extern "C" void __fastcall fn_00554880(void* self, int unusedEdx, boost::shared_ptr<const RBX::DataModel> dataModel)
{
    char* base = static_cast<char*>(self);
    double start = RBX::getRealTime();
    {
        RBX::DataModel::Lock lock(dataModel);
        fn_00578e50((void*)dataModel.get(), 0, *reinterpret_cast<float*>(base + 0x1c0));
        *reinterpret_cast<double*>(base + 0x1c8) = RBX::getRealTime() - start;
    }
}
