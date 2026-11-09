// from server: 72% by colin
struct S_0075dd20 {
    void m();
};

extern "C" void __stdcall f_00630a1e(int);
extern "C" void __stdcall f_00630a18();

void S_0075dd20::m()
{
    int v = *(int *)((char *)this - 0x38);
    v ^= (int)this;
    f_00630a1e(v);
    f_00630a18();
}
