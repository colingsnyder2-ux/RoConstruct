// from server: 22% by Intel




struct VBitStream {
    void* vfptr;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_1C;
    int field_20;
    char field_24[4];
    int field_28;
};

extern "C" void __cdecl sub_434BD0(VBitStream*);

VBitStream* __stdcall VBitStream_ctor(VBitStream* thisptr, int a2, int a3, int a4, int a5, int a6, int a7, int a8) {
    sub_434BD0(thisptr);
    thisptr->vfptr = (void*)0xB720F4;
    thisptr->field_20 = a2;
    if (a2) {
        thisptr->field_28 = a2;
        int (__stdcall *func)(int, int, int) = *(int (__stdcall **)(int, int, int))a2;
        func(0, thisptr->field_28, (int)&thisptr->field_28 + 4);
    }
    if (a2) {
        int vtable = *(int*)a2;
        if (vtable) {
            int (__stdcall *func2)(int, int, int) = *(int (__stdcall **)(int, int, int))vtable;
            func2(2, (int)&thisptr->field_20, (int)&thisptr->field_20);
        }
    }
    return thisptr;
}
