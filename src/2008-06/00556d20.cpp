// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 74% by colin
// roc 2008-06 00556d20  unit: RBX::VRunService::?$BoundFuncDesc  size: 254 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00556d20
//
// 00556d20  64a100000000         mov eax, dword ptr fs:[0]
// 00556d26  6aff                 push -1
// 00556d28  68d8f47b00           push 0x7bf4d8
// 00556d2d  50                   push eax
// 00556d2e  64892500000000       mov dword ptr fs:[0], esp
// 00556d35  83ec28               sub esp, 0x28
// 00556d38  56                   push esi
// 00556d39  8d842480000000       lea eax, [esp + 0x80]
// 00556d40  50                   push eax
// 00556d41  8d4c2444             lea ecx, [esp + 0x44]
// 00556d45  e80643ebff           call 0x40b050
// 00556d4a  84c0                 test al, al
// 00556d4c  0f859b000000         jne 0x556ded
// 00556d52  8b3590288000         mov esi, dword ptr [0x802890]
// 00556d58  eb06                 jmp 0x556d60
// 00556d5a  8d9b00000000         lea ebx, [ebx]
// 00556d60  8b4c247c             mov ecx, dword ptr [esp + 0x7c]
// 00556d64  803900               cmp byte ptr [ecx], 0
// 00556d67  7562                 jne 0x556dcb
// 00556d69  8b442450             mov eax, dword ptr [esp + 0x50]
// 00556d6d  85c0                 test eax, eax
// 00556d6f  750a                 jne 0x556d7b
// 00556d71  ffd6                 call esi
// 00556d73  8b442450             mov eax, dword ptr [esp + 0x50]
// 00556d77  85c0                 test eax, eax
// 00556d79  7404                 je 0x556d7f
// 00556d7b  8b00                 mov eax, dword ptr [eax]
// 00556d7d  eb02                 jmp 0x556d81
// 00556d7f  33c0                 xor eax, eax
// 00556d81  8b542454             mov edx, dword ptr [esp + 0x54]
// 00556d85  3b5014               cmp edx, dword ptr [eax + 0x14]
// 00556d88  7502                 jne 0x556d8c
// 00556d8a  ffd6                 call esi
// 00556d8c  8b442454             mov eax, dword ptr [esp + 0x54]
// 00556d90  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 00556d94  8b4018               mov eax, dword ptr [eax + 0x18]
// 00556d97  d901                 fld dword ptr [ecx]
// 00556d99  d94104               fld dword ptr [ecx + 4]
// 00556d9c  8b4808               mov ecx, dword ptr [eax + 8]
// 00556d9f  83c008               add eax, 8
// 00556da2  85c9                 test ecx, ecx
// 00556da4  745d                 je 0x556e03
// 00556da6  8b4904               mov ecx, dword ptr [ecx + 4]
// 00556da9  83ec08               sub esp, 8
// 00556dac  d95c2404             fstp dword ptr [esp + 4]
// 00556db0  83c008               add eax, 8
// 00556db3  d91c24               fstp dword ptr [esp]
// 00556db6  50                   push eax
// 00556db7  ffd1                 call ecx
// 00556db9  8b842488000000       mov eax, dword ptr [esp + 0x88]
// 00556dc0  83c40c               add esp, 0xc
// 00556dc3  803800               cmp byte ptr [eax], 0
// 00556dc6  7503                 jne 0x556dcb
// 00556dc8  c60001               mov byte ptr [eax], 1
// 00556dcb  8d4c2440             lea ecx, [esp + 0x40]
// 00556dcf  e8fc30f4ff           call 0x499ed0
// 00556dd4  8d942480000000       lea edx, [esp + 0x80]
// 00556ddb  52                   push edx
// 00556ddc  8d4c2444             lea ecx, [esp + 0x44]
// 00556de0  e86b42ebff           call 0x40b050
// 00556de5  84c0                 test al, al
// 00556de7  0f8473ffffff         je 0x556d60
// 00556ded  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00556df1  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 00556df5  5e                   pop esi
// 00556df6  64890d00000000       mov dword ptr fs:[0], ecx
// 00556dfd  83c434               add esp, 0x34
// 00556e00  c28400               ret 0x84
// 00556e03  ddd9                 fstp st(1)
// 00556e05  8d4c2404             lea ecx, [esp + 4]
// 00556e09  ddd8                 fstp st(0)
// 00556e0b  e8e030ebff           call 0x409ef0
// 00556e10  50                   push eax
// 00556e11  c744243800000000     mov dword ptr [esp + 0x38], 0
// 00556e19  e8e236ebff           call 0x40a500

// from server: 73% by king_originala
// roc 2008-06 00556d20  unit: RBX::VRunService::?$BoundFuncDesc  size: 254 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00556d20
//
// 00556d20  64a100000000         mov eax, dword ptr fs:[0]
// 00556d26  6aff                 push -1
// 00556d28  68d8f47b00           push 0x7bf4d8
// 00556d2d  50                   push eax
// 00556d2e  64892500000000       mov dword ptr fs:[0], esp
// 00556d35  83ec28               sub esp, 0x28
// 00556d38  56                   push esi
// 00556d39  8d842480000000       lea eax, [esp + 0x80]
// 00556d40  50                   push eax
// 00556d41  8d4c2444             lea ecx, [esp + 0x44]
// 00556d45  e80643ebff           call 0x40b050
// 00556d4a  84c0                 test al, al
// 00556d4c  0f859b000000         jne 0x556ded
// 00556d52  8b3590288000         mov esi, dword ptr [0x802890]
// 00556d58  eb06                 jmp 0x556d60
// 00556d5a  8d9b00000000         lea ebx, [ebx]
// 00556d60  8b4c247c             mov ecx, dword ptr [esp + 0x7c]
// 00556d64  803900               cmp byte ptr [ecx], 0
// 00556d67  7562                 jne 0x556dcb
// 00556d69  8b442450             mov eax, dword ptr [esp + 0x50]
// 00556d6d  85c0                 test eax, eax
// 00556d6f  750a                 jne 0x556d7b
// 00556d71  ffd6                 call esi
// 00556d73  8b442450             mov eax, dword ptr [esp + 0x50]
// 00556d77  85c0                 test eax, eax
// 00556d79  7404                 je 0x556d7f
// 00556d7b  8b00                 mov eax, dword ptr [eax]
// 00556d7d  eb02                 jmp 0x556d81
// 00556d7f  33c0                 xor eax, eax
// 00556d81  8b542454             mov edx, dword ptr [esp + 0x54]
// 00556d85  3b5014               cmp edx, dword ptr [eax + 0x14]
// 00556d88  7502                 jne 0x556d8c
// 00556d8a  ffd6                 call esi
// 00556d8c  8b442454             mov eax, dword ptr [esp + 0x54]
// 00556d90  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 00556d94  8b4018               mov eax, dword ptr [eax + 0x18]
// 00556d97  d901                 fld dword ptr [ecx]
// 00556d99  d94104               fld dword ptr [ecx + 4]
// 00556d9c  8b4808               mov ecx, dword ptr [eax + 8]
// 00556d9f  83c008               add eax, 8
// 00556da2  85c9                 test ecx, ecx
// 00556da4  745d                 je 0x556e03
// 00556da6  8b4904               mov ecx, dword ptr [ecx + 4]
// 00556da9  83ec08               sub esp, 8
// 00556dac  d95c2404             fstp dword ptr [esp + 4]
// 00556db0  83c008               add eax, 8
// 00556db3  d91c24               fstp dword ptr [esp]
// 00556db6  50                   push eax
// 00556db7  ffd1                 call ecx
// 00556db9  8b842488000000       mov eax, dword ptr [esp + 0x88]
// 00556dc0  83c40c               add esp, 0xc
// 00556dc3  803800               cmp byte ptr [eax], 0
// 00556dc6  7503                 jne 0x556dcb
// 00556dc8  c60001               mov byte ptr [eax], 1
// 00556dcb  8d4c2440             lea ecx, [esp + 0x40]
// 00556dcf  e8fc30f4ff           call 0x499ed0
// 00556dd4  8d942480000000       lea edx, [esp + 0x80]
// 00556ddb  52                   push edx
// 00556ddc  8d4c2444             lea ecx, [esp + 0x44]
// 00556de0  e86b42ebff           call 0x40b050
// 00556de5  84c0                 test al, al
// 00556de7  0f8473ffffff         je 0x556d60
// 00556ded  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00556df1  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 00556df5  5e                   pop esi
// 00556df6  64890d00000000       mov dword ptr fs:[0], ecx
// 00556dfd  83c434               add esp, 0x34
// 00556e00  c28400               ret 0x84
// 00556e03  ddd9                 fstp st(1)
// 00556e05  8d4c2404             lea ecx, [esp + 4]
// 00556e09  ddd8                 fstp st(0)
// 00556e0b  e8e030ebff           call 0x409ef0
// 00556e10  50                   push eax
// 00556e11  c744243800000000     mov dword ptr [esp + 0x38], 0
// 00556e19  e8e236ebff           call 0x40a500
#include <intrin.h>

extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();

struct Failure
{
    unsigned long words[10];
    Failure();
    ~Failure();
};

__declspec(noreturn) void __cdecl raise_exception(const void *);

struct Arguments
{
    float first;
    float second;
};

struct FunctionTable
{
    void *unused;
    void (__cdecl *invoke)(void *, float, float);
};

struct Function
{
    FunctionTable *table;
    unsigned long reserved;
    unsigned char storage[1];
};

struct Callable
{
    unsigned long padding[2];
    Function function;
};

struct Node
{
    unsigned long padding[6];
    Callable *callable;
};

struct List
{
    unsigned long padding[5];
    Node *end;
};

struct Iterator
{
    unsigned long padding[4];
    List **owner;
    Node *node;
    unsigned long state[8];
    Arguments *arguments;
    bool *cached;

    bool equal(const Iterator &) const;
    void advance();
};

struct Result
{
    Result() {}
};

Result __stdcall combine(Iterator first, Iterator last)
{
    while (!first.equal(last))
    {
        if (!*first.cached)
        {
            if (!first.owner)
                _invalid_parameter_noinfo();

            List *list = first.owner ? *first.owner : 0;
            if (first.node == list->end)
                _invalid_parameter_noinfo();

            Function &f = first.node->callable->function;
            float a = first.arguments->first;
            float b = first.arguments->second;

            if (!f.table)
                raise_exception(&Failure());

            f.table->invoke(f.storage, a, b);

            if (!*first.cached)
                *first.cached = true;
        }

        first.advance();
    }

    return Result();
}
