// from server: 100% by EspClaude
// roc 2007-08 00454e90  unit: CRobloxReportView::CStatsItemRecord  size: 359 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00454e90
//
// 00454e90  6aff                 push -1
// 00454e92  6895177400           push 0x741795
// 00454e97  64a100000000         mov eax, dword ptr fs:[0]
// 00454e9d  50                   push eax
// 00454e9e  83ec20               sub esp, 0x20
// 00454ea1  53                   push ebx
// 00454ea2  55                   push ebp
// 00454ea3  56                   push esi
// 00454ea4  57                   push edi
// 00454ea5  a188518b00           mov eax, dword ptr [0x8b5188]
// 00454eaa  33c4                 xor eax, esp
// 00454eac  50                   push eax
// 00454ead  8d442434             lea eax, [esp + 0x34]
// 00454eb1  64a300000000         mov dword ptr fs:[0], eax
// 00454eb7  8bf1                 mov esi, ecx
// 00454eb9  89742420             mov dword ptr [esp + 0x20], esi
// 00454ebd  8d6e54               lea ebp, [esi + 0x54]
// 00454ec0  8d5e70               lea ebx, [esi + 0x70]
// 00454ec3  c706ec237900         mov dword ptr [esi], 0x7923ec
// 00454ec9  c7450054247900       mov dword ptr [ebp], 0x792454
// 00454ed0  c703d8237900         mov dword ptr [ebx], 0x7923d8
// 00454ed6  8b868c000000         mov eax, dword ptr [esi + 0x8c]
// 00454edc  83ec08               sub esp, 8
// 00454edf  8bcc                 mov ecx, esp
// 00454ee1  8901                 mov dword ptr [ecx], eax
// 00454ee3  8b8690000000         mov eax, dword ptr [esi + 0x90]
// 00454ee9  85c0                 test eax, eax
// 00454eeb  c744244404000000     mov dword ptr [esp + 0x44], 4
// 00454ef3  8964242c             mov dword ptr [esp + 0x2c], esp
// 00454ef7  894104               mov dword ptr [ecx + 4], eax
// 00454efa  740c                 je 0x454f08
// 00454efc  83c004               add eax, 4
// 00454eff  b901000000           mov ecx, 1
// 00454f04  f00fc108             lock xadd dword ptr [eax], ecx
// 00454f08  8d4c2430             lea ecx, [esp + 0x30]
// 00454f0c  e83f86fbff           call 0x40d550
// 00454f11  8b8698000000         mov eax, dword ptr [esi + 0x98]
// 00454f17  85c0                 test eax, eax
// 00454f19  c644243c05           mov byte ptr [esp + 0x3c], 5
// 00454f1e  7409                 je 0x454f29
// 00454f20  55                   push ebp
// 00454f21  8d4814               lea ecx, [eax + 0x14]
// 00454f24  e807d6fdff           call 0x432530
// 00454f29  8b8698000000         mov eax, dword ptr [esi + 0x98]
// 00454f2f  85c0                 test eax, eax
// 00454f31  7409                 je 0x454f3c
// 00454f33  53                   push ebx
// 00454f34  8d482c               lea ecx, [eax + 0x2c]
// 00454f37  e8f4d5fdff           call 0x432530
// 00454f3c  8d4c2428             lea ecx, [esp + 0x28]
// 00454f40  c644243c04           mov byte ptr [esp + 0x3c], 4
// 00454f45  e856461000           call 0x5595a0
// 00454f4a  8bbe9c000000         mov edi, dword ptr [esi + 0x9c]
// 00454f50  85ff                 test edi, edi
// 00454f52  c644243c03           mov byte ptr [esp + 0x3c], 3
// 00454f57  742a                 je 0x454f83
// 00454f59  8d5704               lea edx, [edi + 4]
// 00454f5c  83c8ff               or eax, 0xffffffff
// 00454f5f  f00fc102             lock xadd dword ptr [edx], eax
// 00454f63  751e                 jne 0x454f83
// 00454f65  8b17                 mov edx, dword ptr [edi]
// 00454f67  8b4204               mov eax, dword ptr [edx + 4]
// 00454f6a  8bcf                 mov ecx, edi
// 00454f6c  ffd0                 call eax
// 00454f6e  8d4f08               lea ecx, [edi + 8]
// 00454f71  83caff               or edx, 0xffffffff
// 00454f74  f00fc111             lock xadd dword ptr [ecx], edx
// 00454f78  7509                 jne 0x454f83
// 00454f7a  8b07                 mov eax, dword ptr [edi]
// 00454f7c  8b5008               mov edx, dword ptr [eax + 8]
// 00454f7f  8bcf                 mov ecx, edi
// 00454f81  ffd2                 call edx
// 00454f83  8bcb                 mov ecx, ebx
// 00454f85  c644243c02           mov byte ptr [esp + 0x3c], 2
// 00454f8a  e8f1f2ffff           call 0x454280
// 00454f8f  8bcd                 mov ecx, ebp
// 00454f91  c644243c01           mov byte ptr [esp + 0x3c], 1
// 00454f96  e855f2ffff           call 0x4541f0
// 00454f9b  8bbe90000000         mov edi, dword ptr [esi + 0x90]
// 00454fa1  85ff                 test edi, edi
// 00454fa3  c644243c00           mov byte ptr [esp + 0x3c], 0
// 00454fa8  742a                 je 0x454fd4
// 00454faa  8d4704               lea eax, [edi + 4]
// 00454fad  83c9ff               or ecx, 0xffffffff
// 00454fb0  f00fc108             lock xadd dword ptr [eax], ecx
// 00454fb4  751e                 jne 0x454fd4
// 00454fb6  8b17                 mov edx, dword ptr [edi]
// 00454fb8  8b4204               mov eax, dword ptr [edx + 4]
// 00454fbb  8bcf                 mov ecx, edi
// 00454fbd  ffd0                 call eax
// 00454fbf  8d4f08               lea ecx, [edi + 8]
// 00454fc2  83caff               or edx, 0xffffffff
// 00454fc5  f00fc111             lock xadd dword ptr [ecx], edx
// 00454fc9  7509                 jne 0x454fd4
// 00454fcb  8b07                 mov eax, dword ptr [edi]
// 00454fcd  8b5008               mov edx, dword ptr [eax + 8]
// 00454fd0  8bcf                 mov ecx, edi
// 00454fd2  ffd2                 call edx
// 00454fd4  8bce                 mov ecx, esi
// 00454fd6  c744243cffffffff     mov dword ptr [esp + 0x3c], 0xffffffff
// 00454fde  e8cdce2000           call 0x661eb0
// 00454fe3  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00454fe7  64890d00000000       mov dword ptr fs:[0], ecx
// 00454fee  59                   pop ecx
// 00454fef  5f                   pop edi
// 00454ff0  5e                   pop esi
// 00454ff1  5d                   pop ebp
// 00454ff2  5b                   pop ebx
// 00454ff3  83c42c               add esp, 0x2c
// 00454ff6  c3                   ret 

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

template<class T>
struct shared_ptr {
    T* px;
    Control* pn;
    shared_ptr(const shared_ptr& other) : px(other.px), pn(other.pn)
    {
        if (pn)
            _InterlockedIncrement(&pn->strong);
    }
    ~shared_ptr()
    {
        Control* p = pn;
        if (p && _InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
    T* operator->() const { return px; }
    T* get() const { return px; }
};

struct DataModel;

struct Lock {
    void* first;
    void* second;
    void* third;
    Lock(shared_ptr<DataModel> dataModel);
    ~Lock();
};

struct ListenerList {
    void remove(const void* listener);
};

struct Stats {
    char pad[0x14];
    ListenerList itemListeners;
    char pad2[0x2c - 0x15];
    ListenerList valueListeners;
};

struct CXTPReportRecord {
    virtual ~CXTPReportRecord();
    char pad[0x54 - 4];
};

struct DataModelHolder {
    shared_ptr<DataModel> dataModel;
};

struct ItemListener {
    virtual void onItem();
    char pad[0x1c - 4];
    ~ItemListener();
};

struct ValueListener {
    virtual void onValue();
    char pad[0x1c - 4];
    ~ValueListener();
};

class CStatsItemRecord : public CXTPReportRecord, public DataModelHolder, public ItemListener, public ValueListener {
public:
    int flags;
    shared_ptr<Stats> stats;
    ~CStatsItemRecord();
};

CStatsItemRecord::~CStatsItemRecord()
{
    Lock lock(dataModel);
    if (stats.get())
        stats->itemListeners.remove(static_cast<ItemListener*>(this));
    if (stats.get())
        stats->valueListeners.remove(static_cast<ValueListener*>(this));
}
