#include <stddef.h>
#include "AppLeaves2008/RbxDocTemplates2008.h"
#include "AppLeaves2008/EventHandler2008.h"
#include "AppLeaves2008/RobloxCrashReporter2008.h"

// CIDEDocManager(bool) 00449910: operator new(0x90) for each CRbxDocTemplate, operator new(0x98) for the
// CRbxPlayDocTemplate, whose constructor stores +0x90 = 0 and constructs the CString at +0x94.
struct RbxPlayDocTemplateLayout : CRbxPlayDocTemplate {
    static void check();
};
void RbxPlayDocTemplateLayout::check()
{
    typedef char DocSize[sizeof(CRbxDocTemplate) == 0x90 ? 1 : -1];
    typedef char MultiSize[sizeof(CMultiDocTemplate) == 0x90 ? 1 : -1];
    typedef char PlaySize[sizeof(CRbxPlayDocTemplate) == 0x98 ? 1 : -1];
    typedef char PlayDocument[offsetof(RbxPlayDocTemplateLayout, playDocument) == 0x90 ? 1 : -1];
    typedef char LastError[offsetof(RbxPlayDocTemplateLayout, lastError) == 0x94 ? 1 : -1];
    typedef char Untitled[offsetof(RbxPlayDocTemplateLayout, m_nUntitledCount) == 0x8c ? 1 : -1];
}

// Emits the CRbxDocTemplate / CRbxPlayDocTemplate vtables and deleting destructors from the current headers
// (the constructors are inline in the original, inside 00449910).
CDocTemplate* NativeAppLeaves2008MakeDocTemplate(UINT id, CRuntimeClass* doc, CRuntimeClass* frame, CRuntimeClass* view)
{
    return new CRbxDocTemplate(id, doc, frame, view);
}
CDocTemplate* NativeAppLeaves2008MakePlayDocTemplate(UINT id, CRuntimeClass* doc, CRuntimeClass* frame, CRuntimeClass* view)
{
    return new CRbxPlayDocTemplate(id, doc, frame, view);
}

// EventHandler: operator new(0x30) at 0042c12a before the constructor 0042acb0; handler manager pointer stored at +8
// (functor buffer +0x10) and refCount = 0 at +0x28 by that constructor; AddRef 0042ae10 increments +0x28.
struct EventHandlerLayout : EventHandler {
    static void check();
};
void EventHandlerLayout::check()
{
    typedef char Size[sizeof(EventHandler) == 0x30 ? 1 : -1];
    typedef char Handler[offsetof(EventHandlerLayout, handler) == 0x08 ? 1 : -1];
    typedef char RefCount[offsetof(EventHandlerLayout, refCount) == 0x28 ? 1 : -1];
}

// RobloxCrashReporter: 00428180 news 0x7d0; 00427a20 writes +4 (actionToTake), +8 (appName), +0x88 (appVersion),
// +0x108 (pathToMinidump) and +0x7cc (minidumpType).
struct RobloxCrashReporterLayout : RobloxCrashReporter {
    static void check();
};
void RobloxCrashReporterLayout::check()
{
    typedef char Size[sizeof(RobloxCrashReporter) == 0x7d0 ? 1 : -1];
    typedef char Controls[offsetof(RobloxCrashReporterLayout, controls) == 0x04 ? 1 : -1];
    typedef char AppName[offsetof(RobloxCrashReporterLayout, controls.appName) == 0x08 ? 1 : -1];
    typedef char AppVersion[offsetof(RobloxCrashReporterLayout, controls.appVersion) == 0x88 ? 1 : -1];
    typedef char Path[offsetof(RobloxCrashReporterLayout, controls.pathToMinidump) == 0x108 ? 1 : -1];
    typedef char Type[offsetof(RobloxCrashReporterLayout, controls.minidumpType) == 0x7cc ? 1 : -1];
}
