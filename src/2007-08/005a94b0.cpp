// from server: 48% by EspClaude
// from server: 47% by Intel
// roc 2007-08 005a94b0  unit: RBX::VHumanoid::?$SignalDesc  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005a94b0
//
// 005a94b0  55                   push ebp
// 005a94b1  8bec                 mov ebp, esp
// 005a94b3  6aff                 push -1
// 005a94b5  6891857500           push 0x758591
// 005a94ba  64a100000000         mov eax, dword ptr fs:[0]
// 005a94c0  50                   push eax
// 005a94c1  64892500000000       mov dword ptr fs:[0], esp
// 005a94c8  83ec2c               sub esp, 0x2c
// 005a94cb  53                   push ebx
// 005a94cc  56                   push esi
// 005a94cd  33c0                 xor eax, eax
// 005a94cf  3bc8                 cmp ecx, eax
// 005a94d1  57                   push edi
// 005a94d2  8965f0               mov dword ptr [ebp - 0x10], esp
// 005a94d5  8945fc               mov dword ptr [ebp - 4], eax
// 005a94d8  7403                 je 0x5a94dd
// 005a94da  8d41e8               lea eax, [ecx - 0x18]
// 005a94dd  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 005a94e0  8b7508               mov esi, dword ptr [ebp + 8]
// 005a94e3  8b11                 mov edx, dword ptr [ecx]
// 005a94e5  56                   push esi
// 005a94e6  50                   push eax
// 005a94e7  8b02                 mov eax, dword ptr [edx]
// 005a94e9  ffd0                 call eax
// 005a94eb  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005a94ee  5f                   pop edi
// 005a94ef  5e                   pop esi
// 005a94f0  64890d00000000       mov dword ptr fs:[0], ecx
// 005a94f7  5b                   pop ebx
// 005a94f8  8be5                 mov esp, ebp
// 005a94fa  5d                   pop ebp
// 005a94fb  c20800               ret 8
// 005a94fe  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 005a9501  8b11                 mov edx, dword ptr [ecx]
// 005a9503  8b4204               mov eax, dword ptr [edx + 4]
// 005a9506  ffd0                 call eax
// 005a9508  50                   push eax
// 005a9509  8d4dc8               lea ecx, [ebp - 0x38]
// 005a950c  ff1598e67700         call dword ptr [0x77e698]
// 005a9512  8d4de4               lea ecx, [ebp - 0x1c]
// 005a9515  bb02000000           mov ebx, 2
// 005a951a  51                   push ecx
// 005a951b  885dfc               mov byte ptr [ebp - 4], bl
// 005a951e  e88d2efcff           call 0x56c3b0
// 005a9523  83c404               add esp, 4
// 005a9526  837de010             cmp dword ptr [ebp - 0x20], 0x10
// 005a952a  8b4dcc               mov ecx, dword ptr [ebp - 0x34]
// 005a952d  c645fc03             mov byte ptr [ebp - 4], 3
// 005a9531  7303                 jae 0x5a9536
// 005a9533  8d4dcc               lea ecx, [ebp - 0x34]
// 005a9536  8b00                 mov eax, dword ptr [eax]
// 005a9538  51                   push ecx
// 005a9539  68a4ad7800           push 0x78ada4
// 005a953e  53                   push ebx
// 005a953f  50                   push eax
// 005a9540  e85b2bfcff           call 0x56c0a0
// 005a9545  83c410               add esp, 0x10
// 005a9548  8d4de4               lea ecx, [ebp - 0x1c]
// 005a954b  885dfc               mov byte ptr [ebp - 4], bl
// 005a954e  e80d8eeeff           call 0x492360
// 005a9553  8d4dc8               lea ecx, [ebp - 0x38]
// 005a9556  c645fc01             mov byte ptr [ebp - 4], 1
// 005a955a  ff15ace67700         call dword ptr [0x77e6ac]
// 005a9560  b8eb945a00           mov eax, 0x5a94eb
// 005a9565  c3                   ret 
// roc-flags: /O2 /GS- /EHsc /MD

#include <string>
#include <exception>

namespace boost {
namespace detail { struct sp_counted_base; struct shared_count { sp_counted_base* pi_; ~shared_count(); }; }
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    ~shared_ptr();                  // out-of-line: lea ecx,[ebp-0x1c]; call 0x492360
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

class Humanoid;
struct Event;

struct HumanoidSignalHandler {
    virtual void operator()(Humanoid* owner, Event* ev) = 0;   // slot 0, thiscall
};

struct HumanoidHead { virtual ~HumanoidHead() {} int pad[5]; };   // 0x18 bytes incl. vptr: target does lea eax,[ecx-0x18]

struct SignalListener {
    virtual ~SignalListener() {}
    void onEvent(Event* ev, HumanoidSignalHandler* handler);
};

class Humanoid : public HumanoidHead, public SignalListener {};

void SignalListener::onEvent(Event* ev, HumanoidSignalHandler* handler)
{
    try
    {
        (*handler)(static_cast<Humanoid*>(this), ev);
    }
    catch (std::exception& e)
    {
        std::string msg(e.what());
        StandardOut::singleton()->print(MESSAGE_WARNING, "Exception caught in onEvent. %s", msg.c_str());
    }
}
}
