// from server: 100% by atomic.potato
struct CChildFrame
{
    char pad0[0x10];
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
};

extern "C" int __stdcall sub_007191a6(CChildFrame*);

int __stdcall Init(CChildFrame* self)
{
    self->field18 = 0;
    self->field1c = 0;
    self->field10 = 0x7fff;
    self->field14 = 0x7fff;
    if (sub_007191a6(self) == 0)
        return 0;
    self->field20 |= 0x2000000;
    return 1;
}
