// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>
#include "reflection/signal.h"

namespace RBX {
    class Instance;
    namespace Reflection {
        class PropertyDescriptor;
    }
}

// INFERRED: The target is a scalar deleting destructor for this signal instance.
struct Local_006347a0 : RBX::Reflection::TSignalDesc<
    void(boost::shared_ptr<RBX::Instance>, const RBX::Reflection::PropertyDescriptor*)>
{
    typedef TSignalInstance SignalInstance;
};

typedef Local_006347a0::SignalInstance Local_006347a0_Signal;

#pragma inline_depth(0)
extern "C" Local_006347a0_Signal* __fastcall fn_006347a0(
    Local_006347a0_Signal* self, int unusedEdx, unsigned int flags)
{
    self->Local_006347a0_Signal::~Local_006347a0_Signal();
    if (flags & 1)
        ::operator delete(self);
    return self;
}
