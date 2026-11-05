// from server: 100% by EspClaude
// from server: 95% by EspClaude
// roc 2009-06 0045bc20  unit: CRobloxWnd::UserInputJob  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0045bc20
//
// 0045bc20  56                   push esi
// 0045bc21  8bf1                 mov esi, ecx
// 0045bc23  57                   push edi
// 0045bc24  8bbeec000000         mov edi, dword ptr [esi + 0xec]
// 0045bc2a  85ff                 test edi, edi
// 0045bc2c  741a                 je 0x45bc48
// 0045bc2e  393d88c8a300         cmp dword ptr [0xa3c888], edi
// 0045bc34  7412                 je 0x45bc48
// 0045bc36  8b07                 mov eax, dword ptr [edi]
// 0045bc38  8b9098000000         mov edx, dword ptr [eax + 0x98]
// 0045bc3e  8bcf                 mov ecx, edi
// 0045bc40  ffd2                 call edx
// 0045bc42  893d88c8a300         mov dword ptr [0xa3c888], edi
// 0045bc48  8b8ef4000000         mov ecx, dword ptr [esi + 0xf4]
// 0045bc4e  85c9                 test ecx, ecx
// 0045bc50  7429                 je 0x45bc7b
// 0045bc52  e8697c0400           call 0x4a38c0
// 0045bc57  8bbef4000000         mov edi, dword ptr [esi + 0xf4]
// 0045bc5d  85ff                 test edi, edi
// 0045bc5f  7410                 je 0x45bc71
// 0045bc61  8bcf                 mov ecx, edi
// 0045bc63  e838770400           call 0x4a33a0
// 0045bc68  57                   push edi
// 0045bc69  e8c4cd2b00           call 0x718a32
// 0045bc6e  83c404               add esp, 4
// 0045bc71  c786f400000000000000 mov dword ptr [esi + 0xf4], 0
// 0045bc7b  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 0045bc81  85c9                 test ecx, ecx
// 0045bc83  7416                 je 0x45bc9b
// 0045bc85  8b01                 mov eax, dword ptr [ecx]
// 0045bc87  8b909c000000         mov edx, dword ptr [eax + 0x9c]
// 0045bc8d  6a01                 push 1
// 0045bc8f  ffd2                 call edx
// 0045bc91  c786ec00000000000000 mov dword ptr [esi + 0xec], 0
// 0045bc9b  5f                   pop edi
// 0045bc9c  5e                   pop esi
// 0045bc9d  c3                   ret 

// from server: 100% by colin
// roc 2008-06 0045bde0  unit: CRobloxWnd  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045bde0
//
// 0045bde0  56                   push esi
// 0045bde1  8bf1                 mov esi, ecx
// 0045bde3  57                   push edi
// 0045bde4  8bbea4000000         mov edi, dword ptr [esi + 0xa4]
// 0045bdea  85ff                 test edi, edi
// 0045bdec  741a                 je 0x45be08
// 0045bdee  393df4ef9600         cmp dword ptr [0x96eff4], edi
// 0045bdf4  7412                 je 0x45be08
// 0045bdf6  8b07                 mov eax, dword ptr [edi]
// 0045bdf8  8b9098000000         mov edx, dword ptr [eax + 0x98]
// 0045bdfe  8bcf                 mov ecx, edi
// 0045be00  ffd2                 call edx
// 0045be02  893df4ef9600         mov dword ptr [0x96eff4], edi
// 0045be08  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 0045be0e  85c9                 test ecx, ecx
// 0045be10  7429                 je 0x45be3b
// 0045be12  e8c9050200           call 0x47c3e0
// 0045be17  8bbeac000000         mov edi, dword ptr [esi + 0xac]
// 0045be1d  85ff                 test edi, edi
// 0045be1f  7410                 je 0x45be31
// 0045be21  8bcf                 mov ecx, edi
// 0045be23  e898000200           call 0x47bec0
// 0045be28  57                   push edi
// 0045be29  e84c482400           call 0x6a067a
// 0045be2e  83c404               add esp, 4
// 0045be31  c786ac00000000000000 mov dword ptr [esi + 0xac], 0
// 0045be3b  8b8ea4000000         mov ecx, dword ptr [esi + 0xa4]
// 0045be41  85c9                 test ecx, ecx
// 0045be43  7416                 je 0x45be5b
// 0045be45  8b01                 mov eax, dword ptr [ecx]
// 0045be47  8b909c000000         mov edx, dword ptr [eax + 0x9c]
// 0045be4d  6a01                 push 1
// 0045be4f  ffd2                 call edx
// 0045be51  c786a400000000000000 mov dword ptr [esi + 0xa4], 0
// 0045be5b  5f                   pop edi
// 0045be5c  5e                   pop esi
// 0045be5d  c3                   ret 

struct CRobloxWnd {
    char pad0[0xec];
    void* m_a4;
    char pad1[4];
    void* m_ac;
    void f();
};

struct Helper_47c3e0 {
    void run();
};

struct Helper_47bec0 {
    void run();
};

extern void* g_96eff4;
extern void __cdecl sub_006a067a(void*);

void CRobloxWnd::f()
{
    void* p = m_a4;
    if (p != 0 && g_96eff4 != p) {
        (*(void (__thiscall **)(void*))(*(int*)p + 0x98))(p);
        g_96eff4 = p;
    }

    Helper_47c3e0* q = (Helper_47c3e0*)m_ac;
    if (q != 0) {
        q->run();
        Helper_47bec0* r = (Helper_47bec0*)m_ac;
        if (r != 0) {
            r->run();
            sub_006a067a(r);
        }
        m_ac = 0;
    }

    void* s = m_a4;
    if (s != 0) {
        (*(void (__thiscall **)(void*, int))(*(int*)s + 0x9c))(s, 1);
        m_a4 = 0;
    }
}
