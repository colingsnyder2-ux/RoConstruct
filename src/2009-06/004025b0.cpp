// from server: 100% by EspClaude
// roc 2009-06 004025b0  unit: RBX::VTaskSchedulerSettings::?$FactoryProduct::Creator  size: 571 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004025b0
//
// 004025b0  6aff                 push -1
// 004025b2  6830798600           push 0x867930
// 004025b7  64a100000000         mov eax, dword ptr fs:[0]
// 004025bd  50                   push eax
// 004025be  64892500000000       mov dword ptr fs:[0], esp
// 004025c5  83ec10               sub esp, 0x10
// 004025c8  53                   push ebx
// 004025c9  55                   push ebp
// 004025ca  8b2d1097a300         mov ebp, dword ptr [0xa39710]
// 004025d0  56                   push esi
// 004025d1  57                   push edi
// 004025d2  8b3d1497a300         mov edi, dword ptr [0xa39714]
// 004025d8  33db                 xor ebx, ebx
// 004025da  896c2418             mov dword ptr [esp + 0x18], ebp
// 004025de  897c241c             mov dword ptr [esp + 0x1c], edi
// 004025e2  3bfb                 cmp edi, ebx
// 004025e4  740c                 je 0x4025f2
// 004025e6  8d4704               lea eax, [edi + 4]
// 004025e9  b901000000           mov ecx, 1
// 004025ee  f00fc108             lock xadd dword ptr [eax], ecx
// 004025f2  807c243000           cmp byte ptr [esp + 0x30], 0
// 004025f7  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 004025fb  895c2428             mov dword ptr [esp + 0x28], ebx
// 004025ff  746c                 je 0x40266d
// 00402601  8d542410             lea edx, [esp + 0x10]
// 00402605  52                   push edx
// 00402606  890de096a300         mov dword ptr [0xa396e0], ecx
// 0040260c  e86fffffff           call 0x402580
// 00402611  8b08                 mov ecx, dword ptr [eax]
// 00402613  83c004               add eax, 4
// 00402616  890d1097a300         mov dword ptr [0xa39710], ecx
// 0040261c  50                   push eax
// 0040261d  b91497a300           mov ecx, 0xa39714
// 00402622  c644242c01           mov byte ptr [esp + 0x2c], 1
// 00402627  e8d4feffff           call 0x402500
// 0040262c  8b742414             mov esi, dword ptr [esp + 0x14]
// 00402630  c644242800           mov byte ptr [esp + 0x28], 0
// 00402635  3bf3                 cmp esi, ebx
// 00402637  0f8493000000         je 0x4026d0
// 0040263d  8d5604               lea edx, [esi + 4]
// 00402640  83c8ff               or eax, 0xffffffff
// 00402643  f00fc102             lock xadd dword ptr [edx], eax
// 00402647  0f8583000000         jne 0x4026d0
// 0040264d  8b16                 mov edx, dword ptr [esi]
// 0040264f  8b4204               mov eax, dword ptr [edx + 4]
// 00402652  8bce                 mov ecx, esi
// 00402654  ffd0                 call eax
// 00402656  8d4e08               lea ecx, [esi + 8]
// 00402659  83caff               or edx, 0xffffffff
// 0040265c  f00fc111             lock xadd dword ptr [ecx], edx
// 00402660  756e                 jne 0x4026d0
// 00402662  8b06                 mov eax, dword ptr [esi]
// 00402664  8b5008               mov edx, dword ptr [eax + 8]
// 00402667  8bce                 mov ecx, esi
// 00402669  ffd2                 call edx
// 0040266b  eb63                 jmp 0x4026d0
// 0040266d  3b0de096a300         cmp ecx, dword ptr [0xa396e0]
// 00402673  7506                 jne 0x40267b
// 00402675  891de096a300         mov dword ptr [0xa396e0], ebx
// 0040267b  8d442410             lea eax, [esp + 0x10]
// 0040267f  50                   push eax
// 00402680  e8fbfeffff           call 0x402580
// 00402685  8b00                 mov eax, dword ptr [eax]
// 00402687  3b051097a300         cmp eax, dword ptr [0xa39710]
// 0040268d  8b742414             mov esi, dword ptr [esp + 0x14]
// 00402691  0f94c3               sete bl
// 00402694  85f6                 test esi, esi
// 00402696  742a                 je 0x4026c2
// 00402698  8d4e04               lea ecx, [esi + 4]
// 0040269b  83caff               or edx, 0xffffffff
// 0040269e  f00fc111             lock xadd dword ptr [ecx], edx
// 004026a2  751e                 jne 0x4026c2
// 004026a4  8b06                 mov eax, dword ptr [esi]
// 004026a6  8b5004               mov edx, dword ptr [eax + 4]
// 004026a9  8bce                 mov ecx, esi
// 004026ab  ffd2                 call edx
// 004026ad  8d4608               lea eax, [esi + 8]
// 004026b0  83c9ff               or ecx, 0xffffffff
// 004026b3  f00fc108             lock xadd dword ptr [eax], ecx
// 004026b7  7509                 jne 0x4026c2
// 004026b9  8b16                 mov edx, dword ptr [esi]
// 004026bb  8b4208               mov eax, dword ptr [edx + 8]
// 004026be  8bce                 mov ecx, esi
// 004026c0  ffd0                 call eax
// 004026c2  84db                 test bl, bl
// 004026c4  740a                 je 0x4026d0
// 004026c6  b91097a300           mov ecx, 0xa39710
// 004026cb  e8d0480600           call 0x466fa0
// 004026d0  392d1097a300         cmp dword ptr [0xa39710], ebp
// 004026d6  0f84c6000000         je 0x4027a2
// 004026dc  8b0d0897a300         mov ecx, dword ptr [0xa39708]
// 004026e2  8b29                 mov ebp, dword ptr [ecx]
// 004026e4  8b35f096a300         mov esi, dword ptr [0xa396f0]
// 004026ea  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 004026f0  896c2414             mov dword ptr [esp + 0x14], ebp
// 004026f4  89742410             mov dword ptr [esp + 0x10], esi
// 004026f8  eb06                 jmp 0x402700
// 004026fa  8d9b00000000         lea ebx, [ebx]
// 00402700  8b3d0897a300         mov edi, dword ptr [0xa39708]
// 00402706  85f6                 test esi, esi
// 00402708  7408                 je 0x402712
// 0040270a  3b35f096a300         cmp esi, dword ptr [0xa396f0]
// 00402710  7402                 je 0x402714
// 00402712  ffd3                 call ebx
// 00402714  3bef                 cmp ebp, edi
// 00402716  0f8482000000         je 0x40279e
// 0040271c  85f6                 test esi, esi
// 0040271e  757a                 jne 0x40279a
// 00402720  ffd3                 call ebx
// 00402722  3b6e18               cmp ebp, dword ptr [esi + 0x18]
// 00402725  7502                 jne 0x402729
// 00402727  ffd3                 call ebx
// 00402729  8b542418             mov edx, dword ptr [esp + 0x18]
// 0040272d  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00402730  83ec08               sub esp, 8
// 00402733  8bc4                 mov eax, esp
// 00402735  8910                 mov dword ptr [eax], edx
// 00402737  8b542424             mov edx, dword ptr [esp + 0x24]
// 0040273b  89642438             mov dword ptr [esp + 0x38], esp
// 0040273f  895004               mov dword ptr [eax + 4], edx
// 00402742  85d2                 test edx, edx
// 00402744  740c                 je 0x402752
// 00402746  83c204               add edx, 4
// 00402749  b801000000           mov eax, 1
// 0040274e  f00fc102             lock xadd dword ptr [edx], eax
// 00402752  8b151097a300         mov edx, dword ptr [0xa39710]
// 00402758  83ec08               sub esp, 8
// 0040275b  8bc4                 mov eax, esp
// 0040275d  8910                 mov dword ptr [eax], edx
// 0040275f  8b151497a300         mov edx, dword ptr [0xa39714]
// 00402765  895004               mov dword ptr [eax + 4], edx
// 00402768  8bc2                 mov eax, edx
// 0040276a  89642440             mov dword ptr [esp + 0x40], esp
// 0040276e  85c0                 test eax, eax
// 00402770  740c                 je 0x40277e
// 00402772  83c004               add eax, 4
// 00402775  ba01000000           mov edx, 1
// 0040277a  f00fc110             lock xadd dword ptr [eax], edx
// 0040277e  8b01                 mov eax, dword ptr [ecx]
// 00402780  8b10                 mov edx, dword ptr [eax]
// 00402782  ffd2                 call edx
// 00402784  8d4c2410             lea ecx, [esp + 0x10]
// 00402788  e8c3402b00           call 0x6b6850
// 0040278d  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00402791  8b742410             mov esi, dword ptr [esp + 0x10]
// 00402795  e966ffffff           jmp 0x402700
// 0040279a  8b36                 mov esi, dword ptr [esi]
// 0040279c  eb84                 jmp 0x402722
// 0040279e  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 004027a2  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 004027aa  85ff                 test edi, edi
// 004027ac  742a                 je 0x4027d8
// 004027ae  8d4704               lea eax, [edi + 4]
// 004027b1  83c9ff               or ecx, 0xffffffff
// 004027b4  f00fc108             lock xadd dword ptr [eax], ecx
// 004027b8  751e                 jne 0x4027d8
// 004027ba  8b17                 mov edx, dword ptr [edi]
// 004027bc  8b4204               mov eax, dword ptr [edx + 4]
// 004027bf  8bcf                 mov ecx, edi
// 004027c1  ffd0                 call eax
// 004027c3  8d4f08               lea ecx, [edi + 8]
// 004027c6  83caff               or edx, 0xffffffff
// 004027c9  f00fc111             lock xadd dword ptr [ecx], edx
// 004027cd  7509                 jne 0x4027d8
// 004027cf  8b07                 mov eax, dword ptr [edi]
// 004027d1  8b5008               mov edx, dword ptr [eax + 8]
// 004027d4  8bcf                 mov ecx, edi
// 004027d6  ffd2                 call edx
// 004027d8  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004027dc  5f                   pop edi
// 004027dd  5e                   pop esi
// 004027de  5d                   pop ebp
// 004027df  64890d00000000       mov dword ptr fs:[0], ecx
// 004027e6  5b                   pop ebx
// 004027e7  83c41c               add esp, 0x1c
// 004027ea  c3                   ret 
// copied from an identical function in another client (function ?setCurrent@@YAX_NPAVOwner@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <set>
#include <intrin.h>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    long use_count_;
    long weak_count_;
};

class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r);
};

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    T* get() const { return px; }
    void reset();
};
template<class T, class U> inline bool operator==(const shared_ptr<T>& a, const shared_ptr<U>& b) { return a.get() == b.get(); }
template<class T, class U> inline bool operator!=(const shared_ptr<T>& a, const shared_ptr<U>& b) { return a.get() != b.get(); }

class Item;
class Owner {
public:
    shared_ptr<Item> getItem();
};

class Listener {
public:
    virtual void onChanged(shared_ptr<Item> current, shared_ptr<Item> previous) = 0;
};

extern Owner* g_owner;
extern std::set<Listener*> g_listeners;
extern shared_ptr<Item> g_current;

void __cdecl setCurrent(bool on, Owner* owner)
{
    shared_ptr<Item> previous(g_current);
    if (on)
    {
        g_owner = owner;
        g_current = owner->getItem();
    }
    else
    {
        if (owner == g_owner)
            g_owner = 0;
        if (owner->getItem() == g_current)
            g_current.reset();
    }
    if (g_current != previous)
    {
        for (std::set<Listener*>::iterator it = g_listeners.begin(); it != g_listeners.end(); ++it)
            (*it)->onChanged(g_current, previous);
    }
}