// from server: 42% by Intel
struct TypedPropertyDescriptor {
    void* vftable;
    void* vftable2;
    char pad[0x14];
    void* field18;
    void* field1C;
    char pad2[0xC];
    int field28;
};

extern "C" void __stdcall __security_cookie_init(int);
extern "C" void __cdecl sub_6861B0(TypedPropertyDescriptor*);
extern "C" int __cdecl sub_412DF0(TypedPropertyDescriptor*);

int __cdecl TypedPropertyDescriptor_ctor(TypedPropertyDescriptor* thisptr) {
    __security_cookie_init(-1);
    sub_6861B0(thisptr);
    thisptr->vftable = (void*)0xB443CC;
    thisptr->vftable2 = (void*)0xB443C0;
    thisptr->field18 = (void*)0xB443B4;
    thisptr->field1C = (void*)0xB443A8;
    int result = sub_412DF0(thisptr);
    thisptr->field28 = result;
    ++*reinterpret_cast<int*>(0xE18C44);
    return reinterpret_cast<int>(thisptr);
}
