// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string /I{headers}/../native-donor-2007
namespace RBX { const char* get_thread_name(); }
#include "CRobloxApp.h"
#include "PropertyGridItems2008.h"
#include <afxdlgs.h>
#include <fstream>
#include "v8datamodel/DataModel.h"
#include "util/ContentProvider.h"
#include "util/ImageContent.h"

void MainLogManager::startCrashReporter()
{
    std::string appName("log_");
    appName += guid;
    appName.erase(12, std::string::npos);
    appName.erase(4, 3);
    crashReporter.reset(new RobloxCrashReporter(GetLogPath(), appName.c_str(), MiniDumpWithDataSegs));
    crashReporter->Start();
}

LONG WINAPI CrashExceptionFilter(_EXCEPTION_POINTERS* ExceptionInfo);
BOOL PreventSetUnhandledExceptionFilter();

#pragma auto_inline(off)
void CrashReporter::Start()
{
    SetUnhandledExceptionFilter(CrashExceptionFilter);
    PreventSetUnhandledExceptionFilter();
}
#pragma auto_inline(on)


void SoundItem::browse()
{
    CString filter;
    filter.LoadString(0x86);
    CFileDialog dialog(TRUE, NULL, NULL, 0, filter, NULL, 0, TRUE);
    if (dialog.DoModal() == IDOK) {
        if (grid->dataModel)
            RBX::ServiceProvider::create<RBX::ContentProvider>(static_cast<const RBX::ServiceProvider*>(grid->dataModel));
        RBX::Soundscape::SoundId id = RBX::registerImageContent(
            std::ifstream(dialog.GetPathName(), std::ios::in | std::ios::binary),
            RBX::Name::declare("audio/x-wav", -1));
        applyValue(id);
    }
}

void TextureItem::browse()
{
    CString filter;
    filter.LoadString(0x84);
    CFileDialog dialog(TRUE, NULL, NULL, 0, filter, NULL, 0, TRUE);
    if (dialog.DoModal() == IDOK) {
        std::ifstream stream(dialog.GetPathName(), std::ios::in | std::ios::binary);
        if (grid->dataModel)
            RBX::ServiceProvider::create<RBX::ContentProvider>(static_cast<const RBX::ServiceProvider*>(grid->dataModel));
        RBX::TextureId id = RBX::registerImageContent(stream, RBX::getMimeType(dialog.GetPathName()));
        applyValue(id);
    }
}
