// from server: 100% by atomic.potato
extern "C" int __cdecl sub_007f4aaa(int, int, int, int, int);

struct S_func_005596b0 {
    char pad0[0x29d0];
    int m_x;
    bool f(int, int);
};

bool S_func_005596b0::f(int a, int b)
{
    int r = sub_007f4aaa(a, 0, 0xb0c040, 0xaffe40, 0);
    if (r != 0) {
        return m_x == r;
    }
    return true;
}
