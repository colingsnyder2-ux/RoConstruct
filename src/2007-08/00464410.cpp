// from server: 96% by EspClaude
// from server: 100% by EspClaude
// roc 2008-06 00467d50  unit: DxUserInput  size: 443 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00467d50
//
// 00467d50  64a100000000         mov eax, dword ptr fs:[0]
// 00467d56  6aff                 push -1
// 00467d58  6848367c00           push 0x7c3648
// 00467d5d  50                   push eax
// 00467d5e  64892500000000       mov dword ptr fs:[0], esp
// 00467d65  83ec24               sub esp, 0x24
// 00467d68  53                   push ebx
// 00467d69  56                   push esi
// 00467d6a  57                   push edi
// 00467d6b  e8b68b2300           call 0x6a0926
// 00467d70  8b4004               mov eax, dword ptr [eax + 4]
// 00467d73  8b4020               mov eax, dword ptr [eax + 0x20]
// 00467d76  8a8004010000         mov al, byte ptr [eax + 0x104]
// 00467d7c  84c0                 test al, al
// 00467d7e  0f8473010000         je 0x467ef7
// 00467d84  8d44240c             lea eax, [esp + 0xc]
// 00467d88  50                   push eax
// 00467d89  e83289fcff           call 0x4306c0
// 00467d8e  8b742414             mov esi, dword ptr [esp + 0x14]
// 00467d92  83c404               add esp, 4
// 00467d95  833800               cmp dword ptr [eax], 0
// 00467d98  0f95c3               setne bl
// 00467d9b  85f6                 test esi, esi
// 00467d9d  742a                 je 0x467dc9
// 00467d9f  8d4e04               lea ecx, [esi + 4]
// 00467da2  83caff               or edx, 0xffffffff
// 00467da5  f00fc111             lock xadd dword ptr [ecx], edx
// 00467da9  751e                 jne 0x467dc9
// 00467dab  8b06                 mov eax, dword ptr [esi]
// 00467dad  8b5004               mov edx, dword ptr [eax + 4]
// 00467db0  8bce                 mov ecx, esi
// 00467db2  ffd2                 call edx
// 00467db4  8d4608               lea eax, [esi + 8]
// 00467db7  83c9ff               or ecx, 0xffffffff
// 00467dba  f00fc108             lock xadd dword ptr [eax], ecx
// 00467dbe  7509                 jne 0x467dc9
// 00467dc0  8b16                 mov edx, dword ptr [esi]
// 00467dc2  8b4208               mov eax, dword ptr [edx + 8]
// 00467dc5  8bce                 mov ecx, esi
// 00467dc7  ffd0                 call eax
// 00467dc9  84db                 test bl, bl
// 00467dcb  0f8426010000         je 0x467ef7
// 00467dd1  8d4c2414             lea ecx, [esp + 0x14]
// 00467dd5  51                   push ecx
// 00467dd6  e8e588fcff           call 0x4306c0
// 00467ddb  8b10                 mov edx, dword ptr [eax]
// 00467ddd  51                   push ecx
// 00467dde  8bcc                 mov ecx, esp
// 00467de0  8911                 mov dword ptr [ecx], edx
// 00467de2  8b4004               mov eax, dword ptr [eax + 4]
// 00467de5  c744244000000000     mov dword ptr [esp + 0x40], 0
// 00467ded  89642414             mov dword ptr [esp + 0x14], esp
// 00467df1  894104               mov dword ptr [ecx + 4], eax
// 00467df4  85c0                 test eax, eax
// 00467df6  740c                 je 0x467e04
// 00467df8  83c004               add eax, 4
// 00467dfb  b901000000           mov ecx, 1
// 00467e00  f00fc108             lock xadd dword ptr [eax], ecx
// 00467e04  8d4c242c             lea ecx, [esp + 0x2c]
// 00467e08  e8339dfaff           call 0x411b40
// 00467e0d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00467e11  b302                 mov bl, 2
// 00467e13  885c2438             mov byte ptr [esp + 0x38], bl
// 00467e17  85f6                 test esi, esi
// 00467e19  742a                 je 0x467e45
// 00467e1b  8d5604               lea edx, [esi + 4]
// 00467e1e  83c8ff               or eax, 0xffffffff
// 00467e21  f00fc102             lock xadd dword ptr [edx], eax
// 00467e25  751e                 jne 0x467e45
// 00467e27  8b16                 mov edx, dword ptr [esi]
// 00467e29  8b4204               mov eax, dword ptr [edx + 4]
// 00467e2c  8bce                 mov ecx, esi
// 00467e2e  ffd0                 call eax
// 00467e30  8d4e08               lea ecx, [esi + 8]
// 00467e33  83caff               or edx, 0xffffffff
// 00467e36  f00fc111             lock xadd dword ptr [ecx], edx
// 00467e3a  7509                 jne 0x467e45
// 00467e3c  8b06                 mov eax, dword ptr [esi]
// 00467e3e  8b5008               mov edx, dword ptr [eax + 8]
// 00467e41  8bce                 mov ecx, esi
// 00467e43  ffd2                 call edx
// 00467e45  83ec1c               sub esp, 0x1c
// 00467e48  8bcc                 mov ecx, esp
// 00467e4a  89642428             mov dword ptr [esp + 0x28], esp
// 00467e4e  68a4908100           push 0x8190a4
// 00467e53  ff1558248000         call dword ptr [0x802458]
// 00467e59  8d442438             lea eax, [esp + 0x38]
// 00467e5d  50                   push eax
// 00467e5e  e85d88fcff           call 0x4306c0
// 00467e63  83c404               add esp, 4
// 00467e66  8b00                 mov eax, dword ptr [eax]
// 00467e68  8d88c8010000         lea ecx, [eax + 0x1c8]
// 00467e6e  c644245403           mov byte ptr [esp + 0x54], 3
// 00467e73  e808b51100           call 0x583380
// 00467e78  8bf8                 mov edi, eax
// 00467e7a  8b442420             mov eax, dword ptr [esp + 0x20]
// 00467e7e  885c2438             mov byte ptr [esp + 0x38], bl
// 00467e82  85c0                 test eax, eax
// 00467e84  742c                 je 0x467eb2
// 00467e86  8bf0                 mov esi, eax
// 00467e88  83c004               add eax, 4
// 00467e8b  83c9ff               or ecx, 0xffffffff
// 00467e8e  f00fc108             lock xadd dword ptr [eax], ecx
// 00467e92  751e                 jne 0x467eb2
// 00467e94  8b16                 mov edx, dword ptr [esi]
// 00467e96  8b4204               mov eax, dword ptr [edx + 4]
// 00467e99  8bce                 mov ecx, esi
// 00467e9b  ffd0                 call eax
// 00467e9d  8d4e08               lea ecx, [esi + 8]
// 00467ea0  83caff               or edx, 0xffffffff
// 00467ea3  f00fc111             lock xadd dword ptr [ecx], edx
// 00467ea7  7509                 jne 0x467eb2
// 00467ea9  8b06                 mov eax, dword ptr [esi]
// 00467eab  8b5008               mov edx, dword ptr [eax + 8]
// 00467eae  8bce                 mov ecx, esi
// 00467eb0  ffd2                 call edx
// 00467eb2  85ff                 test edi, edi
// 00467eb4  7430                 je 0x467ee6
// 00467eb6  8b07                 mov eax, dword ptr [edi]
// 00467eb8  8b500c               mov edx, dword ptr [eax + 0xc]
// 00467ebb  8bcf                 mov ecx, edi
// 00467ebd  ffd2                 call edx
// 00467ebf  8d4c2424             lea ecx, [esp + 0x24]
// 00467ec3  8ad8                 mov bl, al
// 00467ec5  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 00467ecd  e8eef41000           call 0x5773c0
// 00467ed2  8ac3                 mov al, bl
// 00467ed4  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00467ed8  64890d00000000       mov dword ptr fs:[0], ecx
// 00467edf  5f                   pop edi
// 00467ee0  5e                   pop esi
// 00467ee1  5b                   pop ebx
// 00467ee2  83c430               add esp, 0x30
// 00467ee5  c3                   ret 
// 00467ee6  8d4c2424             lea ecx, [esp + 0x24]
// 00467eea  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 00467ef2  e8c9f41000           call 0x5773c0
// 00467ef7  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00467efb  5f                   pop edi
// 00467efc  5e                   pop esi
// 00467efd  b001                 mov al, 1
// 00467eff  64890d00000000       mov dword ptr fs:[0], ecx
// 00467f06  5b                   pop ebx
// 00467f07  83c430               add esp, 0x30
// 00467f0a  c3                   ret 

// from server: 93% by EspClaude
// roc 2008-06 00467d50  unit: DxUserInput
#include <string>
#include <intrin.h>

namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
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

class shared_count {
public:
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}

template<class T>
class shared_ptr {
    typedef shared_ptr<T> this_type;
public:
    T* px;
    detail::shared_count pn;
    shared_ptr() : px(0) {}
    template<class Y> shared_ptr(shared_ptr<Y> const& r) : px(r.px), pn(r.pn) {}
    T* operator->() const { return px; }
    T* get() const { return px; }
    typedef T* this_type::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &this_type::px; }
};
}

namespace RBX {
class DataModel {
public:
    char pad[0x1c8];
    struct VerbContainer { class Verb* getVerb(std::string name); } verbs;
    class scoped_write_request {
        void* a; void* b; void* c;
    public:
        scoped_write_request(boost::shared_ptr<DataModel> dataModel);
        ~scoped_write_request();
    };
};
}


namespace RBX {
class Game : public DataModel {};
class Verb {
public:
    virtual ~Verb();
    virtual void a();
    virtual bool isEnabled() const;
    virtual bool isChecked() const;
};
}

struct AFX_MODULE_STATE { void* reserved; struct CWinApp* m_pCurrentWinApp; };
AFX_MODULE_STATE* __stdcall AfxGetModuleState();
struct CWinApp { char pad[0x20]; struct CWnd* m_pMainWnd; };
struct CWnd { char pad[0x104]; bool flag; bool isFlag() const { return flag; } };
inline CWinApp* __stdcall AfxGetApp() { return AfxGetModuleState()->m_pCurrentWinApp; }

boost::shared_ptr<RBX::Game> getDataModel() throw();

class DxUserInput {
public:
    static bool isToolboxEnabled();
};

bool DxUserInput::isToolboxEnabled()
{
    CWnd* w = AfxGetApp()->m_pMainWnd;
    if (w->isFlag()) {
        if (!!getDataModel()) {
            RBX::DataModel::scoped_write_request request(getDataModel());
            RBX::Verb* verb = getDataModel()->verbs.getVerb("ToggleToolbox");
            if (verb)
                return verb->isChecked();
        }
    }
    return true;
}
