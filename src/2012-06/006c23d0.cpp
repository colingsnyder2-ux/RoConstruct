// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_descriptorresultcopy_53e2af99d05b6b8d.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
struct Name;
struct Value { std::string text; const Name* type; };
struct Result : Value {};
struct Member { void assign(Value); };
struct Target { char pad[16]; Member member; };
struct Descriptor { Result get(void*); void set(void*,Target*); };
void Descriptor::set(void* source,Target* target) {target->member.assign(get(source));}
