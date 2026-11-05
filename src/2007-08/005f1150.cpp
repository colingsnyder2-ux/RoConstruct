// from server: 48% by atomic.potato
// roc 2007-08 005f1150  unit: RBX::Reflection::Metadata::VClass::?$BoundPropGetSet  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005f1150
//
// 005f1150  07                   pop es
// 005f1151  7c00                 jl 0x5f1153
// 005f1153  894810               mov dword ptr [eax + 0x10], ecx
// 005f1156  895014               mov dword ptr [eax + 0x14], edx
// 005f1159  eb02                 jmp 0x5f115d
// 005f115b  33c0                 xor eax, eax
// 005f115d  56                   push esi
// 005f115e  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005f1162  6a00                 push 0
// 005f1164  c744240800000000     mov dword ptr [esp + 8], 0
// 005f116c  8906                 mov dword ptr [esi], eax
// 005f116e  e8efea0300           call 0x62fc62
// 005f1173  83c404               add esp, 4
// 005f1176  8bc6                 mov eax, esi
// 005f1178  5e                   pop esi
// 005f1179  59                   pop ecx
// 005f117a  c3                   ret 

struct S {
};

extern "C" int __cdecl sub_62FC62(int);

int __cdecl f(int a, int b) {
    int* p = (int*)a;
    p[4] = a;
    p[5] = b;
    int* out = (int*)b;
    *out = a;
    sub_62FC62(0);
    return b;
}
