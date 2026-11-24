// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

extern "C" void __cdecl _invalid_parameter_noinfo(void);

// INFERRED: func_00402410 takes no stack args in the disassembly (ret 0 style, only ecx is set).
extern "C" int __fastcall fn_00402410(void* self, int unusedEdx);
extern "C" int fn_00541d90(int a1);
extern "C" int fn_00541da0(int a1);
// INFERRED: the caller pops the stack argument (add esp,4) and ecx is not set up,
// so these two are plain cdecl rather than __thiscall.
extern "C" int fn_0054c630(int a1);
extern "C" int fn_0054c640(int a1);
extern "C" int fn_005454d0(int a1);

// INFERRED: a checked tree iterator, with the node pointer at offset 4 (after the container proxy pointer).
struct TreeIter {
    int proxy;
    int ptr;
};

extern "C" void __fastcall fn_005458a0(TreeIter* self, int unusedEdx)
{
    if (!(unsigned char)fn_00402410(self, 0))
        _invalid_parameter_noinfo();

    if (*(char*)fn_00541d90(self->ptr) != 0) {
        self->ptr = *(int*)fn_00541da0(self->ptr);
        if (*(char*)fn_00541d90(self->ptr) != 0)
            _invalid_parameter_noinfo();
        return;
    }

    if (*(char*)fn_00541d90(*(int*)fn_0054c630(self->ptr)) == 0) {
        self->ptr = fn_005454d0(*(int*)fn_0054c630(self->ptr));
        return;
    }

    int node;
    for (;;) {
        node = *(int*)fn_0054c640(self->ptr);
        if (*(char*)fn_00541d90(node) == 0 &&
            self->ptr == *(int*)fn_0054c630(node)) {
            self->ptr = node;
            continue;
        }
        break;
    }
    if (*(char*)fn_00541d90(self->ptr) != 0) {
        _invalid_parameter_noinfo();
        return;
    }
    self->ptr = node;
}
