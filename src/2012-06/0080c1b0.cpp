// from server: 37% by atomic.potato
struct S_func_0080c1b0 {
    char pad0[0x28];
    int m_28;
    int m_2c;
    int m_30;
    void f(int, int, int, int, int, int, int, int, int);
};

struct S_sub_6cb9e0 {
    void g(int, int, int, int, int, int);
};

extern "C" void __stdcall sub_4015a0(int, int);
extern "C" int __cdecl sub_737990();
extern "C" int __cdecl sub_73a2c0();
extern "C" int __cdecl sub_80b420(int);
extern "C" void __cdecl sub_982114(int);
extern "C" void __cdecl sub_972290(int, int);
extern "C" int __cdecl sub_b229ec(int);

void S_func_0080c1b0::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
    sub_4015a0(0xe344e0, 0x7379f0);
    int edi = sub_737990();
    sub_73a2c0();
    ((S_sub_6cb9e0*)this)->g(a1, edi, a2, a3, a4, a5);
    m_28 = edi;
    m_2c = 0;
    *(int*)this = 0xbc4eec;
    int* p = (int*)sub_80b420(a6);
    m_2c = *p;
    *p = 0;
    sub_982114(a7);
    sub_4015a0(0xe344e0, 0x7379f0);
    m_30 = sub_737990();
    if (*(char*)0xe580b3 != 0) {
        if (!sub_b229ec(0xdd9fd8)) {
            int fn = *(int*)0xe5809c;
            if (fn != 0) {
                if (((char(__cdecl*)(int,int,int))fn)(0xb44978, 0xb58618, 0xd4))
                    return;
            }
            sub_972290(*(unsigned char*)0xe580b3, 0xb587b8);
        }
    }
}
