// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

struct Local_00401ab0_Iface {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
};

struct Local_00401ab0 {
    unsigned long field00;
    unsigned long field04;
    unsigned long field08;
    unsigned long field0C;
    unsigned long field10;
    unsigned long field14;
    unsigned long field18;
    unsigned long field1C;
    unsigned long field20;
};

// Callees take only ecx (original thiscall never sets edx), so declare one-arg fastcall.
extern "C" void __fastcall fn_0046b740(Local_00401ab0* self);
extern "C" void __fastcall fn_0046a9b0(Local_00401ab0* self);
extern Local_00401ab0_Iface* g_0096c268;

extern "C" void __fastcall fn_00401ab0(Local_00401ab0* self, int unusedEdx)
{
    self->field00 = 0x0080AE6C;
    self->field04 = 0x0080AE58;
    self->field08 = 0x0080AE40;
    self->field10 = 0x0080AE24;
    self->field18 = 0x0080AE18;
    self->field1C = 0x0080AE0C;
    self->field20 = 0xC0000001;
    fn_0046b740(self);
    g_0096c268->slot2();
    fn_0046a9b0(self);
}
