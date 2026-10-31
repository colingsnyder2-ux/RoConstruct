// from server: 100% by EspClaude
// roc 2009-06 00429450  unit: CWrapperView  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00429450
//
// 00429450  83ec10               sub esp, 0x10
// 00429453  56                   push esi
// 00429454  57                   push edi
// 00429455  6a01                 push 1
// 00429457  6a00                 push 0
// 00429459  6a00                 push 0
// 0042945b  6a00                 push 0
// 0042945d  6800e90000           push 0xe900
// 00429462  68ffe80000           push 0xe8ff
// 00429467  6800e80000           push 0xe800
// 0042946c  8bf1                 mov esi, ecx
// 0042946e  e8c7ff2e00           call 0x71943a
// 00429473  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00429477  57                   push edi
// 00429478  8d4c240c             lea ecx, [esp + 0xc]
// 0042947c  e8ef6f3400           call 0x770470
// 00429481  8b8700010000         mov eax, dword ptr [edi + 0x100]
// 00429487  83f802               cmp eax, 2
// 0042948a  740a                 je 0x429496
// 0042948c  83f803               cmp eax, 3
// 0042948f  7405                 je 0x429496
// 00429491  83f805               cmp eax, 5
// 00429494  7512                 jne 0x4294a8
// 00429496  8b442414             mov eax, dword ptr [esp + 0x14]
// 0042949a  2b44240c             sub eax, dword ptr [esp + 0xc]
// 0042949e  8d4c2408             lea ecx, [esp + 8]
// 004294a2  50                   push eax
// 004294a3  6a00                 push 0
// 004294a5  51                   push ecx
// 004294a6  eb10                 jmp 0x4294b8
// 004294a8  8b542410             mov edx, dword ptr [esp + 0x10]
// 004294ac  2b542408             sub edx, dword ptr [esp + 8]
// 004294b0  6a00                 push 0
// 004294b2  52                   push edx
// 004294b3  8d442410             lea eax, [esp + 0x10]
// 004294b7  50                   push eax
// 004294b8  ff15f8ed8900         call dword ptr [0x89edf8]
// 004294be  8b8f80010000         mov ecx, dword ptr [edi + 0x180]
// 004294c4  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004294c8  51                   push ecx
// 004294c9  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 004294cf  8d54240c             lea edx, [esp + 0xc]
// 004294d3  52                   push edx
// 004294d4  50                   push eax
// 004294d5  e8c6ff2f00           call 0x7294a0
// 004294da  5f                   pop edi
// 004294db  5e                   pop esi
// 004294dc  83c410               add esp, 0x10
// 004294df  c20800               ret 8
// copied from an identical function in another client (function ?fn_ROCX000000_004303a0@CWrapperView@@QAEHPAXPAUBar@@@Z)

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
    char reserved0[0x100];
    int position;
    char reserved1[0x7C];
    void* menu;
};

struct CWrapperView
{
    char reserved[0xEC];
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