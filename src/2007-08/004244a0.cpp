// from server: 42% by colin
struct CSelectionTreeCtrl {
    void* field0;
    CSelectionTreeCtrl* construct(void* a, void* b);
};

extern "C" void* __cdecl sub_62FEF6(unsigned int size);

CSelectionTreeCtrl* CSelectionTreeCtrl::construct(void* a, void* b)
{
    CSelectionTreeCtrl* result = 0;
    void* mem = sub_62FEF6(0x14);
    if (mem != 0) {
        *(int*)((char*)mem + 4) = 1;
        *(int*)((char*)mem + 8) = 1;
        *(void**)mem = (void*)0x7887d0;
        *(void**)((char*)mem + 0xc) = a;
        result = (CSelectionTreeCtrl*)mem;
    }
    this->field0 = result;
    return this;
}
