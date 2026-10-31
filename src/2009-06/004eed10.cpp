// from server: 79% by EspClaude
// from server: 100% by coldek
// roc 2008-06 004b6f00  unit: RBX::Network::Replicator::ChangePropertyItem  size: 846 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004b6f00
//
// 004b6f00  6aff                 push -1
// 004b6f02  68188c7c00           push 0x7c8c18
// 004b6f07  64a100000000         mov eax, dword ptr fs:[0]
// 004b6f0d  50                   push eax
// 004b6f0e  64892500000000       mov dword ptr fs:[0], esp
// 004b6f15  83ec44               sub esp, 0x44
// 004b6f18  53                   push ebx
// 004b6f19  8b5c245c             mov ebx, dword ptr [esp + 0x5c]
// 004b6f1d  55                   push ebp
// 004b6f1e  83c314               add ebx, 0x14
// 004b6f21  56                   push esi
// 004b6f22  8b7308               mov esi, dword ptr [ebx + 8]
// 004b6f25  57                   push edi
// 004b6f26  8b7e14               mov edi, dword ptr [esi + 0x14]
// 004b6f29  894c241c             mov dword ptr [esp + 0x1c], ecx
// 004b6f2d  895c2418             mov dword ptr [esp + 0x18], ebx
// 004b6f31  3b7e18               cmp edi, dword ptr [esi + 0x18]
// 004b6f34  7606                 jbe 0x4b6f3c
// 004b6f36  ff1590288000         call dword ptr [0x802890]
// 004b6f3c  8b6e08               mov ebp, dword ptr [esi + 8]
// 004b6f3f  8b7308               mov esi, dword ptr [ebx + 8]
// 004b6f42  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b6f45  896c244c             mov dword ptr [esp + 0x4c], ebp
// 004b6f49  897c2450             mov dword ptr [esp + 0x50], edi
// 004b6f4d  89442414             mov dword ptr [esp + 0x14], eax
// 004b6f51  394614               cmp dword ptr [esi + 0x14], eax
// 004b6f54  7606                 jbe 0x4b6f5c
// 004b6f56  ff1590288000         call dword ptr [0x802890]
// 004b6f5c  8b4608               mov eax, dword ptr [esi + 8]
// 004b6f5f  89442428             mov dword ptr [esp + 0x28], eax
// 004b6f63  bb10000000           mov ebx, 0x10
// 004b6f68  85ed                 test ebp, ebp
// 004b6f6a  7406                 je 0x4b6f72
// 004b6f6c  3b6c2428             cmp ebp, dword ptr [esp + 0x28]
// 004b6f70  7406                 je 0x4b6f78
// 004b6f72  ff1590288000         call dword ptr [0x802890]
// 004b6f78  3b7c2414             cmp edi, dword ptr [esp + 0x14]
// 004b6f7c  0f84b7020000         je 0x4b7239
// 004b6f82  85ed                 test ebp, ebp
// 004b6f84  0f85c8000000         jne 0x4b7052
// 004b6f8a  ff1590288000         call dword ptr [0x802890]
// 004b6f90  33c0                 xor eax, eax
// 004b6f92  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004b6f95  7206                 jb 0x4b6f9d
// 004b6f97  ff1590288000         call dword ptr [0x802890]
// 004b6f9d  8b07                 mov eax, dword ptr [edi]
// 004b6f9f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004b6fa3  89442420             mov dword ptr [esp + 0x20], eax
// 004b6fa7  894c2424             mov dword ptr [esp + 0x24], ecx
// 004b6fab  8b5010               mov edx, dword ptr [eax + 0x10]
// 004b6fae  d1ea                 shr edx, 1
// 004b6fb0  8bf0                 mov esi, eax
// 004b6fb2  f6c201               test dl, 1
// 004b6fb5  0f8452020000         je 0x4b720d
// 004b6fbb  3d343d9700           cmp eax, 0x973d34
// 004b6fc0  0f8447020000         je 0x4b720d
// 004b6fc6  8d7814               lea edi, [eax + 0x14]
// 004b6fc9  8b07                 mov eax, dword ptr [edi]
// 004b6fcb  8b4008               mov eax, dword ptr [eax + 8]
// 004b6fce  50                   push eax
// 004b6fcf  b944969200           mov ecx, 0x929644
// 004b6fd4  ff1578288000         call dword ptr [0x802878]
// 004b6fda  84c0                 test al, al
// 004b6fdc  0f84f1000000         je 0x4b70d3
// 004b6fe2  8b542464             mov edx, dword ptr [esp + 0x64]
// 004b6fe6  8d4c2468             lea ecx, [esp + 0x68]
// 004b6fea  51                   push ecx
// 004b6feb  52                   push edx
// 004b6fec  e83febfeff           call 0x4a5b30
// 004b6ff1  83c408               add esp, 8
// 004b6ff4  837c242400           cmp dword ptr [esp + 0x24], 0
// 004b6ff9  740e                 je 0x4b7009
// 004b6ffb  8d442468             lea eax, [esp + 0x68]
// 004b6fff  50                   push eax
// 004b7000  8d4c2424             lea ecx, [esp + 0x24]
// 004b7004  e8d761ffff           call 0x4ad1e0
// 004b7009  e88278feff           call 0x49e890
// 004b700e  80b83101000000       cmp byte ptr [eax + 0x131], 0
// 004b7015  0f84f2010000         je 0x4b720d
// 004b701b  e87078feff           call 0x49e890
// 004b7020  80b83201000000       cmp byte ptr [eax + 0x132], 0
// 004b7027  0f84e0010000         je 0x4b720d
// 004b702d  8d4c2430             lea ecx, [esp + 0x30]
// 004b7031  51                   push ecx
// 004b7032  e8e9250b00           call 0x569620
// 004b7037  83c404               add esp, 4
// 004b703a  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b703d  83c104               add ecx, 4
// 004b7040  c744245c00000000     mov dword ptr [esp + 0x5c], 0
// 004b7048  395918               cmp dword ptr [ecx + 0x18], ebx
// 004b704b  720d                 jb 0x4b705a
// 004b704d  8b4904               mov ecx, dword ptr [ecx + 4]
// 004b7050  eb0b                 jmp 0x4b705d
// 004b7052  8b4500               mov eax, dword ptr [ebp]
// 004b7055  e938ffffff           jmp 0x4b6f92
// 004b705a  83c104               add ecx, 4
// 004b705d  8b17                 mov edx, dword ptr [edi]
// 004b705f  8b5204               mov edx, dword ptr [edx + 4]
// 004b7062  83c204               add edx, 4
// 004b7065  395a18               cmp dword ptr [edx + 0x18], ebx
// 004b7068  7205                 jb 0x4b706f
// 004b706a  8b5204               mov edx, dword ptr [edx + 4]
// 004b706d  eb03                 jmp 0x4b7072
// 004b706f  83c204               add edx, 4
// 004b7072  8b00                 mov eax, dword ptr [eax]
// 004b7074  51                   push ecx
// 004b7075  52                   push edx
// 004b7076  6870508200           push 0x825070
// 004b707b  6a01                 push 1
// 004b707d  50                   push eax
// 004b707e  e81d230b00           call 0x5693a0
// 004b7083  8b442448             mov eax, dword ptr [esp + 0x48]
// 004b7087  83c414               add esp, 0x14
// 004b708a  c744245cffffffff     mov dword ptr [esp + 0x5c], 0xffffffff
// 004b7092  85c0                 test eax, eax
// 004b7094  0f8473010000         je 0x4b720d
// 004b709a  8bf0                 mov esi, eax
// 004b709c  83c004               add eax, 4
// 004b709f  83c9ff               or ecx, 0xffffffff
// 004b70a2  f00fc108             lock xadd dword ptr [eax], ecx
// 004b70a6  0f8561010000         jne 0x4b720d
// 004b70ac  8b16                 mov edx, dword ptr [esi]
// 004b70ae  8b4204               mov eax, dword ptr [edx + 4]
// 004b70b1  8bce                 mov ecx, esi
// 004b70b3  ffd0                 call eax
// 004b70b5  8d4e08               lea ecx, [esi + 8]
// 004b70b8  83caff               or edx, 0xffffffff
// 004b70bb  f00fc111             lock xadd dword ptr [ecx], edx
// 004b70bf  0f8548010000         jne 0x4b720d
// 004b70c5  8b06                 mov eax, dword ptr [esi]
// 004b70c7  8b5008               mov edx, dword ptr [eax + 8]
// 004b70ca  8bce                 mov ecx, esi
// 004b70cc  ffd2                 call edx
// 004b70ce  e93a010000           jmp 0x4b720d
// 004b70d3  8b6c2464             mov ebp, dword ptr [esp + 0x64]
// 004b70d7  8d442413             lea eax, [esp + 0x13]
// 004b70db  50                   push eax
// 004b70dc  55                   push ebp
// 004b70dd  e84eeafeff           call 0x4a5b30
// 004b70e2  83c408               add esp, 8
// 004b70e5  807c241300           cmp byte ptr [esp + 0x13], 0
// 004b70ea  747e                 je 0x4b716a
// 004b70ec  e89f77feff           call 0x49e890
// 004b70f1  80b83101000000       cmp byte ptr [eax + 0x131], 0
// 004b70f8  0f840b010000         je 0x4b7209
// 004b70fe  e88d77feff           call 0x49e890
// 004b7103  80b83201000000       cmp byte ptr [eax + 0x132], 0
// 004b710a  0f84f9000000         je 0x4b7209
// 004b7110  8d4c2438             lea ecx, [esp + 0x38]
// 004b7114  51                   push ecx
// 004b7115  e806250b00           call 0x569620
// 004b711a  83c404               add esp, 4
// 004b711d  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b7120  83c104               add ecx, 4
// 004b7123  c744245c01000000     mov dword ptr [esp + 0x5c], 1
// 004b712b  395918               cmp dword ptr [ecx + 0x18], ebx
// 004b712e  7205                 jb 0x4b7135
// 004b7130  8b4904               mov ecx, dword ptr [ecx + 4]
// 004b7133  eb03                 jmp 0x4b7138
// 004b7135  83c104               add ecx, 4
// 004b7138  8b17                 mov edx, dword ptr [edi]
// 004b713a  8b5204               mov edx, dword ptr [edx + 4]
// 004b713d  83c204               add edx, 4
// 004b7140  395a18               cmp dword ptr [edx + 0x18], ebx
// 004b7143  7205                 jb 0x4b714a
// 004b7145  8b5204               mov edx, dword ptr [edx + 4]
// 004b7148  eb03                 jmp 0x4b714d
// 004b714a  83c204               add edx, 4
// 004b714d  8b00                 mov eax, dword ptr [eax]
// 004b714f  51                   push ecx
// 004b7150  52                   push edx
// 004b7151  6850508200           push 0x825050
// 004b7156  6a01                 push 1
// 004b7158  50                   push eax
// 004b7159  e842220b00           call 0x5693a0
// 004b715e  83c414               add esp, 0x14
// 004b7161  8d4c2438             lea ecx, [esp + 0x38]
// 004b7165  e992000000           jmp 0x4b71fc
// 004b716a  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 004b716e  8b6d08               mov ebp, dword ptr [ebp + 8]
// 004b7171  8d442420             lea eax, [esp + 0x20]
// 004b7175  50                   push eax
// 004b7176  51                   push ecx
// 004b7177  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004b717b  e830f9ffff           call 0x4b6ab0
// 004b7180  e80b77feff           call 0x49e890
// 004b7185  80b83101000000       cmp byte ptr [eax + 0x131], 0
// 004b718c  747b                 je 0x4b7209
// 004b718e  e8fd76feff           call 0x49e890
// 004b7193  80b83201000000       cmp byte ptr [eax + 0x132], 0
// 004b719a  746d                 je 0x4b7209
// 004b719c  8d542440             lea edx, [esp + 0x40]
// 004b71a0  52                   push edx
// 004b71a1  e87a240b00           call 0x569620
// 004b71a6  83c404               add esp, 4
// 004b71a9  8b5604               mov edx, dword ptr [esi + 4]
// 004b71ac  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 004b71b0  8b4908               mov ecx, dword ptr [ecx + 8]
// 004b71b3  83c204               add edx, 4
// 004b71b6  c744245c02000000     mov dword ptr [esp + 0x5c], 2
// 004b71be  395a18               cmp dword ptr [edx + 0x18], ebx
// 004b71c1  7205                 jb 0x4b71c8
// 004b71c3  8b5204               mov edx, dword ptr [edx + 4]
// 004b71c6  eb03                 jmp 0x4b71cb
// 004b71c8  83c204               add edx, 4
// 004b71cb  8b37                 mov esi, dword ptr [edi]
// 004b71cd  8b7604               mov esi, dword ptr [esi + 4]
// 004b71d0  83c604               add esi, 4
// 004b71d3  395e18               cmp dword ptr [esi + 0x18], ebx
// 004b71d6  7205                 jb 0x4b71dd
// 004b71d8  8b7604               mov esi, dword ptr [esi + 4]
// 004b71db  eb03                 jmp 0x4b71e0
// 004b71dd  83c604               add esi, 4
// 004b71e0  8b00                 mov eax, dword ptr [eax]
// 004b71e2  2bcd                 sub ecx, ebp
// 004b71e4  41                   inc ecx
// 004b71e5  51                   push ecx
// 004b71e6  52                   push edx
// 004b71e7  56                   push esi
// 004b71e8  6838508200           push 0x825038
// 004b71ed  6a01                 push 1
// 004b71ef  50                   push eax
// 004b71f0  e8ab210b00           call 0x5693a0
// 004b71f5  83c418               add esp, 0x18
// 004b71f8  8d4c2440             lea ecx, [esp + 0x40]
// 004b71fc  c744245cffffffff     mov dword ptr [esp + 0x5c], 0xffffffff
// 004b7204  e857941400           call 0x600660
// 004b7209  8b6c244c             mov ebp, dword ptr [esp + 0x4c]
// 004b720d  85ed                 test ebp, ebp
// 004b720f  7523                 jne 0x4b7234
// 004b7211  ff1590288000         call dword ptr [0x802890]
// 004b7217  33c0                 xor eax, eax
// 004b7219  8b7c2450             mov edi, dword ptr [esp + 0x50]
// 004b721d  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004b7220  7206                 jb 0x4b7228
// 004b7222  ff1590288000         call dword ptr [0x802890]
// 004b7228  83c704               add edi, 4
// 004b722b  897c2450             mov dword ptr [esp + 0x50], edi
// 004b722f  e934fdffff           jmp 0x4b6f68
// 004b7234  8b4500               mov eax, dword ptr [ebp]
// 004b7237  ebe0                 jmp 0x4b7219
// 004b7239  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 004b723d  5f                   pop edi
// 004b723e  5e                   pop esi
// 004b723f  5d                   pop ebp
// 004b7240  5b                   pop ebx
// 004b7241  64890d00000000       mov dword ptr fs:[0], ecx
// 004b7248  83c450               add esp, 0x50
// 004b724b  c20800               ret 8

// from server: 84% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
#include <typeinfo>
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

struct __declspec(dllimport) ImportedString {
 void*proxy;union{char buffer[16];char*heap;};unsigned length,capacity;
 ~ImportedString()throw();
 const char*c_str()const{return capacity>=16?heap:buffer;}
};
struct Name {unsigned id;ImportedString text;const char*c_str()const{return text.c_str();}};
struct Type {void*vtable;const Name&name;const type_info&info;};
struct DescribedBase;
struct PropertyDescriptor {
 void**vtable;const Name&name;const Name&category;void*owner;
 unsigned isPublic:1;unsigned streamWrite:1;unsigned reserved:30;
 const Type&type;
 bool canStreamWrite()const{return streamWrite;}
 bool equalValues(const DescribedBase*a,const DescribedBase*b)const{
  typedef bool(__thiscall*Equal)(const PropertyDescriptor*,const DescribedBase*,const DescribedBase*);
  return reinterpret_cast<Equal>(vtable[3])(this,a,b);
 }
};
extern const PropertyDescriptor parentDescriptor;
struct Property {
 const PropertyDescriptor*descriptor;const DescribedBase*instance;
 Property(const PropertyDescriptor&d,const DescribedBase*p):descriptor(&d),instance(p){}
 const PropertyDescriptor&getDescriptor()const{return *descriptor;}
 void setBool(const bool&);
};
typedef std::vector<PropertyDescriptor*>PropertyCollection;
struct PropertyIterator {
 DescribedBase*instance;PropertyCollection::const_iterator iter;
 PropertyIterator(const PropertyCollection::const_iterator&i,DescribedBase*p):instance(p),iter(i){}
 Property operator*()const{return Property(**iter,instance);}
 bool operator!=(const PropertyIterator&r)const{return iter!=r.iter;}
 PropertyIterator&operator++(){++iter;return *this;}
};
struct ClassDescriptor {
 virtual ~ClassDescriptor();const Name&name;PropertyCollection descriptors;
 PropertyIterator members_begin(DescribedBase*p)const{return PropertyIterator(descriptors.begin(),p);}
 PropertyIterator members_end(DescribedBase*p)const{return PropertyIterator(descriptors.end(),p);}
};
struct DescribedBase {
 virtual ~DescribedBase();void*opaque;const ClassDescriptor*descriptor;
 PropertyIterator properties_begin(){return descriptor->members_begin(this);}
 PropertyIterator properties_end(){return descriptor->members_end(this);}
};
struct PrimaryInstance {virtual ~PrimaryInstance();char opaque[12];};
struct FactoryProduct {virtual ~FactoryProduct();virtual const Name&getClassName()const=0;};
struct Instance:PrimaryInstance,FactoryProduct,DescribedBase {};
struct Settings {char prefix[0x131];bool printInstances,printProperties;};
Settings&settings();
struct StandardOut {void __cdecl print(int,const char*,...);};
boost::shared_ptr<StandardOut> __cdecl standardOut();
struct BitStream {unsigned bitsUsed,bitsAllocated,readOffset;int GetReadOffset()const{return readOffset;}};
void __cdecl writeBool(BitStream&,bool);
BitStream& __cdecl readBool(BitStream&,bool&);
struct Replicator {
 const Instance*getDefault(const Name&);
 void serializeValue(const Property&,bool,BitStream&);
 void writeProperties(const Instance*,BitStream&);
 void readProperties(BitStream&,Instance*);
 void deserializeValue(BitStream&,Property&);
};
static __forceinline void printReadBool(const PropertyDescriptor& descriptor){standardOut()->print(1,"   read %s %s, 1 bit",descriptor.type.name.c_str(),descriptor.name.c_str());}

static __forceinline bool isBooleanType(const Type& type){return typeid(bool)==type.info;}
void Replicator::readProperties(BitStream&stream,Instance*instance){
 PropertyIterator iter=instance->properties_begin();
 PropertyIterator end=instance->properties_end();
 for(;iter!=end;++iter){
  Property property=*iter;
  const PropertyDescriptor&descriptor=property.getDescriptor();
  if(descriptor.canStreamWrite()&&&descriptor!=&parentDescriptor){
   if(isBooleanType(descriptor.type)){
    bool value;readBool(stream,value);
    if(property.instance)property.setBool(value);
    if(settings().printInstances&&settings().printProperties){printReadBool(descriptor);}
   }else{
    bool isDefault;readBool(stream,isDefault);
    if(isDefault){
     if(settings().printInstances&&settings().printProperties){standardOut()->print(1,"   read %s %s, 1 bit (default)",descriptor.type.name.c_str(),descriptor.name.c_str());}
    }else{
     int bits=stream.GetReadOffset();
     deserializeValue(stream,property);
     if(settings().printInstances&&settings().printProperties){standardOut()->print(1,"   read %s %s, %d bits",descriptor.type.name.c_str(),descriptor.name.c_str(),stream.GetReadOffset()-bits+1);}
    }
   }
  }
 }
}
