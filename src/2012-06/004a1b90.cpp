// from server: 100% by tajop
struct Inner {
    void f();
};
struct CScriptDoc {
    char pad[0x54];
    Inner* m_inner;
    void g();
    void h();
};
void CScriptDoc::h()
{
    g();
    m_inner->f();
}
