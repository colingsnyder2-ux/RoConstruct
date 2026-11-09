// from server: 74% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    struct T
    {
        int value[73];
    };

    T* p = *(T**)((char*)this + 12);
    int (*fn)(T*) = *(int (**)(T*))((char*)p + 288);
    T* q = (T*)((char*)p + 288);
    int result = fn(q);
    return ((int*)((char*)result + 324))[0] == 2;
}
