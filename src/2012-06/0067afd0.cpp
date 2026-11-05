// from server: 32% by Intel
struct TypeInfo {
    int vftable;
};

extern "C" int __stdcall type_info_equal(TypeInfo* a, TypeInfo* b);
extern "C" void __stdcall bad_cast_ctor(void* thisptr, const char* msg);
extern "C" void __cdecl throw_bad_cast(void* ex);

int __cdecl sub_67AFD0(int* esi) {
    TypeInfo* eax = (TypeInfo*)esi[0];
    TypeInfo* ecx;

    if (eax) {
        ecx = (TypeInfo*)eax->vftable;
    } else {
        ecx = (TypeInfo*)0xD60AC8;
    }

    if (ecx != (TypeInfo*)0xD98050) {
        TypeInfo* eax2;
        if (eax) {
            eax2 = (TypeInfo*)eax->vftable;
        } else {
            eax2 = (TypeInfo*)0xD60AC8;
        }

        if (type_info_equal(eax2, (TypeInfo*)0xD98050)) {
            void* ex = (void*)0xB44128;
            bad_cast_ctor(ex, (const char*)0xB44120);
            throw_bad_cast(ex);
        }
    }

    return esi[1];
}
