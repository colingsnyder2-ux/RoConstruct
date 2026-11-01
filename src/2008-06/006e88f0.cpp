// from server: 100% by tester
struct CRegObject {
    char pad[0x10];
    int m_field10;
    int Check();
};

extern "C" bool __stdcall Helper_760a00(int, int);

int CRegObject::Check()
{
    if (m_field10 == 2)
    {
        if (Helper_760a00(5, 0))
            return 1;
    }
    return 0;
}
