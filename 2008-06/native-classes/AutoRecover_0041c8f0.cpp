// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0080ee30[];   // INFERRED: unnamed global at 0x0080ee30 in the original

// Thiscall helper with 0 stack args, modelled as __fastcall with only the object pointer (ecx).
extern "C" void __fastcall fn_00497740(void* self);
// StringConverter<CoordinateFrame>::convertToValue analog: 1 pushed arg, caller pops.
extern "C" bool __cdecl fn_0060a2f0(const void* a1);
extern "C" void* __cdecl fn_006a0920(unsigned int a1);
// The caller pops all pushes ("add esp, 0xc" covers the 0x30 push plus these two), so this is cdecl.
extern "C" void __cdecl fn_00419010(void* a1, const void* a2);

// INFERRED: shared-pointer-like dword at stack offset 8 of the by-value argument block,
// destroyed by the callee (fn_00497740 on [esp+0x20]).
struct Local_0041c8f0_Shared {
    unsigned int object;
    ~Local_0041c8f0_Shared() { fn_00497740(this); }
};

// INFERRED: object layout from the stores at [esi], [esi+8].
struct Local_0041c8f0_Self {
    const void* manager;
    unsigned int reserved;
    void* storage;
};

// INFERRED: the 13 stack dwords form one contiguous by-value argument block;
// only the dword at offset 8 has a destructor.
extern "C" Local_0041c8f0_Self* __fastcall fn_0041c8f0(Local_0041c8f0_Self* self, int unusedEdx,
                                                     unsigned int a1, unsigned int a2,
                                                     Local_0041c8f0_Shared a3,
                                                     unsigned int a4, unsigned int a5,
                                                     unsigned int a6, unsigned int a7,
                                                     unsigned int a8, unsigned int a9,
                                                     unsigned int a10, unsigned int a11,
                                                     unsigned int a12, unsigned int a13)
{
    self->manager = 0;
    if (!fn_0060a2f0(&a1)) {
        void* p = fn_006a0920(48);
        fn_00419010(p, &a1);
        self->storage = p;
        self->manager = reinterpret_cast<const void*>(((int)&g_0080ee30));
    } else {
        self->manager = 0;
    }
    return self;
}
