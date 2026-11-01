// from server: 100% by colin
struct Arg { char pad[0xf4]; int flag; };

struct CXTPPaintManager {
    char pad0[0x74];
    int m_74;
    int m_78;
    int m(Arg* a);
};

int CXTPPaintManager::m(Arg* a)
{
    if (a->flag == 0)
        return m_78;
    return m_74;
}
