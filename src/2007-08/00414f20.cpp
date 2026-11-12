// from server: 100% by EspClaude
// from server: 45% by colin
// roc 2007-08 00414f20  unit: DHTMLWindow  size: 165 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00414f20
//
// 00414f20  6aff                 push -1
// 00414f22  6871a87300           push 0x73a871
// 00414f27  64a100000000         mov eax, dword ptr fs:[0]
// 00414f2d  50                   push eax
// 00414f2e  83ec08               sub esp, 8
// 00414f31  56                   push esi
// 00414f32  57                   push edi
// 00414f33  a188518b00           mov eax, dword ptr [0x8b5188]
// 00414f38  33c4                 xor eax, esp
// 00414f3a  50                   push eax
// 00414f3b  8d442414             lea eax, [esp + 0x14]
// 00414f3f  64a300000000         mov dword ptr fs:[0], eax
// 00414f45  8bf1                 mov esi, ecx
// 00414f47  8dbee8000000         lea edi, [esi + 0xe8]
// 00414f4d  8bcf                 mov ecx, edi
// 00414f4f  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00414f57  897c240c             mov dword ptr [esp + 0xc], edi
// 00414f5b  e8f0073100           call 0x725750
// 00414f60  b001                 mov al, 1
// 00414f62  88442410             mov byte ptr [esp + 0x10], al
// 00414f66  83bef000000000       cmp dword ptr [esi + 0xf0], 0
// 00414f6d  8844241c             mov byte ptr [esp + 0x1c], al
// 00414f71  7420                 je 0x414f93
// 00414f73  6a00                 push 0
// 00414f75  6a00                 push 0
// 00414f77  6a00                 push 0
// 00414f79  6a00                 push 0
// 00414f7b  6a00                 push 0
// 00414f7d  8d4c2438             lea ecx, [esp + 0x38]
// 00414f81  ff15a8e67700         call dword ptr [0x77e6a8]
// 00414f87  8b8ef0000000         mov ecx, dword ptr [esi + 0xf0]
// 00414f8d  50                   push eax
// 00414f8e  e8c3af2100           call 0x62ff56
// 00414f93  8bcf                 mov ecx, edi
// 00414f95  c644241c00           mov byte ptr [esp + 0x1c], 0
// 00414f9a  e8d1073100           call 0x725770
// 00414f9f  8d4c2424             lea ecx, [esp + 0x24]
// 00414fa3  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00414fab  ff15ace67700         call dword ptr [0x77e6ac]
// 00414fb1  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00414fb5  64890d00000000       mov dword ptr fs:[0], ecx
// 00414fbc  59                   pop ecx
// 00414fbd  5f                   pop edi
// 00414fbe  5e                   pop esi

// MSVCP80 std::string (0x1c bytes); c_str and dtor called through the IAT (0x77e6a8, 0x77e6ac)
namespace std {
    template<class C> struct char_traits {};
    template<class T> class allocator {};
    template<class C, class T, class A> class basic_string {
        unsigned int storage[7];
    public:
        __declspec(dllimport) ~basic_string();
        __declspec(dllimport) const C* c_str() const;
    };
    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

// boost 1.34 win32 mutex shape: 8 bytes at this+0xe8 (next member at +0xf0)
class mutex {
public:
    class scoped_lock;
    void do_lock();     // thiscall, call 0x725750
    void do_unlock();   // thiscall, call 0x725770
private:
    void* m_mutex;
    bool m_critical_section;
};

class mutex::scoped_lock {
public:
    explicit scoped_lock(mutex& mx) : m_mutex(mx), m_locked(false) { lock(); }
    ~scoped_lock() { if (m_locked) unlock(); }
    void lock() { m_mutex.do_lock(); m_locked = true; }
    void unlock() { m_mutex.do_unlock(); m_locked = false; }
private:
    mutex& m_mutex;
    bool m_locked;
};

class CHtmlViewLike {
public:
    void Navigate2(const char* url, unsigned long flags, const char* target,
                   const char* headers, void* postData, unsigned long postLen);   // call 0x62ff56
};

class DHTMLWindow {
public:
    char pad[0xe8];
    mutex navMutex;            // +0xe8
    CHtmlViewLike* view;       // +0xf0
    void navigate(std::string url);
};

void DHTMLWindow::navigate(std::string url)
{
    mutex::scoped_lock lock(navMutex);
    if (view)
        view->Navigate2(url.c_str(), 0, 0, 0, 0, 0);
}
