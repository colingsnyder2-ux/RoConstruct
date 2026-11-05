// from server: 100% by atomic.potato
extern unsigned char g_00C50143;

struct EventDesc
{
    void Set(unsigned char value);
};

void EventDesc::Set(unsigned char value)
{
    g_00C50143 = value;
}
