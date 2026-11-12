// from server: 100% by EspClaude
// from server: 46% by colin
// roc 2007-08 005b0a00  unit: RBX::AutoJoint  size: 291 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005b0a00
//
// 005b0a00  83ec0c               sub esp, 0xc
// 005b0a03  56                   push esi
// 005b0a04  53                   push ebx
// 005b0a05  8bf1                 mov esi, ecx
// 005b0a07  57                   push edi
// 005b0a08  eb06                 jmp 0x5b0a10
// 005b0a0a  8d9b00000000         lea ebx, [ebx]
// 005b0a10  8b1dc85d8c00         mov ebx, dword ptr [0x8c5dc8]
// 005b0a16  f6c301               test bl, 1
// 005b0a19  7520                 jne 0x5b0a3b
// 005b0a1b  a1c05d8c00           mov eax, dword ptr [0x8c5dc0]
// 005b0a20  83cb01               or ebx, 1
// 005b0a23  8bf8                 mov edi, eax
// 005b0a25  83c001               add eax, 1
// 005b0a28  891dc85d8c00         mov dword ptr [0x8c5dc8], ebx
// 005b0a2e  893dc45d8c00         mov dword ptr [0x8c5dc4], edi
// 005b0a34  a3c05d8c00           mov dword ptr [0x8c5dc0], eax
// 005b0a39  eb06                 jmp 0x5b0a41
// 005b0a3b  8b3dc45d8c00         mov edi, dword ptr [0x8c5dc4]
// 005b0a41  8bce                 mov ecx, esi
// 005b0a43  e8c8dbfaff           call 0x55e610
// 005b0a48  3bc7                 cmp eax, edi
// 005b0a4a  7761                 ja 0x5b0aad
// 005b0a4c  8b5604               mov edx, dword ptr [esi + 4]
// 005b0a4f  85d2                 test edx, edx
// 005b0a51  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 005b0a59  7504                 jne 0x5b0a5f
// 005b0a5b  33c9                 xor ecx, ecx
// 005b0a5d  eb08                 jmp 0x5b0a67
// 005b0a5f  8b4e08               mov ecx, dword ptr [esi + 8]
// 005b0a62  2bca                 sub ecx, edx
// 005b0a64  c1f902               sar ecx, 2
// 005b0a67  85d2                 test edx, edx
// 005b0a69  741d                 je 0x5b0a88
// 005b0a6b  8b460c               mov eax, dword ptr [esi + 0xc]
// 005b0a6e  2bc2                 sub eax, edx
// 005b0a70  c1f802               sar eax, 2
// 005b0a73  3bc8                 cmp ecx, eax
// 005b0a75  7311                 jae 0x5b0a88
// 005b0a77  8b4608               mov eax, dword ptr [esi + 8]
// 005b0a7a  c70000000000         mov dword ptr [eax], 0
// 005b0a80  83c004               add eax, 4
// 005b0a83  894608               mov dword ptr [esi + 8], eax
// 005b0a86  eb88                 jmp 0x5b0a10
// 005b0a88  8b7e08               mov edi, dword ptr [esi + 8]
// 005b0a8b  3bd7                 cmp edx, edi
// 005b0a8d  7606                 jbe 0x5b0a95
// 005b0a8f  ff15d8e67700         call dword ptr [0x77e6d8]
// 005b0a95  8d44240c             lea eax, [esp + 0xc]
// 005b0a99  50                   push eax
// 005b0a9a  57                   push edi
// 005b0a9b  56                   push esi
// 005b0a9c  8d4c241c             lea ecx, [esp + 0x1c]
// 005b0aa0  51                   push ecx
// 005b0aa1  8bce                 mov ecx, esi
// 005b0aa3  e8d8d40100           call 0x5cdf80
// 005b0aa8  e963ffffff           jmp 0x5b0a10
// 005b0aad  f6c301               test bl, 1
// 005b0ab0  751e                 jne 0x5b0ad0
// 005b0ab2  a1c05d8c00           mov eax, dword ptr [0x8c5dc0]
// 005b0ab7  83cb01               or ebx, 1
// 005b0aba  8bf8                 mov edi, eax
// 005b0abc  83c001               add eax, 1
// 005b0abf  891dc85d8c00         mov dword ptr [0x8c5dc8], ebx
// 005b0ac5  893dc45d8c00         mov dword ptr [0x8c5dc4], edi
// 005b0acb  a3c05d8c00           mov dword ptr [0x8c5dc0], eax
// 005b0ad0  8b4e04               mov ecx, dword ptr [esi + 4]
// 005b0ad3  85c9                 test ecx, ecx
// 005b0ad5  740c                 je 0x5b0ae3
// 005b0ad7  8b4608               mov eax, dword ptr [esi + 8]
// 005b0ada  2bc1                 sub eax, ecx
// 005b0adc  c1f802               sar eax, 2
// 005b0adf  3bf8                 cmp edi, eax
// 005b0ae1  7206                 jb 0x5b0ae9
// 005b0ae3  ff15d8e67700         call dword ptr [0x77e6d8]

#include <vector>

// this is a std::vector<Base*> (VS2005 layout: _Myfirst +4, _Mylast +8, _Myend +0xc).
// 0x55e610 is an out-of-line size(); slots are created with new(8) (vptr + 4-byte value)
// and the value at +4 is returned. The slot index is a guarded function-local static
// (guard 0x8c5dc8 bit 0, value 0x8c5dc4) taken from a shared counter (0x8c5dc0).
namespace RBX {

class SlotBase {
public:
    virtual ~SlotBase();
};

template<class T>
class Slot : public SlotBase {
public:
    T value;
};

extern unsigned int nextSlotIndex;

template<class T>
struct SlotIndex {
    static unsigned int get() {
        static unsigned int index = nextSlotIndex++;
        return index;
    }
};

class SlotTable {
    std::vector<SlotBase*> slots;
public:
    unsigned int size() const;

    template<class T>
    T& get() {
        while (size() <= SlotIndex<T>::get())
            slots.push_back(NULL);
        SlotBase*& slot = slots[SlotIndex<T>::get()];
        if (!slot)
            slot = new Slot<T>;
        return static_cast<Slot<T>*>(slot)->value;
    }
};

unsigned int SlotTable::size() const
{
    return slots.size();
}

struct AutoJointState {
    int field_0;
};

template AutoJointState& SlotTable::get<AutoJointState>();

}
