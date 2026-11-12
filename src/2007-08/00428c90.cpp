// from server: 87% by EspClaude
// from server: 44% by colin
// roc 2007-08 00428c90  unit: COleException  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00428c90
//
// 00428c90  55                   push ebp
// 00428c91  8bec                 mov ebp, esp
// 00428c93  6aff                 push -1
// 00428c95  68d0cb7300           push 0x73cbd0
// 00428c9a  64a100000000         mov eax, dword ptr fs:[0]
// 00428ca0  50                   push eax
// 00428ca1  83ec24               sub esp, 0x24
// 00428ca4  53                   push ebx
// 00428ca5  56                   push esi
// 00428ca6  57                   push edi
// 00428ca7  a188518b00           mov eax, dword ptr [0x8b5188]
// 00428cac  33c5                 xor eax, ebp
// 00428cae  50                   push eax
// 00428caf  8d45f4               lea eax, [ebp - 0xc]
// 00428cb2  64a300000000         mov dword ptr fs:[0], eax
// 00428cb8  8965f0               mov dword ptr [ebp - 0x10], esp
// 00428cbb  8bf1                 mov esi, ecx
// 00428cbd  8b4508               mov eax, dword ptr [ebp + 8]
// 00428cc0  85c0                 test eax, eax
// 00428cc2  7516                 jne 0x428cda
// 00428cc4  8d4de0               lea ecx, [ebp - 0x20]
// 00428cc7  e844cb2f00           call 0x725810
// 00428ccc  68783a8400           push 0x843a78
// 00428cd1  8d45e0               lea eax, [ebp - 0x20]
// 00428cd4  50                   push eax
// 00428cd5  e8c47e2000           call 0x630b9e
// 00428cda  50                   push eax
// 00428cdb  8bce                 mov ecx, esi
// 00428cdd  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00428ce4  e837d42f00           call 0x726120
// 00428ce9  8bc6                 mov eax, esi
// 00428ceb  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00428cee  64890d00000000       mov dword ptr fs:[0], ecx
// 00428cf5  59                   pop ecx
// 00428cf6  5f                   pop edi
// 00428cf7  5e                   pop esi
// 00428cf8  5b                   pop ebx
// 00428cf9  8be5                 mov esp, ebp
// 00428cfb  5d                   pop ebp
// 00428cfc  c20400               ret 4

// boost 1.34 boost::detail::tss::tss(function1<void,void*>* pcleanup) shape:
// throw on null, try init(), catch(...) delete pcleanup and rethrow a new error.
namespace std {
class exception {
public:
    exception();
    exception(const exception&);
    virtual ~exception();
private:
    const char* _m_what;
    int _m_doFree;
};
}

namespace boost {
class thread_resource_error : public std::exception {
public:
    thread_resource_error();
    thread_resource_error(const thread_resource_error&);
    virtual ~thread_resource_error();
private:
    int m_sys_err;
};

namespace detail { namespace function {
typedef void* any_pointer;
typedef any_pointer (*manager_type)(any_pointer, int);
}}

template <class R, class A> class function1 {
public:
    ~function1() { clear(); }
    void clear()
    {
        if (manager)
            functor = manager(functor, 1);
        manager = 0;
        invoker = 0;
    }
    detail::function::manager_type manager;
    detail::function::any_pointer functor;
    void* invoker;
};

namespace detail {
class tss {
public:
    tss(boost::function1<void, void*>* pcleanup);
private:
    void init(boost::function1<void, void*>* pcleanup);
    int m_slot;
};

tss::tss(boost::function1<void, void*>* pcleanup)
{
    if (pcleanup == 0) throw boost::thread_resource_error();
    try
    {
        init(pcleanup);
    }
    catch (...)
    {
        delete pcleanup;
        throw boost::thread_resource_error();
    }
}
}
}
