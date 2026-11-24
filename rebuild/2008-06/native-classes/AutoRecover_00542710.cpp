// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: checked-iterator style increment (+4 stride, _SCL_SECURE validate pattern); layout guessed.
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

struct Iter {
    int unk0;
    unsigned int pos; // +4
};

// INFERRED: disassembly pushes no args for either callee, so declared with 0 stack args.
extern "C" unsigned char __fastcall fn_00402410(void* self, int unusedEdx);
extern "C" unsigned int* __fastcall fn_00402400(void* self, int unusedEdx);

extern "C" Iter* __fastcall fn_00542710(Iter* self, int unusedEdx)
{
    if (!fn_00402410(self, 0))
        _invalid_parameter_noinfo();
    if (!(self->pos < fn_00402400(self, 0)[4]))
        _invalid_parameter_noinfo();
    self->pos += 4;
    return self;
}
