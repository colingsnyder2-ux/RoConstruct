// from server: 100% by EspClaude
// from server: 45% by colin
// roc 2007-08 0043cae0  unit: MVCXTPPropertyGridItem::?$XItem  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043cae0
//
// 0043cae0  6aff                 push -1
// 0043cae2  6882ea7300           push 0x73ea82
// 0043cae7  64a100000000         mov eax, dword ptr fs:[0]
// 0043caed  50                   push eax
// 0043caee  83ec10               sub esp, 0x10
// 0043caf1  56                   push esi
// 0043caf2  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043caf7  33c4                 xor eax, esp
// 0043caf9  50                   push eax
// 0043cafa  8d442418             lea eax, [esp + 0x18]
// 0043cafe  64a300000000         mov dword ptr fs:[0], eax
// 0043cb04  8bf1                 mov esi, ecx
// 0043cb06  c744240800000000     mov dword ptr [esp + 8], 0
// 0043cb0e  8b8614010000         mov eax, dword ptr [esi + 0x114]
// 0043cb14  8b8888010000         mov ecx, dword ptr [eax + 0x188]
// 0043cb1a  51                   push ecx
// 0043cb1b  8d4c2410             lea ecx, [esp + 0x10]
// 0043cb1f  e82ccdffff           call 0x439850
// 0043cb24  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0043cb28  85c0                 test eax, eax
// 0043cb2a  c744242001000000     mov dword ptr [esp + 0x20], 1
// 0043cb32  7405                 je 0x43cb39
// 0043cb34  83c004               add eax, 4
// 0043cb37  eb02                 jmp 0x43cb3b
// 0043cb39  33c0                 xor eax, eax
// 0043cb3b  8b8e18010000         mov ecx, dword ptr [esi + 0x118]
// 0043cb41  8b11                 mov edx, dword ptr [ecx]
// 0043cb43  8b742428             mov esi, dword ptr [esp + 0x28]
// 0043cb47  50                   push eax
// 0043cb48  8b4210               mov eax, dword ptr [edx + 0x10]
// 0043cb4b  56                   push esi
// 0043cb4c  ffd0                 call eax
// 0043cb4e  8d4c240c             lea ecx, [esp + 0xc]
// 0043cb52  c744240801000000     mov dword ptr [esp + 8], 1
// 0043cb5a  c644242000           mov byte ptr [esp + 0x20], 0
// 0043cb5f  e83cca1100           call 0x5595a0
// 0043cb64  8bc6                 mov eax, esi
// 0043cb66  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0043cb6a  64890d00000000       mov dword ptr fs:[0], ecx
// 0043cb71  59                   pop ecx
// 0043cb72  5e                   pop esi
// 0043cb73  83c41c               add esp, 0x1c
// 0043cb76  c20800               ret 8

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
    ~CValue();
    int m_v;
};

struct CConverter {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual CValue Convert(CItemBase4* pItem);   // vtable +0x10, returns via hidden pointer
};
struct CPanel {
    char pad[0x188];
    void* m_p188;             // +0x188
};

struct CXItemOwner {
    char pad[0x114];
    CPanel* m_pPanel;         // +0x114
    CConverter* m_pConverter; // +0x118
    CValue GetItemValue(CItem* pItem);
};

CValue CXItemOwner::GetItemValue(CItem* pItem)
{
    CScopeObj scope(m_pPanel->m_p188);
    return m_pConverter->Convert(pItem);
}
