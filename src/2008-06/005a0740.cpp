// from server: 100% by colin
// from server: 94% by colin
// roc 2008-06 005a0740  unit: RBX::Workspace  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a0740
//
// 005a0740  56                   push esi
// 005a0741  57                   push edi
// 005a0742  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005a0746  6a00                 push 0
// 005a0748  68d48d9400           push 0x948dd4
// 005a074d  68c8e19200           push 0x92e1c8
// 005a0752  6a00                 push 0
// 005a0754  57                   push edi
// 005a0755  8bf1                 mov esi, ecx
// 005a0757  e86a101000           call 0x6a17c6
// 005a075c  83c414               add esp, 0x14
// 005a075f  81c6c0fcffff         add esi, 0xfffffcc0
// 005a0765  85c0                 test eax, eax
// 005a0767  751e                 jne 0x5a0787
// 005a0769  6a01                 push 1
// 005a076b  56                   push esi
// 005a076c  e83f57efff           call 0x495eb0
// 005a0771  83c408               add esp, 8
// 005a0774  84c0                 test al, al
// 005a0776  7428                 je 0x5a07a0
// 005a0778  85f6                 test esi, esi
// 005a077a  7424                 je 0x5a07a0
// 005a077c  5f                   pop edi
// 005a077d  8d8640030000         lea eax, [esi + 0x340]
// 005a0783  5e                   pop esi
// 005a0784  c20400               ret 4
// 005a0787  56                   push esi
// 005a0788  e813a5efff           call 0x49aca0
// 005a078d  83c404               add esp, 4
// 005a0790  85c0                 test eax, eax
// 005a0792  740c                 je 0x5a07a0
// 005a0794  50                   push eax
// 005a0795  8bcf                 mov ecx, edi
// 005a0797  e84423e8ff           call 0x422ae0
// 005a079c  84c0                 test al, al
// 005a079e  75d8                 jne 0x5a0778
// 005a07a0  5f                   pop edi
// 005a07a1  33c0                 xor eax, eax
// 005a07a3  5e                   pop esi
// 005a07a4  c20400               ret 4

// from server: 78% by colin
// roc 2008-06 005a0740  unit: RBX::Workspace  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a0740
//
// 005a0740  56                   push esi
// 005a0741  57                   push edi
// 005a0742  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005a0746  6a00                 push 0
// 005a0748  68d48d9400           push 0x948dd4
// 005a074d  68c8e19200           push 0x92e1c8
// 005a0752  6a00                 push 0
// 005a0754  57                   push edi
// 005a0755  8bf1                 mov esi, ecx
// 005a0757  e86a101000           call 0x6a17c6
// 005a075c  83c414               add esp, 0x14
// 005a075f  81c6c0fcffff         add esi, 0xfffffcc0
// 005a0765  85c0                 test eax, eax
// 005a0767  751e                 jne 0x5a0787
// 005a0769  6a01                 push 1
// 005a076b  56                   push esi
// 005a076c  e83f57efff           call 0x495eb0
// 005a0771  83c408               add esp, 8
// 005a0774  84c0                 test al, al
// 005a0776  7428                 je 0x5a07a0
// 005a0778  85f6                 test esi, esi
// 005a077a  7424                 je 0x5a07a0
// 005a077c  5f                   pop edi
// 005a077d  8d8640030000         lea eax, [esi + 0x340]
// 005a0783  5e                   pop esi
// 005a0784  c20400               ret 4
// 005a0787  56                   push esi
// 005a0788  e813a5efff           call 0x49aca0
// 005a078d  83c404               add esp, 4
// 005a0790  85c0                 test eax, eax
// 005a0792  740c                 je 0x5a07a0
// 005a0794  50                   push eax
// 005a0795  8bcf                 mov ecx, edi
// 005a0797  e84423e8ff           call 0x422ae0
// 005a079c  84c0                 test al, al
// 005a079e  75d8                 jne 0x5a0778
// 005a07a0  5f                   pop edi
// 005a07a1  33c0                 xor eax, eax
// 005a07a3  5e                   pop esi
// 005a07a4  c20400               ret 4
#include <intrin.h>

namespace RBX {
class Script {
public:
    virtual ~Script();
    bool f(Script* node);
};

class LocalScript : public Script {
};
}
using namespace RBX;

extern "C" bool __cdecl checkOwner(void*, int);
extern "C" Script* __cdecl getCharacter(void*);

struct S {
    S* f(Script* node);
};

S* S::f(Script* node)
{
    LocalScript* script = dynamic_cast<LocalScript*>(node);
    _ReadWriteBarrier();
    char* owner = reinterpret_cast<char*>(this) - 0x340;

    bool ok;
    if (!script) {
        ok = checkOwner(owner, 1);
    } else {
        Script* character = getCharacter(owner);
        ok = character && node->f(character);
    }
    if (ok && owner)
        return reinterpret_cast<S*>(owner + 0x340);

    return 0;
}
