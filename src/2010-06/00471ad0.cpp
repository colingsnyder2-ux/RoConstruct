// from server: 96% by atomic.potato
struct CFont {
    int GetValue();
    unsigned char pad[220];
    unsigned char field_dc;
    unsigned char field_dd;
    int field_d4;
};

int CFont::GetValue()
{
    if (field_dc != 0) {
        if (field_dd != 0)
            return field_d4;
        return 0x00c1c248;
    }
    return field_d4;
}
