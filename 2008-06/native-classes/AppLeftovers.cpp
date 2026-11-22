// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string /I{headers}/../native-donor-2007
// Inactive native 2008-06 app leftovers: MainLogManager::startCrashReporter, CrashReporter::Start and the
// Studio property-grid content rows' browse() (SoundItem / TextureItem, slot 62 of ContentItem<T>).
// Not here (already defined elsewhere or blocked; see the batch report):
//   * RBX::Visit::write 00416690 (xor eax,eax; ret) is the inline body in native-headers/v8datamodel/Visit.h.
//   * NativeAtlModule::RegisterServer 0044bea0 is CAtlModuleT<CAtlMfcModule>::RegisterServer, emitted by the
//     explicit instantiation in AppLeaves2008RobloxModule.cpp.
//   * DHTMLWindow::doSetCallback 00417b40 needs the CLuaHtmlView / CLuaFunction layouts (+0xfc, +0x14).
//   * ScriptItem::OnInplaceButtonDown 0043e140 needs a CRobloxApp declaration of 0044ae00.
// The donor LogManager.h builds ThreadLogManager's inline constructor from RBX::get_thread_name, which no native
// header declares yet (see the header proposal); declaration only, never called here.
// The bodies below need the donor MainLogManager / LogManager declarations (guid at +0x30, crashReporter at +0x2c,
// LogManager::GetLogPath 00427ba0 returning ATL::CPath on the +4 subobject, RobloxCrashReporter / CrashReporter).
// native-headers/LogManager.h (reached through CRobloxApp.h) does not declare GetLogPath, guid or the reporter
// classes yet, so this unit includes the donor header by path instead of CRobloxApp.h until that header gains them.
namespace RBX { const char* get_thread_name(); }
#include <afxwin.h>
#include "../native-donor-2007/LogManager.h"
#include "PropertyGridItems2008.h"
#include <afxdlgs.h>
#include <fstream>
#include "v8datamodel/DataModel.h"
#include "util/ContentProvider.h"
#include "util/ImageContent.h"

// ---------------------------------------------------------------------------------------------------------------
// 00428180: "log_" (008103d0) + guid trimmed like MainLogManager::getLogPath; the reporter writes its minidumps
// (type 1 == MiniDumpWithDataSegs) to the log directory (LogManager::GetLogPath on the +4 subobject).
void MainLogManager::startCrashReporter()
{
    std::string appName("log_");
    appName += guid;
    appName.erase(12, std::string::npos);
    appName.erase(4, 3);
    crashReporter.reset(new RobloxCrashReporter(GetLogPath(), appName.c_str(), MiniDumpWithDataSegs));
    crashReporter->Start();
}

// ---------------------------------------------------------------------------------------------------------------
// CrashReporter unit (0049e490..0049e50f). The filter and the kernel32 hook are its free functions
// (CrashExceptionFilter 0049e490, PreventSetUnhandledExceptionFilter 0049e4a0).
LONG WINAPI CrashExceptionFilter(_EXCEPTION_POINTERS* ExceptionInfo);
BOOL PreventSetUnhandledExceptionFilter();

// 0049e500. The original is in the CrashReporter unit, not MainLogManager's: 00428180 calls it out of line.
// auto_inline(off) only stands in for that unit boundary while both share this leftovers file (move it to its own
// CrashReporter unit and drop the pragma when that file exists); Start's own bytes do not depend on it.
#pragma auto_inline(off)
void CrashReporter::Start()
{
    SetUnhandledExceptionFilter(CrashExceptionFilter);
    PreventSetUnhandledExceptionFilter();
}
#pragma auto_inline(on)

// ---------------------------------------------------------------------------------------------------------------
// ContentItem<T>::browse overrides. Both open a CFileDialog with a string-table filter, make sure the grid's
// DataModel has its ContentProvider (ServiceProvider::create<ContentProvider> 0041eea0, result unused, the
// InsertDecal pattern), register the file content (0055fbc0) and apply the new id (XItem::applyValue 0043e4c0).

// 00441bc0: filter string 0x86; the stream is a temporary of the registering full expression.
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

// 00441d60: filter string 0x84; mime type from the file name (getMimeType 00437d60).
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

// ---------------------------------------------------------------------------------------------------------------
// 004161b0 ??$any_cast@VContentId@RBX@@@boost@@YA?AVContentId@RBX@@AAVany@0@@Z (registry): boost::any_cast<ContentId>
// (any&) emitted next to the other any_cast<T> instances of the Value / variant unit (00415ed0..00416260; caller
// Value::cast<ContentId> 00416340). typeid compare against ContentId's type_info 0092bf44, bad_any_cast thrown through
// throw_exception 0040a3f0, then the ContentId copy (std::string copy + the word at +0x1c).
#include <boost/any.hpp>
template RBX::ContentId boost::any_cast<RBX::ContentId>(boost::any&);

// ---------------------------------------------------------------------------------------------------------------
// Value::cast<T>() (non-const, reflection/type.h member template: return boost::any_cast<T>(value) on the any at +4).
// 00416310 ??$cast@V?$basic_string@...@std@@@Value@Reflection@RBX@@QAE?AV?$basic_string@...@std@@XZ (caller 00416506)
//   calls any_cast<std::string>(any&) 00416110.
// 00416340 ??$cast@VContentId@RBX@@@Value@Reflection@RBX@@QAE?AVContentId@2@XZ (caller 00416546) calls the
//   any_cast<ContentId>(any&) 004161b0 above.
// Both sit in the same Value / variant run (00415ed0..00416360) as the any_cast<T> instances.
template std::string RBX::Reflection::Value::cast<std::string>();
template RBX::ContentId RBX::Reflection::Value::cast<RBX::ContentId>();
