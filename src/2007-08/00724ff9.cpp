// from server: 82% by colin
struct CXTIconHandle {
    int m_domIcon;
    CXTIconHandle();
};

extern "C" void __cdecl sub_724ef9();
extern "C" int __cdecl sub_724e6b(void*);

extern unsigned char g_flag;

CXTIconHandle::CXTIconHandle()
{
    sub_724ef9();
    this->m_domIcon = 0x2c;
    if (sub_724e6b(this) < 0) {
        g_flag = 1;
        this->m_domIcon = 0;
    }
}
