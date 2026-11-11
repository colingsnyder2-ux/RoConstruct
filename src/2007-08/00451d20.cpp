// from server: 100% by EspClaude
// from server: 90% by EspClaude
// roc 2007-08 00451d20  unit: ReportAbuseVerb  size: 511 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00451d20
//
// 00451d20  6aff                 push -1
// 00451d22  68a90f7400           push 0x740fa9
// 00451d27  64a100000000         mov eax, dword ptr fs:[0]
// 00451d2d  50                   push eax
// 00451d2e  83ec44               sub esp, 0x44
// 00451d31  a188518b00           mov eax, dword ptr [0x8b5188]
// 00451d36  33c4                 xor eax, esp
// 00451d38  89442440             mov dword ptr [esp + 0x40], eax
// 00451d3c  56                   push esi
// 00451d3d  57                   push edi
// 00451d3e  a188518b00           mov eax, dword ptr [0x8b5188]
// 00451d43  33c4                 xor eax, esp
// 00451d45  50                   push eax
// 00451d46  8d442450             lea eax, [esp + 0x50]
// 00451d4a  64a300000000         mov dword ptr fs:[0], eax
// 00451d50  8bf1                 mov esi, ecx
// 00451d52  8b4e78               mov ecx, dword ptr [esi + 0x78]
// 00451d55  8d44241c             lea eax, [esp + 0x1c]
// 00451d59  50                   push eax
// 00451d5a  e8a11afbff           call 0x403800
// 00451d5f  8b10                 mov edx, dword ptr [eax]
// 00451d61  83ec08               sub esp, 8
// 00451d64  8bcc                 mov ecx, esp
// 00451d66  8911                 mov dword ptr [ecx], edx
// 00451d68  8b4004               mov eax, dword ptr [eax + 4]
// 00451d6b  85c0                 test eax, eax
// 00451d6d  c744246000000000     mov dword ptr [esp + 0x60], 0
// 00451d75  89642414             mov dword ptr [esp + 0x14], esp
// 00451d79  894104               mov dword ptr [ecx + 4], eax
// 00451d7c  740c                 je 0x451d8a
// 00451d7e  83c004               add eax, 4
// 00451d81  b901000000           mov ecx, 1
// 00451d86  f00fc108             lock xadd dword ptr [eax], ecx
// 00451d8a  8d4c242c             lea ecx, [esp + 0x2c]
// 00451d8e  e8bdb7fbff           call 0x40d550
// 00451d93  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00451d97  85ff                 test edi, edi
// 00451d99  c644245802           mov byte ptr [esp + 0x58], 2
// 00451d9e  742a                 je 0x451dca
// 00451da0  8d5704               lea edx, [edi + 4]
// 00451da3  83c8ff               or eax, 0xffffffff
// 00451da6  f00fc102             lock xadd dword ptr [edx], eax
// 00451daa  751e                 jne 0x451dca
// 00451dac  8b17                 mov edx, dword ptr [edi]
// 00451dae  8b4204               mov eax, dword ptr [edx + 4]
// 00451db1  8bcf                 mov ecx, edi
// 00451db3  ffd0                 call eax
// 00451db5  8d4f08               lea ecx, [edi + 8]
// 00451db8  83caff               or edx, 0xffffffff
// 00451dbb  f00fc111             lock xadd dword ptr [ecx], edx
// 00451dbf  7509                 jne 0x451dca
// 00451dc1  8b07                 mov eax, dword ptr [edi]
// 00451dc3  8b5008               mov edx, dword ptr [eax + 8]
// 00451dc6  8bcf                 mov ecx, edi
// 00451dc8  ffd2                 call edx
// 00451dca  8d442410             lea eax, [esp + 0x10]
// 00451dce  50                   push eax
// 00451dcf  8bce                 mov ecx, esi
// 00451dd1  e85a1afbff           call 0x403830
// 00451dd6  8b08                 mov ecx, dword ptr [eax]
// 00451dd8  85c9                 test ecx, ecx
// 00451dda  c644245803           mov byte ptr [esp + 0x58], 3
// 00451ddf  7409                 je 0x451dea
// 00451de1  e82ac6fdff           call 0x42e410
// 00451de6  8bf0                 mov esi, eax
// 00451de8  eb02                 jmp 0x451dec
// 00451dea  33f6                 xor esi, esi
// 00451dec  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00451df0  85ff                 test edi, edi
// 00451df2  c644245802           mov byte ptr [esp + 0x58], 2
// 00451df7  742a                 je 0x451e23
// 00451df9  8d4f04               lea ecx, [edi + 4]
// 00451dfc  83caff               or edx, 0xffffffff
// 00451dff  f00fc111             lock xadd dword ptr [ecx], edx
// 00451e03  751e                 jne 0x451e23
// 00451e05  8b07                 mov eax, dword ptr [edi]
// 00451e07  8b5004               mov edx, dword ptr [eax + 4]
// 00451e0a  8bcf                 mov ecx, edi
// 00451e0c  ffd2                 call edx
// 00451e0e  8d4708               lea eax, [edi + 8]
// 00451e11  83c9ff               or ecx, 0xffffffff
// 00451e14  f00fc108             lock xadd dword ptr [eax], ecx
// 00451e18  7509                 jne 0x451e23
// 00451e1a  8b17                 mov edx, dword ptr [edi]
// 00451e1c  8b4208               mov eax, dword ptr [edx + 8]
// 00451e1f  8bcf                 mov ecx, edi
// 00451e21  ffd0                 call eax
// 00451e23  85f6                 test esi, esi
// 00451e25  0f84c6000000         je 0x451ef1
// 00451e2b  83be5001000000       cmp dword ptr [esi + 0x150], 0
// 00451e32  0f84b9000000         je 0x451ef1
// 00451e38  8bce                 mov ecx, esi
// 00451e3a  e891210e00           call 0x533fd0
// 00451e3f  8b8e50010000         mov ecx, dword ptr [esi + 0x150]
// 00451e45  8d54240c             lea edx, [esp + 0xc]
// 00451e49  52                   push edx
// 00451e4a  8d44241c             lea eax, [esp + 0x1c]
// 00451e4e  50                   push eax
// 00451e4f  e8ac461400           call 0x596500
// 00451e54  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00451e58  51                   push ecx
// 00451e59  8d542434             lea edx, [esp + 0x34]
// 00451e5d  52                   push edx
// 00451e5e  e86de01200           call 0x57fed0
// 00451e63  83c408               add esp, 8
// 00451e66  8bce                 mov ecx, esi
// 00451e68  c644245804           mov byte ptr [esp + 0x58], 4
// 00451e6d  e87e2f0e00           call 0x534df0
// 00451e72  8bf0                 mov esi, eax
// 00451e74  8d442410             lea eax, [esp + 0x10]
// 00451e78  50                   push eax
// 00451e79  e832a51100           call 0x56c3b0
// 00451e7e  83c404               add esp, 4
// 00451e81  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00451e85  8b38                 mov edi, dword ptr [eax]
// 00451e87  56                   push esi
// 00451e88  51                   push ecx
// 00451e89  8d4c2438             lea ecx, [esp + 0x38]
// 00451e8d  c644246005           mov byte ptr [esp + 0x60], 5
// 00451e92  ff15a8e67700         call dword ptr [0x77e6a8]
// 00451e98  50                   push eax
// 00451e99  68c4197900           push 0x7919c4
// 00451e9e  6a01                 push 1
// 00451ea0  57                   push edi
// 00451ea1  e8faa11100           call 0x56c0a0
// 00451ea6  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00451eaa  83c418               add esp, 0x18
// 00451ead  85c0                 test eax, eax
// 00451eaf  c644245804           mov byte ptr [esp + 0x58], 4
// 00451eb4  742c                 je 0x451ee2
// 00451eb6  8bf0                 mov esi, eax
// 00451eb8  83c004               add eax, 4
// 00451ebb  83caff               or edx, 0xffffffff
// 00451ebe  f00fc110             lock xadd dword ptr [eax], edx
// 00451ec2  751e                 jne 0x451ee2
// 00451ec4  8b06                 mov eax, dword ptr [esi]
// 00451ec6  8b5004               mov edx, dword ptr [eax + 4]
// 00451ec9  8bce                 mov ecx, esi
// 00451ecb  ffd2                 call edx
// 00451ecd  8d4608               lea eax, [esi + 8]
// 00451ed0  83c9ff               or ecx, 0xffffffff
// 00451ed3  f00fc108             lock xadd dword ptr [eax], ecx
// 00451ed7  7509                 jne 0x451ee2
// 00451ed9  8b16                 mov edx, dword ptr [esi]
// 00451edb  8b4208               mov eax, dword ptr [edx + 8]
// 00451ede  8bce                 mov ecx, esi
// 00451ee0  ffd0                 call eax
// 00451ee2  8d4c2430             lea ecx, [esp + 0x30]
// 00451ee6  c644245802           mov byte ptr [esp + 0x58], 2
// 00451eeb  ff15ace67700         call dword ptr [0x77e6ac]
// 00451ef1  8d4c2424             lea ecx, [esp + 0x24]
// 00451ef5  c7442458ffffffff     mov dword ptr [esp + 0x58], 0xffffffff
// 00451efd  e89e761000           call 0x5595a0
// 00451f02  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 00451f06  64890d00000000       mov dword ptr fs:[0], ecx
// 00451f0d  59                   pop ecx
// 00451f0e  5f                   pop edi
// 00451f0f  5e                   pop esi
// 00451f10  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00451f14  33cc                 xor ecx, esp
// 00451f16  e803eb1d00           call 0x630a1e
// 00451f1b  83c450               add esp, 0x50
// 00451f1e  c3                   ret 

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
#include <intrin.h>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
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
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> class shared_ptr {
public:
    typedef T* shared_ptr::*unspecified_bool_type;
    T* px;
    shared_count pn;
    template<class Y> shared_ptr(shared_ptr<Y> const& r) : px(r.px), pn(r.pn) {}
    T* operator->() const { return px; }
    T* get() const { return px; }
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
};

class String {
public:
    __declspec(dllimport) const char* c_str() const;
    __declspec(dllimport) ~String();
    char storage[0x1c];
};

namespace RBX {
class ServiceProvider {
public:
    template<class Class> Class* create() const;
    template<class Class>
    static Class* create(const ServiceProvider* serviceProvider)
    {
        if (serviceProvider)
            return serviceProvider->create<Class>();
        return 0;
    }
};

class DataModel : public ServiceProvider {
public:
    class scoped_lock {
    public:
        scoped_lock(shared_ptr<const DataModel> dm);
        ~scoped_lock();
        int a, b, c;
    };
};

class LuaAllocator {
public:
    void getHeapStats(unsigned int& bytes, unsigned int& blocks) const;
};

template<class T> class scoped_ptr {
public:
    T* ptr;
    typedef T* scoped_ptr::*unspecified_bool_type;
    T* operator->() const { return ptr; }
    operator unspecified_bool_type() const { return ptr == 0 ? 0 : &scoped_ptr::ptr; }
};

class ScriptContext {
public:
    char pad[0x150];
    scoped_ptr<LuaAllocator> allocator;
    void gc();
    unsigned int getThreadCount() const;
};

String memoryString(unsigned int bytes);

enum MessageType { MESSAGE_OUTPUT, MESSAGE_INFO };
class StandardOut {
public:
    static shared_ptr<StandardOut> singleton();
    void print(MessageType type, const char* format, ...);
};
}

class RobloxDocument {
public:
    shared_ptr<RBX::DataModel> getDataModel() const;
};

class CRobloxDoc {
public:
    char pad[0x78];
    RobloxDocument* document;
    shared_ptr<RBX::DataModel> getDataModel() const;
    void OnScriptHeap();
};

void CRobloxDoc::OnScriptHeap()
{
    RBX::DataModel::scoped_lock lock(document->getDataModel());
    RBX::ScriptContext* sc = RBX::ServiceProvider::create<RBX::ScriptContext>(getDataModel().get());
    if (sc && sc->allocator)
    {
        sc->gc();
        unsigned int bytes, blocks;
        sc->allocator->getHeapStats(bytes, blocks);
        String heap = RBX::memoryString(bytes);
        unsigned int threads = sc->getThreadCount();
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_INFO, "Script heap %s (%d blocks), %d threads", heap.c_str(), blocks, threads);
    }
}
