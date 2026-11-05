// from server: 100% by atomic.potato
extern "C" int __stdcall sub_0080a7cc(void*);

struct CChildFrame
{
    char pad0[0x10];
    int field_10;
    int field_14;
    int field_18;
    int field_1c;
    unsigned int field_20;
};

int __stdcall init(CChildFrame* self)
{
    self->field_18 = 0;
    self->field_1c = 0;
    self->field_10 = 0x7fff;
    self->field_14 = 0x7fff;
    if (sub_0080a7cc(self) == 0)
        return 0;
    self->field_20 |= 0x2000000;
    return 1;
}
