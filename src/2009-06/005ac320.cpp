// from server: 100% by EspClaude
// from server: 82% by EspClaude
// roc 2009-06 005ac320  unit: RBX::Mesh  size: 541 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005ac320
//
// 005ac320  55                   push ebp
// 005ac321  8bec                 mov ebp, esp
// 005ac323  6aff                 push -1
// 005ac325  68570f8600           push 0x860f57
// 005ac32a  64a100000000         mov eax, dword ptr fs:[0]
// 005ac330  50                   push eax
// 005ac331  64892500000000       mov dword ptr fs:[0], esp
// 005ac338  83ec24               sub esp, 0x24
// 005ac33b  56                   push esi
// 005ac33c  894dd4               mov dword ptr [ebp - 0x2c], ecx
// 005ac33f  8b45d4               mov eax, dword ptr [ebp - 0x2c]
// 005ac342  8b4804               mov ecx, dword ptr [eax + 4]
// 005ac345  894df0               mov dword ptr [ebp - 0x10], ecx
// 005ac348  8b55d4               mov edx, dword ptr [ebp - 0x2c]
// 005ac34b  8b4508               mov eax, dword ptr [ebp + 8]
// 005ac34e  894204               mov dword ptr [edx + 4], eax
// 005ac351  8b4dd4               mov ecx, dword ptr [ebp - 0x2c]
// 005ac354  8b5104               mov edx, dword ptr [ecx + 4]
// 005ac357  8955ec               mov dword ptr [ebp - 0x14], edx
// 005ac35a  eb09                 jmp 0x5ac365
// 005ac35c  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 005ac35f  83c001               add eax, 1
// 005ac362  8945ec               mov dword ptr [ebp - 0x14], eax
// 005ac365  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 005ac368  3b4df0               cmp ecx, dword ptr [ebp - 0x10]
// 005ac36b  7d02                 jge 0x5ac36f
// 005ac36d  ebed                 jmp 0x5ac35c
// 005ac36f  8b15cc2da400         mov edx, dword ptr [0xa42dcc]
// 005ac375  83e201               and edx, 1
// 005ac378  752c                 jne 0x5ac3a6
// 005ac37a  a1cc2da400           mov eax, dword ptr [0xa42dcc]
// 005ac37f  83c801               or eax, 1
// 005ac382  a3cc2da400           mov dword ptr [0xa42dcc], eax
// 005ac387  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005ac38e  6a01                 push 1
// 005ac390  6a0a                 push 0xa
// 005ac392  e8195eedff           call 0x4821b0
// 005ac397  83c408               add esp, 8
// 005ac39a  a3c82da400           mov dword ptr [0xa42dc8], eax
// 005ac39f  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 005ac3a6  8b4dd4               mov ecx, dword ptr [ebp - 0x2c]
// 005ac3a9  8b55d4               mov edx, dword ptr [ebp - 0x2c]
// 005ac3ac  8b4104               mov eax, dword ptr [ecx + 4]
// 005ac3af  3b4208               cmp eax, dword ptr [edx + 8]
// 005ac3b2  0f8ec7000000         jle 0x5ac47f
// 005ac3b8  8b4dd4               mov ecx, dword ptr [ebp - 0x2c]
// 005ac3bb  83790800             cmp dword ptr [ecx + 8], 0
// 005ac3bf  751e                 jne 0x5ac3df
// 005ac3c1  8b55d4               mov edx, dword ptr [ebp - 0x2c]
// 005ac3c4  8b4508               mov eax, dword ptr [ebp + 8]
// 005ac3c7  894208               mov dword ptr [edx + 8], eax
// 005ac3ca  33c9                 xor ecx, ecx
// 005ac3cc  75fc                 jne 0x5ac3ca
// 005ac3ce  8b55f0               mov edx, dword ptr [ebp - 0x10]
// 005ac3d1  52                   push edx
// 005ac3d2  8b4dd4               mov ecx, dword ptr [ebp - 0x2c]
// 005ac3d5  e8d60b0000           call 0x5acfb0
// 005ac3da  e99e000000           jmp 0x5ac47d
// 005ac3df  8b45d4               mov eax, dword ptr [ebp - 0x2c]
// 005ac3e2  8b4804               mov ecx, dword ptr [eax + 4]
// 005ac3e5  3b0dc82da400         cmp ecx, dword ptr [0xa42dc8]
// 005ac3eb  7d0d                 jge 0x5ac3fa
// 005ac3ed  8b55d4               mov edx, dword ptr [ebp - 0x2c]
// 005ac3f0  a1c82da400           mov eax, dword ptr [0xa42dc8]
// 005ac3f5  894208               mov dword ptr [edx + 8], eax
// 005ac3f8  eb77                 jmp 0x5ac471
// 005ac3fa  d90548e88b00         fld dword ptr [0x8be848]
// 005ac400  d95de8               fstp dword ptr [ebp - 0x18]
// 005ac403  8b4dd4               mov ecx, dword ptr [ebp - 0x2c]
// 005ac406  8b5108               mov edx, dword ptr [ecx + 8]
// 005ac409  6bd218               imul edx, edx, 0x18
// 005ac40c  8955e4               mov dword ptr [ebp - 0x1c], edx
// 005ac40f  817de4801a0600       cmp dword ptr [ebp - 0x1c], 0x61a80
// 005ac416  760b                 jbe 0x5ac423
// 005ac418  d905a0ef8b00         fld dword ptr [0x8befa0]
// 005ac41e  d95de8               fstp dword ptr [ebp - 0x18]
// 005ac421  eb12                 jmp 0x5ac435
// 005ac423  817de400fa0000       cmp dword ptr [ebp - 0x1c], 0xfa00
// 005ac42a  7609                 jbe 0x5ac435
// 005ac42c  d90544d08b00         fld dword ptr [0x8bd044]
// 005ac432  d95de8               fstp dword ptr [ebp - 0x18]
// 005ac435  8b45d4               mov eax, dword ptr [ebp - 0x2c]
// 005ac438  8b4dd4               mov ecx, dword ptr [ebp - 0x2c]
// 005ac43b  8b7004               mov esi, dword ptr [eax + 4]
// 005ac43e  2b7108               sub esi, dword ptr [ecx + 8]
// 005ac441  8b55d4               mov edx, dword ptr [ebp - 0x2c]
// 005ac444  db4208               fild dword ptr [edx + 8]
// 005ac447  d84de8               fmul dword ptr [ebp - 0x18]
// 005ac44a  e871da1600           call 0x719ec0
// 005ac44f  03f0                 add esi, eax
// 005ac451  8b45d4               mov eax, dword ptr [ebp - 0x2c]
// 005ac454  897008               mov dword ptr [eax + 8], esi
// 005ac457  8b4dd4               mov ecx, dword ptr [ebp - 0x2c]
// 005ac45a  8b5108               mov edx, dword ptr [ecx + 8]
// 005ac45d  3b15c82da400         cmp edx, dword ptr [0xa42dc8]
// 005ac463  7d0c                 jge 0x5ac471
// 005ac465  8b45d4               mov eax, dword ptr [ebp - 0x2c]
// 005ac468  8b0dc82da400         mov ecx, dword ptr [0xa42dc8]
// 005ac46e  894808               mov dword ptr [eax + 8], ecx
// 005ac471  8b55f0               mov edx, dword ptr [ebp - 0x10]
// 005ac474  52                   push edx
// 005ac475  8b4dd4               mov ecx, dword ptr [ebp - 0x2c]
// 005ac478  e8330b0000           call 0x5acfb0
// 005ac47d  eb48                 jmp 0x5ac4c7
// 005ac47f  8b45d4               mov eax, dword ptr [ebp - 0x2c]
// 005ac482  8b4008               mov eax, dword ptr [eax + 8]
// 005ac485  99                   cdq 
// 005ac486  b903000000           mov ecx, 3
// 005ac48b  f7f9                 idiv ecx
// 005ac48d  8b55d4               mov edx, dword ptr [ebp - 0x2c]
// 005ac490  394204               cmp dword ptr [edx + 4], eax
// 005ac493  7f32                 jg 0x5ac4c7
// 005ac495  0fb6450c             movzx eax, byte ptr [ebp + 0xc]
// 005ac499  85c0                 test eax, eax
// 005ac49b  742a                 je 0x5ac4c7
// 005ac49d  8b4dd4               mov ecx, dword ptr [ebp - 0x2c]
// 005ac4a0  8b5104               mov edx, dword ptr [ecx + 4]
// 005ac4a3  3b15c82da400         cmp edx, dword ptr [0xa42dc8]
// 005ac4a9  7e1c                 jle 0x5ac4c7
// 005ac4ab  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 005ac4ae  50                   push eax
// 005ac4af  8b4dd4               mov ecx, dword ptr [ebp - 0x2c]
// 005ac4b2  8b5104               mov edx, dword ptr [ecx + 4]
// 005ac4b5  52                   push edx
// 005ac4b6  e8e55cedff           call 0x4821a0
// 005ac4bb  83c408               add esp, 8
// 005ac4be  50                   push eax
// 005ac4bf  8b4dd4               mov ecx, dword ptr [ebp - 0x2c]
// 005ac4c2  e8e90a0000           call 0x5acfb0
// 005ac4c7  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 005ac4ca  8945e0               mov dword ptr [ebp - 0x20], eax
// 005ac4cd  eb09                 jmp 0x5ac4d8
// 005ac4cf  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 005ac4d2  83c101               add ecx, 1
// 005ac4d5  894de0               mov dword ptr [ebp - 0x20], ecx
// 005ac4d8  8b55d4               mov edx, dword ptr [ebp - 0x2c]
// 005ac4db  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 005ac4de  3b4204               cmp eax, dword ptr [edx + 4]
// 005ac4e1  7d49                 jge 0x5ac52c
// 005ac4e3  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 005ac4e6  6bc918               imul ecx, ecx, 0x18
// 005ac4e9  8b55d4               mov edx, dword ptr [ebp - 0x2c]
// 005ac4ec  030a                 add ecx, dword ptr [edx]
// 005ac4ee  51                   push ecx
// 005ac4ef  6a18                 push 0x18
// 005ac4f1  e80a4be5ff           call 0x401000
// 005ac4f6  83c408               add esp, 8
// 005ac4f9  8945d8               mov dword ptr [ebp - 0x28], eax
// 005ac4fc  c745fc01000000       mov dword ptr [ebp - 4], 1
// 005ac503  837dd800             cmp dword ptr [ebp - 0x28], 0
// 005ac507  740d                 je 0x5ac516
// 005ac509  8b4dd8               mov ecx, dword ptr [ebp - 0x28]
// 005ac50c  e88ff62900           call 0x84bba0
// 005ac511  8945d0               mov dword ptr [ebp - 0x30], eax
// 005ac514  eb07                 jmp 0x5ac51d
// 005ac516  c745d000000000       mov dword ptr [ebp - 0x30], 0
// 005ac51d  8b45d0               mov eax, dword ptr [ebp - 0x30]
// 005ac520  8945dc               mov dword ptr [ebp - 0x24], eax
// 005ac523  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 005ac52a  eba3                 jmp 0x5ac4cf
// 005ac52c  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005ac52f  64890d00000000       mov dword ptr fs:[0], ecx
// 005ac536  5e                   pop esi
// 005ac537  8be5                 mov esp, ebp
// 005ac539  5d                   pop ebp
// 005ac53a  c20800               ret 8

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD


#pragma optimize("", off)

extern int __cdecl iMin(int, int);
extern int __cdecl iMax(int, int);

extern const float growthDefault;
extern const float growthLarge;
extern const float growthMedium;

void* __cdecl operator new(unsigned int, void*);
void __cdecl operator delete(void*, void*);

struct Element {
    char storage[24];
    Element();
};

struct Mesh {
    Element* data;
    int size;
    int capacity;

    void resize(int, bool);
    void reallocate(int);
};

void Mesh::resize(int count, bool allowShrink)
{
    int oldSize = size;
    size = count;

    for (int i = size; i < oldSize; ++i) {
    }

    static int minimum = iMax(10, 1);

    if (size > capacity) {
        if (capacity == 0) {
            capacity = count;
            do {
            } while (0);
            reallocate(oldSize);
        } else {
            if (size < minimum) {
                capacity = minimum;
            } else {
                float growth = growthDefault;
                unsigned int bytes = capacity * sizeof(Element);

                if (bytes > 400000)
                    growth = growthLarge;
                else if (bytes > 64000)
                    growth = growthMedium;

                capacity = size - capacity + int(capacity * growth);

                if (capacity < minimum)
                    capacity = minimum;
            }
            reallocate(oldSize);
        }
    } else if (size <= capacity / 3 && allowShrink && size > minimum) {
        reallocate(iMin(size, oldSize));
    }

    for (int i = oldSize; i < size; ++i) {
        new (data + i) Element;
    }
}
