// from server: 84% by EspClaude
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 00466e10  unit: CSettingsDialog  size: 147 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00466e10
//
// 00466e10  6aff                 push -1
// 00466e12  6893357c00           push 0x7c3593
// 00466e17  64a100000000         mov eax, dword ptr fs:[0]
// 00466e1d  50                   push eax
// 00466e1e  64892500000000       mov dword ptr fs:[0], esp
// 00466e25  51                   push ecx
// 00466e26  8b442414             mov eax, dword ptr [esp + 0x14]
// 00466e2a  53                   push ebx
// 00466e2b  56                   push esi
// 00466e2c  57                   push edi
// 00466e2d  50                   push eax
// 00466e2e  8bf1                 mov esi, ecx
// 00466e30  6a7a                 push 0x7a
// 00466e32  89742414             mov dword ptr [esp + 0x14], esi
// 00466e36  e89da02300           call 0x6a0ed8
// 00466e3b  33db                 xor ebx, ebx
// 00466e3d  8d4e74               lea ecx, [esi + 0x74]
// 00466e40  895c2418             mov dword ptr [esp + 0x18], ebx
// 00466e44  c706b4bf8100         mov dword ptr [esi], 0x81bfb4
// 00466e4a  e8011e2a00           call 0x708c50
// 00466e4f  8dbe90010000         lea edi, [esi + 0x190]
// 00466e55  8bcf                 mov ecx, edi
// 00466e57  c644241801           mov byte ptr [esp + 0x18], 1
// 00466e5c  899e8c010000         mov dword ptr [esi + 0x18c], ebx
// 00466e62  e8b9bcfdff           call 0x442b20
// 00466e67  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00466e6b  899f3c020000         mov dword ptr [edi + 0x23c], ebx
// 00466e71  899f40020000         mov dword ptr [edi + 0x240], ebx
// 00466e77  c70774c18100         mov dword ptr [edi], 0x81c174
// 00466e7d  c7878801000068c18100 mov dword ptr [edi + 0x188], 0x81c168
// 00466e87  c787380200005cc18100 mov dword ptr [edi + 0x238], 0x81c15c
// 00466e91  5f                   pop edi
// 00466e92  8bc6                 mov eax, esi
// 00466e94  5e                   pop esi
// 00466e95  5b                   pop ebx
// 00466e96  64890d00000000       mov dword ptr fs:[0], ecx
// 00466e9d  83c410               add esp, 0x10
// 00466ea0  c20400               ret 4

struct DialogBase {
    virtual ~DialogBase();
    char storage[0x70];
    DialogBase(int, void*);
};

struct Splitter {
    char storage[0x118];
    Splitter();
    ~Splitter();
};

struct Primary {
    virtual ~Primary();
    char storage[0x184];
};

struct Secondary {
    virtual ~Secondary();
    char storage[0xAC];
};

struct Tertiary {
    virtual ~Tertiary();
};

struct ControlBase : Primary, Secondary, Tertiary {
    ControlBase();
    virtual ~ControlBase();
};

struct Control : ControlBase {
    int first;
    int second;
    Control();
    virtual ~Control();
};

struct CSettingsDialog : DialogBase {
    Splitter splitter;
    int value;
    Control control;
    CSettingsDialog(void*);
    virtual ~CSettingsDialog();
};

__forceinline Control::Control()
    : ControlBase(), first(0), second(0)
{
}

CSettingsDialog::CSettingsDialog(void* parent)
    : DialogBase(0x7A, parent), splitter(), value(0), control()
{
}
