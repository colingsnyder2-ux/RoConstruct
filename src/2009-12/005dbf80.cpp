// from server: 59% by atomic.potato
struct S {
    char pad[0x28];
    void* field_28;
    char pad2[0x14];
    void* field_14;
    void* field_18;
    void destroy();
};

void S::destroy()
{
    field_28 = (void*)0x99fd90;
    *(void**)this = (void*)0x9c1534;
    field_14 = (void*)0x9c152c;
    field_14 = (void*)0x99fdd8;
    if (field_18) {
        void** vt = *(void***)field_18;
        void (*fn)(void*) = (void (*)(void*))vt[4];
        fn(field_18);
    }
    *(void**)this = (void*)0x9c1364;
    extern void __stdcall sub_98b7a8(void*);
    sub_98b7a8(this);
}
