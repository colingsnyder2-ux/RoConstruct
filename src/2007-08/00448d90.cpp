// from server: 100% by EspClaude
// from server: 41% by colin
// roc 2007-08 00448d90  unit: CRobloxApp  size: 258 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00448d90
//
// 00448d90  6aff                 push -1
// 00448d92  6850fc7300           push 0x73fc50
// 00448d97  64a100000000         mov eax, dword ptr fs:[0]
// 00448d9d  50                   push eax
// 00448d9e  83ec10               sub esp, 0x10
// 00448da1  53                   push ebx
// 00448da2  56                   push esi
// 00448da3  57                   push edi
// 00448da4  a188518b00           mov eax, dword ptr [0x8b5188]
// 00448da9  33c4                 xor eax, esp
// 00448dab  50                   push eax
// 00448dac  8d442420             lea eax, [esp + 0x20]
// 00448db0  64a300000000         mov dword ptr fs:[0], eax
// 00448db6  8bd9                 mov ebx, ecx
// 00448db8  8d442410             lea eax, [esp + 0x10]
// 00448dbc  50                   push eax
// 00448dbd  e8ee351200           call 0x56c3b0
// 00448dc2  8b00                 mov eax, dword ptr [eax]
// 00448dc4  68d8057900           push 0x7905d8
// 00448dc9  6a01                 push 1
// 00448dcb  50                   push eax
// 00448dcc  c744243800000000     mov dword ptr [esp + 0x38], 0
// 00448dd4  e8c7321200           call 0x56c0a0
// 00448dd9  8b442424             mov eax, dword ptr [esp + 0x24]
// 00448ddd  83cfff               or edi, 0xffffffff
// 00448de0  83c410               add esp, 0x10
// 00448de3  85c0                 test eax, eax
// 00448de5  897c2428             mov dword ptr [esp + 0x28], edi
// 00448de9  742a                 je 0x448e15
// 00448deb  8bf0                 mov esi, eax
// 00448ded  83c004               add eax, 4
// 00448df0  8bcf                 mov ecx, edi
// 00448df2  f00fc108             lock xadd dword ptr [eax], ecx
// 00448df6  751d                 jne 0x448e15
// 00448df8  8b16                 mov edx, dword ptr [esi]
// 00448dfa  8b4204               mov eax, dword ptr [edx + 4]
// 00448dfd  8bce                 mov ecx, esi
// 00448dff  ffd0                 call eax
// 00448e01  8d4e08               lea ecx, [esi + 8]
// 00448e04  8bd7                 mov edx, edi
// 00448e06  f00fc111             lock xadd dword ptr [ecx], edx
// 00448e0a  7509                 jne 0x448e15
// 00448e0c  8b06                 mov eax, dword ptr [esi]
// 00448e0e  8b5008               mov edx, dword ptr [eax + 8]
// 00448e11  8bce                 mov ecx, esi
// 00448e13  ffd2                 call edx
// 00448e15  68c0988c00           push 0x8c98c0
// 00448e1a  e851f7ffff           call 0x448570
// 00448e1f  803d51bd8b0000       cmp byte ptr [0x8bbd51], 0
// 00448e26  7450                 je 0x448e78
// 00448e28  8d442418             lea eax, [esp + 0x18]
// 00448e2c  50                   push eax
// 00448e2d  e81e1b1000           call 0x54a950
// 00448e32  83c404               add esp, 4
// 00448e35  8b08                 mov ecx, dword ptr [eax]
// 00448e37  c744242801000000     mov dword ptr [esp + 0x28], 1
// 00448e3f  e8fc111000           call 0x54a040
// 00448e44  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00448e48  85c0                 test eax, eax
// 00448e4a  897c2428             mov dword ptr [esp + 0x28], edi
// 00448e4e  7428                 je 0x448e78
// 00448e50  8bf0                 mov esi, eax
// 00448e52  83c004               add eax, 4
// 00448e55  8bcf                 mov ecx, edi
// 00448e57  f00fc108             lock xadd dword ptr [eax], ecx
// 00448e5b  751b                 jne 0x448e78
// 00448e5d  8b16                 mov edx, dword ptr [esi]
// 00448e5f  8b4204               mov eax, dword ptr [edx + 4]
// 00448e62  8bce                 mov ecx, esi
// 00448e64  ffd0                 call eax
// 00448e66  8d4e08               lea ecx, [esi + 8]
// 00448e69  f00fc139             lock xadd dword ptr [ecx], edi
// 00448e6d  7509                 jne 0x448e78
// 00448e6f  8b16                 mov edx, dword ptr [esi]
// 00448e71  8b4208               mov eax, dword ptr [edx + 8]
// 00448e74  8bce                 mov ecx, esi
// 00448e76  ffd0                 call eax
// 00448e78  8bcb                 mov ecx, ebx
// 00448e7a  e823791e00           call 0x6307a2
// 00448e7f  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00448e83  64890d00000000       mov dword ptr fs:[0], ecx
// 00448e8a  59                   pop ecx
// 00448e8b  5f                   pop edi
// 00448e8c  5e                   pop esi
// 00448e8d  5b                   pop ebx
// 00448e8e  83c41c               add esp, 0x1c
// 00448e91  c3                   ret 

#include <intrin.h>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    long use_count_;
    long weak_count_;
};

class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r);
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    T* operator->() const { return px; }
};

class StandardOut {
public:
    static shared_ptr<StandardOut> singleton();             // 0x56c3b0 (cdecl, hidden return)
    void printf(int type, const char* format, ...);         // 0x56c0a0 (cdecl varargs member)
};

class Service54 {
public:
    static shared_ptr<Service54> singleton();                // 0x54a950
    void shutdown();                                         // 0x54a040 (thiscall)
};

struct Global8C98C0;
extern Global8C98C0 g_8c98c0;
void __stdcall sub_448570(Global8C98C0* p);                  // callee pops its one argument
extern bool g_8bbd51;

class CWinApp {
public:
    virtual int ExitInstance();                              // 0x6307a2
};

class CRobloxApp : public CWinApp {
public:
    virtual int ExitInstance();
};

int CRobloxApp::ExitInstance()
{
    StandardOut::singleton()->printf(1, "ROBLOX ExitInstance");
    sub_448570(&g_8c98c0);
    if (g_8bbd51)
        Service54::singleton()->shutdown();
    return CWinApp::ExitInstance();
}
