// from server: 100% by EspClaude
// from server: 80% by EspClaude
// roc 2007-08 004572f0  unit: CRobloxView  size: 428 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004572f0
//
// 004572f0  6aff                 push -1
// 004572f2  68801d7400           push 0x741d80
// 004572f7  64a100000000         mov eax, dword ptr fs:[0]
// 004572fd  50                   push eax
// 004572fe  83ec14               sub esp, 0x14
// 00457301  53                   push ebx
// 00457302  55                   push ebp
// 00457303  56                   push esi
// 00457304  57                   push edi
// 00457305  a188518b00           mov eax, dword ptr [0x8b5188]
// 0045730a  33c4                 xor eax, esp
// 0045730c  50                   push eax
// 0045730d  8d442428             lea eax, [esp + 0x28]
// 00457311  64a300000000         mov dword ptr fs:[0], eax
// 00457317  8bf1                 mov esi, ecx
// 00457319  8b8630010000         mov eax, dword ptr [esi + 0x130]
// 0045731f  83ec08               sub esp, 8
// 00457322  8bcc                 mov ecx, esp
// 00457324  8901                 mov dword ptr [ecx], eax
// 00457326  8b8634010000         mov eax, dword ptr [esi + 0x134]
// 0045732c  33db                 xor ebx, ebx
// 0045732e  3bc3                 cmp eax, ebx
// 00457330  8964241c             mov dword ptr [esp + 0x1c], esp
// 00457334  894104               mov dword ptr [ecx + 4], eax
// 00457337  740c                 je 0x457345
// 00457339  83c004               add eax, 4
// 0045733c  b901000000           mov ecx, 1
// 00457341  f00fc108             lock xadd dword ptr [eax], ecx
// 00457345  8d4c2424             lea ecx, [esp + 0x24]
// 00457349  e80262fbff           call 0x40d550
// 0045734e  8b8e9c010000         mov ecx, dword ptr [esi + 0x19c]
// 00457354  3bcb                 cmp ecx, ebx
// 00457356  895c2430             mov dword ptr [esp + 0x30], ebx
// 0045735a  899e9c010000         mov dword ptr [esi + 0x19c], ebx
// 00457360  7409                 je 0x45736b
// 00457362  8b11                 mov edx, dword ptr [ecx]
// 00457364  8b4204               mov eax, dword ptr [edx + 4]
// 00457367  6a01                 push 1
// 00457369  ffd0                 call eax
// 0045736b  8b8ea0010000         mov ecx, dword ptr [esi + 0x1a0]
// 00457371  3bcb                 cmp ecx, ebx
// 00457373  899ea0010000         mov dword ptr [esi + 0x1a0], ebx
// 00457379  7409                 je 0x457384
// 0045737b  8b11                 mov edx, dword ptr [ecx]
// 0045737d  8b4204               mov eax, dword ptr [edx + 4]
// 00457380  6a01                 push 1
// 00457382  ffd0                 call eax
// 00457384  8b8ea4010000         mov ecx, dword ptr [esi + 0x1a4]
// 0045738a  3bcb                 cmp ecx, ebx
// 0045738c  899ea4010000         mov dword ptr [esi + 0x1a4], ebx
// 00457392  7409                 je 0x45739d
// 00457394  8b11                 mov edx, dword ptr [ecx]
// 00457396  8b4204               mov eax, dword ptr [edx + 4]
// 00457399  6a01                 push 1
// 0045739b  ffd0                 call eax
// 0045739d  8b8ea8010000         mov ecx, dword ptr [esi + 0x1a8]
// 004573a3  3bcb                 cmp ecx, ebx
// 004573a5  899ea8010000         mov dword ptr [esi + 0x1a8], ebx
// 004573ab  7409                 je 0x4573b6
// 004573ad  8b11                 mov edx, dword ptr [ecx]
// 004573af  8b4204               mov eax, dword ptr [edx + 4]
// 004573b2  6a01                 push 1
// 004573b4  ffd0                 call eax
// 004573b6  8b8eac010000         mov ecx, dword ptr [esi + 0x1ac]
// 004573bc  3bcb                 cmp ecx, ebx
// 004573be  899eac010000         mov dword ptr [esi + 0x1ac], ebx
// 004573c4  7409                 je 0x4573cf
// 004573c6  8b11                 mov edx, dword ptr [ecx]
// 004573c8  8b4204               mov eax, dword ptr [edx + 4]
// 004573cb  6a01                 push 1
// 004573cd  ffd0                 call eax
// 004573cf  3bf3                 cmp esi, ebx
// 004573d1  7405                 je 0x4573d8
// 004573d3  8d4e78               lea ecx, [esi + 0x78]
// 004573d6  eb02                 jmp 0x4573da
// 004573d8  33c9                 xor ecx, ecx
// 004573da  8b8630010000         mov eax, dword ptr [esi + 0x130]
// 004573e0  3bc3                 cmp eax, ebx
// 004573e2  740c                 je 0x4573f0
// 004573e4  51                   push ecx
// 004573e5  8d8800010000         lea ecx, [eax + 0x100]
// 004573eb  e840b1fdff           call 0x432530
// 004573f0  8b8630010000         mov eax, dword ptr [esi + 0x130]
// 004573f6  3bc3                 cmp eax, ebx
// 004573f8  8d4e7c               lea ecx, [esi + 0x7c]
// 004573fb  740c                 je 0x457409
// 004573fd  51                   push ecx
// 004573fe  8d8818010000         lea ecx, [eax + 0x118]
// 00457404  e827b1fdff           call 0x432530
// 00457409  8d4c2414             lea ecx, [esp + 0x14]
// 0045740d  51                   push ecx
// 0045740e  8bce                 mov ecx, esi
// 00457410  e88beeffff           call 0x4562a0
// 00457415  8b08                 mov ecx, dword ptr [eax]
// 00457417  3bcb                 cmp ecx, ebx
// 00457419  c644243001           mov byte ptr [esp + 0x30], 1
// 0045741e  7409                 je 0x457429
// 00457420  e86b71fbff           call 0x40e590
// 00457425  8be8                 mov ebp, eax
// 00457427  eb02                 jmp 0x45742b
// 00457429  33ed                 xor ebp, ebp
// 0045742b  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0045742f  3bfb                 cmp edi, ebx
// 00457431  885c2430             mov byte ptr [esp + 0x30], bl
// 00457435  742a                 je 0x457461
// 00457437  8d5704               lea edx, [edi + 4]
// 0045743a  83c8ff               or eax, 0xffffffff
// 0045743d  f00fc102             lock xadd dword ptr [edx], eax
// 00457441  751e                 jne 0x457461
// 00457443  8b17                 mov edx, dword ptr [edi]
// 00457445  8b4204               mov eax, dword ptr [edx + 4]
// 00457448  8bcf                 mov ecx, edi
// 0045744a  ffd0                 call eax
// 0045744c  8d4f08               lea ecx, [edi + 8]
// 0045744f  83caff               or edx, 0xffffffff
// 00457452  f00fc111             lock xadd dword ptr [ecx], edx
// 00457456  7509                 jne 0x457461
// 00457458  8b07                 mov eax, dword ptr [edi]
// 0045745a  8b5008               mov edx, dword ptr [eax + 8]
// 0045745d  8bcf                 mov ecx, edi
// 0045745f  ffd2                 call edx
// 00457461  3beb                 cmp ebp, ebx
// 00457463  7412                 je 0x457477
// 00457465  8d8680000000         lea eax, [esi + 0x80]
// 0045746b  50                   push eax
// 0045746c  8d8d00010000         lea ecx, [ebp + 0x100]
// 00457472  e8b9b0fdff           call 0x432530
// 00457477  8d4c241c             lea ecx, [esp + 0x1c]
// 0045747b  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 00457483  e818211000           call 0x5595a0
// 00457488  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0045748c  64890d00000000       mov dword ptr fs:[0], ecx
// 00457493  59                   pop ecx
// 00457494  5f                   pop edi
// 00457495  5e                   pop esi
// 00457496  5d                   pop ebp
// 00457497  5b                   pop ebx
// 00457498  83c420               add esp, 0x20
// 0045749b  c3                   ret 

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

struct Listener {virtual ~Listener();};
struct Notifier {char storage[0x18];void removeListener(Listener*)const;};
struct Service {char prefix[0x100];Notifier notifier;};
struct Model {
 char prefix[0x100];Notifier first,second;
 Service* service();
};
struct Request {int storage[3];Request(boost::shared_ptr<Model>);~Request();};
struct Connection {virtual void reserved();virtual ~Connection();};
struct Owned {
 Connection* p;
 void reset(){Connection* old=p;p=0;delete old;}
};
struct ViewPrefix {virtual ~ViewPrefix();char prefix[0x78-4];Listener a,b;};
struct CRobloxView:ViewPrefix,Listener {
 char pad1[0x130-0x84];
 boost::shared_ptr<Model> model;
 char pad2[0x19c-0x138];
 Owned one,two,three,four,five;
 boost::shared_ptr<Model> getModel()const;
 void detach();
};
static Service* findService(Model* m){return m?m->service():0;}
void CRobloxView::detach(){
 Request request(model);
 one.reset();two.reset();three.reset();four.reset();five.reset();
 Listener* first=this?&a:0;
 if(model.get())model->first.removeListener(first);
 Listener* second=&b;
 if(model.get())model->second.removeListener(second);
 Service* current=findService(getModel().get());
 if(current){Listener* third=this;current->notifier.removeListener(third);}
}
