// from server: 100% by colin
// roc 2007-08 00675920  unit: CXTPCustomizeSheet  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00675920

struct CXTPCustomizeSheet {
    char pad[0x90];
    int field_90;
    char pad2[0x1ac - 0x90 - 4];
    void* field_1ac;
    void OnDestroy();
};

extern "C" void __stdcall sub_62FEEA(int);
extern "C" void __stdcall sub_6333A0();

void CXTPCustomizeSheet::OnDestroy()
{
    sub_62FEEA(1);
    void* p = field_1ac;
    int* q = *(int**)((char*)p + 0xb8);
    int v = field_90;
    int* r = *(int**)((char*)q + 0x74);
    *(int*)((char*)r + 0x30) = v;
    sub_6333A0();
}
