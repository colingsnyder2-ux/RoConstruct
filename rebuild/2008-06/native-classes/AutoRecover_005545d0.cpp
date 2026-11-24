// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <exception>
#include <string>

// INFERRED: the third stack argument is an object whose first vtable slot is a
// __thiscall function taking (adjusted this, arg1, arg2).
struct VisitorIface {
    virtual void Visit(void* adjustedThis, int arg1, int arg2) = 0;
};

struct Derived150;

namespace RBX {
    class StandardOut;

    // INFERRED: smart pointer returned by value (8 bytes) with out-of-line dtor
    struct StandardOutPtr {
        StandardOut* p;
        void* cnt;
        ~StandardOutPtr();
        StandardOut* operator->() const { return p; }
    };

    // INFERRED: logging singleton with a variadic (cdecl) print member
    class StandardOut {
    public:
        static StandardOutPtr singleton();
        void print(int type, int flags, const char* fmt, ...);
    };
}

extern "C" void __fastcall fn_005545d0(Derived150* self, int unusedEdx, int arg1, int arg2, VisitorIface* visitor)
{
    try {
        void* adjusted = 0;
        if (self)
            adjusted = reinterpret_cast<char*>(self) - 0x150;
        visitor->Visit(adjusted, arg1, arg2);
    }
    catch (std::exception& e) {
        std::string s(e.what());
        RBX::StandardOut::singleton()->print(2, 0, s.c_str());
    }
}
