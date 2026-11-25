// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_005ed690[];
extern "C" char g_0097b120[];
// INFERRED: layout from analog; self+0x1c is a getset object with vtable slot 3 (setValue).
struct Local_005ee970_Desc {
    bool __thiscall convertToValue(const void* name, int* out) const;
};

struct Local_005ee970_GetSet {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void setValue(void* instance, const int* value);
};

struct Local_005ee970_Self {
    char pad[0x1c];
    Local_005ee970_GetSet* getset;
};

extern "C" void __cdecl fn_00557330(void* a, void* b);
extern "C" Local_005ee970_Desc* __cdecl fn_005ed630();

extern "C" bool __fastcall fn_005ee970(Local_005ee970_Self* self, int unusedEdx, void* instance, const void* name)
{
    fn_00557330((void*)(unsigned)g_005ed690, (void*)(unsigned)g_0097b120);
    Local_005ee970_Desc* desc = fn_005ed630();
    int value;
    if (desc->convertToValue(name, &value)) {
        self->getset->setValue(instance, &value);
        return true;
    }
    return false;
}
