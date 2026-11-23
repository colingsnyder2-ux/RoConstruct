// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the target is the default constructor of G3D::Array<const void*>.
// No header excerpt was available, so a minimal local declaration of the class is
// used. It only exists to produce the mangled name of the private init(int,int)
// callee, ?init@?$Array@PBX@G3D@@AAEXHH@Z. The real member layout is unknown and
// not needed here.
namespace G3D {

template <class T>
class Array {
public:
    Array* construct_() {
        init(0, 0);
        return this;
    }

private:
    void init(int numElements, int maxElements);
};

}

extern "C" G3D::Array<const void*>* __fastcall fn_005527f0(G3D::Array<const void*>* self, int unusedEdx)
{
    return self->construct_();
}
