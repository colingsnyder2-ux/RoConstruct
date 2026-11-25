// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <boost/thread/once.hpp>
#include "v8tree/Service.h"
#include "v8datamodel/GeometryService.h"
#include "util/Object.h"

namespace RBX {
    extern template boost::shared_ptr<GeometryService> Creatable<Instance>::create<GeometryService>();
}

// INFERRED: unknown callees and once_flag global mapped from 006448f0 disassembly
extern "C" RBX::GeometryService* __fastcall fn_006447b0(const RBX::ServiceProvider* self);
extern "C" void __cdecl fn_00643d00(void);
extern "C" size_t __cdecl fn_006434f0(void);
extern "C" boost::once_flag g_0097d5e8;

extern "C" RBX::GeometryService* __fastcall fn_006448f0(const RBX::ServiceProvider* self, int unusedEdx)
{
    RBX::GeometryService* service = fn_006447b0(self);
    if (service == NULL)
    {
        boost::shared_ptr<RBX::GeometryService> value = RBX::Creatable<RBX::Instance>::create<RBX::GeometryService>();
        service = value.get();
        boost::call_once(&fn_00643d00, g_0097d5e8);
        size_t index = fn_006434f0();
        self->serviceArray[index] = value;
        service->setParent(const_cast<RBX::ServiceProvider*>(self));
    }
    return service;
}
