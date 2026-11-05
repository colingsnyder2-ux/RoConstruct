// from server: 54% by atomic.potato
struct VRbxRayHolder {
    void* field0;
    void* field4;

    void* func_4F6EA0();
};

extern "C" void* __cdecl sub_80B2EA(void*, void*, void*, void*);
extern "C" void* __cdecl sub_80B0AC(void*, void*);
extern "C" void __stdcall MSVCR90_bad_cast_ctor(const char*);

void* VRbxRayHolder::func_4F6EA0() {
    void* result;
    const char* badCastStr = "bad cast";
    
    result = sub_80B2EA(this->field0, 0, (void*)0xC079E4, 0);
    if (!result) {
        MSVCR90_bad_cast_ctor(badCastStr);
        sub_80B0AC((void*)0xB989FC, &badCastStr);
    }
    
    void* vtable = *(void**)result;
    void* func = *(void**)((char*)vtable + 8);
    return ((void*(__thiscall*)(void*, void*))func)(*(void**)((char*)result + 0x1C), this->field4);
}
