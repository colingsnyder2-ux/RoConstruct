// from server: 100% by EspClaude
// from server: 73% by EspClaude
// roc 2009-06 006272d0  unit: RBX::Tool  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006272d0
//
// 006272d0  56                   push esi
// 006272d1  57                   push edi
// 006272d2  8bf1                 mov esi, ecx
// 006272d4  e887520100           call 0x63c560
// 006272d9  85c0                 test eax, eax
// 006272db  7504                 jne 0x6272e1
// 006272dd  33ff                 xor edi, edi
// 006272df  eb21                 jmp 0x627302
// 006272e1  56                   push esi
// 006272e2  e8996f0000           call 0x62e280
// 006272e7  83c404               add esp, 4
// 006272ea  84c0                 test al, al
// 006272ec  7507                 jne 0x6272f5
// 006272ee  bf01000000           mov edi, 1
// 006272f3  eb0d                 jmp 0x627302
// 006272f5  8b4648               mov eax, dword ptr [esi + 0x48]
// 006272f8  50                   push eax
// 006272f9  8bce                 mov ecx, esi
// 006272fb  e8d0f9ffff           call 0x626cd0
// 00627300  8bf8                 mov edi, eax
// 00627302  56                   push esi
// 00627303  e8c8c4e8ff           call 0x4b37d0
// 00627308  83c404               add esp, 4
// 0062730b  50                   push eax
// 0062730c  57                   push edi
// 0062730d  8bce                 mov ecx, esi
// 0062730f  e8ec330000           call 0x62a700
// 00627314  5f                   pop edi
// 00627315  5e                   pop esi
// 00627316  c3                   ret 

// from server: 100% by tester
// roc 2008-06 005fdb70  unit: RBX::Tool  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005fdb70
//
// 005fdb70  56                   push esi
// 005fdb71  57                   push edi
// 005fdb72  8bf1                 mov esi, ecx
// 005fdb74  e8272dfbff           call 0x5b08a0
// 005fdb79  85c0                 test eax, eax
// 005fdb7b  7504                 jne 0x5fdb81
// 005fdb7d  33ff                 xor edi, edi
// 005fdb7f  eb24                 jmp 0x5fdba5
// 005fdb81  56                   push esi
// 005fdb82  e84958faff           call 0x5a33d0
// 005fdb87  83c404               add esp, 4
// 005fdb8a  84c0                 test al, al
// 005fdb8c  7507                 jne 0x5fdb95
// 005fdb8e  bf01000000           mov edi, 1
// 005fdb93  eb10                 jmp 0x5fdba5
// 005fdb95  8b8604010000         mov eax, dword ptr [esi + 0x104]
// 005fdb9b  50                   push eax
// 005fdb9c  8bce                 mov ecx, esi
// 005fdb9e  e8bdf8ffff           call 0x5fd460
// 005fdba3  8bf8                 mov edi, eax
// 005fdba5  56                   push esi
// 005fdba6  e825bde8ff           call 0x4898d0
// 005fdbab  83c404               add esp, 4
// 005fdbae  50                   push eax
// 005fdbaf  57                   push edi
// 005fdbb0  8bce                 mov ecx, esi
// 005fdbb2  e8491d0000           call 0x5ff900
// 005fdbb7  5f                   pop edi
// 005fdbb8  5e                   pop esi
// 005fdbb9  c3                   ret 

struct Tool {
    char pad[0x48];
    int field_bc;
    int method_5d1ae0();
    int method_5d1b60(int);
    void method_5d4650(int, int);
    void method_5d2200();
};

extern "C" bool __cdecl sub_57d570(Tool*);
extern "C" int __cdecl sub_486830(Tool*);

void Tool::method_5d2200() {
    int edi;
    if (this->method_5d1ae0() == 0) {
        edi = 0;
    } else if (sub_57d570(this) == false) {
        edi = 1;
    } else {
        edi = this->method_5d1b60(this->field_bc);
    }
    this->method_5d4650(edi, sub_486830(this));
}
