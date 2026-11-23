// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: minimal local declaration of G3D::Win32Window. No header was
// provided, so only the virtual destructor is declared. This gives the
// mangled name ??1Win32Window@G3D@@UAE@XZ.
namespace G3D {
class Win32Window {
public:
    virtual ~Win32Window();
};
}

// INFERRED: scalar deleting destructor. It calls the base destructor
// non-virtually, then deletes the object if bit 0 of flags is set.
extern "C" G3D::Win32Window* __fastcall fn_00483240(G3D::Win32Window* self, int unusedEdx, unsigned int flags)
{
    self->G3D::Win32Window::~Win32Window();
    if (flags & 1) {
        ::operator delete(static_cast<void*>(self));
    }
    return self;
}
