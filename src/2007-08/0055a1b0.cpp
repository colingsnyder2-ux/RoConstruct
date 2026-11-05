// from server: 26% by colin
struct S {
    int f();
};

extern "C" void* __cdecl malloc(unsigned int);
extern "C" int __stdcall sub_5D4AD0(int);
extern "C" int __stdcall sub_55A100(int, int, int);

int S::f()
{
    int v = 0;
    char flag = 0;
    void* p = malloc(0x224);
    int q = 0;
    if (p) {
        sub_5D4AD0(1);
        q = (int)p;
    } else {
        q = 0;
    }
    int r = sub_55A100(q, v, 0);
    return r;
}
