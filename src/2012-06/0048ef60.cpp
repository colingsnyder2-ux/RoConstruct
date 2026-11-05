// from server: 100% by atomic.potato
struct Inner
{
    void method(bool b);
};

struct Outer
{
    int pad[3];
    Inner* ptr;
};

int __stdcall sub_48EF60(Outer* outer, short flag)
{
    Inner* p = outer->ptr;
    if (p == 0)
        return (int)0x80004005;
    p->method(flag);
    return 0;
}
