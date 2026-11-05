// from server: 60% by atomic.potato
extern "C" int sub_007B1EC0(int, int);

struct S_00715870
{
    char pad0[180];
    int m_ptr;
    int f();
};

int S_00715870::f()
{
    return sub_007B1EC0(m_ptr + 208, 0);
}
