// from server: 100% by EspClaude
// roc 2009-06 00436da0  unit: RBX::Soundscape::VSoundId::?$XItem  size: 884 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00436da0
//
// 00436da0  6aff                 push -1
// 00436da2  6811fc8400           push 0x84fc11
// 00436da7  64a100000000         mov eax, dword ptr fs:[0]
// 00436dad  50                   push eax
// 00436dae  64892500000000       mov dword ptr fs:[0], esp
// 00436db5  81eca0000000         sub esp, 0xa0
// 00436dbb  53                   push ebx
// 00436dbc  55                   push ebp
// 00436dbd  56                   push esi
// 00436dbe  8bd9                 mov ebx, ecx
// 00436dc0  57                   push edi
// 00436dc1  8d4c2440             lea ecx, [esp + 0x40]
// 00436dc5  895c2414             mov dword ptr [esp + 0x14], ebx
// 00436dc9  ff15c0e48900         call dword ptr [0x89e4c0]
// 00436dcf  c78424b800000000000000 mov dword ptr [esp + 0xb8], 0
// 00436dda  e8816b1900           call 0x5cd960
// 00436ddf  8944245c             mov dword ptr [esp + 0x5c], eax
// 00436de3  8b8424c0000000       mov eax, dword ptr [esp + 0xc0]
// 00436dea  8b7310               mov esi, dword ptr [ebx + 0x10]
// 00436ded  8b4818               mov ecx, dword ptr [eax + 0x18]
// 00436df0  8b10                 mov edx, dword ptr [eax]
// 00436df2  c78424b800000001000000 mov dword ptr [esp + 0xb8], 1
// 00436dfd  c644241300           mov byte ptr [esp + 0x13], 0
// 00436e02  894c242c             mov dword ptr [esp + 0x2c], ecx
// 00436e06  89542428             mov dword ptr [esp + 0x28], edx
// 00436e0a  3b7314               cmp esi, dword ptr [ebx + 0x14]
// 00436e0d  7606                 jbe 0x436e15
// 00436e0f  ff15ace98900         call dword ptr [0x89e9ac]
// 00436e15  8b7b04               mov edi, dword ptr [ebx + 4]
// 00436e18  8bee                 mov ebp, esi
// 00436e1a  8b7314               mov esi, dword ptr [ebx + 0x14]
// 00436e1d  897c2420             mov dword ptr [esp + 0x20], edi
// 00436e21  896c2424             mov dword ptr [esp + 0x24], ebp
// 00436e25  8974241c             mov dword ptr [esp + 0x1c], esi
// 00436e29  397310               cmp dword ptr [ebx + 0x10], esi
// 00436e2c  7606                 jbe 0x436e34
// 00436e2e  ff15ace98900         call dword ptr [0x89e9ac]
// 00436e34  8b4304               mov eax, dword ptr [ebx + 4]
// 00436e37  89442468             mov dword ptr [esp + 0x68], eax
// 00436e3b  eb03                 jmp 0x436e40
// 00436e3d  8d4900               lea ecx, [ecx]
// 00436e40  85ff                 test edi, edi
// 00436e42  7406                 je 0x436e4a
// 00436e44  3b7c2468             cmp edi, dword ptr [esp + 0x68]
// 00436e48  7406                 je 0x436e50
// 00436e4a  ff15ace98900         call dword ptr [0x89e9ac]
// 00436e50  3bee                 cmp ebp, esi
// 00436e52  0f8477020000         je 0x4370cf
// 00436e58  85ff                 test edi, edi
// 00436e5a  0f8550010000         jne 0x436fb0
// 00436e60  ff15ace98900         call dword ptr [0x89e9ac]
// 00436e66  33c0                 xor eax, eax
// 00436e68  3b6810               cmp ebp, dword ptr [eax + 0x10]
// 00436e6b  7206                 jb 0x436e73
// 00436e6d  ff15ace98900         call dword ptr [0x89e9ac]
// 00436e73  8b4d00               mov ecx, dword ptr [ebp]
// 00436e76  8d542418             lea edx, [esp + 0x18]
// 00436e7a  52                   push edx
// 00436e7b  8d442434             lea eax, [esp + 0x34]
// 00436e7f  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00436e83  8b8c24c4000000       mov ecx, dword ptr [esp + 0xc4]
// 00436e8a  50                   push eax
// 00436e8b  e8d0d7ffff           call 0x434660
// 00436e90  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 00436e94  85db                 test ebx, ebx
// 00436e96  7406                 je 0x436e9e
// 00436e98  3b5c2428             cmp ebx, dword ptr [esp + 0x28]
// 00436e9c  7406                 je 0x436ea4
// 00436e9e  ff15ace98900         call dword ptr [0x89e9ac]
// 00436ea4  8b742434             mov esi, dword ptr [esp + 0x34]
// 00436ea8  3b74242c             cmp esi, dword ptr [esp + 0x2c]
// 00436eac  0f84c5010000         je 0x437077
// 00436eb2  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 00436eb8  85db                 test ebx, ebx
// 00436eba  0f85f7000000         jne 0x436fb7
// 00436ec0  ffd7                 call edi
// 00436ec2  33c0                 xor eax, eax
// 00436ec4  3b7018               cmp esi, dword ptr [eax + 0x18]
// 00436ec7  7502                 jne 0x436ecb
// 00436ec9  ffd7                 call edi
// 00436ecb  8b6e1c               mov ebp, dword ptr [esi + 0x1c]
// 00436ece  3b6e20               cmp ebp, dword ptr [esi + 0x20]
// 00436ed1  7602                 jbe 0x436ed5
// 00436ed3  ffd7                 call edi
// 00436ed5  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00436ed8  897c2438             mov dword ptr [esp + 0x38], edi
// 00436edc  85db                 test ebx, ebx
// 00436ede  0f85da000000         jne 0x436fbe
// 00436ee4  ff15ace98900         call dword ptr [0x89e9ac]
// 00436eea  33c0                 xor eax, eax
// 00436eec  3b7018               cmp esi, dword ptr [eax + 0x18]
// 00436eef  7506                 jne 0x436ef7
// 00436ef1  ff15ace98900         call dword ptr [0x89e9ac]
// 00436ef7  8b5e20               mov ebx, dword ptr [esi + 0x20]
// 00436efa  895c2418             mov dword ptr [esp + 0x18], ebx
// 00436efe  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 00436f01  7606                 jbe 0x436f09
// 00436f03  ff15ace98900         call dword ptr [0x89e9ac]
// 00436f09  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00436f0c  894c2460             mov dword ptr [esp + 0x60], ecx
// 00436f10  85ff                 test edi, edi
// 00436f12  7406                 je 0x436f1a
// 00436f14  3b7c2460             cmp edi, dword ptr [esp + 0x60]
// 00436f18  7406                 je 0x436f20
// 00436f1a  ff15ace98900         call dword ptr [0x89e9ac]
// 00436f20  3beb                 cmp ebp, ebx
// 00436f22  0f8447010000         je 0x43706f
// 00436f28  807c241300           cmp byte ptr [esp + 0x13], 0
// 00436f2d  0f8599000000         jne 0x436fcc
// 00436f33  85ff                 test edi, edi
// 00436f35  0f858a000000         jne 0x436fc5
// 00436f3b  ff15ace98900         call dword ptr [0x89e9ac]
// 00436f41  33c0                 xor eax, eax
// 00436f43  3b6810               cmp ebp, dword ptr [eax + 0x10]
// 00436f46  7206                 jb 0x436f4e
// 00436f48  ff15ace98900         call dword ptr [0x89e9ac]
// 00436f4e  8b4500               mov eax, dword ptr [ebp]
// 00436f51  8b742414             mov esi, dword ptr [esp + 0x14]
// 00436f55  50                   push eax
// 00436f56  8d542474             lea edx, [esp + 0x74]
// 00436f5a  81c6f4feffff         add esi, 0xfffffef4
// 00436f60  52                   push edx
// 00436f61  8bce                 mov ecx, esi
// 00436f63  e888fcffff           call 0x436bf0
// 00436f68  8bf8                 mov edi, eax
// 00436f6a  57                   push edi
// 00436f6b  8d4c2444             lea ecx, [esp + 0x44]
// 00436f6f  c68424bc00000002     mov byte ptr [esp + 0xbc], 2
// 00436f77  ff1564e48900         call dword ptr [0x89e464]
// 00436f7d  8b471c               mov eax, dword ptr [edi + 0x1c]
// 00436f80  8d4c2470             lea ecx, [esp + 0x70]
// 00436f84  8944245c             mov dword ptr [esp + 0x5c], eax
// 00436f88  c68424b800000001     mov byte ptr [esp + 0xb8], 1
// 00436f90  ff15c4e48900         call dword ptr [0x89e4c4]
// 00436f96  8b16                 mov edx, dword ptr [esi]
// 00436f98  8b92e8000000         mov edx, dword ptr [edx + 0xe8]
// 00436f9e  8d442440             lea eax, [esp + 0x40]
// 00436fa2  50                   push eax
// 00436fa3  8bce                 mov ecx, esi
// 00436fa5  ffd2                 call edx
// 00436fa7  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 00436fab  e98c000000           jmp 0x43703c
// 00436fb0  8b07                 mov eax, dword ptr [edi]
// 00436fb2  e9b1feffff           jmp 0x436e68
// 00436fb7  8b03                 mov eax, dword ptr [ebx]
// 00436fb9  e906ffffff           jmp 0x436ec4
// 00436fbe  8b03                 mov eax, dword ptr [ebx]
// 00436fc0  e927ffffff           jmp 0x436eec
// 00436fc5  8b07                 mov eax, dword ptr [edi]
// 00436fc7  e977ffffff           jmp 0x436f43
// 00436fcc  85ff                 test edi, edi
// 00436fce  0f8590000000         jne 0x437064
// 00436fd4  ff15ace98900         call dword ptr [0x89e9ac]
// 00436fda  33c0                 xor eax, eax
// 00436fdc  3b6810               cmp ebp, dword ptr [eax + 0x10]
// 00436fdf  7206                 jb 0x436fe7
// 00436fe1  ff15ace98900         call dword ptr [0x89e9ac]
// 00436fe7  8b4500               mov eax, dword ptr [ebp]
// 00436fea  8b742414             mov esi, dword ptr [esp + 0x14]
// 00436fee  50                   push eax
// 00436fef  8d842494000000       lea eax, [esp + 0x94]
// 00436ff6  81c6f4feffff         add esi, 0xfffffef4
// 00436ffc  50                   push eax
// 00436ffd  8bce                 mov ecx, esi
// 00436fff  e8ecfbffff           call 0x436bf0
// 00437004  8b16                 mov edx, dword ptr [esi]
// 00437006  8b92ec000000         mov edx, dword ptr [edx + 0xec]
// 0043700c  50                   push eax
// 0043700d  8d442444             lea eax, [esp + 0x44]
// 00437011  50                   push eax
// 00437012  8bce                 mov ecx, esi
// 00437014  c68424c000000003     mov byte ptr [esp + 0xc0], 3
// 0043701c  ffd2                 call edx
// 0043701e  84c0                 test al, al
// 00437020  8d8c2490000000       lea ecx, [esp + 0x90]
// 00437027  0f94c3               sete bl
// 0043702a  c68424b800000001     mov byte ptr [esp + 0xb8], 1
// 00437032  ff15c4e48900         call dword ptr [0x89e4c4]
// 00437038  84db                 test bl, bl
// 0043703a  756a                 jne 0x4370a6
// 0043703c  c644241301           mov byte ptr [esp + 0x13], 1
// 00437041  85ff                 test edi, edi
// 00437043  7526                 jne 0x43706b
// 00437045  ff15ace98900         call dword ptr [0x89e9ac]
// 0043704b  33c0                 xor eax, eax
// 0043704d  3b6810               cmp ebp, dword ptr [eax + 0x10]
// 00437050  7206                 jb 0x437058
// 00437052  ff15ace98900         call dword ptr [0x89e9ac]
// 00437058  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0043705c  83c508               add ebp, 8
// 0043705f  e9acfeffff           jmp 0x436f10
// 00437064  8b07                 mov eax, dword ptr [edi]
// 00437066  e971ffffff           jmp 0x436fdc
// 0043706b  8b07                 mov eax, dword ptr [edi]
// 0043706d  ebde                 jmp 0x43704d
// 0043706f  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00437073  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 00437077  85ff                 test edi, edi
// 00437079  7527                 jne 0x4370a2
// 0043707b  ff15ace98900         call dword ptr [0x89e9ac]
// 00437081  33c0                 xor eax, eax
// 00437083  3b6810               cmp ebp, dword ptr [eax + 0x10]
// 00437086  7206                 jb 0x43708e
// 00437088  ff15ace98900         call dword ptr [0x89e9ac]
// 0043708e  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00437092  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00437096  83c504               add ebp, 4
// 00437099  896c2424             mov dword ptr [esp + 0x24], ebp
// 0043709d  e99efdffff           jmp 0x436e40
// 004370a2  8b07                 mov eax, dword ptr [edi]
// 004370a4  ebdd                 jmp 0x437083
// 004370a6  51                   push ecx
// 004370a7  8bcc                 mov ecx, esp
// 004370a9  89642420             mov dword ptr [esp + 0x20], esp
// 004370ad  6816d28a00           push 0x8ad216
// 004370b2  ff1508fd8900         call dword ptr [0x89fd08]
// 004370b8  8b742418             mov esi, dword ptr [esp + 0x18]
// 004370bc  81c6f4feffff         add esi, 0xfffffef4
// 004370c2  8bce                 mov ecx, esi
// 004370c4  e817313500           call 0x78a1e0
// 004370c9  6a00                 push 0
// 004370cb  8bce                 mov ecx, esi
// 004370cd  eb10                 jmp 0x4370df
// 004370cf  33c0                 xor eax, eax
// 004370d1  38442413             cmp byte ptr [esp + 0x13], al
// 004370d5  8d8bf4feffff         lea ecx, [ebx - 0x10c]
// 004370db  0f94c0               sete al
// 004370de  50                   push eax
// 004370df  e8ec273500           call 0x7898d0
// 004370e4  8d4c2440             lea ecx, [esp + 0x40]
// 004370e8  c78424b8000000ffffffff mov dword ptr [esp + 0xb8], 0xffffffff
// 004370f3  ff15c4e48900         call dword ptr [0x89e4c4]
// 004370f9  8b8c24b0000000       mov ecx, dword ptr [esp + 0xb0]
// 00437100  5f                   pop edi
// 00437101  5e                   pop esi
// 00437102  5d                   pop ebp
// 00437103  64890d00000000       mov dword ptr fs:[0], ecx
// 0043710a  5b                   pop ebx
// 0043710b  81c4ac000000         add esp, 0xac
// 00437111  c20400               ret 4
// copied from an identical function in another client (function ?update@XItem@@UAEXAAV?$map@PBUClassDescriptor@@V?$vector@V?$shared_ptr@UInstance@@@boost@@V?$allocator@V?$shared_ptr@UInstance@@@boost@@@std@@@std@@U?$less@PBUClassDescriptor@@@3@V?$allocator@U?$pair@QBUClassDescriptor@@V?$vector@V?$shared_ptr@UInstance@@@boost@@V?$allocator@V?$shared_ptr@UInstance@@@boost@@@std@@@std@@@std@@@3@@std@@@Z)

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
void* __cdecl getTag();
struct TaggedString {std::string text;void* tag;TaggedString():tag(getTag()){}TaggedString(const TaggedString&v):text(v.text),tag(v.tag){}TaggedString&operator=(const TaggedString&v){text=v.text;tag=v.tag;return *this;}};
struct Instance;
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
 virtual void setCommon(const TaggedString&);
 virtual bool equals(const TaggedString&,const TaggedString&);
 char padding[0x108];
 TaggedString value(Instance*);
 void SetValue(CString);
 void SetHidden(int);
};
struct UpdateBase {virtual void update(Selection&);std::vector<const ClassDescriptor*> classes;};
struct XItem:GridBase,UpdateBase {void update(Selection&);};
void XItem::update(Selection& selection){
 TaggedString common;
 bool foundAny=false;
 Selection::iterator selectionEnd=selection.end();
 for(std::vector<const ClassDescriptor*>::iterator c=classes.begin(),ce=classes.end();c!=ce;++c){
  const ClassDescriptor* key=*c;
  Selection::iterator selected=selection.find(key);
  if(selected!=selectionEnd){
   for(Instances::iterator i=selected->second.begin(),end=selected->second.end();i!=end;++i){
    if(!foundAny){common=value(i->get());setCommon(common);}
    else if(!equals(common,value(i->get()))){
     SetValue(CString(""));
     SetHidden(0);return;
    }
    foundAny=true;
   }
  }
 }
 SetHidden(!foundAny);
}