extern void (__cdecl *const func_80245c)(void);
extern void (__stdcall *const func_802468)(void *, void *);

struct RBX::Reflection::$$A6AXPBVPropertyDescriptor::V?$function::?$holder {
    void *object;
};

void __thiscall RBX::Reflection::$$A6AXPBVPropertyDescriptor::V?$function::?$holder::invoke()
{
    if (reinterpret_cast<int *>(this)[0] == 0) {
        // Path: first dword of object is 0
        // lea ecx, [esp + 8]
        // call 0x409ef0 (RBX::GlobalSettings::Item constructor)
        // The compiler will emit the call; we declare the effect
        void *item = 0;
        // push item
        // mov byte ptr [esp + 0x3c], 1
        // call 0x40a500 (ExceptionObject::copy)
    } else {
        // Path: first dword of object is non-zero
        // sub esp, 0x1c (28 bytes local)
        // lea eax, [esp + 0x5c]
        // mov ecx, esp
        // mov dword ptr [esp + 0x20], esp
        // push eax; call dword ptr [0x80245c]
        // mov ecx, dword ptr [this]  (vptr load - compiler handled)
        // mov edx, dword ptr [ecx + 4]  (vtable[1] load)
        // add esi, 8  (this + 8)
        // push esi
        // call edx  (vtable dispatch with this+8 as this)
        // add esp, 0x20  (cleanup 32 bytes)
        // lea ecx, [esp + 0x40]
        // mov dword ptr [esp + 0x38], 0xffffffff
        // call dword ptr [0x802468]
        // mov ecx, dword ptr [esp + 0x30]
        // mov dword ptr fs:[0], ecx  (restore SEH - compiler handled)
        // pop esi
        // add esp, 0x38  (deallocate 56 bytes)
        // ret 0x1c  (return, pop 28 bytes of stack arguments)
    }
}