// from server: 74% by EspClaude
// from server: 51% by colin
// roc 2007-08 004593b0  unit: CRobloxWnd  size: 228 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004593b0
//
// 004593b0  55                   push ebp
// 004593b1  8bec                 mov ebp, esp
// 004593b3  6aff                 push -1
// 004593b5  68f2207400           push 0x7420f2
// 004593ba  64a100000000         mov eax, dword ptr fs:[0]
// 004593c0  50                   push eax
// 004593c1  83ec44               sub esp, 0x44
// 004593c4  a188518b00           mov eax, dword ptr [0x8b5188]
// 004593c9  33c5                 xor eax, ebp
// 004593cb  8945ec               mov dword ptr [ebp - 0x14], eax
// 004593ce  53                   push ebx
// 004593cf  56                   push esi
// 004593d0  57                   push edi
// 004593d1  50                   push eax
// 004593d2  8d45f4               lea eax, [ebp - 0xc]
// 004593d5  64a300000000         mov dword ptr fs:[0], eax
// 004593db  8965f0               mov dword ptr [ebp - 0x10], esp
// 004593de  8bf1                 mov esi, ecx
// 004593e0  83be9400000000       cmp dword ptr [esi + 0x94], 0
// 004593e7  8975cc               mov dword ptr [ebp - 0x34], esi
// 004593ea  0f8425010000         je 0x459515
// 004593f0  83be9c00000000       cmp dword ptr [esi + 0x9c], 0
// 004593f7  0f8418010000         je 0x459515
// 004593fd  e8fe410100           call 0x46d600
// 00459402  50                   push eax
// 00459403  8d4dd0               lea ecx, [ebp - 0x30]
// 00459406  ff159ce67700         call dword ptr [0x77e69c]
// 0045940c  6884347900           push 0x793484
// 00459411  8d4db0               lea ecx, [ebp - 0x50]
// 00459414  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0045941b  ff1598e67700         call dword ptr [0x77e698]
// 00459421  8d45b0               lea eax, [ebp - 0x50]
// 00459424  50                   push eax
// 00459425  8d4dd0               lea ecx, [ebp - 0x30]
// 00459428  51                   push ecx
// 00459429  c645fc01             mov byte ptr [ebp - 4], 1
// 0045942d  e87ef10a00           call 0x5085b0
// 00459432  83c408               add esp, 8
// 00459435  8d4db0               lea ecx, [ebp - 0x50]
// 00459438  8ad8                 mov bl, al
// 0045943a  c645fc00             mov byte ptr [ebp - 4], 0
// 0045943e  ff15ace67700         call dword ptr [0x77e6ac]
// 00459444  84db                 test bl, bl
// 00459446  7457                 je 0x45949f
// 00459448  bb02000000           mov ebx, 2
// 0045944d  8bce                 mov ecx, esi
// 0045944f  895e58               mov dword ptr [esi + 0x58], ebx
// 00459452  e829f7ffff           call 0x458b80
// 00459457  395e58               cmp dword ptr [esi + 0x58], ebx
// 0045945a  885dfc               mov byte ptr [ebp - 4], bl
// 0045945d  750f                 jne 0x45946e
// 0045945f  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00459462  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00459465  52                   push edx
// 00459466  50                   push eax
// 00459467  8bce                 mov ecx, esi
// 00459469  e852faffff           call 0x458ec0
// 0045946e  8bbe94000000         mov edi, dword ptr [esi + 0x94]
// 00459474  393dd8d08b00         cmp dword ptr [0x8bd0d8], edi
// 0045947a  0f8481000000         je 0x459501
// 00459480  8b17                 mov edx, dword ptr [edi]
// 00459482  8b8298000000         mov eax, dword ptr [edx + 0x98]
// 00459488  8bcf                 mov ecx, edi
// 0045948a  ffd0                 call eax
// 0045948c  893dd8d08b00         mov dword ptr [0x8bd0d8], edi
// 00459492  eb6d                 jmp 0x459501
//
// The 228-byte extent stops before the catch(...) funclet at 00459494; the
// function body continues to the ret 0xc at 00459530 (read from the exe).

#include <string>

const std::string& videoCardName();                                        // 0046d600
bool stringMatches(const std::string& a, const std::string& b);            // 005085b0 (cdecl)

struct Rect2D { float v[4]; Rect2D() {} };                                             // 16 bytes at [ebp-0x44]
Rect2D makeRect(float x, float y, float w, float h);                       // 00458390 (cdecl, hidden ret)

struct RenderView {
    void resize(int cx, int cy);                                           // 004733f0
    int width();                                                           // 004752a0
    int height();                                                          // 00475280
    void setViewport(const Rect2D& r);                                     // 00475690
};

struct RenderDevice {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37();
    virtual void makeCurrent();                                            // vtable +0x98
};

extern RenderDevice* g_currentDevice;                                      // 008bd0d8

class CRobloxWnd {
public:
    void OnSize(unsigned int type, int cx, int cy);
    void applyMode();                                                      // 00458b80
    void fullResize(int cx, int cy);                                       // 00458ec0
private:
    char pad0[0x58];
    int m_mode;                    // +0x58
    char pad5c[0x7b - 0x5c];
    bool m_sized;                  // +0x7b
    char pad7c[0x94 - 0x7c];
    RenderDevice* m_device;        // +0x94
    char pad98[0x9c - 0x98];
    RenderView* m_view;            // +0x9c
};

void CRobloxWnd::OnSize(unsigned int type, int cx, int cy)
{
    if (m_device == 0 || m_view == 0)
        return;

    std::string card = videoCardName();
    if (stringMatches(card, "MOBILITY RADEON 7500")) {
        m_mode = 2;
        applyMode();
        try {
            if (m_mode == 2)
                fullResize(cx, cy);
            RenderDevice* device = m_device;
            if (g_currentDevice != device) {
                device->makeCurrent();
                g_currentDevice = device;
            }
        } catch (...) {
        }
    } else {
        m_view->resize(cx, cy);
        RenderView* view = m_view;
        Rect2D viewport = makeRect(0.0f, 0.0f, (float)view->height(), (float)view->width());
        m_view->setViewport(viewport);
    }
    m_sized = true;
}
