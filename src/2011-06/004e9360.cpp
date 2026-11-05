// from server: 100% by atomic.potato
struct PluginInterface2
{
    void setValue(unsigned char value);
};

void PluginInterface2::setValue(unsigned char value)
{
    *(unsigned char*)((char*)this + 0x12c) = value;
}
