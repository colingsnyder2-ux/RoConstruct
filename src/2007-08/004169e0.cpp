// from server: 89% by EspClaude
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
    unsigned int reserved[4];
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
        blocks[index] = allocate(32);

    construct(blocks[index], value);
    ++count;
}
