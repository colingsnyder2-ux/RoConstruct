// from server: 37% by atomic.potato
struct GfxAttachement
{
    void f(unsigned char value);
};

void GfxAttachement::f(unsigned char value)
{
    *(unsigned char*)((char*)this + 0x41) = value;
}
