// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00838578[];   // INFERRED: unnamed global at 0x00838578 in the original
extern "C" char g_00838588[];   // INFERRED: unnamed global at 0x00838588 in the original
extern "C" char g_00838598[];   // INFERRED: unnamed global at 0x00838598 in the original
extern "C" char g_008385a8[];   // INFERRED: unnamed global at 0x008385a8 in the original
extern "C" char g_008385b8[];   // INFERRED: unnamed global at 0x008385b8 in the original
extern "C" char g_008385c8[];   // INFERRED: unnamed global at 0x008385c8 in the original
extern "C" char g_008385d8[];   // INFERRED: unnamed global at 0x008385d8 in the original
extern "C" char g_008385e0[];   // INFERRED: unnamed global at 0x008385e0 in the original
extern "C" char g_008385e8[];   // INFERRED: unnamed global at 0x008385e8 in the original
extern "C" char g_008385f4[];   // INFERRED: unnamed global at 0x008385f4 in the original
// INFERRED: object is a multi-vtable class (vtables at 0x00,0x10,0x14,0x20,0x24,0x44,0x64,0x84,0xa4,0xc4); this is a destructor-style vtable reset followed by a tail call to the base-class routine.
extern "C" void fn_005bf0d0(void* self);

struct Local_005bf1f0
{
    unsigned long data[0x31];
};

extern "C" unsigned long g_0096dd10;

extern "C" void fn_005bf1f0(Local_005bf1f0* self)
{
    self->data[0] = ((int)&g_008385f4);
    self->data[4] = ((int)&g_008385e8);
    self->data[5] = ((int)&g_008385e0);
    self->data[8] = ((int)&g_008385d8);
    self->data[9] = ((int)&g_008385c8);
    self->data[17] = ((int)&g_008385b8);
    self->data[25] = ((int)&g_008385a8);
    self->data[33] = ((int)&g_00838598);
    self->data[41] = ((int)&g_00838588);
    self->data[49] = ((int)&g_00838578);
    g_0096dd10 = 0;
    fn_005bf0d0(self);
}
