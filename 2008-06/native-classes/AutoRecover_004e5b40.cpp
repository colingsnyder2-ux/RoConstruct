// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: G3D::_WeakPtr is an empty polymorphic base (only a vptr) with an
// inline virtual destructor. The original is the compiler-generated
// deleting destructor: it sets the vptr, calls operator delete(this) when
// bit 0 of the flag is set, and returns this. There is no array loop, so only
// bit 0 is tested.
namespace G3D {
class _WeakPtr {
public:
    virtual ~_WeakPtr() {}
};
}

// INFERRED: a compiler-generated ??_E cannot be written directly, so the same
// body is spelled out by hand. Calling the destructor explicitly inlines the
// vptr store.
extern "C" void* __fastcall fn_004e5b40(G3D::_WeakPtr* self, int unusedEdx, unsigned int flags)
{
    self->G3D::_WeakPtr::~_WeakPtr();
    if (flags & 1)
        ::operator delete((void*)self);
    return self;
}
