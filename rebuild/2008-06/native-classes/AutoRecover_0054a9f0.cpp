// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: layout from the disassembly. Members at 0x0 (base, filled by fn_0054bf50),
// 0xc list, 0x18 (fn_0054bfe0), 0x24 list, 0x30 HuffmanEncodingTree.
struct Fn54A9F0Obj;

extern "C" int __fastcall fn_0054bf50(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5, int a6);
extern "C" int __fastcall fn_0054bfe0(void* self, int unusedEdx);
extern "C" void __fastcall fn_00481520(void* self, int unusedEdx);
extern "C" void __fastcall fn_004f0810(void* self, int unusedEdx);

extern "C" Fn54A9F0Obj* __fastcall fn_0054a9f0(Fn54A9F0Obj* self, int unusedEdx)
{
    char* p = (char*)self;
    // INFERRED: disassembly pushes no stack args to fn_0054bf50 here; the callee
    // reads them as garbage, so pass zeros to keep the call shape.
    fn_0054bf50(p, 0, 0, 0, 0, 0, 0, 0);
    fn_00481520(p + 0xc, 0);
    fn_0054bfe0(p + 0x18, 0);
    fn_00481520(p + 0x24, 0);
    fn_004f0810(p + 0x30, 0);
    return self;
}
