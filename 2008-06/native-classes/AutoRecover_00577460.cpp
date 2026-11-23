// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layout from raw offsets only; no native header found for this class.
struct DrawChangedArg { char flag; };

extern "C" void __fastcall fn_00575ba0(void* self, int unusedEdx, const GuiEvent* ev);
// Notifier<Workspace, DrawChanged>::raise (thiscall, 1 stack arg)
extern "C" void __fastcall fn_00576940(void* notifier, int unusedEdx, DrawChangedArg arg);

extern "C" void __fastcall fn_00577460(char* self, int unusedEdx, int* arg1)
{
    if (self[0x259]) {
        if (*arg1)
            fn_00575ba0((int)arg1);
        if (*(int*)(*(char**)(self + 0x20c) + 0x1b4) != 1) {
            DrawChangedArg d;
            d.flag = 0;
            fn_00576940(*(char**)(self + 0x204) + 0x344, 0, d);
        }
    }
}
