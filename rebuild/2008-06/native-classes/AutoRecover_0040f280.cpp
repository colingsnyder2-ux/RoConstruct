// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layout and vtable constants taken from the server-verified analog; real class unknown.
struct Local_0040f280_Iface
{
    virtual void slot0() = 0;
    virtual void slot1() = 0;
};

struct Local_0040f280
{
    unsigned int table0;
    unsigned int table4;
    volatile unsigned int table8;
    unsigned int valueC;
    unsigned int value10;
    unsigned int table14;
    unsigned int value18;
    volatile unsigned short value1C;
};

extern "C" Local_0040f280_Iface* g_0096c268;

extern "C" Local_0040f280* __fastcall fn_0040f280(Local_0040f280* self, int unusedEdx, int arg)
{
    self->value18 = 0;
    self->value10 = 0;
    self->valueC = 0;
    self->table8 = 0x80D388;
    self->value1C = 0;
    self->table0 = 0x80D638;
    self->table4 = 0x80D620;
    self->table8 = 0x80D5FC;
    self->table14 = 0x80D5D4;
    g_0096c268->slot1();
    return self;
}
