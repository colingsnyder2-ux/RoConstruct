// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS /arch:SSE2 /fp:fast /I{headers}/g3d-image-2008
#include <string>
#include "G3D/GImage.h"

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
