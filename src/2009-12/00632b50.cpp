// from server: 100% by atomic.potato
struct S
{
    void f(void*, int);
};

void S::f(void* p, int value)
{
    int* current = *(int**)((char*)p + 4);
    while (current != 0)
    {
        typedef void (__thiscall S::*Method)(int*, int);
        Method method = *(Method*)((char*)*(void**)this + 0x44);
        (this->*method)(current, value);
        current = *(int**)current;
    }
}
