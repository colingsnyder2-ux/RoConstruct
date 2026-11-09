// from server: 100% by atomic.potato
struct S
{
    void f(void*, float*);
};

void S::f(void* object, float* value)
{
    char* base = (char*)object;
    if (base != 0)
        base -= 0x1c;
    else
        base = 0;

    void** table = *(void*** )((char*)this + 8);
    char* target = *(char**)((char*)this + 0xc);
    ((void (__thiscall *)(char*, float))table)(target + (int)base, *value);
}
