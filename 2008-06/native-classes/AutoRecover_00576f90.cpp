// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "G3D/Array.h"
#include "G3D/Vector4.h"

namespace G3D {

// INFERRED: header path "G3D/Array.h" and resize(n, shrinkIfNecessary=true) as func_0048a7c0.
template<>
Array<Vector4>& Array<Vector4>::operator=(const Array<Vector4>& other) {
    resize(other.num, true);
    for (int i = 0; i < num; ++i) {
        data[i] = other.data[i];
    }
    return *this;
}

}
