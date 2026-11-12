// from server: 100% by EspClaude
// from server: 44% by colin
// roc 2007-08 00456ff0  unit: CRobloxView  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00456ff0
//
// 00456ff0  6aff                 push -1
// 00456ff2  68b89d7400           push 0x749db8
// 00456ff7  64a100000000         mov eax, dword ptr fs:[0]
// 00456ffd  50                   push eax
// 00456ffe  56                   push esi
// 00456fff  57                   push edi
// 00457000  a188518b00           mov eax, dword ptr [0x8b5188]
// 00457005  33c4                 xor eax, esp
// 00457007  50                   push eax
// 00457008  8d44240c             lea eax, [esp + 0xc]
// 0045700c  64a300000000         mov dword ptr fs:[0], eax
// 00457012  8bf9                 mov edi, ecx
// 00457014  8b742420             mov esi, dword ptr [esp + 0x20]
// 00457018  8b06                 mov eax, dword ptr [esi]
// 0045701a  8b5004               mov edx, dword ptr [eax + 4]
// 0045701d  8bce                 mov ecx, esi
// 0045701f  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00457027  ffd2                 call edx
// 00457029  68dc6d7800           push 0x786ddc
// 0045702e  8d4804               lea ecx, [eax + 4]
// 00457031  ff15f4e57700         call dword ptr [0x77e5f4]
// 00457037  85c0                 test eax, eax
// 00457039  741b                 je 0x457056
// 0045703b  8b06                 mov eax, dword ptr [esi]
// 0045703d  8b5004               mov edx, dword ptr [eax + 4]
// 00457040  8bce                 mov ecx, esi
// 00457042  ffd2                 call edx
// 00457044  68a42b7900           push 0x792ba4
// 00457049  8d4804               lea ecx, [eax + 4]
// 0045704c  ff15f4e57700         call dword ptr [0x77e5f4]
// 00457052  85c0                 test eax, eax
// 00457054  7513                 jne 0x457069
// 00457056  8b47a8               mov eax, dword ptr [edi - 0x58]
// 00457059  6a00                 push 0
// 0045705b  6a00                 push 0
// 0045705d  686b040000           push 0x46b
// 00457062  50                   push eax
// 00457063  ff15d0ec7700         call dword ptr [0x77ecd0]
// 00457069  8b16                 mov edx, dword ptr [esi]
// 0045706b  8b4204               mov eax, dword ptr [edx + 4]
// 0045706e  8bce                 mov ecx, esi
// 00457070  ffd0                 call eax
// 00457072  68a42b7900           push 0x792ba4
// 00457077  8d4804               lea ecx, [eax + 4]
// 0045707a  ff15f4e57700         call dword ptr [0x77e5f4]
// 00457080  85c0                 test eax, eax
// 00457082  751a                 jne 0x45709e
// 00457084  8d4f88               lea ecx, [edi - 0x78]
// 00457087  85c9                 test ecx, ecx
// 00457089  7405                 je 0x457090
// 0045708b  8d4708               lea eax, [edi + 8]
// 0045708e  eb02                 jmp 0x457092
// 00457090  33c0                 xor eax, eax
// 00457092  50                   push eax
// 00457093  8d8e00010000         lea ecx, [esi + 0x100]
// 00457099  e8a2c1fcff           call 0x423240
// 0045709e  8b742424             mov esi, dword ptr [esp + 0x24]
// 004570a2  85f6                 test esi, esi
// 004570a4  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 004570ac  742a                 je 0x4570d8
// 004570ae  8d5604               lea edx, [esi + 4]
// 004570b1  83c8ff               or eax, 0xffffffff
// 004570b4  f00fc102             lock xadd dword ptr [edx], eax
// 004570b8  751e                 jne 0x4570d8
// 004570ba  8b16                 mov edx, dword ptr [esi]
// 004570bc  8b4204               mov eax, dword ptr [edx + 4]
// 004570bf  8bce                 mov ecx, esi
// 004570c1  ffd0                 call eax
// 004570c3  8d4e08               lea ecx, [esi + 8]
// 004570c6  83caff               or edx, 0xffffffff
// 004570c9  f00fc111             lock xadd dword ptr [ecx], edx
// 004570cd  7509                 jne 0x4570d8
// 004570cf  8b06                 mov eax, dword ptr [esi]
// 004570d1  8b5008               mov edx, dword ptr [eax + 8]
// 004570d4  8bce                 mov ecx, esi
// 004570d6  ffd2                 call edx
// 004570d8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004570dc  64890d00000000       mov dword ptr fs:[0], ecx
// 004570e3  59                   pop ecx
// 004570e4  5f                   pop edi
// 004570e5  5e                   pop esi
// 004570e6  83c40c               add esp, 0xc
// 004570e9  c20c00               ret 0xc

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" __declspec(dllimport) int __stdcall PostMessageA(void*, unsigned int, unsigned int, long);

int __cdecl compareText(const void*, const char*);

struct String
{
    __declspec(dllimport) __declspec(noinline) int compare(const char* s) const
    {
        return compareText(this, s);
    }
};

inline bool operator==(const String& a, const char* b)
{
    return a.compare(b) == 0;
}

inline bool operator!=(const String& a, const char* b)
{
    return a.compare(b) != 0;
}

struct Name
{
    int id;
    String str;
    bool operator==(const char* s) const
    {
        return str == s;
    }
};

struct Control
{
    virtual ~Control();
    virtual void dispose() = 0;
    virtual void destroy() = 0;

    volatile long strong;
    volatile long weak;

    void release();
    void releaseWeak();
};

inline void Control::releaseWeak()
{
    if (_InterlockedDecrement(&weak) == 0)
        destroy();
}

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        releaseWeak();
    }
}

struct Listener;

struct Registry
{
    void add(Listener*);
    void remove(Listener*);
};

struct Instance
{
    virtual ~Instance();
    virtual const Name& getClassName() const;
    char pad[0xfc];
    Registry registry;
};

struct InstancePtr
{
    Instance* px;
    Control* pn;
    ~InstancePtr()
    {
        if (pn)
            pn->release();
    }
    Instance* operator->() const { return px; }
};

struct WndBase
{
    virtual ~WndBase();
    char pad[0x1c];
    void* m_hWnd;
    char pad2[0x54];
};

struct ChildAddedObserver
{
    virtual void onChildAdded(int, InstancePtr) = 0;
};

struct ChildRemovedObserver
{
    virtual void onChildRemoved(int, InstancePtr) = 0;
};

struct Listener
{
    virtual void onListen();
};

struct CRobloxView : WndBase, ChildAddedObserver, ChildRemovedObserver, Listener
{
    virtual void onChildAdded(int, InstancePtr);
    virtual void onChildRemoved(int, InstancePtr);
};

void CRobloxView::onChildAdded(int, InstancePtr child)
{
    if (child->getClassName() == "NetworkClient" || child->getClassName() == "Players")
        PostMessageA(m_hWnd, 0x46b, 0, 0);
    if (child->getClassName() == "Players")
        child->registry.add(this);
}
