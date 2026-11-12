// from server: 84% by EspClaude
// from server: 45% by colin
// roc 2007-08 00431460  unit: CMainFrame  size: 571 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00431460
// 00431460  6aff                 push -1
// 00431462  68fbda7300           push 0x73dafb
// 00431467  64a100000000         mov eax, dword ptr fs:[0]
// 0043146d  50                   push eax
// 0043146e  81ecb4000000         sub esp, 0xb4
// 00431474  a188518b00           mov eax, dword ptr [0x8b5188]
// 00431479  33c4                 xor eax, esp
// 0043147b  898424b0000000       mov dword ptr [esp + 0xb0], eax
// 00431482  53                   push ebx
// 00431483  55                   push ebp
// 00431484  56                   push esi
// 00431485  57                   push edi
// 00431486  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043148b  33c4                 xor eax, esp
// 0043148d  50                   push eax
// 0043148e  8d8424c8000000       lea eax, [esp + 0xc8]
// 00431495  64a300000000         mov dword ptr fs:[0], eax
// 0043149b  8b9c24d8000000       mov ebx, dword ptr [esp + 0xd8]
// 004314a2  8bac24dc000000       mov ebp, dword ptr [esp + 0xdc]
// 004314a9  689c000000           push 0x9c
// 004314ae  8d44242c             lea eax, [esp + 0x2c]
// 004314b2  6a00                 push 0
// 004314b4  50                   push eax
// 004314b5  e8d2f61f00           call 0x630b8c
// 004314ba  83c40c               add esp, 0xc
// 004314bd  6a00                 push 0
// 004314bf  8d4c242c             lea ecx, [esp + 0x2c]
// 004314c3  51                   push ecx
// 004314c4  6aff                 push -1
// 004314c6  55                   push ebp
// 004314c7  66c744245c9c00       mov word ptr [esp + 0x5c], 0x9c
// 004314ce  ff15c0ed7700         call dword ptr [0x77edc0]
// 004314d4  85c0                 test eax, eax
// 004314d6  756e                 jne 0x431546
// 004314d8  8d542418             lea edx, [esp + 0x18]
// 004314dc  52                   push edx
// 004314dd  e8ceae1300           call 0x56c3b0
// 004314e2  83c404               add esp, 4
// 004314e5  8b30                 mov esi, dword ptr [eax]
// 004314e7  c78424d000000000000000 mov dword ptr [esp + 0xd0], 0
// 004314f2  ff1500d37700         call dword ptr [0x77d300]
// 004314f8  50                   push eax
// 004314f9  6838b17800           push 0x78b138
// 004314fe  6a03                 push 3
// 00431500  56                   push esi
// 00431501  e89aab1300           call 0x56c0a0
// 00431506  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0043150a  83c410               add esp, 0x10
// 0043150d  85f6                 test esi, esi
// 0043150f  c78424d0000000ffffffff mov dword ptr [esp + 0xd0], 0xffffffff
// 0043151a  742a                 je 0x431546
// 0043151c  8d4604               lea eax, [esi + 4]
// 0043151f  83c9ff               or ecx, 0xffffffff
// 00431522  f00fc108             lock xadd dword ptr [eax], ecx
// 00431526  751e                 jne 0x431546
// 00431528  8b16                 mov edx, dword ptr [esi]
// 0043152a  8b4204               mov eax, dword ptr [edx + 4]
// 0043152d  8bce                 mov ecx, esi
// 0043152f  ffd0                 call eax
// 00431531  8d4e08               lea ecx, [esi + 8]
// 00431534  83caff               or edx, 0xffffffff
// 00431537  f00fc111             lock xadd dword ptr [ecx], edx
// 0043153b  7509                 jne 0x431546
// 0043153d  8b06                 mov eax, dword ptr [esi]
// 0043153f  8b5008               mov edx, dword ptr [eax + 8]
// 00431542  8bce                 mov ecx, esi
// 00431544  ffd2                 call edx
// 00431546  8b842494000000       mov eax, dword ptr [esp + 0x94]
// 0043154d  db842494000000       fild dword ptr [esp + 0x94]
// 00431554  85c0                 test eax, eax
// 00431556  7d06                 jge 0x43155e
// 00431558  dc0530b17800         fadd qword ptr [0x78b130]
// 0043155e  8b8c2498000000       mov ecx, dword ptr [esp + 0x98]
// 00431565  db842498000000       fild dword ptr [esp + 0x98]
// 0043156c  85c9                 test ecx, ecx
// 0043156e  7d06                 jge 0x431576
// 00431570  dc0530b17800         fadd qword ptr [0x78b130]
// 00431576  def9                 fdivp st(1)
// 00431578  b927000000           mov ecx, 0x27
// 0043157d  8d742428             lea esi, [esp + 0x28]
// 00431581  8bfb                 mov edi, ebx
// 00431583  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00431585  33f6                 xor esi, esi
// 00431587  56                   push esi
// 00431588  8d54242c             lea edx, [esp + 0x2c]
// 0043158c  52                   push edx
// 0043158d  56                   push esi
// 0043158e  55                   push ebp
// 0043158f  dd5c2430             fstp qword ptr [esp + 0x30]
// 00431593  ff15c0ed7700         call dword ptr [0x77edc0]
// 00431599  85c0                 test eax, eax
// 0043159b  0f84c9000000         je 0x43166a
// 004315a1  83c601               add esi, 1
// 004315a4  89742418             mov dword ptr [esp + 0x18], esi
// 004315a8  8bb42494000000       mov esi, dword ptr [esp + 0x94]
// 004315af  8bc6                 mov eax, esi
// 004315b1  85c0                 test eax, eax
// 004315b3  89442414             mov dword ptr [esp + 0x14], eax
// 004315b7  db442414             fild dword ptr [esp + 0x14]
// 004315bb  7d06                 jge 0x4315c3
// 004315bd  dc0530b17800         fadd qword ptr [0x78b130]
// 004315c3  8b8c2498000000       mov ecx, dword ptr [esp + 0x98]
// 004315ca  8bd1                 mov edx, ecx
// 004315cc  85d2                 test edx, edx
// 004315ce  89542414             mov dword ptr [esp + 0x14], edx
// 004315d2  db442414             fild dword ptr [esp + 0x14]
// 004315d6  7d06                 jge 0x4315de
// 004315d8  dc0530b17800         fadd qword ptr [0x78b130]
// 004315de  def9                 fdivp st(1)
// 004315e0  dd442420             fld qword ptr [esp + 0x20]
// 004315e4  d9c0                 fld st(0)
// 004315e6  dee2                 fsubrp st(2)
// 004315e8  d9c9                 fxch st(1)
// 004315ea  d9e1                 fabs 
// 004315ec  def1                 fdivrp st(1)
// 004315ee  dc1d28b17800         fcomp qword ptr [0x78b128]
// 004315f4  dfe0                 fnstsw ax
// 004315f6  f6c441               test ah, 0x41
// 004315f9  7a54                 jp 0x43164f
// 004315fb  8b4368               mov eax, dword ptr [ebx + 0x68]
// 004315fe  3b842490000000       cmp eax, dword ptr [esp + 0x90]
// 00431605  7548                 jne 0x43164f
// 00431607  8b5378               mov edx, dword ptr [ebx + 0x78]
// 0043160a  3b9424a0000000       cmp edx, dword ptr [esp + 0xa0]
// 00431611  753c                 jne 0x43164f
// 00431613  8b5370               mov edx, dword ptr [ebx + 0x70]
// 00431616  0fafce               imul ecx, esi
// 00431619  0faf536c             imul edx, dword ptr [ebx + 0x6c]
// 0043161d  8bbc24e0000000       mov edi, dword ptr [esp + 0xe0]
// 00431624  8bc7                 mov eax, edi
// 00431626  2bc2                 sub eax, edx
// 00431628  99                   cdq 
// 00431629  33c2                 xor eax, edx
// 0043162b  2bc2                 sub eax, edx
// 0043162d  89442414             mov dword ptr [esp + 0x14], eax
// 00431631  8bc7                 mov eax, edi
// 00431633  2bc1                 sub eax, ecx
// 00431635  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00431639  99                   cdq 
// 0043163a  33c2                 xor eax, edx
// 0043163c  2bc2                 sub eax, edx
// 0043163e  3bc1                 cmp eax, ecx
// 00431640  7d0d                 jge 0x43164f
// 00431642  b927000000           mov ecx, 0x27
// 00431647  8d742428             lea esi, [esp + 0x28]
// 0043164b  8bfb                 mov edi, ebx
// 0043164d  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 0043164f  8b742418             mov esi, dword ptr [esp + 0x18]
// 00431653  6a00                 push 0
// 00431655  8d44242c             lea eax, [esp + 0x2c]
// 00431659  50                   push eax
// 0043165a  56                   push esi
// 0043165b  55                   push ebp
// 0043165c  ff15c0ed7700         call dword ptr [0x77edc0]
// 00431662  85c0                 test eax, eax
// 00431664  0f8537ffffff         jne 0x4315a1
// 0043166a  8bc3                 mov eax, ebx
// 0043166c  c7432800001800       mov dword ptr [ebx + 0x28], 0x180000
// 00431673  8b8c24c8000000       mov ecx, dword ptr [esp + 0xc8]
// 0043167a  64890d00000000       mov dword ptr fs:[0], ecx
// 00431681  59                   pop ecx
// 00431682  5f                   pop edi
// 00431683  5e                   pop esi
// 00431684  5d                   pop ebp
// 00431685  5b                   pop ebx
// 00431686  8b8c24b0000000       mov ecx, dword ptr [esp + 0xb0]
// 0043168d  33cc                 xor ecx, esp
// 0043168f  e88af31f00           call 0x630a1e
// 00431694  81c4c0000000         add esp, 0xc0
// 0043169a  c3                   ret 

#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long DWORD;
typedef unsigned short WORD;

// Win32 SDK DEVMODEA (sizeof 0x9c; dmSize +0x24, dmFields +0x28, dmBitsPerPel +0x68,
// dmPelsWidth +0x6c, dmPelsHeight +0x70, dmDisplayFrequency +0x78, as the target addresses them)
struct DEVMODEA {
    unsigned char dmDeviceName[32];
    WORD dmSpecVersion;
    WORD dmDriverVersion;
    WORD dmSize;
    WORD dmDriverExtra;
    DWORD dmFields;
    short dmOrientation;
    short dmPaperSize;
    short dmPaperLength;
    short dmPaperWidth;
    short dmScale;
    short dmCopies;
    short dmDefaultSource;
    short dmPrintQuality;
    short dmColor;
    short dmDuplex;
    short dmYResolution;
    short dmTTOption;
    short dmCollate;
    unsigned char dmFormName[32];
    WORD dmLogPixels;
    DWORD dmBitsPerPel;
    DWORD dmPelsWidth;
    DWORD dmPelsHeight;
    DWORD dmDisplayFlags;
    DWORD dmDisplayFrequency;
    DWORD dmICMMethod;
    DWORD dmICMIntent;
    DWORD dmMediaType;
    DWORD dmDitherType;
    DWORD dmReserved1;
    DWORD dmReserved2;
    DWORD dmPanningWidth;
    DWORD dmPanningHeight;
};

#define ENUM_CURRENT_SETTINGS ((DWORD)-1)
#define DM_PELSWIDTH  0x00080000L
#define DM_PELSHEIGHT 0x00100000L
extern "C" __declspec(dllimport) int __stdcall EnumDisplaySettingsExA(const char*, DWORD, DEVMODEA*, DWORD);
extern "C" __declspec(dllimport) DWORD __stdcall GetLastError();

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

// boost 1.34 sp_counted_base: dispose at vtable+4, destroy at vtable+8, use_count +4, weak_count +8
class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};

struct Log {
    static void __cdecl print(Log*, int, const char*, ...);   // 0x56c0a0 (cdecl, logger pushed first)
};

struct LogPtr {
    Log* px;
    sp_counted_base* pi;
    ~LogPtr() { if (pi != 0) pi->release(); }
    Log* get() const { return px; }
};

LogPtr __cdecl currentLog();                               // 0x56c3b0, returns via hidden pointer

// Returns DEVMODEA (0x9c) through hidden pointer; device in second arg slot, pixel target third.
DEVMODEA __cdecl findBestMode(const char* device, int pixels)
{
    DEVMODEA best;
    DEVMODEA dm;
    memset(&dm, 0, sizeof(dm));
    dm.dmSize = sizeof(dm);
    if (!EnumDisplaySettingsExA(device, ENUM_CURRENT_SETTINGS, &dm, 0))
        Log::print(currentLog().get(), 3, "EnumDisplaySettings failed. GetLastError() == %d", GetLastError());

    double ratio = (double)dm.dmPelsWidth / (double)dm.dmPelsHeight;
    best = dm;

    DWORD i = 0;
    while (EnumDisplaySettingsExA(device, i, &dm, 0)) {
        i++;
        double r = (double)dm.dmPelsWidth / (double)dm.dmPelsHeight;
        if (fabs(ratio - r) / ratio <= 0.1
            && best.dmBitsPerPel == dm.dmBitsPerPel
            && best.dmDisplayFrequency == dm.dmDisplayFrequency
            && abs(pixels - (int)(dm.dmPelsHeight * dm.dmPelsWidth)) < abs(pixels - (int)(best.dmPelsHeight * best.dmPelsWidth)))
            best = dm;
    }
    best.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
    return best;
}
