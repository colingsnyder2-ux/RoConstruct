// from server: 100% by EspClaude
// from server: 96% by EspClaude
// roc 2009-06 00448170  unit: RBX::VMaterialBase::?$WeakReferenceCountedPointer  size: 276 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00448170
//
// 00448170  64a100000000         mov eax, dword ptr fs:[0]
// 00448176  6aff                 push -1
// 00448178  68a8ed8600           push 0x86eda8
// 0044817d  50                   push eax
// 0044817e  64892500000000       mov dword ptr fs:[0], esp
// 00448185  83ec14               sub esp, 0x14
// 00448188  53                   push ebx
// 00448189  55                   push ebp
// 0044818a  83c14c               add ecx, 0x4c
// 0044818d  833900               cmp dword ptr [ecx], 0
// 00448190  56                   push esi
// 00448191  57                   push edi
// 00448192  0f84d7000000         je 0x44826f
// 00448198  8d442414             lea eax, [esp + 0x14]
// 0044819c  50                   push eax
// 0044819d  e8ce2cfdff           call 0x41ae70
// 004481a2  8b742414             mov esi, dword ptr [esp + 0x14]
// 004481a6  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 004481a9  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 004481af  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004481b7  396e0c               cmp dword ptr [esi + 0xc], ebp
// 004481ba  7602                 jbe 0x4481be
// 004481bc  ffd3                 call ebx
// 004481be  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004481c1  8b0e                 mov ecx, dword ptr [esi]
// 004481c3  894c241c             mov dword ptr [esp + 0x1c], ecx
// 004481c7  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004481ca  7602                 jbe 0x4481ce
// 004481cc  ffd3                 call ebx
// 004481ce  8b36                 mov esi, dword ptr [esi]
// 004481d0  85f6                 test esi, esi
// 004481d2  7406                 je 0x4481da
// 004481d4  3b74241c             cmp esi, dword ptr [esp + 0x1c]
// 004481d8  7402                 je 0x4481dc
// 004481da  ffd3                 call ebx
// 004481dc  3bfd                 cmp edi, ebp
// 004481de  7455                 je 0x448235
// 004481e0  85f6                 test esi, esi
// 004481e2  7549                 jne 0x44822d
// 004481e4  ffd3                 call ebx
// 004481e6  33c0                 xor eax, eax
// 004481e8  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004481eb  7202                 jb 0x4481ef
// 004481ed  ffd3                 call ebx
// 004481ef  8b17                 mov edx, dword ptr [edi]
// 004481f1  83ec08               sub esp, 8
// 004481f4  8bcc                 mov ecx, esp
// 004481f6  8911                 mov dword ptr [ecx], edx
// 004481f8  8b4704               mov eax, dword ptr [edi + 4]
// 004481fb  89642418             mov dword ptr [esp + 0x18], esp
// 004481ff  894104               mov dword ptr [ecx + 4], eax
// 00448202  85c0                 test eax, eax
// 00448204  740c                 je 0x448212
// 00448206  83c004               add eax, 4
// 00448209  b901000000           mov ecx, 1
// 0044820e  f00fc108             lock xadd dword ptr [eax], ecx
// 00448212  ff54243c             call dword ptr [esp + 0x3c]
// 00448216  83c408               add esp, 8
// 00448219  85f6                 test esi, esi
// 0044821b  7514                 jne 0x448231
// 0044821d  ffd3                 call ebx
// 0044821f  33c0                 xor eax, eax
// 00448221  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00448224  7202                 jb 0x448228
// 00448226  ffd3                 call ebx
// 00448228  83c708               add edi, 8
// 0044822b  eba3                 jmp 0x4481d0
// 0044822d  8b06                 mov eax, dword ptr [esi]
// 0044822f  ebb7                 jmp 0x4481e8
// 00448231  8b06                 mov eax, dword ptr [esi]
// 00448233  ebec                 jmp 0x448221
// 00448235  8b742418             mov esi, dword ptr [esp + 0x18]
// 00448239  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 00448241  85f6                 test esi, esi
// 00448243  742a                 je 0x44826f
// 00448245  8d5604               lea edx, [esi + 4]
// 00448248  83c8ff               or eax, 0xffffffff
// 0044824b  f00fc102             lock xadd dword ptr [edx], eax
// 0044824f  751e                 jne 0x44826f
// 00448251  8b16                 mov edx, dword ptr [esi]
// 00448253  8b4204               mov eax, dword ptr [edx + 4]
// 00448256  8bce                 mov ecx, esi
// 00448258  ffd0                 call eax
// 0044825a  8d4e08               lea ecx, [esi + 8]
// 0044825d  83caff               or edx, 0xffffffff
// 00448260  f00fc111             lock xadd dword ptr [ecx], edx
// 00448264  7509                 jne 0x44826f
// 00448266  8b06                 mov eax, dword ptr [esi]
// 00448268  8b5008               mov edx, dword ptr [eax + 8]
// 0044826b  8bce                 mov ecx, esi
// 0044826d  ffd2                 call edx
// 0044826f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00448273  5f                   pop edi
// 00448274  5e                   pop esi
// 00448275  5d                   pop ebp
// 00448276  64890d00000000       mov dword ptr fs:[0], ecx
// 0044827d  5b                   pop ebx
// 0044827e  83c420               add esp, 0x20
// 00448281  c20400               ret 4

// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
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

namespace RBX {
class Instance;class Adorn;
typedef std::vector<boost::shared_ptr<Instance> > Instances;
struct Children {boost::shared_ptr<Instances> object;operator boost::shared_ptr<Instances>::unspecified_bool_type()const{return object;}__declspec(noinline) boost::shared_ptr<const Instances> read()const{return object;}};
typedef void(__cdecl*Visitor)(boost::shared_ptr<Instance>);
class Instance {char prefix[0x4c];Children children;public:void visitChildren(Visitor)const;};
void Instance::visitChildren(Visitor func)const{
 if(children){
  boost::shared_ptr<const Instances> c=children.read();
  Instances::const_iterator end=c->end();
  Instances::const_iterator iter=c->begin();
  for(;iter!=end;iter++){
   func(*iter);
  }
 }
}
}
