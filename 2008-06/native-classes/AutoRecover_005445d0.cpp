// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is the std::_Tree iterator increment (_Inc) with a checked-iterator
// validity test in front. The node accessors are helpers (_Isnil, _Right, _Min, _Parent).

// The call goes through an import-table slot, so declare it dllimport.
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

struct TreeIter {
    int _unused0;
    int _Ptr; // node pointer at +4
};

// INFERRED: no stack argument is pushed at the call site, so the a1 parameter is dropped.
extern "C" char __fastcall fn_00402410(void* self, int unusedEdx);
extern "C" int fn_00541d90(int a1);
extern "C" int fn_00541da0(int a1);
extern "C" int fn_00545510(int a1);
// INFERRED: the call site pushes one arg and the caller cleans up (cdecl), despite the
// thiscall guess in the hint.
extern "C" int fn_0054c640(int a1);

extern "C" void __fastcall fn_005445d0(TreeIter* self, int unusedEdx)
{
    if (!fn_00402410(self, 0))
        _invalid_parameter_noinfo();

    if (*(char*)fn_00541d90(self->_Ptr) != 0) {
        _invalid_parameter_noinfo();
        return;
    }

    int right = *(int*)fn_00541da0(self->_Ptr);
    if (*(char*)fn_00541d90(right) == 0) {
        self->_Ptr = fn_00545510(*(int*)fn_00541da0(self->_Ptr));
        return;
    }

    int node;
    for (;;) {
        node = *(int*)fn_0054c640(self->_Ptr);
        if (*(char*)fn_00541d90(node) != 0)
            break;
        if (self->_Ptr != *(int*)fn_00541da0(node))
            break;
        self->_Ptr = node;
    }
    self->_Ptr = node;
}
