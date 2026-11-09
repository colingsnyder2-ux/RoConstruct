// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct IRunView { virtual void onEvent(int); };
struct Tool {
    void* m_a;
    void* m_b;
    IRunView* m_view;
    void method();
};
void Tool::method()
{
    IRunView* v = m_view;
    if (v)
        v->onEvent(1);
}
