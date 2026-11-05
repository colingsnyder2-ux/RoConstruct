// from server: 95% by atomic.potato
extern "C" void __cdecl sub_0040C080(const char*);

struct S
{
    void f(const char*);
};

void S::f(const char* value)
{
    if (*(const char**)((char*)this + 0x1BC) != value)
    {
        *(const char**)((char*)this + 0x1BC) = value;
        sub_0040C080("T$$VP");
    }
}
