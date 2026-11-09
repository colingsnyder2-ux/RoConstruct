// from server: 100% by Yeetserama
// roc 2011-06 00448ef0  unit: XBoolItem  size: 325 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00448ef0
//
// 00448ef0  83ec10               sub esp, 0x10
// 00448ef3  56                   push esi
// 00448ef4  8bf1                 mov esi, ecx
// 00448ef6  83be1c01000000       cmp dword ptr [esi + 0x11c], 0
// 00448efd  7509                 jne 0x448f08
// 00448eff  33c0                 xor eax, eax
// 00448f01  5e                   pop esi
// 00448f02  83c410               add esp, 0x10
// 00448f05  c21400               ret 0x14
// 00448f08  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00448f0c  8b542428             mov edx, dword ptr [esp + 0x28]
// 00448f10  8d41ff               lea eax, [ecx - 1]
// 00448f13  89442404             mov dword ptr [esp + 4], eax
// 00448f17  8b442420             mov eax, dword ptr [esp + 0x20]
// 00448f1b  03c2                 add eax, edx
// 00448f1d  99                   cdq 
// 00448f1e  2bc2                 sub eax, edx
// 00448f20  d1f8                 sar eax, 1
// 00448f22  83c10c               add ecx, 0xc
// 00448f25  8d50fa               lea edx, [eax - 6]
// 00448f28  894c240c             mov dword ptr [esp + 0xc], ecx
// 00448f2c  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 00448f32  83c007               add eax, 7
// 00448f35  57                   push edi
// 00448f36  8954240c             mov dword ptr [esp + 0xc], edx
// 00448f3a  89442414             mov dword ptr [esp + 0x14], eax
// 00448f3e  e8cdce4200           call 0x875e10
// 00448f43  83780401             cmp dword ptr [eax + 4], 1
// 00448f47  0f8599000000         jne 0x448fe6
// 00448f4d  8d7814               lea edi, [eax + 0x14]
// 00448f50  8bcf                 mov ecx, edi
// 00448f52  e879434300           call 0x87d2d0
// 00448f57  85c0                 test eax, eax
// 00448f59  0f8487000000         je 0x448fe6
// 00448f5f  8b06                 mov eax, dword ptr [esi]
// 00448f61  8b5058               mov edx, dword ptr [eax + 0x58]
// 00448f64  8bce                 mov ecx, esi
// 00448f66  ffd2                 call edx
// 00448f68  85c0                 test eax, eax
// 00448f6a  8b06                 mov eax, dword ptr [esi]
// 00448f6c  8b9000010000         mov edx, dword ptr [eax + 0x100]
// 00448f72  8bce                 mov ecx, esi
// 00448f74  7425                 je 0x448f9b
// 00448f76  ffd2                 call edx
// 00448f78  84c0                 test al, al
// 00448f7a  7407                 je 0x448f83
// 00448f7c  b80c000000           mov eax, 0xc
// 00448f81  eb39                 jmp 0x448fbc
// 00448f83  8b06                 mov eax, dword ptr [esi]
// 00448f85  8b90e8000000         mov edx, dword ptr [eax + 0xe8]
// 00448f8b  8bce                 mov ecx, esi
// 00448f8d  ffd2                 call edx
// 00448f8f  f7d8                 neg eax
// 00448f91  1bc0                 sbb eax, eax
// 00448f93  83e004               and eax, 4
// 00448f96  83c004               add eax, 4
// 00448f99  eb21                 jmp 0x448fbc
// 00448f9b  ffd2                 call edx
// 00448f9d  84c0                 test al, al
// 00448f9f  7407                 je 0x448fa8
// 00448fa1  b809000000           mov eax, 9
// 00448fa6  eb14                 jmp 0x448fbc
// 00448fa8  8b06                 mov eax, dword ptr [esi]
// 00448faa  8b90e8000000         mov edx, dword ptr [eax + 0xe8]
// 00448fb0  8bce                 mov ecx, esi
// 00448fb2  ffd2                 call edx
// 00448fb4  f7d8                 neg eax
// 00448fb6  1bc0                 sbb eax, eax
// 00448fb8  83e004               and eax, 4
// 00448fbb  40                   inc eax
// 00448fbc  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00448fc0  85c9                 test ecx, ecx
// 00448fc2  7403                 je 0x448fc7
// 00448fc4  8b4904               mov ecx, dword ptr [ecx + 4]
// 00448fc7  6a00                 push 0
// 00448fc9  8d54240c             lea edx, [esp + 0xc]
// 00448fcd  52                   push edx
// 00448fce  50                   push eax
// 00448fcf  6a03                 push 3
// 00448fd1  51                   push ecx
// 00448fd2  8bcf                 mov ecx, edi
// 00448fd4  e827404300           call 0x87d000
// 00448fd9  5f                   pop edi
// 00448fda  b801000000           mov eax, 1
// 00448fdf  5e                   pop esi
// 00448fe0  83c410               add esp, 0x10
// 00448fe3  c21400               ret 0x14
// 00448fe6  8b06                 mov eax, dword ptr [esi]
// 00448fe8  8b90e8000000         mov edx, dword ptr [eax + 0xe8]
// 00448fee  8bce                 mov ecx, esi
// 00448ff0  ffd2                 call edx
// 00448ff2  8bf8                 mov edi, eax
// 00448ff4  8b06                 mov eax, dword ptr [esi]
// 00448ff6  8b5058               mov edx, dword ptr [eax + 0x58]
// 00448ff9  f7df                 neg edi
// 00448ffb  1bff                 sbb edi, edi
// 00448ffd  8bce                 mov ecx, esi
// 00448fff  81e700040000         and edi, 0x400
// 00449005  ffd2                 call edx
// 00449007  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0044900b  8b5104               mov edx, dword ptr [ecx + 4]
// 0044900e  f7d8                 neg eax
// 00449010  1bc0                 sbb eax, eax
// 00449012  2500010000           and eax, 0x100
// 00449017  0bc7                 or eax, edi
// 00449019  50                   push eax
// 0044901a  6a04                 push 4
// 0044901c  8d442410             lea eax, [esp + 0x10]
// 00449020  50                   push eax
// 00449021  52                   push edx
// 00449022  ff15241ca400         call dword ptr [0xa41c24]
// 00449028  5f                   pop edi
// 00449029  b801000000           mov eax, 1
// 0044902e  5e                   pop esi
// 0044902f  83c410               add esp, 0x10
// 00449032  c21400               ret 0x14
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
