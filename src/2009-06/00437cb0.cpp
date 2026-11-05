// from server: 100% by EspClaude
// roc 2009-06 00437cb0  unit: XBoolItem  size: 325 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00437cb0
//
// 00437cb0  83ec10               sub esp, 0x10
// 00437cb3  56                   push esi
// 00437cb4  8bf1                 mov esi, ecx
// 00437cb6  83be1c01000000       cmp dword ptr [esi + 0x11c], 0
// 00437cbd  7509                 jne 0x437cc8
// 00437cbf  33c0                 xor eax, eax
// 00437cc1  5e                   pop esi
// 00437cc2  83c410               add esp, 0x10
// 00437cc5  c21400               ret 0x14
// 00437cc8  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00437ccc  8b542428             mov edx, dword ptr [esp + 0x28]
// 00437cd0  8d41ff               lea eax, [ecx - 1]
// 00437cd3  89442404             mov dword ptr [esp + 4], eax
// 00437cd7  8b442420             mov eax, dword ptr [esp + 0x20]
// 00437cdb  03c2                 add eax, edx
// 00437cdd  99                   cdq 
// 00437cde  2bc2                 sub eax, edx
// 00437ce0  d1f8                 sar eax, 1
// 00437ce2  83c10c               add ecx, 0xc
// 00437ce5  8d50fa               lea edx, [eax - 6]
// 00437ce8  894c240c             mov dword ptr [esp + 0xc], ecx
// 00437cec  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 00437cf2  83c007               add eax, 7
// 00437cf5  57                   push edi
// 00437cf6  8954240c             mov dword ptr [esp + 0xc], edx
// 00437cfa  89442414             mov dword ptr [esp + 0x14], eax
// 00437cfe  e84d4c3500           call 0x78c950
// 00437d03  83780401             cmp dword ptr [eax + 4], 1
// 00437d07  0f8599000000         jne 0x437da6
// 00437d0d  8d7814               lea edi, [eax + 0x14]
// 00437d10  8bcf                 mov ecx, edi
// 00437d12  e8898e3500           call 0x790ba0
// 00437d17  85c0                 test eax, eax
// 00437d19  0f8487000000         je 0x437da6
// 00437d1f  8b06                 mov eax, dword ptr [esi]
// 00437d21  8b5058               mov edx, dword ptr [eax + 0x58]
// 00437d24  8bce                 mov ecx, esi
// 00437d26  ffd2                 call edx
// 00437d28  85c0                 test eax, eax
// 00437d2a  8b06                 mov eax, dword ptr [esi]
// 00437d2c  8b9000010000         mov edx, dword ptr [eax + 0x100]
// 00437d32  8bce                 mov ecx, esi
// 00437d34  7425                 je 0x437d5b
// 00437d36  ffd2                 call edx
// 00437d38  84c0                 test al, al
// 00437d3a  7407                 je 0x437d43
// 00437d3c  b80c000000           mov eax, 0xc
// 00437d41  eb39                 jmp 0x437d7c
// 00437d43  8b06                 mov eax, dword ptr [esi]
// 00437d45  8b90e8000000         mov edx, dword ptr [eax + 0xe8]
// 00437d4b  8bce                 mov ecx, esi
// 00437d4d  ffd2                 call edx
// 00437d4f  f7d8                 neg eax
// 00437d51  1bc0                 sbb eax, eax
// 00437d53  83e004               and eax, 4
// 00437d56  83c004               add eax, 4
// 00437d59  eb21                 jmp 0x437d7c
// 00437d5b  ffd2                 call edx
// 00437d5d  84c0                 test al, al
// 00437d5f  7407                 je 0x437d68
// 00437d61  b809000000           mov eax, 9
// 00437d66  eb14                 jmp 0x437d7c
// 00437d68  8b06                 mov eax, dword ptr [esi]
// 00437d6a  8b90e8000000         mov edx, dword ptr [eax + 0xe8]
// 00437d70  8bce                 mov ecx, esi
// 00437d72  ffd2                 call edx
// 00437d74  f7d8                 neg eax
// 00437d76  1bc0                 sbb eax, eax
// 00437d78  83e004               and eax, 4
// 00437d7b  40                   inc eax
// 00437d7c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00437d80  85c9                 test ecx, ecx
// 00437d82  7403                 je 0x437d87
// 00437d84  8b4904               mov ecx, dword ptr [ecx + 4]
// 00437d87  6a00                 push 0
// 00437d89  8d54240c             lea edx, [esp + 0xc]
// 00437d8d  52                   push edx
// 00437d8e  50                   push eax
// 00437d8f  6a03                 push 3
// 00437d91  51                   push ecx
// 00437d92  8bcf                 mov ecx, edi
// 00437d94  e8878a3500           call 0x790820
// 00437d99  5f                   pop edi
// 00437d9a  b801000000           mov eax, 1
// 00437d9f  5e                   pop esi
// 00437da0  83c410               add esp, 0x10
// 00437da3  c21400               ret 0x14
// 00437da6  8b06                 mov eax, dword ptr [esi]
// 00437da8  8b90e8000000         mov edx, dword ptr [eax + 0xe8]
// 00437dae  8bce                 mov ecx, esi
// 00437db0  ffd2                 call edx
// 00437db2  8bf8                 mov edi, eax
// 00437db4  8b06                 mov eax, dword ptr [esi]
// 00437db6  8b5058               mov edx, dword ptr [eax + 0x58]
// 00437db9  f7df                 neg edi
// 00437dbb  1bff                 sbb edi, edi
// 00437dbd  8bce                 mov ecx, esi
// 00437dbf  81e700040000         and edi, 0x400
// 00437dc5  ffd2                 call edx
// 00437dc7  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00437dcb  8b5104               mov edx, dword ptr [ecx + 4]
// 00437dce  f7d8                 neg eax
// 00437dd0  1bc0                 sbb eax, eax
// 00437dd2  2500010000           and eax, 0x100
// 00437dd7  0bc7                 or eax, edi
// 00437dd9  50                   push eax
// 00437dda  6a04                 push 4
// 00437ddc  8d442410             lea eax, [esp + 0x10]
// 00437de0  50                   push eax
// 00437de1  52                   push edx
// 00437de2  ff15cced8900         call dword ptr [0x89edcc]
// 00437de8  5f                   pop edi
// 00437de9  b801000000           mov eax, 1
// 00437dee  5e                   pop esi
// 00437def  83c410               add esp, 0x10
// 00437df2  c21400               ret 0x14
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
