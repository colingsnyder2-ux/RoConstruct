// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0097b11c[];
// INFERRED: Local_005ee860 stands in for the unnamed owner class; member at +0x1c is an object with a vtable whose slot 3 (+0xc) is the setter.
struct Local_005ee860_Setter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(const void* object, const int* value);
};

struct Local_005ee860 {
    unsigned char pad[0x1c];
    Local_005ee860_Setter* access;
};

// INFERRED: fn_005ed300 is a true __thiscall member (ecx only, no edx setup in caller).
struct Local_005ee860_Table {
    bool fn_005ed300(const void* name, int* out);
};

extern "C" void __cdecl fn_00557330(void (__cdecl*)(), long*);
extern "C" void __cdecl fn_005ed620();
extern "C" Local_005ee860_Table* __cdecl fn_005ed5c0();

extern "C" bool __fastcall fn_005ee860(Local_005ee860* self, int unusedEdx, const void* object, const void* name)
{
    int value;
    fn_00557330(fn_005ed620, reinterpret_cast<long*>(g_0097b11c));
    Local_005ee860_Table* table = fn_005ed5c0();
    if (table->fn_005ed300(name, &value)) {
        self->access->set(object, &value);
        return true;
    }
    return false;
}
