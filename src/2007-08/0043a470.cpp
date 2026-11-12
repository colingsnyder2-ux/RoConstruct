// from server: 66% by EspClaude
// from server: 55% by colin
// roc 2007-08 0043a470  unit: IIHAAH::?$CMap  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043a470
//
// 0043a470  56                   push esi
// 0043a471  57                   push edi
// 0043a472  8bf9                 mov edi, ecx
// 0043a474  85ff                 test edi, edi
// 0043a476  7408                 je 0x43a480
// 0043a478  8db700010000         lea esi, [edi + 0x100]
// 0043a47e  eb02                 jmp 0x43a482
// 0043a480  33f6                 xor esi, esi
// 0043a482  8b4608               mov eax, dword ptr [esi + 8]
// 0043a485  85c0                 test eax, eax
// 0043a487  7409                 je 0x43a492
// 0043a489  50                   push eax
// 0043a48a  e8d3571f00           call 0x62fc62
// 0043a48f  83c404               add esp, 4
// 0043a492  8bcf                 mov ecx, edi
// 0043a494  5f                   pop edi
// 0043a495  c7460800000000       mov dword ptr [esi + 8], 0
// 0043a49c  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 0043a4a3  c7461000000000       mov dword ptr [esi + 0x10], 0
// 0043a4aa  5e                   pop esi
// 0043a4ab  e9a0fc2500           jmp 0x69a150
// 0043a4b0  56                   push esi
// 0043a4b1  57                   push edi
// 0043a4b2  8bf9                 mov edi, ecx
// 0043a4b4  85ff                 test edi, edi
// 0043a4b6  7408                 je 0x43a4c0
// 0043a4b8  8db708010000         lea esi, [edi + 0x108]
// 0043a4be  eb02                 jmp 0x43a4c2
// 0043a4c0  33f6                 xor esi, esi
// 0043a4c2  8b4608               mov eax, dword ptr [esi + 8]
// 0043a4c5  85c0                 test eax, eax
// 0043a4c7  7409                 je 0x43a4d2
// 0043a4c9  50                   push eax
// 0043a4ca  e893571f00           call 0x62fc62
// 0043a4cf  83c404               add esp, 4
// 0043a4d2  8bcf                 mov ecx, edi
// 0043a4d4  5f                   pop edi
// 0043a4d5  c7460800000000       mov dword ptr [esi + 8], 0
// 0043a4dc  c7460c00000000       mov dword ptr [esi + 0xc], 0

struct Buf {
    int pad[2];
    void* first;
    void* last;
    void* end;
};

struct CMap {
    void sub_43a470();
    void sub_69a150();
};

extern "C" void __cdecl sub_62fc62(void*);

void CMap::sub_43a470()
{
    Buf* b = this ? (Buf*)((char*)this + 0x100) : 0;
    if (b->first != 0)
        sub_62fc62(b->first);
    b->first = 0;
    b->last = 0;
    b->end = 0;
    sub_69a150();
}
