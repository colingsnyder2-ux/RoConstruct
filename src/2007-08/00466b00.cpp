// from server: 100% by colin
struct VCWorkspace_CComObject {
    char pad[0x10];
    void* field10;
    void Method(void* a, void* b);
};

extern "C" void __fastcall sub_52db00(void* p);

void VCWorkspace_CComObject::Method(void* a, void* b)
{
    sub_52db00(field10);
}
