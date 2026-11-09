// from server: 100% by atomic.potato
typedef unsigned char BYTE;

extern BYTE g_00ccc3b5;

struct EventDesc
{
    void SetValue(BYTE value);
};

void EventDesc::SetValue(BYTE value)
{
    g_00ccc3b5 = value;
}
