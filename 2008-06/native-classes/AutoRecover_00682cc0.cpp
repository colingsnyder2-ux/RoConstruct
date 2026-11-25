// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: header path for RBX::Reflection::SignatureDescriptor; the real header name was not shown.
#include <list>
#include <stdexcept>
#include "reflection/Reflection.h"

// Explicitly instantiate the vendor std::list<Item>::_Incsize
// (max_size() - _Mysize < _Count -> throw length_error("list<T> too long"); _Mysize += _Count).
template void std::list<
    RBX::Reflection::SignatureDescriptor::Item,
    std::allocator<RBX::Reflection::SignatureDescriptor::Item> >::_Incsize(unsigned int);
