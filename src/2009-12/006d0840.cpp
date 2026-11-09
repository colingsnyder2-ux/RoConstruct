// from server: 68% by atomic.potato
extern "C" void __stdcall sub_0040C080(void*);

struct S
{
    char pad[0x170];
    int value;
    void set(int);
};

void S::set(int v)
{
    if (v != *(int*)((char*)this + 0x170))
    {
        *(int*)((char*)this + 0x170) = v;
        sub_0040C080((void*)0x00B92AA8);
        sub_0040C080((void*)0x00B92788);
    }
}
