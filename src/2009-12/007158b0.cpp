// from server: 55% by atomic.potato
struct S_007158b0
{
    int m_ptr;
    int f();
};

extern "C" int __stdcall sub_007b1ec0(int, int);

int S_007158b0::f()
{
    return sub_007b1ec0(m_ptr + 208, 2);
}
