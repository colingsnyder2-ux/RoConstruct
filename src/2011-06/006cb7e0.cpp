// from server: 75% by atomic.potato
struct TextBox
{
    void f(unsigned char value);
};

extern "C" void __cdecl SetTextBoxValue(int);

void TextBox::f(unsigned char value)
{
    if (value != *(unsigned char *)((char *)this + 0x24f))
    {
        *(unsigned char *)((char *)this + 0x24f) = value;
        SetTextBoxValue(0xcd10b8);
    }
}
