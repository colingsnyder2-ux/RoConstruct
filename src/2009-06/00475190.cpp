// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0068fde0  unit: Ogre::RbxSceneManagerFactory  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068fde0
//
// 0068fde0  6aff                 push -1
// 0068fde2  683bf47b00           push 0x7bf43b
// 0068fde7  64a100000000         mov eax, dword ptr fs:[0]
// 0068fded  50                   push eax
// 0068fdee  64892500000000       mov dword ptr fs:[0], esp
// 0068fdf5  51                   push ecx
// 0068fdf6  68048c0000           push 0x8c04
// 0068fdfb  e8200b0100           call 0x6a0920
// 0068fe00  83c404               add esp, 4
// 0068fe03  890424               mov dword ptr [esp], eax
// 0068fe06  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0068fe0e  85c0                 test eax, eax
// 0068fe10  741d                 je 0x68fe2f
// 0068fe12  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0068fe16  51                   push ecx
// 0068fe17  8bc8                 mov ecx, eax
// 0068fe19  e8a2e9ffff           call 0x68e7c0
// 0068fe1e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0068fe22  64890d00000000       mov dword ptr fs:[0], ecx
// 0068fe29  83c410               add esp, 0x10
// 0068fe2c  c20400               ret 4
// 0068fe2f  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0068fe33  33c0                 xor eax, eax
// 0068fe35  64890d00000000       mov dword ptr fs:[0], ecx
// 0068fe3c  83c410               add esp, 0x10
// 0068fe3f  c20400               ret 4

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct SceneManager
{
    char storage[0x8e40];
    SceneManager(unsigned int);
};

struct Factory
{
    SceneManager* create(unsigned int);
};

SceneManager* Factory::create(unsigned int value)
{
    return new SceneManager(value);
}
