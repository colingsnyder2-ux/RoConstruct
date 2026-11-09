// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll roc_espeon_propertylistimportedf7def85c6a9d6756.cpp

// Candidate translation unit (score above; library headers required).
#include <list>
#include <string>
#include <atlbase.h>
struct String:std::string {using std::string::operator=;__declspec(dllimport) const char* c_str()const;};
struct Value {std::string get();};
struct Interface {virtual void __stdcall slot0();virtual void __stdcall slot1();virtual void __stdcall slot2();virtual void __stdcall slot3();virtual void __stdcall slot4();virtual void __stdcall slot5();virtual void __stdcall slot6();virtual void __stdcall slot7();virtual void __stdcall slot8();virtual long __stdcall set(BSTR);};
struct Binder {char prefix[12];std::list<Value*> values;bool updating;char gap[7];Interface* target;void update();};
void Binder::update(){updating=false;String text;std::list<Value*>::const_iterator current=values.begin(),last=values.end();if(current!=last){text=(*current)->get();++current;}for(;current!=last;++current){if(text!=(*current)->get()){text.clear();break;}}Interface* destination=target;destination->set(ATL::CComBSTR(text.c_str()));}
