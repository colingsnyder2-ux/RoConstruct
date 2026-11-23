// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: vector-like container erase(); layout and arg types from disassembly only.
struct Obj40710 {
    int pad[4];
    char* last; // +0x10
};

extern "C" char* fn_00545e60(char* first, char* last, char* dest);
extern "C" int __fastcall fn_005414a0(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_00541360(void* self, int unusedEdx, int a1, int a2, int a3);

extern "C" int __fastcall fn_00540710(Obj40710* self, int unusedEdx, int a1, int a2, int a3)
{
    fn_00545e60((char*)a3 + 4, self->last, (char*)a3);
    fn_005414a0(self, 0, (int)(self->last - 4), (int)self->last);
    self->last = self->last - 4;
    fn_00541360(self, 0, a1, a2, a3);
    return a1;
}
