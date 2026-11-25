// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-import-length /I{headers}/std-noinline-string /I{headers}/../../../tools/rbxgs/Client/App/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/include /I{headers}/../../../tools/rbxgs/Client/boost_1_34_1/src /I{headers}
#include <afxwin.h>
namespace RBX { const char* get_thread_name(); }
#include "../native-donor-2007/LogManager.h"
#include "util/FileSystem.h"
#include <G3D/Log.h>
std::string MoveRelative(const char*, std::string);
extern MainLogManager* mainLogManager;   // the exe global (MainLogManagerState.cpp), not the donor header's LogManager::mainLogManager static

static CString __stdcall logDirectory()
{
    std::string directory = RBX::FileSystem::getUserAppDataDirectory(true, "logs");
    return directory.c_str();
}

std::string MainLogManager::getLogFileName()
{
    CString directory = logDirectory();
    std::string filename("log_");
    filename += guid;
    filename.erase(12, std::string::npos);
    filename.erase(4, 3);
    filename += ".txt";
    const char* text = filename.c_str();
    char* buffer = directory.GetBuffer(CString::StringLength(text) + directory.GetLength() + 1);
    PathAppendA(buffer, text);
    directory.ReleaseBuffer();
    return std::string(static_cast<const char*>(directory));
}

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
