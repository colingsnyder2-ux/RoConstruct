// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_008232b4[];
extern "C" char g_008232c0[];
extern "C" char g_008232f0[];
extern "C" char g_00823300[];
extern "C" char g_00823310[];
extern "C" char g_00823320[];
extern "C" char g_00823330[];
extern "C" char g_00823340[];
extern "C" char g_00823350[];
extern "C" char g_00823358[];
extern "C" char g_00823360[];
extern "C" char g_0082336c[];
// INFERRED: the object is a multiple-inheritance class whose vtable pointers are reset
// before tail-jumping into the shared base cleanup (fn_004ac830).
// INFERRED: the original takes the object in ecx (thiscall-like), but the ABI check
// classifies it as __cdecl because it has no ret, so it is declared plain cdecl here.
struct Local_004a1580 {
    unsigned int data[78];
};

extern "C" void fn_004ac830(Local_004a1580* self);

extern "C" void fn_004a1580(Local_004a1580* self)
{
    self->data[0]  = (unsigned)g_0082336c;
    self->data[4]  = (unsigned)g_00823360;
    self->data[5]  = (unsigned)g_00823358;
    self->data[8]  = (unsigned)g_00823350;
    self->data[9]  = (unsigned)g_00823340;
    self->data[17] = (unsigned)g_00823330;
    self->data[25] = (unsigned)g_00823320;
    self->data[33] = (unsigned)g_00823310;
    self->data[41] = (unsigned)g_00823300;
    self->data[49] = (unsigned)g_008232f0;
    self->data[76] = (unsigned)g_008232c0;
    self->data[77] = (unsigned)g_008232b4;
    fn_004ac830(self);
}
