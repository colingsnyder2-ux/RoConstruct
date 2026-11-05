// from server: 100% by king_originala
typedef unsigned long DWORD;

struct RECT {
    long left, top, right, bottom;
};

struct POINT {
    long x, y;
};

struct PAGESETUPDLG {
    DWORD lStructSize;
    void* hwndOwner;
    void* hDevMode;
    void* hDevNames;
    DWORD Flags;
    POINT ptPaperSize;
    RECT rtMinMargin;
    RECT rtMargin;
    void* hInstance;
    long lCustData;
    void* lpfnPageSetupHook;
    void* lpfnPagePaintHook;
    const char* lpPageSetupTemplateName;
    void* hPageSetupTemplate;
};

struct PRINTDLG {
    char prefix[8];
    void* hDevMode;
    void* hDevNames;
    char suffix[50];
};

struct Dialog {
    virtual ~Dialog();
    char data[0x70];
};

struct PageSetupDialog : Dialog {
    PAGESETUPDLG psd;
    PageSetupDialog(DWORD flags, void* parent);
    virtual ~PageSetupDialog();
    virtual int DoModal();
};

inline PageSetupDialog::~PageSetupDialog()
{
}

struct Printer {
    int GetPrinterDeviceDefaults(PRINTDLG*);
    void SelectPrinter(void* names, void* mode, int freePrevious);
};

struct Application {
    void* reserved;
    Printer* printer;
};

Application* __cdecl GetApplication();

extern "C" int (__stdcall *CopyRect)(RECT*, const RECT*);

struct View {
    char prefix[0xc8];
    RECT margins;
    char padding[0x10];
    int metric;
    void PageSetup();
};

void View::PageSetup()
{
    PageSetupDialog dialog(2, 0);
    dialog.psd.Flags |= 2;
    if (metric)
        dialog.psd.Flags |= 8;
    else
        dialog.psd.Flags |= 4;

    dialog.psd.rtMargin = margins;

    PRINTDLG defaults;
    defaults.hDevNames = 0;
    defaults.hDevMode = 0;

    Printer* printer = GetApplication()->printer;
    printer->GetPrinterDeviceDefaults(&defaults);
    dialog.psd.hDevNames = defaults.hDevNames;
    dialog.psd.hDevMode = defaults.hDevMode;

    if (dialog.DoModal() == 1) {
        CopyRect(&margins, &dialog.psd.rtMargin);
        printer->SelectPrinter(dialog.psd.hDevNames,
                               dialog.psd.hDevMode, 1);
    }
}
