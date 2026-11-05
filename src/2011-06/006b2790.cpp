// from server: 84% by atomic.potato
struct GuiButton
{
    void SetFlag(unsigned char value);
};

void GuiButton::SetFlag(unsigned char value)
{
    *(unsigned char*)((char*)this + 0x180) = value;
}
