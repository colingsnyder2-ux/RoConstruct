// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: xtp-11.2.2-lib-strlen roc_espeon_propertylistchangedf88b1516a00dfb5a.cpp

// Candidate translation unit (score above; library headers required).
#include <afxwin.h>
#include <atlbase.h>
#include <list>
#include <string>
#include <functional>
#include <algorithm>
struct Value {void set(const std::string*);};
struct Interface {virtual void __stdcall slot0();virtual void __stdcall slot1();virtual void __stdcall slot2();virtual void __stdcall slot3();virtual void __stdcall slot4();virtual void __stdcall slot5();virtual void __stdcall slot6();virtual void __stdcall slot7();virtual void __stdcall slot8();virtual void __stdcall slot9();virtual long __stdcall get(BSTR*);};
struct Binder {char prefix[12];std::list<Value*> values;bool updating;char gap[7];Interface* source;bool changed();};
bool Binder::changed(){ATL::CComBSTR value;source->get(&value);std::string text((LPCSTR)CStringA(value));std::for_each(values.begin(),values.end(),std::bind2nd(std::mem_fun(&Value::set),&text));return true;}
