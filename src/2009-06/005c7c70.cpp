// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);
struct C { char pad[0x18]; char* first; unsigned int count; };
struct Base { void* mycont; Base(); void adopt(const C* c); };
struct It : Base {
    char* ptr;
    It(char* p, const C* c);
};
It::It(char* p, const C* c)
{
    if (1) { if (!(c != 0 && c->first <= p && p <= c->first + c->count)) _invalid_parameter_noinfo(); do {} while (0); }
    adopt(c);
    ptr = p;
}
