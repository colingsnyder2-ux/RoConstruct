// from server: 100% by EspClaude
// from server: 40% by colin
// roc 2007-08 00456840  unit: CRobloxView  size: 298 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00456840
//
// 00456840  6aff                 push -1
// 00456842  68a8137400           push 0x7413a8
// 00456847  64a100000000         mov eax, dword ptr fs:[0]
// 0045684d  50                   push eax
// 0045684e  53                   push ebx
// 0045684f  56                   push esi
// 00456850  57                   push edi
// 00456851  a188518b00           mov eax, dword ptr [0x8b5188]
// 00456856  33c4                 xor eax, esp
// 00456858  50                   push eax
// 00456859  8d442410             lea eax, [esp + 0x10]
// 0045685d  64a300000000         mov dword ptr fs:[0], eax
// 00456863  8bf9                 mov edi, ecx
// 00456865  8b742424             mov esi, dword ptr [esp + 0x24]
// 00456869  8b06                 mov eax, dword ptr [esi]
// 0045686b  8b5004               mov edx, dword ptr [eax + 4]
// 0045686e  8bce                 mov ecx, esi
// 00456870  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00456878  ffd2                 call edx
// 0045687a  68dc6d7800           push 0x786ddc
// 0045687f  8d4804               lea ecx, [eax + 4]
// 00456882  ff15f4e57700         call dword ptr [0x77e5f4]
// 00456888  85c0                 test eax, eax
// 0045688a  8b1dd0ec7700         mov ebx, dword ptr [0x77ecd0]
// 00456890  750f                 jne 0x4568a1
// 00456892  8b47a4               mov eax, dword ptr [edi - 0x5c]
// 00456895  6a00                 push 0
// 00456897  6a00                 push 0
// 00456899  686c040000           push 0x46c
// 0045689e  50                   push eax
// 0045689f  ffd3                 call ebx
// 004568a1  8b16                 mov edx, dword ptr [esi]
// 004568a3  8b4204               mov eax, dword ptr [edx + 4]
// 004568a6  8bce                 mov ecx, esi
// 004568a8  ffd0                 call eax
// 004568aa  68dc6d7800           push 0x786ddc
// 004568af  8d4804               lea ecx, [eax + 4]
// 004568b2  ff15f4e57700         call dword ptr [0x77e5f4]
// 004568b8  85c0                 test eax, eax
// 004568ba  741b                 je 0x4568d7
// 004568bc  8b16                 mov edx, dword ptr [esi]
// 004568be  8b4204               mov eax, dword ptr [edx + 4]
// 004568c1  8bce                 mov ecx, esi
// 004568c3  ffd0                 call eax
// 004568c5  68a42b7900           push 0x792ba4
// 004568ca  8d4804               lea ecx, [eax + 4]
// 004568cd  ff15f4e57700         call dword ptr [0x77e5f4]
// 004568d3  85c0                 test eax, eax
// 004568d5  750f                 jne 0x4568e6
// 004568d7  8b4fa4               mov ecx, dword ptr [edi - 0x5c]
// 004568da  6a00                 push 0
// 004568dc  6a00                 push 0
// 004568de  686b040000           push 0x46b
// 004568e3  51                   push ecx
// 004568e4  ffd3                 call ebx
// 004568e6  8b16                 mov edx, dword ptr [esi]
// 004568e8  8b4204               mov eax, dword ptr [edx + 4]
// 004568eb  8bce                 mov ecx, esi
// 004568ed  ffd0                 call eax
// 004568ef  68a42b7900           push 0x792ba4
// 004568f4  8d4804               lea ecx, [eax + 4]
// 004568f7  ff15f4e57700         call dword ptr [0x77e5f4]
// 004568fd  85c0                 test eax, eax
// 004568ff  751a                 jne 0x45691b
// 00456901  8d4f84               lea ecx, [edi - 0x7c]
// 00456904  85c9                 test ecx, ecx
// 00456906  7405                 je 0x45690d
// 00456908  8d4704               lea eax, [edi + 4]
// 0045690b  eb02                 jmp 0x45690f
// 0045690d  33c0                 xor eax, eax
// 0045690f  50                   push eax
// 00456910  8d8e00010000         lea ecx, [esi + 0x100]
// 00456916  e815bcfdff           call 0x432530
// 0045691b  8b742428             mov esi, dword ptr [esp + 0x28]
// 0045691f  85f6                 test esi, esi
// 00456921  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00456929  742a                 je 0x456955
// 0045692b  8d5604               lea edx, [esi + 4]
// 0045692e  83c8ff               or eax, 0xffffffff
// 00456931  f00fc102             lock xadd dword ptr [edx], eax
// 00456935  751e                 jne 0x456955
// 00456937  8b16                 mov edx, dword ptr [esi]
// 00456939  8b4204               mov eax, dword ptr [edx + 4]
// 0045693c  8bce                 mov ecx, esi
// 0045693e  ffd0                 call eax
// 00456940  8d4e08               lea ecx, [esi + 8]
// 00456943  83caff               or edx, 0xffffffff
// 00456946  f00fc111             lock xadd dword ptr [ecx], edx
// 0045694a  7509                 jne 0x456955
// 0045694c  8b06                 mov eax, dword ptr [esi]
// 0045694e  8b5008               mov edx, dword ptr [eax + 8]
// 00456951  8bce                 mov ecx, esi
// 00456953  ffd2                 call edx
// 00456955  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00456959  64890d00000000       mov dword ptr fs:[0], ecx
// 00456960  59                   pop ecx
// 00456961  5f                   pop edi
// 00456962  5e                   pop esi
// 00456963  5b                   pop ebx
// 00456964  83c40c               add esp, 0xc
// 00456967  c20c00               ret 0xc

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

void CRobloxView::onChildRemoved(int, InstancePtr child)
{
    if (child->getClassName() == "NetworkClient")
        PostMessageA(m_hWnd, 0x46c, 0, 0);
    if (child->getClassName() == "NetworkClient" || child->getClassName() == "Players")
        PostMessageA(m_hWnd, 0x46b, 0, 0);
    if (child->getClassName() == "Players")
        child->registry.remove(this);
}
