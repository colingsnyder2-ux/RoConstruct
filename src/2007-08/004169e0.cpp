// from server: 100% by Intel
// from server: 89% by EspClaude
// roc 2007-08 004169e0  unit: VCLuaFunction::?$CComObject  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004169e0
//
// 004169e0  56                   push esi
// 004169e1  8bf1                 mov esi, ecx
// 004169e3  8b4610               mov eax, dword ptr [esi + 0x10]
// 004169e6  83c001               add eax, 1
// 004169e9  394608               cmp dword ptr [esi + 8], eax
// 004169ec  57                   push edi
// 004169ed  7707                 ja 0x4169f6
// 004169ef  6a01                 push 1
// 004169f1  e8cafcffff           call 0x4166c0
// 004169f6  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004169f9  037e10               add edi, dword ptr [esi + 0x10]
// 004169fc  8b4608               mov eax, dword ptr [esi + 8]
// 004169ff  3bc7                 cmp eax, edi
// 00416a01  7702                 ja 0x416a05
// 00416a03  2bf8                 sub edi, eax
// 00416a05  8b4e04               mov ecx, dword ptr [esi + 4]
// 00416a08  833cb900             cmp dword ptr [ecx + edi*4], 0
// 00416a0c  7510                 jne 0x416a1e
// 00416a0e  6a0c                 push 0xc
// 00416a10  e8e1942100           call 0x62fef6
// 00416a15  8b5604               mov edx, dword ptr [esi + 4]
// 00416a18  83c404               add esp, 4
// 00416a1b  8904ba               mov dword ptr [edx + edi*4], eax
// 00416a1e  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00416a22  8b4e04               mov ecx, dword ptr [esi + 4]
// 00416a25  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 00416a28  50                   push eax
// 00416a29  52                   push edx
// 00416a2a  e8712d0300           call 0x4497a0
// 00416a2f  83461001             add dword ptr [esi + 0x10], 1
// 00416a33  83c408               add esp, 8
// 00416a36  5f                   pop edi
// 00416a37  5e                   pop esi
// 00416a38  c20400               ret 4

// from server: 100% by king_originala
// roc 2008-06 00419ae0  unit: VCLuaFunction::?$CComObject  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00419ae0
//
// 00419ae0  56                   push esi
// 00419ae1  8bf1                 mov esi, ecx
// 00419ae3  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00419ae6  40                   inc eax
// 00419ae7  57                   push edi
// 00419ae8  394614               cmp dword ptr [esi + 0x14], eax
// 00419aeb  7707                 ja 0x419af4
// 00419aed  6a01                 push 1
// 00419aef  e8acf7ffff           call 0x4192a0
// 00419af4  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00419af7  037e1c               add edi, dword ptr [esi + 0x1c]
// 00419afa  8b4614               mov eax, dword ptr [esi + 0x14]
// 00419afd  3bc7                 cmp eax, edi
// 00419aff  7702                 ja 0x419b03
// 00419b01  2bf8                 sub edi, eax
// 00419b03  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00419b06  833cb900             cmp dword ptr [ecx + edi*4], 0
// 00419b0a  7510                 jne 0x419b1c
// 00419b0c  6a20                 push 0x20
// 00419b0e  e80d6e2800           call 0x6a0920
// 00419b13  8b5610               mov edx, dword ptr [esi + 0x10]
// 00419b16  83c404               add esp, 4
// 00419b19  8904ba               mov dword ptr [edx + edi*4], eax
// 00419b1c  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00419b20  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00419b23  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 00419b26  50                   push eax
// 00419b27  52                   push edx
// 00419b28  e813f50000           call 0x429040
// 00419b2d  ff461c               inc dword ptr [esi + 0x1c]
// 00419b30  83c408               add esp, 8
// 00419b33  5f                   pop edi
// 00419b34  5e                   pop esi
// 00419b35  c20400               ret 4

extern "C" void* __cdecl allocate(unsigned int);
extern "C" void __cdecl construct(void*, const void*);

struct S {
    unsigned int reserved[1];
    void** blocks;
    unsigned int capacity;
    unsigned int start;
    unsigned int count;

    void grow(unsigned int);
    void append(const void*);
};

void S::append(const void* value)
{
    if (capacity <= count + 1)
        grow(1);

    unsigned int index = start + count;
    if (capacity <= index)
        index -= capacity;

    if (blocks[index] == 0)
        blocks[index] = allocate(12);

    construct(blocks[index], value);
    ++count;
}
