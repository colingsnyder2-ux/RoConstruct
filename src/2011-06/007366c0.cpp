// from server: 72% by atomic.potato
struct TextureContentProvider {
    char pad0[144];
    unsigned char m_value;
    void f(unsigned char value);
};

void TextureContentProvider::f(unsigned char value)
{
    if (m_value != value)
        m_value = value;
}
