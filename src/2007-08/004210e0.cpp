// from server: 100% by Intel
// from server: 99% by EspClaude
// roc 2007-08 004210e0  unit: CSelectionTreeCtrl  size: 246 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004210e0
//
// 004210e0  6aff                 push -1
// 004210e2  6858bc7300           push 0x73bc58
// 004210e7  64a100000000         mov eax, dword ptr fs:[0]
// 004210ed  50                   push eax
// 004210ee  83ec18               sub esp, 0x18
// 004210f1  53                   push ebx
// 004210f2  55                   push ebp
// 004210f3  56                   push esi
// 004210f4  57                   push edi
// 004210f5  a188518b00           mov eax, dword ptr [0x8b5188]
// 004210fa  33c4                 xor eax, esp
// 004210fc  50                   push eax
// 004210fd  8d44242c             lea eax, [esp + 0x2c]
// 00421101  64a300000000         mov dword ptr fs:[0], eax
// 00421107  8bf1                 mov esi, ecx
// 00421109  8b6c243c             mov ebp, dword ptr [esp + 0x3c]
// 0042110d  85ed                 test ebp, ebp
// 0042110f  0f84a9000000         je 0x4211be
// 00421115  55                   push ebp
// 00421116  e893f32000           call 0x6304ae
// 0042111b  85c0                 test eax, eax
// 0042111d  0f849b000000         je 0x4211be
// 00421123  8b580c               mov ebx, dword ptr [eax + 0xc]
// 00421126  8b4010               mov eax, dword ptr [eax + 0x10]
// 00421129  85c0                 test eax, eax
// 0042112b  895c2414             mov dword ptr [esp + 0x14], ebx
// 0042112f  89442418             mov dword ptr [esp + 0x18], eax
// 00421133  740c                 je 0x421141
// 00421135  83c004               add eax, 4
// 00421138  b901000000           mov ecx, 1
// 0042113d  f00fc108             lock xadd dword ptr [eax], ecx
// 00421141  85db                 test ebx, ebx
// 00421143  c744243400000000     mov dword ptr [esp + 0x34], 0
// 0042114b  7460                 je 0x4211ad
// 0042114d  8b06                 mov eax, dword ptr [esi]
// 0042114f  8d54241c             lea edx, [esp + 0x1c]
// 00421153  52                   push edx
// 00421154  8b9048010000         mov edx, dword ptr [eax + 0x148]
// 0042115a  8bce                 mov ecx, esi
// 0042115c  ffd2                 call edx
// 0042115e  8bc8                 mov ecx, eax
// 00421160  e84becfeff           call 0x40fdb0
// 00421165  8b16                 mov edx, dword ptr [esi]
// 00421167  8bf8                 mov edi, eax
// 00421169  8d442424             lea eax, [esp + 0x24]
// 0042116d  50                   push eax
// 0042116e  8b8248010000         mov eax, dword ptr [edx + 0x148]
// 00421174  8bce                 mov ecx, esi
// 00421176  ffd0                 call eax
// 00421178  8bc8                 mov ecx, eax
// 0042117a  e801ecfeff           call 0x40fd80
// 0042117f  8b4f04               mov ecx, dword ptr [edi + 4]
// 00421182  8b17                 mov edx, dword ptr [edi]
// 00421184  51                   push ecx
// 00421185  8b4804               mov ecx, dword ptr [eax + 4]
// 00421188  52                   push edx
// 00421189  8b10                 mov edx, dword ptr [eax]
// 0042118b  51                   push ecx
// 0042118c  52                   push edx
// 0042118d  8bcb                 mov ecx, ebx
// 0042118f  e88cf3ffff           call 0x420520
// 00421194  84c0                 test al, al
// 00421196  7415                 je 0x4211ad
// 00421198  8d4c2414             lea ecx, [esp + 0x14]
// 0042119c  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 004211a4  e8b7110700           call 0x492360
// 004211a9  8bc5                 mov eax, ebp
// 004211ab  eb13                 jmp 0x4211c0
// 004211ad  8d4c2414             lea ecx, [esp + 0x14]
// 004211b1  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 004211b9  e8a2110700           call 0x492360
// 004211be  33c0                 xor eax, eax
// 004211c0  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004211c4  64890d00000000       mov dword ptr fs:[0], ecx
// 004211cb  59                   pop ecx
// 004211cc  5f                   pop edi
// 004211cd  5e                   pop esi
// 004211ce  5d                   pop ebp
// 004211cf  5b                   pop ebx
// 004211d0  83c424               add esp, 0x24
// 004211d3  c20400               ret 4

// from server: 100% by king_originala
// roc-cl: 50727
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
    __declspec(noinline) ~shared_ptr(){}
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

struct Iterator {void* owner;void* position;};
struct Instance {bool acceptChildren(Iterator,Iterator);};
struct ItemData {char unused[12];boost::shared_ptr<Instance> instance;};
struct Selection {Iterator begin()const;Iterator end()const;};
struct TreeCtrl {
 unsigned long GetItemData(void*)const;
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
 virtual void v31();
 virtual void v32();
 virtual void v33();
 virtual void v34();
 virtual void v35();
 virtual void v36();
 virtual void v37();
 virtual void v38();
 virtual void v39();
 virtual void v40();
 virtual void v41();
 virtual void v42();
 virtual void v43();
 virtual void v44();
 virtual void v45();
 virtual void v46();
 virtual void v47();
 virtual void v48();
 virtual void v49();
 virtual void v50();
 virtual void v51();
 virtual void v52();
 virtual void v53();
 virtual void v54();
 virtual void v55();
 virtual void v56();
 virtual void v57();
 virtual void v58();
 virtual void v59();
 virtual void v60();
 virtual void v61();
 virtual void v62();
 virtual void v63();
 virtual void v64();
 virtual void v65();
 virtual void v66();
 virtual void v67();
 virtual void v68();
 virtual void v69();
 virtual void v70();
 virtual void v71();
 virtual void v72();
 virtual void v73();
 virtual void v74();
 virtual void v75();
 virtual void v76();
 virtual void v77();
 virtual void v78();
 virtual void v79();
 virtual void v80();
 virtual void v81();
 virtual Selection* getSelection();
};
struct CSelectionTreeCtrl:TreeCtrl {void* findAccepting(void*);};
void* CSelectionTreeCtrl::findAccepting(void* item){
 if(!item)return 0;
 ItemData* data=reinterpret_cast<ItemData*>(GetItemData(item));
 if(data){
  boost::shared_ptr<Instance> instance=data->instance;
  if(instance.get()&&instance->acceptChildren(getSelection()->begin(),getSelection()->end()))
   return item;
 }
 return 0;
}
