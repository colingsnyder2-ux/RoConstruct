// from server: 100% by colin
struct CXTPImageManagerIcon {
    char pad0[4];
    int m_nWidth;
    char pad1[4];
    int m_bLoaded;
    void sub_648640();
    void Init(int);
};

extern "C" int __cdecl sub_649a10(int);

void CXTPImageManagerIcon::Init(int nWidth)
{
    sub_648640();
    m_nWidth = sub_649a10(nWidth);
    m_bLoaded = 1;
}
