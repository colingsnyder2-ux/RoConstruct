// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_008147a4[];   // INFERRED: unnamed global at 0x008147a4 in the original
extern "C" char g_008147ac[];   // INFERRED: unnamed global at 0x008147ac in the original
extern "C" char g_0081480c[];   // INFERRED: unnamed global at 0x0081480c in the original
struct Local_0043d560 {
    void* vtbl;
    char pad[0x300]; // INFERRED: size covers offsets touched (0x20, 0x118)
};

extern "C" void* __fastcall fn_0043b400(Local_0043d560* self, int unusedEdx, int arg1, int arg2);

extern "C" Local_0043d560* __fastcall fn_0043d560(Local_0043d560* self, int unusedEdx, int arg1, int arg2)
{
    fn_0043b400(self, 0, arg1, arg2);
    // INFERRED: derived-class ctor resetting vtables (primary, +0x20, +0x118)
    *(void**)self = (void*)((int)&g_0081480c);
    *(void**)((char*)self + 0x20) = (void*)((int)&g_008147ac);
    *(void**)((char*)self + 0x118) = (void*)((int)&g_008147a4);
    return self;
}
