// from server: 40% by atomic.potato
struct GfxAttachement
{
    int getValue();
};

int GfxAttachement::getValue()
{
    volatile unsigned int value = *(unsigned int*)this;
    if (value >= 0x3d09000)
        return 0x400;
    return 0x200;
}
