// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: operator-new-like allocator, called with one dword (size 4).
extern "C" void* fn_006a0920(int size);
// INFERRED: std::list<boost::signals::connection>::_Buynode, thiscall on the object.
extern "C" void* __fastcall fn_0041a800(void* self, int unusedEdx);

struct Node4 {
    void* owner;
};

struct Fn594ae0Obj {
    Node4* node;     // +0x00
    int pad[4];      // INFERRED: untouched by this ctor
    void* listNode;  // +0x14
    int field18;     // +0x18
};

struct Fn594ae0Holder {
    Fn594ae0Obj* ctor();
};

extern "C" Fn594ae0Obj* __fastcall fn_00594ae0(Fn594ae0Obj* self, int unusedEdx)
{
    Node4* n = (Node4*)fn_006a0920(4);
    if (n)
        n->owner = self;
    self->node = n;
    self->listNode = fn_0041a800(self, 0);
    self->field18 = 0;
    return self;
}
