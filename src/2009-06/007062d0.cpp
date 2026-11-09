// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Flag_007062d0 { int x; };
void __cdecl callOnce_007062d0(Flag_007062d0& f, void (*fn)());
struct Str_007062d0 {
    int alval;
    union { char buf[16]; char* ptr; };
    unsigned size, res;
    const char* c_str() const { return res >= 16 ? ptr : buf; }
};
Str_007062d0* __cdecl lookup_007062d0(int key);
extern Flag_007062d0 flag_007062d0;
extern int key_007062d0;
extern const char* default_007062d0;
void init_007062d0();
const char* get_007062d0()
{
    callOnce_007062d0(flag_007062d0, init_007062d0);
    Str_007062d0* x = lookup_007062d0(key_007062d0);
    if (x)
        return x->c_str();
    return default_007062d0;
}
