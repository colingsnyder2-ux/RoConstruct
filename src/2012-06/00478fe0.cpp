// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc 2012-06 00478110  unit: CRobloxControlColorSelector  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00478110
//
// 00478110  53                   push ebx
// 00478111  56                   push esi
// 00478112  8bf1                 mov esi, ecx
// 00478114  8b869c000000         mov eax, dword ptr [esi + 0x9c]
// 0047811a  57                   push edi
// 0047811b  83f8ff               cmp eax, -1
// 0047811e  750f                 jne 0x47812f
// 00478120  8b8e5c010000         mov ecx, dword ptr [esi + 0x15c]
// 00478126  85c9                 test ecx, ecx
// 00478128  7405                 je 0x47812f
// 0047812a  e8f1cd5000           call 0x984f20
// 0047812f  85c0                 test eax, eax
// 00478131  7468                 je 0x47819b
// 00478133  8b442418             mov eax, dword ptr [esp + 0x18]
// 00478137  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0047813b  50                   push eax
// 0047813c  51                   push ecx
// 0047813d  8bce                 mov ecx, esi
// 0047813f  e8bcfcffff           call 0x477e00
// 00478144  83f8ff               cmp eax, -1
// 00478147  7452                 je 0x47819b
// 00478149  837c241000           cmp dword ptr [esp + 0x10], 0
// 0047814e  898678010000         mov dword ptr [esi + 0x178], eax
// 00478154  752f                 jne 0x478185
// 00478156  83ec10               sub esp, 0x10
// 00478159  8bc4                 mov eax, esp
// 0047815b  33c9                 xor ecx, ecx
// 0047815d  8908                 mov dword ptr [eax], ecx
// 0047815f  33d2                 xor edx, edx
// 00478161  33ff                 xor edi, edi
// 00478163  895004               mov dword ptr [eax + 4], edx
// 00478166  33db                 xor ebx, ebx
// 00478168  897808               mov dword ptr [eax + 8], edi
// 0047816b  8bce                 mov ecx, esi
// 0047816d  89580c               mov dword ptr [eax + 0xc], ebx
// 00478170  e8fbea5000           call 0x986c70
// 00478175  c78678010000ffffffff mov dword ptr [esi + 0x178], 0xffffffff
// 0047817f  5f                   pop edi
// 00478180  5e                   pop esi
// 00478181  5b                   pop ebx
// 00478182  c20c00               ret 0xc
// 00478185  8b16                 mov edx, dword ptr [esi]
// 00478187  8b8298000000         mov eax, dword ptr [edx + 0x98]
// 0047818d  8bce                 mov ecx, esi
// 0047818f  ffd0                 call eax
// 00478191  c78678010000ffffffff mov dword ptr [esi + 0x178], 0xffffffff
// 0047819b  5f                   pop edi
// 0047819c  5e                   pop esi
// 0047819d  5b                   pop ebx
// 0047819e  c20c00               ret 0xc
// copied from an identical function in another client (function ?click@S@ns_ROCX00001a@@QAEXHUPOINT@2@@Z)

namespace ns_ROCX00001a {
struct POINT
{
    int x, y;
};

struct RECT
{
    int left, top, right, bottom;

    RECT(int l, int t, int r, int b)
        : left(l), top(t), right(r), bottom(b) {}
};

struct Parent
{
    int getEnabled();
};

struct S
{
    typedef void (__thiscall *VirtualFunction)(S*);

    VirtualFunction* vtable;
    char padding0[0x98];
    int enabled;
    char padding1[0xBC];
    Parent* parent;
    char padding2[0x20];
    int selected;

    int getEnabled()
    {
        if (enabled != -1 || !parent)
            return enabled;
        return parent->getEnabled();
    }

    int hitTest(POINT point);
    void execute(RECT rect);
    void click(int keyboard, POINT point);
};

void S::click(int keyboard, POINT point)
{
    if (getEnabled())
    {
        int index = hitTest(point);
        if (index != -1)
        {
            selected = index;
            if (!keyboard)
                execute(RECT(0, 0, 0, 0));
            else
                vtable[38](this);
            selected = -1;
        }
    }
}
}