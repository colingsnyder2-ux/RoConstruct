// from server: 58% by Intel
struct ScriptImpl {
    int field_8;
    int field_C;
    int (__thiscall *callback)(int, int);

    int __thiscall func(int a2, int a3);
};

extern "C" void __stdcall string_ctor(void *this_ptr, const void *other);

int __thiscall ScriptImpl::func(int a2, int a3) {
    int v3 = 0;
    int v4 = 0;
    if (a3) {
        v4 = a3 - 0x1C;
    }
    int ecx_val = field_C + v4;
    int eax_val = callback(ecx_val, a2);
    string_ctor((void *)a3, &eax_val);
    return a3;
}
