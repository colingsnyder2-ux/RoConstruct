// from server: 100% by EspClaude
// from server: 74% by tajop
// roc 2007-08 00725910  unit: boost::thread_resource_error  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00725910
//
// 00725910  83ec30               sub esp, 0x30
// 00725913  56                   push esi
// 00725914  8b742438             mov esi, dword ptr [esp + 0x38]
// 00725918  57                   push edi
// 00725919  8bce                 mov ecx, esi
// 0072591b  33ff                 xor edi, edi
// 0072591d  e8ee8ce3ff           call 0x55e610
// 00725922  85c0                 test eax, eax
// 00725924  0f86bc000000         jbe 0x7259e6
// 0072592a  53                   push ebx
// 0072592b  55                   push ebp
// 0072592c  8d642400             lea esp, [esp]
// 00725930  8b0df0988c00         mov ecx, dword ptr [0x8c98f0]
// 00725936  894c2410             mov dword ptr [esp + 0x10], ecx
// 0072593a  e811feffff           call 0x725750
// 0072593f  8b4e04               mov ecx, dword ptr [esi + 4]
// 00725942  85c9                 test ecx, ecx
// 00725944  740c                 je 0x725952
// 00725946  8b4608               mov eax, dword ptr [esi + 8]
// 00725949  2bc1                 sub eax, ecx
// 0072594b  c1f802               sar eax, 2
// 0072594e  3bf8                 cmp edi, eax
// 00725950  7206                 jb 0x725958
// 00725952  ff15d8e67700         call dword ptr [0x77e6d8]
// 00725958  a1f0988c00           mov eax, dword ptr [0x8c98f0]
// 0072595d  8b5e04               mov ebx, dword ptr [esi + 4]
// 00725960  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00725963  8d500c               lea edx, [eax + 0xc]
// 00725966  8d2cbd00000000       lea ebp, [edi*4]
// 0072596d  03dd                 add ebx, ebp
// 0072596f  85c9                 test ecx, ecx
// 00725971  89542444             mov dword ptr [esp + 0x44], edx
// 00725975  740c                 je 0x725983
// 00725977  8b4010               mov eax, dword ptr [eax + 0x10]
// 0072597a  2bc1                 sub eax, ecx
// 0072597c  c1f802               sar eax, 2
// 0072597f  3bf8                 cmp edi, eax
// 00725981  720a                 jb 0x72598d
// 00725983  ff15d8e67700         call dword ptr [0x77e6d8]
// 00725989  8b542444             mov edx, dword ptr [esp + 0x44]
// 0072598d  8b02                 mov eax, dword ptr [edx]
// 0072598f  8b0428               mov eax, dword ptr [eax + ebp]
// 00725992  833800               cmp dword ptr [eax], 0
// 00725995  7455                 je 0x7259ec
// 00725997  8b0b                 mov ecx, dword ptr [ebx]
// 00725999  8b5004               mov edx, dword ptr [eax + 4]
// 0072599c  8b4008               mov eax, dword ptr [eax + 8]
// 0072599f  51                   push ecx
// 007259a0  52                   push edx
// 007259a1  ffd0                 call eax
// 007259a3  8b4e04               mov ecx, dword ptr [esi + 4]
// 007259a6  83c408               add esp, 8
// 007259a9  85c9                 test ecx, ecx
// 007259ab  740c                 je 0x7259b9
// 007259ad  8b4608               mov eax, dword ptr [esi + 8]
// 007259b0  2bc1                 sub eax, ecx
// 007259b2  c1f802               sar eax, 2
// 007259b5  3bf8                 cmp edi, eax
// 007259b7  7206                 jb 0x7259bf
// 007259b9  ff15d8e67700         call dword ptr [0x77e6d8]
// 007259bf  8b4e04               mov ecx, dword ptr [esi + 4]
// 007259c2  c7042900000000       mov dword ptr [ecx + ebp], 0
// 007259c9  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007259cd  e89efdffff           call 0x725770
// 007259d2  8bce                 mov ecx, esi
// 007259d4  83c701               add edi, 1
// 007259d7  e8348ce3ff           call 0x55e610
// 007259dc  3bf8                 cmp edi, eax
// 007259de  0f824cffffff         jb 0x725930
// 007259e4  5d                   pop ebp
// 007259e5  5b                   pop ebx
// 007259e6  5f                   pop edi
// 007259e7  5e                   pop esi
// 007259e8  83c430               add esp, 0x30
// 007259eb  c3                   ret 
// 007259ec  8d4c2418             lea ecx, [esp + 0x18]
// 007259f0  e80be2ceff           call 0x413c00
// 007259f5  50                   push eax
// 007259f6  e875e7ceff           call 0x414170

extern "C" void (__cdecl *_invalid_parameter_noinfo)();

struct bad_function_call {
    char data[0x28];
    bad_function_call();
};

__declspec(noreturn) void throw_exception(const bad_function_call& e);

struct Mutex {
    void* handle;
    bool flag;
    void lock();
    void unlock();
};

struct Function {
    void* manager;
    void* functor;
    void (*invoker)(void* functor, void* a0);
    void operator()(void* a0) const
    {
        if (!manager)
            throw_exception(bad_function_call());
        invoker(functor, a0);
    }
};

struct FuncVec {
    int alloc;
    Function** first;
    Function** last;
    Function** end;
    unsigned vsize() const { return first == 0 ? 0 : (unsigned)(last - first); }
    Function*& operator[](unsigned i)
    {
        if (!(i < vsize()))
            _invalid_parameter_noinfo();
        return *(first + i);
    }
};

struct ArgVec {
    int alloc;
    void** first;
    void** last;
    void** end;
    unsigned size() const;
    unsigned vsize() const { return first == 0 ? 0 : (unsigned)(last - first); }
    void*& operator[](unsigned i)
    {
        if (!(i < vsize()))
            _invalid_parameter_noinfo();
        return *(first + i);
    }
};

struct scoped_lock {
    Mutex& m_mutex;
    bool m_locked;
    explicit scoped_lock(Mutex& m) : m_mutex(m), m_locked(false)
    {
        m_mutex.lock();
        m_locked = true;
    }
    ~scoped_lock()
    {
        if (m_locked)
            m_mutex.unlock();
    }
};

struct Registry {
    Mutex mutex;
    FuncVec funcs;
};

extern Registry* g_registry;

extern "C" void invokeAll(void* p)
{
    ArgVec* v = static_cast<ArgVec*>(p);
    for (unsigned i = 0; i < v->size(); ++i) {
        scoped_lock lock(g_registry->mutex);
        (*g_registry->funcs[i])((*v)[i]);
        (*v)[i] = 0;
    }
}
