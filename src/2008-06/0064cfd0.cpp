// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_clumpcollection_c89bbf73068d04a6.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
// from server: 90% by king_originala
// roc 2008-06 0064cfd0  unit: RBX::ClumpStage  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064cfd0
//
// 0064cfd0  6aff                 push -1
// 0064cfd2  68b3b17d00           push 0x7db1b3
// 0064cfd7  64a100000000         mov eax, dword ptr fs:[0]
// 0064cfdd  50                   push eax
// 0064cfde  64892500000000       mov dword ptr fs:[0], esp
// 0064cfe5  83ec08               sub esp, 8
// 0064cfe8  56                   push esi
// 0064cfe9  57                   push edi
// 0064cfea  8bf1                 mov esi, ecx
// 0064cfec  6a78                 push 0x78
// 0064cfee  8974240c             mov dword ptr [esp + 0xc], esi
// 0064cff2  e829390500           call 0x6a0920
// 0064cff7  83c404               add esp, 4
// 0064cffa  8944240c             mov dword ptr [esp + 0xc], eax
// 0064cffe  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0064d002  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0064d00a  85c0                 test eax, eax
// 0064d00c  740b                 je 0x64d019
// 0064d00e  57                   push edi
// 0064d00f  56                   push esi
// 0064d010  8bc8                 mov ecx, eax
// 0064d012  e859c80100           call 0x669870
// 0064d017  eb02                 jmp 0x64d01b
// 0064d019  33c0                 xor eax, eax
// 0064d01b  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0064d01f  894e04               mov dword ptr [esi + 4], ecx
// 0064d022  894608               mov dword ptr [esi + 8], eax
// 0064d025  897e0c               mov dword ptr [esi + 0xc], edi
// 0064d028  8d542424             lea edx, [esp + 0x24]
// 0064d02c  52                   push edx
// 0064d02d  8d442428             lea eax, [esp + 0x28]
// 0064d031  50                   push eax
// 0064d032  8d4e10               lea ecx, [esi + 0x10]
// 0064d035  c744242001000000     mov dword ptr [esp + 0x20], 1
// 0064d03d  c7064cb18400         mov dword ptr [esi], 0x84b14c
// 0064d043  e858e2ffff           call 0x64b2a0
// 0064d048  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0064d04c  5f                   pop edi
// 0064d04d  8bc6                 mov eax, esi
// 0064d04f  5e                   pop esi
// 0064d050  64890d00000000       mov dword ptr fs:[0], ecx
// 0064d057  83c414               add esp, 0x14
// 0064d05a  c20800               ret 8

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Stage;

struct TreeStage {
    char storage[120];
    TreeStage(Stage* owner, Stage* next);
};

typedef std::set<Stage*> Collection;

struct __declspec(novtable) Stage {
    virtual ~Stage();

    Stage* owner;
    TreeStage* tree;
    Stage* next;

    __forceinline Stage(Stage* ownerValue, Stage* nextValue);
};

struct ClumpStage : Stage {
    Collection collection;

    ClumpStage(Stage* ownerValue, Stage* nextValue);
    virtual ~ClumpStage();
};

__forceinline Stage::Stage(Stage* ownerValue, Stage* nextValue)
{
    TreeStage* treeValue = new TreeStage(this, nextValue);
    owner = ownerValue;
    tree = treeValue;
    next = nextValue;
}

ClumpStage::ClumpStage(Stage* ownerValue, Stage* nextValue)
    : Stage(ownerValue, nextValue),
      collection()
{
}
