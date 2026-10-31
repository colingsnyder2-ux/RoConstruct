// from server: 97% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00466fa0  unit: CSettingsDialog  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00466fa0
//
// 00466fa0  6aff                 push -1
// 00466fa2  681afa7b00           push 0x7bfa1a
// 00466fa7  64a100000000         mov eax, dword ptr fs:[0]
// 00466fad  50                   push eax
// 00466fae  64892500000000       mov dword ptr fs:[0], esp
// 00466fb5  51                   push ecx
// 00466fb6  68d4030000           push 0x3d4
// 00466fbb  e860992300           call 0x6a0920
// 00466fc0  83c404               add esp, 4
// 00466fc3  890424               mov dword ptr [esp], eax
// 00466fc6  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00466fce  85c0                 test eax, eax
// 00466fd0  7418                 je 0x466fea
// 00466fd2  6a00                 push 0
// 00466fd4  8bc8                 mov ecx, eax
// 00466fd6  e835feffff           call 0x466e10
// 00466fdb  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00466fdf  64890d00000000       mov dword ptr fs:[0], ecx
// 00466fe6  83c410               add esp, 0x10
// 00466fe9  c3                   ret 
// 00466fea  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00466fee  33c0                 xor eax, eax
// 00466ff0  64890d00000000       mov dword ptr fs:[0], ecx
// 00466ff7  83c410               add esp, 0x10
// 00466ffa  c3                   ret 

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct CSettingsDialog {
    char storage[0x3D4];
    CSettingsDialog(int);
};

CSettingsDialog* createSettingsDialog()
{
    return new CSettingsDialog(0);
}
