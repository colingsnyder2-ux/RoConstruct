// from server: 96% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0058ba70  unit: RBX::ChangeHistoryService  size: 193 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0058ba70
//
// 0058ba70  64a100000000         mov eax, dword ptr fs:[0]
// 0058ba76  6aff                 push -1
// 0058ba78  6868617c00           push 0x7c6168
// 0058ba7d  50                   push eax
// 0058ba7e  64892500000000       mov dword ptr fs:[0], esp
// 0058ba85  56                   push esi
// 0058ba86  80b96401000000       cmp byte ptr [ecx + 0x164], 0
// 0058ba8d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0058ba95  754e                 jne 0x58bae5
// 0058ba97  8b542414             mov edx, dword ptr [esp + 0x14]
// 0058ba9b  3bd1                 cmp edx, ecx
// 0058ba9d  7446                 je 0x58bae5
// 0058ba9f  83b93401000000       cmp dword ptr [ecx + 0x134], 0
// 0058baa6  743d                 je 0x58bae5
// 0058baa8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0058baac  50                   push eax
// 0058baad  83ec08               sub esp, 8
// 0058bab0  8bc4                 mov eax, esp
// 0058bab2  8910                 mov dword ptr [eax], edx
// 0058bab4  8b542424             mov edx, dword ptr [esp + 0x24]
// 0058bab8  895004               mov dword ptr [eax + 4], edx
// 0058babb  8b442424             mov eax, dword ptr [esp + 0x24]
// 0058babf  89642428             mov dword ptr [esp + 0x28], esp
// 0058bac3  85c0                 test eax, eax
// 0058bac5  740c                 je 0x58bad3
// 0058bac7  83c004               add eax, 4
// 0058baca  ba01000000           mov edx, 1
// 0058bacf  f00fc110             lock xadd dword ptr [eax], edx
// 0058bad3  8b8934010000         mov ecx, dword ptr [ecx + 0x134]
// 0058bad9  e8e2fbffff           call 0x58b6c0
// 0058bade  8bc8                 mov ecx, eax
// 0058bae0  e86bdbffff           call 0x589650
// 0058bae5  8b742418             mov esi, dword ptr [esp + 0x18]
// 0058bae9  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 0058baf1  85f6                 test esi, esi
// 0058baf3  742a                 je 0x58bb1f
// 0058baf5  8d4604               lea eax, [esi + 4]
// 0058baf8  83c9ff               or ecx, 0xffffffff
// 0058bafb  f00fc108             lock xadd dword ptr [eax], ecx
// 0058baff  751e                 jne 0x58bb1f
// 0058bb01  8b16                 mov edx, dword ptr [esi]
// 0058bb03  8b4204               mov eax, dword ptr [edx + 4]
// 0058bb06  8bce                 mov ecx, esi
// 0058bb08  ffd0                 call eax
// 0058bb0a  8d4e08               lea ecx, [esi + 8]
// 0058bb0d  83caff               or edx, 0xffffffff
// 0058bb10  f00fc111             lock xadd dword ptr [ecx], edx
// 0058bb14  7509                 jne 0x58bb1f
// 0058bb16  8b06                 mov eax, dword ptr [esi]
// 0058bb18  8b5008               mov edx, dword ptr [eax + 8]
// 0058bb1b  8bce                 mov ecx, esi
// 0058bb1d  ffd2                 call edx
// 0058bb1f  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0058bb23  64890d00000000       mov dword ptr fs:[0], ecx
// 0058bb2a  5e                   pop esi
// 0058bb2b  83c40c               add esp, 0xc
// 0058bb2e  c20c00               ret 0xc

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;

    void release();
    void weakRelease();
};

inline void Control::weakRelease()
{
    if (_InterlockedDecrement(&weak) == 0)
        destroy();
}

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        weakRelease();
    }
}

struct ChangeHistoryService;

struct Shared {
    ChangeHistoryService* pointer;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control)
{
    if (control) {
        volatile long* count = &control->strong;
        _InterlockedExchangeAdd(count, 1);
    }
}

inline Shared::~Shared()
{
    if (control)
        control->release();
}

struct Record {
    void update();
};

struct History {
    Record* find(Shared object, int value);
};

struct ChangeHistoryService {
    unsigned char padding0[0x134];
    History* history;
    unsigned char padding1[0x2c];
    bool blocked;

    void notify(Shared object, int value);
};

void ChangeHistoryService::notify(Shared object, int value)
{
    if (!blocked && object.pointer != this && history)
        history->find(object, value)->update();
}
