// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/g3d-binary-output-2008
#include "G3D/BinaryOutput.h"
#include <exception>

namespace G3D {
void BinaryOutput::setLength(int n) {
    n = n - (int)alreadyWritten;
    // INFERRED: original 0050ab9d constructs std::exception with this message.
    if (n < 0)
        throw std::exception("Cannot resize huge files to be shorter.");
    if (n < bufferLen)
        pos = n;
    if (n > bufferLen)
        reserveBytes(n - bufferLen);
}
}
