// from server: 86% by colin
struct VColor3
{
    float r;
    float g;
    float b;
};

struct XItem
{
    VColor3 *convert(VColor3 *out);
};

VColor3 *XItem::convert(VColor3 *out)
{
    unsigned int packed = (*(unsigned int (__thiscall **)(void))((char *)this + 0xE8))();
    unsigned char r = (unsigned char)packed;
    unsigned char g = (unsigned char)(packed >> 8);
    unsigned char b = (unsigned char)(packed >> 16);
    out->r = (float)r / 255.0;
    out->g = (float)g / 255.0;
    out->b = (float)b / 255.0;
    return out;
}
