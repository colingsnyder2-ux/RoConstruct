// from server: 100% by EspClaude
// roc 2007-08 00454dc0  unit: CRobloxReportView::CStatsItemRecord  size: 195 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00454dc0
//
// 00454dc0  6aff                 push -1
// 00454dc2  68a8137400           push 0x7413a8
// 00454dc7  64a100000000         mov eax, dword ptr fs:[0]
// 00454dcd  50                   push eax
// 00454dce  53                   push ebx
// 00454dcf  56                   push esi
// 00454dd0  57                   push edi
// 00454dd1  a188518b00           mov eax, dword ptr [0x8b5188]
// 00454dd6  33c4                 xor eax, esp
// 00454dd8  50                   push eax
// 00454dd9  8d442410             lea eax, [esp + 0x10]
// 00454ddd  64a300000000         mov dword ptr fs:[0], eax
// 00454de3  8d7990               lea edi, [ecx - 0x70]
// 00454de6  8bcf                 mov ecx, edi
// 00454de8  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00454df0  e83bd12000           call 0x661f30
// 00454df5  8bc8                 mov ecx, eax
// 00454df7  e854ee2000           call 0x663c50
// 00454dfc  8bf0                 mov esi, eax
// 00454dfe  83ee01               sub esi, 1
// 00454e01  7831                 js 0x454e34
// 00454e03  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00454e07  56                   push esi
// 00454e08  8bcf                 mov ecx, edi
// 00454e0a  e821d12000           call 0x661f30
// 00454e0f  8bc8                 mov ecx, eax
// 00454e11  e8eac82000           call 0x661700
// 00454e16  399898000000         cmp dword ptr [eax + 0x98], ebx
// 00454e1c  7407                 je 0x454e25
// 00454e1e  83ee01               sub esi, 1
// 00454e21  79e4                 jns 0x454e07
// 00454e23  eb0f                 jmp 0x454e34
// 00454e25  56                   push esi
// 00454e26  8bcf                 mov ecx, edi
// 00454e28  e803d12000           call 0x661f30
// 00454e2d  8bc8                 mov ecx, eax
// 00454e2f  e84cca2000           call 0x661880
// 00454e34  8b742428             mov esi, dword ptr [esp + 0x28]
// 00454e38  85f6                 test esi, esi
// 00454e3a  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00454e42  742a                 je 0x454e6e
// 00454e44  8d4604               lea eax, [esi + 4]
// 00454e47  83c9ff               or ecx, 0xffffffff
// 00454e4a  f00fc108             lock xadd dword ptr [eax], ecx
// 00454e4e  751e                 jne 0x454e6e
// 00454e50  8b16                 mov edx, dword ptr [esi]
// 00454e52  8b4204               mov eax, dword ptr [edx + 4]
// 00454e55  8bce                 mov ecx, esi
// 00454e57  ffd0                 call eax
// 00454e59  8d4e08               lea ecx, [esi + 8]
// 00454e5c  83caff               or edx, 0xffffffff
// 00454e5f  f00fc111             lock xadd dword ptr [ecx], edx
// 00454e63  7509                 jne 0x454e6e
// 00454e65  8b06                 mov eax, dword ptr [esi]
// 00454e67  8b5008               mov edx, dword ptr [eax + 8]
// 00454e6a  8bce                 mov ecx, esi
// 00454e6c  ffd2                 call edx
// 00454e6e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00454e72  64890d00000000       mov dword ptr fs:[0], ecx
// 00454e79  59                   pop ecx
// 00454e7a  5f                   pop edi
// 00454e7b  5e                   pop esi
// 00454e7c  5b                   pop ebx
// 00454e7d  83c40c               add esp, 0xc
// 00454e80  c20c00               ret 0xc

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Instance;

struct SharedInstance {
    Instance* object;
    Control* control;
    ~SharedInstance()
    {
        Control* p = control;
        if (p && _InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
};

struct CXTPReportRecord {
    char pad[0x98];
    Instance* instance;
};

struct CXTPReportRecords {
    int GetCount();
    CXTPReportRecord* GetAt(int index);
    void RemoveAt(int index);
};

struct CXTPReportControl {
    virtual ~CXTPReportControl();
    char pad[0x70 - 4];
    CXTPReportRecords* GetRecords();
};

struct Listener {
    virtual void onChildRemoved(void* sender, SharedInstance child);
};

struct CStatsView : CXTPReportControl, Listener {
    void onChildRemoved(void* sender, SharedInstance child);
};

void CStatsView::onChildRemoved(void* sender, SharedInstance child)
{
    for (int i = GetRecords()->GetCount() - 1; i >= 0; i--) {
        if (GetRecords()->GetAt(i)->instance == child.object) {
            GetRecords()->RemoveAt(i);
            break;
        }
    }
}
