// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: callee is vector<Listener<Players,SuperSafeChanged>*, alloc>::push_back
// (thiscall: ecx = vector, one stack arg = const T&). Declared per the fixed naming convention.
extern "C" void __fastcall fn_004213a0(void* vec, int unusedEdx, void* const* value);

// INFERRED: target is a thiscall member (uses ecx, ret 4). It pushes its argument onto
// the listener vector stored at this+0xD8.
extern "C" void __fastcall fn_0067da50(char* self, int unusedEdx, void* listener)
{
    void* local = listener;
    fn_004213a0(self + 0xd8, 0, &local);
}
