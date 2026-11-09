// from server: 32% by atomic.potato
typedef unsigned int DWORD;

extern "C" void __stdcall sub_556070();
extern "C" void __stdcall sub_638B70();
extern "C" void __stdcall sub_74B400();

struct NormalBreakConnector
{
    void *vtable;
    int field_4;
    int field_8;
    int field_c;
    char pad_10[0x60];
    float field_70;
    float field_74;
    float field_78;
    float field_7c;
    char field_80;
    char pad_81[0x27];

    NormalBreakConnector *ctor(void *a, void *b, void *c, float d, float e, float f, void *g);
};

NormalBreakConnector *NormalBreakConnector::ctor(void *a, void *b, void *c, float d, float e, float f, void *g)
{
    this->field_4 = -1;
    this->field_c = (int)c;
    this->vtable = (void *)0xa5162c;
    this->field_8 = (int)a;

    sub_556070();
    *(float *)((char *)this + 0x34) = *(float *)((char *)b + 0x24);
    *(float *)((char *)this + 0x38) = *(float *)((char *)b + 0x28);
    *(float *)((char *)this + 0x3c) = *(float *)((char *)b + 0x2c);

    sub_556070();
    *(float *)((char *)this + 0x64) = *(float *)((char *)g + 0x24);
    *(float *)((char *)this + 0x68) = *(float *)((char *)g + 0x28);
    *(float *)((char *)this + 0x6c) = *(float *)((char *)g + 0x2c);

    this->field_70 = e * d * d;
    this->field_74 = f;
    this->field_7c = 0.0f;
    this->field_80 = 0;

    sub_638B70();
    sub_638B70();

    sub_74B400();

    this->field_78 = 0.0f - this->field_74;

    return this;
}
