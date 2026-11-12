// from server: 100% by EspClaude
// from server: 41% by colin
// roc 2007-08 00455ce0  unit: CRobloxReportPaneView  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00455ce0
// 00455ce0  6aff                 push -1
// 00455ce2  68fad87300           push 0x73d8fa
// 00455ce7  64a100000000         mov eax, dword ptr fs:[0]
// 00455ced  50                   push eax
// 00455cee  51                   push ecx
// 00455cef  56                   push esi
// 00455cf0  a188518b00           mov eax, dword ptr [0x8b5188]
// 00455cf5  33c4                 xor eax, esp
// 00455cf7  50                   push eax
// 00455cf8  8d44240c             lea eax, [esp + 0xc]
// 00455cfc  64a300000000         mov dword ptr fs:[0], eax
// 00455d02  6818030000           push 0x318
// 00455d07  e8eaa11d00           call 0x62fef6
// 00455d0c  8bf0                 mov esi, eax
// 00455d0e  83c404               add esp, 4
// 00455d11  89742408             mov dword ptr [esp + 8], esi
// 00455d15  33c0                 xor eax, eax
// 00455d17  3bf0                 cmp esi, eax
// 00455d19  89442414             mov dword ptr [esp + 0x14], eax
// 00455d1d  7423                 je 0x455d42
// 00455d1f  8bce                 mov ecx, esi
// 00455d21  e81aeaffff           call 0x454740
// 00455d26  c706c4267900         mov dword ptr [esi], 0x7926c4
// 00455d2c  c786cc020000b0267900 mov dword ptr [esi + 0x2cc], 0x7926b0
// 00455d36  c786e80200009c267900 mov dword ptr [esi + 0x2e8], 0x79269c
// 00455d40  8bc6                 mov eax, esi
// 00455d42  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00455d46  64890d00000000       mov dword ptr fs:[0], ecx
// 00455d4d  59                   pop ecx
// 00455d4e  5e                   pop esi
// 00455d4f  83c410               add esp, 0x10
// 00455d52  c3                   ret 

class CObject;

class Base0 {
public:
    virtual ~Base0();
    char pad_4[0x2c8];
};

class Base1 {
public:
    virtual void f1();
    char pad_4[0x18];
};

class Base2 {
public:
    virtual void f2();
    char pad_4[0x2c];
};

class CRobloxReportPaneViewBase : public Base0, public Base1, public Base2 {
public:
    CRobloxReportPaneViewBase();
};

class CRobloxReportPaneView : public CRobloxReportPaneViewBase {
public:
    virtual void f1();
    virtual void f2();
    static CObject* __stdcall CreateObject();
};

CObject* __stdcall CRobloxReportPaneView::CreateObject()
{
    return (CObject*)new CRobloxReportPaneView;
}
