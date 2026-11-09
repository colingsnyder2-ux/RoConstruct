// roc 2012-06 00864920  unit: RBX::BaseThreadPool::UPoolData::XP6AXV?$shared_ptr::V?$bind_t::?$thread_data  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00864920
//
// 00864920  53                   push ebx
// 00864921  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00864925  56                   push esi
// 00864926  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0086492a  3bf3                 cmp esi, ebx
// 0086492c  742a                 je 0x864958
// 0086492e  57                   push edi
// 0086492f  8d7e08               lea edi, [esi + 8]
// 00864932  8b06                 mov eax, dword ptr [esi]
// 00864934  85c0                 test eax, eax
// 00864936  7415                 je 0x86494d
// 00864938  8b00                 mov eax, dword ptr [eax]
// 0086493a  85c0                 test eax, eax
// 0086493c  7409                 je 0x864947
// 0086493e  6a02                 push 2
// 00864940  57                   push edi
// 00864941  57                   push edi
// 00864942  ffd0                 call eax
// 00864944  83c40c               add esp, 0xc
// 00864947  c70600000000         mov dword ptr [esi], 0
// 0086494d  83c628               add esi, 0x28
// 00864950  83c728               add edi, 0x28
// 00864953  3bf3                 cmp esi, ebx
// 00864955  75db                 jne 0x864932
// 00864957  5f                   pop edi
// 00864958  5e                   pop esi
// 00864959  5b                   pop ebx
// 0086495a  c3                   ret 
// copied from an identical function in another client (function ?destroy_range@ns_ROCX000003@@YAXPAUElem@1@0@Z)

namespace ns_ROCX000003 {
// from server: 100% by atomic.potato
struct Elem {
    void* p;
    int pad[9];
};

struct Range {
    Elem* first;
    Elem* last;
};

void destroy_range(Elem* first, Elem* last) {
    while (first != last) {
        void** pp = (void**)first;
        void* obj = *pp;
        if (obj != 0) {
            void* fn = *(void**)obj;
            if (fn != 0) {
                typedef void (__cdecl *Fn)(void*, void*, int);
                ((Fn)fn)((void*)((char*)first + 8), (void*)((char*)first + 8), 2);
            }
            *pp = 0;
        }
        first = (Elem*)((char*)first + 0x28);
    }
}
}