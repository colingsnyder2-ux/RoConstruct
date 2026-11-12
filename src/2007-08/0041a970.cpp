// from server: 70% by EspClaude
// from server: 46% by colin
// roc 2007-08 0041a970  unit: VDHTMLWindow::?$BoundFuncDesc  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041a970
//
// 0041a970  56                   push esi
// 0041a971  57                   push edi
// 0041a972  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0041a976  8b4710               mov eax, dword ptr [edi + 0x10]
// 0041a979  83ec0c               sub esp, 0xc
// 0041a97c  8bcc                 mov ecx, esp
// 0041a97e  89642418             mov dword ptr [esp + 0x18], esp
// 0041a982  8d7708               lea esi, [edi + 8]
// 0041a985  6a00                 push 0
// 0041a987  50                   push eax
// 0041a988  e813daffff           call 0x4183a0
// 0041a98d  56                   push esi
// 0041a98e  8bcf                 mov ecx, edi
// 0041a990  e8abb2ffff           call 0x415c40
// 0041a995  5f                   pop edi
// 0041a996  5e                   pop esi
// 0041a997  c3                   ret 
// Arg of 0x415c40: 12-byte object passed by value, built in place by its
// thiscall ctor 0x4183a0(int, int) (sub esp,0xc; mov ecx,esp; call).
struct Arg12 {
    int a, b, c;
    Arg12(int v, int w);
    Arg12(const Arg12&);
    ~Arg12();
};

struct BoundFuncDesc {
    int f0, f4;
    int f8;   // +8 : address passed to 0x415c40
    int fc;
    int f10;  // +0x10
    void bind(void* p, Arg12 a);   // 0x415c40 thiscall
};

void construct(BoundFuncDesc* d)
{
    int* p = &d->f8;
    d->bind(p, Arg12(d->f10, 0));
}
