// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the by-value 16-byte argument and the embedded member at +8 are the same
// container type (vptr, count, buffer, capacity). Its real name is unknown.
struct Table16 {
    void* vptr;
    int   count;
    void* buffer;
    int   capacity;
};

// INFERRED: the owning class is unknown. Layout is taken from the disassembly.
struct Obj {
    int     field0;   // +0x00
    int     field4;   // +0x04
    Table16 table;    // +0x08
    int     field18;  // +0x18
};

extern "C" void* __cdecl fn_00508580(unsigned size, unsigned align);          // G3D::System::alignedMalloc
extern "C" void  __cdecl fn_00508a30(void* p, int value, unsigned count);     // G3D::System::memset
extern "C" int __fastcall fn_004d7e30(void* self, int unusedEdx);
extern "C" int __fastcall fn_004e7880(void* self, int unusedEdx, int a1);

// INFERRED: vtable of the table type (unknown global at the original address 0x826c0c).
extern "C" char g_00826c0c[];

extern "C" Obj* __fastcall fn_004e8940(Obj* self, int unusedEdx, int arg1, Table16 src, int arg6, int arg7)
{
    self->field4 = 0;
    self->table.vptr = (void*)g_00826c0c;
    self->table.capacity = 10;
    self->table.count = 0;
    self->table.buffer = fn_00508580(0x28, 0x10);
    fn_00508a30(self->table.buffer, 0, (unsigned)self->table.capacity * 4);

    self->field4 = arg1;
    if (&self->table != &src) {
        fn_004d7e30(&self->table, 0);
        fn_004e7880(&self->table, 0, (int)&src);
    }
    self->field0 = arg6;
    self->field18 = arg7;

    src.vptr = (void*)g_00826c0c;
    fn_004d7e30(&src, 0);
    return self;
}
