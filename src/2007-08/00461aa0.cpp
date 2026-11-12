// from server: 100% by EspClaude
// from server: 41% by colin
// roc 2007-08 00461aa0  unit: CScriptEditor  size: 383 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00461aa0
//
// 00461aa0  6aff                 push -1
// 00461aa2  68ab2a7400           push 0x742aab
// 00461aa7  64a100000000         mov eax, dword ptr fs:[0]
// 00461aad  50                   push eax
// 00461aae  83ec14               sub esp, 0x14
// 00461ab1  53                   push ebx
// 00461ab2  55                   push ebp
// 00461ab3  56                   push esi
// 00461ab4  57                   push edi
// 00461ab5  a188518b00           mov eax, dword ptr [0x8b5188]
// 00461aba  33c4                 xor eax, esp
// 00461abc  50                   push eax
// 00461abd  8d442428             lea eax, [esp + 0x28]
// 00461ac1  64a300000000         mov dword ptr fs:[0], eax
// 00461ac7  8bf1                 mov esi, ecx
// 00461ac9  89742420             mov dword ptr [esp + 0x20], esi
// 00461acd  8d9ef0000000         lea ebx, [esi + 0xf0]
// 00461ad3  8dae0c010000         lea ebp, [esi + 0x10c]
// 00461ad9  c706d44b7900         mov dword ptr [esi], 0x794bd4
// 00461adf  c786ec000000c84b7900 mov dword ptr [esi + 0xec], 0x794bc8
// 00461ae9  c703b44b7900         mov dword ptr [ebx], 0x794bb4
// 00461aef  c74500a04b7900       mov dword ptr [ebp], 0x794ba0
// 00461af6  83ec08               sub esp, 8
// 00461af9  8bc4                 mov eax, esp
// 00461afb  c70000000000         mov dword ptr [eax], 0
// 00461b01  c744243807000000     mov dword ptr [esp + 0x38], 7
// 00461b09  8964242c             mov dword ptr [esp + 0x2c], esp
// 00461b0d  c7400400000000       mov dword ptr [eax + 4], 0
// 00461b14  e8b7fbffff           call 0x4616d0
// 00461b19  8d8e48010000         lea ecx, [esi + 0x148]
// 00461b1f  c644243006           mov byte ptr [esp + 0x30], 6
// 00461b24  c701c8647800         mov dword ptr [ecx], 0x7864c8
// 00461b2a  e8fde61c00           call 0x63022c
// 00461b2f  8bbe40010000         mov edi, dword ptr [esi + 0x140]
// 00461b35  85ff                 test edi, edi
// 00461b37  c644243005           mov byte ptr [esp + 0x30], 5
// 00461b3c  742a                 je 0x461b68
// 00461b3e  8d4704               lea eax, [edi + 4]
// 00461b41  83c9ff               or ecx, 0xffffffff
// 00461b44  f00fc108             lock xadd dword ptr [eax], ecx
// 00461b48  751e                 jne 0x461b68
// 00461b4a  8b17                 mov edx, dword ptr [edi]
// 00461b4c  8b4204               mov eax, dword ptr [edx + 4]
// 00461b4f  8bcf                 mov ecx, edi
// 00461b51  ffd0                 call eax
// 00461b53  8d4f08               lea ecx, [edi + 8]
// 00461b56  83caff               or edx, 0xffffffff
// 00461b59  f00fc111             lock xadd dword ptr [ecx], edx
// 00461b5d  7509                 jne 0x461b68
// 00461b5f  8b07                 mov eax, dword ptr [edi]
// 00461b61  8b5008               mov edx, dword ptr [eax + 8]
// 00461b64  8bcf                 mov ecx, edi
// 00461b66  ffd2                 call edx
// 00461b68  8bbe38010000         mov edi, dword ptr [esi + 0x138]
// 00461b6e  85ff                 test edi, edi
// 00461b70  c644243004           mov byte ptr [esp + 0x30], 4
// 00461b75  742a                 je 0x461ba1
// 00461b77  8d4704               lea eax, [edi + 4]
// 00461b7a  83c9ff               or ecx, 0xffffffff
// 00461b7d  f00fc108             lock xadd dword ptr [eax], ecx
// 00461b81  751e                 jne 0x461ba1
// 00461b83  8b17                 mov edx, dword ptr [edi]
// 00461b85  8b4204               mov eax, dword ptr [edx + 4]
// 00461b88  8bcf                 mov ecx, edi
// 00461b8a  ffd0                 call eax
// 00461b8c  8d4f08               lea ecx, [edi + 8]
// 00461b8f  83caff               or edx, 0xffffffff
// 00461b92  f00fc111             lock xadd dword ptr [ecx], edx
// 00461b96  7509                 jne 0x461ba1
// 00461b98  8b07                 mov eax, dword ptr [edi]
// 00461b9a  8b5008               mov edx, dword ptr [eax + 8]
// 00461b9d  8bcf                 mov ecx, edi
// 00461b9f  ffd2                 call edx
// 00461ba1  8bbe2c010000         mov edi, dword ptr [esi + 0x12c]
// 00461ba7  85ff                 test edi, edi
// 00461ba9  c644243003           mov byte ptr [esp + 0x30], 3
// 00461bae  742a                 je 0x461bda
// 00461bb0  8d4704               lea eax, [edi + 4]
// 00461bb3  83c9ff               or ecx, 0xffffffff
// 00461bb6  f00fc108             lock xadd dword ptr [eax], ecx
// 00461bba  751e                 jne 0x461bda
// 00461bbc  8b17                 mov edx, dword ptr [edi]
// 00461bbe  8b4204               mov eax, dword ptr [edx + 4]
// 00461bc1  8bcf                 mov ecx, edi
// 00461bc3  ffd0                 call eax
// 00461bc5  8d4f08               lea ecx, [edi + 8]
// 00461bc8  83caff               or edx, 0xffffffff
// 00461bcb  f00fc111             lock xadd dword ptr [ecx], edx
// 00461bcf  7509                 jne 0x461bda
// 00461bd1  8b07                 mov eax, dword ptr [edi]
// 00461bd3  8b5008               mov edx, dword ptr [eax + 8]
// 00461bd6  8bcf                 mov ecx, edi
// 00461bd8  ffd2                 call edx
// 00461bda  8bcd                 mov ecx, ebp
// 00461bdc  c644243002           mov byte ptr [esp + 0x30], 2
// 00461be1  e8aaf0ffff           call 0x460c90
// 00461be6  8bcb                 mov ecx, ebx
// 00461be8  c644243001           mov byte ptr [esp + 0x30], 1
// 00461bed  e80ef0ffff           call 0x460c00
// 00461bf2  8bce                 mov ecx, esi
// 00461bf4  c786ec000000204a7900 mov dword ptr [esi + 0xec], 0x794a20
// 00461bfe  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 00461c06  e885c3ffff           call 0x45df90
// 00461c0b  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00461c0f  64890d00000000       mov dword ptr fs:[0], ecx
// 00461c16  59                   pop ecx
// 00461c17  5f                   pop edi
// 00461c18  5e                   pop esi
// 00461c19  5d                   pop ebp
// 00461c1a  5b                   pop ebx
// 00461c1b  83c420               add esp, 0x20
// 00461c1e  c3                   ret 
// roc-cl: 50727
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
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};

class shared_count {
public:
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) _InterlockedIncrement(&pi_->use_count_); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}

template<class T>
class shared_ptr {
public:
    shared_ptr() : px(0), pn() {}
    T* px;
    detail::shared_count pn;
};
}

class CGdiObject {
public:
    virtual ~CGdiObject();
    void* m_hObject;
};

class CFont : public CGdiObject {
public:
    virtual ~CFont() {}
};

class EditorBase {
public:
    virtual ~EditorBase();
    char pad_04[0xec - 4];
};

class EditorIface {
public:
    virtual ~EditorIface() {}
};

class ListenerA {
public:
    virtual ~ListenerA();
    char pad_04[0x1c - 4];
};

class ListenerB {
public:
    virtual ~ListenerB();
    char pad_04[0x1c - 4];
};

class Script;
class Thing;

class CScriptEditor : public EditorBase, public EditorIface, public ListenerA, public ListenerB {
public:
    boost::shared_ptr<Thing> m_128;
    int m_130;
    boost::shared_ptr<Thing> m_134;
    boost::shared_ptr<Thing> m_13c;
    int m_144;
    CFont m_148;

    void setScript(boost::shared_ptr<Script> script);
    virtual ~CScriptEditor();
};

CScriptEditor::~CScriptEditor()
{
    setScript(boost::shared_ptr<Script>());
}
