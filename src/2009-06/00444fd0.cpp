// from server: 100% by EspClaude
// roc 2009-06 00444fd0  unit: G3D::_WeakPtr  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00444fd0
//
// 00444fd0  6aff                 push -1
// 00444fd2  68a2058500           push 0x8505a2
// 00444fd7  64a100000000         mov eax, dword ptr fs:[0]
// 00444fdd  50                   push eax
// 00444fde  64892500000000       mov dword ptr fs:[0], esp
// 00444fe5  83ec08               sub esp, 8
// 00444fe8  56                   push esi
// 00444fe9  8bf1                 mov esi, ecx
// 00444feb  57                   push edi
// 00444fec  89742408             mov dword ptr [esp + 8], esi
// 00444ff0  e8fb452d00           call 0x7195f0
// 00444ff5  6a6c                 push 0x6c
// 00444ff7  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00444fff  c7061c6b8b00         mov dword ptr [esi], 0x8b6b1c
// 00445005  e82e3a2d00           call 0x718a38
// 0044500a  8bf8                 mov edi, eax
// 0044500c  83c404               add esp, 4
// 0044500f  897c240c             mov dword ptr [esp + 0xc], edi
// 00445013  c644241801           mov byte ptr [esp + 0x18], 1
// 00445018  85ff                 test edi, edi
// 0044501a  7420                 je 0x44503c
// 0044501c  e84f7bfcff           call 0x40cb70
// 00445021  50                   push eax
// 00445022  e88975feff           call 0x42c5b0
// 00445027  50                   push eax
// 00445028  e8637bfcff           call 0x40cb90
// 0044502d  50                   push eax
// 0044502e  68b9000000           push 0xb9
// 00445033  8bcf                 mov ecx, edi
// 00445035  e8b0452d00           call 0x7195ea
// 0044503a  eb02                 jmp 0x44503e
// 0044503c  33c0                 xor eax, eax
// 0044503e  50                   push eax
// 0044503f  8bce                 mov ecx, esi
// 00445041  c644241c00           mov byte ptr [esp + 0x1c], 0
// 00445046  894620               mov dword ptr [esi + 0x20], eax
// 00445049  e896452d00           call 0x7195e4
// 0044504e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00445052  5f                   pop edi
// 00445053  8bc6                 mov eax, esi
// 00445055  5e                   pop esi
// 00445056  64890d00000000       mov dword ptr fs:[0], ecx
// 0044505d  83c414               add esp, 0x14
// 00445060  c3                   ret 
// copied from an identical function in another client (function ??0S@ns_ROCX00000c@@QAE@XZ)

namespace ns_ROCX00000c {
extern char* fn_ROCX00000c_0040df80();
extern char* fn_ROCX00000c_0040dfa0();
extern char* fn_ROCX00000c_00432fc0();

struct Item {
    unsigned char storage[0x6c];
    Item(int, char*, char*, char*);
};

struct Base {
    unsigned char padding[0x1c];
    Base();
    virtual ~Base();
    void attach(Item*);
};

struct S : Base {
    Item* item;
    S();
    virtual ~S();
};

S::S()
{
    item = new Item(0xb9, fn_ROCX00000c_0040dfa0(),
                    fn_ROCX00000c_00432fc0(), fn_ROCX00000c_0040df80());
    attach(item);
}
}
