// from server: 42% by colin
struct EnumDesc {
    void addPair(const char* name, int value);
    void dummy();
};

void EnumDesc::dummy()
{
    addPair("Laser", 7);
    addPair("QSUVWj", 0x83aebc);
}
