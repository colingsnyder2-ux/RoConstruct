// from server: 72% by colin
// roc 2007-08 00461c90  size: 98 bytes
// library mfc-8.0/atlmfc\src\mfc\viewform.cpp

extern "C" void __stdcall sub_8bab64();

struct CFormView {
    char pad[0xf0];
    bool m_bSomeFlag;
    int OnSomething(unsigned int, unsigned int, unsigned int);
};

int CFormView::OnSomething(unsigned int a, unsigned int b, unsigned int c)
{
    sub_8bab64();
    if (a != 0xffffea78) {
        if (m_bSomeFlag) {
            *(unsigned short*)c = 3;
            *(unsigned int*)((char*)c + 8) = 0x1730;
            return 1;
        }
        return ((int (__thiscall*)(CFormView*, unsigned int, unsigned int, unsigned int))0x62fdd0)(this, b, 0xffffea78, c);
    }
    return ((int (__thiscall*)(CFormView*, unsigned int, unsigned int, unsigned int))0x62fdd0)(this, b, a, c);
}
