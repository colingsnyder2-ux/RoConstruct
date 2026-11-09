// from server: 25% by colin
struct VColor3 {
    float r;
    float g;
    float b;
};

struct XItem {
    void setColor(const VColor3& color);
};

void XItem::setColor(const VColor3& color)
{
    unsigned int packed = 0;
    packed |= (unsigned int)(char)(int)(color.b * 255.0f);
    packed <<= 8;
    packed |= (unsigned int)(char)(int)(color.g * 255.0f);
    packed <<= 8;
    packed |= (unsigned int)(char)(int)(color.r * 255.0f);

    void (__thiscall *fn)(void*, unsigned int) =
        *(void (__thiscall **)(void*, unsigned int))(*(unsigned int*)this + 0xe4);
    fn(this, packed);
}
