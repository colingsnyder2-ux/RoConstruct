// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// ValueConverter | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 12b00ae4 | roc native-status --write
#include <afxwin.h>
#include <atlbase.h>
#include <atlsafe.h>
#include "reflection/type.h"
#include "util/ContentProvider.h"

extern template const char* std::basic_string<char>::c_str() const;
extern SAFEARRAY* __cdecl makeSafeArray(RBX::Reflection::ValueCollection*);

void __cdecl valueToVariant(RBX::Reflection::Value* value, VARIANT* result) {
    if (value->isVoid()) { result->vt = VT_NULL; return; }
    if (value->isType<int>()) { ATL::CComVariant v(value->cast<int>()); v.Detach(result); return; }
    if (value->isType<bool>()) { ATL::CComVariant v(value->cast<bool>()); v.Detach(result); return; }
    if (value->isType<float>()) { ATL::CComVariant v(value->cast<float>()); v.Detach(result); return; }
    if (value->isType<double>()) { ATL::CComVariant v(value->cast<double>()); v.Detach(result); return; }
    if (value->isType<std::string>()) { ATL::CComVariant v(value->cast<std::string>().c_str()); v.Detach(result); return; }
    if (value->isType<RBX::ContentId>()) { ATL::CComVariant v(value->cast<RBX::ContentId>().c_str()); v.Detach(result); return; }
    if (value->isType<RBX::Reflection::ValueCollection>()) {
        ATL::CComVariant v(makeSafeArray(const_cast<RBX::Reflection::ValueCollection*>(&value->asRef<RBX::Reflection::ValueCollection>())));
        v.Detach(result);
        return;
    }
    result->vt = VT_EMPTY;
}
