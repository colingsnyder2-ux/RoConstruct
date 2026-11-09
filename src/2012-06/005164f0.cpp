// from server: 72% by atomic.potato
extern "C" void Call973130(void*, void*);

struct S
{
};

void __cdecl f(void* first, void* last)
{
    char* p = (char*)first;
    char* end = (char*)last;
    while (p != end)
    {
        Call973130(p, 0);
        p += 4;
    }
}
