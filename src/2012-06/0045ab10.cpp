// from server: 84% by Intel
// roc 2012-06 0045ab10  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0045ab10
//
// 0045ab10  8b11                 mov edx, dword ptr [ecx]
// 0045ab12  8b4204               mov eax, dword ptr [edx + 4]
// 0045ab15  6a00                 push 0
// 0045ab17  6a00                 push 0
// 0045ab19  ffd0                 call eax
// 0045ab1b  50                   push eax
// 0045ab1c  e84f220300           call 0x48cd70
// 0045ab21  83c40c               add esp, 0xc
// 0045ab24  b8faaa4500           mov eax, 0x45aafa
// 0045ab29  c3                   ret 

struct VTable {
    void* p0;
    int (__thiscall* p1)(void*, int, int);
};

struct ThisClass {
    VTable* vptr;

    int __thiscall sub_45AB10();
};

extern "C" int __cdecl sub_48CD70(int);

int __thiscall ThisClass::sub_45AB10() {
    int result = this->vptr->p1(this, 0, 0);
    sub_48CD70(result);
    return 0x45AAFa;
}
