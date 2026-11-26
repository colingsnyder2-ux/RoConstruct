// from server: 100% by Xemicl
// roc 2012-06 0059f310  unit: seg_00590000  size: 165 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0059f310
//
// 0059f310  6aff                 push -1
// 0059f312  68c816ab00           push 0xab16c8
// 0059f317  64a100000000         mov eax, dword ptr fs:[0]
// 0059f31d  50                   push eax
// 0059f31e  64892500000000       mov dword ptr fs:[0], esp
// 0059f325  51                   push ecx
// 0059f326  56                   push esi
// 0059f327  8bf1                 mov esi, ecx
// 0059f329  57                   push edi
// 0059f32a  89742408             mov dword ptr [esp + 8], esi
// 0059f32e  837e0800             cmp dword ptr [esi + 8], 0
// 0059f332  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0059f33a  7437                 je 0x59f373
// 0059f33c  8b06                 mov eax, dword ptr [esi]
// 0059f33e  85c0                 test eax, eax
// 0059f340  741d                 je 0x59f35f
// 0059f342  8b48fc               mov ecx, dword ptr [eax - 4]
// 0059f345  8d78fc               lea edi, [eax - 4]
// 0059f348  6890a75900           push 0x59a790
// 0059f34d  51                   push ecx
// 0059f34e  6a08                 push 8
// 0059f350  50                   push eax
// 0059f351  e81a3f3e00           call 0x983270
// 0059f356  57                   push edi
// 0059f357  e85e303e00           call 0x9823ba
// 0059f35c  83c404               add esp, 4
// 0059f35f  c7460800000000       mov dword ptr [esi + 8], 0
// 0059f366  c70600000000         mov dword ptr [esi], 0
// 0059f36c  c7460400000000       mov dword ptr [esi + 4], 0
// 0059f373  837e0800             cmp dword ptr [esi + 8], 0
// 0059f377  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0059f37f  7623                 jbe 0x59f3a4
// 0059f381  8b36                 mov esi, dword ptr [esi]
// 0059f383  85f6                 test esi, esi
// 0059f385  741d                 je 0x59f3a4
// 0059f387  8b56fc               mov edx, dword ptr [esi - 4]
// 0059f38a  6890a75900           push 0x59a790
// 0059f38f  8d7efc               lea edi, [esi - 4]
// 0059f392  52                   push edx
// 0059f393  6a08                 push 8
// 0059f395  56                   push esi
// 0059f396  e8d53e3e00           call 0x983270
// 0059f39b  57                   push edi
// 0059f39c  e819303e00           call 0x9823ba
// 0059f3a1  83c404               add esp, 4
// 0059f3a4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0059f3a8  5f                   pop edi
// 0059f3a9  5e                   pop esi
// 0059f3aa  64890d00000000       mov dword ptr fs:[0], ecx
// 0059f3b1  83c410               add esp, 0x10
// 0059f3b4  c3                   ret 
// copied from an identical function in another client (function ??1Holder@@QAE@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace DataStructures {
template<class list_type> class List {
public:
    ~List()
    {
        if (allocation_size > 0)
            delete[] listArray;
    }
    void Clear(bool doNotDeallocateSmallBlocks = false)
    {
        if (allocation_size == 0)
            return;
        if (allocation_size > 512 || doNotDeallocateSmallBlocks == false) {
            delete[] listArray;
            allocation_size = 0;
            listArray = 0;
        }
        list_size = 0;
    }
    list_type* listArray;
    unsigned int list_size;
    unsigned int allocation_size;
};
}
struct Elem { ~Elem(); int a, b; };
class Holder {
public:
    ~Holder();
    DataStructures::List<Elem> list;
};
Holder::~Holder()
{
    list.Clear(false);
}