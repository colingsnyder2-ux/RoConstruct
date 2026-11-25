// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 006b9020  unit: RBX::MD5HasherImpl  size: 162 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006b9020
//
// 006b9020  83ec08               sub esp, 8
// 006b9023  53                   push ebx
// 006b9024  56                   push esi
// 006b9025  6800d74400           push 0x44d700
// 006b902a  68c889e100           push 0xe189c8
// 006b902f  8bf1                 mov esi, ecx
// 006b9031  e86a85d4ff           call 0x4015a0
// 006b9036  b801000000           mov eax, 1
// 006b903b  83c408               add esp, 8
// 006b903e  8405b889e100         test byte ptr [0xe189b8], al
// 006b9044  751f                 jne 0x6b9065
// 006b9046  0905b889e100         or dword ptr [0xe189b8], eax
// 006b904c  33c0                 xor eax, eax
// 006b904e  68801bb100           push 0xb11b80
// 006b9053  a3b089e100           mov dword ptr [0xe189b0], eax
// 006b9058  a3b489e100           mov dword ptr [0xe189b4], eax
// 006b905d  e893a12c00           call 0x9831f5
// 006b9062  83c404               add esp, 4
// 006b9065  8d4c2408             lea ecx, [esp + 8]
// 006b9069  c7442408b089e100     mov dword ptr [esp + 8], 0xe189b0
// 006b9071  c644240c00           mov byte ptr [esp + 0xc], 0
// 006b9076  e815a8d5ff           call 0x413890
// 006b907b  833e00               cmp dword ptr [esi], 0
// 006b907e  0f94c3               sete bl
// 006b9081  807c240c00           cmp byte ptr [esp + 0xc], 0
// 006b9086  7432                 je 0x6b90ba
// 006b9088  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006b908c  b800000080           mov eax, 0x80000000
// 006b9091  8bd1                 mov edx, ecx
// 006b9093  f00fc102             lock xadd dword ptr [edx], eax
// 006b9097  a900000040           test eax, 0x40000000
// 006b909c  751c                 jne 0x6b90ba
// 006b909e  3d00000080           cmp eax, 0x80000000
// 006b90a3  7e15                 jle 0x6b90ba
// 006b90a5  8bc1                 mov eax, ecx
// 006b90a7  f00fba281e           lock bts dword ptr [eax], 0x1e
// 006b90ac  720c                 jb 0x6b90ba
// 006b90ae  e80d29d5ff           call 0x40b9c0
// 006b90b3  50                   push eax
// 006b90b4  ff150c23b200         call dword ptr [0xb2230c]
// 006b90ba  5e                   pop esi
// 006b90bb  8ac3                 mov al, bl
// 006b90bd  5b                   pop ebx
// 006b90be  83c408               add esp, 8
// 006b90c1  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" unsigned char __cdecl _interlockedbittestandset(volatile long*, long);
#pragma intrinsic(_interlockedbittestandset)

extern "C" int (__stdcall *_imp__SetEvent)(void*);

struct OnceFlag { long status; };
extern OnceFlag onceFlag;
void onceInit();
void callOnce(OnceFlag& flag, void (*fn)());

struct Mutex {
    long active_count;
    void* event;
    Mutex() { active_count = 0; event = 0; }
    ~Mutex();
    void* get_event();
    void unlock() {
        long old_count = _InterlockedExchangeAdd(&active_count, (long)0x80000000);
        if (!(old_count & 0x40000000) && old_count > (long)0x80000000) {
            if (!_interlockedbittestandset(&active_count, 30)) {
                _imp__SetEvent(get_event());
            }
        }
    }
};

struct ScopedLock {
    Mutex* m;
    bool is_locked;
    ScopedLock(Mutex& m_) : m(&m_), is_locked(false) { lock(); }
    ~ScopedLock() {
        if (is_locked)
            m->unlock();
    }
    void lock();
};

struct S {
    void* value;
    bool isNull();
};

bool S::isNull() {
    callOnce(onceFlag, onceInit);
    static Mutex mutex;
    ScopedLock lock(mutex);
    return value == 0;
}
