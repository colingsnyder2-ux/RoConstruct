// from server: 100% by EspClaude
// from server: 97% by EspClaude
// roc 2009-06 0062aad0  unit: RBX::VTool::?$EventDesc  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0062aad0
//
// 0062aad0  53                   push ebx
// 0062aad1  56                   push esi
// 0062aad2  8bf1                 mov esi, ecx
// 0062aad4  8b9e24010000         mov ebx, dword ptr [esi + 0x124]
// 0062aada  57                   push edi
// 0062aadb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0062aadf  3bfb                 cmp edi, ebx
// 0062aae1  7e77                 jle 0x62ab5a
// 0062aae3  6814b7a400           push 0xa4b714
// 0062aae8  89be24010000         mov dword ptr [esi + 0x124], edi
// 0062aaee  e8dd17deff           call 0x40c2d0
// 0062aaf3  56                   push esi
// 0062aaf4  e8d78ce8ff           call 0x4b37d0
// 0062aaf9  83c404               add esp, 4
// 0062aafc  85c0                 test eax, eax
// 0062aafe  745a                 je 0x62ab5a
// 0062ab00  6a01                 push 1
// 0062ab02  56                   push esi
// 0062ab03  e87894e9ff           call 0x4c3f80
// 0062ab08  83c408               add esp, 8
// 0062ab0b  84c0                 test al, al
// 0062ab0d  744b                 je 0x62ab5a
// 0062ab0f  83be2001000005       cmp dword ptr [esi + 0x120], 5
// 0062ab16  7c42                 jl 0x62ab5a
// 0062ab18  8d47ff               lea eax, [edi - 1]
// 0062ab1b  3bc3                 cmp eax, ebx
// 0062ab1d  7e1d                 jle 0x62ab3c
// 0062ab1f  2501000080           and eax, 0x80000001
// 0062ab24  7905                 jns 0x62ab2b
// 0062ab26  48                   dec eax
// 0062ab27  83c8fe               or eax, 0xfffffffe
// 0062ab2a  40                   inc eax
// 0062ab2b  f7d8                 neg eax
// 0062ab2d  1bc0                 sbb eax, eax
// 0062ab2f  f7d8                 neg eax
// 0062ab31  83c005               add eax, 5
// 0062ab34  50                   push eax
// 0062ab35  8bce                 mov ecx, esi
// 0062ab37  e894fbffff           call 0x62a6d0
// 0062ab3c  81e701000080         and edi, 0x80000001
// 0062ab42  7905                 jns 0x62ab49
// 0062ab44  4f                   dec edi
// 0062ab45  83cffe               or edi, 0xfffffffe
// 0062ab48  47                   inc edi
// 0062ab49  f7df                 neg edi
// 0062ab4b  1bff                 sbb edi, edi
// 0062ab4d  f7df                 neg edi
// 0062ab4f  83c705               add edi, 5
// 0062ab52  57                   push edi
// 0062ab53  8bce                 mov ecx, esi
// 0062ab55  e876fbffff           call 0x62a6d0
// 0062ab5a  5f                   pop edi
// 0062ab5b  5e                   pop esi
// 0062ab5c  5b                   pop ebx
// 0062ab5d  c20400               ret 4

// from server: 100% by king_originala
// roc 2008-06 00600420  unit: RBX::VTool::?$BoundPropGetSet  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00600420
//
// 00600420  53                   push ebx
// 00600421  56                   push esi
// 00600422  8bf1                 mov esi, ecx
// 00600424  8b9ec8010000         mov ebx, dword ptr [esi + 0x1c8]
// 0060042a  57                   push edi
// 0060042b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0060042f  3bfb                 cmp edi, ebx
// 00600431  7e77                 jle 0x6004aa
// 00600433  68c4b79700           push 0x97b7c4
// 00600438  89bec8010000         mov dword ptr [esi + 0x1c8], edi
// 0060043e  e8bdd6e0ff           call 0x40db00
// 00600443  56                   push esi
// 00600444  e88794e8ff           call 0x4898d0
// 00600449  83c404               add esp, 4
// 0060044c  85c0                 test eax, eax
// 0060044e  745a                 je 0x6004aa
// 00600450  6a01                 push 1
// 00600452  56                   push esi
// 00600453  e8585ae9ff           call 0x495eb0
// 00600458  83c408               add esp, 8
// 0060045b  84c0                 test al, al
// 0060045d  744b                 je 0x6004aa
// 0060045f  83bec401000005       cmp dword ptr [esi + 0x1c4], 5
// 00600466  7c42                 jl 0x6004aa
// 00600468  8d47ff               lea eax, [edi - 1]
// 0060046b  3bc3                 cmp eax, ebx
// 0060046d  7e1d                 jle 0x60048c
// 0060046f  2501000080           and eax, 0x80000001
// 00600474  7905                 jns 0x60047b
// 00600476  48                   dec eax
// 00600477  83c8fe               or eax, 0xfffffffe
// 0060047a  40                   inc eax
// 0060047b  f7d8                 neg eax
// 0060047d  1bc0                 sbb eax, eax
// 0060047f  f7d8                 neg eax
// 00600481  83c005               add eax, 5
// 00600484  50                   push eax
// 00600485  8bce                 mov ecx, esi
// 00600487  e844f4ffff           call 0x5ff8d0
// 0060048c  81e701000080         and edi, 0x80000001
// 00600492  7905                 jns 0x600499
// 00600494  4f                   dec edi
// 00600495  83cffe               or edi, 0xfffffffe
// 00600498  47                   inc edi
// 00600499  f7df                 neg edi
// 0060049b  1bff                 sbb edi, edi
// 0060049d  f7df                 neg edi
// 0060049f  83c705               add edi, 5
// 006004a2  57                   push edi
// 006004a3  8bce                 mov ecx, esi
// 006004a5  e826f4ffff           call 0x5ff8d0
// 006004aa  5f                   pop edi
// 006004ab  5e                   pop esi
// 006004ac  5b                   pop ebx
// 006004ad  c20400               ret 4

extern char propertyDescriptor;
extern "C" int __cdecl sub_4898d0(int);
extern "C" int __cdecl sub_495eb0(int, int);

struct S
{
    char storage[0x120];
    int value;
    int count;

    void notify(const void *descriptor);
    void setValue(int newValue);
    void f(int newCount);
};

void S::f(int newCount)
{
    int oldCount = count;
    if (newCount > oldCount)
    {
        count = newCount;
        notify(&propertyDescriptor);
        if (sub_4898d0((int)this))
        {
            if ((unsigned char)sub_495eb0((int)this, 1))
            {
                if (value >= 5)
                {
                    if (newCount - 1 > oldCount)
                        setValue(5 + ((newCount - 1) % 2 != 0));
                    setValue(5 + (newCount % 2 != 0));
                }
            }
        }
    }
}
