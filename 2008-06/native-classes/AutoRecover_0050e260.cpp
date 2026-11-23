// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no GImage header was provided, so GImage is forward-declared and the
// private GImage::_copy is reached through the fn_0050e1b0 extern.
// INFERRED: the target looks like GImage::operator=(const GImage&), i.e. { _copy(other); return *this; }.
namespace G3D {
class GImage;
}

// ?_copy@GImage@G3D@@AAEXABV12@@Z
extern "C" void __fastcall fn_0050e1b0(G3D::GImage* self, int unusedEdx, const G3D::GImage& other);

extern "C" G3D::GImage* __fastcall fn_0050e260(G3D::GImage* self, int unusedEdx, const G3D::GImage& other)
{
    fn_0050e1b0(self, 0, other);
    return self;
}
