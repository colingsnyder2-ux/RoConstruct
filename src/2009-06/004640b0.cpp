// from server: 100% by EspClaude
// roc 2009-06 004640b0  unit: Scintilla::CScintillaView  size: 311 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004640b0
//
// 004640b0  6aff                 push -1
// 004640b2  687b2c8500           push 0x852c7b
// 004640b7  64a100000000         mov eax, dword ptr fs:[0]
// 004640bd  50                   push eax
// 004640be  64892500000000       mov dword ptr fs:[0], esp
// 004640c5  81ec0c010000         sub esp, 0x10c
// 004640cb  56                   push esi
// 004640cc  57                   push edi
// 004640cd  33ff                 xor edi, edi
// 004640cf  57                   push edi
// 004640d0  8bf1                 mov esi, ecx
// 004640d2  6a02                 push 2
// 004640d4  8d4c2410             lea ecx, [esp + 0x10]
// 004640d8  e873582b00           call 0x719950
// 004640dd  838c248c00000002     or dword ptr [esp + 0x8c], 2
// 004640e5  89bc241c010000       mov dword ptr [esp + 0x11c], edi
// 004640ec  39bee8000000         cmp dword ptr [esi + 0xe8], edi
// 004640f2  740a                 je 0x4640fe
// 004640f4  838c248c00000008     or dword ptr [esp + 0x8c], 8
// 004640fc  eb08                 jmp 0x464106
// 004640fe  838c248c00000004     or dword ptr [esp + 0x8c], 4
// 00464106  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 0046410c  8b8ecc000000         mov ecx, dword ptr [esi + 0xcc]
// 00464112  8b96d0000000         mov edx, dword ptr [esi + 0xd0]
// 00464118  81c6c8000000         add esi, 0xc8
// 0046411e  898424a8000000       mov dword ptr [esp + 0xa8], eax
// 00464125  8b460c               mov eax, dword ptr [esi + 0xc]
// 00464128  898c24ac000000       mov dword ptr [esp + 0xac], ecx
// 0046412f  899424b0000000       mov dword ptr [esp + 0xb0], edx
// 00464136  898424b4000000       mov dword ptr [esp + 0xb4], eax
// 0046413d  89bc24dc000000       mov dword ptr [esp + 0xdc], edi
// 00464144  89bc24d8000000       mov dword ptr [esp + 0xd8], edi
// 0046414b  e8a64b2b00           call 0x718cf6
// 00464150  8b7804               mov edi, dword ptr [eax + 4]
// 00464153  8d8c24d0000000       lea ecx, [esp + 0xd0]
// 0046415a  51                   push ecx
// 0046415b  8bcf                 mov ecx, edi
// 0046415d  e8e8572b00           call 0x71994a
// 00464162  8b9424dc000000       mov edx, dword ptr [esp + 0xdc]
// 00464169  8b8424d8000000       mov eax, dword ptr [esp + 0xd8]
// 00464170  8d4c2408             lea ecx, [esp + 8]
// 00464174  89942488000000       mov dword ptr [esp + 0x88], edx
// 0046417b  89842484000000       mov dword ptr [esp + 0x84], eax
// 00464182  e8bd572b00           call 0x719944
// 00464187  83f801               cmp eax, 1
// 0046418a  7528                 jne 0x4641b4
// 0046418c  8d8c24a8000000       lea ecx, [esp + 0xa8]
// 00464193  51                   push ecx
// 00464194  56                   push esi
// 00464195  ff1500ee8900         call dword ptr [0x89ee00]
// 0046419b  8b942484000000       mov edx, dword ptr [esp + 0x84]
// 004641a2  8b842488000000       mov eax, dword ptr [esp + 0x88]
// 004641a9  6a01                 push 1
// 004641ab  52                   push edx
// 004641ac  50                   push eax
// 004641ad  8bcf                 mov ecx, edi
// 004641af  e88a572b00           call 0x71993e
// 004641b4  8d4c2408             lea ecx, [esp + 8]
// 004641b8  c784241c010000ffffffff mov dword ptr [esp + 0x11c], 0xffffffff
// 004641c3  c7442408acb28b00     mov dword ptr [esp + 8], 0x8bb2ac
// 004641cb  e898512b00           call 0x719368
// 004641d0  8b8c2414010000       mov ecx, dword ptr [esp + 0x114]
// 004641d7  5f                   pop edi
// 004641d8  5e                   pop esi
// 004641d9  64890d00000000       mov dword ptr fs:[0], ecx
// 004641e0  81c418010000         add esp, 0x118
// 004641e6  c3                   ret 
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
