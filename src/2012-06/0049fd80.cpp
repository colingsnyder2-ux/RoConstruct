// from server: 100% by Xemicl
// roc 2012-06 0049fd80  unit: Scintilla::CScintillaView  size: 311 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0049fd80
//
// 0049fd80  6aff                 push -1
// 0049fd82  682b3baa00           push 0xaa3b2b
// 0049fd87  64a100000000         mov eax, dword ptr fs:[0]
// 0049fd8d  50                   push eax
// 0049fd8e  64892500000000       mov dword ptr fs:[0], esp
// 0049fd95  81ec0c010000         sub esp, 0x10c
// 0049fd9b  56                   push esi
// 0049fd9c  57                   push edi
// 0049fd9d  33ff                 xor edi, edi
// 0049fd9f  57                   push edi
// 0049fda0  8bf1                 mov esi, ecx
// 0049fda2  6a02                 push 2
// 0049fda4  8d4c2410             lea ecx, [esp + 0x10]
// 0049fda8  e897324e00           call 0x983044
// 0049fdad  838c248c00000002     or dword ptr [esp + 0x8c], 2
// 0049fdb5  89bc241c010000       mov dword ptr [esp + 0x11c], edi
// 0049fdbc  39bee8000000         cmp dword ptr [esi + 0xe8], edi
// 0049fdc2  740a                 je 0x49fdce
// 0049fdc4  838c248c00000008     or dword ptr [esp + 0x8c], 8
// 0049fdcc  eb08                 jmp 0x49fdd6
// 0049fdce  838c248c00000004     or dword ptr [esp + 0x8c], 4
// 0049fdd6  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 0049fddc  8b8ecc000000         mov ecx, dword ptr [esi + 0xcc]
// 0049fde2  8b96d0000000         mov edx, dword ptr [esi + 0xd0]
// 0049fde8  81c6c8000000         add esi, 0xc8
// 0049fdee  898424a8000000       mov dword ptr [esp + 0xa8], eax
// 0049fdf5  8b460c               mov eax, dword ptr [esi + 0xc]
// 0049fdf8  898c24ac000000       mov dword ptr [esp + 0xac], ecx
// 0049fdff  899424b0000000       mov dword ptr [esp + 0xb0], edx
// 0049fe06  898424b4000000       mov dword ptr [esp + 0xb4], eax
// 0049fe0d  89bc24dc000000       mov dword ptr [esp + 0xdc], edi
// 0049fe14  89bc24d8000000       mov dword ptr [esp + 0xd8], edi
// 0049fe1b  e8b2254e00           call 0x9823d2
// 0049fe20  8b7804               mov edi, dword ptr [eax + 4]
// 0049fe23  8d8c24d0000000       lea ecx, [esp + 0xd0]
// 0049fe2a  51                   push ecx
// 0049fe2b  8bcf                 mov ecx, edi
// 0049fe2d  e80c324e00           call 0x98303e
// 0049fe32  8b9424dc000000       mov edx, dword ptr [esp + 0xdc]
// 0049fe39  8b8424d8000000       mov eax, dword ptr [esp + 0xd8]
// 0049fe40  8d4c2408             lea ecx, [esp + 8]
// 0049fe44  89942488000000       mov dword ptr [esp + 0x88], edx
// 0049fe4b  89842484000000       mov dword ptr [esp + 0x84], eax
// 0049fe52  e8e1314e00           call 0x983038
// 0049fe57  83f801               cmp eax, 1
// 0049fe5a  7528                 jne 0x49fe84
// 0049fe5c  8d8c24a8000000       lea ecx, [esp + 0xa8]
// 0049fe63  51                   push ecx
// 0049fe64  56                   push esi
// 0049fe65  ff15ec3ab200         call dword ptr [0xb23aec]
// 0049fe6b  8b942484000000       mov edx, dword ptr [esp + 0x84]
// 0049fe72  8b842488000000       mov eax, dword ptr [esp + 0x88]
// 0049fe79  6a01                 push 1
// 0049fe7b  52                   push edx
// 0049fe7c  50                   push eax
// 0049fe7d  8bcf                 mov ecx, edi
// 0049fe7f  e8ae314e00           call 0x983032
// 0049fe84  8d4c2408             lea ecx, [esp + 8]
// 0049fe88  c784241c010000ffffffff mov dword ptr [esp + 0x11c], 0xffffffff
// 0049fe93  c74424081cfeb500     mov dword ptr [esp + 8], 0xb5fe1c
// 0049fe9b  e86e2b4e00           call 0x982a0e
// 0049fea0  8b8c2414010000       mov ecx, dword ptr [esp + 0x114]
// 0049fea7  5f                   pop edi
// 0049fea8  5e                   pop esi
// 0049fea9  64890d00000000       mov dword ptr fs:[0], ecx
// 0049feb0  81c418010000         add esp, 0x118
// 0049feb6  c3                   ret 
// copied from an identical function in another client (function ?PageSetup@View@ns_ROCX00006f@@QAEXXZ)

namespace ns_ROCX00006f {
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
}