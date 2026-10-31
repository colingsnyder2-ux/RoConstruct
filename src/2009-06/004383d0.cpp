// from server: 95% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0043dc00  unit: RefItem  size: 835 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043dc00
//
// 0043dc00  6aff                 push -1
// 0043dc02  68da077c00           push 0x7c07da
// 0043dc07  64a100000000         mov eax, dword ptr fs:[0]
// 0043dc0d  50                   push eax
// 0043dc0e  64892500000000       mov dword ptr fs:[0], esp
// 0043dc15  83ec58               sub esp, 0x58
// 0043dc18  8b442468             mov eax, dword ptr [esp + 0x68]
// 0043dc1c  53                   push ebx
// 0043dc1d  55                   push ebp
// 0043dc1e  8be9                 mov ebp, ecx
// 0043dc20  c744240800000000     mov dword ptr [esp + 8], 0
// 0043dc28  8b4818               mov ecx, dword ptr [eax + 0x18]
// 0043dc2b  8b10                 mov edx, dword ptr [eax]
// 0043dc2d  56                   push esi
// 0043dc2e  8b7510               mov esi, dword ptr [ebp + 0x10]
// 0043dc31  32db                 xor bl, bl
// 0043dc33  57                   push edi
// 0043dc34  896c2414             mov dword ptr [esp + 0x14], ebp
// 0043dc38  894c2438             mov dword ptr [esp + 0x38], ecx
// 0043dc3c  89542434             mov dword ptr [esp + 0x34], edx
// 0043dc40  3b7514               cmp esi, dword ptr [ebp + 0x14]
// 0043dc43  7606                 jbe 0x43dc4b
// 0043dc45  ff1590288000         call dword ptr [0x802890]
// 0043dc4b  8b7d04               mov edi, dword ptr [ebp + 4]
// 0043dc4e  89742430             mov dword ptr [esp + 0x30], esi
// 0043dc52  8b7514               mov esi, dword ptr [ebp + 0x14]
// 0043dc55  897c242c             mov dword ptr [esp + 0x2c], edi
// 0043dc59  89742420             mov dword ptr [esp + 0x20], esi
// 0043dc5d  397510               cmp dword ptr [ebp + 0x10], esi
// 0043dc60  7606                 jbe 0x43dc68
// 0043dc62  ff1590288000         call dword ptr [0x802890]
// 0043dc68  8b4504               mov eax, dword ptr [ebp + 4]
// 0043dc6b  89442444             mov dword ptr [esp + 0x44], eax
// 0043dc6f  90                   nop 
// 0043dc70  85ff                 test edi, edi
// 0043dc72  7406                 je 0x43dc7a
// 0043dc74  3b7c2444             cmp edi, dword ptr [esp + 0x44]
// 0043dc78  7406                 je 0x43dc80
// 0043dc7a  ff1590288000         call dword ptr [0x802890]
// 0043dc80  39742430             cmp dword ptr [esp + 0x30], esi
// 0043dc84  0f8491020000         je 0x43df1b
// 0043dc8a  85ff                 test edi, edi
// 0043dc8c  0f8508010000         jne 0x43dd9a
// 0043dc92  ff1590288000         call dword ptr [0x802890]
// 0043dc98  33c0                 xor eax, eax
// 0043dc9a  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0043dc9e  3b4810               cmp ecx, dword ptr [eax + 0x10]
// 0043dca1  7206                 jb 0x43dca9
// 0043dca3  ff1590288000         call dword ptr [0x802890]
// 0043dca9  8b542430             mov edx, dword ptr [esp + 0x30]
// 0043dcad  8b02                 mov eax, dword ptr [edx]
// 0043dcaf  8d4c241c             lea ecx, [esp + 0x1c]
// 0043dcb3  51                   push ecx
// 0043dcb4  8b4c247c             mov ecx, dword ptr [esp + 0x7c]
// 0043dcb8  8d542440             lea edx, [esp + 0x40]
// 0043dcbc  52                   push edx
// 0043dcbd  89442424             mov dword ptr [esp + 0x24], eax
// 0043dcc1  e85ac6ffff           call 0x43a320
// 0043dcc6  8b7c243c             mov edi, dword ptr [esp + 0x3c]
// 0043dcca  85ff                 test edi, edi
// 0043dccc  7406                 je 0x43dcd4
// 0043dcce  3b7c2434             cmp edi, dword ptr [esp + 0x34]
// 0043dcd2  7406                 je 0x43dcda
// 0043dcd4  ff1590288000         call dword ptr [0x802890]
// 0043dcda  8b742440             mov esi, dword ptr [esp + 0x40]
// 0043dcde  3b742438             cmp esi, dword ptr [esp + 0x38]
// 0043dce2  0f84d5010000         je 0x43debd
// 0043dce8  85ff                 test edi, edi
// 0043dcea  0f85b1000000         jne 0x43dda1
// 0043dcf0  ff1590288000         call dword ptr [0x802890]
// 0043dcf6  33c0                 xor eax, eax
// 0043dcf8  3b7018               cmp esi, dword ptr [eax + 0x18]
// 0043dcfb  7506                 jne 0x43dd03
// 0043dcfd  ff1590288000         call dword ptr [0x802890]
// 0043dd03  8b6e1c               mov ebp, dword ptr [esi + 0x1c]
// 0043dd06  3b6e20               cmp ebp, dword ptr [esi + 0x20]
// 0043dd09  7606                 jbe 0x43dd11
// 0043dd0b  ff1590288000         call dword ptr [0x802890]
// 0043dd11  8b4610               mov eax, dword ptr [esi + 0x10]
// 0043dd14  896c2428             mov dword ptr [esp + 0x28], ebp
// 0043dd18  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0043dd1e  89442424             mov dword ptr [esp + 0x24], eax
// 0043dd22  85ff                 test edi, edi
// 0043dd24  0f857e000000         jne 0x43dda8
// 0043dd2a  ffd5                 call ebp
// 0043dd2c  8b442424             mov eax, dword ptr [esp + 0x24]
// 0043dd30  3b7718               cmp esi, dword ptr [edi + 0x18]
// 0043dd33  7506                 jne 0x43dd3b
// 0043dd35  ffd5                 call ebp
// 0043dd37  8b442424             mov eax, dword ptr [esp + 0x24]
// 0043dd3b  8b7e20               mov edi, dword ptr [esi + 0x20]
// 0043dd3e  897c241c             mov dword ptr [esp + 0x1c], edi
// 0043dd42  397e1c               cmp dword ptr [esi + 0x1c], edi
// 0043dd45  7606                 jbe 0x43dd4d
// 0043dd47  ffd5                 call ebp
// 0043dd49  8b442424             mov eax, dword ptr [esp + 0x24]
// 0043dd4d  8b7610               mov esi, dword ptr [esi + 0x10]
// 0043dd50  85c0                 test eax, eax
// 0043dd52  7404                 je 0x43dd58
// 0043dd54  3bc6                 cmp eax, esi
// 0043dd56  7406                 je 0x43dd5e
// 0043dd58  ffd5                 call ebp
// 0043dd5a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0043dd5e  397c2428             cmp dword ptr [esp + 0x28], edi
// 0043dd62  0f8451010000         je 0x43deb9
// 0043dd68  84db                 test bl, bl
// 0043dd6a  0f85bc000000         jne 0x43de2c
// 0043dd70  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0043dd76  33db                 xor ebx, ebx
// 0043dd78  3bc3                 cmp eax, ebx
// 0043dd7a  7530                 jne 0x43ddac
// 0043dd7c  ffd5                 call ebp
// 0043dd7e  33c0                 xor eax, eax
// 0043dd80  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0043dd84  3b4810               cmp ecx, dword ptr [eax + 0x10]
// 0043dd87  7202                 jb 0x43dd8b
// 0043dd89  ffd5                 call ebp
// 0043dd8b  8b542428             mov edx, dword ptr [esp + 0x28]
// 0043dd8f  8b02                 mov eax, dword ptr [edx]
// 0043dd91  3bc3                 cmp eax, ebx
// 0043dd93  741b                 je 0x43ddb0
// 0043dd95  83c014               add eax, 0x14
// 0043dd98  eb18                 jmp 0x43ddb2
// 0043dd9a  8b07                 mov eax, dword ptr [edi]
// 0043dd9c  e9f9feffff           jmp 0x43dc9a
// 0043dda1  8b07                 mov eax, dword ptr [edi]
// 0043dda3  e950ffffff           jmp 0x43dcf8
// 0043dda8  8b3f                 mov edi, dword ptr [edi]
// 0043ddaa  eb84                 jmp 0x43dd30
// 0043ddac  8b00                 mov eax, dword ptr [eax]
// 0043ddae  ebd0                 jmp 0x43dd80
// 0043ddb0  33c0                 xor eax, eax
// 0043ddb2  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0043ddb6  8b4f24               mov ecx, dword ptr [edi + 0x24]
// 0043ddb9  8b11                 mov edx, dword ptr [ecx]
// 0043ddbb  50                   push eax
// 0043ddbc  8b4230               mov eax, dword ptr [edx + 0x30]
// 0043ddbf  ffd0                 call eax
// 0043ddc1  3bc3                 cmp eax, ebx
// 0043ddc3  7409                 je 0x43ddce
// 0043ddc5  83c0ec               add eax, -0x14
// 0043ddc8  89442418             mov dword ptr [esp + 0x18], eax
// 0043ddcc  eb06                 jmp 0x43ddd4
// 0043ddce  895c2418             mov dword ptr [esp + 0x18], ebx
// 0043ddd2  8bc3                 mov eax, ebx
// 0043ddd4  3bc3                 cmp eax, ebx
// 0043ddd6  7407                 je 0x43dddf
// 0043ddd8  0510010000           add eax, 0x110
// 0043dddd  eb18                 jmp 0x43ddf7
// 0043dddf  6816b78000           push 0x80b716
// 0043dde4  8d4c2450             lea ecx, [esp + 0x50]
// 0043dde8  ff1558248000         call dword ptr [0x802458]
// 0043ddee  834c241001           or dword ptr [esp + 0x10], 1
// 0043ddf3  895c2470             mov dword ptr [esp + 0x70], ebx
// 0043ddf7  8b97f4feffff         mov edx, dword ptr [edi - 0x10c]
// 0043ddfd  8d8ff4feffff         lea ecx, [edi - 0x10c]
// 0043de03  50                   push eax
// 0043de04  8b82e8000000         mov eax, dword ptr [edx + 0xe8]
// 0043de0a  ffd0                 call eax
// 0043de0c  f644241001           test byte ptr [esp + 0x10], 1
// 0043de11  c7442470ffffffff     mov dword ptr [esp + 0x70], 0xffffffff
// 0043de19  7469                 je 0x43de84
// 0043de1b  83642410fe           and dword ptr [esp + 0x10], 0xfffffffe
// 0043de20  8d4c244c             lea ecx, [esp + 0x4c]
// 0043de24  ff1568248000         call dword ptr [0x802468]
// 0043de2a  eb58                 jmp 0x43de84
// 0043de2c  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0043de30  85ff                 test edi, edi
// 0043de32  7405                 je 0x43de39
// 0043de34  83c714               add edi, 0x14
// 0043de37  eb02                 jmp 0x43de3b
// 0043de39  33ff                 xor edi, edi
// 0043de3b  85c0                 test eax, eax
// 0043de3d  7526                 jne 0x43de65
// 0043de3f  ff1590288000         call dword ptr [0x802890]
// 0043de45  33c0                 xor eax, eax
// 0043de47  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0043de4b  3b4810               cmp ecx, dword ptr [eax + 0x10]
// 0043de4e  7206                 jb 0x43de56
// 0043de50  ff1590288000         call dword ptr [0x802890]
// 0043de56  8b542428             mov edx, dword ptr [esp + 0x28]
// 0043de5a  8b02                 mov eax, dword ptr [edx]
// 0043de5c  85c0                 test eax, eax
// 0043de5e  7409                 je 0x43de69
// 0043de60  83c014               add eax, 0x14
// 0043de63  eb06                 jmp 0x43de6b
// 0043de65  8b00                 mov eax, dword ptr [eax]
// 0043de67  ebde                 jmp 0x43de47
// 0043de69  33c0                 xor eax, eax
// 0043de6b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0043de6f  8b4924               mov ecx, dword ptr [ecx + 0x24]
// 0043de72  8b11                 mov edx, dword ptr [ecx]
// 0043de74  50                   push eax
// 0043de75  8b4230               mov eax, dword ptr [edx + 0x30]
// 0043de78  ffd0                 call eax
// 0043de7a  3bf8                 cmp edi, eax
// 0043de7c  7574                 jne 0x43def2
// 0043de7e  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0043de84  8b442424             mov eax, dword ptr [esp + 0x24]
// 0043de88  b301                 mov bl, 1
// 0043de8a  85c0                 test eax, eax
// 0043de8c  7527                 jne 0x43deb5
// 0043de8e  ffd5                 call ebp
// 0043de90  33c0                 xor eax, eax
// 0043de92  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0043de96  3b4810               cmp ecx, dword ptr [eax + 0x10]
// 0043de99  7202                 jb 0x43de9d
// 0043de9b  ffd5                 call ebp
// 0043de9d  8344242808           add dword ptr [esp + 0x28], 8
// 0043dea2  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0043dea8  8b442424             mov eax, dword ptr [esp + 0x24]
// 0043deac  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0043deb0  e99bfeffff           jmp 0x43dd50
// 0043deb5  8b00                 mov eax, dword ptr [eax]
// 0043deb7  ebd9                 jmp 0x43de92
// 0043deb9  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0043debd  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0043dec1  85c0                 test eax, eax
// 0043dec3  7529                 jne 0x43deee
// 0043dec5  ff1590288000         call dword ptr [0x802890]
// 0043decb  33c0                 xor eax, eax
// 0043decd  8b542430             mov edx, dword ptr [esp + 0x30]
// 0043ded1  3b5010               cmp edx, dword ptr [eax + 0x10]
// 0043ded4  7206                 jb 0x43dedc
// 0043ded6  ff1590288000         call dword ptr [0x802890]
// 0043dedc  8344243004           add dword ptr [esp + 0x30], 4
// 0043dee1  8b742420             mov esi, dword ptr [esp + 0x20]
// 0043dee5  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0043dee9  e982fdffff           jmp 0x43dc70
// 0043deee  8b00                 mov eax, dword ptr [eax]
// 0043def0  ebdb                 jmp 0x43decd
// 0043def2  51                   push ecx
// 0043def3  8bcc                 mov ecx, esp
// 0043def5  8964247c             mov dword ptr [esp + 0x7c], esp
// 0043def9  6816b78000           push 0x80b716
// 0043defe  ff15103f8000         call dword ptr [0x803f10]
// 0043df04  8b742418             mov esi, dword ptr [esp + 0x18]
// 0043df08  81c6f4feffff         add esi, 0xfffffef4
// 0043df0e  8bce                 mov ecx, esi
// 0043df10  e8db3a2d00           call 0x7119f0
// 0043df15  6a00                 push 0
// 0043df17  8bce                 mov ecx, esi
// 0043df19  eb0e                 jmp 0x43df29
// 0043df1b  33c0                 xor eax, eax
// 0043df1d  84db                 test bl, bl
// 0043df1f  0f94c0               sete al
// 0043df22  8d8df4feffff         lea ecx, [ebp - 0x10c]
// 0043df28  50                   push eax
// 0043df29  e8a2312d00           call 0x7110d0
// 0043df2e  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 0043df32  5f                   pop edi
// 0043df33  5e                   pop esi
// 0043df34  5d                   pop ebp
// 0043df35  64890d00000000       mov dword ptr fs:[0], ecx
// 0043df3c  5b                   pop ebx
// 0043df3d  83c464               add esp, 0x64
// 0043df40  c20400               ret 4

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

#include <vector>
#include <map>
#include <string>
namespace G3D {struct Vector3 {float x,y,z;Vector3():x(0),y(0),z(0){}Vector3(float a,float b,float c):x(a),y(b),z(c){}Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}Vector3& operator=(const Vector3&v){x=v.x;y=v.y;z=v.z;return *this;}};}
struct DescribedBase {virtual ~DescribedBase();};
struct InstancePrimary {virtual ~InstancePrimary();char prefix[0x10];};
struct Instance:InstancePrimary,DescribedBase {char gap[0x110-0x18];std::string name;const std::string&getName()const{return name;}};
struct RefDescriptor {virtual ~RefDescriptor();
virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual DescribedBase* getRef(DescribedBase*)const;};
struct ClassDescriptor;
typedef std::vector<boost::shared_ptr<Instance> > Instances;
typedef std::map<const ClassDescriptor*,Instances> Selection;
struct __declspec(dllimport) CString {void* data;CString(const char*);CString(const CString&);~CString();};
struct GridBase {virtual ~GridBase();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void slot31();
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35();
virtual void slot36();
virtual void slot37();
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45();
virtual void slot46();
virtual void slot47();
virtual void slot48();
virtual void slot49();
virtual void slot50();
virtual void slot51();
virtual void slot52();
virtual void slot53();
virtual void slot54();
virtual void slot55();
virtual void slot56();
virtual void slot57();
 virtual void setCommon(const std::string&);
 virtual bool equals(const std::string&,const std::string&);
 char padding[0x108];
 std::string value(Instance*);
 void SetValue(CString);
 void SetHidden(int);
};
struct UpdateBase {virtual void update(Selection&);std::vector<const ClassDescriptor*> classes;char gap[8];RefDescriptor* descriptor;};
struct XItem:GridBase,UpdateBase {void update(Selection&);};
void XItem::update(Selection& selection){
 Instance* common;
 bool foundAny=false;
 Selection::iterator selectionEnd=selection.end();
 for(std::vector<const ClassDescriptor*>::const_iterator c=classes.begin(),ce=classes.end();c!=ce;++c){
  const ClassDescriptor* key=*c;
  Selection::iterator selected=selection.find(key);
  if(selected!=selectionEnd){
   for(Instances::iterator i=selected->second.begin(),end=selected->second.end();i!=end;++i){
    if(!foundAny){common=static_cast<Instance*>(descriptor->getRef(static_cast<DescribedBase*>(i->get())));setCommon(common?common->getName():std::string(""));}
    else if(static_cast<DescribedBase*>(common)!=descriptor->getRef(static_cast<DescribedBase*>(i->get()))){SetValue(CString(""));SetHidden(0);return;}
    foundAny=true;
   }
  }
 }
 SetHidden(!foundAny);
}
