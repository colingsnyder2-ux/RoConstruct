// from server: 70% by atomic.potato
struct VPlayerBoundFuncDesc {
    char pad0[0x30];
    int (__stdcall *fn)(void*);
    char* ctx;
    char field38;
    int invoke(void* a, void* b);
};

extern "C" int __stdcall sub_532a10(void*, void*, int);

int VPlayerBoundFuncDesc::invoke(void* a, void* b)
{
    int r = sub_532a10(a, &field38, 0);
    if (b) {
        int (__stdcall *f)(void*) = fn;
        char* c = ctx;
        c += (int)b - 0x1c;
        return f(c);
    } else {
        int (__stdcall *f)(void*) = fn;
        char* c = ctx;
        return f(c);
    }
}
