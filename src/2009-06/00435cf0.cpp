// from server: 100% by EspClaude
// roc 2009-06 00435cf0  unit: std::D::DU?$char_traits::V?$basic_string::?$XItem  size: 831 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00435cf0
//
// 00435cf0  6aff                 push -1
// 00435cf2  680bfb8400           push 0x84fb0b
// 00435cf7  64a100000000         mov eax, dword ptr fs:[0]
// 00435cfd  50                   push eax
// 00435cfe  64892500000000       mov dword ptr fs:[0], esp
// 00435d05  81ec8c000000         sub esp, 0x8c
// 00435d0b  53                   push ebx
// 00435d0c  55                   push ebp
// 00435d0d  56                   push esi
// 00435d0e  8bd9                 mov ebx, ecx
// 00435d10  57                   push edi
// 00435d11  8d4c2448             lea ecx, [esp + 0x48]
// 00435d15  895c2414             mov dword ptr [esp + 0x14], ebx
// 00435d19  ff15c0e48900         call dword ptr [0x89e4c0]
// 00435d1f  8b8424ac000000       mov eax, dword ptr [esp + 0xac]
// 00435d26  8b7310               mov esi, dword ptr [ebx + 0x10]
// 00435d29  8b4818               mov ecx, dword ptr [eax + 0x18]
// 00435d2c  8b10                 mov edx, dword ptr [eax]
// 00435d2e  c78424a400000000000000 mov dword ptr [esp + 0xa4], 0
// 00435d39  c644241300           mov byte ptr [esp + 0x13], 0
// 00435d3e  894c242c             mov dword ptr [esp + 0x2c], ecx
// 00435d42  89542428             mov dword ptr [esp + 0x28], edx
// 00435d46  3b7314               cmp esi, dword ptr [ebx + 0x14]
// 00435d49  7606                 jbe 0x435d51
// 00435d4b  ff15ace98900         call dword ptr [0x89e9ac]
// 00435d51  8b6b04               mov ebp, dword ptr [ebx + 4]
// 00435d54  8bfe                 mov edi, esi
// 00435d56  8b7314               mov esi, dword ptr [ebx + 0x14]
// 00435d59  896c2420             mov dword ptr [esp + 0x20], ebp
// 00435d5d  897c2424             mov dword ptr [esp + 0x24], edi
// 00435d61  8974241c             mov dword ptr [esp + 0x1c], esi
// 00435d65  397310               cmp dword ptr [ebx + 0x10], esi
// 00435d68  7606                 jbe 0x435d70
// 00435d6a  ff15ace98900         call dword ptr [0x89e9ac]
// 00435d70  8b4304               mov eax, dword ptr [ebx + 4]
// 00435d73  89442440             mov dword ptr [esp + 0x40], eax
// 00435d77  85ed                 test ebp, ebp
// 00435d79  7406                 je 0x435d81
// 00435d7b  3b6c2440             cmp ebp, dword ptr [esp + 0x40]
// 00435d7f  7406                 je 0x435d87
// 00435d81  ff15ace98900         call dword ptr [0x89e9ac]
// 00435d87  3bfe                 cmp edi, esi
// 00435d89  0f845b020000         je 0x435fea
// 00435d8f  85ed                 test ebp, ebp
// 00435d91  0f8535010000         jne 0x435ecc
// 00435d97  ff15ace98900         call dword ptr [0x89e9ac]
// 00435d9d  33c0                 xor eax, eax
// 00435d9f  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00435da2  7206                 jb 0x435daa
// 00435da4  ff15ace98900         call dword ptr [0x89e9ac]
// 00435daa  8b0f                 mov ecx, dword ptr [edi]
// 00435dac  8d542418             lea edx, [esp + 0x18]
// 00435db0  52                   push edx
// 00435db1  8d442434             lea eax, [esp + 0x34]
// 00435db5  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00435db9  8b8c24b0000000       mov ecx, dword ptr [esp + 0xb0]
// 00435dc0  50                   push eax
// 00435dc1  e89ae8ffff           call 0x434660
// 00435dc6  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 00435dca  85db                 test ebx, ebx
// 00435dcc  7406                 je 0x435dd4
// 00435dce  3b5c2428             cmp ebx, dword ptr [esp + 0x28]
// 00435dd2  7406                 je 0x435dda
// 00435dd4  ff15ace98900         call dword ptr [0x89e9ac]
// 00435dda  8b742434             mov esi, dword ptr [esp + 0x34]
// 00435dde  3b74242c             cmp esi, dword ptr [esp + 0x2c]
// 00435de2  0f84a9010000         je 0x435f91
// 00435de8  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 00435dee  85db                 test ebx, ebx
// 00435df0  0f85de000000         jne 0x435ed4
// 00435df6  ffd5                 call ebp
// 00435df8  33c0                 xor eax, eax
// 00435dfa  3b7018               cmp esi, dword ptr [eax + 0x18]
// 00435dfd  7502                 jne 0x435e01
// 00435dff  ffd5                 call ebp
// 00435e01  8b7e1c               mov edi, dword ptr [esi + 0x1c]
// 00435e04  3b7e20               cmp edi, dword ptr [esi + 0x20]
// 00435e07  7602                 jbe 0x435e0b
// 00435e09  ffd5                 call ebp
// 00435e0b  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 00435e0e  85db                 test ebx, ebx
// 00435e10  0f85c5000000         jne 0x435edb
// 00435e16  ff15ace98900         call dword ptr [0x89e9ac]
// 00435e1c  3b7318               cmp esi, dword ptr [ebx + 0x18]
// 00435e1f  7506                 jne 0x435e27
// 00435e21  ff15ace98900         call dword ptr [0x89e9ac]
// 00435e27  8b5e20               mov ebx, dword ptr [esi + 0x20]
// 00435e2a  895c2418             mov dword ptr [esp + 0x18], ebx
// 00435e2e  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 00435e31  7606                 jbe 0x435e39
// 00435e33  ff15ace98900         call dword ptr [0x89e9ac]
// 00435e39  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00435e3c  894c2438             mov dword ptr [esp + 0x38], ecx
// 00435e40  85ed                 test ebp, ebp
// 00435e42  7406                 je 0x435e4a
// 00435e44  3b6c2438             cmp ebp, dword ptr [esp + 0x38]
// 00435e48  7406                 je 0x435e50
// 00435e4a  ff15ace98900         call dword ptr [0x89e9ac]
// 00435e50  3bfb                 cmp edi, ebx
// 00435e52  0f8431010000         je 0x435f89
// 00435e58  807c241300           cmp byte ptr [esp + 0x13], 0
// 00435e5d  0f8584000000         jne 0x435ee7
// 00435e63  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 00435e69  85ed                 test ebp, ebp
// 00435e6b  7575                 jne 0x435ee2
// 00435e6d  ffd3                 call ebx
// 00435e6f  33c0                 xor eax, eax
// 00435e71  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00435e74  7202                 jb 0x435e78
// 00435e76  ffd3                 call ebx
// 00435e78  8b07                 mov eax, dword ptr [edi]
// 00435e7a  8b742414             mov esi, dword ptr [esp + 0x14]
// 00435e7e  50                   push eax
// 00435e7f  8d542468             lea edx, [esp + 0x68]
// 00435e83  81c6f4feffff         add esi, 0xfffffef4
// 00435e89  52                   push edx
// 00435e8a  8bce                 mov ecx, esi
// 00435e8c  e8dffbffff           call 0x435a70
// 00435e91  50                   push eax
// 00435e92  8d4c244c             lea ecx, [esp + 0x4c]
// 00435e96  c68424a800000001     mov byte ptr [esp + 0xa8], 1
// 00435e9e  ff1564e48900         call dword ptr [0x89e464]
// 00435ea4  8d4c2464             lea ecx, [esp + 0x64]
// 00435ea8  c68424a400000000     mov byte ptr [esp + 0xa4], 0
// 00435eb0  ff15c4e48900         call dword ptr [0x89e4c4]
// 00435eb6  8b06                 mov eax, dword ptr [esi]
// 00435eb8  8b90e8000000         mov edx, dword ptr [eax + 0xe8]
// 00435ebe  8d4c2448             lea ecx, [esp + 0x48]
// 00435ec2  51                   push ecx
// 00435ec3  8bce                 mov ecx, esi
// 00435ec5  ffd2                 call edx
// 00435ec7  e990000000           jmp 0x435f5c
// 00435ecc  8b4500               mov eax, dword ptr [ebp]
// 00435ecf  e9cbfeffff           jmp 0x435d9f
// 00435ed4  8b03                 mov eax, dword ptr [ebx]
// 00435ed6  e91fffffff           jmp 0x435dfa
// 00435edb  8b1b                 mov ebx, dword ptr [ebx]
// 00435edd  e93affffff           jmp 0x435e1c
// 00435ee2  8b4500               mov eax, dword ptr [ebp]
// 00435ee5  eb8a                 jmp 0x435e71
// 00435ee7  85ed                 test ebp, ebp
// 00435ee9  0f858d000000         jne 0x435f7c
// 00435eef  ff15ace98900         call dword ptr [0x89e9ac]
// 00435ef5  33c0                 xor eax, eax
// 00435ef7  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00435efa  7206                 jb 0x435f02
// 00435efc  ff15ace98900         call dword ptr [0x89e9ac]
// 00435f02  8b07                 mov eax, dword ptr [edi]
// 00435f04  8b742414             mov esi, dword ptr [esp + 0x14]
// 00435f08  50                   push eax
// 00435f09  8d842484000000       lea eax, [esp + 0x84]
// 00435f10  81c6f4feffff         add esi, 0xfffffef4
// 00435f16  50                   push eax
// 00435f17  8bce                 mov ecx, esi
// 00435f19  e852fbffff           call 0x435a70
// 00435f1e  8b16                 mov edx, dword ptr [esi]
// 00435f20  8b92ec000000         mov edx, dword ptr [edx + 0xec]
// 00435f26  50                   push eax
// 00435f27  8d44244c             lea eax, [esp + 0x4c]
// 00435f2b  50                   push eax
// 00435f2c  8bce                 mov ecx, esi
// 00435f2e  c68424ac00000002     mov byte ptr [esp + 0xac], 2
// 00435f36  ffd2                 call edx
// 00435f38  84c0                 test al, al
// 00435f3a  8d8c2480000000       lea ecx, [esp + 0x80]
// 00435f41  0f94c3               sete bl
// 00435f44  c68424a400000000     mov byte ptr [esp + 0xa4], 0
// 00435f4c  ff15c4e48900         call dword ptr [0x89e4c4]
// 00435f52  84db                 test bl, bl
// 00435f54  756b                 jne 0x435fc1
// 00435f56  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 00435f5c  c644241301           mov byte ptr [esp + 0x13], 1
// 00435f61  85ed                 test ebp, ebp
// 00435f63  751f                 jne 0x435f84
// 00435f65  ffd3                 call ebx
// 00435f67  33c0                 xor eax, eax
// 00435f69  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00435f6c  7202                 jb 0x435f70
// 00435f6e  ffd3                 call ebx
// 00435f70  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00435f74  83c708               add edi, 8
// 00435f77  e9c4feffff           jmp 0x435e40
// 00435f7c  8b4500               mov eax, dword ptr [ebp]
// 00435f7f  e973ffffff           jmp 0x435ef7
// 00435f84  8b4500               mov eax, dword ptr [ebp]
// 00435f87  ebe0                 jmp 0x435f69
// 00435f89  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00435f8d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00435f91  85ed                 test ebp, ebp
// 00435f93  7527                 jne 0x435fbc
// 00435f95  ff15ace98900         call dword ptr [0x89e9ac]
// 00435f9b  33c0                 xor eax, eax
// 00435f9d  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00435fa0  7206                 jb 0x435fa8
// 00435fa2  ff15ace98900         call dword ptr [0x89e9ac]
// 00435fa8  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00435fac  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00435fb0  83c704               add edi, 4
// 00435fb3  897c2424             mov dword ptr [esp + 0x24], edi
// 00435fb7  e9bbfdffff           jmp 0x435d77
// 00435fbc  8b4500               mov eax, dword ptr [ebp]
// 00435fbf  ebdc                 jmp 0x435f9d
// 00435fc1  51                   push ecx
// 00435fc2  8bcc                 mov ecx, esp
// 00435fc4  89642420             mov dword ptr [esp + 0x20], esp
// 00435fc8  6816d28a00           push 0x8ad216
// 00435fcd  ff1508fd8900         call dword ptr [0x89fd08]
// 00435fd3  8b742418             mov esi, dword ptr [esp + 0x18]
// 00435fd7  81c6f4feffff         add esi, 0xfffffef4
// 00435fdd  8bce                 mov ecx, esi
// 00435fdf  e8fc413500           call 0x78a1e0
// 00435fe4  6a00                 push 0
// 00435fe6  8bce                 mov ecx, esi
// 00435fe8  eb10                 jmp 0x435ffa
// 00435fea  33c0                 xor eax, eax
// 00435fec  38442413             cmp byte ptr [esp + 0x13], al
// 00435ff0  8d8bf4feffff         lea ecx, [ebx - 0x10c]
// 00435ff6  0f94c0               sete al
// 00435ff9  50                   push eax
// 00435ffa  e8d1383500           call 0x7898d0
// 00435fff  8d4c2448             lea ecx, [esp + 0x48]
// 00436003  c78424a4000000ffffffff mov dword ptr [esp + 0xa4], 0xffffffff
// 0043600e  ff15c4e48900         call dword ptr [0x89e4c4]
// 00436014  8b8c249c000000       mov ecx, dword ptr [esp + 0x9c]
// 0043601b  5f                   pop edi
// 0043601c  5e                   pop esi
// 0043601d  5d                   pop ebp
// 0043601e  64890d00000000       mov dword ptr fs:[0], ecx
// 00436025  5b                   pop ebx
// 00436026  81c498000000         add esp, 0x98
// 0043602c  c20400               ret 4
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
 virtual void setCommon(const std::string&);
 virtual bool equals(const std::string&,const std::string&);
 char padding[0x108];
 std::string value(Instance*);
 void SetValue(CString);
 void SetHidden(int);
};
struct UpdateBase {virtual void update(Selection&);std::vector<const ClassDescriptor*> classes;};
struct XItem:GridBase,UpdateBase {void update(Selection&);};
void XItem::update(Selection& selection){
 std::string common;
 bool foundAny=false;
 Selection::iterator selectionEnd=selection.end();
 for(std::vector<const ClassDescriptor*>::const_iterator c=classes.begin(),ce=classes.end();c!=ce;++c){
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