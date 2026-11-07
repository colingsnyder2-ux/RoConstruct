// from server: 100% by Intel
// from server: 98% by EspClaude
// roc 2007-08 00430a60  unit: CWrapperView  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00430a60
//
// 00430a60  83ec10               sub esp, 0x10
// 00430a63  56                   push esi
// 00430a64  57                   push edi
// 00430a65  6a01                 push 1
// 00430a67  6a00                 push 0
// 00430a69  6a00                 push 0
// 00430a6b  6a00                 push 0
// 00430a6d  6800e90000           push 0xe900
// 00430a72  68ffe80000           push 0xe8ff
// 00430a77  6800e80000           push 0xe800
// 00430a7c  8bf1                 mov esi, ecx
// 00430a7e  e8affa1f00           call 0x630532
// 00430a83  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00430a87  57                   push edi
// 00430a88  8d4c240c             lea ecx, [esp + 0xc]
// 00430a8c  e80ff52400           call 0x67ffa0
// 00430a91  8b87fc000000         mov eax, dword ptr [edi + 0xfc]
// 00430a97  83f802               cmp eax, 2
// 00430a9a  740a                 je 0x430aa6
// 00430a9c  83f803               cmp eax, 3
// 00430a9f  7405                 je 0x430aa6
// 00430aa1  83f805               cmp eax, 5
// 00430aa4  7512                 jne 0x430ab8
// 00430aa6  8b442414             mov eax, dword ptr [esp + 0x14]
// 00430aaa  2b44240c             sub eax, dword ptr [esp + 0xc]
// 00430aae  8d4c2408             lea ecx, [esp + 8]
// 00430ab2  50                   push eax
// 00430ab3  6a00                 push 0
// 00430ab5  51                   push ecx
// 00430ab6  eb10                 jmp 0x430ac8
// 00430ab8  8b542410             mov edx, dword ptr [esp + 0x10]
// 00430abc  2b542408             sub edx, dword ptr [esp + 8]
// 00430ac0  6a00                 push 0
// 00430ac2  52                   push edx
// 00430ac3  8d442410             lea eax, [esp + 0x10]
// 00430ac7  50                   push eax
// 00430ac8  ff15d8ed7700         call dword ptr [0x77edd8]
// 00430ace  8b8f80010000         mov ecx, dword ptr [edi + 0x180]
// 00430ad4  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00430ad8  51                   push ecx
// 00430ad9  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 00430adf  8d54240c             lea edx, [esp + 0xc]
// 00430ae3  52                   push edx
// 00430ae4  50                   push eax
// 00430ae5  e866122000           call 0x631d50
// 00430aea  5f                   pop edi
// 00430aeb  5e                   pop esi
// 00430aec  83c410               add esp, 0x10
// 00430aef  c20800               ret 8

// from server: 100% by colin
// roc-flags: /O2 /MD /GS /EHsc /Ob1
// roc-cl: 21022
struct Bar;

struct Rect
{
    int left;
    int top;
    int right;
    int bottom;

    Rect(Bar*);
};

extern "C" int (__stdcall *OffsetRect)(Rect*, int, int);

struct CommandBars
{
    int func_006a2a00(void*, Rect*, void*);
};

struct Bar
{
    char reserved0[0xFC];
    int position;
    char reserved1[0x7C+4];
    void* menu;
};

struct CWrapperView
{
    char reserved[0xD8];
    CommandBars* commandBars;

    void func_006a0fc8(int, int, int, int, Rect*, Rect*, int);
    int func_004303a0(void*, Bar*);
};

int CWrapperView::func_004303a0(void* context, Bar* bar)
{
    func_006a0fc8(0xE800, 0xE8FF, 0xE900, 0, 0, 0, 1);

    Rect rect(bar);

    int pos = bar->position;
    if (pos == 2) goto L_case;
    if (pos == 3) goto L_case;
    if (pos == 5) goto L_case;
    goto L_default;

L_case:
    OffsetRect(&rect, 0, rect.bottom - rect.top);
    goto L_end;

L_default:
    OffsetRect(&rect, rect.right - rect.left, 0);

L_end:
    return commandBars->func_006a2a00(context, &rect, bar->menu);
}
