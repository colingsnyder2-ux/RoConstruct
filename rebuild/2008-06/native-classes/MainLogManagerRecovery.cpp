// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/std-noinline-string /I{headers}/../../../tools/rbxgs/Client/App/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/include /I{headers}/../../../tools/rbxgs/Client/boost_1_34_1/src /I{headers}
#include <afxwin.h>
namespace RBX { const char* get_thread_name(); }
#include "../native-donor-2007/LogManager.h"
#include <G3D/Log.h>
// The donor header names the +4 subobject's slot 1 getLogFileName; the 2008 native header (MainLogPath.cpp, exact 00427f30)
// calls it getLogPath. Same signature and slot, so the donor-named reference resolves to the native definition.
#pragma comment(linker, "/alternatename:?getLogFileName@MainLogManager@@UAE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ=?getLogPath@MainLogManager@@UAE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ")
std::string MoveRelative(const char*, std::string);
extern MainLogManager* mainLogManager;   // the exe global (MainLogManagerState.cpp), not the donor header's LogManager::mainLogManager static

MainLogManager::~MainLogManager()
{
    if (G3D::Log::common()) {
        std::string path = G3D::Log::getCommonLogFilename();
        delete G3D::Log::common();
        if (RBX::Log::aggregateWorstSeverity == RBX::Log::Error)
            MoveRelative(path.c_str(), "error\\");
        else
            MoveRelative(path.c_str(), "archive\\");
    }
    ::mainLogManager = 0;
}

#include "util/Guid.h"
#include <G3D/debugAssert.h>
void __cdecl purecallHandler();

MainLogManager::MainLogManager(const char* productName) : LogManager(productName)
{
    RBX::Guid::generateGUID(guid);
    CullLogs("\\", 32);
    CullLogs("error\\", 32);
    CullLogs("archive\\", 32);

    std::string path = getLogFileName();
    path.erase(path.size() - 4);
    path += "_G3D.txt";
    new G3D::Log(path);

    ::mainLogManager = this;
    RBX::Log::setLogProvider(this);
    G3D::setAssertionHook(handleDebugAssert);
    G3D::setFailureHook(handleG3DFailure);
    _set_purecall_handler(purecallHandler);
}
