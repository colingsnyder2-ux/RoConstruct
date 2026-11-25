// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
struct Local_00407ef0_Manager {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void release() = 0;
};

struct Local_00407ef0_Interface {
    virtual void __stdcall slot0() = 0;
    virtual void __stdcall slot1() = 0;
    virtual unsigned long __stdcall release() = 0;
};

void __cdecl operator delete(void*);

// INFERRED: layout from the disassembly; vtable addresses stored as raw dwords
struct Local_00407ef0 {
    unsigned long table0;
    unsigned long table4;
    unsigned long field8;
    unsigned long table12;
    Local_00407ef0_Interface* field16;
    unsigned long table20;
    unsigned long field24;
};

// INFERRED: global at 0x0096C268 is a pointer to a manager object
extern Local_00407ef0_Manager* g_0096C268;

extern "C" Local_00407ef0* __fastcall fn_00407ef0(Local_00407ef0* self, int unusedEdx, unsigned int flags)
{
    self->table0 = 0x0080B58C;
    self->table4 = 0x0080B574;
    self->table12 = 0x0080B558;
    self->table20 = 0x0080B50C;
    self->field24 = 0xC0000001;

    g_0096C268->release();

    if (self->field16)
        self->field16->release();

    if (flags & 1)
        operator delete(self);

    return self;
}
