// from server: 100% by EspClaude
// roc 2009-06 0046c600  unit: DxUserInput  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0046c600
//
// 0046c600  6aff                 push -1
// 0046c602  6839068500           push 0x850639
// 0046c607  64a100000000         mov eax, dword ptr fs:[0]
// 0046c60d  50                   push eax
// 0046c60e  64892500000000       mov dword ptr fs:[0], esp
// 0046c615  51                   push ecx
// 0046c616  56                   push esi
// 0046c617  57                   push edi
// 0046c618  8bf1                 mov esi, ecx
// 0046c61a  33ff                 xor edi, edi
// 0046c61c  6888d08b00           push 0x8bd088
// 0046c621  8d4c240c             lea ecx, [esp + 0xc]
// 0046c625  897c240c             mov dword ptr [esp + 0xc], edi
// 0046c629  ff1508fd8900         call dword ptr [0x89fd08]
// 0046c62f  8d442408             lea eax, [esp + 8]
// 0046c633  897c2414             mov dword ptr [esp + 0x14], edi
// 0046c637  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0046c63b  50                   push eax
// 0046c63c  57                   push edi
// 0046c63d  8bce                 mov ecx, esi
// 0046c63f  e81cfeffff           call 0x46c460
// 0046c644  8d4c2408             lea ecx, [esp + 8]
// 0046c648  ff1510fd8900         call dword ptr [0x89fd10]
// 0046c64e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0046c652  8bc7                 mov eax, edi
// 0046c654  5f                   pop edi
// 0046c655  5e                   pop esi
// 0046c656  64890d00000000       mov dword ptr fs:[0], ecx
// 0046c65d  83c410               add esp, 0x10
// 0046c660  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX00001f_0046a440@DxUserInput@ns_ROCX00001f@@QAEHH@Z)

namespace ns_ROCX00001f {
// from server: 92% by king_originala
// roc 2008-06 0046a440  unit: DxUserInput  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046a440
//
// 0046a440  6aff                 push -1
// 0046a442  68c9107c00           push 0x7c10c9
// 0046a447  64a100000000         mov eax, dword ptr fs:[0]
// 0046a44d  50                   push eax
// 0046a44e  64892500000000       mov dword ptr fs:[0], esp
// 0046a455  51                   push ecx
// 0046a456  56                   push esi
// 0046a457  57                   push edi
// 0046a458  8bf1                 mov esi, ecx
// 0046a45a  33ff                 xor edi, edi
// 0046a45c  6878c48100           push 0x81c478
// 0046a461  8d4c240c             lea ecx, [esp + 0xc]
// 0046a465  897c240c             mov dword ptr [esp + 0xc], edi
// 0046a469  ff15103f8000         call dword ptr [0x803f10]
// 0046a46f  8d442408             lea eax, [esp + 8]
// 0046a473  897c2414             mov dword ptr [esp + 0x14], edi
// 0046a477  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0046a47b  50                   push eax
// 0046a47c  57                   push edi
// 0046a47d  8bce                 mov ecx, esi
// 0046a47f  e8ecfeffff           call 0x46a370
// 0046a484  8d4c2408             lea ecx, [esp + 8]
// 0046a488  ff15143f8000         call dword ptr [0x803f14]
// 0046a48e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0046a492  8bc7                 mov eax, edi
// 0046a494  5f                   pop edi
// 0046a495  5e                   pop esi
// 0046a496  64890d00000000       mov dword ptr fs:[0], ecx
// 0046a49d  83c410               add esp, 0x10
// 0046a4a0  c20400               ret 4

struct Text;

extern void (__thiscall *constructText)(Text *, const char *);
extern void (__thiscall *destroyText)(Text *);

struct Text {
    void *data;
    Text(const char *);
    __declspec(dllimport) ~Text() throw();
};

inline Text::Text(const char *value) : data(0)
{
    constructText(this, value);
}

struct DxUserInput {
    void helper(int, const Text *);
    int fn_ROCX00001f_0046a440(int);
};

int DxUserInput::fn_ROCX00001f_0046a440(int value)
{
    Text name("FileVersion");
    helper(value, &name);
    return value;
}
}
