// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the CRT header in this toolchain does not declare this, so declare it here.
// The call goes through an import-table slot, hence dllimport.
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

// INFERRED: this is a checked-iterator operator== (iterator base at +0, pointer at +4).
struct CheckedIter {
    void* _Container;   // +0 (iterator base / proxy)
    void* _Ptr;         // +4
};

// INFERRED: the disassembly pushes no stack args to this callee, so it is declared with none
// instead of the two stack args suggested; it returns a bool in al.
extern "C" bool __fastcall fn_00402410(void* self, int unusedEdx);
// std::_Iterator_base_aux::_Same_container(const _Iterator_base_aux&) const
extern "C" bool __fastcall fn_004d71d0(void* self, int unusedEdx, const void* other);

extern "C" bool __fastcall fn_00540ed0(CheckedIter* self, int unusedEdx, const CheckedIter* right)
{
    if (!fn_00402410(self, 0) || !fn_004d71d0(self, 0, right)) {
        _invalid_parameter_noinfo();
    }
    return self->_Ptr == right->_Ptr;
}
