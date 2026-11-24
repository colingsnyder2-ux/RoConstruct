// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the target is an unnamed SceneManager-like clear/destroy routine, so it is declared as a plain fn_ function.
// INFERRED: the disassembly pushes no argument to fn_00540d60, so it is declared with 0 stack args.
//           This deviates from the supplied "1 stack arg" declaration, which would push an extra dword.
// INFERRED: iterator type is an opaque 8-byte struct (the locals sit at ebp-8 and ebp-0x10).

struct FnIter {
    void* a;
    int   b;
};

struct SceneClearSelf;

extern "C" int   __fastcall fn_00540d60(void* self, int unusedEdx);
extern "C" void* __fastcall fn_0054f140(void* self, int unusedEdx, FnIter* out);               // set<int>::begin
extern "C" int   __fastcall fn_005409b0(void* self, int unusedEdx, FnIter* out);               // end
extern "C" unsigned char __fastcall fn_00540f20(FnIter* self, int unusedEdx, FnIter* other);   // operator!=
extern "C" char* __fastcall fn_00540e90(FnIter* self, int unusedEdx);                          // operator*
extern "C" void* __fastcall fn_00540e80(void* self, int unusedEdx);                            // GetQuantity-like accessor
extern "C" int   __fastcall fn_005404b0(void* self, int unusedEdx);
extern "C" void* __fastcall fn_00540eb0(FnIter* self, int unusedEdx);                          // operator++
extern "C" void  __fastcall fn_004d8310(void* self, int unusedEdx);                            // SceneManager::clearScene

extern "C" void __fastcall fn_0053f6a0(SceneClearSelf* self, int unusedEdx)
{
    char* p = (char*)self;
    fn_00540d60(p + 0x28, 0);
    fn_00540d60(p + 0x48, 0);

    FnIter it;
    FnIter end;
    fn_0054f140(p + 8, 0, &it);
    fn_005409b0(p + 8, 0, &end);

    while (fn_00540f20(&it, 0, &end)) {
        char* v = fn_00540e90(&it, 0);
        void* q = fn_00540e80(v + 0xc, 0);
        fn_005404b0(q, 0);
        fn_00540eb0(&it, 0);
    }

    fn_004d8310(self, 0);
}
