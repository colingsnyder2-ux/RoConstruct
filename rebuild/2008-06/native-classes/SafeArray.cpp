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
