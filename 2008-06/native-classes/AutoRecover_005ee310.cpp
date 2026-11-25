// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the target is a thiscall member (this in ecx, ret 4). A free __stdcall function cannot read ecx, so it is written as a member of a file-local type.
// INFERRED: the linker alternatename below exposes it under the fn_005ee310 stdcall symbol.

struct Local_005ee310_Source {
    virtual void slot0();
    virtual void slot1();
    virtual unsigned int get(void*);
};

struct Local_005ee310_Table {
    char padding[0xdc];
    int* begin;
    int* volatile end;
};

extern "C" void __cdecl fn_00557330(void (__cdecl*)(), int*);
extern "C" Local_005ee310_Table* __cdecl fn_005ed630();
extern "C" void (__cdecl* _invalid_parameter_noinfo)();

struct Local_005ee310_Self {
    char padding[0x1c];
    Local_005ee310_Source* source;
    int lookup(void* object);
};

#pragma comment(linker, "/alternatename:_fn_005ee310@4=?lookup@Local_005ee310_Self@@QAEHPAX@Z")

int Local_005ee310_Self::lookup(void* object)
{
    unsigned int index = source->get(object);
    fn_00557330(
        reinterpret_cast<void (__cdecl*)()>(0x5ed690),
        reinterpret_cast<int*>(0x97b120));
    Local_005ee310_Table* table = fn_005ed630();

    if (index < static_cast<unsigned int>(table->end - table->begin)) {
        if (index >= static_cast<unsigned int>(table->end - table->begin))
            _invalid_parameter_noinfo();
        return table->begin[index];
    }

    return -1;
}
