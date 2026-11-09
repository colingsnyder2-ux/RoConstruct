// from server: 95% by atomic.potato
struct S
{
    bool __thiscall f(int);
};

typedef bool (__thiscall *Method)(void *);

bool __thiscall S::f(int arg)
{
    if (*(unsigned char *)((char *)this + 0x266e) &&
        *(unsigned char *)((char *)this + 0x266c))
    {
        void **object = *(void ***)arg;
        Method method = (Method)object[2];
        if (!method((void *)arg))
            return true;
    }
    return false;
}
