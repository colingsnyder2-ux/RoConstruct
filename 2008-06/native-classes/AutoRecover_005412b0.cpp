// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layout from disassembly; field +4 is a pointer to an object whose +8 slot holds a freshly built 8-byte node.
extern "C" void* __cdecl fn_006a0920(unsigned size);  // cdecl: push 8 / add esp,4 (really operator new)
extern "C" void __fastcall fn_004f0840(void* self, int unusedEdx);  // zeroPointer

struct Node;
extern "C" Node* __fastcall fn_005f1270(Node* self, int unusedEdx, int a, int b);  // CSize(int,int)

struct Node {
    int a, b;
    static void* operator new(unsigned size) { return fn_006a0920(size); }
};

struct Target {
    int unk0;
    struct Obj { int pad0, pad4; Node* slot; }* ptr;
};

extern "C" void __fastcall fn_005412b0(Target* self, int unusedEdx, Target::Obj* arg)
{
    fn_004f0840(self, 0);
    self->ptr = arg;
    if (self->ptr) {
        Node* n = new Node;
        Node* r = n ? fn_005f1270(n, 0, (int)self, (int)(self->ptr->slot)) : 0;
        self->ptr->slot = r;
    }
}
