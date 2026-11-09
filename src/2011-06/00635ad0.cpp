// from server: 100% by atomic.potato
unsigned char g_00ccc3a3;

struct EventDesc
{
    void SetValue(unsigned char value);
};

void EventDesc::SetValue(unsigned char value)
{
    g_00ccc3a3 = value;
}
