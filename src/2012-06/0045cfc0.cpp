// from server: 100% by Xemicl
// roc 2012-06 0045cfc0  unit: XBoolItem  size: 325 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0045cfc0
//
// 0045cfc0  83ec10               sub esp, 0x10
// 0045cfc3  56                   push esi
// 0045cfc4  8bf1                 mov esi, ecx
// 0045cfc6  83be1c01000000       cmp dword ptr [esi + 0x11c], 0
// 0045cfcd  7509                 jne 0x45cfd8
// 0045cfcf  33c0                 xor eax, eax
// 0045cfd1  5e                   pop esi
// 0045cfd2  83c410               add esp, 0x10
// 0045cfd5  c21400               ret 0x14
// 0045cfd8  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0045cfdc  8b542428             mov edx, dword ptr [esp + 0x28]
// 0045cfe0  8d41ff               lea eax, [ecx - 1]
// 0045cfe3  89442404             mov dword ptr [esp + 4], eax
// 0045cfe7  8b442420             mov eax, dword ptr [esp + 0x20]
// 0045cfeb  03c2                 add eax, edx
// 0045cfed  99                   cdq 
// 0045cfee  2bc2                 sub eax, edx
// 0045cff0  d1f8                 sar eax, 1
// 0045cff2  83c10c               add ecx, 0xc
// 0045cff5  8d50fa               lea edx, [eax - 6]
// 0045cff8  894c240c             mov dword ptr [esp + 0xc], ecx
// 0045cffc  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 0045d002  83c007               add eax, 7
// 0045d005  57                   push edi
// 0045d006  8954240c             mov dword ptr [esp + 0xc], edx
// 0045d00a  89442414             mov dword ptr [esp + 0x14], eax
// 0045d00e  e89d135900           call 0x9ee3b0
// 0045d013  83780401             cmp dword ptr [eax + 4], 1
// 0045d017  0f8599000000         jne 0x45d0b6
// 0045d01d  8d7814               lea edi, [eax + 0x14]
// 0045d020  8bcf                 mov ecx, edi
// 0045d022  e849885900           call 0x9f5870
// 0045d027  85c0                 test eax, eax
// 0045d029  0f8487000000         je 0x45d0b6
// 0045d02f  8b06                 mov eax, dword ptr [esi]
// 0045d031  8b5058               mov edx, dword ptr [eax + 0x58]
// 0045d034  8bce                 mov ecx, esi
// 0045d036  ffd2                 call edx
// 0045d038  85c0                 test eax, eax
// 0045d03a  8b06                 mov eax, dword ptr [esi]
// 0045d03c  8b9000010000         mov edx, dword ptr [eax + 0x100]
// 0045d042  8bce                 mov ecx, esi
// 0045d044  7425                 je 0x45d06b
// 0045d046  ffd2                 call edx
// 0045d048  84c0                 test al, al
// 0045d04a  7407                 je 0x45d053
// 0045d04c  b80c000000           mov eax, 0xc
// 0045d051  eb39                 jmp 0x45d08c
// 0045d053  8b06                 mov eax, dword ptr [esi]
// 0045d055  8b90e8000000         mov edx, dword ptr [eax + 0xe8]
// 0045d05b  8bce                 mov ecx, esi
// 0045d05d  ffd2                 call edx
// 0045d05f  f7d8                 neg eax
// 0045d061  1bc0                 sbb eax, eax
// 0045d063  83e004               and eax, 4
// 0045d066  83c004               add eax, 4
// 0045d069  eb21                 jmp 0x45d08c
// 0045d06b  ffd2                 call edx
// 0045d06d  84c0                 test al, al
// 0045d06f  7407                 je 0x45d078
// 0045d071  b809000000           mov eax, 9
// 0045d076  eb14                 jmp 0x45d08c
// 0045d078  8b06                 mov eax, dword ptr [esi]
// 0045d07a  8b90e8000000         mov edx, dword ptr [eax + 0xe8]
// 0045d080  8bce                 mov ecx, esi
// 0045d082  ffd2                 call edx
// 0045d084  f7d8                 neg eax
// 0045d086  1bc0                 sbb eax, eax
// 0045d088  83e004               and eax, 4
// 0045d08b  40                   inc eax
// 0045d08c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0045d090  85c9                 test ecx, ecx
// 0045d092  7403                 je 0x45d097
// 0045d094  8b4904               mov ecx, dword ptr [ecx + 4]
// 0045d097  6a00                 push 0
// 0045d099  8d54240c             lea edx, [esp + 0xc]
// 0045d09d  52                   push edx
// 0045d09e  50                   push eax
// 0045d09f  6a03                 push 3
// 0045d0a1  51                   push ecx
// 0045d0a2  8bcf                 mov ecx, edi
// 0045d0a4  e8f7845900           call 0x9f55a0
// 0045d0a9  5f                   pop edi
// 0045d0aa  b801000000           mov eax, 1
// 0045d0af  5e                   pop esi
// 0045d0b0  83c410               add esp, 0x10
// 0045d0b3  c21400               ret 0x14
// 0045d0b6  8b06                 mov eax, dword ptr [esi]
// 0045d0b8  8b90e8000000         mov edx, dword ptr [eax + 0xe8]
// 0045d0be  8bce                 mov ecx, esi
// 0045d0c0  ffd2                 call edx
// 0045d0c2  8bf8                 mov edi, eax
// 0045d0c4  8b06                 mov eax, dword ptr [esi]
// 0045d0c6  8b5058               mov edx, dword ptr [eax + 0x58]
// 0045d0c9  f7df                 neg edi
// 0045d0cb  1bff                 sbb edi, edi
// 0045d0cd  8bce                 mov ecx, esi
// 0045d0cf  81e700040000         and edi, 0x400
// 0045d0d5  ffd2                 call edx
// 0045d0d7  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0045d0db  8b5104               mov edx, dword ptr [ecx + 4]
// 0045d0de  f7d8                 neg eax
// 0045d0e0  1bc0                 sbb eax, eax
// 0045d0e2  2500010000           and eax, 0x100
// 0045d0e7  0bc7                 or eax, edi
// 0045d0e9  50                   push eax
// 0045d0ea  6a04                 push 4
// 0045d0ec  8d442410             lea eax, [esp + 0x10]
// 0045d0f0  50                   push eax
// 0045d0f1  52                   push edx
// 0045d0f2  ff15383bb200         call dword ptr [0xb23b38]
// 0045d0f8  5f                   pop edi
// 0045d0f9  b801000000           mov eax, 1
// 0045d0fe  5e                   pop esi
// 0045d0ff  83c410               add esp, 0x10
// 0045d102  c21400               ret 0x14
// copied from an identical function in another client (function ?draw@XBoolItem@ns_ROCX000003@@QAEHPAUContext@2@HHHH@Z)

namespace ns_ROCX000003 {
struct Rect {
    int left, top, right, bottom;
};

struct Context {
    int unused;
    void* dc;
};

struct Theme {
    int available();
    int draw(void*, int, int, const Rect*, const Rect*);
};

struct ThemeInfo {
    int unused;
    int kind;
    char padding[12];
    Theme theme;
};

struct I_func_00714140 {
    char pad[324];
    int m_x;
};

struct S_func_00714140 {
    char pad[176];
    I_func_00714140* m_p;
    int f();
};

extern "C" {
    extern int (__stdcall *DrawFrameControl)(void*, Rect*, unsigned int, unsigned int);
}

#define V(N) virtual void v##N();

struct XBoolItem {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7)
    V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15)
    V(16) V(17) V(18) V(19) V(20) V(21)
    virtual int checked();
    V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30)
    V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38)
    V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46)
    V(47) V(48) V(49) V(50) V(51) V(52) V(53) V(54)
    V(55) V(56) V(57)
    virtual int hot();
    V(59) V(60) V(61) V(62) V(63)
    virtual bool disabled();

    char pad0[184];
    S_func_00714140* provider;
    char pad1[92];
    int enabled;

    int draw(Context*, int, int, int, int);
};

#undef V

int XBoolItem::draw(Context* context, int x, int top, int unused, int bottom)
{
    if (!enabled)
        return 0;

    Rect rect;
    rect.left = x - 1;
    int center = (top + bottom) / 2;
    rect.top = center - 6;
    rect.right = x + 12;
    rect.bottom = center + 7;

    ThemeInfo* info = reinterpret_cast<ThemeInfo*>(provider->f());
    if (info->kind == 1 && info->theme.available()) {
        int state;
        if (checked()) {
            if (disabled())
                state = 12;
            else
                state = (hot() != 0 ? 4 : 0) + 4;
        } else {
            if (disabled())
                state = 9;
            else
                state = (hot() != 0 ? 4 : 0) + 1;
        }
        void* dc = context;
        if (context)
            dc = context->dc;
        info->theme.draw(dc, 3, state, &rect, 0);
        return 1;
    }

    unsigned int hotFlags = hot() != 0 ? 0x400 : 0;
    unsigned int flags = checked() != 0 ? 0x100 : 0;
    flags |= hotFlags;
    DrawFrameControl(context->dc, &rect, 4, flags);
    return 1;
}
}