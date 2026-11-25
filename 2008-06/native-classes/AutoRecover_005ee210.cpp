// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_005ed620[];   // INFERRED: unnamed global at 0x005ed620 in the original
extern "C" char g_0097b11c[];   // INFERRED: unnamed global at 0x0097b11c in the original
struct Local_005ee210_Getter {
    virtual void slot0();
    virtual void slot1();
    virtual int get(int value);
};

struct Local_005ee210_EnumDesc {
    void convert(void* result, const int* value);
};

// INFERRED: callee types; real symbols are boost::call_once and a static enum descriptor accessor.
extern "C" void __cdecl fn_00557330(void (__cdecl* initializer)(), int* flag);
extern "C" Local_005ee210_EnumDesc* __cdecl fn_005ed5c0();
extern "C" void __cdecl fn_005ed620();

struct Local_005ee210_Self {
    char padding[28];
    Local_005ee210_Getter* getter;
};

extern "C" void* __fastcall fn_005ee210(Local_005ee210_Self* self, int unusedEdx, void* result, int value)
{
    volatile int state = 0;
    value = self->getter->get(value);
    fn_00557330(
        reinterpret_cast<void (__cdecl*)()>(((int)&g_005ed620)),
        reinterpret_cast<int*>(((int)&g_0097b11c)));
    Local_005ee210_EnumDesc* descriptor = fn_005ed5c0();
    descriptor->convert(result, &value);
    return result;
}
