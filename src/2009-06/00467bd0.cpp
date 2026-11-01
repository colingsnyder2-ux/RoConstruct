// from server: 100% by EspClaude
// from server: 82% by EspClaude
// roc 2009-06 00467bd0  unit: CSettingsDialog  size: 156 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00467bd0
//

// from server: 100% by king_originala
// roc 2008-06 00466e10  unit: CSettingsDialog  size: 147 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00466e10
//

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

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern volatile long g_instanceCount;

struct ControlBase {
    virtual ~ControlBase();
    char storage[0x264];
    ControlBase();
};

struct One { int a; One() : a(0) {} };
struct Mid : ControlBase {
    int first;
    One second;
    Mid() : first(0) { InterlockedIncrement(&g_instanceCount); }
    virtual ~Mid();
};

struct Control : Mid {
    int third;
    int fourth;
    Control() : third(0), fourth(0) {}
    virtual ~Control();
};

struct CSettingsDialog : DialogBase {
    Splitter splitter;
    int value;
    Control control;
    CSettingsDialog(void*);
    virtual ~CSettingsDialog();
};

CSettingsDialog::CSettingsDialog(void* parent)
    : DialogBase(0x7A, parent), splitter(), value(0), control()
{
}

