// from server: 100% by Yeetserama
// roc 2007-08 00447e60  unit: CRenderSettings  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00447e60
//
// 00447e60  6aff                 push -1
// 00447e62  68f2f97300           push 0x73f9f2
// 00447e67  64a100000000         mov eax, dword ptr fs:[0]
// 00447e6d  50                   push eax
// 00447e6e  83ec08               sub esp, 8
// 00447e71  56                   push esi
// 00447e72  57                   push edi
// 00447e73  a188518b00           mov eax, dword ptr [0x8b5188]
// 00447e78  33c4                 xor eax, esp
// 00447e7a  50                   push eax
// 00447e7b  8d442414             lea eax, [esp + 0x14]
// 00447e7f  64a300000000         mov dword ptr fs:[0], eax
// 00447e85  8bf1                 mov esi, ecx
// 00447e87  8974240c             mov dword ptr [esp + 0xc], esi
// 00447e8b  e846881e00           call 0x6306d6
// 00447e90  6a6c                 push 0x6c
// 00447e92  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00447e9a  c706ac037900         mov dword ptr [esi], 0x7903ac
// 00447ea0  e851801e00           call 0x62fef6
// 00447ea5  8bf8                 mov edi, eax
// 00447ea7  83c404               add esp, 4
// 00447eaa  897c2410             mov dword ptr [esp + 0x10], edi
// 00447eae  85ff                 test edi, edi
// 00447eb0  c644241c01           mov byte ptr [esp + 0x1c], 1
// 00447eb5  7420                 je 0x447ed7
// 00447eb7  e81429fcff           call 0x40a7d0
// 00447ebc  50                   push eax
// 00447ebd  e85ebefeff           call 0x433d20
// 00447ec2  50                   push eax
// 00447ec3  e82829fcff           call 0x40a7f0
// 00447ec8  50                   push eax
// 00447ec9  68b9000000           push 0xb9
// 00447ece  8bcf                 mov ecx, edi
// 00447ed0  e8fb871e00           call 0x6306d0
// 00447ed5  eb02                 jmp 0x447ed9
// 00447ed7  33c0                 xor eax, eax
// 00447ed9  50                   push eax
// 00447eda  8bce                 mov ecx, esi
// 00447edc  c644242000           mov byte ptr [esp + 0x20], 0
// 00447ee1  894620               mov dword ptr [esi + 0x20], eax
// 00447ee4  e8e1871e00           call 0x6306ca
// 00447ee9  8bc6                 mov eax, esi
// 00447eeb  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00447eef  64890d00000000       mov dword ptr fs:[0], ecx
// 00447ef6  59                   pop ecx
// 00447ef7  5f                   pop edi
// 00447ef8  5e                   pop esi
// 00447ef9  83c414               add esp, 0x14
// 00447efc  c3                   ret 
// copied from an identical function in another client (function ??0S@ns_ROCX000006@@QAE@XZ)

namespace ns_ROCX000006 {
// from server: 100% by king_originala
extern char* fn_ROCX000006_0040df80();
extern char* fn_ROCX000006_0040dfa0();
extern char* fn_ROCX000006_00432fc0();

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
    item = new Item(0xb9, fn_ROCX000006_0040dfa0(),
                    fn_ROCX000006_00432fc0(), fn_ROCX000006_0040df80());
    attach(item);
}
}
