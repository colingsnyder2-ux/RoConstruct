// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 00619ad0  unit: RBX::FlatTool  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00619ad0
//
// 00619ad0  56                   push esi
// 00619ad1  8b742408             mov esi, dword ptr [esp + 8]
// 00619ad5  8b0e                 mov ecx, dword ptr [esi]
// 00619ad7  e894f1f7ff           call 0x598c70
// 00619adc  8bce                 mov ecx, esi
// 00619ade  e8ad7bfdff           call 0x5f1690
// 00619ae3  8b0e                 mov ecx, dword ptr [esi]
// 00619ae5  e8a6f1f7ff           call 0x598c90
// 00619aea  5e                   pop esi
// 00619aeb  c20400               ret 4

struct S {
    void f(int* p);
};

extern "C" void __fastcall sub_598C70(int);
extern "C" void __fastcall sub_598C90(int);
extern "C" void __fastcall sub_5F1690(int);

void S::f(int* p) {
    sub_598C70(*p);
    sub_5F1690((int)p);
    sub_598C90(*p);
}
