// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layout from disassembly offsets; no native header for Players members used here.
struct Local_00492320_Players {
    char padding[0x1a0];
    char* localPlayer;
};

// ServiceProvider::find<Players> is __thiscall (ecx = provider, no edx use): one-arg __fastcall.
extern "C" Local_00492320_Players* __fastcall fn_004125d0(void* serviceProvider);
extern "C" const void* __cdecl fn_004898d0(const void* instance);
extern "C" double __cdecl fn_00508410(void);

extern "C" void __cdecl fn_00492320(void* serviceProvider)
{
    Local_00492320_Players* players = fn_004125d0(serviceProvider);
    if (players) {
        // INFERRED: member at 0x1a0 is an Instance*, 0x1d0 double lives on that object.
        char* inst = players->localPlayer;
        if (inst && fn_004898d0(inst))
            *(double*)(inst + 0x1d0) = fn_00508410();
    }
}
