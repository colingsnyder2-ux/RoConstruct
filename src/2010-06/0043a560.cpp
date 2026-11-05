// from server: 100% by Yeetserama
// roc 2010-06 0043a560  unit: RBX::Soundscape::VSoundId::?$XItem  size: 884 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0043a560
//
// 0043a560  6aff                 push -1
// 0043a562  68610c9800           push 0x980c61
// 0043a567  64a100000000         mov eax, dword ptr fs:[0]
// 0043a56d  50                   push eax
// 0043a56e  64892500000000       mov dword ptr fs:[0], esp
// 0043a575  81eca0000000         sub esp, 0xa0
// 0043a57b  53                   push ebx
// 0043a57c  55                   push ebp
// 0043a57d  56                   push esi
// 0043a57e  8bd9                 mov ebx, ecx
// 0043a580  57                   push edi
// 0043a581  8d4c2440             lea ecx, [esp + 0x40]
// 0043a585  895c2414             mov dword ptr [esp + 0x14], ebx
// 0043a589  ff1504a49e00         call dword ptr [0x9ea404]
// 0043a58f  c78424b800000000000000 mov dword ptr [esp + 0xb8], 0
// 0043a59a  e8519e1500           call 0x5943f0
// 0043a59f  8944245c             mov dword ptr [esp + 0x5c], eax
// 0043a5a3  8b8424c0000000       mov eax, dword ptr [esp + 0xc0]
// 0043a5aa  8b7310               mov esi, dword ptr [ebx + 0x10]
// 0043a5ad  8b4818               mov ecx, dword ptr [eax + 0x18]
// 0043a5b0  8b10                 mov edx, dword ptr [eax]
// 0043a5b2  c78424b800000001000000 mov dword ptr [esp + 0xb8], 1
// 0043a5bd  c644241300           mov byte ptr [esp + 0x13], 0
// 0043a5c2  894c242c             mov dword ptr [esp + 0x2c], ecx
// 0043a5c6  89542428             mov dword ptr [esp + 0x28], edx
// 0043a5ca  3b7314               cmp esi, dword ptr [ebx + 0x14]
// 0043a5cd  7606                 jbe 0x43a5d5
// 0043a5cf  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043a5d5  8b7b04               mov edi, dword ptr [ebx + 4]
// 0043a5d8  8bee                 mov ebp, esi
// 0043a5da  8b7314               mov esi, dword ptr [ebx + 0x14]
// 0043a5dd  897c2420             mov dword ptr [esp + 0x20], edi
// 0043a5e1  896c2424             mov dword ptr [esp + 0x24], ebp
// 0043a5e5  8974241c             mov dword ptr [esp + 0x1c], esi
// 0043a5e9  397310               cmp dword ptr [ebx + 0x10], esi
// 0043a5ec  7606                 jbe 0x43a5f4
// 0043a5ee  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043a5f4  8b4304               mov eax, dword ptr [ebx + 4]
// 0043a5f7  89442468             mov dword ptr [esp + 0x68], eax
// 0043a5fb  eb03                 jmp 0x43a600
// 0043a5fd  8d4900               lea ecx, [ecx]
// 0043a600  85ff                 test edi, edi
// 0043a602  7406                 je 0x43a60a
// 0043a604  3b7c2468             cmp edi, dword ptr [esp + 0x68]
// 0043a608  7406                 je 0x43a610
// 0043a60a  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043a610  3bee                 cmp ebp, esi
// 0043a612  0f8477020000         je 0x43a88f
// 0043a618  85ff                 test edi, edi
// 0043a61a  0f8550010000         jne 0x43a770
// 0043a620  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043a626  33c0                 xor eax, eax
// 0043a628  3b6810               cmp ebp, dword ptr [eax + 0x10]
// 0043a62b  7206                 jb 0x43a633
// 0043a62d  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043a633  8b4d00               mov ecx, dword ptr [ebp]
// 0043a636  8d542418             lea edx, [esp + 0x18]
// 0043a63a  52                   push edx
// 0043a63b  8d442434             lea eax, [esp + 0x34]
// 0043a63f  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0043a643  8b8c24c4000000       mov ecx, dword ptr [esp + 0xc4]
// 0043a64a  50                   push eax
// 0043a64b  e850b5ffff           call 0x435ba0
// 0043a650  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 0043a654  85db                 test ebx, ebx
// 0043a656  7406                 je 0x43a65e
// 0043a658  3b5c2428             cmp ebx, dword ptr [esp + 0x28]
// 0043a65c  7406                 je 0x43a664
// 0043a65e  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043a664  8b742434             mov esi, dword ptr [esp + 0x34]
// 0043a668  3b74242c             cmp esi, dword ptr [esp + 0x2c]
// 0043a66c  0f84c5010000         je 0x43a837
// 0043a672  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 0043a678  85db                 test ebx, ebx
// 0043a67a  0f85f7000000         jne 0x43a777
// 0043a680  ffd7                 call edi
// 0043a682  33c0                 xor eax, eax
// 0043a684  3b7018               cmp esi, dword ptr [eax + 0x18]
// 0043a687  7502                 jne 0x43a68b
// 0043a689  ffd7                 call edi
// 0043a68b  8b6e1c               mov ebp, dword ptr [esi + 0x1c]
// 0043a68e  3b6e20               cmp ebp, dword ptr [esi + 0x20]
// 0043a691  7602                 jbe 0x43a695
// 0043a693  ffd7                 call edi
// 0043a695  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0043a698  897c2438             mov dword ptr [esp + 0x38], edi
// 0043a69c  85db                 test ebx, ebx
// 0043a69e  0f85da000000         jne 0x43a77e
// 0043a6a4  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043a6aa  33c0                 xor eax, eax
// 0043a6ac  3b7018               cmp esi, dword ptr [eax + 0x18]
// 0043a6af  7506                 jne 0x43a6b7
// 0043a6b1  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043a6b7  8b5e20               mov ebx, dword ptr [esi + 0x20]
// 0043a6ba  895c2418             mov dword ptr [esp + 0x18], ebx
// 0043a6be  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 0043a6c1  7606                 jbe 0x43a6c9
// 0043a6c3  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043a6c9  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0043a6cc  894c2460             mov dword ptr [esp + 0x60], ecx
// 0043a6d0  85ff                 test edi, edi
// 0043a6d2  7406                 je 0x43a6da
// 0043a6d4  3b7c2460             cmp edi, dword ptr [esp + 0x60]
// 0043a6d8  7406                 je 0x43a6e0
// 0043a6da  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043a6e0  3beb                 cmp ebp, ebx
// 0043a6e2  0f8447010000         je 0x43a82f
// 0043a6e8  807c241300           cmp byte ptr [esp + 0x13], 0
// 0043a6ed  0f8599000000         jne 0x43a78c
// 0043a6f3  85ff                 test edi, edi
// 0043a6f5  0f858a000000         jne 0x43a785
// 0043a6fb  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043a701  33c0                 xor eax, eax
// 0043a703  3b6810               cmp ebp, dword ptr [eax + 0x10]
// 0043a706  7206                 jb 0x43a70e
// 0043a708  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043a70e  8b4500               mov eax, dword ptr [ebp]
// 0043a711  8b742414             mov esi, dword ptr [esp + 0x14]
// 0043a715  50                   push eax
// 0043a716  8d542474             lea edx, [esp + 0x74]
// 0043a71a  81c6f4feffff         add esi, 0xfffffef4
// 0043a720  52                   push edx
// 0043a721  8bce                 mov ecx, esi
// 0043a723  e8f8fdffff           call 0x43a520
// 0043a728  8bf8                 mov edi, eax
// 0043a72a  57                   push edi
// 0043a72b  8d4c2444             lea ecx, [esp + 0x44]
// 0043a72f  c68424bc00000002     mov byte ptr [esp + 0xbc], 2
// 0043a737  ff1568a49e00         call dword ptr [0x9ea468]
// 0043a73d  8b471c               mov eax, dword ptr [edi + 0x1c]
// 0043a740  8d4c2470             lea ecx, [esp + 0x70]
// 0043a744  8944245c             mov dword ptr [esp + 0x5c], eax
// 0043a748  c68424b800000001     mov byte ptr [esp + 0xb8], 1
// 0043a750  ff1500a49e00         call dword ptr [0x9ea400]
// 0043a756  8b16                 mov edx, dword ptr [esi]
// 0043a758  8b92e8000000         mov edx, dword ptr [edx + 0xe8]
// 0043a75e  8d442440             lea eax, [esp + 0x40]
// 0043a762  50                   push eax
// 0043a763  8bce                 mov ecx, esi
// 0043a765  ffd2                 call edx
// 0043a767  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 0043a76b  e98c000000           jmp 0x43a7fc
// 0043a770  8b07                 mov eax, dword ptr [edi]
// 0043a772  e9b1feffff           jmp 0x43a628
// 0043a777  8b03                 mov eax, dword ptr [ebx]
// 0043a779  e906ffffff           jmp 0x43a684
// 0043a77e  8b03                 mov eax, dword ptr [ebx]
// 0043a780  e927ffffff           jmp 0x43a6ac
// 0043a785  8b07                 mov eax, dword ptr [edi]
// 0043a787  e977ffffff           jmp 0x43a703
// 0043a78c  85ff                 test edi, edi
// 0043a78e  0f8590000000         jne 0x43a824
// 0043a794  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043a79a  33c0                 xor eax, eax
// 0043a79c  3b6810               cmp ebp, dword ptr [eax + 0x10]
// 0043a79f  7206                 jb 0x43a7a7
// 0043a7a1  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043a7a7  8b4500               mov eax, dword ptr [ebp]
// 0043a7aa  8b742414             mov esi, dword ptr [esp + 0x14]
// 0043a7ae  50                   push eax
// 0043a7af  8d842494000000       lea eax, [esp + 0x94]
// 0043a7b6  81c6f4feffff         add esi, 0xfffffef4
// 0043a7bc  50                   push eax
// 0043a7bd  8bce                 mov ecx, esi
// 0043a7bf  e85cfdffff           call 0x43a520
// 0043a7c4  8b16                 mov edx, dword ptr [esi]
// 0043a7c6  8b92ec000000         mov edx, dword ptr [edx + 0xec]
// 0043a7cc  50                   push eax
// 0043a7cd  8d442444             lea eax, [esp + 0x44]
// 0043a7d1  50                   push eax
// 0043a7d2  8bce                 mov ecx, esi
// 0043a7d4  c68424c000000003     mov byte ptr [esp + 0xc0], 3
// 0043a7dc  ffd2                 call edx
// 0043a7de  84c0                 test al, al
// 0043a7e0  8d8c2490000000       lea ecx, [esp + 0x90]
// 0043a7e7  0f94c3               sete bl
// 0043a7ea  c68424b800000001     mov byte ptr [esp + 0xb8], 1
// 0043a7f2  ff1500a49e00         call dword ptr [0x9ea400]
// 0043a7f8  84db                 test bl, bl
// 0043a7fa  756a                 jne 0x43a866
// 0043a7fc  c644241301           mov byte ptr [esp + 0x13], 1
// 0043a801  85ff                 test edi, edi
// 0043a803  7526                 jne 0x43a82b
// 0043a805  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043a80b  33c0                 xor eax, eax
// 0043a80d  3b6810               cmp ebp, dword ptr [eax + 0x10]
// 0043a810  7206                 jb 0x43a818
// 0043a812  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043a818  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0043a81c  83c508               add ebp, 8
// 0043a81f  e9acfeffff           jmp 0x43a6d0
// 0043a824  8b07                 mov eax, dword ptr [edi]
// 0043a826  e971ffffff           jmp 0x43a79c
// 0043a82b  8b07                 mov eax, dword ptr [edi]
// 0043a82d  ebde                 jmp 0x43a80d
// 0043a82f  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0043a833  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0043a837  85ff                 test edi, edi
// 0043a839  7527                 jne 0x43a862
// 0043a83b  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043a841  33c0                 xor eax, eax
// 0043a843  3b6810               cmp ebp, dword ptr [eax + 0x10]
// 0043a846  7206                 jb 0x43a84e
// 0043a848  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043a84e  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0043a852  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0043a856  83c504               add ebp, 4
// 0043a859  896c2424             mov dword ptr [esp + 0x24], ebp
// 0043a85d  e99efdffff           jmp 0x43a600
// 0043a862  8b07                 mov eax, dword ptr [edi]
// 0043a864  ebdd                 jmp 0x43a843
// 0043a866  51                   push ecx
// 0043a867  8bcc                 mov ecx, esp
// 0043a869  89642420             mov dword ptr [esp + 0x20], esp
// 0043a86d  68fe08a000           push 0xa008fe
// 0043a872  ff15e8ce9e00         call dword ptr [0x9ecee8]
// 0043a878  8b742418             mov esi, dword ptr [esp + 0x18]
// 0043a87c  81c6f4feffff         add esi, 0xfffffef4
// 0043a882  8bce                 mov ecx, esi
// 0043a884  e827e93d00           call 0x8191b0
// 0043a889  6a00                 push 0
// 0043a88b  8bce                 mov ecx, esi
// 0043a88d  eb10                 jmp 0x43a89f
// 0043a88f  33c0                 xor eax, eax
// 0043a891  38442413             cmp byte ptr [esp + 0x13], al
// 0043a895  8d8bf4feffff         lea ecx, [ebx - 0x10c]
// 0043a89b  0f94c0               sete al
// 0043a89e  50                   push eax
// 0043a89f  e80ce03d00           call 0x8188b0
// 0043a8a4  8d4c2440             lea ecx, [esp + 0x40]
// 0043a8a8  c78424b8000000ffffffff mov dword ptr [esp + 0xb8], 0xffffffff
// 0043a8b3  ff1500a49e00         call dword ptr [0x9ea400]
// 0043a8b9  8b8c24b0000000       mov ecx, dword ptr [esp + 0xb0]
// 0043a8c0  5f                   pop edi
// 0043a8c1  5e                   pop esi
// 0043a8c2  5d                   pop ebp
// 0043a8c3  64890d00000000       mov dword ptr fs:[0], ecx
// 0043a8ca  5b                   pop ebx
// 0043a8cb  81c4ac000000         add esp, 0xac
// 0043a8d1  c20400               ret 4
// copied from an identical function in another client (function ?update@XItem@@UAEXAAV?$map@PBUClassDescriptor@@V?$vector@V?$shared_ptr@UInstance@@@boost@@V?$allocator@V?$shared_ptr@UInstance@@@boost@@@std@@@std@@U?$less@PBUClassDescriptor@@@3@V?$allocator@U?$pair@QBUClassDescriptor@@V?$vector@V?$shared_ptr@UInstance@@@boost@@V?$allocator@V?$shared_ptr@UInstance@@@boost@@@std@@@std@@@std@@@3@@std@@@Z)

// from server: 100% by king_originala
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