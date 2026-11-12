// from server: 68% by EspClaude
// from server: 41% by Intel
// roc 2007-08 00491bd0  unit: RBX::Network::VPlayer::?$Listener  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00491bd0
//
// 00491bd0  55                   push ebp
// 00491bd1  8bec                 mov ebp, esp
// 00491bd3  6aff                 push -1
// 00491bd5  68c97b7400           push 0x747bc9
// 00491bda  64a100000000         mov eax, dword ptr fs:[0]
// 00491be0  50                   push eax
// 00491be1  83ec30               sub esp, 0x30
// 00491be4  a188518b00           mov eax, dword ptr [0x8b5188]
// 00491be9  33c5                 xor eax, ebp
// 00491beb  8945ec               mov dword ptr [ebp - 0x14], eax
// 00491bee  53                   push ebx
// 00491bef  56                   push esi
// 00491bf0  57                   push edi
// 00491bf1  50                   push eax
// 00491bf2  8d45f4               lea eax, [ebp - 0xc]
// 00491bf5  64a300000000         mov dword ptr fs:[0], eax
// 00491bfb  8965f0               mov dword ptr [ebp - 0x10], esp
// 00491bfe  8bc1                 mov eax, ecx
// 00491c00  8b5d34               mov ebx, dword ptr [ebp + 0x34]
// 00491c03  33ff                 xor edi, edi
// 00491c05  3bc7                 cmp eax, edi
// 00491c07  897dfc               mov dword ptr [ebp - 4], edi
// 00491c0a  c645fc01             mov byte ptr [ebp - 4], 1
// 00491c0e  7406                 je 0x491c16
// 00491c10  8db818ffffff         lea edi, [eax - 0xe8]
// 00491c16  83ec2c               sub esp, 0x2c
// 00491c19  8bf4                 mov esi, esp
// 00491c1b  8d4508               lea eax, [ebp + 8]
// 00491c1e  8965cc               mov dword ptr [ebp - 0x34], esp
// 00491c21  50                   push eax
// 00491c22  8bce                 mov ecx, esi
// 00491c24  ff159ce67700         call dword ptr [0x77e69c]
// 00491c2a  8b4d24               mov ecx, dword ptr [ebp + 0x24]
// 00491c2d  894e1c               mov dword ptr [esi + 0x1c], ecx
// 00491c30  8b5528               mov edx, dword ptr [ebp + 0x28]
// 00491c33  895620               mov dword ptr [esi + 0x20], edx
// 00491c36  8b4528               mov eax, dword ptr [ebp + 0x28]
// 00491c39  85c0                 test eax, eax
// 00491c3b  740c                 je 0x491c49
// 00491c3d  83c004               add eax, 4
// 00491c40  b901000000           mov ecx, 1
// 00491c45  f00fc108             lock xadd dword ptr [eax], ecx
// 00491c49  8b552c               mov edx, dword ptr [ebp + 0x2c]
// 00491c4c  895624               mov dword ptr [esi + 0x24], edx
// 00491c4f  8b4530               mov eax, dword ptr [ebp + 0x30]
// 00491c52  894628               mov dword ptr [esi + 0x28], eax
// 00491c55  8b4530               mov eax, dword ptr [ebp + 0x30]
// 00491c58  85c0                 test eax, eax
// 00491c5a  740c                 je 0x491c68
// 00491c5c  83c004               add eax, 4
// 00491c5f  b901000000           mov ecx, 1
// 00491c64  f00fc108             lock xadd dword ptr [eax], ecx
// 00491c68  8b13                 mov edx, dword ptr [ebx]
// 00491c6a  8b02                 mov eax, dword ptr [edx]
// 00491c6c  57                   push edi
// 00491c6d  8bcb                 mov ecx, ebx
// 00491c6f  ffd0                 call eax
//
// The target continues past 0x491c71 (EH cleanup, catch funclet at 0x491c9e
// referencing "Exception caught in onEvent. %s" at 0x78ada4, ret 0x30).
// Shape follows matched 2007-08 Notifier::raise (0052cf50): Notifier base at
// Source+0xe8; the event here is 0x2c bytes (std::string + two shared_ptrs,
// copied at esi+0, +0x1c, +0x24; ret 0x30 = 0x2c + listener).

#include <exception>
#include <string>
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

namespace boost {
namespace detail {
struct sp_counted_base {
    virtual void dispose();
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
};
}
template<class T> class shared_ptr {
    T* px;
    detail::sp_counted_base* pn;
public:
    shared_ptr(const shared_ptr& r) : px(r.px), pn(r.pn) { if (pn != 0) pn->add_ref_copy(); }
    ~shared_ptr();
    T* operator->() const { return px; }
};
}
namespace RBX {
enum MessageType { MESSAGE_OUTPUT, MESSAGE_INFO, MESSAGE_WARNING, MESSAGE_ERROR };
class StandardOut {
public:
    static boost::shared_ptr<StandardOut> singleton();
    void print(MessageType type, const char* format, ...);
};
class A; class B;
struct Ev {
    std::string name;
    boost::shared_ptr<A> a;
    boost::shared_ptr<B> b;
    ~Ev();   // 0x4919b0
};
template<class Source, class Event> class Listener {
public:
    virtual void onEvent(const Source* source, Event event) = 0;
};
template<class Source, class Event> class Notifier {
public:
    virtual ~Notifier();
protected:
    void raise(Event event, Listener<Source, Event>* listener) const;
};
template<class Source, class Event>
void Notifier<Source, Event>::raise(Event event, Listener<Source, Event>* listener) const
{
    try {
        listener->onEvent(static_cast<const Source*>(this), event);
    }
    catch (std::exception& error) {
        std::string what(error.what());
        StandardOut::singleton()->print(MESSAGE_WARNING, "Exception caught in onEvent. %s", what.c_str());
    }
}
class SrcPad { public: virtual ~SrcPad(); char pad[0xe8 - 4]; };
class Src : public SrcPad, public Notifier<Src, Ev> {};
template class Notifier<Src, Ev>;
}
