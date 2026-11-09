// from server: 100% by atomic.potato
// roc 2009-12 0041d620  unit: CEnabledCmdUI  size: 57 bytes
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp

extern "C" __declspec(dllimport) void *__stdcall SendMessageA(void *, unsigned int, unsigned int, long);
extern "C" void *__stdcall sub_7f3b2a(void *);

struct CEnabledCmdUI {
    char pad[0x20];
    void *m_hWnd;
    void Enable(int, int);
};

void CEnabledCmdUI::Enable(int a, int b)
{
    void *p = SendMessageA(m_hWnd, 0x110f, 0, 0);
    void *q = sub_7f3b2a(p);
    SendMessageA(*(void **)((char *)q + 0x20), 0xc5, 0x20, 0);
    *(int *)b = 0;
}
