// from server: 100% by EspClaude
// roc 2007-08 0042a5f0  unit: CLuaHtmlView
struct Result {
    Result(const Result&);
    ~Result();
    void* p;
};
struct IBase0 { virtual void f0(); };
struct IBase1 { virtual void f1(); };
struct CObj : IBase0, IBase1 { };
struct IProvider {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual Result Lookup(IBase1* key);
};
class CLuaHtmlView {
    CObj* m_obj;
    int m_4;
    IProvider* m_provider;
public:
    Result Get();
};
Result CLuaHtmlView::Get()
{
    return m_provider->Lookup(m_obj);
}
