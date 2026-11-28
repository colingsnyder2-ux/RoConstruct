// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/openrbx/Client/fmod/api/inc
#include <string.h>
#include <boost/shared_ptr.hpp>
#include "v8datamodel/DebugSettings.h"
#include "v8tree/Instance.h"
#include "util/Object.h"
#include "util/StandardOut.h"

#include <fmod.h>
#include <fmod_errors.h>   // static FMOD_ErrorString: the original passes errcode in eax (file-local copy)

// INFERRED: this is the ERRCHECK(FMOD_RESULT) helper from the FMOD vendor code.
// INFERRED: the settings class is DebugSettings. Its flag byte at +0x133 is read by raw offset.
extern "C" void fn_005b87a0(FMOD_RESULT result)
{
    if (result != FMOD_OK)
    {
        char* settings = reinterpret_cast<char*>(&RBX::DebugSettings::singleton());
        if (settings[0x133])
        {
            char buf[512];
            strncpy(buf, FMOD_ErrorString(result), 512);
            RBX::StandardOut::singleton()->print(RBX::MESSAGE_WARNING, "FMOD %d: %s", result, buf);
        }
    }
}
