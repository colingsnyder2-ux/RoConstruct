// from server: 57% by atomic.potato
extern "C" void __cdecl Function_00926ca0(int, int, int);

struct S
{
};

int __cdecl f(void* a, void* b, void* c)
{
    int (**vtable)(void*, void*) = (int (**)(void*, void*))*(void**)((char*)a + 0x54);
    int result = vtable[0x3c / 4](b, c);
    if (result != (int)c)
        Function_00926ca0(0x0e, -1, 0);
    return result;
}
