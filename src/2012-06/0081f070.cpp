// from server: 85% by atomic.potato
struct S_func_0081f070 {
    char pad0[8];
    char m_field8;

    void f(void* a, void* b);
};

extern "C" void __stdcall sub_0081ee90(S_func_0081f070* a, void* b);

void S_func_0081f070::f(void* a, void* b)
{
    char* p1 = (char*)a;
    char* p2 = (char*)b;
    if (p1[0x115] == 0) {
        unsigned char al = (unsigned char)p1[0x94];
        unsigned char cl = al;
        cl = (unsigned char)(cl + 1);
        cl = (unsigned char)(cl ^ al);
        cl = (unsigned char)(cl & 0xf);
        cl = (unsigned char)(cl ^ al);
        p1[0x94] = (char)cl;
    }
    if (p2[0x115] == 0) {
        unsigned char al = (unsigned char)p2[0x94];
        unsigned char cl = al;
        cl = (unsigned char)(cl + 1);
        cl = (unsigned char)(cl ^ al);
        cl = (unsigned char)(cl & 0xf);
        cl = (unsigned char)(cl ^ al);
        p2[0x94] = (char)cl;
    }
    sub_0081ee90((S_func_0081f070*)((char*)this + 8), b);
}
