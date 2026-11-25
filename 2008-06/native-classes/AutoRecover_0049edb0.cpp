// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00822d8c[];
extern "C" char g_00822d98[];
extern "C" char g_00822dc8[];
extern "C" char g_00822dd8[];
extern "C" char g_00822de8[];
extern "C" char g_00822df8[];
extern "C" char g_00822e08[];
extern "C" char g_00822e18[];
extern "C" char g_00822e28[];
extern "C" char g_00822e30[];
extern "C" char g_00822e38[];
extern "C" char g_00822e44[];

// INFERRED: the object is a multiple-inheritance class with 12 vtable-pointer
// stores; its real type is unknown, so a raw dword layout stands in for it.
struct Local_0049edb0
{
    unsigned long data[78];
};

// INFERRED: the callee takes the object in ecx (thiscall, no stack args).
extern "C" void __fastcall fn_004ac830(Local_0049edb0* self);

// INFERRED: the ABI check requires __cdecl. The original reads the object from ecx.
extern "C" void __cdecl fn_0049edb0(Local_0049edb0* self)
{
    self->data[0]  = (unsigned)g_00822e44;
    self->data[4]  = (unsigned)g_00822e38;
    self->data[5]  = (unsigned)g_00822e30;
    self->data[8]  = (unsigned)g_00822e28;
    self->data[9]  = (unsigned)g_00822e18;
    self->data[17] = (unsigned)g_00822e08;
    self->data[25] = (unsigned)g_00822df8;
    self->data[33] = (unsigned)g_00822de8;
    self->data[41] = (unsigned)g_00822dd8;
    self->data[49] = (unsigned)g_00822dc8;
    self->data[76] = (unsigned)g_00822d98;
    self->data[77] = (unsigned)g_00822d8c;
    fn_004ac830(self);
}
