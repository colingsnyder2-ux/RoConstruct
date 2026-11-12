// from server: 100% by EspClaude
// from server: 41% by colin
// roc 2007-08 0043bbe0  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043bbe0
// 0043bbe0  6aff                 push -1
// 0043bbe2  6838eb7300           push 0x73eb38
// 0043bbe7  64a100000000         mov eax, dword ptr fs:[0]
// 0043bbed  50                   push eax
// 0043bbee  83ec0c               sub esp, 0xc
// 0043bbf1  56                   push esi
// 0043bbf2  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043bbf7  33c4                 xor eax, esp
// 0043bbf9  50                   push eax
// 0043bbfa  8d442414             lea eax, [esp + 0x14]
// 0043bbfe  64a300000000         mov dword ptr fs:[0], eax
// 0043bc04  8bf1                 mov esi, ecx
// 0043bc06  8b8614010000         mov eax, dword ptr [esi + 0x114]
// 0043bc0c  8b8888010000         mov ecx, dword ptr [eax + 0x188]
// 0043bc12  51                   push ecx
// 0043bc13  8d4c240c             lea ecx, [esp + 0xc]
// 0043bc17  e834dcffff           call 0x439850
// 0043bc1c  8b442424             mov eax, dword ptr [esp + 0x24]
// 0043bc20  33d2                 xor edx, edx
// 0043bc22  3bc2                 cmp eax, edx
// 0043bc24  8954241c             mov dword ptr [esp + 0x1c], edx
// 0043bc28  7403                 je 0x43bc2d
// 0043bc2a  8d5004               lea edx, [eax + 4]
// 0043bc2d  8b8618010000         mov eax, dword ptr [esi + 0x118]
// 0043bc33  8b4818               mov ecx, dword ptr [eax + 0x18]
// 0043bc36  8b01                 mov eax, dword ptr [ecx]
// 0043bc38  52                   push edx
// 0043bc39  8b5004               mov edx, dword ptr [eax + 4]
// 0043bc3c  ffd2                 call edx
// 0043bc3e  d95c2424             fstp dword ptr [esp + 0x24]
// 0043bc42  8d4c2408             lea ecx, [esp + 8]
// 0043bc46  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0043bc4e  e84dd91100           call 0x5595a0
// 0043bc53  d9442424             fld dword ptr [esp + 0x24]
// 0043bc57  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0043bc5b  64890d00000000       mov dword ptr fs:[0], ecx
// 0043bc62  59                   pop ecx
// 0043bc63  5e                   pop esi
// 0043bc64  83c418               add esp, 0x18
// 0043bc67  c20400               ret 4

struct CScopeObj {
    CScopeObj(void* p);       // 0x439850, thiscall, 1 arg
    ~CScopeObj();             // 0x5595a0
    int m_data[3];
};

struct CItemBase0 { int m_base0; };
struct CItemBase4 { int m_base4; };
struct CItem : public CItemBase0, public CItemBase4 { };   // base at +4

struct CMeasurer {
    virtual void v00();
    virtual float Measure(CItemBase4* pItem);   // vtable +4
};
struct CPaintOwner {
    char pad[0x18];
    CMeasurer* m_pMeasurer;   // +0x18
    float GetMetric(CItemBase4* p) { return m_pMeasurer->Measure(p); }
};
struct CPanel {
    char pad[0x188];
    void* m_p188;             // +0x188
};

struct CAutoHidePanelTabManager {
    char pad[0x114];
    CPanel* m_pPanel;         // +0x114
    CPaintOwner* m_pOwner;    // +0x118
    float GetItemMetric(CItem* pItem);
};

float CAutoHidePanelTabManager::GetItemMetric(CItem* pItem)
{
    CScopeObj scope(m_pPanel->m_p188);
    return m_pOwner->GetMetric(pItem);
}
