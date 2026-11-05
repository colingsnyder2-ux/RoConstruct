// from server: 91% by atomic.potato
struct CEnumPins
{
    char pad0[4];
    int field4;
    int field8;
    void *fieldC;
    int field10;
    char pad14[4];
    char field18;
    int f(void *);
};

extern "C" int __stdcall sub_4A33D0(void *);

int CEnumPins::f(void *arg)
{
    CEnumPins *self = (CEnumPins *)arg;
    void *p = self->fieldC;
    int r1 = ((int (__thiscall *)(void *))(*(void ***)p)[5])(p);
    self->field10 = r1;
    void *p2 = self->fieldC;
    int r2 = ((int (__thiscall *)(void *))(*(void ***)p2)[6])(p2);
    self->field8 = r2;
    self->field4 = 0;
    sub_4A33D0(&self->field18);
    return 0;
}
