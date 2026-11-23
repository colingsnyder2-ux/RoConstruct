// =============================================================================
// CrashReporter.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/network/CrashReporter.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

namespace RBX { const char* get_thread_name(); }
#include <afxwin.h>
#include "../../../native-donor-2007/LogManager.h"
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

#include <boost/any.hpp>
template RBX::ContentId boost::any_cast<RBX::ContentId>(boost::any&);

template std::string RBX::Reflection::Value::cast<std::string>();
template RBX::ContentId RBX::Reflection::Value::cast<RBX::ContentId>();
