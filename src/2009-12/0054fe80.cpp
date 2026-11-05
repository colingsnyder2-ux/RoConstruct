// from server: 57% by atomic.potato
struct S_func_007b2f20
{
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_007b2f20::f(int a1)
{
    m_x = a1;
}

struct FilePacketLogger
{
    void f(int a1);
};

void FilePacketLogger::f(int a1)
{
    S_func_007b2f20 *p;
    p = (S_func_007b2f20 *)this;
    p->f(a1);
    void (**vtable)(FilePacketLogger *);
    vtable = *(void (***)(FilePacketLogger *))this;
    vtable[13](this);
}
