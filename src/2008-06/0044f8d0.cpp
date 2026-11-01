// from server: 100% by EspClaude
// from server: 58% by colin
// roc 2008-06 0044f8d0  unit: CRobloxDoc  size: 213 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044f8d0
//
// 0044f8d0  6aff                 push -1
// 0044f8d2  6868917d00           push 0x7d9168
// 0044f8d7  64a100000000         mov eax, dword ptr fs:[0]
// 0044f8dd  50                   push eax
// 0044f8de  64892500000000       mov dword ptr fs:[0], esp
// 0044f8e5  83ec08               sub esp, 8
// 0044f8e8  53                   push ebx
// 0044f8e9  56                   push esi
// 0044f8ea  57                   push edi
// 0044f8eb  8bf9                 mov edi, ecx
// 0044f8ed  8b8f94000000         mov ecx, dword ptr [edi + 0x94]
// 0044f8f3  8d44240c             lea eax, [esp + 0xc]
// 0044f8f7  50                   push eax
// 0044f8f8  e843b00100           call 0x46a940
// 0044f8fd  8b30                 mov esi, dword ptr [eax]
// 0044f8ff  6a01                 push 1
// 0044f901  56                   push esi
// 0044f902  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0044f90a  e851650400           call 0x495e60
// 0044f90f  83c408               add esp, 8
// 0044f912  84c0                 test al, al
// 0044f914  740f                 je 0x44f925
// 0044f916  6a01                 push 1
// 0044f918  56                   push esi
// 0044f919  e852650400           call 0x495e70
// 0044f91e  83c408               add esp, 8
// 0044f921  84c0                 test al, al
// 0044f923  7402                 je 0x44f927
// 0044f925  b001                 mov al, 1
// 0044f927  8b742410             mov esi, dword ptr [esp + 0x10]
// 0044f92b  84c0                 test al, al
// 0044f92d  0f94c3               sete bl
// 0044f930  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0044f938  85f6                 test esi, esi
// 0044f93a  742a                 je 0x44f966
// 0044f93c  8d4e04               lea ecx, [esi + 4]
// 0044f93f  83caff               or edx, 0xffffffff
// 0044f942  f00fc111             lock xadd dword ptr [ecx], edx
// 0044f946  751e                 jne 0x44f966
// 0044f948  8b06                 mov eax, dword ptr [esi]
// 0044f94a  8b5004               mov edx, dword ptr [eax + 4]
// 0044f94d  8bce                 mov ecx, esi
// 0044f94f  ffd2                 call edx
// 0044f951  8d4608               lea eax, [esi + 8]
// 0044f954  83c9ff               or ecx, 0xffffffff
// 0044f957  f00fc108             lock xadd dword ptr [eax], ecx
// 0044f95b  7509                 jne 0x44f966
// 0044f95d  8b16                 mov edx, dword ptr [esi]
// 0044f95f  8b4208               mov eax, dword ptr [edx + 8]
// 0044f962  8bce                 mov ecx, esi
// 0044f964  ffd0                 call eax
// 0044f966  84db                 test bl, bl
// 0044f968  7416                 je 0x44f980
// 0044f96a  5f                   pop edi
// 0044f96b  5e                   pop esi
// 0044f96c  33c0                 xor eax, eax
// 0044f96e  5b                   pop ebx
// 0044f96f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0044f973  64890d00000000       mov dword ptr fs:[0], ecx
// 0044f97a  83c414               add esp, 0x14
// 0044f97d  c20800               ret 8
// 0044f980  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0044f984  8b542424             mov edx, dword ptr [esp + 0x24]
// 0044f988  51                   push ecx
// 0044f989  52                   push edx
// 0044f98a  8bcf                 mov ecx, edi
// 0044f98c  e867102500           call 0x6a09f8
// 0044f991  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044f995  5f                   pop edi
// 0044f996  5e                   pop esi
// 0044f997  5b                   pop ebx
// 0044f998  64890d00000000       mov dword ptr fs:[0], ecx
// 0044f99f  83c414               add esp, 0x14
// 0044f9a2  c20800               ret 8

// from server: 54% by colin
// roc 2008-06 0044f8d0  unit: CRobloxDoc  size: 213 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044f8d0
//
// 0044f8d0  6aff                 push -1
// 0044f8d2  6868917d00           push 0x7d9168
// 0044f8d7  64a100000000         mov eax, dword ptr fs:[0]
// 0044f8dd  50                   push eax
// 0044f8de  64892500000000       mov dword ptr fs:[0], esp
// 0044f8e5  83ec08               sub esp, 8
// 0044f8e8  53                   push ebx
// 0044f8e9  56                   push esi
// 0044f8ea  57                   push edi
// 0044f8eb  8bf9                 mov edi, ecx
// 0044f8ed  8b8f94000000         mov ecx, dword ptr [edi + 0x94]
// 0044f8f3  8d44240c             lea eax, [esp + 0xc]
// 0044f8f7  50                   push eax
// 0044f8f8  e843b00100           call 0x46a940
// 0044f8fd  8b30                 mov esi, dword ptr [eax]
// 0044f8ff  6a01                 push 1
// 0044f901  56                   push esi
// 0044f902  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0044f90a  e851650400           call 0x495e60
// 0044f90f  83c408               add esp, 8
// 0044f912  84c0                 test al, al
// 0044f914  740f                 je 0x44f925
// 0044f916  6a01                 push 1
// 0044f918  56                   push esi
// 0044f919  e852650400           call 0x495e70
// 0044f91e  83c408               add esp, 8
// 0044f921  84c0                 test al, al
// 0044f923  7402                 je 0x44f927
// 0044f925  b001                 mov al, 1
// 0044f927  8b742410             mov esi, dword ptr [esp + 0x10]
// 0044f92b  84c0                 test al, al
// 0044f92d  0f94c3               sete bl
// 0044f930  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0044f938  85f6                 test esi, esi
// 0044f93a  742a                 je 0x44f966
// 0044f93c  8d4e04               lea ecx, [esi + 4]
// 0044f93f  83caff               or edx, 0xffffffff
// 0044f942  f00fc111             lock xadd dword ptr [ecx], edx
// 0044f946  751e                 jne 0x44f966
// 0044f948  8b06                 mov eax, dword ptr [esi]
// 0044f94a  8b5004               mov edx, dword ptr [eax + 4]
// 0044f94d  8bce                 mov ecx, esi
// 0044f94f  ffd2                 call edx
// 0044f951  8d4608               lea eax, [esi + 8]
// 0044f954  83c9ff               or ecx, 0xffffffff
// 0044f957  f00fc108             lock xadd dword ptr [eax], ecx
// 0044f95b  7509                 jne 0x44f966
// 0044f95d  8b16                 mov edx, dword ptr [esi]
// 0044f95f  8b4208               mov eax, dword ptr [edx + 8]
// 0044f962  8bce                 mov ecx, esi
// 0044f964  ffd0                 call eax
// 0044f966  84db                 test bl, bl
// 0044f968  7416                 je 0x44f980
// 0044f96a  5f                   pop edi
// 0044f96b  5e                   pop esi
// 0044f96c  33c0                 xor eax, eax
// 0044f96e  5b                   pop ebx
// 0044f96f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0044f973  64890d00000000       mov dword ptr fs:[0], ecx
// 0044f97a  83c414               add esp, 0x14
// 0044f97d  c20800               ret 8
// 0044f980  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0044f984  8b542424             mov edx, dword ptr [esp + 0x24]
// 0044f988  51                   push ecx
// 0044f989  52                   push edx
// 0044f98a  8bcf                 mov ecx, edi
// 0044f98c  e867102500           call 0x6a09f8
// 0044f991  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044f995  5f                   pop edi
// 0044f996  5e                   pop esi
// 0044f997  5b                   pop ebx
// 0044f998  64890d00000000       mov dword ptr fs:[0], ecx
// 0044f99f  83c414               add esp, 0x14
// 0044f9a2  c20800               ret 8

#include <intrin.h>

struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};

struct shared_count {
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> struct shared_ptr {
    T* px;
    shared_count pn;
    T* get() const { return px; }
};

struct DataModel;
bool isLocked(DataModel* dm, bool b);
bool isUnlocked(DataModel* dm, bool b);

struct Workspace {
    shared_ptr<DataModel> getDataModel();
};

struct CDocument {
    int CanCloseFrame(void* frame, int x);
};

inline bool canEdit(DataModel* dm)
{
    if (isLocked(dm, true) && !isUnlocked(dm, true))
        return false;
    return true;
}

struct CRobloxDoc : CDocument {
    char pad[0x94];
    Workspace* workspace;
    int CanCloseFrame(void* frame, int x);
};

int CRobloxDoc::CanCloseFrame(void* frame, int x)
{
    if (!canEdit(workspace->getDataModel().get()))
        return 0;
    return CDocument::CanCloseFrame(frame, x);
}
