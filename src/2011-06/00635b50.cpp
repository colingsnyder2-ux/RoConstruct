// from server: 100% by atomic.potato
typedef unsigned char BYTE;

extern BYTE g_00cd6199;

struct EventDesc
{
    void f(BYTE value);
};

void EventDesc::f(BYTE value)
{
    g_00cd6199 = value;
}
