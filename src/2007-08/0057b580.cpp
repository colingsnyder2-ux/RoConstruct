// from server: 50% by EspClaude
// from server: 43% by colin
// roc 2007-08 0057b580  unit: RBX::RootInstance  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0057b580
//
// 0057b580  55                   push ebp
// 0057b581  8bec                 mov ebp, esp
// 0057b583  6aff                 push -1
// 0057b585  6811567500           push 0x755611
// 0057b58a  64a100000000         mov eax, dword ptr fs:[0]
// 0057b590  50                   push eax
// 0057b591  64892500000000       mov dword ptr fs:[0], esp
// 0057b598  83ec2c               sub esp, 0x2c
// 0057b59b  53                   push ebx
// 0057b59c  56                   push esi
// 0057b59d  33c0                 xor eax, eax
// 0057b59f  3bc8                 cmp ecx, eax
// 0057b5a1  57                   push edi
// 0057b5a2  8965f0               mov dword ptr [ebp - 0x10], esp
// 0057b5a5  8945fc               mov dword ptr [ebp - 4], eax
// 0057b5a8  7406                 je 0x57b5b0
// 0057b5aa  8d8114fdffff         lea eax, [ecx - 0x2ec]
// 0057b5b0  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0057b5b3  8b7508               mov esi, dword ptr [ebp + 8]
// 0057b5b6  8b11                 mov edx, dword ptr [ecx]
// 0057b5b8  56                   push esi
// 0057b5b9  50                   push eax
// 0057b5ba  8b02                 mov eax, dword ptr [edx]
// 0057b5bc  ffd0                 call eax
// 0057b5be  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0057b5c1  5f                   pop edi
// 0057b5c2  5e                   pop esi
// 0057b5c3  64890d00000000       mov dword ptr fs:[0], ecx
// 0057b5ca  5b                   pop ebx
// 0057b5cb  8be5                 mov esp, ebp
// 0057b5cd  5d                   pop ebp
// 0057b5ce  c20800               ret 8
// 0057b5d1  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 0057b5d4  8b11                 mov edx, dword ptr [ecx]
// 0057b5d6  8b4204               mov eax, dword ptr [edx + 4]
// 0057b5d9  ffd0                 call eax
// 0057b5db  50                   push eax
// 0057b5dc  8d4dc8               lea ecx, [ebp - 0x38]
// 0057b5df  ff1598e67700         call dword ptr [0x77e698]
// 0057b5e5  8d4de4               lea ecx, [ebp - 0x1c]
// 0057b5e8  bb02000000           mov ebx, 2
// 0057b5ed  51                   push ecx
// 0057b5ee  885dfc               mov byte ptr [ebp - 4], bl
// 0057b5f1  e8ba0dffff           call 0x56c3b0
// 0057b5f6  83c404               add esp, 4
// 0057b5f9  837de010             cmp dword ptr [ebp - 0x20], 0x10
// 0057b5fd  8b4dcc               mov ecx, dword ptr [ebp - 0x34]
// 0057b600  c645fc03             mov byte ptr [ebp - 4], 3
// 0057b604  7303                 jae 0x57b609
// 0057b606  8d4dcc               lea ecx, [ebp - 0x34]
// 0057b609  8b00                 mov eax, dword ptr [eax]
// 0057b60b  51                   push ecx
// 0057b60c  68a4ad7800           push 0x78ada4
// 0057b611  53                   push ebx
// 0057b612  50                   push eax
// 0057b613  e8880affff           call 0x56c0a0
// 0057b618  83c410               add esp, 0x10
// 0057b61b  8d4de4               lea ecx, [ebp - 0x1c]
// 0057b61e  885dfc               mov byte ptr [ebp - 4], bl
// 0057b621  e83a6df1ff           call 0x492360
// 0057b626  8d4dc8               lea ecx, [ebp - 0x38]
// 0057b629  c645fc01             mov byte ptr [ebp - 4], 1
// 0057b62d  ff15ace67700         call dword ptr [0x77e6ac]
// 0057b633  b8beb55700           mov eax, 0x57b5be
// 0057b638  c3                   ret 

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <exception>

namespace boost {
namespace detail { struct shared_count { void* pi_; }; }
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    ~shared_ptr();
    T* operator->() const { return px; }
};
}

namespace RBX {

enum MessageType { MESSAGE_OUTPUT, MESSAGE_INFO, MESSAGE_WARNING, MESSAGE_ERROR };

class StandardOut {
public:
    static boost::shared_ptr<StandardOut> singleton();
    void __cdecl print(MessageType type, const char* format, ...);
};

template<typename Class, typename Event> class Notifier;

template<typename Class, typename Event>
class __declspec(novtable) Listener
{
    friend class Notifier<Class, Event>;
protected:
    virtual void onEvent(const Class*, Event) = 0;
    virtual ~Listener() {}
};

template<typename Class, typename Event>
class __declspec(novtable) Notifier
{
protected:
    virtual ~Notifier() {}
public:
    void raise(Event event, Listener<Class, Event>* listener) const
    {
        try
        {
            listener->onEvent((Class*)this, event);
        }
        catch (std::exception& exp)
        {
            std::string what = exp.what();
            StandardOut::singleton()->print(MESSAGE_WARNING, "Exception caught in onEvent. %s", what.c_str());
        }
    }
};

struct RootInstanceEvent { int value; };

class RootInstanceBase {
public:
    virtual ~RootInstanceBase();
    char data[0x2ec - 4];
};

class RootInstance : public RootInstanceBase, public Notifier<RootInstance, RootInstanceEvent> {
};

template class Notifier<RootInstance, RootInstanceEvent>;
}
