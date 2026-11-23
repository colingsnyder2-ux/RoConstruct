// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
struct TreeSelf;
struct TreeOut;

// INFERRED: types opaque; names from callee conventions in the disassembly.
extern "C" void* __fastcall fn_00543580(TreeSelf* self, int unusedEdx, TreeSelf* arg1, int arg2);
extern "C" void __fastcall fn_0054e320(TreeOut* self, int unusedEdx, void* arg1);

extern "C" TreeOut* __fastcall fn_00541c70(TreeSelf* self, int unusedEdx, TreeOut* out, int key)
{
    fn_0054e320(out, 0, fn_00543580(self, 0, self, key));
    return out;
}
