// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// The target is a compiler-generated adjustor thunk
// ("sub ecx,0x14; jmp `vector deleting destructor'"). It is produced by the
// compiler when the vtable of DescribedCreatable<Tool,BackpackItem,&sTool>
// is emitted and a polymorphic base sits at offset 0x14.

namespace RBX {

class Tool;
class BackpackItem;
extern const char* const sTool;

// INFERRED: primary polymorphic base occupying 0x14 bytes (vptr + 16 bytes).
class DescribedCreatablePrimaryBase
{
public:
    virtual ~DescribedCreatablePrimaryBase();
private:
    char pad_[0x10];
};

// INFERRED: secondary polymorphic base located at offset 0x14 (adjustor{20}).
class DescribedCreatableSecondaryBase
{
public:
    virtual ~DescribedCreatableSecondaryBase();
};

template<class Class, class Base, const char* const* ClassName>
class DescribedCreatable
    : public DescribedCreatablePrimaryBase
    , public DescribedCreatableSecondaryBase
{
public:
    DescribedCreatable();
    virtual ~DescribedCreatable() {}
};

template<class Class, class Base, const char* const* ClassName>
DescribedCreatable<Class, Base, ClassName>::DescribedCreatable()
{
}

// Explicit instantiation emits the vtable and thus the
// `vector deleting destructor'`adjustor{20}' thunk.
template class DescribedCreatable<Tool, BackpackItem, &sTool>;

} // namespace RBX
