// from server: 100% by EspClaude
// roc 2009-06 0066ad50  unit: RBX::Humanoid  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0066ad50
//

struct Humanoid {
    char pad[0x1e5];
    unsigned char field_x;
    void setFlag(unsigned char value);
};

void Humanoid::setFlag(unsigned char value)
{
    if (field_x != value)
    {
        field_x = value;
        extern void __stdcall notifyChange(unsigned long);
        notifyChange(0xa4d718);
    }
}
