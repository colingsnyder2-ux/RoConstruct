// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layout from disassembly only; +8 is an embedded allocator-like sub-object, +0xc/+0x10/+0x14 are begin/cur/end of a dword buffer.
// INFERRED: fn_00542a30 is called with no pushed args in the disassembly, so it is declared with none (max-size query).
extern "C" unsigned __fastcall fn_00542a30(void* self, int unusedEdx);
extern "C" int fn_00553270(void);
extern "C" unsigned* __fastcall fn_00542de0(void* self, int unusedEdx, unsigned a1);

struct Buf553 {
    char pad[8];
    char sub[4];      // +8
    unsigned* begin;  // +0xc
    unsigned* cur;    // +0x10
    unsigned* end;    // +0x14
};

extern "C" bool __fastcall fn_005530e0(Buf553* self, int unusedEdx, unsigned count)
{
    self->begin = 0;
    self->cur = 0;
    self->end = 0;
    if (count == 0)
        return false;
    if (fn_00542a30(self, 0) < count) {
        fn_00553270();
    } else {
        self->begin = fn_00542de0(self->sub, 0, count);
        self->cur = self->begin;
        self->end = self->begin + count;
    }
    return true;
}
