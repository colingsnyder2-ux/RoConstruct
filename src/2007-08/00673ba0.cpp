// from server: 100% by colin
struct CXTPCustomizeSheet {
    char pad[0xb8];
    void* field_b8;
    void func(void*);
};

void CXTPCustomizeSheet::func(void* arg)
{
    void* p = arg;
    void (__thiscall**vt)(void*, int) = *(void (__thiscall***)(void*, int))p;
    vt[1](p, 0);
    void* q = *(void**)((char*)this->field_b8 + 0x58);
    if (q) {
        void (__thiscall**vt2)(void*, int) = *(void (__thiscall***)(void*, int))p;
        vt2[1](p, *(int*)((char*)q + 0x98));
        void (__thiscall**vt3)(void*, int) = *(void (__thiscall***)(void*, int))p;
        int flag = (*(int*)((char*)q + 0x80) != 0);
        vt3[0](p, flag);
    }
}
