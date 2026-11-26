// from server: 100% by Xemicl
// roc 2012-06 00437500  unit: CMainFrame  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00437500
//
// 00437500  83ec10               sub esp, 0x10
// 00437503  56                   push esi
// 00437504  57                   push edi
// 00437505  6a01                 push 1
// 00437507  6a00                 push 0
// 00437509  6a00                 push 0
// 0043750b  6a00                 push 0
// 0043750d  6800e90000           push 0xe900
// 00437512  68ffe80000           push 0xe8ff
// 00437517  6800e80000           push 0xe800
// 0043751c  8bf1                 mov esi, ecx
// 0043751e  e8d5b55400           call 0x982af8
// 00437523  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00437527  57                   push edi
// 00437528  8d4c240c             lea ecx, [esp + 0xc]
// 0043752c  e80fdc5900           call 0x9d5140
// 00437531  8b8700010000         mov eax, dword ptr [edi + 0x100]
// 00437537  83f802               cmp eax, 2
// 0043753a  740a                 je 0x437546
// 0043753c  83f803               cmp eax, 3
// 0043753f  7405                 je 0x437546
// 00437541  83f805               cmp eax, 5
// 00437544  7512                 jne 0x437558
// 00437546  8b442414             mov eax, dword ptr [esp + 0x14]
// 0043754a  2b44240c             sub eax, dword ptr [esp + 0xc]
// 0043754e  8d4c2408             lea ecx, [esp + 8]
// 00437552  50                   push eax
// 00437553  6a00                 push 0
// 00437555  51                   push ecx
// 00437556  eb10                 jmp 0x437568
// 00437558  8b542410             mov edx, dword ptr [esp + 0x10]
// 0043755c  2b542408             sub edx, dword ptr [esp + 8]
// 00437560  6a00                 push 0
// 00437562  52                   push edx
// 00437563  8d442410             lea eax, [esp + 0x10]
// 00437567  50                   push eax
// 00437568  ff15f43ab200         call dword ptr [0xb23af4]
// 0043756e  8b8f80010000         mov ecx, dword ptr [edi + 0x180]
// 00437574  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00437578  51                   push ecx
// 00437579  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 0043757f  8d54240c             lea edx, [esp + 0xc]
// 00437583  52                   push edx
// 00437584  50                   push eax
// 00437585  e886ad5600           call 0x9a2310
// 0043758a  5f                   pop edi
// 0043758b  5e                   pop esi
// 0043758c  83c410               add esp, 0x10
// 0043758f  c20800               ret 8
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