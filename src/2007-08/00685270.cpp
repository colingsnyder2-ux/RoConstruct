// from server: 100% by colin
struct CXTPPropExchange {
    char pad[0x24];
    int m_field;
    void Forward(int a);
};

extern "C" void __cdecl sub_6851a0(int, int);

void CXTPPropExchange::Forward(int a)
{
    sub_6851a0(a, m_field);
}
