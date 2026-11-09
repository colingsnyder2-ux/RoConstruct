// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_descriptorvariant_5cffc17d2669c6db.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
struct Name;
extern const Name& __cdecl getLocalScope();
struct Value { std::string text; const Name* type; Value():type(&getLocalScope()){} };
extern bool __cdecl convert(const std::string&,Value&);
struct Receiver;
struct Table { void* reserved[3]; void (__thiscall* set)(Receiver*,const Name&,const Value&); };
struct Receiver { Table* table; };
struct Descriptor { char pad[0x18]; Receiver* receiver; bool setValue(const Name&,const std::string&); };
bool Descriptor::setValue(const Name& name,const std::string& input) { Value local; if(convert(input,local)) {receiver->table->set(receiver,name,local);return true;}return false;}
