// from server: 92% by EspClaude
// from server: 44% by colin
// roc 2007-08 0043ae20  unit: CSelectionPropGrid  size: 316 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043ae20
//
// 0043ae20  6aff                 push -1
// 0043ae22  6892e87300           push 0x73e892
// 0043ae27  64a100000000         mov eax, dword ptr fs:[0]
// 0043ae2d  50                   push eax
// 0043ae2e  83ec10               sub esp, 0x10
// 0043ae31  53                   push ebx
// 0043ae32  55                   push ebp
// 0043ae33  56                   push esi
// 0043ae34  57                   push edi
// 0043ae35  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043ae3a  33c4                 xor eax, esp
// 0043ae3c  50                   push eax
// 0043ae3d  8d442424             lea eax, [esp + 0x24]
// 0043ae41  64a300000000         mov dword ptr fs:[0], eax
// 0043ae47  8bf9                 mov edi, ecx
// 0043ae49  897c2420             mov dword ptr [esp + 0x20], edi
// 0043ae4d  8b5c2434             mov ebx, dword ptr [esp + 0x34]
// 0043ae51  8b8324010000         mov eax, dword ptr [ebx + 0x124]
// 0043ae57  8b4808               mov ecx, dword ptr [eax + 8]
// 0043ae5a  51                   push ecx
// 0043ae5b  8bcf                 mov ecx, edi
// 0043ae5d  e86ee9ffff           call 0x4397d0
// 0043ae62  8b88b8000000         mov ecx, dword ptr [eax + 0xb8]
// 0043ae68  33f6                 xor esi, esi
// 0043ae6a  397128               cmp dword ptr [ecx + 0x28], esi
// 0043ae6d  89442414             mov dword ptr [esp + 0x14], eax
// 0043ae71  0f8e90000000         jle 0x43af07
// 0043ae77  eb0b                 jmp 0x43ae84
// 0043ae79  8da42400000000       lea esp, [esp]
// 0043ae80  8b5c2434             mov ebx, dword ptr [esp + 0x34]
// 0043ae84  56                   push esi
// 0043ae85  e876e12500           call 0x699000
// 0043ae8a  8d54241c             lea edx, [esp + 0x1c]
// 0043ae8e  52                   push edx
// 0043ae8f  8bc8                 mov ecx, eax
// 0043ae91  e87adfffff           call 0x438e10
// 0043ae96  8bf8                 mov edi, eax
// 0043ae98  8d442418             lea eax, [esp + 0x18]
// 0043ae9c  50                   push eax
// 0043ae9d  8bcb                 mov ecx, ebx
// 0043ae9f  c744243000000000     mov dword ptr [esp + 0x30], 0
// 0043aea7  e864dfffff           call 0x438e10
// 0043aeac  8be8                 mov ebp, eax
// 0043aeae  8bcf                 mov ecx, edi
// 0043aeb0  c644242c01           mov byte ptr [esp + 0x2c], 1
// 0043aeb5  ff1598dd7700         call dword ptr [0x77dd98]
// 0043aebb  50                   push eax
// 0043aebc  8bcd                 mov ecx, ebp
// 0043aebe  ff15b8dc7700         call dword ptr [0x77dcb8]
// 0043aec4  85c0                 test eax, eax
// 0043aec6  8d4c2418             lea ecx, [esp + 0x18]
// 0043aeca  0f9cc3               setl bl
// 0043aecd  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0043aed3  8d4c241c             lea ecx, [esp + 0x1c]
// 0043aed7  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 0043aedf  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0043aee5  84db                 test bl, bl
// 0043aee7  7512                 jne 0x43aefb
// 0043aee9  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0043aeed  8b89b8000000         mov ecx, dword ptr [ecx + 0xb8]
// 0043aef3  83c601               add esi, 1
// 0043aef6  3b7128               cmp esi, dword ptr [ecx + 0x28]
// 0043aef9  7c85                 jl 0x43ae80
// 0043aefb  8b442414             mov eax, dword ptr [esp + 0x14]
// 0043aeff  8b5c2434             mov ebx, dword ptr [esp + 0x34]
// 0043af03  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0043af07  53                   push ebx
// 0043af08  56                   push esi
// 0043af09  8bc8                 mov ecx, eax
// 0043af0b  e810e42500           call 0x699320
// 0043af10  8b9324010000         mov edx, dword ptr [ebx + 0x124]
// 0043af16  8d442434             lea eax, [esp + 0x34]
// 0043af1a  50                   push eax
// 0043af1b  8d8f9c010000         lea ecx, [edi + 0x19c]
// 0043af21  8db30c010000         lea esi, [ebx + 0x10c]
// 0043af27  89542438             mov dword ptr [esp + 0x38], edx
// 0043af2b  e8a08affff           call 0x4339d0
// 0043af30  8d4c2434             lea ecx, [esp + 0x34]
// 0043af34  51                   push ecx
// 0043af35  8d8f8c010000         lea ecx, [edi + 0x18c]
// 0043af3b  8930                 mov dword ptr [eax], esi
// 0043af3d  89742438             mov dword ptr [esp + 0x38], esi
// 0043af41  e87a9f0200           call 0x464ec0
// 0043af46  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0043af4a  64890d00000000       mov dword ptr fs:[0], ecx
// 0043af51  59                   pop ecx
// 0043af52  5f                   pop edi
// 0043af53  5e                   pop esi
// 0043af54  5d                   pop ebp
// 0043af55  5b                   pop ebx
// 0043af56  83c41c               add esp, 0x1c
// 0043af59  c20400               ret 4
// roc-cl: 50727
#include <vector>
#include <map>

class CStr;

class __declspec(dllimport) CStr {
    void* m_p;
public:
    CStr(const CStr&);
    ~CStr() throw();
    operator const char*() const;
    int Compare(const char*) const;
};

class Item;

class Items {
public:
    char pad0[0x28];
    int m_nSize;
    int GetCount() const { return m_nSize; }
    Item* GetAt(int i) const;
};

class Instance {};
struct Category : public Instance {
    char pad0[8];
    void* m_name;
};

class Item {
public:
    CStr GetCaption() const;
    Item* InsertChildItem(int index, Item* item);
    char pad0[0xb8];
    Items* m_pChilds;
};

struct Sub {
    int x;
};

class InstanceItem : public Item {
public:
    char pad1[0x10c - 0xbc];
    Sub m_10c;
    char pad2[0x124 - 0x110];
    Category* m_124;
};

class CSelectionPropGrid {
public:
    Item* findCategory(void* name);
    void addItem(InstanceItem* item);
    char pad0[0x18c];
    std::vector<Sub*> m_items;
    std::map<Instance*, Sub*> m_map;
};

static __forceinline int findInsertIndex(Item* category, Item* item);

void CSelectionPropGrid::addItem(InstanceItem* item)
{
    Item* category = findCategory(item->m_124->m_name);
    category->InsertChildItem(findInsertIndex(category, item), item);
    m_map[item->m_124] = &item->m_10c;
    m_items.push_back(&item->m_10c);
}

static __forceinline int findInsertIndex(Item* category, Item* item)
{
    int i;
    for (i = 0; i < category->m_pChilds->GetCount(); i++) {
        Item* child = category->m_pChilds->GetAt(i);
        if (item->GetCaption().Compare(child->GetCaption()) < 0)
            break;
    }
    return i;
}

