// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: header paths and the vtable layout are guesses. The thirteen vtable stores
// at 0x00/0x10/0x14/0x20/0x24/0x44/0x64/0x84/0xa4/0xc4/0x130/0x150/0x170 come from
// the compiler (base-class and virtual-base setup) after the ServiceProvider ctor call.
#include "v8tree/ServiceProvider.h"

namespace RBX {

extern const char* const sGlobalSettings;

// INFERRED: NonFactoryProduct<Base, &name> derives from Base and only adds vtables.
template<class T, const char* const* Name>
class NonFactoryProduct : public T {
public:
    NonFactoryProduct() : T() {}
};

// Explicit instantiation emits the target constructor.
template class NonFactoryProduct<ServiceProvider, &sGlobalSettings>;

}
