// from server: 20% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" void __stdcall sub_675140();

struct S {
    char pad[0x38];
    int field38;
    int f(int a, int b, int c, int d);
};

int S::f(int a, int b, int c, int d) {
    int local = 0;
    if (a == 0) {
        InterlockedIncrement((long volatile*)0xc007a8);
        *(int*)b = 0;
        *(int*)(b + 4) = 0;
        return 0;
    }
    char buf[0x20];
    *(int*)buf = 0;
    int* p = (int*)c;
    int v = *p;
    if (v != 0) {
        *(int*)buf = v;
        int* q = (int*)c;
        int* r = (int*)(buf + 8);
        q += 2;
        int fn = *(int*)v;
        ((void (__stdcall*)(int*, int*, int))fn)(q, r, 0);
    }
    int e = d;
    int g = *(int*)(buf + 4);
    sub_675140();
    return g;
}
