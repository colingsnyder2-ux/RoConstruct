// from server: 41% by atomic.potato
struct S_0073b0e0 {
    char pad0[0x14];
    int* m_14;
    char pad18[0x10];
    int m_28;
    int m_2c;
    char m_30;
    int f_0073b0e0(int, int, int, int, int);
};

extern "C" int __cdecl func_005ce7d0(int, int);
extern "C" int __cdecl func_006a5b20(int*, int);
extern "C" int __cdecl func_0062d1b0(int);
extern "C" int __cdecl func_0062d140(int);
extern "C" int __cdecl func_005ba5e0();
extern "C" int __cdecl func_00592b40(int*, int, int);
extern "C" int __cdecl func_0062d1d0(int*, int);

int S_0073b0e0::f_0073b0e0(int a1, int a2, int a3, int a4, int a5)
{
    int v = func_005ce7d0(a1, a2);
    func_006a5b20((int*)this, v);
    this->m_28 = a3;
    this->m_2c = a4;
    *(int*)this = 0xab423c;
    func_0062d1b0((int)&this->m_30);
    ++*(int*)0xcca3e4;
    func_0062d140(a5);
    this->m_14 = (int*)func_0062d140(a5);
    ++*(int*)0xcca450;
    int r = func_005ba5e0();
    int tmp;
    func_00592b40(&tmp, r, (int)&this->m_30);
    func_0062d1d0(this->m_14, tmp);
    return (int)this;
}
