// from server: 100% by EspClaude
// from server: 72% by colin
// roc 2007-08 00461c90  size: 98 bytes
// library mfc-8.0/atlmfc\src\mfc\viewform.cpp

extern "C" void* (__stdcall* sub_8bab64)();

struct CFormViewBase {
    char pad[0xf0];
    int baseHandler(unsigned int, unsigned int, unsigned int);
};

struct CFormView : CFormViewBase {
    bool m_bSomeFlag;
    int OnSomething(unsigned int, unsigned int, unsigned int);
};

int CFormView::OnSomething(unsigned int a, unsigned int b, unsigned int c)
{
    sub_8bab64();
    if (b != 0xffffea78)
        return baseHandler(a, b, c);
    if (m_bSomeFlag) {
        *(unsigned short*)c = 3;
        *(unsigned int*)((char*)c + 8) = 0x1730;
        return 1;
    }
    return baseHandler(a, 0xffffea78, c);
}
