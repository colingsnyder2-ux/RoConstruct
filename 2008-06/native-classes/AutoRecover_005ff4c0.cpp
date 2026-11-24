// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no Mouse header was provided, so the class layout is reconstructed here.
// The target is a compiler-generated adjustor thunk: `this -= 16`, then a jump to
// Mouse's vector deleting destructor. The compiler emits it when Mouse has a
// secondary polymorphic base at offset 16 whose virtual destructor Mouse overrides.
namespace RBX {

// INFERRED: primary base occupying the first 16 bytes (vptr + 12 bytes of data).
struct MousePrimaryBase {
    int pad[3];
    virtual ~MousePrimaryBase() {}
};

// INFERRED: secondary polymorphic base at offset 16 (an interface-like base).
struct MouseSecondaryBase {
    virtual ~MouseSecondaryBase() {}
};

class Mouse : public MousePrimaryBase, public MouseSecondaryBase {
public:
    Mouse();
    virtual ~Mouse();
    int state;
};

Mouse::Mouse() : state(0) {}

Mouse::~Mouse() {}

} // namespace RBX
