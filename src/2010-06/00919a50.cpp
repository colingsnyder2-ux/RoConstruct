// from server: 28% by atomic.potato
struct GfxAttachement
{
    unsigned char f();
};

unsigned char GfxAttachement::f()
{
    return *((unsigned char*)this + 0x41);
}
