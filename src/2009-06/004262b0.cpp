// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD


extern "C" void* __cdecl get_type();
void* __cdecl operator new(unsigned int);
extern unsigned int holder_table[];

struct Holder {
    void* table;
    bool value;
    Holder(const bool& v);
};

inline Holder::Holder(const bool& v)
{
    table = holder_table;
    value = v;
}

struct S {
    void* type;
    Holder* holder;
    S(const bool& value);
};

extern int exeCounter;
S::S(const bool& value)
{
    ++exeCounter;
    type = get_type();
    holder = new Holder(value);
}
