// from server: 24% by Intel
struct TypeInfo {
    int vftable;
};

extern "C" int __stdcall type_info_equal(TypeInfo* a, TypeInfo* b);
extern "C" void __stdcall bad_cast_ctor(void* exc, const char* msg);
extern "C" void __cdecl throw_exception(void* exc);

int __cdecl sub_6D9CC0(int* esi) {
    TypeInfo* eax = reinterpret_cast<TypeInfo*>(esi[0]);
    TypeInfo* ecx;

    if (eax) {
        ecx = reinterpret_cast<TypeInfo*>(eax->vftable);
    } else {
        ecx = reinterpret_cast<TypeInfo*>(0xD60AC8);
    }

    if (ecx == reinterpret_cast<TypeInfo*>(0xDA4608)) {
        TypeInfo* eax2;
        if (eax) {
            eax2 = reinterpret_cast<TypeInfo*>(eax->vftable);
        } else {
            eax2 = reinterpret_cast<TypeInfo*>(0xD60AC8);
        }

        if (type_info_equal(eax2, reinterpret_cast<TypeInfo*>(0xDA4608))) {
            int local_8 = 0xB44128;
            int local_4 = 0xB44120;
            int local_C = 0;
            throw_exception(&local_8);
        }
    }

    return esi[1];
}
