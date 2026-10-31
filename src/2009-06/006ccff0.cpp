// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00640b40  unit: RBX::AxisMoveTool  size: 513 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00640b40
//
// 00640b40  6aff                 push -1
// 00640b42  6878aa7d00           push 0x7daa78
// 00640b47  64a100000000         mov eax, dword ptr fs:[0]
// 00640b4d  50                   push eax
// 00640b4e  64892500000000       mov dword ptr fs:[0], esp
// 00640b55  83ec44               sub esp, 0x44
// 00640b58  8b4118               mov eax, dword ptr [ecx + 0x18]
// 00640b5b  55                   push ebp
// 00640b5c  33ed                 xor ebp, ebp
// 00640b5e  56                   push esi
// 00640b5f  89442410             mov dword ptr [esp + 0x10], eax
// 00640b63  896c2414             mov dword ptr [esp + 0x14], ebp
// 00640b67  896c2418             mov dword ptr [esp + 0x18], ebp
// 00640b6b  6a04                 push 4
// 00640b6d  896c2458             mov dword ptr [esp + 0x58], ebp
// 00640b71  e8aafd0500           call 0x6a0920
// 00640b76  83c404               add esp, 4
// 00640b79  3bc5                 cmp eax, ebp
// 00640b7b  7408                 je 0x640b85
// 00640b7d  8d4c241c             lea ecx, [esp + 0x1c]
// 00640b81  8908                 mov dword ptr [eax], ecx
// 00640b83  eb02                 jmp 0x640b87
// 00640b85  33c0                 xor eax, eax
// 00640b87  53                   push ebx
// 00640b88  57                   push edi
// 00640b89  89442424             mov dword ptr [esp + 0x24], eax
// 00640b8d  896c2430             mov dword ptr [esp + 0x30], ebp
// 00640b91  896c2434             mov dword ptr [esp + 0x34], ebp
// 00640b95  896c2438             mov dword ptr [esp + 0x38], ebp
// 00640b99  6a01                 push 1
// 00640b9b  8d4c241c             lea ecx, [esp + 0x1c]
// 00640b9f  c644246002           mov byte ptr [esp + 0x60], 2
// 00640ba4  e81711f4ff           call 0x581cc0
// 00640ba9  8bb054010000         mov esi, dword ptr [eax + 0x154]
// 00640baf  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00640bb2  395e0c               cmp dword ptr [esi + 0xc], ebx
// 00640bb5  7606                 jbe 0x640bbd
// 00640bb7  ff1590288000         call dword ptr [0x802890]
// 00640bbd  8b16                 mov edx, dword ptr [esi]
// 00640bbf  6a01                 push 1
// 00640bc1  8d4c241c             lea ecx, [esp + 0x1c]
// 00640bc5  89542414             mov dword ptr [esp + 0x14], edx
// 00640bc9  e8f210f4ff           call 0x581cc0
// 00640bce  8bb854010000         mov edi, dword ptr [eax + 0x154]
// 00640bd4  8b770c               mov esi, dword ptr [edi + 0xc]
// 00640bd7  3b7710               cmp esi, dword ptr [edi + 0x10]
// 00640bda  7606                 jbe 0x640be2
// 00640bdc  ff1590288000         call dword ptr [0x802890]
// 00640be2  8b3f                 mov edi, dword ptr [edi]
// 00640be4  8d442424             lea eax, [esp + 0x24]
// 00640be8  50                   push eax
// 00640be9  b8c0046400           mov eax, 0x6404c0
// 00640bee  50                   push eax
// 00640bef  8b442418             mov eax, dword ptr [esp + 0x18]
// 00640bf3  53                   push ebx
// 00640bf4  50                   push eax
// 00640bf5  56                   push esi
// 00640bf6  8d4c2424             lea ecx, [esp + 0x24]
// 00640bfa  57                   push edi
// 00640bfb  51                   push ecx
// 00640bfc  e89ffbffff           call 0x6407a0
// 00640c01  8b542450             mov edx, dword ptr [esp + 0x50]
// 00640c05  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 00640c09  83c41c               add esp, 0x1c
// 00640c0c  2bd0                 sub edx, eax
// 00640c0e  c1fa02               sar edx, 2
// 00640c11  5f                   pop edi
// 00640c12  5b                   pop ebx
// 00640c13  85d2                 test edx, edx
// 00640c15  0f86b1000000         jbe 0x640ccc
// 00640c1b  8d44241c             lea eax, [esp + 0x1c]
// 00640c1f  50                   push eax
// 00640c20  8d4c2438             lea ecx, [esp + 0x38]
// 00640c24  51                   push ecx
// 00640c25  e856f3fcff           call 0x60ff80
// 00640c2a  d900                 fld dword ptr [eax]
// 00640c2c  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 00640c30  d919                 fstp dword ptr [ecx]
// 00640c32  83c408               add esp, 8
// 00640c35  d94004               fld dword ptr [eax + 4]
// 00640c38  d95904               fstp dword ptr [ecx + 4]
// 00640c3b  d94008               fld dword ptr [eax + 8]
// 00640c3e  d95908               fstp dword ptr [ecx + 8]
// 00640c41  d9400c               fld dword ptr [eax + 0xc]
// 00640c44  d9590c               fstp dword ptr [ecx + 0xc]
// 00640c47  d94010               fld dword ptr [eax + 0x10]
// 00640c4a  d95910               fstp dword ptr [ecx + 0x10]
// 00640c4d  d94014               fld dword ptr [eax + 0x14]
// 00640c50  8b442428             mov eax, dword ptr [esp + 0x28]
// 00640c54  d95914               fstp dword ptr [ecx + 0x14]
// 00640c57  3bc5                 cmp eax, ebp
// 00640c59  7409                 je 0x640c64
// 00640c5b  50                   push eax
// 00640c5c  e819fa0500           call 0x6a067a
// 00640c61  83c404               add esp, 4
// 00640c64  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00640c68  52                   push edx
// 00640c69  896c242c             mov dword ptr [esp + 0x2c], ebp
// 00640c6d  896c2430             mov dword ptr [esp + 0x30], ebp
// 00640c71  896c2434             mov dword ptr [esp + 0x34], ebp
// 00640c75  e800fa0500           call 0x6a067a
// 00640c7a  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00640c7e  83c404               add esp, 4
// 00640c81  c7442454ffffffff     mov dword ptr [esp + 0x54], 0xffffffff
// 00640c89  3bf5                 cmp esi, ebp
// 00640c8b  742a                 je 0x640cb7
// 00640c8d  8d4604               lea eax, [esi + 4]
// 00640c90  83c9ff               or ecx, 0xffffffff
// 00640c93  f00fc108             lock xadd dword ptr [eax], ecx
// 00640c97  751e                 jne 0x640cb7
// 00640c99  8b16                 mov edx, dword ptr [esi]
// 00640c9b  8b4204               mov eax, dword ptr [edx + 4]
// 00640c9e  8bce                 mov ecx, esi
// 00640ca0  ffd0                 call eax
// 00640ca2  8d4e08               lea ecx, [esi + 8]
// 00640ca5  83caff               or edx, 0xffffffff
// 00640ca8  f00fc111             lock xadd dword ptr [ecx], edx
// 00640cac  7509                 jne 0x640cb7
// 00640cae  8b06                 mov eax, dword ptr [esi]
// 00640cb0  8b5008               mov edx, dword ptr [eax + 8]
// 00640cb3  8bce                 mov ecx, esi
// 00640cb5  ffd2                 call edx
// 00640cb7  5e                   pop esi
// 00640cb8  b001                 mov al, 1
// 00640cba  5d                   pop ebp
// 00640cbb  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 00640cbf  64890d00000000       mov dword ptr fs:[0], ecx
// 00640cc6  83c450               add esp, 0x50
// 00640cc9  c20400               ret 4
// 00640ccc  3bc5                 cmp eax, ebp
// 00640cce  7409                 je 0x640cd9
// 00640cd0  50                   push eax
// 00640cd1  e8a4f90500           call 0x6a067a
// 00640cd6  83c404               add esp, 4
// 00640cd9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00640cdd  50                   push eax
// 00640cde  896c242c             mov dword ptr [esp + 0x2c], ebp
// 00640ce2  896c2430             mov dword ptr [esp + 0x30], ebp
// 00640ce6  896c2434             mov dword ptr [esp + 0x34], ebp
// 00640cea  e88bf90500           call 0x6a067a
// 00640cef  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00640cf3  83c404               add esp, 4
// 00640cf6  c7442454ffffffff     mov dword ptr [esp + 0x54], 0xffffffff
// 00640cfe  3bf5                 cmp esi, ebp
// 00640d00  742a                 je 0x640d2c
// 00640d02  8d4e04               lea ecx, [esi + 4]
// 00640d05  83caff               or edx, 0xffffffff
// 00640d08  f00fc111             lock xadd dword ptr [ecx], edx
// 00640d0c  751e                 jne 0x640d2c
// 00640d0e  8b06                 mov eax, dword ptr [esi]
// 00640d10  8b5004               mov edx, dword ptr [eax + 4]
// 00640d13  8bce                 mov ecx, esi
// 00640d15  ffd2                 call edx
// 00640d17  8d4608               lea eax, [esi + 8]
// 00640d1a  83c9ff               or ecx, 0xffffffff
// 00640d1d  f00fc108             lock xadd dword ptr [eax], ecx
// 00640d21  7509                 jne 0x640d2c
// 00640d23  8b16                 mov edx, dword ptr [esi]
// 00640d25  8b4208               mov eax, dword ptr [edx + 8]
// 00640d28  8bce                 mov ecx, esi
// 00640d2a  ffd0                 call eax
// 00640d2c  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00640d30  5e                   pop esi
// 00640d31  32c0                 xor al, al
// 00640d33  5d                   pop ebp
// 00640d34  64890d00000000       mov dword ptr fs:[0], ecx
// 00640d3b  83c450               add esp, 0x50
// 00640d3e  c20400               ret 4

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
#include <algorithm>
struct Instance;struct Part;
typedef std::vector<boost::shared_ptr<Instance> > Instances;
typedef std::vector<Part*> Parts;
struct Snapshot {boost::shared_ptr<Instances> object;const Instances*operator->()const{return object.get();}};
struct Selection {char prefix[0x154];Snapshot selected;Instances::const_iterator begin()const{return selected->begin();}Instances::const_iterator end()const{return selected->end();}};
struct CachedSelection {Instance* context;boost::shared_ptr<Selection> selected;CachedSelection(Instance*p):context(p){}Selection*get(int);};
void __cdecl collectPart(boost::shared_ptr<Instance>,Parts*);
struct Callback {void(__cdecl* function)(boost::shared_ptr<Instance>,Parts*);Parts* parts;Callback(void(__cdecl*f)(boost::shared_ptr<Instance>,Parts*),Parts*p):function(f),parts(p){}void operator()(const boost::shared_ptr<Instance>&p){function(p,parts);}};
struct Vec3 {float x,y,z;Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return *this;}};
struct Extents {Vec3 min,max;Extents&operator=(const Extents&v){min=v.min;max=v.max;return *this;}};
Extents __cdecl worldExtents(const Parts&);
struct AxisMoveTool {char prefix[0x18];Instance* workspace;bool extents(Extents&);};
bool AxisMoveTool::extents(Extents& out){
 CachedSelection selection(workspace);
 Parts parts;
 std::for_each(selection.get(1)->begin(),selection.get(1)->end(),Callback(collectPart,&parts));
 if(parts.size()>0){out=worldExtents(parts);return true;}
 return false;
}
