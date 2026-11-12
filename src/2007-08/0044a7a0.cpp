// from server: 91% by EspClaude
// from server: 42% by colin
// roc 2007-08 0044a7a0  unit: CRobloxApp  size: 344 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044a7a0
//
// 0044a7a0  6aff                 push -1
// 0044a7a2  68f4fe7300           push 0x73fef4
// 0044a7a7  64a100000000         mov eax, dword ptr fs:[0]
// 0044a7ad  50                   push eax
// 0044a7ae  83ec2c               sub esp, 0x2c
// 0044a7b1  a188518b00           mov eax, dword ptr [0x8b5188]
// 0044a7b6  33c4                 xor eax, esp
// 0044a7b8  89442428             mov dword ptr [esp + 0x28], eax
// 0044a7bc  53                   push ebx
// 0044a7bd  56                   push esi
// 0044a7be  57                   push edi
// 0044a7bf  a188518b00           mov eax, dword ptr [0x8b5188]
// 0044a7c4  33c4                 xor eax, esp
// 0044a7c6  50                   push eax
// 0044a7c7  8d44243c             lea eax, [esp + 0x3c]
// 0044a7cb  64a300000000         mov dword ptr fs:[0], eax
// 0044a7d1  8bf1                 mov esi, ecx
// 0044a7d3  89742418             mov dword ptr [esp + 0x18], esi
// 0044a7d7  e89e601e00           call 0x63087a
// 0044a7dc  33db                 xor ebx, ebx
// 0044a7de  c706c4097900         mov dword ptr [esi], 0x7909c4
// 0044a7e4  885e24               mov byte ptr [esi + 0x24], bl
// 0044a7e7  885e25               mov byte ptr [esi + 0x25], bl
// 0044a7ea  885e26               mov byte ptr [esi + 0x26], bl
// 0044a7ed  885e27               mov byte ptr [esi + 0x27], bl
// 0044a7f0  895c2444             mov dword ptr [esp + 0x44], ebx
// 0044a7f4  895e2c               mov dword ptr [esi + 0x2c], ebx
// 0044a7f7  895e30               mov dword ptr [esi + 0x30], ebx
// 0044a7fa  895e34               mov dword ptr [esi + 0x34], ebx
// 0044a7fd  a158e97700           mov eax, dword ptr [0x77e958]
// 0044a802  3918                 cmp dword ptr [eax], ebx
// 0044a804  c644244401           mov byte ptr [esp + 0x44], 1
// 0044a809  0f8ec9000000         jle 0x44a8d8
// 0044a80f  8d4c241c             lea ecx, [esp + 0x1c]
// 0044a813  ff15a4e67700         call dword ptr [0x77e6a4]
// 0044a819  8b0d58e97700         mov ecx, dword ptr [0x77e958]
// 0044a81f  33ff                 xor edi, edi
// 0044a821  3919                 cmp dword ptr [ecx], ebx
// 0044a823  c644244402           mov byte ptr [esp + 0x44], 2
// 0044a828  7e3c                 jle 0x44a866
// 0044a82a  8d9b00000000         lea ebx, [ebx]
// 0044a830  3bfb                 cmp edi, ebx
// 0044a832  740f                 je 0x44a843
// 0044a834  6834707800           push 0x787034
// 0044a839  8d4c2420             lea ecx, [esp + 0x20]
// 0044a83d  ff1560e67700         call dword ptr [0x77e660]
// 0044a843  8b155ce97700         mov edx, dword ptr [0x77e95c]
// 0044a849  8b02                 mov eax, dword ptr [edx]
// 0044a84b  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 0044a84e  51                   push ecx
// 0044a84f  8d4c2420             lea ecx, [esp + 0x20]
// 0044a853  ff1560e67700         call dword ptr [0x77e660]
// 0044a859  8b1558e97700         mov edx, dword ptr [0x77e958]
// 0044a85f  83c701               add edi, 1
// 0044a862  3b3a                 cmp edi, dword ptr [edx]
// 0044a864  7cca                 jl 0x44a830
// 0044a866  8d442410             lea eax, [esp + 0x10]
// 0044a86a  50                   push eax
// 0044a86b  e8401b1200           call 0x56c3b0
// 0044a870  83c404               add esp, 4
// 0044a873  8b38                 mov edi, dword ptr [eax]
// 0044a875  8d4c241c             lea ecx, [esp + 0x1c]
// 0044a879  c644244403           mov byte ptr [esp + 0x44], 3
// 0044a87e  ff15a8e67700         call dword ptr [0x77e6a8]
// 0044a884  50                   push eax
// 0044a885  6a01                 push 1
// 0044a887  57                   push edi
// 0044a888  e813181200           call 0x56c0a0
// 0044a88d  8b442420             mov eax, dword ptr [esp + 0x20]
// 0044a891  83c40c               add esp, 0xc
// 0044a894  3bc3                 cmp eax, ebx
// 0044a896  c644244402           mov byte ptr [esp + 0x44], 2
// 0044a89b  742c                 je 0x44a8c9
// 0044a89d  8bf8                 mov edi, eax
// 0044a89f  83c004               add eax, 4
// 0044a8a2  83c9ff               or ecx, 0xffffffff
// 0044a8a5  f00fc108             lock xadd dword ptr [eax], ecx
// 0044a8a9  751e                 jne 0x44a8c9
// 0044a8ab  8b17                 mov edx, dword ptr [edi]
// 0044a8ad  8b4204               mov eax, dword ptr [edx + 4]
// 0044a8b0  8bcf                 mov ecx, edi
// 0044a8b2  ffd0                 call eax
// 0044a8b4  8d4f08               lea ecx, [edi + 8]
// 0044a8b7  83caff               or edx, 0xffffffff
// 0044a8ba  f00fc111             lock xadd dword ptr [ecx], edx
// 0044a8be  7509                 jne 0x44a8c9
// 0044a8c0  8b07                 mov eax, dword ptr [edi]
// 0044a8c2  8b5008               mov edx, dword ptr [eax + 8]
// 0044a8c5  8bcf                 mov ecx, edi
// 0044a8c7  ffd2                 call edx
// 0044a8c9  8d4c241c             lea ecx, [esp + 0x1c]
// 0044a8cd  c644244401           mov byte ptr [esp + 0x44], 1
// 0044a8d2  ff15ace67700         call dword ptr [0x77e6ac]
// 0044a8d8  8bc6                 mov eax, esi
// 0044a8da  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0044a8de  64890d00000000       mov dword ptr fs:[0], ecx
// 0044a8e5  59                   pop ecx
// 0044a8e6  5f                   pop edi
// 0044a8e7  5e                   pop esi
// 0044a8e8  5b                   pop ebx
// 0044a8e9  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0044a8ed  33cc                 xor ecx, esp
// 0044a8ef  e82a611e00           call 0x630a1e
// 0044a8f4  83c438               add esp, 0x38
// 0044a8f7  c3                   ret 

#include <string>
#include <vector>
#include <stdlib.h>
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
    static shared_ptr<StandardOut> singleton();             // 0x56c3b0
    void printf(int type, const char* format, ...);         // 0x56c0a0
};

// MFC 8 CCommandLineInfo (ctor through import thunk 0x63087a, no args); derived fields start at 0x24.
class CCommandLineInfo {
public:
    CCommandLineInfo();
    virtual ~CCommandLineInfo();
    virtual void ParseParam(const char* pszParam, int bFlag, int bLast);
    char pad4[0x20];
};

class CRobloxCommandLineInfo : public CCommandLineInfo {
public:
    CRobloxCommandLineInfo();
    virtual void ParseParam(const char* pszParam, int bFlag, int bLast);
    bool m_24;
    bool m_25;
    bool m_26;
    bool m_27;
    std::vector<int> m_28;          // +0x28: zeroed 0x2c/0x30/0x34, has unwind state
};

CRobloxCommandLineInfo::CRobloxCommandLineInfo()
    : m_24(false), m_25(false), m_26(false), m_27(false)
{
    if (__argc > 0)
    {
        std::string s;
        for (int i = 0; i < __argc; ++i)
        {
            if (i != 0)
                s += " ";
            s += __argv[i];
        }
        StandardOut::singleton()->printf(1, s.c_str());
    }
}
