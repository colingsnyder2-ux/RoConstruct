// from server: 76% by atomic.potato
struct PlayerGui
{
    void setValue(unsigned char value);
};

void PlayerGui::setValue(unsigned char value)
{
    if (*(unsigned char*)((char*)this + 0xad) != value)
    {
        *(unsigned char*)((char*)this + 0xad) = value;
        *(int*)0x40c080 = 0xb94bc0;
    }
}
