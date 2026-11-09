// from server: 100% by atomic.potato
struct CWnd
{
    char pad[0x20];
    void* m_hWnd;
};

struct CChildFrame
{
    char pad[0x20];
    void* m_hWnd;
    void SetChild(int nCmdShow);
    void sub_6A0E0C(int n);
};

extern "C" void* (__stdcall *GetParent)(void*);
extern "C" void* (__stdcall *GetWindow)(void*, unsigned int);

CWnd* __stdcall sub_6A0BDE(void*);

void CChildFrame::SetChild(int nCmdShow)
{
    CWnd* pParent = sub_6A0BDE(GetParent(m_hWnd));
    CWnd* pOwner = sub_6A0BDE(GetWindow(pParent->m_hWnd, 5));
    int n = (pOwner == (CWnd*)this) ? 3 : nCmdShow;
    sub_6A0E0C(n);
}
