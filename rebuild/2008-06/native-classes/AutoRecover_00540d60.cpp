// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this looks like std::set<int>::clear() / _Tree::clear():
//   _Erase(_Root()); _Root() = _Myhead; _Mysize = 0; _Lmost() = _Myhead; _Rmost() = _Myhead;
// The class has no known name, so a minimal layout is declared here.
struct TreeSetInt {
    char pad[0x18];
    void* myhead;   // +0x18
    unsigned mysize; // +0x1c
};

// INFERRED: _Parent()/_Root() accessor, returns a reference to the root node pointer.
// Declared with 0 stack args to match the disassembly (no pushes before the call).
extern "C" void** __fastcall fn_005423f0(void* self, int unusedEdx);
// INFERRED: _Erase(node)
extern "C" int __fastcall fn_00541ef0(void* self, int unusedEdx, void* node);
// INFERRED: _Lmost() (mangled in the original as std::_Tree<...>::_Lmost)
extern "C" void** __fastcall fn_005508e0(void* self, int unusedEdx);
// INFERRED: _Rmost()
extern "C" void** __fastcall fn_0054cec0(void* self, int unusedEdx);

extern "C" void __fastcall fn_00540d60(TreeSetInt* self, int unusedEdx)
{
    fn_00541ef0(self, 0, *fn_005423f0(self, 0));
    *fn_005423f0(self, 0) = self->myhead;
    self->mysize = 0;
    *fn_005508e0(self, 0) = self->myhead;
    *fn_0054cec0(self, 0) = self->myhead;
}
