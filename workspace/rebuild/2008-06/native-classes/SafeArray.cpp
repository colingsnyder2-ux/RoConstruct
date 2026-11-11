// >>> native-status (generated) -- do not edit >>>
// SafeArray | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 0106daaf | roc native-status --write
#include <afxwin.h>
#include <atlsafe.h>
#include "reflection/type.h"

extern void __cdecl valueToVariant(RBX::Reflection::Value*, VARIANT*);

SAFEARRAY* __cdecl makeSafeArray(RBX::Reflection::ValueCollection* values) {
    ATL::CComSafeArray<VARIANT> array;
    array.Create(static_cast<ULONG>(values->size()));
    for (unsigned int i = 0; i < values->size(); i++)
        { RBX::Reflection::Value* value=&(*values)[i]; VARIANT* dest=&array[(LONG)i]; valueToVariant(value,dest); }
    return array.Detach();
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class ATL::CComSafeArray<tagVARIANT,12>;
