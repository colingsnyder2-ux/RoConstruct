// from server: 100% by Yeetserama
// roc 2010-06 0043b3b0  unit: XBoolItem  size: 325 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0043b3b0
//
// 0043b3b0  83ec10               sub esp, 0x10
// 0043b3b3  56                   push esi
// 0043b3b4  8bf1                 mov esi, ecx
// 0043b3b6  83be1c01000000       cmp dword ptr [esi + 0x11c], 0
// 0043b3bd  7509                 jne 0x43b3c8
// 0043b3bf  33c0                 xor eax, eax
// 0043b3c1  5e                   pop esi
// 0043b3c2  83c410               add esp, 0x10
// 0043b3c5  c21400               ret 0x14
// 0043b3c8  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0043b3cc  8b542428             mov edx, dword ptr [esp + 0x28]
// 0043b3d0  8d41ff               lea eax, [ecx - 1]
// 0043b3d3  89442404             mov dword ptr [esp + 4], eax
// 0043b3d7  8b442420             mov eax, dword ptr [esp + 0x20]
// 0043b3db  03c2                 add eax, edx
// 0043b3dd  99                   cdq 
// 0043b3de  2bc2                 sub eax, edx
// 0043b3e0  d1f8                 sar eax, 1
// 0043b3e2  83c10c               add ecx, 0xc
// 0043b3e5  8d50fa               lea edx, [eax - 6]
// 0043b3e8  894c240c             mov dword ptr [esp + 0xc], ecx
// 0043b3ec  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 0043b3f2  83c007               add eax, 7
// 0043b3f5  57                   push edi
// 0043b3f6  8954240c             mov dword ptr [esp + 0xc], edx
// 0043b3fa  89442414             mov dword ptr [esp + 0x14], eax
// 0043b3fe  e8fd043e00           call 0x81b900
// 0043b403  83780401             cmp dword ptr [eax + 4], 1
// 0043b407  0f8599000000         jne 0x43b4a6
// 0043b40d  8d7814               lea edi, [eax + 0x14]
// 0043b410  8bcf                 mov ecx, edi
// 0043b412  e8a9473e00           call 0x81fbc0
// 0043b417  85c0                 test eax, eax
// 0043b419  0f8487000000         je 0x43b4a6
// 0043b41f  8b06                 mov eax, dword ptr [esi]
// 0043b421  8b5058               mov edx, dword ptr [eax + 0x58]
// 0043b424  8bce                 mov ecx, esi
// 0043b426  ffd2                 call edx
// 0043b428  85c0                 test eax, eax
// 0043b42a  8b06                 mov eax, dword ptr [esi]
// 0043b42c  8b9000010000         mov edx, dword ptr [eax + 0x100]
// 0043b432  8bce                 mov ecx, esi
// 0043b434  7425                 je 0x43b45b
// 0043b436  ffd2                 call edx
// 0043b438  84c0                 test al, al
// 0043b43a  7407                 je 0x43b443
// 0043b43c  b80c000000           mov eax, 0xc
// 0043b441  eb39                 jmp 0x43b47c
// 0043b443  8b06                 mov eax, dword ptr [esi]
// 0043b445  8b90e8000000         mov edx, dword ptr [eax + 0xe8]
// 0043b44b  8bce                 mov ecx, esi
// 0043b44d  ffd2                 call edx
// 0043b44f  f7d8                 neg eax
// 0043b451  1bc0                 sbb eax, eax
// 0043b453  83e004               and eax, 4
// 0043b456  83c004               add eax, 4
// 0043b459  eb21                 jmp 0x43b47c
// 0043b45b  ffd2                 call edx
// 0043b45d  84c0                 test al, al
// 0043b45f  7407                 je 0x43b468
// 0043b461  b809000000           mov eax, 9
// 0043b466  eb14                 jmp 0x43b47c
// 0043b468  8b06                 mov eax, dword ptr [esi]
// 0043b46a  8b90e8000000         mov edx, dword ptr [eax + 0xe8]
// 0043b470  8bce                 mov ecx, esi
// 0043b472  ffd2                 call edx
// 0043b474  f7d8                 neg eax
// 0043b476  1bc0                 sbb eax, eax
// 0043b478  83e004               and eax, 4
// 0043b47b  40                   inc eax
// 0043b47c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0043b480  85c9                 test ecx, ecx
// 0043b482  7403                 je 0x43b487
// 0043b484  8b4904               mov ecx, dword ptr [ecx + 4]
// 0043b487  6a00                 push 0
// 0043b489  8d54240c             lea edx, [esp + 0xc]
// 0043b48d  52                   push edx
// 0043b48e  50                   push eax
// 0043b48f  6a03                 push 3
// 0043b491  51                   push ecx
// 0043b492  8bcf                 mov ecx, edi
// 0043b494  e8a7433e00           call 0x81f840
// 0043b499  5f                   pop edi
// 0043b49a  b801000000           mov eax, 1
// 0043b49f  5e                   pop esi
// 0043b4a0  83c410               add esp, 0x10
// 0043b4a3  c21400               ret 0x14
// 0043b4a6  8b06                 mov eax, dword ptr [esi]
// 0043b4a8  8b90e8000000         mov edx, dword ptr [eax + 0xe8]
// 0043b4ae  8bce                 mov ecx, esi
// 0043b4b0  ffd2                 call edx
// 0043b4b2  8bf8                 mov edi, eax
// 0043b4b4  8b06                 mov eax, dword ptr [esi]
// 0043b4b6  8b5058               mov edx, dword ptr [eax + 0x58]
// 0043b4b9  f7df                 neg edi
// 0043b4bb  1bff                 sbb edi, edi
// 0043b4bd  8bce                 mov ecx, esi
// 0043b4bf  81e700040000         and edi, 0x400
// 0043b4c5  ffd2                 call edx
// 0043b4c7  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0043b4cb  8b5104               mov edx, dword ptr [ecx + 4]
// 0043b4ce  f7d8                 neg eax
// 0043b4d0  1bc0                 sbb eax, eax
// 0043b4d2  2500010000           and eax, 0x100
// 0043b4d7  0bc7                 or eax, edi
// 0043b4d9  50                   push eax
// 0043b4da  6a04                 push 4
// 0043b4dc  8d442410             lea eax, [esp + 0x10]
// 0043b4e0  50                   push eax
// 0043b4e1  52                   push edx
// 0043b4e2  ff15ecbb9e00         call dword ptr [0x9ebbec]
// 0043b4e8  5f                   pop edi
// 0043b4e9  b801000000           mov eax, 1
// 0043b4ee  5e                   pop esi
// 0043b4ef  83c410               add esp, 0x10
// 0043b4f2  c21400               ret 0x14
// copied from an identical function in another client (function ?draw@XBoolItem@ns_ROCX000004@@QAEHPAUContext@2@HHHH@Z)

namespace ns_ROCX000004 {
// from server: 100% by king_originala
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
