// from server: 100% by tester
typedef unsigned char BYTE;

BYTE g_value;

struct EventDesc
{
    void set(BYTE value);
};

void EventDesc::set(BYTE value)
{
    g_value = value;
}
