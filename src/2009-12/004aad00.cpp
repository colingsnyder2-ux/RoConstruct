// from server: 100% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    int* p = *(int**)((char*)this + 4);
    if (*(S**)((char*)p + 0x16c) == this)
        *(S**)((char*)p + 0x16c) = 0;
}
