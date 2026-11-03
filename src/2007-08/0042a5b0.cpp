// from server: 100% by EspClaude
// roc 2007-08 0042a5b0  unit: CLuaHtmlView
struct IBase0 { virtual void f0(); };
struct IBase1 { virtual void f1(); };
struct CObj : IBase0, IBase1 { };
struct IProvider {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void Store(IBase1* key, const char* value);
};
class CLuaHtmlView {
    CObj* m_obj;
    int m_4;
    IProvider* m_provider;
public:
    void Set(const char* value);
};
void CLuaHtmlView::Set(const char* value)
{
    m_provider->Store(m_obj, value);
}
