// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

namespace G3D { class CoordinateFrame; }

namespace RBX {
template<typename T> class StringConverter;

template<>
class StringConverter<G3D::CoordinateFrame> {
public:
    static bool convertToValue(const std::string& text, G3D::CoordinateFrame& value);
};

// INFERRED: disassembly is `xor al, al; ret`, so the 2008 body always returns false
bool StringConverter<G3D::CoordinateFrame>::convertToValue(const std::string&, G3D::CoordinateFrame&)
{
    return false;
}
}
