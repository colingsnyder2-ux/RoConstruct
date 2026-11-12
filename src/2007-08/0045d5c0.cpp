// from server: 91% by EspClaude
// from server: 55% by colin
// roc 2007-08 0045d5c0  unit: Scintilla::CScintillaView  size: 348 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0045d5c0
//
// 0045d5c0  8b442404             mov eax, dword ptr [esp + 4]
// 0045d5c4  53                   push ebx
// 0045d5c5  55                   push ebp
// 0045d5c6  56                   push esi
// 0045d5c7  57                   push edi
// 0045d5c8  8bf1                 mov esi, ecx
// 0045d5ca  50                   push eax
// 0045d5cb  b97ca58800           mov ecx, 0x88a57c
// 0045d5d0  ff156cdd7700         call dword ptr [0x77dd6c]
// 0045d5d6  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0045d5da  51                   push ecx
// 0045d5db  b980a58800           mov ecx, 0x88a580
// 0045d5e0  ff156cdd7700         call dword ptr [0x77dd6c]
// 0045d5e6  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0045d5ea  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0045d5ee  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0045d5f2  8b542418             mov edx, dword ptr [esp + 0x18]
// 0045d5f6  55                   push ebp
// 0045d5f7  893d84a58800         mov dword ptr [0x88a584], edi
// 0045d5fd  891d8ca58800         mov dword ptr [0x88a58c], ebx
// 0045d603  891588a58800         mov dword ptr [0x88a588], edx
// 0045d609  892d90a58800         mov dword ptr [0x88a590], ebp
// 0045d60f  8b06                 mov eax, dword ptr [esi]
// 0045d611  53                   push ebx
// 0045d612  57                   push edi
// 0045d613  b97ca58800           mov ecx, 0x88a57c
// 0045d618  89442420             mov dword ptr [esp + 0x20], eax
// 0045d61c  ff1598dd7700         call dword ptr [0x77dd98]
// 0045d622  8b542420             mov edx, dword ptr [esp + 0x20]
// 0045d626  50                   push eax
// 0045d627  8b82b8010000         mov eax, dword ptr [edx + 0x1b8]
// 0045d62d  8bce                 mov ecx, esi
// 0045d62f  ffd0                 call eax
// 0045d631  85c0                 test eax, eax
// 0045d633  7561                 jne 0x45d696
// 0045d635  8b0e                 mov ecx, dword ptr [esi]
// 0045d637  8b542418             mov edx, dword ptr [esp + 0x18]
// 0045d63b  55                   push ebp
// 0045d63c  53                   push ebx
// 0045d63d  57                   push edi
// 0045d63e  894c2420             mov dword ptr [esp + 0x20], ecx
// 0045d642  52                   push edx
// 0045d643  b97ca58800           mov ecx, 0x88a57c
// 0045d648  ff1598dd7700         call dword ptr [0x77dd98]
// 0045d64e  50                   push eax
// 0045d64f  8b442428             mov eax, dword ptr [esp + 0x28]
// 0045d653  8b90a4010000         mov edx, dword ptr [eax + 0x1a4]
// 0045d659  8bce                 mov ecx, esi
// 0045d65b  ffd2                 call edx
// 0045d65d  85c0                 test eax, eax
// 0045d65f  0f85a4000000         jne 0x45d709
// 0045d665  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0045d669  8b06                 mov eax, dword ptr [esi]
// 0045d66b  6a01                 push 1
// 0045d66d  55                   push ebp
// 0045d66e  53                   push ebx
// 0045d66f  57                   push edi
// 0045d670  51                   push ecx
// 0045d671  b97ca58800           mov ecx, 0x88a57c
// 0045d676  89442428             mov dword ptr [esp + 0x28], eax
// 0045d67a  ff1598dd7700         call dword ptr [0x77dd98]
// 0045d680  8b542428             mov edx, dword ptr [esp + 0x28]
// 0045d684  50                   push eax
// 0045d685  8b82a0010000         mov eax, dword ptr [edx + 0x1a0]
// 0045d68b  8bce                 mov ecx, esi
// 0045d68d  ffd0                 call eax
// 0045d68f  5f                   pop edi
// 0045d690  5e                   pop esi
// 0045d691  5d                   pop ebp
// 0045d692  5b                   pop ebx
// 0045d693  c21800               ret 0x18
// 0045d696  6a01                 push 1
// 0045d698  b980a58800           mov ecx, 0x88a580
// 0045d69d  ff1598dd7700         call dword ptr [0x77dd98]
// 0045d6a3  50                   push eax
// 0045d6a4  8d4e58               lea ecx, [esi + 0x58]
// 0045d6a7  e8e4f3ffff           call 0x45ca90
// 0045d6ac  8b0e                 mov ecx, dword ptr [esi]
// 0045d6ae  8b542418             mov edx, dword ptr [esp + 0x18]
// 0045d6b2  55                   push ebp
// 0045d6b3  53                   push ebx
// 0045d6b4  57                   push edi
// 0045d6b5  894c2420             mov dword ptr [esp + 0x20], ecx
// 0045d6b9  52                   push edx
// 0045d6ba  b97ca58800           mov ecx, 0x88a57c
// 0045d6bf  ff1598dd7700         call dword ptr [0x77dd98]
// 0045d6c5  50                   push eax
// 0045d6c6  8b442428             mov eax, dword ptr [esp + 0x28]
// 0045d6ca  8b90a4010000         mov edx, dword ptr [eax + 0x1a4]
// 0045d6d0  8bce                 mov ecx, esi
// 0045d6d2  ffd2                 call edx
// 0045d6d4  85c0                 test eax, eax
// 0045d6d6  7531                 jne 0x45d709
// 0045d6d8  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0045d6dc  8b06                 mov eax, dword ptr [esi]
// 0045d6de  6a01                 push 1
// 0045d6e0  55                   push ebp
// 0045d6e1  53                   push ebx
// 0045d6e2  57                   push edi
// 0045d6e3  51                   push ecx
// 0045d6e4  b97ca58800           mov ecx, 0x88a57c
// 0045d6e9  89442428             mov dword ptr [esp + 0x28], eax
// 0045d6ed  ff1598dd7700         call dword ptr [0x77dd98]
// 0045d6f3  8b542428             mov edx, dword ptr [esp + 0x28]
// 0045d6f7  50                   push eax
// 0045d6f8  8b82a0010000         mov eax, dword ptr [edx + 0x1a0]
// 0045d6fe  8bce                 mov ecx, esi
// 0045d700  ffd0                 call eax
// 0045d702  5f                   pop edi
// 0045d703  5e                   pop esi
// 0045d704  5d                   pop ebp
// 0045d705  5b                   pop ebx
// 0045d706  c21800               ret 0x18
// 0045d709  8b16                 mov edx, dword ptr [esi]
// 0045d70b  8b82c0010000         mov eax, dword ptr [edx + 0x1c0]
// 0045d711  8bce                 mov ecx, esi
// 0045d713  ffd0                 call eax
// 0045d715  5f                   pop edi
// 0045d716  5e                   pop esi
// 0045d717  5d                   pop ebp
// 0045d718  5b                   pop ebx
// 0045d719  c21800               ret 0x18

struct __declspec(dllimport) Holder {
    void Set(int v);
    int Get();
};

extern Holder g_holderA;   // 0x88a57c
extern Holder g_holderB;   // 0x88a580
extern int g_584;
extern int g_588;
extern int g_58c;
extern int g_590;

struct Inner {
    void f45ca90(int v, int flag);
};

struct CScintillaView {
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0(int h, int a2, int a3, int a4, int a5, int flag); // +0x1a0
    virtual int v1a4(int h, int a2, int a3, int a4, int a5);            // +0x1a4
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual int v1b8(int h, int a3, int a4, int a5);                    // +0x1b8
    virtual void v1bc();
    virtual void v1c0();                                                // +0x1c0
    char pad4[0x58 - 4];
    Inner m_inner;   // +0x58
    void func(int a1, int a2, int a3, int a4, int a5, int a6);
};

void CScintillaView::func(int a1, int a2, int a3, int a4, int a5, int a6)
{
    g_holderA.Set(a1);
    g_holderB.Set(a6);
    g_584 = a3;
    g_58c = a4;
    g_588 = a2;
    g_590 = a5;
    if (!v1b8(g_holderA.Get(), a3, a4, a5)) {
        if (!v1a4(g_holderA.Get(), a2, a3, a4, a5)) {
            v1a0(g_holderA.Get(), a2, a3, a4, a5, 1);
            return;
        }
    } else {
        m_inner.f45ca90(g_holderB.Get(), 1);
        if (!v1a4(g_holderA.Get(), a2, a3, a4, a5)) {
            v1a0(g_holderA.Get(), a2, a3, a4, a5, 1);
            return;
        }
    }
    v1c0();
}
