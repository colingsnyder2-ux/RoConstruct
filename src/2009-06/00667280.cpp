// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct VState {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4(); virtual void v5();
    virtual ~VState();
};
struct Counted {
    virtual void dispose();
    int use_count_;
    int weak_count_;
    VState* px_;
};
void Counted::dispose()
{
    delete px_;
}
