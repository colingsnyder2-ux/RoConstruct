// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 00538160  unit: rbx::signals::Z::$$A6AX_NH::?$signal::Vslot::?$callable  size: 165 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00538160
//
// 00538160  64a100000000         mov eax, dword ptr fs:[0]
// 00538166  6aff                 push -1
// 00538168  6898d5aa00           push 0xaad598
// 0053816d  50                   push eax
// 0053816e  64892500000000       mov dword ptr fs:[0], esp
// 00538175  83ec08               sub esp, 8
// 00538178  56                   push esi
// 00538179  8bf1                 mov esi, ecx
// 0053817b  837e1000             cmp dword ptr [esi + 0x10], 0
// 0053817f  7474                 je 0x5381f5
// 00538181  e88a6affff           call 0x52ec10
// 00538186  8d4c2404             lea ecx, [esp + 4]
// 0053818a  89442404             mov dword ptr [esp + 4], eax
// 0053818e  c644240800           mov byte ptr [esp + 8], 0
// 00538193  e8f8b6edff           call 0x413890
// 00538198  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0053819b  c744241400000000     mov dword ptr [esp + 0x14], 0
// 005381a3  85c9                 test ecx, ecx
// 005381a5  740d                 je 0x5381b4
// 005381a7  56                   push esi
// 005381a8  c7461000000000       mov dword ptr [esi + 0x10], 0
// 005381af  e83c843800           call 0x8c05f0
// 005381b4  807c240800           cmp byte ptr [esp + 8], 0
// 005381b9  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 005381c1  7432                 je 0x5381f5
// 005381c3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005381c7  b800000080           mov eax, 0x80000000
// 005381cc  8bd1                 mov edx, ecx
// 005381ce  f00fc102             lock xadd dword ptr [edx], eax
// 005381d2  a900000040           test eax, 0x40000000
// 005381d7  751c                 jne 0x5381f5
// 005381d9  3d00000080           cmp eax, 0x80000000
// 005381de  7e15                 jle 0x5381f5
// 005381e0  8bc1                 mov eax, ecx
// 005381e2  f00fba281e           lock bts dword ptr [eax], 0x1e
// 005381e7  720c                 jb 0x5381f5
// 005381e9  e8d237edff           call 0x40b9c0
// 005381ee  50                   push eax
// 005381ef  ff150c23b200         call dword ptr [0xb2230c]
// 005381f5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005381f9  5e                   pop esi
// 005381fa  64890d00000000       mov dword ptr fs:[0], ecx
// 00538201  83c414               add esp, 0x14
// 00538204  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" unsigned char __cdecl _interlockedbittestandset(volatile long*, long);
#pragma intrinsic(_interlockedbittestandset)
extern "C" int (__stdcall* pSetEvent)(void*);

struct timed_mutex {
    volatile long active_count;
    void* event;
    void* get_event();
    void unlock() {
        long const offset = (long)0x80000000;
        long const old_count = _InterlockedExchangeAdd(&active_count, offset);
        if (!(old_count & 0x40000000) && old_count > offset) {
            if (!_interlockedbittestandset(&active_count, 30)) {
                pSetEvent(get_event());
            }
        }
    }
};

struct scoped_lock {
    timed_mutex* m;
    bool is_locked;
    explicit scoped_lock(timed_mutex& m_) : m(&m_), is_locked(false) { lock(); }
    ~scoped_lock() {
        if (is_locked)
            m->unlock();
    }
    void lock();
};

timed_mutex& get_mutex();

struct callable;

struct slot_owner {
    void remove(callable* c);
};

struct callable {
    char pad[0x10];
    slot_owner* owner;
    void disconnect();
};

void callable::disconnect() {
    if (owner != 0) {
        scoped_lock lock(get_mutex());
        slot_owner* p = owner;
        if (p != 0) {
            owner = 0;
            p->remove(this);
        }
    }
}
