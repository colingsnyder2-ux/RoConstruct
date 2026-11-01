// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct S {
    char pad[0x41];
    bool m_b;
    void set(bool b);
};
void S::set(bool b) { m_b = b; }
