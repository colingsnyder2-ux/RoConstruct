// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Type { Type(const char* name, int x); virtual ~Type(); };
struct TypeImpl : Type { TypeImpl() : Type("Object", 0) {} virtual ~TypeImpl() {} };
TypeImpl* func_005e58a0(){ static TypeImpl init; return &init; }
