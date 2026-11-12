// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 45% by colin
// roc 2007-08 005601b0  unit: RBX::VModelInstance::?$FilteredSelection  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005601b0
//
// 005601b0  6aff                 push -1
// 005601b2  68f93d7500           push 0x753df9
// 005601b7  64a100000000         mov eax, dword ptr fs:[0]
// 005601bd  50                   push eax
// 005601be  64892500000000       mov dword ptr fs:[0], esp
// 005601c5  51                   push ecx
// 005601c6  53                   push ebx
// 005601c7  55                   push ebp
// 005601c8  56                   push esi
// 005601c9  57                   push edi
// 005601ca  33ff                 xor edi, edi
// 005601cc  897c2410             mov dword ptr [esp + 0x10], edi
// 005601d0  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 005601d4  55                   push ebp
// 005601d5  8bf1                 mov esi, ecx
// 005601d7  897c2420             mov dword ptr [esp + 0x20], edi
// 005601db  e8c076eaff           call 0x4078a0
// 005601e0  83c404               add esp, 4
// 005601e3  8b4d00               mov ecx, dword ptr [ebp]
// 005601e6  56                   push esi
// 005601e7  897c2420             mov dword ptr [esp + 0x20], edi
// 005601eb  c744241401000000     mov dword ptr [esp + 0x14], 1
// 005601f3  e83814feff           call 0x541630
// 005601f8  8b742428             mov esi, dword ptr [esp + 0x28]
// 005601fc  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00560200  85f6                 test esi, esi
// 00560202  7406                 je 0x56020a
// 00560204  3b742430             cmp esi, dword ptr [esp + 0x30]
// 00560208  7406                 je 0x560210
// 0056020a  ff15d8e67700         call dword ptr [0x77e6d8]
// 00560210  3b7c2434             cmp edi, dword ptr [esp + 0x34]
// 00560214  7430                 je 0x560246
// 00560216  85f6                 test esi, esi
// 00560218  8b5d00               mov ebx, dword ptr [ebp]
// 0056021b  7506                 jne 0x560223
// 0056021d  ff15d8e67700         call dword ptr [0x77e6d8]
// 00560223  3b7e08               cmp edi, dword ptr [esi + 8]
// 00560226  7206                 jb 0x56022e
// 00560228  ff15d8e67700         call dword ptr [0x77e6d8]
// 0056022e  8b0f                 mov ecx, dword ptr [edi]
// 00560230  53                   push ebx
// 00560231  e8fa13feff           call 0x541630
// 00560236  3b7e08               cmp edi, dword ptr [esi + 8]
// 00560239  7206                 jb 0x560241
// 0056023b  ff15d8e67700         call dword ptr [0x77e6d8]
// 00560241  83c708               add edi, 8
// 00560244  ebba                 jmp 0x560200
// 00560246  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0056024a  5f                   pop edi
// 0056024b  5e                   pop esi
// 0056024c  8bc5                 mov eax, ebp
// 0056024e  5d                   pop ebp
// 0056024f  5b                   pop ebx
// 00560250  64890d00000000       mov dword ptr fs:[0], ecx
// 00560257  83c410               add esp, 0x10
// 0056025a  c21400               ret 0x14

#include <vector>

template<class T> struct shared_ptr {
    T* px;
    void* pn;
    ~shared_ptr();
    T* operator->() const { return px; }
    T* get() const { return px; }
};

struct FilteredSelection {
    void attach(FilteredSelection* other);                  // 0x541630
    static shared_ptr<FilteredSelection> create();           // 0x4078a0
    shared_ptr<FilteredSelection> build(
        std::vector< shared_ptr<FilteredSelection> >::const_iterator first,
        std::vector< shared_ptr<FilteredSelection> >::const_iterator last);
};

shared_ptr<FilteredSelection> FilteredSelection::build(
    std::vector< shared_ptr<FilteredSelection> >::const_iterator first,
    std::vector< shared_ptr<FilteredSelection> >::const_iterator last)
{
    shared_ptr<FilteredSelection> result = create();
    result->attach(this);
    for (; first != last; ++first)
        (*first)->attach(result.get());
    return result;
}
