// from server: 27% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" void __stdcall func_00c007a8();

struct Inner {
    void* p0;
    void* p4;
};

struct Outer {
    char pad[0x38];
    int field38;
    void func(int a, int b, int c, int d);
};

void __stdcall func_006ca5b0(int, int);

void Outer::func(int a, int b, int c, int d) {
    if (a == 0) {
        func_00c007a8();
        Inner* r = (Inner*)b;
        r->p0 = 0;
        r->p4 = 0;
        return;
    }
    Inner local;
    local.p0 = 0;
    local.p4 = 0;
    int* src = (int*)d;
    if (*src != 0) {
        local.p0 = (void*)*src;
        int* vt = (int*)*src;
        void* fn = (void*)*(int*)vt;
        ((void (__stdcall*)(int*, int*, int))fn)(src + 2, (int*)&local.p4, 0);
    }
    int* out = (int*)b;
    func_006ca5b0(field38 + (a - 0x1c), (int)out);
    *out = (int)local.p0;
}
