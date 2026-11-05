// from server: 83% by atomic.potato
extern unsigned long global_2cd102c;

struct TextBox
{
    unsigned char field_2a0;
    void setValue(unsigned char value);
};

void TextBox::setValue(unsigned char value)
{
    if (value != *((unsigned char*)this + 0x2a0))
    {
        *((unsigned char*)this + 0x2a0) = value;
        global_2cd102c = 0;
    }
}
