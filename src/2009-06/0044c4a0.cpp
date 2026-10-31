// from server: 100% by EspClaude
// roc 2009-06 0044c4a0  unit: CRobloxControlColorSelector  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044c4a0
//
// 0044c4a0  53                   push ebx
// 0044c4a1  56                   push esi
// 0044c4a2  8bf1                 mov esi, ecx
// 0044c4a4  8b869c000000         mov eax, dword ptr [esi + 0x9c]
// 0044c4aa  57                   push edi
// 0044c4ab  83f8ff               cmp eax, -1
// 0044c4ae  750f                 jne 0x44c4bf
// 0044c4b0  8b8e5c010000         mov ecx, dword ptr [esi + 0x15c]
// 0044c4b6  85c9                 test ecx, ecx
// 0044c4b8  7405                 je 0x44c4bf
// 0044c4ba  e8e1392d00           call 0x71fea0
// 0044c4bf  85c0                 test eax, eax
// 0044c4c1  7468                 je 0x44c52b
// 0044c4c3  8b442418             mov eax, dword ptr [esp + 0x18]
// 0044c4c7  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044c4cb  50                   push eax
// 0044c4cc  51                   push ecx
// 0044c4cd  8bce                 mov ecx, esi
// 0044c4cf  e81cfcffff           call 0x44c0f0
// 0044c4d4  83f8ff               cmp eax, -1
// 0044c4d7  7452                 je 0x44c52b
// 0044c4d9  837c241000           cmp dword ptr [esp + 0x10], 0
// 0044c4de  898678010000         mov dword ptr [esi + 0x178], eax
// 0044c4e4  752f                 jne 0x44c515
// 0044c4e6  83ec10               sub esp, 0x10
// 0044c4e9  8bc4                 mov eax, esp
// 0044c4eb  33c9                 xor ecx, ecx
// 0044c4ed  8908                 mov dword ptr [eax], ecx
// 0044c4ef  33d2                 xor edx, edx
// 0044c4f1  33ff                 xor edi, edi
// 0044c4f3  895004               mov dword ptr [eax + 4], edx
// 0044c4f6  33db                 xor ebx, ebx
// 0044c4f8  897808               mov dword ptr [eax + 8], edi
// 0044c4fb  8bce                 mov ecx, esi
// 0044c4fd  89580c               mov dword ptr [eax + 0xc], ebx
// 0044c500  e85b562d00           call 0x721b60
// 0044c505  c78678010000ffffffff mov dword ptr [esi + 0x178], 0xffffffff
// 0044c50f  5f                   pop edi
// 0044c510  5e                   pop esi
// 0044c511  5b                   pop ebx
// 0044c512  c20c00               ret 0xc
// 0044c515  8b16                 mov edx, dword ptr [esi]
// 0044c517  8b8298000000         mov eax, dword ptr [edx + 0x98]
// 0044c51d  8bce                 mov ecx, esi
// 0044c51f  ffd0                 call eax
// 0044c521  c78678010000ffffffff mov dword ptr [esi + 0x178], 0xffffffff
// 0044c52b  5f                   pop edi
// 0044c52c  5e                   pop esi
// 0044c52d  5b                   pop ebx
// 0044c52e  c20c00               ret 0xc
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
    char padding2[0x18];
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
