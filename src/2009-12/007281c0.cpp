// from server: 78% by atomic.potato
struct S
{
    void f();
};

void sub_00723b90(S*);

void S::f()
{
    S* p = *(S**)this;
    if (*(unsigned char*)((char*)p + 0x58) != 0)
    {
        sub_00723b90(p);
        *(unsigned char*)((char*)p + 0x58) = 0;
    }
}
