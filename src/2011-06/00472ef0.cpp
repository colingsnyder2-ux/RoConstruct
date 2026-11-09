// from server: 72% by atomic.potato
extern "C" void* __cdecl sub_472550(void*, void*, void*);

struct VerbBinder
{
};

void* __cdecl f(void* a, void* b)
{
    void* local = 0;
    sub_472550(b, &local, 0);
    return b;
}
