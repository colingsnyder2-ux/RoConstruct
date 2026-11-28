// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: minimal local stand-ins for the reflection types; real headers not shown.
namespace RBX {
    class RunService;
    namespace Reflection {
        template<class T, class Sig>
        class SignalDesc {
        public:
            SignalDesc(const char* name, const char* category);
            ~SignalDesc();
            char storage[64];
        };
    }
}

// INFERRED: the event is a static of type SignalDesc<RunService, void(float)>
typedef RBX::Reflection::SignalDesc<RBX::RunService, void(float)> PlayerAddedDesc;

namespace RBX { namespace Reflection {
    template<> SignalDesc<RBX::RunService, void(float)>::SignalDesc(const char*, const char*);
    template<> SignalDesc<RBX::RunService, void(float)>::~SignalDesc();
}}

PlayerAddedDesc event_PlayerAdded("PlayerAdded", "player");
