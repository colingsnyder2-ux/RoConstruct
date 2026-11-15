// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /U_RELEASE /FImalloc.h /I{headers}/../../../tools/openrbx/Client/Network/raknet30/Source /I{headers}/../../../tools/openrbx/util
// 2008-06 native RSACryptDtor (inactive): RakNet 3.0 big::RSACrypt<8> destructor; 004c0750 is the thunk tail-jumping to reset (004bd860).
#include <string.h>
#include "RSACrypt.h"

template big::RSACrypt<RSA_BIT_SIZE>::~RSACrypt();
