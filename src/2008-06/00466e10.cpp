// from server: 100% by king_originala
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
