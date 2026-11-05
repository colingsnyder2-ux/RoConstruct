// from server: 90% by atomic.potato
extern "C" void __fastcall sub_00982c1e(void*);

struct CMemberTreeView
{
    char pad0[0xf4];
    int field_f4;
    int field_f8;
    int field_fc;
    int field_100;
    int field_104;
    int field_108;
    int field_10c;
    int field_110;
    int field_114;
};

CMemberTreeView* __fastcall ctor(CMemberTreeView* self)
{
    sub_00982c1e(self);
    self->field_f4 = 0;
    self->field_f8 = 0;
    self->field_fc = 0;
    self->field_100 = 0;
    self->field_104 = 0;
    self->field_108 = 0;
    self->field_10c = 0;
    self->field_110 = 0;
    self->field_114 = 0;
    *(int*)self = 0xb52ca4;
    return self;
}
