// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" int fn_006a0920(int a1, int a2, int a3, int a4, int a5);
extern "C" int __fastcall fn_006790b0(void* self, int unusedEdx, int a1, int a2);

struct Node {
    Node* owner;
};

struct Obj {
    Node* node;
};

// INFERRED: __thiscall ctor, one stack arg forwarded to fn_006790b0 with a 0.0f float; node alloc size 4 with back pointer
extern "C" Obj* __fastcall fn_006798b0(Obj* self, int unusedEdx, int arg1)
{
    Node* n = (Node*)fn_006a0920(4, 0, 0, 0, 0);
    if (n)
        n->owner = (Node*)self;
    self->node = n;
    float zero = 0.0f;
    fn_006790b0(self, 0, arg1, (int)&zero);
    return self;
}
