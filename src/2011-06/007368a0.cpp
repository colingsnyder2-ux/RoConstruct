// from server: 100% by atomic.potato
struct EventDesc
{
    void Set(unsigned short, unsigned short);
    unsigned short a[75];
};

void EventDesc::Set(unsigned short x, unsigned short y)
{
    a[73] = x;
    a[74] = y;
}
