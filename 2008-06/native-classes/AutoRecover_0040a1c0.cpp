// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <exception>
#include <string>
#include <boost/shared_ptr.hpp>

namespace RBX {
// INFERRED: minimal local declaration; matches mangled names in the disassembly comments
class StandardOut {
public:
    enum MessageType { MESSAGE_OUTPUT, MESSAGE_INFO, MESSAGE_WARNING, MESSAGE_ERROR };
    static boost::shared_ptr<StandardOut> singleton();
    void print(MessageType type, const char* fmt, ...);
};
}

// INFERRED: two-dword by-value argument pair
struct EventArgs {
    int a;
    int b;
};

struct EventTarget;

// INFERRED: arg3 has a vtable whose slot 0 takes (adjusted this, EventArgs by value)
struct EventSlot {
    virtual void invoke(EventTarget* target, EventArgs args) = 0;
};

// INFERRED: this is a secondary base at offset 0xc4 of the owner; null-preserving adjust
extern "C" void __fastcall fn_0040a1c0(char* self, int unusedEdx, int arg1, int arg2, EventSlot* slot)
{
    EventTarget* target = self ? (EventTarget*)(self - 0xc4) : 0;
    EventArgs args;
    args.a = arg1;
    args.b = arg2;
    try {
        slot->invoke(target, args);
    } catch (std::exception& e) {
        std::string msg(e.what());
        boost::shared_ptr<RBX::StandardOut> out = RBX::StandardOut::singleton();
        out->print(RBX::StandardOut::MESSAGE_WARNING, "Exception caught in onEvent. %s", msg.c_str());
    }
}
