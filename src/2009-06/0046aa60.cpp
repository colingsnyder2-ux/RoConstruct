// from server: 72% by EspClaude
// from server: 100% by EspClaude
// roc 2008-06 004685b0  unit: DxUserInput  size: 1026 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004685b0
//
// 004685b0  55                   push ebp
// 004685b1  8bec                 mov ebp, esp
// 004685b3  83e4f8               and esp, 0xfffffff8
// 004685b6  6aff                 push -1
// 004685b8  68e1367c00           push 0x7c36e1
// 004685bd  64a100000000         mov eax, dword ptr fs:[0]
// 004685c3  50                   push eax
// 004685c4  64892500000000       mov dword ptr fs:[0], esp
// 004685cb  51                   push ecx
// 004685cc  b880a00000           mov eax, 0xa080
// 004685d1  e84a8f2300           call 0x6a1520
// 004685d6  53                   push ebx
// 004685d7  55                   push ebp
// 004685d8  56                   push esi
// 004685d9  57                   push edi
// 004685da  8bf1                 mov esi, ecx
// 004685dc  8d7e34               lea edi, [esi + 0x34]
// 004685df  57                   push edi
// 004685e0  c744241c00080000     mov dword ptr [esp + 0x1c], 0x800
// 004685e8  897c2448             mov dword ptr [esp + 0x48], edi
// 004685ec  ff15d4228000         call dword ptr [0x8022d4]
// 004685f2  c644244801           mov byte ptr [esp + 0x48], 1
// 004685f7  8b8678010000         mov eax, dword ptr [esi + 0x178]
// 004685fd  50                   push eax
// 004685fe  8d44241c             lea eax, [esp + 0x1c]
// 00468602  50                   push eax
// 00468603  8d8c2498000000       lea ecx, [esp + 0x98]
// 0046860a  51                   push ecx
// 0046860b  33ed                 xor ebp, ebp
// 0046860d  8bce                 mov ecx, esi
// 0046860f  89ac24a8a00000       mov dword ptr [esp + 0xa0a8], ebp
// 00468616  e865f2ffff           call 0x467880
// 0046861b  57                   push edi
// 0046861c  84c0                 test al, al
// 0046861e  7522                 jne 0x468642
// 00468620  888692010000         mov byte ptr [esi + 0x192], al
// 00468626  ff15f4218000         call dword ptr [0x8021f4]
// 0046862c  8b8c2494a00000       mov ecx, dword ptr [esp + 0xa094]
// 00468633  64890d00000000       mov dword ptr fs:[0], ecx
// 0046863a  5f                   pop edi
// 0046863b  5e                   pop esi
// 0046863c  5d                   pop ebp
// 0046863d  5b                   pop ebx
// 0046863e  8be5                 mov esp, ebp
// 00468640  5d                   pop ebp
// 00468641  c3                   ret 
// 00468642  83cbff               or ebx, 0xffffffff
// 00468645  899c24a0a00000       mov dword ptr [esp + 0xa0a0], ebx
// 0046864c  ff15f4218000         call dword ptr [0x8021f4]
// 00468652  d9ee                 fldz 
// 00468654  d9542420             fst dword ptr [esp + 0x20]
// 00468658  c644241300           mov byte ptr [esp + 0x13], 0
// 0046865d  d9542424             fst dword ptr [esp + 0x24]
// 00468661  896c2414             mov dword ptr [esp + 0x14], ebp
// 00468665  396c2418             cmp dword ptr [esp + 0x18], ebp
// 00468669  0f8622010000         jbe 0x468791
// 0046866f  8b1d0c2e8000         mov ebx, dword ptr [0x802e0c]
// 00468675  8dbc2494000000       lea edi, [esp + 0x94]
// 0046867c  eb04                 jmp 0x468682
// 0046867e  8bff                 mov edi, edi
// 00468680  d9ee                 fldz 
// 00468682  8b4ffc               mov ecx, dword ptr [edi - 4]
// 00468685  8d47fc               lea eax, [edi - 4]
// 00468688  83f90d               cmp ecx, 0xd
// 0046868b  0f87e3000000         ja 0x468774
// 00468691  0fb691a4894600       movzx edx, byte ptr [ecx + 0x4689a4]
// 00468698  ff249590894600       jmp dword ptr [edx*4 + 0x468990]
// 0046869f  8b866c010000         mov eax, dword ptr [esi + 0x16c]
// 004686a5  ddd8                 fstp st(0)
// 004686a7  8b4020               mov eax, dword ptr [eax + 0x20]
// 004686aa  6a00                 push 0
// 004686ac  6a00                 push 0
// 004686ae  68bb040000           push 0x4bb
// 004686b3  50                   push eax
// 004686b4  ffd3                 call ebx
// 004686b6  8b16                 mov edx, dword ptr [esi]
// 004686b8  8b12                 mov edx, dword ptr [edx]
// 004686ba  8d44243c             lea eax, [esp + 0x3c]
// 004686be  50                   push eax
// 004686bf  8bce                 mov ecx, esi
// 004686c1  ffd2                 call edx
// 004686c3  50                   push eax
// 004686c4  33c0                 xor eax, eax
// 004686c6  813f80000000         cmp dword ptr [edi], 0x80
// 004686cc  8bce                 mov ecx, esi
// 004686ce  0f95c0               setne al
// 004686d1  83c003               add eax, 3
// 004686d4  50                   push eax
// 004686d5  e8c6fdffff           call 0x4684a0
// 004686da  e997000000           jmp 0x468776
// 004686df  8b866c010000         mov eax, dword ptr [esi + 0x16c]
// 004686e5  ddd8                 fstp st(0)
// 004686e7  8b4820               mov ecx, dword ptr [eax + 0x20]
// 004686ea  6a00                 push 0
// 004686ec  6a00                 push 0
// 004686ee  68bb040000           push 0x4bb
// 004686f3  51                   push ecx
// 004686f4  ffd3                 call ebx
// 004686f6  8b16                 mov edx, dword ptr [esi]
// 004686f8  8b12                 mov edx, dword ptr [edx]
// 004686fa  8d842480000000       lea eax, [esp + 0x80]
// 00468701  50                   push eax
// 00468702  8bce                 mov ecx, esi
// 00468704  ffd2                 call edx
// 00468706  50                   push eax
// 00468707  33c0                 xor eax, eax
// 00468709  813f80000000         cmp dword ptr [edi], 0x80
// 0046870f  8bce                 mov ecx, esi
// 00468711  0f95c0               setne al
// 00468714  40                   inc eax
// 00468715  50                   push eax
// 00468716  e885fdffff           call 0x4684a0
// 0046871b  eb59                 jmp 0x468776
// 0046871d  8d4c2420             lea ecx, [esp + 0x20]
// 00468721  ddd8                 fstp st(0)
// 00468723  51                   push ecx
// 00468724  50                   push eax
// 00468725  8d542470             lea edx, [esp + 0x70]
// 00468729  52                   push edx
// 0046872a  c644241f01           mov byte ptr [esp + 0x1f], 1
// 0046872f  e80c0c0000           call 0x469340
// 00468734  83c408               add esp, 8
// 00468737  50                   push eax
// 00468738  8bce                 mov ecx, esi
// 0046873a  e8d1f7ffff           call 0x467f10
// 0046873f  eb35                 jmp 0x468776
// 00468741  db07                 fild dword ptr [edi]
// 00468743  bd08000000           mov ebp, 8
// 00468748  d80de4c38100         fmul dword ptr [0x81c3e4]
// 0046874e  ded9                 fcompp 
// 00468750  dfe0                 fnstsw ax
// 00468752  f6c441               test ah, 0x41
// 00468755  7405                 je 0x46875c
// 00468757  bd09000000           mov ebp, 9
// 0046875c  8b06                 mov eax, dword ptr [esi]
// 0046875e  8b10                 mov edx, dword ptr [eax]
// 00468760  8d4c244c             lea ecx, [esp + 0x4c]
// 00468764  51                   push ecx
// 00468765  8bce                 mov ecx, esi
// 00468767  ffd2                 call edx
// 00468769  50                   push eax
// 0046876a  55                   push ebp
// 0046876b  8bce                 mov ecx, esi
// 0046876d  e82efdffff           call 0x4684a0
// 00468772  eb02                 jmp 0x468776
// 00468774  ddd8                 fstp st(0)
// 00468776  8b442414             mov eax, dword ptr [esp + 0x14]
// 0046877a  40                   inc eax
// 0046877b  83c714               add edi, 0x14
// 0046877e  89442414             mov dword ptr [esp + 0x14], eax
// 00468782  3b442418             cmp eax, dword ptr [esp + 0x18]
// 00468786  0f82f4feffff         jb 0x468680
// 0046878c  83cbff               or ebx, 0xffffffff
// 0046878f  eb02                 jmp 0x468793
// 00468791  ddd8                 fstp st(0)
// 00468793  e808140a00           call 0x509ba0
// 00468798  8bc8                 mov ecx, eax
// 0046879a  d901                 fld dword ptr [ecx]
// 0046879c  d85c2420             fcomp dword ptr [esp + 0x20]
// 004687a0  dfe0                 fnstsw ax
// 004687a2  f6c444               test ah, 0x44
// 004687a5  7a12                 jp 0x4687b9
// 004687a7  d94104               fld dword ptr [ecx + 4]
// 004687aa  d85c2424             fcomp dword ptr [esp + 0x24]
// 004687ae  dfe0                 fnstsw ax
// 004687b0  f6c444               test ah, 0x44
// 004687b3  0f8b0d010000         jnp 0x4688c6
// 004687b9  8b8680010000         mov eax, dword ptr [esi + 0x180]
// 004687bf  83ec08               sub esp, 8
// 004687c2  8bcc                 mov ecx, esp
// 004687c4  8901                 mov dword ptr [ecx], eax
// 004687c6  8b8684010000         mov eax, dword ptr [esi + 0x184]
// 004687cc  89642424             mov dword ptr [esp + 0x24], esp
// 004687d0  894104               mov dword ptr [ecx + 4], eax
// 004687d3  85c0                 test eax, eax
// 004687d5  740c                 je 0x4687e3
// 004687d7  83c004               add eax, 4
// 004687da  b901000000           mov ecx, 1
// 004687df  f00fc108             lock xadd dword ptr [eax], ecx
// 004687e3  8d4c2470             lea ecx, [esp + 0x70]
// 004687e7  e85493faff           call 0x411b40
// 004687ec  8b8680010000         mov eax, dword ptr [esi + 0x180]
// 004687f2  8b8004020000         mov eax, dword ptr [eax + 0x204]
// 004687f8  8d542420             lea edx, [esp + 0x20]
// 004687fc  52                   push edx
// 004687fd  8bc8                 mov ecx, eax
// 004687ff  c78424a0a0000001000000 mov dword ptr [esp + 0xa0a0], 1
// 0046880a  e8117a1300           call 0x5a0220
// 0046880f  8b06                 mov eax, dword ptr [esi]
// 00468811  8b10                 mov edx, dword ptr [eax]
// 00468813  8d4c244c             lea ecx, [esp + 0x4c]
// 00468817  51                   push ecx
// 00468818  8bce                 mov ecx, esi
// 0046881a  ffd2                 call edx
// 0046881c  50                   push eax
// 0046881d  8d4c2418             lea ecx, [esp + 0x18]
// 00468821  e8aa9a0a00           call 0x5122d0
// 00468826  8d44243c             lea eax, [esp + 0x3c]
// 0046882a  50                   push eax
// 0046882b  8bce                 mov ecx, esi
// 0046882d  e80eecffff           call 0x467440
// 00468832  8b00                 mov eax, dword ptr [eax]
// 00468834  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00468838  33d2                 xor edx, edx
// 0046883a  894c2430             mov dword ptr [esp + 0x30], ecx
// 0046883e  33c9                 xor ecx, ecx
// 00468840  6689542434           mov word ptr [esp + 0x34], dx
// 00468845  8d542428             lea edx, [esp + 0x28]
// 00468849  66894c2436           mov word ptr [esp + 0x36], cx
// 0046884e  52                   push edx
// 0046884f  8bce                 mov ecx, esi
// 00468851  c744242c06000000     mov dword ptr [esp + 0x2c], 6
// 00468859  89742430             mov dword ptr [esp + 0x30], esi
// 0046885d  8944243c             mov dword ptr [esp + 0x3c], eax
// 00468861  e89af1ffff           call 0x467a00
// 00468866  8b06                 mov eax, dword ptr [esi]
// 00468868  8b10                 mov edx, dword ptr [eax]
// 0046886a  8d4c244c             lea ecx, [esp + 0x4c]
// 0046886e  51                   push ecx
// 0046886f  8bce                 mov ecx, esi
// 00468871  ffd2                 call edx
// 00468873  50                   push eax
// 00468874  8d4c2418             lea ecx, [esp + 0x18]
// 00468878  e8539a0a00           call 0x5122d0
// 0046887d  8d44243c             lea eax, [esp + 0x3c]
// 00468881  50                   push eax
// 00468882  8bce                 mov ecx, esi
// 00468884  e8b7ebffff           call 0x467440
// 00468889  8b00                 mov eax, dword ptr [eax]
// 0046888b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0046888f  33d2                 xor edx, edx
// 00468891  894c2430             mov dword ptr [esp + 0x30], ecx
// 00468895  33c9                 xor ecx, ecx
// 00468897  6689542434           mov word ptr [esp + 0x34], dx
// 0046889c  8d542428             lea edx, [esp + 0x28]
// 004688a0  66894c2436           mov word ptr [esp + 0x36], cx
// 004688a5  52                   push edx
// 004688a6  8bce                 mov ecx, esi
// 004688a8  c744242c05000000     mov dword ptr [esp + 0x2c], 5
// 004688b0  89742430             mov dword ptr [esp + 0x30], esi
// 004688b4  8944243c             mov dword ptr [esp + 0x3c], eax
// 004688b8  e843f1ffff           call 0x467a00
// 004688bd  8d4c2468             lea ecx, [esp + 0x68]
// 004688c1  e9a7000000           jmp 0x46896d
// 004688c6  807c241300           cmp byte ptr [esp + 0x13], 0
// 004688cb  0f84a8000000         je 0x468979
// 004688d1  8b8680010000         mov eax, dword ptr [esi + 0x180]
// 004688d7  83ec08               sub esp, 8
// 004688da  8bcc                 mov ecx, esp
// 004688dc  8901                 mov dword ptr [ecx], eax
// 004688de  8b8684010000         mov eax, dword ptr [esi + 0x184]
// 004688e4  89642444             mov dword ptr [esp + 0x44], esp
// 004688e8  894104               mov dword ptr [ecx + 4], eax
// 004688eb  85c0                 test eax, eax
// 004688ed  740c                 je 0x4688fb
// 004688ef  83c004               add eax, 4
// 004688f2  b901000000           mov ecx, 1
// 004688f7  f00fc108             lock xadd dword ptr [eax], ecx
// 004688fb  8d4c247c             lea ecx, [esp + 0x7c]
// 004688ff  e83c92faff           call 0x411b40
// 00468904  8b16                 mov edx, dword ptr [esi]
// 00468906  8b12                 mov edx, dword ptr [edx]
// 00468908  8d842488000000       lea eax, [esp + 0x88]
// 0046890f  50                   push eax
// 00468910  8bce                 mov ecx, esi
// 00468912  c78424a0a0000002000000 mov dword ptr [esp + 0xa0a0], 2
// 0046891d  ffd2                 call edx
// 0046891f  50                   push eax
// 00468920  8d4c2420             lea ecx, [esp + 0x20]
// 00468924  e8a7990a00           call 0x5122d0
// 00468929  8d442444             lea eax, [esp + 0x44]
// 0046892d  50                   push eax
// 0046892e  8bce                 mov ecx, esi
// 00468930  e80bebffff           call 0x467440
// 00468935  8b00                 mov eax, dword ptr [eax]
// 00468937  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0046893b  33d2                 xor edx, edx
// 0046893d  894c245c             mov dword ptr [esp + 0x5c], ecx
// 00468941  33c9                 xor ecx, ecx
// 00468943  6689542460           mov word ptr [esp + 0x60], dx
// 00468948  8d542454             lea edx, [esp + 0x54]
// 0046894c  66894c2462           mov word ptr [esp + 0x62], cx
// 00468951  52                   push edx
// 00468952  8bce                 mov ecx, esi
// 00468954  c744245805000000     mov dword ptr [esp + 0x58], 5
// 0046895c  8974245c             mov dword ptr [esp + 0x5c], esi
// 00468960  89442468             mov dword ptr [esp + 0x68], eax
// 00468964  e897f0ffff           call 0x467a00
// 00468969  8d4c2474             lea ecx, [esp + 0x74]
// 0046896d  899c249ca00000       mov dword ptr [esp + 0xa09c], ebx
// 00468974  e847ea1000           call 0x5773c0
// 00468979  8b8c2494a00000       mov ecx, dword ptr [esp + 0xa094]
// 00468980  5f                   pop edi
// 00468981  64890d00000000       mov dword ptr fs:[0], ecx
// 00468988  5e                   pop esi
// 00468989  5d                   pop ebp
// 0046898a  5b                   pop ebx
// 0046898b  8be5                 mov esp, ebp
// 0046898d  5d                   pop ebp
// 0046898e  c3                   ret 
// 0046898f  90                   nop 
// 00468990  1d87460041           sbb eax, 0x41004687
// 00468995  874600               xchg dword ptr [esi], eax
// 00468998  9f                   lahf 
// 00468999  864600               xchg byte ptr [esi], al
// 0046899c  df8646007487         fild word ptr [esi - 0x788bffba]
// 004689a2  46                   inc esi
// 004689a3  0000                 add byte ptr [eax], al
// 004689a5  0404                 add al, 4
// 004689a7  0400                 add al, 0
// 004689a9  0404                 add al, 4
// 004689ab  0401                 add al, 1
// 004689ad  0404                 add al, 4
// 004689af  0402                 add al, 2

// from server: 78% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// Complete native004685b0 buffered mouse input; existing-pointer native views.
#include <string>
#include <memory>
#include <cstddef>
#include <typeinfo>
#include <intrin.h>

// Genuine Windows SDK used declarations; default compiler includes only CRT headers.
struct HWND__;typedef HWND__* HWND;struct tagRECT;struct _GUID;
typedef long HRESULT;typedef unsigned long ULONG;typedef int BOOL;
extern "C" __declspec(dllimport) BOOL __stdcall InvalidateRect(HWND,const tagRECT*,BOOL);
struct IUnknown {virtual HRESULT __stdcall QueryInterface(const _GUID&,void**)=0;virtual ULONG __stdcall AddRef()=0;virtual ULONG __stdcall Release()=0;};
namespace boost {
namespace noncopyable_ {class noncopyable {protected:noncopyable(){}~noncopyable(){}private:noncopyable(const noncopyable&);const noncopyable&operator=(const noncopyable&);};}typedef noncopyable_::noncopyable noncopyable;
namespace detail {
// Actual Boost1.34.1 Windows counted base; only unused methods are omitted.
class sp_counted_base {
 sp_counted_base(const sp_counted_base&);sp_counted_base&operator=(const sp_counted_base&);
 long use_count_,weak_count_;
public:
 sp_counted_base():use_count_(1),weak_count_(1){}
 virtual ~sp_counted_base(){}
 virtual void dispose()=0;
 virtual void destroy(){delete this;}
 virtual void*get_deleter(const std::type_info&)=0;
 void add_ref_copy(){_InterlockedIncrement(&use_count_);}
 void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
 void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
};
class shared_count {sp_counted_base*pi_;
public:shared_count():pi_(0){}
 shared_count(const shared_count&r):pi_(r.pi_){if(pi_)pi_->add_ref_copy();}
 shared_count&operator=(const shared_count&); //004025b0 native out-of-line boundary
 ~shared_count(){if(pi_)pi_->release();}
};
}
template<class T>class shared_ptr {T*px;detail::shared_count pn;
template<class Y>friend class shared_ptr;
public:shared_ptr():px(0),pn(){}
 template<class Y>shared_ptr(const shared_ptr<Y>&r):px(r.px),pn(r.pn){}
 void reset(); //00456e80 native out-of-line boundary
 template<class Y>shared_ptr&operator=(const shared_ptr<Y>&r){px=r.px;pn=r.pn;return *this;}
 T*get()const{return px;}T&operator*()const{return *px;}T*operator->()const{return px;}
 typedef T*shared_ptr::*unspecified_bool_type;
 operator unspecified_bool_type()const{return px==0?0:&shared_ptr::px;}
};
}

namespace boost {template<class T>inline void checked_delete(T*x){typedef char type_must_be_complete[sizeof(T)?1:-1];(void)sizeof(type_must_be_complete);delete x;}
class recursive_mutex;namespace detail {template<class M>class scoped_lock;}
template<class T>class scoped_ptr {T*ptr;scoped_ptr(const scoped_ptr&);scoped_ptr&operator=(const scoped_ptr&);
public:explicit scoped_ptr(T*p=0):ptr(p){}~scoped_ptr(){boost::checked_delete(ptr);}
void reset(T*p=0){scoped_ptr(p).swap(*this);}void swap(scoped_ptr&b){T*tmp=b.ptr;b.ptr=ptr;ptr=tmp;}T*get()const{return ptr;}T*operator->()const{return ptr;}
};}
namespace ATL {
inline IUnknown*__stdcall AtlComPtrAssign(IUnknown**pp,IUnknown*lp){if(pp==0)return 0;if(lp)lp->AddRef();if(*pp)(*pp)->Release();*pp=lp;return lp;}
template<class T>class CComPtrBase {protected:CComPtrBase()throw():p(0){}public:T*p;~CComPtrBase()throw(){if(p)p->Release();}operator T*()const throw(){return p;}};
template<class T>class CComPtr:public CComPtrBase<T> {public:T*operator=(T*lp)throw(){if(*this!=lp)return static_cast<T*>(AtlComPtrAssign((IUnknown**)&p,lp));return *this;}};
}

typedef enum {
	/* The keyboard syms have been cleverly chosen to map to ASCII */
	SDLK_UNKNOWN		= 0,
	SDLK_FIRST		= 0,
	SDLK_BACKSPACE		= 8,
	SDLK_TAB		= 9,
	SDLK_CLEAR		= 12,
	SDLK_RETURN		= 13,
	SDLK_PAUSE		= 19,
	SDLK_ESCAPE		= 27,
	SDLK_SPACE		= 32,
	SDLK_EXCLAIM		= 33,
	SDLK_QUOTEDBL		= 34,
	SDLK_HASH		= 35,
	SDLK_DOLLAR		= 36,
	SDLK_AMPERSAND		= 38,
	SDLK_QUOTE		= 39,
	SDLK_LEFTPAREN		= 40,
	SDLK_RIGHTPAREN		= 41,
	SDLK_ASTERISK		= 42,
	SDLK_PLUS		= 43,
	SDLK_COMMA		= 44,
	SDLK_MINUS		= 45,
	SDLK_PERIOD		= 46,
	SDLK_SLASH		= 47,
	SDLK_0			= 48,
	SDLK_1			= 49,
	SDLK_2			= 50,
	SDLK_3			= 51,
	SDLK_4			= 52,
	SDLK_5			= 53,
	SDLK_6			= 54,
	SDLK_7			= 55,
	SDLK_8			= 56,
	SDLK_9			= 57,
	SDLK_COLON		= 58,
	SDLK_SEMICOLON		= 59,
	SDLK_LESS		= 60,
	SDLK_EQUALS		= 61,
	SDLK_GREATER		= 62,
	SDLK_QUESTION		= 63,
	SDLK_AT			= 64,
	/* 
	   Skip uppercase letters
	 */
	SDLK_LEFTBRACKET	= 91,
	SDLK_BACKSLASH		= 92,
	SDLK_RIGHTBRACKET	= 93,
	SDLK_CARET		= 94,
	SDLK_UNDERSCORE		= 95,
	SDLK_BACKQUOTE		= 96,
	SDLK_a			= 97,
	SDLK_b			= 98,
	SDLK_c			= 99,
	SDLK_d			= 100,
	SDLK_e			= 101,
	SDLK_f			= 102,
	SDLK_g			= 103,
	SDLK_h			= 104,
	SDLK_i			= 105,
	SDLK_j			= 106,
	SDLK_k			= 107,
	SDLK_l			= 108,
	SDLK_m			= 109,
	SDLK_n			= 110,
	SDLK_o			= 111,
	SDLK_p			= 112,
	SDLK_q			= 113,
	SDLK_r			= 114,
	SDLK_s			= 115,
	SDLK_t			= 116,
	SDLK_u			= 117,
	SDLK_v			= 118,
	SDLK_w			= 119,
	SDLK_x			= 120,
	SDLK_y			= 121,
	SDLK_z			= 122,
	SDLK_DELETE		= 127,
	/* End of ASCII mapped keysyms */

	/* International keyboard syms */
	SDLK_WORLD_0		= 160,		/* 0xA0 */
	SDLK_WORLD_1		= 161,
	SDLK_WORLD_2		= 162,
	SDLK_WORLD_3		= 163,
	SDLK_WORLD_4		= 164,
	SDLK_WORLD_5		= 165,
	SDLK_WORLD_6		= 166,
	SDLK_WORLD_7		= 167,
	SDLK_WORLD_8		= 168,
	SDLK_WORLD_9		= 169,
	SDLK_WORLD_10		= 170,
	SDLK_WORLD_11		= 171,
	SDLK_WORLD_12		= 172,
	SDLK_WORLD_13		= 173,
	SDLK_WORLD_14		= 174,
	SDLK_WORLD_15		= 175,
	SDLK_WORLD_16		= 176,
	SDLK_WORLD_17		= 177,
	SDLK_WORLD_18		= 178,
	SDLK_WORLD_19		= 179,
	SDLK_WORLD_20		= 180,
	SDLK_WORLD_21		= 181,
	SDLK_WORLD_22		= 182,
	SDLK_WORLD_23		= 183,
	SDLK_WORLD_24		= 184,
	SDLK_WORLD_25		= 185,
	SDLK_WORLD_26		= 186,
	SDLK_WORLD_27		= 187,
	SDLK_WORLD_28		= 188,
	SDLK_WORLD_29		= 189,
	SDLK_WORLD_30		= 190,
	SDLK_WORLD_31		= 191,
	SDLK_WORLD_32		= 192,
	SDLK_WORLD_33		= 193,
	SDLK_WORLD_34		= 194,
	SDLK_WORLD_35		= 195,
	SDLK_WORLD_36		= 196,
	SDLK_WORLD_37		= 197,
	SDLK_WORLD_38		= 198,
	SDLK_WORLD_39		= 199,
	SDLK_WORLD_40		= 200,
	SDLK_WORLD_41		= 201,
	SDLK_WORLD_42		= 202,
	SDLK_WORLD_43		= 203,
	SDLK_WORLD_44		= 204,
	SDLK_WORLD_45		= 205,
	SDLK_WORLD_46		= 206,
	SDLK_WORLD_47		= 207,
	SDLK_WORLD_48		= 208,
	SDLK_WORLD_49		= 209,
	SDLK_WORLD_50		= 210,
	SDLK_WORLD_51		= 211,
	SDLK_WORLD_52		= 212,
	SDLK_WORLD_53		= 213,
	SDLK_WORLD_54		= 214,
	SDLK_WORLD_55		= 215,
	SDLK_WORLD_56		= 216,
	SDLK_WORLD_57		= 217,
	SDLK_WORLD_58		= 218,
	SDLK_WORLD_59		= 219,
	SDLK_WORLD_60		= 220,
	SDLK_WORLD_61		= 221,
	SDLK_WORLD_62		= 222,
	SDLK_WORLD_63		= 223,
	SDLK_WORLD_64		= 224,
	SDLK_WORLD_65		= 225,
	SDLK_WORLD_66		= 226,
	SDLK_WORLD_67		= 227,
	SDLK_WORLD_68		= 228,
	SDLK_WORLD_69		= 229,
	SDLK_WORLD_70		= 230,
	SDLK_WORLD_71		= 231,
	SDLK_WORLD_72		= 232,
	SDLK_WORLD_73		= 233,
	SDLK_WORLD_74		= 234,
	SDLK_WORLD_75		= 235,
	SDLK_WORLD_76		= 236,
	SDLK_WORLD_77		= 237,
	SDLK_WORLD_78		= 238,
	SDLK_WORLD_79		= 239,
	SDLK_WORLD_80		= 240,
	SDLK_WORLD_81		= 241,
	SDLK_WORLD_82		= 242,
	SDLK_WORLD_83		= 243,
	SDLK_WORLD_84		= 244,
	SDLK_WORLD_85		= 245,
	SDLK_WORLD_86		= 246,
	SDLK_WORLD_87		= 247,
	SDLK_WORLD_88		= 248,
	SDLK_WORLD_89		= 249,
	SDLK_WORLD_90		= 250,
	SDLK_WORLD_91		= 251,
	SDLK_WORLD_92		= 252,
	SDLK_WORLD_93		= 253,
	SDLK_WORLD_94		= 254,
	SDLK_WORLD_95		= 255,		/* 0xFF */

	/* Numeric keypad */
	SDLK_KP0		= 256,
	SDLK_KP1		= 257,
	SDLK_KP2		= 258,
	SDLK_KP3		= 259,
	SDLK_KP4		= 260,
	SDLK_KP5		= 261,
	SDLK_KP6		= 262,
	SDLK_KP7		= 263,
	SDLK_KP8		= 264,
	SDLK_KP9		= 265,
	SDLK_KP_PERIOD		= 266,
	SDLK_KP_DIVIDE		= 267,
	SDLK_KP_MULTIPLY	= 268,
	SDLK_KP_MINUS		= 269,
	SDLK_KP_PLUS		= 270,
	SDLK_KP_ENTER		= 271,
	SDLK_KP_EQUALS		= 272,

	/* Arrows + Home/End pad */
	SDLK_UP			= 273,
	SDLK_DOWN		= 274,
	SDLK_RIGHT		= 275,
	SDLK_LEFT		= 276,
	SDLK_INSERT		= 277,
	SDLK_HOME		= 278,
	SDLK_END		= 279,
	SDLK_PAGEUP		= 280,
	SDLK_PAGEDOWN		= 281,

	/* Function keys */
	SDLK_F1			= 282,
	SDLK_F2			= 283,
	SDLK_F3			= 284,
	SDLK_F4			= 285,
	SDLK_F5			= 286,
	SDLK_F6			= 287,
	SDLK_F7			= 288,
	SDLK_F8			= 289,
	SDLK_F9			= 290,
	SDLK_F10		= 291,
	SDLK_F11		= 292,
	SDLK_F12		= 293,
	SDLK_F13		= 294,
	SDLK_F14		= 295,
	SDLK_F15		= 296,

	/* Key state modifier keys */
	SDLK_NUMLOCK		= 300,
	SDLK_CAPSLOCK		= 301,
	SDLK_SCROLLOCK		= 302,
	SDLK_RSHIFT		= 303,
	SDLK_LSHIFT		= 304,
	SDLK_RCTRL		= 305,
	SDLK_LCTRL		= 306,
	SDLK_RALT		= 307,
	SDLK_LALT		= 308,
	SDLK_RMETA		= 309,
	SDLK_LMETA		= 310,
	SDLK_LSUPER		= 311,		/* Left "Windows" key */
	SDLK_RSUPER		= 312,		/* Right "Windows" key */
	SDLK_MODE		= 313,		/* "Alt Gr" key */
	SDLK_COMPOSE		= 314,		/* Multi-key compose key */

	/* Miscellaneous function keys */
	SDLK_HELP		= 315,
	SDLK_PRINT		= 316,
	SDLK_SYSREQ		= 317,
	SDLK_BREAK		= 318,
	SDLK_MENU		= 319,
	SDLK_POWER		= 320,		/* Power Macintosh power key */
	SDLK_EURO		= 321,		/* Some european keyboards */
	SDLK_UNDO		= 322,		/* Atari keyboard has Undo */

	/* Add any other keys here */

	SDLK_LAST
} SDLKey;

class CWnd;union SDL_Event;
namespace G3D {class Vector2;class Vector3;class Rect2D;class Color4;class CoordinateFrame;class AABox;class Sphere;class Ray;class LineSegment;
// Genuine counted-handle storage; no handle methods/objects are used by this TU.
template<class T>class ReferenceCountedPointer {T*pointer;};}
class RenderStats;
namespace RBX {class TextureProxyBase;class TextureId;class Adorn;class RunService;template<class C,class E>class Notifier;class Name {public:static const Name&getNullName();};
class ContentId
	{
	private:
		std::string id;
		const Name* mimeTypePtr;

	public:
		ContentId()
			: id(), 
			  mimeTypePtr(&Name::getNullName())
		{
		}
		ContentId(const std::string& id)
			: id(id),
			  mimeTypePtr(&Name::getNullName())
		{
		}
		ContentId(const char* id)
			: id(id),
			  mimeTypePtr(&Name::getNullName())
		{
		}
		ContentId(const std::string& id, const Name& mimeType)
			: id(id),
			  mimeTypePtr(&mimeType)
		{
		}

	public:
		const Name& mimeType() const
		{
			return *mimeTypePtr;
		}
		const char* c_str() const
		{
			return id.c_str();
		}
		const std::string& toString() const
		{
			return id;
		}
		bool isNull() const
		{
			return id.empty();
		}
		bool isFile() const
		{
			return id.substr(0, 7) == "file://";
		}
		bool isAsset() const
		{
			return id.substr(0, 11) == "rbxasset://";
		}
		bool isHttp() const
		{
			return id.substr(0, 4) == "http";
		}

	public:
		static ContentId fromUrl(const std::string&);
		static ContentId fromFile(const std::string&);
		static ContentId fromAssets(const std::string& filePath);
		static ContentId fromMD5Hash(const std::string&);
	};
enum RunState
	{
		RS_NORMAL,
		RS_RUNNING,
		RS_PAUSED
	};

	class RunTransition
	{
	public:
		RunState oldState;
		RunState newState;

		RunTransition(RunState oldState, RunState newState)
			: oldState(oldState),
			  newState(newState)
		{
		}

		bool startEvent();
		bool resetEvent();
	};

	class Heartbeat
	{
	public:
		const float time;
		const float step;

		Heartbeat(float time, float step)
			: time(time),
			step(step)
		{
		}
	};

	class Stepped
	{
	public:
		const float time;
		const float step;

		Stepped(float time, float step)
			: time(time),
			step(step)
		{
		}
	};

	class IRunView
	{
	public:
		virtual void InvalidateRunView() = 0;
		virtual void AdjustThrottle(double) = 0;
	};


template<typename Class, typename Event>
	class __declspec(novtable) Listener
	{
		friend class Notifier<Class, Event>;

	protected:
		virtual void onEvent(const Class*, Event) = 0;
		Listener& operator=(const Listener&);

		virtual ~Listener()
		{
		}
	};}
namespace RBX
{
	class Adorn;
	class UserInputBase
	{
	public:
		enum WrapMode
		{
			WRAP_AUTO,
			WRAP_CENTER
		};

	private:
		ContentId currentCursorId;
		G3D::ReferenceCountedPointer<TextureProxyBase> currentCursor;
	  
	protected:
		virtual G3D::Vector2 getCursorPosition() = 0;
		virtual G3D::ReferenceCountedPointer<TextureProxyBase> getGameCursor(Adorn*);
	public:
		UserInputBase();
	public:
		void init(Adorn*);
	public:
		~UserInputBase();
	public:
		virtual void setWrapMode(WrapMode) = 0;
		virtual WrapMode getWrapMode() const = 0;
		virtual void centerCursor() = 0;
		virtual bool keyDown(SDLKey) const = 0;
		bool altKeyDown() const;
		bool shiftKeyDown() const;
		bool ctrlKeyDown() const;
		virtual void setKeyState(SDLKey key, bool down) = 0;
		virtual void setCursorId(Adorn*, const TextureId&);
		void renderGameCursor(Adorn*);
	};
}

// Used G3D6.09 interfaces and inline vector bodies, unchanged.
namespace G3D {
class Vector2 {public:float x,y;Vector2():x(0.0f),y(0.0f){}Vector2(float x,float y):x(x),y(y){}static const Vector2&zero();bool operator!=(const Vector2&v)const{return x!=v.x||y!=v.y;}};
class Vector2int16 {public:short x,y;Vector2int16():x(0),y(0){}Vector2int16(short x,short y):x(x),y(y){}Vector2int16(const Vector2&);};
}
typedef unsigned long DWORD;typedef unsigned int UINT_PTR;
typedef struct DIDEVICEOBJECTDATA {DWORD dwOfs,dwData,dwTimeStamp,dwSequence;UINT_PTR uAppData;}DIDEVICEOBJECTDATA;
struct IDirectInputDevice8A;
// WinSDK x86 RTL_CRITICAL_SECTION. No native synchronization objects constructed.
struct _RTL_CRITICAL_SECTION_DEBUG;
typedef struct _RTL_CRITICAL_SECTION { _RTL_CRITICAL_SECTION_DEBUG*DebugInfo;long LockCount,RecursionCount;void*OwningThread;void*LockSemaphore;unsigned long SpinCount;}CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) BOOL __stdcall PostMessageA(HWND,unsigned int,unsigned int,long);
namespace ATL {
void __stdcall AtlThrow(HRESULT);
class CComCriticalSection {public:HRESULT Lock()throw(){EnterCriticalSection(&m_sec);return 0;}HRESULT Unlock()throw(){LeaveCriticalSection(&m_sec);return 0;}CRITICAL_SECTION m_sec;};
template<class TLock>class CComCritSecLock {
 TLock&m_cs;bool m_bLocked;
 CComCritSecLock(const CComCritSecLock&)throw();CComCritSecLock&operator=(const CComCritSecLock&)throw();
public:CComCritSecLock(TLock&cs,bool bInitialLock=true):m_cs(cs),m_bLocked(false){if(bInitialLock){HRESULT hr=Lock();if(hr<0)AtlThrow(hr);}}
 ~CComCritSecLock()throw(){if(m_bLocked)Unlock();}
 HRESULT Lock()throw(){HRESULT hr=m_cs.Lock();if(hr<0)return hr;m_bLocked=true;return 0;}
 void Unlock()throw(){m_cs.Unlock();m_bLocked=false;}
};
}
namespace RBX {
// Native20-byte UIEvent mouse representation, with original four-argument ctor.
class UIEvent {public:enum EventType {NO_EVENT,MOUSE_RIGHT_BUTTON_DOWN,MOUSE_RIGHT_BUTTON_UP,MOUSE_LEFT_BUTTON_DOWN,MOUSE_LEFT_BUTTON_UP,MOUSE_MOVE,MOUSE_DELTA,MOUSE_IDLE,MOUSE_WHEEL_FORWARD,MOUSE_WHEEL_BACKWARD,KEY_DOWN,KEY_UP};
 EventType eventType;UserInputBase*userInput;G3D::Vector2int16 mousePosition,mouseDelta,windowSize;
 UIEvent(UserInputBase*u,EventType t,G3D::Vector2int16 w,G3D::Vector2int16 p):eventType(t),userInput(u),mousePosition(p),mouseDelta(),windowSize(w){}
};
class Workspace {public:void onWrapMouse(const G3D::Vector2&);}; //005a0220
class DataModel {public:
 class Lock {boost::shared_ptr<boost::recursive_mutex>mutex;boost::detail::scoped_lock<boost::recursive_mutex>*lock;public:Lock(boost::shared_ptr<const DataModel>);~Lock();};
 char observed00[0x204];boost::shared_ptr<Workspace>workspace;
 Workspace*getWorkspace()const{return workspace.get();}
};
}
// Existing CWnd pointer only; observed HWND field20. No CWnd objects or size claim.
class CWnd {public:char observed00[0x20];HWND m_hWnd;BOOL PostMessage(unsigned int message,unsigned int wParam=0,long lParam=0){return ::PostMessageA(m_hWnd,message,wParam,lParam);}};
class DxUserInput:public RBX::UserInputBase,public RBX::Listener<RBX::RunService,RBX::RunTransition>,public RBX::Listener<RBX::RunService,RBX::Heartbeat> {
public:
 char observed30[4];ATL::CComCriticalSection critical;char observed4c[0x120];CWnd*window;char observed170[8];IDirectInputDevice8A*mouseDevice;char observed17c[4];boost::shared_ptr<RBX::DataModel>model;char observed188[10];bool acquired;char observed193;
 DxUserInput(CWnd*,RBX::DataModel*);~DxUserInput();
 G3D::Vector2 getCursorPosition();void setWrapMode(WrapMode);WrapMode getWrapMode()const;void centerCursor();bool keyDown(SDLKey)const;void setKeyState(SDLKey,bool);
 void onEvent(const RBX::RunService*,RBX::RunTransition);void onEvent(const RBX::RunService*,RBX::Heartbeat);
 bool readBufferedInput(DIDEVICEOBJECTDATA*,DWORD*,IDirectInputDevice8A*); //00467880 ret12
 G3D::Vector2int16 getWindowSize(); //00467440 hiddenret4
 void sendMouseEvent(RBX::UIEvent::EventType,const G3D::Vector2&); //004684a0 ret8
 void onMouseMove(const G3D::Vector2&,G3D::Vector2&); //00467f10 ret8
 void dispatchEvent(const RBX::UIEvent&); //00467a00 ret4
 void processMouseInput();
};
G3D::Vector2 mouseAxisDelta(const DIDEVICEOBJECTDATA&); //00469340 cdecl hidden result
extern const float wheelDeltaScale; //0081c3e4
void DxUserInput::processMouseInput(){
 DIDEVICEOBJECTDATA data[2048];DWORD count=2048;
 {ATL::CComCritSecLock<ATL::CComCriticalSection>guard(critical);
  IDirectInputDevice8A*device=mouseDevice;
  if(!readBufferedInput(data,&count,device)){acquired=false;return;}
 }
 G3D::Vector2 delta;bool moved=false;
 for(DWORD i=0;i<count;++i){
  switch(data[i].dwOfs){
   case 12:window->PostMessage(0x4bb);sendMouseEvent(data[i].dwData==0x80?RBX::UIEvent::MOUSE_LEFT_BUTTON_DOWN:RBX::UIEvent::MOUSE_LEFT_BUTTON_UP,getCursorPosition());break;
   case 13:window->PostMessage(0x4bb);sendMouseEvent(data[i].dwData==0x80?RBX::UIEvent::MOUSE_RIGHT_BUTTON_DOWN:RBX::UIEvent::MOUSE_RIGHT_BUTTON_UP,getCursorPosition());break;
   case 0:case 4:moved=true;onMouseMove(mouseAxisDelta(data[i]),delta);break;
   case 8:sendMouseEvent(float(long(data[i].dwData))*wheelDeltaScale>0.0f?RBX::UIEvent::MOUSE_WHEEL_FORWARD:RBX::UIEvent::MOUSE_WHEEL_BACKWARD,getCursorPosition());break;
  }
 }
 if(delta!=G3D::Vector2::zero()){
  RBX::DataModel::Lock lock(model);
  model->getWorkspace()->onWrapMouse(delta);
  {RBX::UIEvent event(this,RBX::UIEvent::MOUSE_DELTA,getWindowSize(),getCursorPosition());dispatchEvent(event);}
  {RBX::UIEvent event(this,RBX::UIEvent::MOUSE_MOVE,getWindowSize(),getCursorPosition());dispatchEvent(event);}
 }else if(moved){
  RBX::DataModel::Lock lock(model);
  RBX::UIEvent event(this,RBX::UIEvent::MOUSE_MOVE,getWindowSize(),getCursorPosition());dispatchEvent(event);
 }
}



typedef char input_vec_size[sizeof(G3D::Vector2)==8?1:-1];
typedef char input_shortvec_size[sizeof(G3D::Vector2int16)==4?1:-1];
typedef char input_shortvec_align[__alignof(G3D::Vector2int16)==2?1:-1];
typedef char input_event_size[sizeof(RBX::UIEvent)==20?1:-1];
typedef char input_event_position[offsetof(RBX::UIEvent,mousePosition)==8?1:-1];
typedef char input_event_delta[offsetof(RBX::UIEvent,mouseDelta)==12?1:-1];
typedef char input_event_window[offsetof(RBX::UIEvent,windowSize)==16?1:-1];
typedef char input_data_size[sizeof(DIDEVICEOBJECTDATA)==20?1:-1];
typedef char input_data_data[offsetof(DIDEVICEOBJECTDATA,dwData)==4?1:-1];
typedef char input_cs_size[sizeof(CRITICAL_SECTION)==24?1:-1];
typedef char input_cs_align[__alignof(CRITICAL_SECTION)==4?1:-1];
typedef char input_guard_size[sizeof(ATL::CComCritSecLock<ATL::CComCriticalSection>)==8?1:-1];
typedef char input_shared_size[sizeof(boost::shared_ptr<RBX::DataModel>)==8?1:-1];
typedef char input_lock_size[sizeof(RBX::DataModel::Lock)==12?1:-1];
typedef char input_base_size[sizeof(RBX::UserInputBase)==40?1:-1];
typedef char input_dx_size[sizeof(DxUserInput)==404?1:-1];
typedef char input_mutex_offset[offsetof(DxUserInput,critical)==0x34?1:-1];
typedef char input_window_offset[offsetof(DxUserInput,window)==0x16c?1:-1];
typedef char input_device_offset[offsetof(DxUserInput,mouseDevice)==0x178?1:-1];
typedef char input_model_offset[offsetof(DxUserInput,model)==0x180?1:-1];
typedef char input_acquired_offset[offsetof(DxUserInput,acquired)==0x192?1:-1];
typedef char input_workspace_offset[offsetof(RBX::DataModel,workspace)==0x204?1:-1];
typedef char input_hwnd_offset[offsetof(CWnd,m_hWnd)==0x20?1:-1];
