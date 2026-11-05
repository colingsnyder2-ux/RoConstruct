// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00615b60  unit: RBX::Unlocked  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00615b60
//
// 00615b60  8b442404             mov eax, dword ptr [esp + 4]
// 00615b64  50                   push eax
// 00615b65  e886a60400           call 0x6601f0
// 00615b6a  0fb6c0               movzx eax, al
// 00615b6d  83c404               add esp, 4
// 00615b70  f7d8                 neg eax
// 00615b72  1bc0                 sbb eax, eax
// 00615b74  83e002               and eax, 2
// 00615b77  c20400               ret 4

extern "C" bool __cdecl sub_6601f0(void*);

int __stdcall sub_615b60(void* arg)
{
    return sub_6601f0(arg) ? 2 : 0;
}
