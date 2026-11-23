// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the target looks like a constructor of a small holder object. It
// takes a large by-value argument pack (21 dwords) whose first part is
// treated as a std::string. Their real types are unknown, so they are
// declared as int.
struct Holder {
    void* vtbl;   // +0
    int   pad;    // +4
    int   ptr;    // +8
};

// INFERRED: unknown global at the old address 0x832358 (a vtable of the object stored in the holder).
extern "C" char g_00832358[];

extern "C" int  fn_006a0920(int a1);
extern "C" int  __fastcall fn_00596a50(void* self, int unusedEdx, int a1, int a2);
extern "C" void __fastcall fn_00596470(void* self);
// StringConverter<CoordinateFrame>::convertToValue(const std::string&, CoordinateFrame&-ish)
// INFERRED: called with one argument, returns bool in al.
extern "C" bool fn_0060a2f0(void* str);

extern "C" Holder* __fastcall fn_00597080(Holder* self, int unusedEdx,
    int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7,
    int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14,
    int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21)
{
    self->vtbl = 0;
    if (!fn_0060a2f0(&arg1)) {
        int obj = fn_006a0920(0x50);
        // INFERRED: ecx is left holding &arg1 from the earlier lea
        fn_00596a50(&arg1, 0, obj, (int)&arg1);
        self->ptr = obj;
        self->vtbl = (void*)g_00832358;
    } else {
        self->vtbl = 0;
    }
    // INFERRED: destructor of the argument pack member starting at arg3
    fn_00596470(&arg3);
    return self;
}
