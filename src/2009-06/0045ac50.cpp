// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct V { virtual ~V(); };
template<class T> inline void safeDelete(T*& p) { delete p; p = 0; }
struct C {
    char pad[0xfc];
    V* a;
    V* b;
    void release();
};
void C::release()
{
    if (b) {
        safeDelete(a);
        safeDelete(b);
    }
}
