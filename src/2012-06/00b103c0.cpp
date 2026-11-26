// from server: 100% by Xemicl
// roc 2012-06 00b103c0  unit: seg_00b10000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b103c0
//
// 00b103c0  51                   push ecx
// 00b103c1  56                   push esi
// 00b103c2  c644240400           mov byte ptr [esp + 4], 0
// 00b103c7  e80457e6ff           call 0x975ad0
// 00b103cc  8bf0                 mov esi, eax
// 00b103ce  8b442404             mov eax, dword ptr [esp + 4]
// 00b103d2  50                   push eax
// 00b103d3  56                   push esi
// 00b103d4  b9b881e500           mov ecx, 0xe581b8
// 00b103d9  8935b481e500         mov dword ptr [0xe581b4], esi
// 00b103df  e89c57e6ff           call 0x975b80
// 00b103e4  56                   push esi
// 00b103e5  56                   push esi
// 00b103e6  68b881e500           push 0xe581b8
// 00b103eb  e8a0a3a8ff           call 0x59a790
// 00b103f0  684015b200           push 0xb21540
// 00b103f5  e8fb2de7ff           call 0x9831f5
// 00b103fa  83c410               add esp, 0x10
// 00b103fd  5e                   pop esi
// 00b103fe  59                   pop ecx
// 00b103ff  c3                   ret 
// copied from an identical function in another client (function ??__EtheHeap@@YAXXZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace boost {
namespace detail {
class shared_count {
    void* pi_;
public:
    template<class P, class D> shared_count(P p, D d);
    ~shared_count();
};
void sp_enable_shared_from_this(const shared_count&, ...) throw();
}
template<class T> class shared_ptr {
    T* px;
    detail::shared_count pn;
public:
    template<class Y, class D> __forceinline shared_ptr(Y* p, D d) : px(p), pn(p, d)
    {
        detail::sp_enable_shared_from_this(pn, p, p);
    }
};
}
struct Heap { virtual ~Heap(); };
struct HeapDeleter { void operator()(Heap*); };
Heap* createHeap();
boost::shared_ptr<Heap> theHeap(createHeap(), HeapDeleter());