// from server: 48% by atomic.potato
struct S_func_008df2c0 {
    char pad0[0x30];
    int m_30;
    int m_34;
    void f(int, int);
};

extern "C" int __cdecl sub_0076d9f0(int);
extern "C" void __cdecl sub_008df000(int, int, int);
extern "C" void __cdecl sub_00972290(int, int);
extern "C" int (__cdecl *off_e5809c)(int, int, int);
extern "C" unsigned char byte_e580b3;

void S_func_008df2c0::f(int a, int b)
{
    if (byte_e580b3 != 0) {
        int ecx = *(int*)(a + 8) - *(int*)(a + 4);
        int eax = (int)((long long)ecx * 0x78787879 >> 32);
        eax = (eax >> 5) + ((unsigned)eax >> 31);
        if (eax == 2) goto L325;
        if (off_e5809c != 0) {
            if (off_e5809c(0x111, 0xb70328, 0xb70a94)) goto L325;
        }
        sub_00972290(byte_e580b3, 0xb70a20);
    }
L325:
    int esi;
    if (b != 0) esi = b - 0x1c; else esi = 0;
    int* p1 = (int*)sub_0076d9f0(*(int*)(a + 4) + 0x48);
    int ebx = *p1;
    int* p2 = (int*)sub_0076d9f0(*(int*)(a + 4) + 4);
    int eax2 = *p2;
    int edx = *(int*)(esi + 0x84);
    int ecx = *(int*)(edx + m_34) + m_30;
    sub_008df000(ecx + esi + 0x84, eax2, ebx);
}
