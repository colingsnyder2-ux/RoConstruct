// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 00595780: this-adjustor thunk (add ecx, 4; jmp 00595700). 00595700 is
// shared_ptr<slot_base::data_t>::reset<data_t>(data_t*) (thiscall, ret 4), so the thunk forwards its one stack argument.
// INFERRED: the earlier draft dropped that argument, which left the stack 4 bytes off after every call.
extern "C" void __fastcall fn_00595700(void* self, int unusedEdx, void* p);

extern "C" void __fastcall fn_00595780(void* self, int unusedEdx, void* p)
{
    fn_00595700((char*)self + 4, unusedEdx, p);
}
