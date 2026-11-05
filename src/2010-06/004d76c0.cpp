// from server: 68% by atomic.potato
typedef double (__cdecl *ConvertFn)(void*);
typedef void (__thiscall *ApplyFn)(void*, void*, double*);

extern "C" double __cdecl func_004162a0(void*);

struct S_004d76c0 {
    void* f_0;
    char pad_4[24];
    void* f_1c;
    void f(void* a, void* b);
};

void S_004d76c0::f(void* a, void* b)
{
    double value = func_004162a0(b);
    void* vtable = *(void**)f_1c;
    ApplyFn apply = *(ApplyFn*)((char*)vtable + 0x10);
    apply(f_1c, a, &value);
}
