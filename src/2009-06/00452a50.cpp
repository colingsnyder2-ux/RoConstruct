// from server: 70% by EspClaude
// from server: 100% by colin
// roc 2008-06 00454c90  unit: CRobloxDoc  size: 631 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00454c90
//
// 00454c90  55                   push ebp
// 00454c91  8d6c24a0             lea ebp, [esp - 0x60]
// 00454c95  83ec60               sub esp, 0x60
// 00454c98  6aff                 push -1
// 00454c9a  683a217c00           push 0x7c213a
// 00454c9f  64a100000000         mov eax, dword ptr fs:[0]
// 00454ca5  50                   push eax
// 00454ca6  64892500000000       mov dword ptr fs:[0], esp
// 00454cad  81ec84020000         sub esp, 0x284
// 00454cb3  53                   push ebx
// 00454cb4  56                   push esi
// 00454cb5  57                   push edi
// 00454cb6  8bf9                 mov edi, ecx
// 00454cb8  8d4d5c               lea ecx, [ebp + 0x5c]
// 00454cbb  8965f0               mov dword ptr [ebp - 0x10], esp
// 00454cbe  ff15043f8000         call dword ptr [0x803f04]
// 00454cc4  688d000000           push 0x8d
// 00454cc9  8d4d5c               lea ecx, [ebp + 0x5c]
// 00454ccc  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00454cd3  ff15c0328000         call dword ptr [0x8032c0]
// 00454cd9  6a01                 push 1
// 00454cdb  6a00                 push 0
// 00454cdd  6a00                 push 0
// 00454cdf  8d4d5c               lea ecx, [ebp + 0x5c]
// 00454ce2  ff15e03e8000         call dword ptr [0x803ee0]
// 00454ce8  50                   push eax
// 00454ce9  6a06                 push 6
// 00454ceb  6a00                 push 0
// 00454ced  68fc7e8100           push 0x817efc
// 00454cf2  6a01                 push 1
// 00454cf4  8d8d70fdffff         lea ecx, [ebp - 0x290]
// 00454cfa  e873c12400           call 0x6a0e72
// 00454cff  8d8d70fdffff         lea ecx, [ebp - 0x290]
// 00454d05  c645fc01             mov byte ptr [ebp - 4], 1
// 00454d09  e85ec12400           call 0x6a0e6c
// 00454d0e  83f801               cmp eax, 1
// 00454d11  0f85c4010000         jne 0x454edb
// 00454d17  8d4554               lea eax, [ebp + 0x54]
// 00454d1a  50                   push eax
// 00454d1b  8d8d70fdffff         lea ecx, [ebp - 0x290]
// 00454d21  e840c12400           call 0x6a0e66
// 00454d26  8bc8                 mov ecx, eax
// 00454d28  c645fc02             mov byte ptr [ebp - 4], 2
// 00454d2c  ff15e03e8000         call dword ptr [0x803ee0]
// 00454d32  50                   push eax
// 00454d33  8d4dd0               lea ecx, [ebp - 0x30]
// 00454d36  e8d5a30100           call 0x46f110
// 00454d3b  8d4d54               lea ecx, [ebp + 0x54]
// 00454d3e  c645fc04             mov byte ptr [ebp - 4], 4
// 00454d42  ff15143f8000         call dword ptr [0x803f14]
// 00454d48  6a01                 push 1
// 00454d4a  6a02                 push 2
// 00454d4c  8d8d50ffffff         lea ecx, [ebp - 0xb0]
// 00454d52  ff1530248000         call dword ptr [0x802430]
// 00454d58  8d8d50ffffff         lea ecx, [ebp - 0xb0]
// 00454d5e  51                   push ecx
// 00454d5f  8d4dd0               lea ecx, [ebp - 0x30]
// 00454d62  c645fc05             mov byte ptr [ebp - 4], 5
// 00454d66  e895a40100           call 0x46f200
// 00454d6b  8d8d50ffffff         lea ecx, [ebp - 0xb0]
// 00454d71  ff15bc238000         call dword ptr [0x8023bc]
// 00454d77  8b8f94000000         mov ecx, dword ptr [edi + 0x94]
// 00454d7d  8d5540               lea edx, [ebp + 0x40]
// 00454d80  52                   push edx
// 00454d81  c645fc06             mov byte ptr [ebp - 4], 6
// 00454d85  e8b65b0100           call 0x46a940
// 00454d8a  8b10                 mov edx, dword ptr [eax]
// 00454d8c  83ec08               sub esp, 8
// 00454d8f  8bcc                 mov ecx, esp
// 00454d91  8911                 mov dword ptr [ecx], edx
// 00454d93  8b4004               mov eax, dword ptr [eax + 4]
// 00454d96  c645fc07             mov byte ptr [ebp - 4], 7
// 00454d9a  896558               mov dword ptr [ebp + 0x58], esp
// 00454d9d  894104               mov dword ptr [ecx + 4], eax
// 00454da0  85c0                 test eax, eax
// 00454da2  740c                 je 0x454db0
// 00454da4  83c004               add eax, 4
// 00454da7  b901000000           mov ecx, 1
// 00454dac  f00fc108             lock xadd dword ptr [eax], ecx
// 00454db0  8d4d34               lea ecx, [ebp + 0x34]
// 00454db3  e888cdfbff           call 0x411b40
// 00454db8  8b7544               mov esi, dword ptr [ebp + 0x44]
// 00454dbb  c645fc09             mov byte ptr [ebp - 4], 9
// 00454dbf  85f6                 test esi, esi
// 00454dc1  742a                 je 0x454ded
// 00454dc3  8d5604               lea edx, [esi + 4]
// 00454dc6  83c8ff               or eax, 0xffffffff
// 00454dc9  f00fc102             lock xadd dword ptr [edx], eax
// 00454dcd  751e                 jne 0x454ded
// 00454dcf  8b16                 mov edx, dword ptr [esi]
// 00454dd1  8b4204               mov eax, dword ptr [edx + 4]
// 00454dd4  8bce                 mov ecx, esi
// 00454dd6  ffd0                 call eax
// 00454dd8  8d4e08               lea ecx, [esi + 8]
// 00454ddb  83caff               or edx, 0xffffffff
// 00454dde  f00fc111             lock xadd dword ptr [ecx], edx
// 00454de2  7509                 jne 0x454ded
// 00454de4  8b06                 mov eax, dword ptr [esi]
// 00454de6  8b5008               mov edx, dword ptr [eax + 8]
// 00454de9  8bce                 mov ecx, esi
// 00454deb  ffd2                 call edx
// 00454ded  8d4d1c               lea ecx, [ebp + 0x1c]
// 00454df0  e8db45fdff           call 0x4293d0
// 00454df5  8d4500               lea eax, [ebp]
// 00454df8  50                   push eax
// 00454df9  8d8d50ffffff         lea ecx, [ebp - 0xb0]
// 00454dff  c645fc0a             mov byte ptr [ebp - 4], 0xa
// 00454e03  ff1534248000         call dword ptr [0x802434]
// 00454e09  8d4d4c               lea ecx, [ebp + 0x4c]
// 00454e0c  51                   push ecx
// 00454e0d  b30b                 mov bl, 0xb
// 00454e0f  8bcf                 mov ecx, edi
// 00454e11  885dfc               mov byte ptr [ebp - 4], bl
// 00454e14  e827e2faff           call 0x403040
// 00454e19  8b30                 mov esi, dword ptr [eax]
// 00454e1b  8d4d00               lea ecx, [ebp]
// 00454e1e  c645fc0c             mov byte ptr [ebp - 4], 0xc
// 00454e22  ff1564248000         call dword ptr [0x802464]
// 00454e28  8bce                 mov ecx, esi
// 00454e2a  8bf8                 mov edi, eax
// 00454e2c  e89f91fdff           call 0x42dfd0
// 00454e31  8d551c               lea edx, [ebp + 0x1c]
// 00454e34  52                   push edx
// 00454e35  68f47e8100           push 0x817ef4
// 00454e3a  57                   push edi
// 00454e3b  6a01                 push 1
// 00454e3d  8d4d58               lea ecx, [ebp + 0x58]
// 00454e40  51                   push ecx
// 00454e41  8bc8                 mov ecx, eax
// 00454e43  e838b61500           call 0x5b0480
// 00454e48  8b4d58               mov ecx, dword ptr [ebp + 0x58]
// 00454e4b  85c9                 test ecx, ecx
// 00454e4d  7410                 je 0x454e5f
// 00454e4f  8bf1                 mov esi, ecx
// 00454e51  e8da87fdff           call 0x42d630
// 00454e56  56                   push esi
// 00454e57  e81eb82400           call 0x6a067a
// 00454e5c  83c404               add esp, 4
// 00454e5f  8b7550               mov esi, dword ptr [ebp + 0x50]
// 00454e62  885dfc               mov byte ptr [ebp - 4], bl
// 00454e65  85f6                 test esi, esi
// 00454e67  742a                 je 0x454e93
// 00454e69  8d5604               lea edx, [esi + 4]
// 00454e6c  83c8ff               or eax, 0xffffffff
// 00454e6f  f00fc102             lock xadd dword ptr [edx], eax
// 00454e73  751e                 jne 0x454e93
// 00454e75  8b16                 mov edx, dword ptr [esi]
// 00454e77  8b4204               mov eax, dword ptr [edx + 4]
// 00454e7a  8bce                 mov ecx, esi
// 00454e7c  ffd0                 call eax
// 00454e7e  8d4e08               lea ecx, [esi + 8]
// 00454e81  83caff               or edx, 0xffffffff
// 00454e84  f00fc111             lock xadd dword ptr [ecx], edx
// 00454e88  7509                 jne 0x454e93
// 00454e8a  8b06                 mov eax, dword ptr [esi]
// 00454e8c  8b5008               mov edx, dword ptr [eax + 8]
// 00454e8f  8bce                 mov ecx, esi
// 00454e91  ffd2                 call edx
// 00454e93  8d4d00               lea ecx, [ebp]
// 00454e96  c645fc0a             mov byte ptr [ebp - 4], 0xa
// 00454e9a  ff1568248000         call dword ptr [0x802468]
// 00454ea0  8d4d1c               lea ecx, [ebp + 0x1c]
// 00454ea3  c645fc09             mov byte ptr [ebp - 4], 9
// 00454ea7  e88487fdff           call 0x42d630
// 00454eac  8d4d34               lea ecx, [ebp + 0x34]
// 00454eaf  c645fc06             mov byte ptr [ebp - 4], 6
// 00454eb3  e808251200           call 0x5773c0
// 00454eb8  c745fc05000000       mov dword ptr [ebp - 4], 5
// 00454ebf  8d8d50ffffff         lea ecx, [ebp - 0xb0]
// 00454ec5  c645fc04             mov byte ptr [ebp - 4], 4
// 00454ec9  ff1538248000         call dword ptr [0x802438]
// 00454ecf  8d4dd0               lea ecx, [ebp - 0x30]
// 00454ed2  c645fc01             mov byte ptr [ebp - 4], 1
// 00454ed6  e825a20100           call 0x46f100
// 00454edb  8d8d70fdffff         lea ecx, [ebp - 0x290]
// 00454ee1  c645fc00             mov byte ptr [ebp - 4], 0
// 00454ee5  e870bf2400           call 0x6a0e5a
// 00454eea  8d4d5c               lea ecx, [ebp + 0x5c]
// 00454eed  ff15143f8000         call dword ptr [0x803f14]
// 00454ef3  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00454ef6  5f                   pop edi
// 00454ef7  5e                   pop esi
// 00454ef8  64890d00000000       mov dword ptr fs:[0], ecx
// 00454eff  5b                   pop ebx
// 00454f00  83c560               add ebp, 0x60
// 00454f03  8be5                 mov esp, ebp
// 00454f05  5d                   pop ebp
// 00454f06  c3                   ret 

// from server: 97% by EspClaude
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <vector>
#include <memory>
#include <exception>

template <class T> class bstr {
public:
    __declspec(noinline) bstr() { _Mysize = 0; }
    __declspec(noinline) ~bstr() { _Mysize = 0; }
    __declspec(noinline) bstr& operator=(const bstr& r) { _Mysize = r._Mysize; return *this; }
    __declspec(noinline) bstr& operator=(const T* r) { _Mysize = 0; return *this; }
    __declspec(noinline) const T* c_str() const { return _Buf; }
    __declspec(noinline) unsigned int size() const { return _Mysize; }
    void* _Myaux;
    T _Buf[16];
    unsigned int _Mysize;
    unsigned int _Myres;
};
extern template class __declspec(dllimport) bstr<char>;
typedef bstr<char> string_;
__declspec(dllimport) bool operator==(const string_&, const char*);

namespace boost {
struct lock_error { lock_error(); };
namespace detail {
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
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) _InterlockedIncrement(&pi_->use_count_); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r);
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    shared_ptr() : px(0), pn() {}
    template<class Y> shared_ptr(const shared_ptr<Y>& r) : px(r.px), pn(r.pn) {}
    void reset();
    T* get() const { return px; }
    T* operator->() const { return px; }
    T& operator*() const { return *px; }
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
};

}

template <class T> class bios {
public:
    __declspec(noinline) bios() { x = 0; }
    __declspec(noinline) virtual ~bios() { x = 0; }
    int x;
    char pad[0x40];
};
template <class T> class bostr : virtual public bios<T> {
public:
    __declspec(noinline) explicit bostr(int mode) { y = mode; }
    __declspec(noinline) virtual ~bostr() { y = 0; }
    __declspec(noinline) bostr& flush() { return *this; }
    __declspec(noinline) bstr<T> str() const { return bstr<T>(); }
    int y;
    char pad[0x30];
};
extern template class __declspec(dllimport) bios<char>;
extern template class __declspec(dllimport) bostr<char>;
typedef bostr<char> ostringstream_;

template <class T> class CStringT_ {
public:
    __declspec(noinline) CStringT_() { m_pszData = 0; }
    __declspec(noinline) ~CStringT_() throw() { m_pszData = 0; }
    __declspec(noinline) operator const T*() const { return m_pszData; }
    __declspec(noinline) int LoadString(unsigned int nID) { return 0; }
    T* m_pszData;
};
extern template class __declspec(dllimport) CStringT_<char>;
typedef CStringT_<char> CString;
class CWnd;
class CFileDialog {
public:
    CFileDialog(int bOpenFileDialog, const char* lpszDefExt = 0, const char* lpszFileName = 0,
                unsigned long dwFlags = 6, const char* lpszFilter = 0, CWnd* pParentWnd = 0,
                unsigned long dwSize = 0, int bVistaStyle = 1);
    virtual ~CFileDialog();
    virtual int DoModal();
    CString GetPathName() const;
    char data[0x1dc];
};
int __stdcall AfxMessageBox(const char* lpszText, unsigned int nType = 0, unsigned int nIDHelp = 0);

namespace RBX {
class Tuple { public: Tuple(); ~Tuple(); char data[0x18]; };
class ScriptContext {
public:
    std::auto_ptr<Tuple> executeInNewThread(int identity, const char* script, const char* name, const Tuple& args);
};
class ServiceProvider {
public:
    virtual ~ServiceProvider();
    template<class T> T* create() const;
};
class DataModel : public ServiceProvider {};
class ReadRequest {
public:
    ReadRequest(boost::shared_ptr<const DataModel> dm);
    ~ReadRequest();
    void* a; void* b; void* c;
};
namespace LDraw2Lua {
class LDrawParser {
public:
    explicit LDrawParser(const char* fileName);
    ~LDrawParser();
    void writeLua(bostr<char>& stream);
    char data[0x20];
};
}
}

class CRobloxView { public: boost::shared_ptr<RBX::DataModel> getDataModel(); };

class CRobloxDoc {
public:
    virtual ~CRobloxDoc();
    char pad[0x90];
    CRobloxView* view;
    boost::shared_ptr<RBX::DataModel> getDataModel();
    void OnInsertLDraw();
};

void CRobloxDoc::OnInsertLDraw()
{
    CString filter;
    filter.LoadString(0x8d);
    CFileDialog dlg(1, "ldr", 0, 6, filter, 0, 0, 1);
    if (dlg.DoModal() == 1) {
        RBX::LDraw2Lua::LDrawParser parser(dlg.GetPathName());
        ostringstream_ stream(2);
        parser.writeLua(stream);
        stream.flush();
        try {
            RBX::ReadRequest request(view->getDataModel());
            RBX::Tuple args;
            string_ script = stream.str();
            getDataModel()->create<RBX::ScriptContext>()->executeInNewThread(1, script.c_str(), "LDraw", args);
        } catch (std::exception& e) {
            AfxMessageBox(e.what(), 0x10);
        }
    }
}
