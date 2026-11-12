// from server: 100% by EspClaude
// from server: 43% by colin
// roc 2007-08 0043cff0  unit: G3D::VVector3::?$XItem  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043cff0
//
// 0043cff0  6aff                 push -1
// 0043cff2  6838eb7300           push 0x73eb38
// 0043cff7  64a100000000         mov eax, dword ptr fs:[0]
// 0043cffd  50                   push eax
// 0043cffe  83ec0c               sub esp, 0xc
// 0043d001  56                   push esi
// 0043d002  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043d007  33c4                 xor eax, esp
// 0043d009  50                   push eax
// 0043d00a  8d442414             lea eax, [esp + 0x14]
// 0043d00e  64a300000000         mov dword ptr fs:[0], eax
// 0043d014  8bf1                 mov esi, ecx
// 0043d016  8b8614010000         mov eax, dword ptr [esi + 0x114]
// 0043d01c  8b8888010000         mov ecx, dword ptr [eax + 0x188]
// 0043d022  51                   push ecx
// 0043d023  8d4c240c             lea ecx, [esp + 0xc]
// 0043d027  e824c8ffff           call 0x439850
// 0043d02c  8b442428             mov eax, dword ptr [esp + 0x28]
// 0043d030  33d2                 xor edx, edx
// 0043d032  3bc2                 cmp eax, edx
// 0043d034  8954241c             mov dword ptr [esp + 0x1c], edx
// 0043d038  7403                 je 0x43d03d
// 0043d03a  8d5004               lea edx, [eax + 4]
// 0043d03d  8b8618010000         mov eax, dword ptr [esi + 0x118]
// 0043d043  8b4818               mov ecx, dword ptr [eax + 0x18]
// 0043d046  8b01                 mov eax, dword ptr [ecx]
// 0043d048  8b742424             mov esi, dword ptr [esp + 0x24]
// 0043d04c  52                   push edx
// 0043d04d  8b5004               mov edx, dword ptr [eax + 4]
// 0043d050  56                   push esi
// 0043d051  ffd2                 call edx
// 0043d053  8d4c2408             lea ecx, [esp + 8]
// 0043d057  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0043d05f  e83cc51100           call 0x5595a0
// 0043d064  8bc6                 mov eax, esi
// 0043d066  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0043d06a  64890d00000000       mov dword ptr fs:[0], ecx
// 0043d071  59                   pop ecx
// 0043d072  5e                   pop esi
// 0043d073  83c418               add esp, 0x18
// 0043d076  c20800               ret 8


struct CScopeObj {
    CScopeObj(void* p);       // 0x439850, thiscall, 1 arg
    ~CScopeObj();             // 0x5595a0
    int m_data[3];
};

struct CItemBase0 { int m_base0; };
struct CItemBase4 { int m_base4; };
struct CItem : public CItemBase0, public CItemBase4 { };   // base at +4

struct CValue {
    CValue(const CValue&);
    int m_v;
};

struct CConverter {
    virtual void v00();
    virtual CValue Convert(CItemBase4* pItem);   // vtable +4, returns via hidden pointer
};
struct COwner {
    char pad[0x18];
    CConverter* m_pConverter;   // +0x18
    CValue Get(CItemBase4* p) { return m_pConverter->Convert(p); }
};
struct CPanel {
    char pad[0x188];
    void* m_p188;             // +0x188
};

struct CXItemOwner {
    char pad[0x114];
    CPanel* m_pPanel;         // +0x114
    COwner* m_pOwner;         // +0x118
    CValue GetItemValue(CItem* pItem);
};

CValue CXItemOwner::GetItemValue(CItem* pItem)
{
    CScopeObj scope(m_pPanel->m_p188);
    return m_pOwner->Get(pItem);
}
