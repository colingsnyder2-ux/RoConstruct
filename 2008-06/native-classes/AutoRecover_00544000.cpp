// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this looks like std::_Tree<set<int>>::_Init(): allocate the head node,
// mark it nil, and point parent/lmost/rmost at it with size 0.
// INFERRED: the owner class is unknown, so the tree members are modelled as a
// padded struct with the head pointer at +0x18 and the size at +0x1c.
struct TreeOwner {
    char pad[0x18];
    void* myhead;   // +0x18
    int   mysize;   // +0x1c
};

// The disassembly pushes no stack args for fn_00545550, so it is declared with none.
extern "C" void* __fastcall fn_00545550(void* self, int unusedEdx);
extern "C" int fn_00541d90(int value);
extern "C" void** __fastcall fn_005423f0(void* self, int unusedEdx);
extern "C" void** __fastcall fn_005508e0(void* self, int unusedEdx);
extern "C" void** __fastcall fn_0054cec0(void* self, int unusedEdx);

extern "C" void __fastcall fn_00544000(TreeOwner* self, int unusedEdx)
{
    self->myhead = fn_00545550(self, 0);
    *fn_00541d90(self, 0, self->myhead) = 1;
    *fn_005423f0(self, 0) = self->myhead;
    *fn_005508e0(self, 0) = self->myhead;
    *fn_0054cec0(self, 0) = self->myhead;
    self->mysize = 0;
}
