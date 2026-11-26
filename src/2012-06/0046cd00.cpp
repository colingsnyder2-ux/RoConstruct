// from server: 100% by Xemicl
// roc 2012-06 0046cd00  unit: RBX::TeleportCallback  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046cd00
//
// 0046cd00  6aff                 push -1
// 0046cd02  6862fea900           push 0xa9fe62
// 0046cd07  64a100000000         mov eax, dword ptr fs:[0]
// 0046cd0d  50                   push eax
// 0046cd0e  64892500000000       mov dword ptr fs:[0], esp
// 0046cd15  83ec08               sub esp, 8
// 0046cd18  56                   push esi
// 0046cd19  8bf1                 mov esi, ecx
// 0046cd1b  57                   push edi
// 0046cd1c  89742408             mov dword ptr [esp + 8], esi
// 0046cd20  e8835f5100           call 0x982ca8
// 0046cd25  6a6c                 push 0x6c
// 0046cd27  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0046cd2f  c7064496b500         mov dword ptr [esi], 0xb59644
// 0046cd35  e8e0535100           call 0x98211a
// 0046cd3a  8bf8                 mov edi, eax
// 0046cd3c  83c404               add esp, 4
// 0046cd3f  897c240c             mov dword ptr [esp + 0xc], edi
// 0046cd43  c644241801           mov byte ptr [esp + 0x18], 1
// 0046cd48  85ff                 test edi, edi
// 0046cd4a  7420                 je 0x46cd6c
// 0046cd4c  e88f86faff           call 0x4153e0
// 0046cd51  50                   push eax
// 0046cd52  e869c1fdff           call 0x448ec0
// 0046cd57  50                   push eax
// 0046cd58  e8a386faff           call 0x415400
// 0046cd5d  50                   push eax
// 0046cd5e  68b9000000           push 0xb9
// 0046cd63  8bcf                 mov ecx, edi
// 0046cd65  e8385f5100           call 0x982ca2
// 0046cd6a  eb02                 jmp 0x46cd6e
// 0046cd6c  33c0                 xor eax, eax
// 0046cd6e  50                   push eax
// 0046cd6f  8bce                 mov ecx, esi
// 0046cd71  c644241c00           mov byte ptr [esp + 0x1c], 0
// 0046cd76  894620               mov dword ptr [esi + 0x20], eax
// 0046cd79  e81e5f5100           call 0x982c9c
// 0046cd7e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0046cd82  5f                   pop edi
// 0046cd83  8bc6                 mov eax, esi
// 0046cd85  5e                   pop esi
// 0046cd86  64890d00000000       mov dword ptr fs:[0], ecx
// 0046cd8d  83c414               add esp, 0x14
// 0046cd90  c3                   ret 
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