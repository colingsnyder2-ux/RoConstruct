// from server: 100% by EspClaude
// from server: 76% by EspClaude
// roc 2007-08 00431890  unit: VCMDIFrameWnd::?$CXTPFrameWndBase  size: 165 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00431890
//
// 00431890  6aff                 push -1
// 00431892  6868db7300           push 0x73db68
// 00431897  64a100000000         mov eax, dword ptr fs:[0]
// 0043189d  50                   push eax
// 0043189e  51                   push ecx
// 0043189f  56                   push esi
// 004318a0  57                   push edi
// 004318a1  a188518b00           mov eax, dword ptr [0x8b5188]
// 004318a6  33c4                 xor eax, esp
// 004318a8  50                   push eax
// 004318a9  8d442410             lea eax, [esp + 0x10]
// 004318ad  64a300000000         mov dword ptr fs:[0], eax
// 004318b3  8bf1                 mov esi, ecx
// 004318b5  8974240c             mov dword ptr [esp + 0xc], esi
// 004318b9  e8a20c0100           call 0x442560
// 004318be  c786d001000038837800 mov dword ptr [esi + 0x1d0], 0x788338
// 004318c8  33c0                 xor eax, eax
// 004318ca  c7066caf7800         mov dword ptr [esi], 0x78af6c
// 004318d0  c7867c01000060af7800 mov dword ptr [esi + 0x17c], 0x78af60
// 004318da  c786d001000054af7800 mov dword ptr [esi + 0x1d0], 0x78af54
// 004318e4  8986d4010000         mov dword ptr [esi + 0x1d4], eax
// 004318ea  8986d8010000         mov dword ptr [esi + 0x1d8], eax
// 004318f0  8dbedc010000         lea edi, [esi + 0x1dc]
// 004318f6  8bcf                 mov ecx, edi
// 004318f8  89442418             mov dword ptr [esp + 0x18], eax
// 004318fc  e8bf5afdff           call 0x4073c0
// 00431901  c7061cb37800         mov dword ptr [esi], 0x78b31c
// 00431907  c7867c01000010b37800 mov dword ptr [esi + 0x17c], 0x78b310
// 00431911  c786d001000004b37800 mov dword ptr [esi + 0x1d0], 0x78b304
// 0043191b  c707fcb27800         mov dword ptr [edi], 0x78b2fc
// 00431921  8bc6                 mov eax, esi
// 00431923  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00431927  64890d00000000       mov dword ptr fs:[0], ecx
// 0043192e  59                   pop ecx
// 0043192f  5f                   pop edi
// 00431930  5e                   pop esi
// 00431931  83c410               add esp, 0x10
// 00431934  c3                   ret 

// from server: 100% by EspClaude
// roc 2008-06 00431040  unit: VCMDIFrameWnd::?$CXTPFrameWndBase  size: 143 bytes

struct FrameA { FrameA(); virtual ~FrameA(); char pad[0x17c - 4]; };
struct __declspec(novtable) FrameB { virtual void b(); char pad[0x1d0 - 0x17c - 4]; };
struct FrameC { virtual void c(); virtual ~FrameC() {} };

class VCMDIFrameWnd : public FrameA, public FrameB, public FrameC {
public:
    virtual ~VCMDIFrameWnd();
};

class CXTPCommandBars;

template<class TBase>
class CXTPCommandBarsSiteBase : public TBase {
public:
    CXTPCommandBarsSiteBase() {}
protected:
    virtual int PreTranslateMessage(void* pMsg);
};

template<class TBase>
class CXTPFrameWndBase : public CXTPCommandBarsSiteBase<TBase> {
public:
    CXTPFrameWndBase() : m_pCommandBars(0), m_nState(0) {}
    CXTPCommandBars* m_pCommandBars;
    int m_nState;
};

class Listener {
public:
    Listener();
    virtual ~Listener();
    char pad[0x20];
};

class CMainFrame : public CXTPFrameWndBase<VCMDIFrameWnd>, public Listener {
public:
    CMainFrame();
    virtual ~CMainFrame();
};

CMainFrame::CMainFrame()
{
}
