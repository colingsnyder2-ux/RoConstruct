// from server: 49% by colin
struct CChatPrompt {
    void* field0;
    void* construct(int, int);
};

extern "C" void* __cdecl sub_62FEF6(unsigned int);

void* CChatPrompt::construct(int a1, int a2) {
    void* p;
    field0 = 0;
    p = sub_62FEF6(0x14);
    if (p != 0) {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(void**)p = (void*)0x786894;
        *(int*)((char*)p + 0xc) = a1;
    } else {
        p = 0;
    }
    field0 = p;
    return this;
}
