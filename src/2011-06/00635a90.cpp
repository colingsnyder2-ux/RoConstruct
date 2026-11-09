// from server: 100% by atomic.potato
typedef unsigned char byte;

extern byte g_00ccc3a1;

struct EventDesc
{
    void f(byte value);
};

void EventDesc::f(byte value)
{
    g_00ccc3a1 = value;
}
