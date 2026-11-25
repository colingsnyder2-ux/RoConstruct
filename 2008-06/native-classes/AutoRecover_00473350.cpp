// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

namespace G3D {

class GImage {
public:
    class Error {
    public:
        std::string reason;
        std::string filename;
        // INFERRED: the frame layout puts the Error object at 0x58 bytes, so it is padded.
        char        pad_[0x20];
        Error(const std::string& reason, const std::string& filename);
    };
};

} // namespace G3D

// INFERRED: vendor G3D::Texture::splitFilenameAtWildCard (static), emitted under the fixed name.
extern "C" void fn_00473350(
    const std::string&  filename,
    std::string&        filenameBeforeWildCard,
    std::string&        filenameAfterWildCard) {

    const std::string DELIMITER = "*";

    int i = (int)filename.rfind(DELIMITER);
    if (i != -1) {
        filenameBeforeWildCard = filename.substr(0, i);
        filenameAfterWildCard  = filename.substr(i + 1, filename.size() - i - DELIMITER.size());
    } else {
        throw G3D::GImage::Error("Cube map filenames must contain \"*\" as a placeholder for up/lf/rt/bk/ft/dn", filename);
    }
}
