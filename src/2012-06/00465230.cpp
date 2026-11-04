// from server: 56% by Intel
struct VCRenderSettingsItem {
    struct FactoryProduct {
        int vftable;
        int field4;
        int field8;
        int fieldC;
    };

    static FactoryProduct* __cdecl Create(int a1, int a2, int a3, int a4);
};

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

VCRenderSettingsItem::FactoryProduct* __cdecl VCRenderSettingsItem::Create(int a1, int a2, int a3, int a4) {
    FactoryProduct* obj = 0;
    void* mem = operator new(0x10);
    if (mem) {
        obj = static_cast<FactoryProduct*>(mem);
        obj->vftable = 0x00B57CA0;
        obj->field4 = a1;
        obj->field8 = a2;
        obj->fieldC = a3;
    }

    int* outPtr = reinterpret_cast<int*>(a4);
    *outPtr = reinterpret_cast<int>(obj);

    void* guardMem = operator new(0);
    operator delete(guardMem);

    return obj;
}
