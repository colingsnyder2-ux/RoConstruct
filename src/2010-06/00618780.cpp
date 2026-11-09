// from server: 100% by atomic.potato
extern int g_00C18314;

struct S_func_00618780
{
    int m_value;
    int m_unused;
    S_func_00618780();
};

extern "C" int __cdecl func_00618710();

S_func_00618780::S_func_00618780()
{
    ++g_00C18314;
    m_value = func_00618710();
    m_unused = 0;
}
