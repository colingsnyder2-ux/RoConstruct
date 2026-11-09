// from server: 30% by atomic.potato
struct TextBox
{
    char padding[0x238];
    float value;
    void setValue(float);
};

void TextBox::setValue(float v)
{
    if (value != v)
        value = v;
}
