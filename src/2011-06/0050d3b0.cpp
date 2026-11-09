// from server: 44% by atomic.potato
struct S_func_0050d3b0 {
    char pad[0xae8];
    unsigned int field_ae8;
    bool f(unsigned int a, unsigned int b, unsigned int c, unsigned int d);
};

extern "C" void __cdecl G1_func_007fb760(void*);
extern "C" void __cdecl G2_func_007fb580(void*, void*);
extern "C" bool __cdecl G3_func_0052a350(void*, unsigned int, unsigned int, unsigned int, unsigned int);
extern "C" void __cdecl G4_func_004f6440(void*);
extern "C" void __cdecl G5_func_004ed970(void*, double);

bool S_func_0050d3b0::f(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    char buf1[8];
    char buf2[8];
    G1_func_007fb760(buf1);
    bool r = G3_func_0052a350(this, a, b, c, d);
    G1_func_007fb760(buf2);
    G2_func_007fb580(buf2, buf1);
    unsigned int* p = (unsigned int*)((char*)this->field_ae8 + 0xa8);
    G4_func_004f6440((char*)p + 0x28);
    double v;
    *(unsigned int*)&v = c;
    *((unsigned int*)&v + 1) = d;
    G5_func_004ed970(p, v);
    return r;
}
