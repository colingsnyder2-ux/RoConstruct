// from server: 89% by atomic.potato
struct S
{
    void f(int);
    unsigned char pad[0xb4];
};

extern "C" void __stdcall call7737f0(void*, int, int);
extern "C" void __stdcall call40c080(void*, const void*);

void S::f(int value)
{
    call7737f0(*(void**)((char*)this + 0xb4), 1, value);
    call40c080(this, (const void*)0xb9579c);
}
