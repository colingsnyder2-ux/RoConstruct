// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 41% by colin
// roc 2007-08 004d30d0  unit: RBX::Render::Chunk  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004d30d0
//
// 004d30d0  6aff                 push -1
// 004d30d2  6824c67400           push 0x74c624
// 004d30d7  64a100000000         mov eax, dword ptr fs:[0]
// 004d30dd  50                   push eax
// 004d30de  64892500000000       mov dword ptr fs:[0], esp
// 004d30e5  51                   push ecx
// 004d30e6  56                   push esi
// 004d30e7  8bf1                 mov esi, ecx
// 004d30e9  57                   push edi
// 004d30ea  89742408             mov dword ptr [esp + 8], esi
// 004d30ee  c706d8f17900         mov dword ptr [esi], 0x79f1d8
// 004d30f4  8d8ee8000000         lea ecx, [esi + 0xe8]
// 004d30fa  c744241402000000     mov dword ptr [esp + 0x14], 2
// 004d3102  e899542500           call 0x7285a0
// 004d3107  8d8ed4000000         lea ecx, [esi + 0xd4]
// 004d310d  c644241401           mov byte ptr [esp + 0x14], 1
// 004d3112  e889542500           call 0x7285a0
// 004d3117  8bbed0000000         mov edi, dword ptr [esi + 0xd0]
// 004d311d  85ff                 test edi, edi
// 004d311f  c644241400           mov byte ptr [esp + 0x14], 0
// 004d3124  742a                 je 0x4d3150
// 004d3126  8d4704               lea eax, [edi + 4]
// 004d3129  83c9ff               or ecx, 0xffffffff
// 004d312c  f00fc108             lock xadd dword ptr [eax], ecx
// 004d3130  751e                 jne 0x4d3150
// 004d3132  8b17                 mov edx, dword ptr [edi]
// 004d3134  8b4204               mov eax, dword ptr [edx + 4]
// 004d3137  8bcf                 mov ecx, edi
// 004d3139  ffd0                 call eax
// 004d313b  8d4f08               lea ecx, [edi + 8]
// 004d313e  83caff               or edx, 0xffffffff
// 004d3141  f00fc111             lock xadd dword ptr [ecx], edx
// 004d3145  7509                 jne 0x4d3150
// 004d3147  8b07                 mov eax, dword ptr [edi]
// 004d3149  8b5008               mov edx, dword ptr [eax + 8]
// 004d314c  8bcf                 mov ecx, edi
// 004d314e  ffd2                 call edx
// 004d3150  8bce                 mov ecx, esi
// 004d3152  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 004d315a  e881fdffff           call 0x4d2ee0
// 004d315f  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004d3163  5f                   pop edi
// 004d3164  5e                   pop esi
// 004d3165  64890d00000000       mov dword ptr fs:[0], ecx
// 004d316c  83c410               add esp, 0x10
// 004d316f  c3                   ret 

// Destructor: members destroyed 0xe8, 0xd4 (same dtor 0x7285a0, 0x14 apart), then
// shared count at 0xd0 (boost w32 sp_counted_base: use_count +4, weak_count +8,
// vt[1] dispose, vt[2] destroy, decrement == 0), then base dtor 0x4d2ee0.

extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedDecrement)

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;

    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};

template<class T> class shared_ptr {
public:
    T* px;
    sp_counted_base* pi_;
    ~shared_ptr() { if (pi_ != 0) pi_->release(); }
};

class Member {
    int data[5];
public:
    ~Member();
};

class ChunkBase {
public:
    virtual ~ChunkBase();
    int pad[50];
};

class Thing;

class Chunk : public ChunkBase {
public:
    shared_ptr<Thing> sp;
    Member m1;
    Member m2;
    virtual ~Chunk();
};

Chunk::~Chunk()
{
}
