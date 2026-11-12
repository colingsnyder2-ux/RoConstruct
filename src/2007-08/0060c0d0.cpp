// from server: 100% by EspClaude
// from server: 52% by colin
// roc 2007-08 0060c0d0  unit: CXTCaptionButtonTheme  size: 231 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0060c0d0
//
// 0060c0d0  83ec10               sub esp, 0x10
// 0060c0d3  53                   push ebx
// 0060c0d4  8bd9                 mov ebx, ecx
// 0060c0d6  837b3800             cmp dword ptr [ebx + 0x38], 0
// 0060c0da  0f84d2000000         je 0x60c1b2
// 0060c0e0  55                   push ebp
// 0060c0e1  56                   push esi
// 0060c0e2  57                   push edi
// 0060c0e3  8d7330               lea esi, [ebx + 0x30]
// 0060c0e6  8b4604               mov eax, dword ptr [esi + 4]
// 0060c0e9  8b38                 mov edi, dword ptr [eax]
// 0060c0eb  3bf8                 cmp edi, eax
// 0060c0ed  7506                 jne 0x60c0f5
// 0060c0ef  ff15d8e67700         call dword ptr [0x77e6d8]
// 0060c0f5  8b7f0c               mov edi, dword ptr [edi + 0xc]
// 0060c0f8  3b7b24               cmp edi, dword ptr [ebx + 0x24]
// 0060c0fb  7507                 jne 0x60c104
// 0060c0fd  c7432400000000       mov dword ptr [ebx + 0x24], 0
// 0060c104  6a00                 push 0
// 0060c106  8bcf                 mov ecx, edi
// 0060c108  c6434c01             mov byte ptr [ebx + 0x4c], 1
// 0060c10c  e80f87faff           call 0x5b4820
// 0060c111  8b4f64               mov ecx, dword ptr [edi + 0x64]
// 0060c114  6a00                 push 0
// 0060c116  e89563fdff           call 0x5e24b0
// 0060c11b  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060c11e  8b4104               mov eax, dword ptr [ecx + 4]
// 0060c121  80781100             cmp byte ptr [eax + 0x11], 0
// 0060c125  894c2410             mov dword ptr [esp + 0x10], ecx
// 0060c129  751b                 jne 0x60c146
// 0060c12b  eb03                 jmp 0x60c130
// 0060c12d  8d4900               lea ecx, [ecx]
// 0060c130  3b780c               cmp edi, dword ptr [eax + 0xc]
// 0060c133  7308                 jae 0x60c13d
// 0060c135  89442410             mov dword ptr [esp + 0x10], eax
// 0060c139  8b00                 mov eax, dword ptr [eax]
// 0060c13b  eb03                 jmp 0x60c140
// 0060c13d  8b4008               mov eax, dword ptr [eax + 8]
// 0060c140  80781100             cmp byte ptr [eax + 0x11], 0
// 0060c144  74ea                 je 0x60c130
// 0060c146  8be9                 mov ebp, ecx
// 0060c148  8b4504               mov eax, dword ptr [ebp + 4]
// 0060c14b  80781100             cmp byte ptr [eax + 0x11], 0
// 0060c14f  7514                 jne 0x60c165
// 0060c151  39780c               cmp dword ptr [eax + 0xc], edi
// 0060c154  7305                 jae 0x60c15b
// 0060c156  8b4008               mov eax, dword ptr [eax + 8]
// 0060c159  eb04                 jmp 0x60c15f
// 0060c15b  8be8                 mov ebp, eax
// 0060c15d  8b00                 mov eax, dword ptr [eax]
// 0060c15f  80781100             cmp byte ptr [eax + 0x11], 0
// 0060c163  74ec                 je 0x60c151
// 0060c165  8b442410             mov eax, dword ptr [esp + 0x10]
// 0060c169  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0060c171  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0060c175  51                   push ecx
// 0060c176  8d542418             lea edx, [esp + 0x18]
// 0060c17a  52                   push edx
// 0060c17b  50                   push eax
// 0060c17c  56                   push esi
// 0060c17d  55                   push ebp
// 0060c17e  56                   push esi
// 0060c17f  e83cb4f2ff           call 0x5375c0
// 0060c184  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0060c188  83c418               add esp, 0x18
// 0060c18b  51                   push ecx
// 0060c18c  56                   push esi
// 0060c18d  55                   push ebp
// 0060c18e  56                   push esi
// 0060c18f  8d542428             lea edx, [esp + 0x28]
// 0060c193  52                   push edx
// 0060c194  8bce                 mov ecx, esi
// 0060c196  e8c578faff           call 0x5b3a60
// 0060c19b  8bcb                 mov ecx, ebx
// 0060c19d  e8def9ffff           call 0x60bb80
// 0060c1a2  88432c               mov byte ptr [ebx + 0x2c], al
// 0060c1a5  837b3800             cmp dword ptr [ebx + 0x38], 0
// 0060c1a9  0f8537ffffff         jne 0x60c0e6
// 0060c1af  5f                   pop edi
// 0060c1b0  5e                   pop esi
// 0060c1b1  5d                   pop ebp
// 0060c1b2  5b                   pop ebx
// 0060c1b3  83c410               add esp, 0x10
// 0060c1b6  c3                   ret 

#include <set>

class CInner {
public:
    void Update(int);
};

class CButton {
public:
    char pad0[0x64];
    CInner *m_pInner;
    void SetState(int);
};

class CXTCaptionButtonTheme {
public:
    char pad0[0x24];
    CButton *m_pHot;
    char pad28[4];
    bool m_b2c;
    std::set<CButton *> m_buttons;
    char pad3c[0x10];
    bool m_b4c;
    bool Check();
    void RemoveAll();
};

void CXTCaptionButtonTheme::RemoveAll()
{
    while (!m_buttons.empty()) {
        CButton *pButton = *m_buttons.begin();
        if (pButton == m_pHot)
            m_pHot = 0;
        m_b4c = true;
        pButton->SetState(0);
        pButton->m_pInner->Update(0);
        m_buttons.erase(pButton);
        m_b2c = Check();
    }
}
