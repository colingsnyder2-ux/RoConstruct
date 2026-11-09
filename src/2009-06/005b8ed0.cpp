// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);
struct E { char d[0x48]; };
struct It {
    void* cont; E* ptr;
    bool hasCont() const; bool same(const It& r) const;
    int operator-(const It& r) const;
};
int It::operator-(const It& r) const
{
    if (!(hasCont() && same(r))) _invalid_parameter_noinfo();
    return ptr - r.ptr;
}
