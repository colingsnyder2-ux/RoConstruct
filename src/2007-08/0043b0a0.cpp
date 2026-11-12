// from server: 91% by EspClaude
// roc 2007-08 0043b0a0  unit: CSelectionPropGrid  size: 316 bytes
// roc-flags: /O2 /GS /EHsc /MD
// Rewritten from target disassembly: item list loop comparing CString names (MFC IAT),
// insert at index, then two map updates (this+0x19c, this+0x18c).
namespace ATL {
template<typename T, bool B> class CSimpleStringT {
public:
    __declspec(dllimport) operator const T*() const;
    T* m_pszData;
};
template<typename T, class Traits> class CStringT : public CSimpleStringT<T, true> {
public:
    __declspec(dllimport) ~CStringT() throw();
    __declspec(dllimport) int Compare(const T* psz) const;
};
}
template<typename T> class StrTraitMFC_DLL {};
typedef ATL::CStringT<char, StrTraitMFC_DLL<char> > CString;

class Item;
struct Items {                      // count at +0x28 (target: cmp [ecx+0x28])
    char pad0[0x28];
    int count;
    Item* GetAt(int i);             // 0x699000 thiscall
    int GetCount() { return count; }
};
struct Key { char pad0[8]; int id; }; // a->[0x118]->[8]
class Item {
public:
    char pad0[0xb8];
    Items* childs;                  // +0xb8
    char padbc[0x100 - 0xbc];
    char field100[0x18];
    Key* key;                       // +0x118
    CString GetName() const;        // 0x438e10
    void InsertChild(int i, Item* item); // 0x699320
};
struct MapA { char pad[0x10]; Item*& operator[](void* const& k); };  // 0x4339d0
struct MapB { char pad[0x10]; int erase(void* const& k); };          // 0x464ec0

class CSelectionPropGrid {
public:
    char pad0[0x18c];
    MapB map18c;
    MapA map19c;
    Item* FindParent(int id);       // 0x4397d0
    void AddItem(Item* item);
};

void CSelectionPropGrid::AddItem(Item* item)
{
    Item* parent = FindParent(item->key->id);
    int i;
    for (i = 0; i < parent->childs->GetCount(); i++) {
        Item* child = parent->childs->GetAt(i);
        if (item->GetName().Compare(child->GetName()) < 0)
            break;
    }
    parent->InsertChild(i, item);
    map19c[item->key] = (Item*)item->field100;
    map18c.erase(item->field100);
}
