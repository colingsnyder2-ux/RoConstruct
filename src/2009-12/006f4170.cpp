// from server: 74% by atomic.potato
struct FaceInstance
{
    char padding[164];
    int field_a4;
    void setValue(int value);
};

extern "C" void __stdcall sub_40c080(int, int);

void FaceInstance::setValue(int value)
{
    if (field_a4 != value)
    {
        field_a4 = value;
        sub_40c080(0x00B946BC, 0);
    }
}
