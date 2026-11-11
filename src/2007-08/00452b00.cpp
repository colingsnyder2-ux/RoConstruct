// from server: 99% by EspClaude
// from server: 77% by EspClaude
// roc 2007-08 00452b00  unit: CRobloxDoc  size: 1028 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00452b00
//
// 00452b00  6aff                 push -1
// 00452b02  685c127400           push 0x74125c
// 00452b07  64a100000000         mov eax, dword ptr fs:[0]
// 00452b0d  50                   push eax
// 00452b0e  81ec78010000         sub esp, 0x178
// 00452b14  a188518b00           mov eax, dword ptr [0x8b5188]
// 00452b19  33c4                 xor eax, esp
// 00452b1b  89842474010000       mov dword ptr [esp + 0x174], eax
// 00452b22  53                   push ebx
// 00452b23  55                   push ebp
// 00452b24  56                   push esi
// 00452b25  57                   push edi
// 00452b26  a188518b00           mov eax, dword ptr [0x8b5188]
// 00452b2b  33c4                 xor eax, esp
// 00452b2d  50                   push eax
// 00452b2e  8d84248c010000       lea eax, [esp + 0x18c]
// 00452b35  64a300000000         mov dword ptr fs:[0], eax
// 00452b3b  8be9                 mov ebp, ecx
// 00452b3d  33ff                 xor edi, edi
// 00452b3f  8d442418             lea eax, [esp + 0x18]
// 00452b43  897c2420             mov dword ptr [esp + 0x20], edi
// 00452b47  8b4d78               mov ecx, dword ptr [ebp + 0x78]
// 00452b4a  50                   push eax
// 00452b4b  e8b00cfbff           call 0x403800
// 00452b50  3938                 cmp dword ptr [eax], edi
// 00452b52  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00452b56  0f94c3               sete bl
// 00452b59  3bc7                 cmp eax, edi
// 00452b5b  742c                 je 0x452b89
// 00452b5d  8bf0                 mov esi, eax
// 00452b5f  83c004               add eax, 4
// 00452b62  83c9ff               or ecx, 0xffffffff
// 00452b65  f00fc108             lock xadd dword ptr [eax], ecx
// 00452b69  751e                 jne 0x452b89
// 00452b6b  8b16                 mov edx, dword ptr [esi]
// 00452b6d  8b4204               mov eax, dword ptr [edx + 4]
// 00452b70  8bce                 mov ecx, esi
// 00452b72  ffd0                 call eax
// 00452b74  8d4e08               lea ecx, [esi + 8]
// 00452b77  83caff               or edx, 0xffffffff
// 00452b7a  f00fc111             lock xadd dword ptr [ecx], edx
// 00452b7e  7509                 jne 0x452b89
// 00452b80  8b06                 mov eax, dword ptr [esi]
// 00452b82  8b5008               mov edx, dword ptr [eax + 8]
// 00452b85  8bce                 mov ecx, esi
// 00452b87  ffd2                 call edx
// 00452b89  84db                 test bl, bl
// 00452b8b  0f8589020000         jne 0x452e1a
// 00452b91  8b4500               mov eax, dword ptr [ebp]
// 00452b94  8b5060               mov edx, dword ptr [eax + 0x60]
// 00452b97  8bcd                 mov ecx, ebp
// 00452b99  ffd2                 call edx
// 00452b9b  85c0                 test eax, eax
// 00452b9d  0f8477020000         je 0x452e1a
// 00452ba3  8d442434             lea eax, [esp + 0x34]
// 00452ba7  50                   push eax
// 00452ba8  8bcd                 mov ecx, ebp
// 00452baa  e8810cfbff           call 0x403830
// 00452baf  8b10                 mov edx, dword ptr [eax]
// 00452bb1  83ec08               sub esp, 8
// 00452bb4  8bcc                 mov ecx, esp
// 00452bb6  8911                 mov dword ptr [ecx], edx
// 00452bb8  8b4004               mov eax, dword ptr [eax + 4]
// 00452bbb  3bc7                 cmp eax, edi
// 00452bbd  89bc249c010000       mov dword ptr [esp + 0x19c], edi
// 00452bc4  89642420             mov dword ptr [esp + 0x20], esp
// 00452bc8  894104               mov dword ptr [ecx + 4], eax
// 00452bcb  740c                 je 0x452bd9
// 00452bcd  83c004               add eax, 4
// 00452bd0  b901000000           mov ecx, 1
// 00452bd5  f00fc108             lock xadd dword ptr [eax], ecx
// 00452bd9  8d4c2430             lea ecx, [esp + 0x30]
// 00452bdd  e86ea9fbff           call 0x40d550
// 00452be2  8b742438             mov esi, dword ptr [esp + 0x38]
// 00452be6  3bf7                 cmp esi, edi
// 00452be8  c684249401000002     mov byte ptr [esp + 0x194], 2
// 00452bf0  742a                 je 0x452c1c
// 00452bf2  8d5604               lea edx, [esi + 4]
// 00452bf5  83c8ff               or eax, 0xffffffff
// 00452bf8  f00fc102             lock xadd dword ptr [edx], eax
// 00452bfc  751e                 jne 0x452c1c
// 00452bfe  8b16                 mov edx, dword ptr [esi]
// 00452c00  8b4204               mov eax, dword ptr [edx + 4]
// 00452c03  8bce                 mov ecx, esi
// 00452c05  ffd0                 call eax
// 00452c07  8d4e08               lea ecx, [esi + 8]
// 00452c0a  83caff               or edx, 0xffffffff
// 00452c0d  f00fc111             lock xadd dword ptr [ecx], edx
// 00452c11  7509                 jne 0x452c1c
// 00452c13  8b06                 mov eax, dword ptr [esi]
// 00452c15  8b5008               mov edx, dword ptr [eax + 8]
// 00452c18  8bce                 mov ecx, esi
// 00452c1a  ffd2                 call edx
// 00452c1c  8d442418             lea eax, [esp + 0x18]
// 00452c20  50                   push eax
// 00452c21  8bcd                 mov ecx, ebp
// 00452c23  e8080cfbff           call 0x403830
// 00452c28  8b08                 mov ecx, dword ptr [eax]
// 00452c2a  3bcf                 cmp ecx, edi
// 00452c2c  c684249401000003     mov byte ptr [esp + 0x194], 3
// 00452c34  7407                 je 0x452c3d
// 00452c36  e885e2ffff           call 0x450ec0
// 00452c3b  eb02                 jmp 0x452c3f
// 00452c3d  33c0                 xor eax, eax
// 00452c3f  bb01000000           mov ebx, 1
// 00452c44  39984c010000         cmp dword ptr [eax + 0x14c], ebx
// 00452c4a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00452c4e  0f94442417           sete byte ptr [esp + 0x17]
// 00452c53  3bc7                 cmp eax, edi
// 00452c55  c684249401000002     mov byte ptr [esp + 0x194], 2
// 00452c5d  742c                 je 0x452c8b
// 00452c5f  8bf0                 mov esi, eax
// 00452c61  83c004               add eax, 4
// 00452c64  83c9ff               or ecx, 0xffffffff
// 00452c67  f00fc108             lock xadd dword ptr [eax], ecx
// 00452c6b  751e                 jne 0x452c8b
// 00452c6d  8b16                 mov edx, dword ptr [esi]
// 00452c6f  8b4204               mov eax, dword ptr [edx + 4]
// 00452c72  8bce                 mov ecx, esi
// 00452c74  ffd0                 call eax
// 00452c76  8d4e08               lea ecx, [esi + 8]
// 00452c79  83caff               or edx, 0xffffffff
// 00452c7c  f00fc111             lock xadd dword ptr [ecx], edx
// 00452c80  7509                 jne 0x452c8b
// 00452c82  8b06                 mov eax, dword ptr [esi]
// 00452c84  8b5008               mov edx, dword ptr [eax + 8]
// 00452c87  8bce                 mov ecx, esi
// 00452c89  ffd2                 call edx
// 00452c8b  8d442418             lea eax, [esp + 0x18]
// 00452c8f  50                   push eax
// 00452c90  8bcd                 mov ecx, ebp
// 00452c92  e8990bfbff           call 0x403830
// 00452c97  8b08                 mov ecx, dword ptr [eax]
// 00452c99  3bcf                 cmp ecx, edi
// 00452c9b  c684249401000004     mov byte ptr [esp + 0x194], 4
// 00452ca3  7407                 je 0x452cac
// 00452ca5  e816e2ffff           call 0x450ec0
// 00452caa  eb02                 jmp 0x452cae
// 00452cac  33c0                 xor eax, eax
// 00452cae  6a02                 push 2
// 00452cb0  8bc8                 mov ecx, eax
// 00452cb2  e8c9aa0d00           call 0x52d780
// 00452cb7  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00452cbb  3bf7                 cmp esi, edi
// 00452cbd  c684249401000002     mov byte ptr [esp + 0x194], 2
// 00452cc5  742a                 je 0x452cf1
// 00452cc7  8d4e04               lea ecx, [esi + 4]
// 00452cca  83caff               or edx, 0xffffffff
// 00452ccd  f00fc111             lock xadd dword ptr [ecx], edx
// 00452cd1  751e                 jne 0x452cf1
// 00452cd3  8b06                 mov eax, dword ptr [esi]
// 00452cd5  8b5004               mov edx, dword ptr [eax + 4]
// 00452cd8  8bce                 mov ecx, esi
// 00452cda  ffd2                 call edx
// 00452cdc  8d4608               lea eax, [esi + 8]
// 00452cdf  83c9ff               or ecx, 0xffffffff
// 00452ce2  f00fc108             lock xadd dword ptr [eax], ecx
// 00452ce6  7509                 jne 0x452cf1
// 00452ce8  8b16                 mov edx, dword ptr [esi]
// 00452cea  8b4208               mov eax, dword ptr [edx + 8]
// 00452ced  8bce                 mov ecx, esi
// 00452cef  ffd0                 call eax
// 00452cf1  8d4c2418             lea ecx, [esp + 0x18]
// 00452cf5  51                   push ecx
// 00452cf6  8bcd                 mov ecx, ebp
// 00452cf8  e8330bfbff           call 0x403830
// 00452cfd  8b08                 mov ecx, dword ptr [eax]
// 00452cff  3bcf                 cmp ecx, edi
// 00452d01  c684249401000005     mov byte ptr [esp + 0x194], 5
// 00452d09  7407                 je 0x452d12
// 00452d0b  e830deffff           call 0x450b40
// 00452d10  8bf8                 mov edi, eax
// 00452d12  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00452d16  85f6                 test esi, esi
// 00452d18  c684249401000002     mov byte ptr [esp + 0x194], 2
// 00452d20  742a                 je 0x452d4c
// 00452d22  8d5604               lea edx, [esi + 4]
// 00452d25  83c8ff               or eax, 0xffffffff
// 00452d28  f00fc102             lock xadd dword ptr [edx], eax
// 00452d2c  751e                 jne 0x452d4c
// 00452d2e  8b16                 mov edx, dword ptr [esi]
// 00452d30  8b4204               mov eax, dword ptr [edx + 4]
// 00452d33  8bce                 mov ecx, esi
// 00452d35  ffd0                 call eax
// 00452d37  8d4e08               lea ecx, [esi + 8]
// 00452d3a  83caff               or edx, 0xffffffff
// 00452d3d  f00fc111             lock xadd dword ptr [ecx], edx
// 00452d41  7509                 jne 0x452d4c
// 00452d43  8b06                 mov eax, dword ptr [esi]
// 00452d45  8b5008               mov edx, dword ptr [eax + 8]
// 00452d48  8bce                 mov ecx, esi
// 00452d4a  ffd2                 call edx
// 00452d4c  85ff                 test edi, edi
// 00452d4e  742f                 je 0x452d7f
// 00452d50  8d44243c             lea eax, [esp + 0x3c]
// 00452d54  50                   push eax
// 00452d55  8bcf                 mov ecx, edi
// 00452d57  e874a2ffff           call 0x44cfd0
// 00452d5c  68081a7900           push 0x791a08
// 00452d61  50                   push eax
// 00452d62  c684249c01000006     mov byte ptr [esp + 0x19c], 6
// 00452d6a  895c2428             mov dword ptr [esp + 0x28], ebx
// 00452d6e  ff15f8e57700         call dword ptr [0x77e5f8]
// 00452d74  83c408               add esp, 8
// 00452d77  84c0                 test al, al
// 00452d79  7504                 jne 0x452d7f
// 00452d7b  32db                 xor bl, bl
// 00452d7d  eb02                 jmp 0x452d81
// 00452d7f  b301                 mov bl, 1
// 00452d81  f644242001           test byte ptr [esp + 0x20], 1
// 00452d86  c784249401000002000000 mov dword ptr [esp + 0x194], 2
// 00452d91  740a                 je 0x452d9d
// 00452d93  8d4c243c             lea ecx, [esp + 0x3c]
// 00452d97  ff15ace67700         call dword ptr [0x77e6ac]
// 00452d9d  84db                 test bl, bl
// 00452d9f  742e                 je 0x452dcf
// 00452da1  e82ad61d00           call 0x6303d0
// 00452da6  85c0                 test eax, eax
// 00452da8  740b                 je 0x452db5
// 00452daa  8b10                 mov edx, dword ptr [eax]
// 00452dac  8bc8                 mov ecx, eax
// 00452dae  8b427c               mov eax, dword ptr [edx + 0x7c]
// 00452db1  ffd0                 call eax
// 00452db3  eb02                 jmp 0x452db7
// 00452db5  33c0                 xor eax, eax
// 00452db7  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00452dba  51                   push ecx
// 00452dbb  ff15f0ec7700         call dword ptr [0x77ecf0]
// 00452dc1  8bcd                 mov ecx, ebp
// 00452dc3  e836db1d00           call 0x6308fe
// 00452dc8  8bf0                 mov esi, eax
// 00452dca  e9f7000000           jmp 0x452ec6
// 00452dcf  8d54243c             lea edx, [esp + 0x3c]
// 00452dd3  52                   push edx
// 00452dd4  8bcf                 mov ecx, edi
// 00452dd6  e8f5a1ffff           call 0x44cfd0
// 00452ddb  8bc8                 mov ecx, eax
// 00452ddd  c684249401000007     mov byte ptr [esp + 0x194], 7
// 00452de5  ff154ce67700         call dword ptr [0x77e64c]
// 00452deb  85c0                 test eax, eax
// 00452ded  8d4c243c             lea ecx, [esp + 0x3c]
// 00452df1  0f94c3               sete bl
// 00452df4  c684249401000002     mov byte ptr [esp + 0x194], 2
// 00452dfc  ff15ace67700         call dword ptr [0x77e6ac]
// 00452e02  84db                 test bl, bl
// 00452e04  741e                 je 0x452e24
// 00452e06  8d4c2428             lea ecx, [esp + 0x28]
// 00452e0a  c7842494010000ffffffff mov dword ptr [esp + 0x194], 0xffffffff
// 00452e15  e886671000           call 0x5595a0
// 00452e1a  b801000000           mov eax, 1
// 00452e1f  e9b8000000           jmp 0x452edc
// 00452e24  e8a7d51d00           call 0x6303d0
// 00452e29  85c0                 test eax, eax
// 00452e2b  740b                 je 0x452e38
// 00452e2d  8b10                 mov edx, dword ptr [eax]
// 00452e2f  8bc8                 mov ecx, eax
// 00452e31  8b427c               mov eax, dword ptr [edx + 0x7c]
// 00452e34  ffd0                 call eax
// 00452e36  eb02                 jmp 0x452e3a
// 00452e38  33c0                 xor eax, eax
// 00452e3a  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00452e3d  6a00                 push 0
// 00452e3f  51                   push ecx
// 00452e40  ff159ced7700         call dword ptr [0x77ed9c]
// 00452e46  8b5578               mov edx, dword ptr [ebp + 0x78]
// 00452e49  6a00                 push 0
// 00452e4b  52                   push edx
// 00452e4c  8d4c2460             lea ecx, [esp + 0x60]
// 00452e50  e85ba4ffff           call 0x44d2b0
// 00452e55  b308                 mov bl, 8
// 00452e57  8d4c2458             lea ecx, [esp + 0x58]
// 00452e5b  889c2494010000       mov byte ptr [esp + 0x194], bl
// 00452e62  e8c3cf1d00           call 0x62fe2a
// 00452e67  8bf0                 mov esi, eax
// 00452e69  83ee01               sub esi, 1
// 00452e6c  f7de                 neg esi
// 00452e6e  1bf6                 sbb esi, esi
// 00452e70  46                   inc esi
// 00452e71  7542                 jne 0x452eb5
// 00452e73  807c241700           cmp byte ptr [esp + 0x17], 0
// 00452e78  743b                 je 0x452eb5
// 00452e7a  8b4d78               mov ecx, dword ptr [ebp + 0x78]
// 00452e7d  8d442420             lea eax, [esp + 0x20]
// 00452e81  50                   push eax
// 00452e82  e87909fbff           call 0x403800
// 00452e87  8b08                 mov ecx, dword ptr [eax]
// 00452e89  85c9                 test ecx, ecx
// 00452e8b  c684249401000009     mov byte ptr [esp + 0x194], 9
// 00452e93  7407                 je 0x452e9c
// 00452e95  e826e0ffff           call 0x450ec0
// 00452e9a  eb02                 jmp 0x452e9e
// 00452e9c  33c0                 xor eax, eax
// 00452e9e  8bc8                 mov ecx, eax
// 00452ea0  e8cba0ffff           call 0x44cf70
// 00452ea5  8d4c2420             lea ecx, [esp + 0x20]
// 00452ea9  889c2494010000       mov byte ptr [esp + 0x194], bl
// 00452eb0  e8abf40300           call 0x492360
// 00452eb5  8d4c2458             lea ecx, [esp + 0x58]
// 00452eb9  c684249401000002     mov byte ptr [esp + 0x194], 2
// 00452ec1  e86a8d0000           call 0x45bc30
// 00452ec6  8d4c2428             lea ecx, [esp + 0x28]
// 00452eca  c7842494010000ffffffff mov dword ptr [esp + 0x194], 0xffffffff
// 00452ed5  e8c6661000           call 0x5595a0
// 00452eda  8bc6                 mov eax, esi
// 00452edc  8b8c248c010000       mov ecx, dword ptr [esp + 0x18c]
// 00452ee3  64890d00000000       mov dword ptr fs:[0], ecx
// 00452eea  59                   pop ecx
// 00452eeb  5f                   pop edi
// 00452eec  5e                   pop esi
// 00452eed  5d                   pop ebp
// 00452eee  5b                   pop ebx
// 00452eef  8b8c2474010000       mov ecx, dword ptr [esp + 0x174]
// 00452ef6  33cc                 xor ecx, esp
// 00452ef8  e821db1d00           call 0x630a1e
// 00452efd  81c484010000         add esp, 0x184
// 00452f03  c3                   ret 

// from server: 100% by EspClaude
#include <intrin.h>
#include <vector>

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

namespace RBX {
class RunService { public: char pad[0x14c]; int runState; void setRunState(int s); void run(); };
class Visit { public: string_ getUploadUrl() const; };
class ServiceProvider {
public:
    virtual ~ServiceProvider();
    template<class T> T* findServiceT() const;
    template<class T> static T* find(const ServiceProvider* context)
    {
        return context ? context->findServiceT<T>() : 0;
    }
};
class DataModel : public ServiceProvider {};
class ReadRequest {
public:
    ReadRequest(boost::shared_ptr<const DataModel> dm);
    ~ReadRequest();
    void* a; void* b;
};
}
extern "C" __declspec(dllimport) int __stdcall SetForegroundWindow(void* hWnd);
extern "C" __declspec(dllimport) int __stdcall FlashWindow(void* hWnd, int bInvert);

class CWnd { public: virtual ~CWnd(); char pad[0x1c]; void* m_hWnd; };
class CWinThread { public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual CWnd* GetMainWnd();
};
CWinThread* __stdcall AfxGetThread();
inline CWnd* AfxGetMainWnd()
{
    CWinThread* pThread = AfxGetThread();
    return pThread != 0 ? pThread->GetMainWnd() : 0;
}

class CRobloxView { public: boost::shared_ptr<RBX::DataModel> getDataModel(); };
class CPublishDialog {
public:
    CPublishDialog(CRobloxView* view, CWnd* parent = 0);
    ~CPublishDialog();
    int DoModal();
    char data[0x130];
};

class CDocument {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual int IsModified();
    int SaveModified();
};

class CRobloxDoc : public CDocument {
public:
    char pad[0x74];
    CRobloxView* view;
    boost::shared_ptr<RBX::DataModel> getDataModel();
    int SaveModified();
};

int CRobloxDoc::SaveModified()
{
    if (!view->getDataModel())
        return 1;
    if (!IsModified())
        return 1;
    RBX::ReadRequest request(getDataModel());
    bool wasRunning = RBX::ServiceProvider::find<RBX::RunService>(getDataModel().get())->runState == 1;
    RBX::ServiceProvider::find<RBX::RunService>(getDataModel().get())->setRunState(2);
    RBX::Visit* visit = RBX::ServiceProvider::find<RBX::Visit>(getDataModel().get());
    if (!visit || visit->getUploadUrl() == "NoVisit") {
        SetForegroundWindow(AfxGetMainWnd()->m_hWnd);
        return CDocument::SaveModified();
    }
    if (visit->getUploadUrl().size() == 0)
        return 1;
    FlashWindow(AfxGetMainWnd()->m_hWnd, 0);
    CPublishDialog dlg(view, 0);
    int result = dlg.DoModal() == 1;
    if (!result && wasRunning)
        RBX::ServiceProvider::find<RBX::RunService>(view->getDataModel().get())->run();
    return result;
}
