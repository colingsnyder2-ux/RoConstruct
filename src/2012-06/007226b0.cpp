// from server: 62% by Intel
struct Object {
    char pad[0x38];
    Object* field_38;
};

extern "C" void __stdcall sub_4A01E0(Object* ecx);
extern "C" int __stdcall sub_983448(int, Object*, int, int, int);
extern "C" void __stdcall sub_4979D0(Object* ecx);

int __cdecl func_007226B0(Object* ecx) {
    if (!ecx)
        return 0;

    Object* eax = ecx->field_38;
    if (eax) {
        Object* ecx2 = eax->field_38;
        if (ecx2)
            sub_4A01E0(ecx2);
    } else {
        eax = ecx;
    }

    if (!eax)
        return 0;

    int result = sub_983448(0, eax, 0, 0xD601E8, 0xD65108);
    if (!result)
        return 0;

    sub_4979D0(reinterpret_cast<Object*>(result));
    return 0;
}
