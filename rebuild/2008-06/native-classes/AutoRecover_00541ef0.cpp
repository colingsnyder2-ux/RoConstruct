// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this looks like std::set<int>::_Erase(_Nodeptr). Disassembly shows the
// helpers 541d90/541da0/54c630 are called cdecl with one stack arg (no ecx setup),
// so they are declared cdecl here rather than with the suggested __fastcall form.
extern "C" char* fn_00541d90(int node);   // _Isnil(node) field address
extern "C" int*  fn_00541da0(int node);   // _Right(node) field address
extern "C" int*  fn_0054c630(int node);   // _Left(node) field address
extern "C" int __fastcall fn_005442d0(void* self, int unusedEdx, int a1);   // destroy (this+0xc)
extern "C" int __fastcall fn_00543610(void* self, int unusedEdx, int a1, int a2); // deallocate (this+0xc)
extern "C" int __fastcall fn_00541ef0(void* self, int unusedEdx, int a1);

extern "C" int __fastcall fn_00541ef0(void* self, int unusedEdx, int a1)
{
    int node = a1;
    while (*fn_00541d90(node) == 0) {
        fn_00541ef0(self, 0, *fn_00541da0(node));
        int cur = node;
        node = *fn_0054c630(node);
        fn_005442d0((char*)self + 0xc, 0, cur);
        fn_00543610((char*)self + 0xc, 0, cur, 1);
    }
    return 0;
}
