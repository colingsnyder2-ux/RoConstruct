// from server: 100% by colin
// from server: 97% by atomic.potato
typedef char BOOL;

extern "C" int __cdecl sub_7f5286(int);
extern "C" int (__thiscall *global_98b768)(void*, int);

struct S
{
    int pad0[3];
    void* data;
    char value();
};

char S::value()
{
    void* a = *(void**)((char*)this + 0x0C);
    a = *(void**)((char*)a + 0xA90);
    void* b = *(void**)((char*)a + 0x1B4);
    if (b)
        return global_98b768((void*)0xB3FF7C, sub_7f5286((int)b));
    return 0;
}