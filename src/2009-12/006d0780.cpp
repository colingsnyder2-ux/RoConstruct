// from server: 100% by atomic.potato
extern "C" void __stdcall sub_0040C080(void*);

struct S
{
    int value;
    void set(int);
};

void S::set(int v)
{
    if (v != *(int*)((char*)this + 0x174))
    {
        *(int*)((char*)this + 0x174) = v;
        sub_0040C080((void*)0x00B928D0);
    }
}
