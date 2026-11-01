// from server: 100% by why2
// roc 2009-06 0046ddc0  unit: VCContent::?$CComObject  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0046ddc0
//
// 0046ddc0  8b442404             mov eax, dword ptr [esp + 4]
// 0046ddc4  ff4008               inc dword ptr [eax + 8]
// 0046ddc7  8b4008               mov eax, dword ptr [eax + 8]
// 0046ddca  c20400               ret 4

struct VCContent_CComObject {
    int AddRefHelper();
};

int VCContent_CComObject::AddRefHelper() {
    return 0;
}

extern "C" int __stdcall VCContent_AddRef(void* p);

int __stdcall VCContent_AddRef(void* p) {
    int* q = (int*)p;
    ++q[2];
    return q[2];
}
