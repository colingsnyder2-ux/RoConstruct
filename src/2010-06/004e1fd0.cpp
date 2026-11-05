// from server: 67% by atomic.potato
extern "C" void __cdecl call_4e10d0(void*, void*);
extern "C" void call_4d91b0(void*, void*);

struct S
{
};

void* __cdecl f(void* a, void* b)
{
    call_4e10d0(b, a);
    b = (char*)b + 4;
    call_4d91b0(a, b);
    return a;
}
