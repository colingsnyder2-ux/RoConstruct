// from server: 39% by tester
struct S_func_0080bc30 {
    char pad0[0x28];
    int m_28;
    int m_2c;
    int m_30;
    void f(int a, int b, int c, int d, int e, int f, int g, int h, int i);
};

extern "C" int __cdecl func_004015a0(int, int);
extern "C" int __cdecl func_00737920();
extern "C" int __cdecl func_0073a2c0();
extern "C" int __cdecl func_006cb9e0();
extern "C" int __cdecl func_0080b290();
extern "C" int __cdecl func_00982114(int);
extern "C" int __cdecl func_00972290(int, int);
extern "C" int __cdecl func_00b229ec(int, int);

extern unsigned char g_e580b3;
extern int g_e5809c;

void S_func_0080bc30::f(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    func_004015a0(0xe344dc, 0x737980);
    int v1 = func_00737920();
    func_0073a2c0();
    func_006cb9e0();
    m_28 = v1;
    *(int*)this = 0xbc4dcc;
    int* p = (int*)func_0080b290();
    int v2 = *p;
    *p = 0;
    m_2c = v2;
    func_00982114(i);
    func_004015a0(0xe344dc, 0x737980);
    m_30 = func_00737920();
    if (g_e580b3 != 0) {
        if (func_00b229ec(0xdd9fd8, 0xdd9fd8) == 0) {
            if (g_e5809c != 0) {
                if (func_00b229ec(0xb44978, 0xb58618) != 0)
                    return;
            }
            func_00972290(g_e580b3, 0xb587b8);
        }
    }
}
