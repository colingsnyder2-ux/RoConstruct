// from server: 40% by colin
// roc 2007-08 00439160  unit: IIHAAH::?$CMap  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00439160
//
// 00439160  8b01                 mov eax, dword ptr [ecx]
// 00439162  ff20                 jmp dword ptr [eax]

struct IIHAAH__CMap {
    void* vtable;
};

extern "C" __declspec(dllimport) void __stdcall func_00439160(void);

void func_00439160(IIHAAH__CMap* thisPtr) {
    void* vtable = thisPtr->vtable;
    func_00439160();
}
