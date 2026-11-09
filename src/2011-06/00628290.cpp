// from server: 100% by atomic.potato
struct EventDesc
{
    void f(int);
    void g();
};

void EventDesc::f(int)
{
    if (*(unsigned char *)((char *)this + 0x11a))
        g();
}
