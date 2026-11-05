// from server: 93% by Intel
// roc 2012-06 004b59f0  unit: VCWorkspace::?$CComObject  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004b59f0

extern "C" void __cdecl sub_983374(int, void*, int);

struct CComObject {
    int method();
};

int CComObject::method()
{
    int esi = (int)this;
    sub_983374(0x48, (void*)esi, 0);
    *(int*)(esi + 0x28) = 1;
    *(int*)(esi + 0x20) = 1;
    return esi;
}
