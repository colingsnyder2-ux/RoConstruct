// from server: 100% by atomic.potato
typedef unsigned char BYTE;

extern "C" BYTE g_00ccc39f;

struct EventDesc
{
    void f(BYTE value);
};

BYTE g_00ccc39f;

void EventDesc::f(BYTE value)
{
    g_00ccc39f = value;
}
