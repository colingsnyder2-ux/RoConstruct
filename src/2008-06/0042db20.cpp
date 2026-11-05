// from server: 100% by EspClaude
// from server: 86% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espclaude_448d9bca34009ac9.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#ifndef _AFXDLL
#define _AFXDLL
#endif
#include <new>
#include <afxwin.h>
#include <atlbase.h>
#include <atlcom.h>
#include <vector>
#include <string>
#include <stdexcept>

struct BStr {
    char* m_pszData;
    __declspec(dllimport) BStr(const wchar_t* psz);
    __declspec(dllimport) operator const char*() const throw();
    __declspec(dllimport) ~BStr() throw();
};

class placeholder {
public:
    virtual ~placeholder();
};

class Value {
public:
    Value();
    template<class T> Value(const T& v);
    Value(const Value& other);
    ~Value() { delete content; }
    const void* type;
    placeholder* content;
};

std::string __cdecl format(const char* fmt, ...);

class LuaArgs {
public:
    ~LuaArgs();
    void push(ATL::CComVariant value);
    template<class T> __forceinline void add(const T& v) { values.push_back(v); }
    template<class T> __forceinline void addv(T v) { values.push_back(v); }
    std::vector<Value> values;
};

void LuaArgs::push(ATL::CComVariant value)
{
    switch (value.vt)
    {
    case VT_R4:
        add(value.fltVal);
        break;
    case VT_R8:
        addv((float)value.dblVal);
        break;
    case VT_BSTR:
        add(std::string(BStr(value.bstrVal)));
        break;
    case VT_BOOL:
        add(value.boolVal == VARIANT_TRUE);
        break;
    case VT_I2:
        addv((int)value.iVal);
        break;
    case VT_I4:
        addv((int)value.lVal);
        break;
    case VT_NULL:
        values.push_back(Value());
        break;
    case VT_EMPTY:
    case VT_ERROR:
        break;
    default:
        {
            std::string msg = format("Invalid argument %d VT_TYPE=%d", values.size() + 1, value.vt);
            throw std::runtime_error(msg);
        }
    }
}

