// from server: 100% by atomic.potato
struct Obj;

struct CMainFrame {
    Obj* m_ptr;
    void Set(Obj* p);
};

struct Obj {
    void Release();
};

void __cdecl G1_func_006a067a(void* p);

void CMainFrame::Set(Obj* p)
{
    Obj* old = m_ptr;
    m_ptr = p;
    if (old)
    {
        old->Release();
        G1_func_006a067a(old);
    }
}
