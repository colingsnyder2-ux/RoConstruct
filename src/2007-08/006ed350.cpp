// from server: 100% by EspClaude
// from server: 71% by colin
// roc 2007-08 006ed350  unit: CXTPDockingPaneContext  size: 192 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006ed350
//
// 006ed350  83ec0c               sub esp, 0xc
// 006ed353  8b442420             mov eax, dword ptr [esp + 0x20]
// 006ed357  2b442418             sub eax, dword ptr [esp + 0x18]
// 006ed35b  53                   push ebx
// 006ed35c  56                   push esi
// 006ed35d  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 006ed361  2b742424             sub esi, dword ptr [esp + 0x24]
// 006ed365  6a00                 push 0
// 006ed367  6a00                 push 0
// 006ed369  6a00                 push 0
// 006ed36b  6a00                 push 0
// 006ed36d  894c2418             mov dword ptr [esp + 0x18], ecx
// 006ed371  8944241c             mov dword ptr [esp + 0x1c], eax
// 006ed375  89742420             mov dword ptr [esp + 0x20], esi
// 006ed379  ff1524d17700         call dword ptr [0x77d124]
// 006ed37f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006ed383  50                   push eax
// 006ed384  e8af2ef4ff           call 0x630238
// 006ed389  33db                 xor ebx, ebx
// 006ed38b  85f6                 test esi, esi
// 006ed38d  7e79                 jle 0x6ed408
// 006ed38f  55                   push ebp
// 006ed390  57                   push edi
// 006ed391  33ed                 xor ebp, ebp
// 006ed393  33f6                 xor esi, esi
// 006ed395  39742414             cmp dword ptr [esp + 0x14], esi
// 006ed399  8d7d01               lea edi, [ebp + 1]
// 006ed39c  7e5f                 jle 0x6ed3fd
// 006ed39e  8bff                 mov edi, edi
// 006ed3a0  8b442424             mov eax, dword ptr [esp + 0x24]
// 006ed3a4  8b4804               mov ecx, dword ptr [eax + 4]
// 006ed3a7  53                   push ebx
// 006ed3a8  56                   push esi
// 006ed3a9  51                   push ecx
// 006ed3aa  ff1534d17700         call dword ptr [0x77d134]
// 006ed3b0  f7d8                 neg eax
// 006ed3b2  1bc0                 sbb eax, eax
// 006ed3b4  83c001               add eax, 1
// 006ed3b7  85ff                 test edi, edi
// 006ed3b9  740a                 je 0x6ed3c5
// 006ed3bb  85c0                 test eax, eax
// 006ed3bd  7520                 jne 0x6ed3df
// 006ed3bf  8bee                 mov ebp, esi
// 006ed3c1  33ff                 xor edi, edi
// 006ed3c3  eb1a                 jmp 0x6ed3df
// 006ed3c5  85c0                 test eax, eax
// 006ed3c7  7416                 je 0x6ed3df
// 006ed3c9  8b542420             mov edx, dword ptr [esp + 0x20]
// 006ed3cd  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006ed3d1  56                   push esi
// 006ed3d2  53                   push ebx
// 006ed3d3  55                   push ebp
// 006ed3d4  52                   push edx
// 006ed3d5  e8c6feffff           call 0x6ed2a0
// 006ed3da  bf01000000           mov edi, 1
// 006ed3df  83c601               add esi, 1
// 006ed3e2  3b742414             cmp esi, dword ptr [esp + 0x14]
// 006ed3e6  7cb8                 jl 0x6ed3a0
// 006ed3e8  85ff                 test edi, edi
// 006ed3ea  7511                 jne 0x6ed3fd
// 006ed3ec  8b442420             mov eax, dword ptr [esp + 0x20]
// 006ed3f0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006ed3f4  56                   push esi
// 006ed3f5  53                   push ebx
// 006ed3f6  55                   push ebp
// 006ed3f7  50                   push eax
// 006ed3f8  e8a3feffff           call 0x6ed2a0
// 006ed3fd  83c301               add ebx, 1
// 006ed400  3b5c2418             cmp ebx, dword ptr [esp + 0x18]
// 006ed404  7c8b                 jl 0x6ed391
// 006ed406  5f                   pop edi
// 006ed407  5d                   pop ebp
// 006ed408  5e                   pop esi
// 006ed409  5b                   pop ebx
// 006ed40a  83c40c               add esp, 0xc
// 006ed40d  c21800               ret 0x18

extern "C" __declspec(dllimport) void* __stdcall CreateRectRgn(int, int, int, int);
extern "C" __declspec(dllimport) unsigned long __stdcall GetPixel(void*, int, int);

struct Rgn
{
    void* vt;
    void* m_hObject;
    int Attach(void*);
    int CreateRectRgn(int x1, int y1, int x2, int y2) { return Attach(::CreateRectRgn(x1, y1, x2, y2)); }
};

struct DC
{
    void* vt;
    void* m_hDC;
    unsigned long GetPixel(int x, int y) const { return ::GetPixel(m_hDC, x, y); }
};

struct Sz { int cx, cy; };
struct Rc { int left, top, right, bottom; Sz Size() const { Sz s; s.cx = right - left; s.cy = bottom - top; return s; } };

struct CXTPDockingPaneContext
{
    void func_006ed350(Rgn* pRgn, DC* pDC, Rc rc);
    void sub_006ed2a0(Rgn*, int, int, int);
};

void CXTPDockingPaneContext::func_006ed350(Rgn* pRgn, DC* pDC, Rc rc)
{
    Sz sz = rc.Size();
    pRgn->CreateRectRgn(0, 0, 0, 0);

    for (int y = 0; y < sz.cy; y++)
    {
        int start = 0;
        int bOut = 1;
        int x;
        for (x = 0; x < sz.cx; x++)
        {
            int bTransparent = pDC->GetPixel(x, y) == 0;
            if (bOut)
            {
                if (!bTransparent)
                {
                    start = x;
                    bOut = 0;
                }
            }
            else if (bTransparent)
            {
                sub_006ed2a0(pRgn, start, y, x);
                bOut = 1;
            }
        }
        if (!bOut)
            sub_006ed2a0(pRgn, start, y, x);
    }
}
