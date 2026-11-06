// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /U_RELEASEASSERT /I{headers}/../../../work/native-candidates/standardout-lifetime-20261106/profile /I{headers}/std-noinline-string
#include "util/standardout.h"
namespace RBX {
boost::shared_ptr<StandardOut> StandardOut::singleton() {
    static boost::shared_ptr<StandardOut> standardOut(new StandardOut());
    return standardOut;
}
StandardOut::StandardOut() {}
}
typedef char NativeStandardOutSize[sizeof(RBX::StandardOut) == 0x30 ? 1 : -1];
