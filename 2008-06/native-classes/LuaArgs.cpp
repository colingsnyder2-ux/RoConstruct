// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// LuaArgs | 2008-06 | 1 byte-exact, inactive (not link-selected)
// 1/1 mapped addresses byte-exact | 0 unproved | no mapped strings | by EspClaude (deepseek:deepseek-chat)
// <<< native-status | src 2b1bedbf | roc native-status --write
#include <afxwin.h>
#include <atlbase.h>
#include <stdexcept>
#include <G3D/format.h>
#include "LuaArgs.h"

void LuaArgs::push(ATL::CComVariant value) {
    switch (value.vt) {
    case VT_R4: add(value.fltVal); break;
    case VT_R8: addv((float)value.dblVal); break;
    case VT_BSTR: add(std::string(CStringA(value.bstrVal))); break;
    case VT_BOOL: add(value.boolVal == VARIANT_TRUE); break;
    case VT_I2: addv((int)value.iVal); break;
    case VT_I4: addv((int)value.lVal); break;
    case VT_NULL: values.push_back(RBX::Reflection::Value()); break;
    case VT_EMPTY:
    case VT_ERROR: break;
    default:
        std::string msg = G3D::format("Invalid argument %d VT_TYPE=%d", values.size() + 1, value.vt);
        throw std::runtime_error(msg);
    }
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Vector_const_iterator<RBX::Reflection::Value,std::allocator<RBX::Reflection::Value> >;
template class std::_Vector_iterator<RBX::Reflection::Value,std::allocator<RBX::Reflection::Value> >;
