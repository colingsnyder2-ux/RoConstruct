// from server: 46% by atomic.potato
extern "C" long __declspec(dllimport) __stdcall InterlockedExchange(long *, long);
extern "C" void __stdcall _invalid_parameter_noinfo();

struct Inner {
    char pad[0x18];
};

struct S {
    char pad0[0xc];
    unsigned int m_c;
    unsigned int m_10;
    char pad1[0x4];
    Inner m_18;
    void sub_72d760(unsigned int);
    void sub_72c040(unsigned int, unsigned int, unsigned int, unsigned int);
    void f(unsigned int);
};

void sub_7e1e30(void *, void *);
void sub_7e1e80(void *);

void S::f(unsigned int arg)
{
    Inner local;
    sub_7e1e30(&local, &m_18);
    sub_72d760(arg);
    unsigned int ebx = m_10;
    if (m_c > ebx)
        _invalid_parameter_noinfo();
    unsigned int edi = m_c;
    unsigned int ebp = *(unsigned int *)this;
    if (edi > m_10)
        _invalid_parameter_noinfo();
    unsigned int esi = *(unsigned int *)this;
    sub_72c040(esi, edi, ebp, ebx);
    sub_7e1e80(&local);
}
