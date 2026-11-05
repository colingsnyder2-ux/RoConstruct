// from server: 100% by atomic.potato
extern unsigned char g_00cd6198;

struct EventDesc
{
    void f(unsigned char value);
};

void EventDesc::f(unsigned char value)
{
    g_00cd6198 = value;
}
