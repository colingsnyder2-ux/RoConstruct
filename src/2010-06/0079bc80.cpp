// from server: 70% by atomic.potato
struct S;

extern "C" void __stdcall sub_4A5450(S*, void*);

struct S
{
    void* f(void*);
};

void* S::f(void* value)
{
    sub_4A5450((S*)((char*)this + 0x5c), value);
    return value;
}
