// from server: 37% by atomic.potato
struct GfxAttachement
{
    void SetValue(unsigned char value);
};

void GfxAttachement::SetValue(unsigned char value)
{
    ((unsigned char*)this)[0x41] = value;
}
