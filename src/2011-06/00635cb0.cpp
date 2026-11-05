// from server: 100% by atomic.potato
extern unsigned char g_00ccc3af;

struct EventDesc
{
    void f(unsigned char value);
};

void EventDesc::f(unsigned char value)
{
    g_00ccc3af = value;
}
