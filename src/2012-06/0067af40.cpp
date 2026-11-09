// from server: 32% by Intel
struct TypeInfo {
    int vftable;
};

extern "C" int __stdcall type_info_equal(TypeInfo*, TypeInfo*);
extern "C" void* __stdcall sub_B22A20(void*, int);
extern "C" void __cdecl sub_40F520(int*);

int __cdecl sub_67AF40(int* esi) {
    TypeInfo* eax = (TypeInfo*)esi[0];
    TypeInfo* ecx;

    if (eax)
        ecx = (TypeInfo*)eax->vftable;
    else
        ecx = (TypeInfo*)0xD60AC8;

    if (ecx != (TypeInfo*)0xD97FC8) {
        if (eax)
            eax = (TypeInfo*)eax->vftable;
        else
            eax = (TypeInfo*)0xD60AC8;

        if (type_info_equal(eax, (TypeInfo*)0xD97FC8)) {
            int local_8;
            sub_B22A20(&local_8, 0xB44128);
            int local_4 = 0xB44120;
            sub_40F520(&local_4);
        }
    }

    return esi[1];
}
