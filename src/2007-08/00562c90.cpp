// from server: 100% by EspClaude
// from server: 78% by EspClaude
// roc 2007-08 00562c90  unit: RBX::TrackCameraCommand  size: 264 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00562c90
//
// 00562c90  64a100000000         mov eax, dword ptr fs:[0]
// 00562c96  6aff                 push -1
// 00562c98  68d8bc7500           push 0x75bcd8
// 00562c9d  50                   push eax
// 00562c9e  64892500000000       mov dword ptr fs:[0], esp
// 00562ca5  83ec08               sub esp, 8
// 00562ca8  53                   push ebx
// 00562ca9  8bd9                 mov ebx, ecx
// 00562cab  8b4b20               mov ecx, dword ptr [ebx + 0x20]
// 00562cae  85c9                 test ecx, ecx
// 00562cb0  56                   push esi
// 00562cb1  7407                 je 0x562cba
// 00562cb3  e888e0eaff           call 0x410d40
// 00562cb8  eb02                 jmp 0x562cbc
// 00562cba  33c0                 xor eax, eax
// 00562cbc  8d4c2408             lea ecx, [esp + 8]
// 00562cc0  51                   push ecx
// 00562cc1  8bc8                 mov ecx, eax
// 00562cc3  e8c8cfeaff           call 0x40fc90
// 00562cc8  8b00                 mov eax, dword ptr [eax]
// 00562cca  6a00                 push 0
// 00562ccc  68c08f8900           push 0x898fc0
// 00562cd1  684c1f8800           push 0x881f4c
// 00562cd6  6a00                 push 0
// 00562cd8  50                   push eax
// 00562cd9  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00562ce1  e850e00c00           call 0x630d36
// 00562ce6  8bf0                 mov esi, eax
// 00562ce8  8b442420             mov eax, dword ptr [esp + 0x20]
// 00562cec  83c414               add esp, 0x14
// 00562cef  85c0                 test eax, eax
// 00562cf1  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00562cf9  742e                 je 0x562d29
// 00562cfb  57                   push edi
// 00562cfc  8bf8                 mov edi, eax
// 00562cfe  83c004               add eax, 4
// 00562d01  83caff               or edx, 0xffffffff
// 00562d04  f00fc110             lock xadd dword ptr [eax], edx
// 00562d08  751e                 jne 0x562d28
// 00562d0a  8b07                 mov eax, dword ptr [edi]
// 00562d0c  8b5004               mov edx, dword ptr [eax + 4]
// 00562d0f  8bcf                 mov ecx, edi
// 00562d11  ffd2                 call edx
// 00562d13  8d4708               lea eax, [edi + 8]
// 00562d16  83c9ff               or ecx, 0xffffffff
// 00562d19  f00fc108             lock xadd dword ptr [eax], ecx
// 00562d1d  7509                 jne 0x562d28
// 00562d1f  8b17                 mov edx, dword ptr [edi]
// 00562d21  8b4208               mov eax, dword ptr [edx + 8]
// 00562d24  8bcf                 mov ecx, edi
// 00562d26  ffd0                 call eax
// 00562d28  5f                   pop edi
// 00562d29  85f6                 test esi, esi
// 00562d2b  7439                 je 0x562d66
// 00562d2d  8b430c               mov eax, dword ptr [ebx + 0xc]
// 00562d30  8b9028020000         mov edx, dword ptr [eax + 0x228]
// 00562d36  8d8828020000         lea ecx, [eax + 0x228]
// 00562d3c  8b4204               mov eax, dword ptr [edx + 4]
// 00562d3f  56                   push esi
// 00562d40  ffd0                 call eax
// 00562d42  8bc8                 mov ecx, eax
// 00562d44  e8b7890300           call 0x59b700
// 00562d49  8b430c               mov eax, dword ptr [ebx + 0xc]
// 00562d4c  8b9028020000         mov edx, dword ptr [eax + 0x228]
// 00562d52  8d8828020000         lea ecx, [eax + 0x228]
// 00562d58  8b4204               mov eax, dword ptr [edx + 4]
// 00562d5b  6a03                 push 3
// 00562d5d  ffd0                 call eax
// 00562d5f  8bc8                 mov ecx, eax
// 00562d61  e85a890300           call 0x59b6c0
// 00562d66  8b742420             mov esi, dword ptr [esp + 0x20]
// 00562d6a  6aff                 push -1
// 00562d6c  8bce                 mov ecx, esi
// 00562d6e  e83ddbeaff           call 0x4108b0
// 00562d73  8b16                 mov edx, dword ptr [esi]
// 00562d75  8b4204               mov eax, dword ptr [edx + 4]
// 00562d78  6a01                 push 1
// 00562d7a  8bce                 mov ecx, esi
// 00562d7c  c74604ffffffff       mov dword ptr [esi + 4], 0xffffffff
// 00562d83  ffd0                 call eax
// 00562d85  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00562d89  5e                   pop esi
// 00562d8a  5b                   pop ebx
// 00562d8b  64890d00000000       mov dword ptr fs:[0], ecx
// 00562d92  83c414               add esp, 0x14
// 00562d95  c20400               ret 4

// from server: 100% by king_originala
// roc 2008-06 005813f0  unit: RBX::TrackCameraCommand  size: 278 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005813f0
//
// 005813f0  64a100000000         mov eax, dword ptr fs:[0]
// 005813f6  6aff                 push -1
// 005813f8  6868917d00           push 0x7d9168
// 005813fd  50                   push eax
// 005813fe  64892500000000       mov dword ptr fs:[0], esp
// 00581405  83ec08               sub esp, 8
// 00581408  56                   push esi
// 00581409  8bf1                 mov esi, ecx
// 0058140b  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0058140e  57                   push edi
// 0058140f  85c9                 test ecx, ecx
// 00581411  7407                 je 0x58141a
// 00581413  e8983fe9ff           call 0x4153b0
// 00581418  eb02                 jmp 0x58141c
// 0058141a  33c0                 xor eax, eax
// 0058141c  8d4c2408             lea ecx, [esp + 8]
// 00581420  51                   push ecx
// 00581421  8bc8                 mov ecx, eax
// 00581423  e8f827e9ff           call 0x413c20
// 00581428  8b00                 mov eax, dword ptr [eax]
// 0058142a  6a00                 push 0
// 0058142c  681c7f9400           push 0x947f1c
// 00581431  687c909200           push 0x92907c
// 00581436  6a00                 push 0
// 00581438  50                   push eax
// 00581439  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00581441  e880031200           call 0x6a17c6
// 00581446  8bf8                 mov edi, eax
// 00581448  8b442420             mov eax, dword ptr [esp + 0x20]
// 0058144c  83c414               add esp, 0x14
// 0058144f  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00581457  85c0                 test eax, eax
// 00581459  742e                 je 0x581489
// 0058145b  53                   push ebx
// 0058145c  8bd8                 mov ebx, eax
// 0058145e  83c004               add eax, 4
// 00581461  83caff               or edx, 0xffffffff
// 00581464  f00fc110             lock xadd dword ptr [eax], edx
// 00581468  751e                 jne 0x581488
// 0058146a  8b03                 mov eax, dword ptr [ebx]
// 0058146c  8b5004               mov edx, dword ptr [eax + 4]
// 0058146f  8bcb                 mov ecx, ebx
// 00581471  ffd2                 call edx
// 00581473  8d4308               lea eax, [ebx + 8]
// 00581476  83c9ff               or ecx, 0xffffffff
// 00581479  f00fc108             lock xadd dword ptr [eax], ecx
// 0058147d  7509                 jne 0x581488
// 0058147f  8b13                 mov edx, dword ptr [ebx]
// 00581481  8b4208               mov eax, dword ptr [edx + 8]
// 00581484  8bcb                 mov ecx, ebx
// 00581486  ffd0                 call eax
// 00581488  5b                   pop ebx
// 00581489  85ff                 test edi, edi
// 0058148b  7439                 je 0x5814c6
// 0058148d  8b460c               mov eax, dword ptr [esi + 0xc]
// 00581490  8b9088020000         mov edx, dword ptr [eax + 0x288]
// 00581496  8d8888020000         lea ecx, [eax + 0x288]
// 0058149c  8b4204               mov eax, dword ptr [edx + 4]
// 0058149f  57                   push edi
// 005814a0  ffd0                 call eax
// 005814a2  8bc8                 mov ecx, eax
// 005814a4  e867c90400           call 0x5cde10
// 005814a9  8b460c               mov eax, dword ptr [esi + 0xc]
// 005814ac  8b9088020000         mov edx, dword ptr [eax + 0x288]
// 005814b2  8d8888020000         lea ecx, [eax + 0x288]
// 005814b8  8b4204               mov eax, dword ptr [edx + 4]
// 005814bb  6a03                 push 3
// 005814bd  ffd0                 call eax
// 005814bf  8bc8                 mov ecx, eax
// 005814c1  e80ac90400           call 0x5cddd0
// 005814c6  8b4604               mov eax, dword ptr [esi + 4]
// 005814c9  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 005814cc  83c004               add eax, 4
// 005814cf  83781810             cmp dword ptr [eax + 0x18], 0x10
// 005814d3  5f                   pop edi
// 005814d4  5e                   pop esi
// 005814d5  7205                 jb 0x5814dc
// 005814d7  8b4004               mov eax, dword ptr [eax + 4]
// 005814da  eb03                 jmp 0x5814df
// 005814dc  83c004               add eax, 4
// 005814df  51                   push ecx
// 005814e0  50                   push eax
// 005814e1  e8dab00000           call 0x58c5c0
// 005814e6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005814ea  8b11                 mov edx, dword ptr [ecx]
// 005814ec  8b02                 mov eax, dword ptr [edx]
// 005814ee  83c408               add esp, 8
// 005814f1  6a01                 push 1
// 005814f3  ffd0                 call eax
// 005814f5  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005814f9  64890d00000000       mov dword ptr fs:[0], ecx
// 00581500  83c414               add esp, 0x14
// 00581503  c20400               ret 4

// from server: 97% by Espeon
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
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

#include <string>
namespace RBX {
class Instance {public:virtual ~Instance();};
class PVInstance:public Instance {};
struct Selection {boost::shared_ptr<Instance> first();};
struct Context {Selection* selection();};
struct Camera {void setSubject(PVInstance*);void setType(int);};
struct CameraOwner {virtual ~CameraOwner();virtual Camera* getCamera();};
struct Workspace {char pad[0x228];CameraOwner cameraOwner;};
struct Name {int id;std::string text;const char* c_str()const{return text.c_str();}};
struct IDataState {virtual void slot0();virtual void setDirty(bool)=0;int field4;void func_4108b0(int);};
void __cdecl trackVerb(const char*,Workspace*);
struct TrackCameraCommand {
 void* table;
 const Name* name;
 void* unused;
 Workspace* workspace;
 char pad[0x10];
 Context* context;
 void doIt(IDataState*);
};
void TrackCameraCommand::doIt(IDataState* state){
 PVInstance* subject=dynamic_cast<PVInstance*>((context?context->selection():0)->first().get());
 if(subject){
  workspace->cameraOwner.getCamera()->setSubject(subject);
  workspace->cameraOwner.getCamera()->setType(3);
 }
 state->func_4108b0(-1);
 state->field4=-1;
 state->setDirty(true);
}
}
