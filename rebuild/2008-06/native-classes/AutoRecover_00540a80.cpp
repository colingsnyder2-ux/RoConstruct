// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a std::set<int> default constructor wrapper. It calls
// _Tree(const less<int>&, const allocator<int>&) with two empty-object
// temporaries. The allocator reference comes from an identical-COMDAT-folded
// stub (named XMin in the symbol table) called on a one-byte local.

extern "C" void* __fastcall fn_0054e310(void* self, int unusedEdx);
extern "C" void* __fastcall fn_00541db0(void* self, int unusedEdx, void* lessRef, void* allocRef);

extern "C" void* __fastcall fn_00540a80(void* self, int unusedEdx)
{
    char allocObj;
    char lessObj;
    void* allocRef = fn_0054e310(&allocObj, 0);
    fn_00541db0(self, 0, &lessObj, allocRef);
    return self;
}
