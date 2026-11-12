// from server: 100% by EspClaude
// from server: 50% by colin
// roc 2007-08 004628b0  unit: RBX::VSelection::?$MarshaledListener  size: 155 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004628b0
//
// 004628b0  51                   push ecx
// 004628b1  56                   push esi
// 004628b2  57                   push edi
// 004628b3  6a20                 push 0x20
// 004628b5  8bf9                 mov edi, ecx
// 004628b7  e83ad61c00           call 0x62fef6
// 004628bc  83c404               add esp, 4
// 004628bf  85c0                 test eax, eax
// 004628c1  745d                 je 0x462920
// 004628c3  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004628c7  83ec10               sub esp, 0x10
// 004628ca  8bd4                 mov edx, esp
// 004628cc  890a                 mov dword ptr [edx], ecx
// 004628ce  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004628d2  894a04               mov dword ptr [edx + 4], ecx
// 004628d5  8b742428             mov esi, dword ptr [esp + 0x28]
// 004628d9  85f6                 test esi, esi
// 004628db  89642418             mov dword ptr [esp + 0x18], esp
// 004628df  740c                 je 0x4628ed
// 004628e1  83c604               add esi, 4
// 004628e4  b901000000           mov ecx, 1
// 004628e9  f00fc10e             lock xadd dword ptr [esi], ecx
// 004628ed  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004628f1  894a08               mov dword ptr [edx + 8], ecx
// 004628f4  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004628f8  894a0c               mov dword ptr [edx + 0xc], ecx
// 004628fb  8b542430             mov edx, dword ptr [esp + 0x30]
// 004628ff  85d2                 test edx, edx
// 00462901  740c                 je 0x46290f
// 00462903  83c204               add edx, 4
// 00462906  b901000000           mov ecx, 1
// 0046290b  f00fc10a             lock xadd dword ptr [edx], ecx
// 0046290f  8b542420             mov edx, dword ptr [esp + 0x20]
// 00462913  52                   push edx
// 00462914  57                   push edi
// 00462915  8bc8                 mov ecx, eax
// 00462917  e8b4f9ffff           call 0x4622d0
// 0046291c  8bf0                 mov esi, eax
// 0046291e  eb02                 jmp 0x462922
// 00462920  33f6                 xor esi, esi
// 00462922  8d442410             lea eax, [esp + 0x10]
// 00462926  50                   push eax
// 00462927  8d4f04               lea ecx, [edi + 4]
// 0046292a  89742414             mov dword ptr [esp + 0x14], esi
// 0046292e  e88d250000           call 0x464ec0
// 00462933  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00462936  56                   push esi
// 00462937  e80408fdff           call 0x433140
// 0046293c  8d4c2414             lea ecx, [esp + 0x14]
// 00462940  e8bbb0fbff           call 0x41da00
// 00462945  5f                   pop edi
// 00462946  5e                   pop esi
// 00462947  59                   pop ecx
// 00462948  c21400               ret 0x14

#include <intrin.h>

namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    long use_count_;
    long weak_count_;
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_) _InterlockedIncrement(&pi_->use_count_); }
    ~shared_count();
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
}

namespace RBX {
class Instance;

struct Event {
    boost::shared_ptr<Instance> a;
    boost::shared_ptr<Instance> b;
    ~Event();
};

struct Queue {
    void push(void* const& item);
};

struct Item;
struct Signal {
    void post(Item* item);
};

class MarshaledListener;

struct Item {
    char data[0x20];
    Item(MarshaledListener* owner, int tag, Event e);
};

class MarshaledListener {
public:
    virtual void onEvent(int tag, Event e) throw();
    Queue queue;
    char pad[0x18 - 4 - sizeof(Queue)];
    Signal* signal;
};

void MarshaledListener::onEvent(int tag, Event e) throw()
{
    Item* item = new Item(this, tag, e);
    queue.push(item);
    signal->post(item);
}
}
