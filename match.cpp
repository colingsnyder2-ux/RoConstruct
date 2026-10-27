extern DWORD glob_7d2971;

struct RBXInstance {
    void func_at_005a0ec0(DWORD param1, DWORD param2);
};

void RBXInstance::func_at_005a0ec0(DWORD param1, DWORD param2) {
    DWORD eax = 0;

    // this is in ecx (thiscall convention)
    // cmp ecx, eax compares this with 0
    // je 0x5a0ef0: if this == 0, jump to common code (eax stays 0)
    if (this != 0) {
        // lea eax, [ecx - 0x364]
        eax = (DWORD)this - 0x364;
    }
    // If this == 0, eax remains 0, control flows to common code

    // Common code at 0x5a0ef0:
    // mov esi, [ebp + 8]  -> param1 (first dereference value)
    // mov ecx, [ebp + 0xc] -> param2 (overwrites ecx=this)
    // mov edx, [ecx]      -> edx = [param2], dereference param2 as pointer (first deref)
    // push esi            -> push param1
    // push eax            -> push the computed value (0 or this-0x364)
    // mov eax, [edx]      -> eax = [[param2]], reload from dereferenced pointer (second deref)
    // call eax            -> indirect call through [[param2]]

    // param2 is treated as a pointer to a function pointer (double indirection).
    // The function address is at the address stored at param2, i.e. **param2.
    // Double-dereference to get the actual function address.
    const DWORD* p1 = reinterpret_cast<const DWORD*>(param2);
    const DWORD* p2 = reinterpret_cast<const DWORD*>(*p1);
    typedef void (__stdcall *FuncPtr)(DWORD, DWORD);
    FuncPtr func = reinterpret_cast<FuncPtr>(*p2);
    func(param1, eax);
}