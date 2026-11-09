// from server: 100% by atomic.potato
extern unsigned char g_value;

struct EventDesc
{
    void set(unsigned char value);
};

void EventDesc::set(unsigned char value)
{
    g_value = value;
}
