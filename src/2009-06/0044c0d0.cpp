// from server: 100% by why2
// roc 2009-06 0044c0d0  unit: CRobloxControlColorSelector  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044c0d0
//
// 0044c0d0  8b442404             mov eax, dword ptr [esp + 4]
// 0044c0d4  c70004010000         mov dword ptr [eax], 0x104
// 0044c0da  c7400404010000       mov dword ptr [eax + 4], 0x104
// 0044c0e1  c20800               ret 8

struct CRobloxControlColorSelector {
    void set(int* a, int b);
};

void CRobloxControlColorSelector::set(int* a, int b) {
    a[0] = 0x104;
    a[1] = 0x104;
}
