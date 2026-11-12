// from server: 100% by EspClaude
// from server: 61% by colin
// roc 2007-08 006671b0  unit: CRobloxTreeCtrl  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006671b0
//
// 006671b0  8b442404             mov eax, dword ptr [esp + 4]
// 006671b4  85c0                 test eax, eax
// 006671b6  53                   push ebx
// 006671b7  56                   push esi
// 006671b8  8bf1                 mov esi, ecx
// 006671ba  8b5e04               mov ebx, dword ptr [esi + 4]
// 006671bd  894604               mov dword ptr [esi + 4], eax
// 006671c0  754e                 jne 0x667210
// 006671c2  8b4634               mov eax, dword ptr [esi + 0x34]
// 006671c5  8b4020               mov eax, dword ptr [eax + 0x20]
// 006671c8  57                   push edi
// 006671c9  6a00                 push 0
// 006671cb  6a09                 push 9
// 006671cd  680a110000           push 0x110a
// 006671d2  50                   push eax
// 006671d3  ff15d8ec7700         call dword ptr [0x77ecd8]
// 006671d9  8bf8                 mov edi, eax
// 006671db  85ff                 test edi, edi
// 006671dd  7411                 je 0x6671f0
// 006671df  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 006671e2  6a02                 push 2
// 006671e4  57                   push edi
// 006671e5  e850140d00           call 0x73863a
// 006671ea  a802                 test al, 2
// 006671ec  7502                 jne 0x6671f0
// 006671ee  33ff                 xor edi, edi
// 006671f0  8b16                 mov edx, dword ptr [esi]
// 006671f2  8b424c               mov eax, dword ptr [edx + 0x4c]
// 006671f5  57                   push edi
// 006671f6  6a00                 push 0
// 006671f8  8bce                 mov ecx, esi
// 006671fa  ffd0                 call eax
// 006671fc  85ff                 test edi, edi
// 006671fe  7408                 je 0x667208
// 00667200  57                   push edi
// 00667201  8bce                 mov ecx, esi
// 00667203  e8d8edffff           call 0x665fe0
// 00667208  5f                   pop edi
// 00667209  5e                   pop esi
// 0066720a  8bc3                 mov eax, ebx
// 0066720c  5b                   pop ebx
// 0066720d  c20400               ret 4
// 00667210  5e                   pop esi
// 00667211  8bc3                 mov eax, ebx

struct HWND__ { int unused; };
typedef HWND__* HWND;
struct _TREEITEM;
typedef _TREEITEM* HTREEITEM;

extern "C" __declspec(dllimport) long __stdcall SendMessageA(HWND, unsigned int, unsigned int, long);

struct CTreeCtrl {
    char pad_0[0x20];
    HWND m_hWnd;   // [eax+0x20]
    unsigned int GetItemState(HTREEITEM hItem, unsigned int nStateMask) const;
    HTREEITEM GetSelectedItem() const {
        return (HTREEITEM)SendMessageA(m_hWnd, 0x110a, 9, 0);
    }
};

struct CRobloxTreeCtrl {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48();
    virtual void OnSelect(int a, HTREEITEM item);   // vtable +0x4c
    void* m_owner;          // +4
    char pad_8[0x2c];
    CTreeCtrl* m_tree;      // +0x34
    void sub_665FE0(HTREEITEM);
    void* SetOwner(void* owner);
};

void* CRobloxTreeCtrl::SetOwner(void* owner) {
    void* old = m_owner;
    m_owner = owner;
    if (owner == 0) {
        HTREEITEM item = m_tree->GetSelectedItem();
        if (item != 0 && !(m_tree->GetItemState(item, 2) & 2))
            item = 0;
        OnSelect(0, item);
        if (item != 0)
            sub_665FE0(item);
    }
    return old;
}
