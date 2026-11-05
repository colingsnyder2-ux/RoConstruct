// from server: 100% by atomic.potato
extern "C" int __declspec(dllimport) __cdecl omp_get_max_threads();

struct S
{
    int f();
};

int S::f()
{
    extern unsigned char g;
    if (g && *((unsigned char*)this + 0x0c) &&
        omp_get_max_threads() > 1)
        return 1;
    return 0;
}
