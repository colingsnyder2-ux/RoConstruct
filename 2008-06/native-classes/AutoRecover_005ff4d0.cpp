// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: The target is a compiler-generated adjustor thunk
// (sub ecx,0x14 ; jmp Mouse::`vector deleting destructor').
// Plain C++ cannot define such a thunk directly. Instead, Mouse is modelled
// with a primary base and a secondary polymorphic base at offset 20, and the
// compiler emits the thunk when it builds Mouse's vtable.
// No headers were available, so the base classes below are guesses.

namespace RBX {

// INFERRED: primary base, 20 bytes (vptr + 16 bytes of data).
class MousePrimaryBase {
public:
    int pad[4];
    virtual ~MousePrimaryBase() {}
    virtual void primaryFn() {}
};

// INFERRED: secondary base with a virtual destructor, placed at offset 20.
class MouseSecondaryBase {
public:
    virtual ~MouseSecondaryBase() {}
    virtual void secondaryFn() {}
};

class Mouse : public MousePrimaryBase, public MouseSecondaryBase {
public:
    int state;
    Mouse() : state(0) {}
    virtual ~Mouse() {}
};

} // namespace RBX

// Forces the Mouse vtable to be emitted, and with it the
// secondary-base deleting-destructor thunk.
RBX::Mouse* rbx_mouse_vtable_anchor()
{
    return new RBX::Mouse();
}
