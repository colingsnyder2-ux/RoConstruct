// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no Hat header is available. The target is the compiler-generated
// `vector deleting destructor'`adjustor{16}' thunk (sub ecx,0x10 ; jmp real
// vector-deleting-dtor). It is emitted when Hat has a virtual destructor and a
// secondary polymorphic base at offset 16. The layout below is a local
// reconstruction that makes the compiler generate that thunk.

namespace RBX {

// INFERRED: primary polymorphic base, 16 bytes (vptr + 12 bytes of data)
class HatPrimaryBase {
public:
    HatPrimaryBase();
    virtual ~HatPrimaryBase();
    int pad[3];
};

// INFERRED: secondary polymorphic base placed at offset 16 inside Hat
class HatSecondaryBase {
public:
    HatSecondaryBase();
    virtual ~HatSecondaryBase();
};

class Hat : public HatPrimaryBase, public HatSecondaryBase {
public:
    Hat();
    virtual ~Hat();   // INFERRED: defined elsewhere (real Hat destructor)
};

// Out-of-line constructor makes the compiler emit the vtable, which in turn
// emits the destructor adjustor thunk for the secondary base.
Hat::Hat()
{
}

} // namespace RBX
