// from server: 38% by Intel
struct TypeInfo {
    int vftable;
};

extern "C" int __stdcall type_info_equal(TypeInfo* a, TypeInfo* b);
extern "C" void __stdcall construct_bad_cast(const char* msg);
extern "C" void __stdcall throw_exception(void* exception);

int __cdecl sub_4671B0(int* esi) {
    TypeInfo* vftable_ptr = (TypeInfo*)esi[0];
    TypeInfo* type_info = vftable_ptr ? vftable_ptr : (TypeInfo*)0xD60AC8;

    if (type_info->vftable != 0xD6BA68) {
        TypeInfo* obj_type = vftable_ptr ? vftable_ptr : (TypeInfo*)0xD60AC8;
        if (type_info_equal(obj_type, (TypeInfo*)0xD6BA68)) {
            construct_bad_cast(".?AV?$TypedPropertyDescriptor@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Reflection@");
            throw_exception((void*)0xB44120);
        }
    }
    return esi[1];
}
