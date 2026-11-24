// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: constructor-like wrapper; ecx passed through to fn_00545770, which takes 2 stack args per inferred convention but the disassembly pushes none, so declared with no extra args here.
extern "C" int __fastcall fn_00545770(void* self, int unusedEdx);

extern "C" void* __fastcall fn_005443a0(void* self, int unusedEdx)
{
    fn_00545770(self, 0);
    return self;
}
