// from server: 97% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0044e370  unit: CRobloxControlColorSelector  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044e370
//
// 0044e370  53                   push ebx
// 0044e371  56                   push esi
// 0044e372  8bf1                 mov esi, ecx
// 0044e374  8b869c000000         mov eax, dword ptr [esi + 0x9c]
// 0044e37a  57                   push edi
// 0044e37b  83f8ff               cmp eax, -1
// 0044e37e  750f                 jne 0x44e38f
// 0044e380  8b8e5c010000         mov ecx, dword ptr [esi + 0x15c]
// 0044e386  85c9                 test ecx, ecx
// 0044e388  7405                 je 0x44e38f
// 0044e38a  e831d42500           call 0x6ab7c0
// 0044e38f  85c0                 test eax, eax
// 0044e391  7468                 je 0x44e3fb
// 0044e393  8b442418             mov eax, dword ptr [esp + 0x18]
// 0044e397  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044e39b  50                   push eax
// 0044e39c  51                   push ecx
// 0044e39d  8bce                 mov ecx, esi
// 0044e39f  e81cfcffff           call 0x44dfc0
// 0044e3a4  83f8ff               cmp eax, -1
// 0044e3a7  7452                 je 0x44e3fb
// 0044e3a9  837c241000           cmp dword ptr [esp + 0x10], 0
// 0044e3ae  898678010000         mov dword ptr [esi + 0x178], eax
// 0044e3b4  752f                 jne 0x44e3e5
// 0044e3b6  83ec10               sub esp, 0x10
// 0044e3b9  8bc4                 mov eax, esp
// 0044e3bb  33c9                 xor ecx, ecx
// 0044e3bd  8908                 mov dword ptr [eax], ecx
// 0044e3bf  33d2                 xor edx, edx
// 0044e3c1  33ff                 xor edi, edi
// 0044e3c3  895004               mov dword ptr [eax + 4], edx
// 0044e3c6  33db                 xor ebx, ebx
// 0044e3c8  897808               mov dword ptr [eax + 8], edi
// 0044e3cb  8bce                 mov ecx, esi
// 0044e3cd  89580c               mov dword ptr [eax + 0xc], ebx
// 0044e3d0  e87bf02500           call 0x6ad450
// 0044e3d5  c78678010000ffffffff mov dword ptr [esi + 0x178], 0xffffffff
// 0044e3df  5f                   pop edi
// 0044e3e0  5e                   pop esi
// 0044e3e1  5b                   pop ebx
// 0044e3e2  c20c00               ret 0xc
// 0044e3e5  8b16                 mov edx, dword ptr [esi]
// 0044e3e7  8b8298000000         mov eax, dword ptr [edx + 0x98]
// 0044e3ed  8bce                 mov ecx, esi
// 0044e3ef  ffd0                 call eax
// 0044e3f1  c78678010000ffffffff mov dword ptr [esi + 0x178], 0xffffffff
// 0044e3fb  5f                   pop edi
// 0044e3fc  5e                   pop esi
// 0044e3fd  5b                   pop ebx
// 0044e3fe  c20c00               ret 0xc

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
