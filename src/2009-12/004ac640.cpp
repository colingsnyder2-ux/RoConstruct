// from server: 84% by atomic.potato
struct S
{
};

extern "C" void callee(void*, void*);

void __cdecl f(void* begin, void* end, void* arg)
{
    char* p = (char*)begin;
    char* q = (char*)end;
    while (p != q)
    {
        callee(p, arg);
        p += 0x50;
    }
}
