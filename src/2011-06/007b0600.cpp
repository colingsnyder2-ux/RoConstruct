// from server: 57% by atomic.potato
struct ManualJointSurfacePair {
    void* vfptr;              // 0x00
    int field_04;             // 0x04
    int field_08;             // 0x08
    int field_0c;             // 0x0c
    int field_10;             // 0x10
    char pad_14[0x04];        // 0x14..0x17
    int field_18;             // 0x18
    char pad_1c[0x04];        // 0x1c..0x1f
    int field_20;             // 0x20
    int field_24;             // 0x24
    int field_28;             // 0x28
    char pad_2c[0x04];        // 0x2c..0x2f
    int field_30;             // 0x30
    int field_34;             // 0x34
    int field_38;             // 0x38
    int field_3c;             // 0x3c

    ManualJointSurfacePair(int arg);
};

extern "C" void __stdcall sub_58a6f0(int, ManualJointSurfacePair*);

ManualJointSurfacePair::ManualJointSurfacePair(int arg)
{
    this->field_04 = -1;
    this->field_08 = -1;
    this->field_0c = -1;
    this->field_10 = 0;
    this->vfptr = (void*)0xabd110;
    this->field_20 = 0;
    this->field_24 = 0;
    this->field_28 = 0;
    this->field_30 = 0;
    this->field_34 = 0;
    this->field_38 = 0;
    *(char*)((char*)this + 0x14) = 0;
    *(char*)((char*)this + 0x15) = 0;
    this->field_3c = 0;
    this->field_18 = arg;
    sub_58a6f0(*(int*)(arg + 0x170), this);
    *(char*)((char*)this + 0x15) = 1;
}
