// from server: 100% by EspClaude
// from server: 46% by colin
// roc 2007-08 0041a680  unit: VDHTMLWindow::?$BoundFuncDesc  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041a680
//
// 0041a680  6aff                 push -1
// 0041a682  6809b27300           push 0x73b209
// 0041a687  64a100000000         mov eax, dword ptr fs:[0]
// 0041a68d  50                   push eax
// 0041a68e  51                   push ecx
// 0041a68f  56                   push esi
// 0041a690  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041a695  33c4                 xor eax, esp
// 0041a697  50                   push eax
// 0041a698  8d44240c             lea eax, [esp + 0xc]
// 0041a69c  64a300000000         mov dword ptr fs:[0], eax
// 0041a6a2  8bf1                 mov esi, ecx
// 0041a6a4  89742408             mov dword ptr [esp + 8], esi
// 0041a6a8  8b442434             mov eax, dword ptr [esp + 0x34]
// 0041a6ac  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0041a6b0  50                   push eax
// 0041a6b1  51                   push ecx
// 0041a6b2  e859eaffff           call 0x419110
// 0041a6b7  50                   push eax
// 0041a6b8  8bce                 mov ecx, esi
// 0041a6ba  e8f1661500           call 0x570db0
// 0041a6bf  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0041a6c3  8b442420             mov eax, dword ptr [esp + 0x20]
// 0041a6c7  8d4e30               lea ecx, [esi + 0x30]
// 0041a6ca  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0041a6d2  c70680787800         mov dword ptr [esi], 0x787880
// 0041a6d8  895628               mov dword ptr [esi + 0x28], edx
// 0041a6db  89462c               mov dword ptr [esi + 0x2c], eax
// 0041a6de  e8dd2c1500           call 0x56d3c0
// 0041a6e3  8d4e38               lea ecx, [esi + 0x38]
// 0041a6e6  c644241401           mov byte ptr [esp + 0x14], 1
// 0041a6eb  e8d02c1500           call 0x56d3c0
// 0041a6f0  8d4e40               lea ecx, [esi + 0x40]
// 0041a6f3  c644241402           mov byte ptr [esp + 0x14], 2
// 0041a6f8  e8c32c1500           call 0x56d3c0
// 0041a6fd  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0041a701  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0041a705  8b442428             mov eax, dword ptr [esp + 0x28]
// 0041a709  51                   push ecx
// 0041a70a  52                   push edx
// 0041a70b  50                   push eax
// 0041a70c  8bce                 mov ecx, esi
// 0041a70e  c644242003           mov byte ptr [esp + 0x20], 3
// 0041a713  e88891ffff           call 0x4138a0
// 0041a718  8bc6                 mov eax, esi
// 0041a71a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0041a71e  64890d00000000       mov dword ptr fs:[0], ecx
// 0041a725  59                   pop ecx
// 0041a726  5e                   pop esi
// 0041a727  83c410               add esp, 0x10
// 0041a72a  c21c00               ret 0x1c

// Base: 0x28 bytes (first own field at +0x28), thiscall ctor 0x570db0(int).
struct DescBase {
    char pad[0x24];   // + vptr = 0x28
    DescBase(int a);
    virtual ~DescBase();
};

// Members at +0x30/+0x38/+0x40, 8 bytes apart, default ctor 0x56d3c0.
struct Member8 {
    int a, b;
    Member8();
    ~Member8();
};

int __stdcall sub_419110(int a, int b);   // callee-cleans 2 args

struct BoundFuncDesc : DescBase {
    int field28;
    int field2c;
    Member8 m30;
    Member8 m38;
    Member8 m40;

    BoundFuncDesc(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
    virtual ~BoundFuncDesc();
    void init(int a, int b, int c);       // 0x4138a0 thiscall
};

BoundFuncDesc::BoundFuncDesc(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
    : DescBase(sub_419110(a3, a7)), field28(a1), field2c(a2)
{
    init(a4, a5, a6);
}
