// from server: 58% by colin
// roc 2007-08 00674f30  unit: seg_00670000  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00674f30
//
// 00674f30  e8e9bafbff           call 0x630a1e
// 00674f35  81c428010000         add esp, 0x128
// 00674f3b  c20400               ret 4
// 00674f3e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00674f42  56                   push esi
// 00674f43  e8f4370c00           call 0x73873c
// 00674f48  b801000000           mov eax, 1
// 00674f4d  ebd5                 jmp 0x674f24

extern "C" void __cdecl sub_630a1e();
extern "C" void __fastcall sub_73873c(int);
extern "C" void __cdecl sub_674f24();

struct CXTPCustomizeSheet {
    int OnCommand(int nID);
};

int CXTPCustomizeSheet::OnCommand(int nID)
{
    sub_630a1e();
    sub_73873c(nID);
    sub_674f24();
    return 1;
}
