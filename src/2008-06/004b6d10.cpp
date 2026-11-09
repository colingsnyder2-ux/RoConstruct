// from server: 100% by coldek
// from server: 98% by Espeon
// roc 2008-06 004b6d10  unit: RBX::Network::Replicator::ChangePropertyItem  size: 490 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004b6d10
//
// 004b6d10  6aff                 push -1
// 004b6d12  68e18a7c00           push 0x7c8ae1
// 004b6d17  64a100000000         mov eax, dword ptr fs:[0]
// 004b6d1d  50                   push eax
// 004b6d1e  64892500000000       mov dword ptr fs:[0], esp
// 004b6d25  83ec30               sub esp, 0x30
// 004b6d28  53                   push ebx
// 004b6d29  55                   push ebp
// 004b6d2a  56                   push esi
// 004b6d2b  8bf1                 mov esi, ecx
// 004b6d2d  8b460c               mov eax, dword ptr [esi + 0xc]
// 004b6d30  89442410             mov dword ptr [esp + 0x10], eax
// 004b6d34  8b4604               mov eax, dword ptr [esi + 4]
// 004b6d37  8ba8502c0000         mov ebp, dword ptr [eax + 0x2c50]
// 004b6d3d  8b98382c0000         mov ebx, dword ptr [eax + 0x2c38]
// 004b6d43  57                   push edi
// 004b6d44  8d88382c0000         lea ecx, [eax + 0x2c38]
// 004b6d4a  8d542414             lea edx, [esp + 0x14]
// 004b6d4e  52                   push edx
// 004b6d4f  8d442420             lea eax, [esp + 0x20]
// 004b6d53  50                   push eax
// 004b6d54  e87772ffff           call 0x4adfd0
// 004b6d59  8bf8                 mov edi, eax
// 004b6d5b  8b07                 mov eax, dword ptr [edi]
// 004b6d5d  85c0                 test eax, eax
// 004b6d5f  7404                 je 0x4b6d65
// 004b6d61  3bc3                 cmp eax, ebx
// 004b6d63  7406                 je 0x4b6d6b
// 004b6d65  ff1590288000         call dword ptr [0x802890]
// 004b6d6b  396f04               cmp dword ptr [edi + 4], ebp
// 004b6d6e  0f8471010000         je 0x4b6ee5
// 004b6d74  8b7c2450             mov edi, dword ptr [esp + 0x50]
// 004b6d78  6a03                 push 3
// 004b6d7a  57                   push edi
// 004b6d7b  e85048ffff           call 0x4ab5d0
// 004b6d80  8b460c               mov eax, dword ptr [esi + 0xc]
// 004b6d83  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b6d86  83c408               add esp, 8
// 004b6d89  50                   push eax
// 004b6d8a  57                   push edi
// 004b6d8b  e8501dffff           call 0x4a8ae0
// 004b6d90  8b4e08               mov ecx, dword ptr [esi + 8]
// 004b6d93  51                   push ecx
// 004b6d94  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b6d97  57                   push edi
// 004b6d98  81c1f42b0000         add ecx, 0x2bf4
// 004b6d9e  e8fd7dffff           call 0x4aeba0
// 004b6da3  e8e87afeff           call 0x49e890
// 004b6da8  80b83201000000       cmp byte ptr [eax + 0x132], 0
// 004b6daf  0f8407010000         je 0x4b6ebc
// 004b6db5  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004b6db8  8bcf                 mov ecx, edi
// 004b6dba  8d6f10               lea ebp, [edi + 0x10]
// 004b6dbd  e8de4dfeff           call 0x49bba0
// 004b6dc2  6a04                 push 4
// 004b6dc4  8d542428             lea edx, [esp + 0x28]
// 004b6dc8  52                   push edx
// 004b6dc9  8d4f08               lea ecx, [edi + 8]
// 004b6dcc  e8ff3fffff           call 0x4aadd0
// 004b6dd1  8bf8                 mov edi, eax
// 004b6dd3  8d44241c             lea eax, [esp + 0x1c]
// 004b6dd7  50                   push eax
// 004b6dd8  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 004b6de0  e83b280b00           call 0x569620
// 004b6de5  83c404               add esp, 4
// 004b6de8  8bd8                 mov ebx, eax
// 004b6dea  8b4e08               mov ecx, dword ptr [esi + 8]
// 004b6ded  8b4104               mov eax, dword ptr [ecx + 4]
// 004b6df0  83c004               add eax, 4
// 004b6df3  b910000000           mov ecx, 0x10
// 004b6df8  c644244801           mov byte ptr [esp + 0x48], 1
// 004b6dfd  394818               cmp dword ptr [eax + 0x18], ecx
// 004b6e00  7209                 jb 0x4b6e0b
// 004b6e02  8b5004               mov edx, dword ptr [eax + 4]
// 004b6e05  89542410             mov dword ptr [esp + 0x10], edx
// 004b6e09  eb07                 jmp 0x4b6e12
// 004b6e0b  83c004               add eax, 4
// 004b6e0e  89442410             mov dword ptr [esp + 0x10], eax
// 004b6e12  394f18               cmp dword ptr [edi + 0x18], ecx
// 004b6e15  7209                 jb 0x4b6e20
// 004b6e17  8b4704               mov eax, dword ptr [edi + 4]
// 004b6e1a  89442414             mov dword ptr [esp + 0x14], eax
// 004b6e1e  eb07                 jmp 0x4b6e27
// 004b6e20  83c704               add edi, 4
// 004b6e23  897c2414             mov dword ptr [esp + 0x14], edi
// 004b6e27  8b5500               mov edx, dword ptr [ebp]
// 004b6e2a  8b4204               mov eax, dword ptr [edx + 4]
// 004b6e2d  8bcd                 mov ecx, ebp
// 004b6e2f  ffd0                 call eax
// 004b6e31  83781c10             cmp dword ptr [eax + 0x1c], 0x10
// 004b6e35  7205                 jb 0x4b6e3c
// 004b6e37  8b6808               mov ebp, dword ptr [eax + 8]
// 004b6e3a  eb03                 jmp 0x4b6e3f
// 004b6e3c  8d6808               lea ebp, [eax + 8]
// 004b6e3f  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b6e42  8b3b                 mov edi, dword ptr [ebx]
// 004b6e44  6a01                 push 1
// 004b6e46  81c1542d0000         add ecx, 0x2d54
// 004b6e4c  e85f2affff           call 0x4a98b0
// 004b6e51  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004b6e55  8b542414             mov edx, dword ptr [esp + 0x14]
// 004b6e59  50                   push eax
// 004b6e5a  51                   push ecx
// 004b6e5b  52                   push edx
// 004b6e5c  55                   push ebp
// 004b6e5d  681c508200           push 0x82501c
// 004b6e62  6a01                 push 1
// 004b6e64  57                   push edi
// 004b6e65  e836250b00           call 0x5693a0
// 004b6e6a  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 004b6e6e  83c41c               add esp, 0x1c
// 004b6e71  c644244800           mov byte ptr [esp + 0x48], 0
// 004b6e76  85c0                 test eax, eax
// 004b6e78  742c                 je 0x4b6ea6
// 004b6e7a  8bf8                 mov edi, eax
// 004b6e7c  83c004               add eax, 4
// 004b6e7f  83c9ff               or ecx, 0xffffffff
// 004b6e82  f00fc108             lock xadd dword ptr [eax], ecx
// 004b6e86  751e                 jne 0x4b6ea6
// 004b6e88  8b17                 mov edx, dword ptr [edi]
// 004b6e8a  8b4204               mov eax, dword ptr [edx + 4]
// 004b6e8d  8bcf                 mov ecx, edi
// 004b6e8f  ffd0                 call eax
// 004b6e91  8d4f08               lea ecx, [edi + 8]
// 004b6e94  83caff               or edx, 0xffffffff
// 004b6e97  f00fc111             lock xadd dword ptr [ecx], edx
// 004b6e9b  7509                 jne 0x4b6ea6
// 004b6e9d  8b07                 mov eax, dword ptr [edi]
// 004b6e9f  8b5008               mov edx, dword ptr [eax + 8]
// 004b6ea2  8bcf                 mov ecx, edi
// 004b6ea4  ffd2                 call edx
// 004b6ea6  8d4c2424             lea ecx, [esp + 0x24]
// 004b6eaa  c7442448ffffffff     mov dword ptr [esp + 0x48], 0xffffffff
// 004b6eb2  ff1568248000         call dword ptr [0x802468]
// 004b6eb8  8b7c2450             mov edi, dword ptr [esp + 0x50]
// 004b6ebc  8b460c               mov eax, dword ptr [esi + 0xc]
// 004b6ebf  85c0                 test eax, eax
// 004b6ec1  7405                 je 0x4b6ec8
// 004b6ec3  83c014               add eax, 0x14
// 004b6ec6  eb02                 jmp 0x4b6eca
// 004b6ec8  33c0                 xor eax, eax
// 004b6eca  8b4e08               mov ecx, dword ptr [esi + 8]
// 004b6ecd  57                   push edi
// 004b6ece  6a01                 push 1
// 004b6ed0  8d54241c             lea edx, [esp + 0x1c]
// 004b6ed4  894c241c             mov dword ptr [esp + 0x1c], ecx
// 004b6ed8  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b6edb  52                   push edx
// 004b6edc  89442424             mov dword ptr [esp + 0x24], eax
// 004b6ee0  e8abf9ffff           call 0x4b6890
// 004b6ee5  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 004b6ee9  5f                   pop edi
// 004b6eea  5e                   pop esi
// 004b6eeb  5d                   pop ebp
// 004b6eec  5b                   pop ebx
// 004b6eed  64890d00000000       mov dword ptr fs:[0], ecx
// 004b6ef4  83c43c               add esp, 0x3c
// 004b6ef7  c20400               ret 4

#include <set>
// from server: 97% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <intrin.h>
#include <utility>
namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose()=0;
    virtual void destroy(){delete this;}
    long use_count_,weak_count_;
    void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
    void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count():pi_(0){}
    shared_count& operator=(const shared_count& r){sp_counted_base* tmp=r.pi_;if(tmp!=pi_){if(tmp)_InterlockedIncrement(&tmp->use_count_);if(pi_)pi_->release();pi_=tmp;}return *this;}
    void swap(shared_count& r){sp_counted_base* tmp=r.pi_;r.pi_=pi_;pi_=tmp;}
    shared_count(const shared_count& r):pi_(r.pi_){if(pi_)_InterlockedIncrement(&pi_->use_count_);}
    ~shared_count(){if(pi_)pi_->release();}
};
}
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    shared_ptr():px(0),pn(){}
    shared_ptr& operator=(const shared_ptr& r){px=r.px;pn=r.pn;return *this;}
    void swap(shared_ptr& r){std::swap(px,r.px);pn.swap(r.pn);}
    void reset(){shared_ptr().swap(*this);}
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type()const{return px==0?0:&shared_ptr::px;}
    shared_ptr(const shared_ptr& r):px(r.px),pn(r.pn){}
    template<class Y> shared_ptr(const shared_ptr<Y>& r):px(r.px),pn(r.pn){}
    T* get()const{return px;}
    T* operator->()const{return px;}
};
template<class T,class U> bool operator==(const shared_ptr<T>& a,const shared_ptr<U>& b){return a.get()==b.get();}
}

extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();
namespace RBX {
struct Name {int index;const std::string text;const std::string& toString()const{return text;}const char* c_str()const{return text.c_str();}};
struct Guid {void* scope;int index;std::string readableString(int)const;};
struct Primary {virtual void slot0();char flags[4];Guid guid;};
struct NameInterface {virtual void slot0();virtual const Name& getClassName()const;};
struct ReflectionObject {virtual void slot0();};
struct Instance:Primary,NameInterface,ReflectionObject {void ensureGuid()const;const Guid& getGuid()const{ensureGuid();return guid;}};
struct Descriptor {void* slot;const Name& name;};
struct Container:std::set<const Instance*> { __declspec(noinline) const_iterator find(const Instance*const&)const; };
typedef char container_extent[sizeof(Container)==32?1:-1];
struct BitStream;
struct Dictionary {char opaque[68];void send(BitStream&,const Descriptor&);};
struct Address {const char* ToString(bool)const;};
struct Property {const Descriptor* desc;const ReflectionObject* instance;Property(const Descriptor&d,const ReflectionObject*i):desc(&d),instance(i){}};
struct Settings {char prefix[0x132];bool printProperties;static Settings& singleton();};
struct StandardOut {void print(int,const char*,...);static boost::shared_ptr<StandardOut> singleton();};
struct Replicator {char prefix[0x2bf4];Dictionary propNames;Container objects;char gap[0xfc];Address remotePlayerId;void serializeId(BitStream&,const Instance*);void serializeValue(const Property&,bool,BitStream&);
 struct ChangePropertyItem {void* vptr;Replicator& replicator;const Descriptor& desc;boost::shared_ptr<const Instance> instance;void write(BitStream&);};
};
void __cdecl writeItemType(BitStream&,int);
Container::const_iterator Container::find(const Instance*const& key)const{return std::set<const Instance*>::find(key);}
void Replicator::ChangePropertyItem::write(BitStream& bitStream){
 if(replicator.objects.find(instance.get())!=replicator.objects.end()){
  writeItemType(bitStream,3);
  replicator.serializeId(bitStream,instance.get());
  replicator.propNames.send(bitStream,desc);
  if(Settings::singleton().printProperties){
   StandardOut::singleton()->print(1,"Replication: %s:%s.%s >> %s",instance->getClassName().c_str(),instance->getGuid().readableString(4).c_str(),desc.name.c_str(),replicator.remotePlayerId.ToString(true));
  }
  replicator.serializeValue(Property(desc,instance.get()),true,bitStream);
 }
}
}
