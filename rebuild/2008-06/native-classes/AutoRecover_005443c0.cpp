// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: this looks like a checked std::map/set (_Tree) iterator operator++.
// fn_00542e00 is _Isnil, fn_00541da0 is _Right, fn_0054c640 is _Parent, and
// fn_005450f0 is _Min. The iterator keeps the node pointer at offset 4.
extern "C" void __cdecl _invalid_parameter_noinfo(void);

// INFERRED: the disassembly pushes no stack arg for this call, so the declared arg is dropped.
extern "C" int __fastcall fn_00402410(void* self, int unusedEdx);
extern "C" char* fn_00542e00(int node);
extern "C" int* fn_00541da0(int node);
extern "C" int fn_005450f0(int node);
// INFERRED: the call site pushes one arg and the caller pops it, so this is cdecl rather than thiscall.
extern "C" int* fn_0054c640(int node);

struct TreeIter {
    int container;  // INFERRED: unused here
    int ptr;
};

extern "C" void __fastcall fn_005443c0(TreeIter* self, int unusedEdx)
{
    if (!(unsigned char)fn_00402410(self, 0))
        _invalid_parameter_noinfo();

    if (*fn_00542e00(self->ptr) != 0) {
        // incrementing end(): invalid
        _invalid_parameter_noinfo();
        return;
    }

    int right = *fn_00541da0(self->ptr);
    if (*fn_00542e00(right) == 0) {
        self->ptr = fn_005450f0(*fn_00541da0(self->ptr));
        return;
    }

    int pnode = *fn_0054c640(self->ptr);
    while (*fn_00542e00(pnode) == 0 && self->ptr == *fn_00541da0(pnode)) {
        self->ptr = pnode;
        pnode = *fn_0054c640(self->ptr);
    }
    self->ptr = pnode;
}
