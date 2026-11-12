// from server: 100% by EspClaude
// from server: 40% by colin
// roc 2007-08 00437c30  unit: RBX::VStandardOut::?$MarshaledListener  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00437c30
//
// 00437c30  6aff                 push -1
// 00437c32  68eee47300           push 0x73e4ee
// 00437c37  64a100000000         mov eax, dword ptr fs:[0]
// 00437c3d  50                   push eax
// 00437c3e  51                   push ecx
// 00437c3f  56                   push esi
// 00437c40  57                   push edi
// 00437c41  a188518b00           mov eax, dword ptr [0x8b5188]
// 00437c46  33c4                 xor eax, esp
// 00437c48  50                   push eax
// 00437c49  8d442410             lea eax, [esp + 0x10]
// 00437c4d  64a300000000         mov dword ptr fs:[0], eax
// 00437c53  8bf1                 mov esi, ecx
// 00437c55  8974240c             mov dword ptr [esp + 0xc], esi
// 00437c59  c70610ce7800         mov dword ptr [esi], 0x78ce10
// 00437c5f  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00437c62  85c9                 test ecx, ecx
// 00437c64  c744241802000000     mov dword ptr [esp + 0x18], 2
// 00437c6c  7406                 je 0x437c74
// 00437c6e  56                   push esi
// 00437c6f  e80cffffff           call 0x437b80
// 00437c74  8d4e14               lea ecx, [esi + 0x14]
// 00437c77  c644241801           mov byte ptr [esp + 0x18], 1
// 00437c7c  ff15ace67700         call dword ptr [0x77e6ac]
// 00437c82  8b7e08               mov edi, dword ptr [esi + 8]
// 00437c85  85ff                 test edi, edi
// 00437c87  c644241800           mov byte ptr [esp + 0x18], 0
// 00437c8c  742a                 je 0x437cb8
// 00437c8e  8d4704               lea eax, [edi + 4]
// 00437c91  83c9ff               or ecx, 0xffffffff
// 00437c94  f00fc108             lock xadd dword ptr [eax], ecx
// 00437c98  751e                 jne 0x437cb8
// 00437c9a  8b17                 mov edx, dword ptr [edi]
// 00437c9c  8b4204               mov eax, dword ptr [edx + 4]
// 00437c9f  8bcf                 mov ecx, edi
// 00437ca1  ffd0                 call eax
// 00437ca3  8d4f08               lea ecx, [edi + 8]
// 00437ca6  83caff               or edx, 0xffffffff
// 00437ca9  f00fc111             lock xadd dword ptr [ecx], edx
// 00437cad  7509                 jne 0x437cb8
// 00437caf  8b07                 mov eax, dword ptr [edi]
// 00437cb1  8b5008               mov edx, dword ptr [eax + 8]
// 00437cb4  8bcf                 mov ecx, edi
// 00437cb6  ffd2                 call edx
// 00437cb8  c706687f7800         mov dword ptr [esi], 0x787f68
// 00437cbe  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00437cc2  64890d00000000       mov dword ptr fs:[0], ecx
// 00437cc9  59                   pop ecx
// 00437cca  5f                   pop edi

#include <string>

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0) destroy();
    }
};

struct shared_count {
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> struct shared_ptr {
    T* px;
    shared_count pn;
};

struct Target;
struct MarshaledListener;

struct Connection {
    void remove(MarshaledListener* l);
};

struct ListenerBase {
    virtual ~ListenerBase() {}
};

struct MarshaledListener : ListenerBase {
    shared_ptr<Target> target;
    Connection* connection;
    int field10;
    std::string text;
    virtual ~MarshaledListener();
};

MarshaledListener::~MarshaledListener()
{
    if (connection)
        connection->remove(this);
}
