#pragma once
// >>> native-status (generated) -- do not edit >>>
// DHTMLWindow2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 78de3abd | roc native-status --write
// Inactive native 2008-06 recovery: DHTMLWindow, the scriptable HTML window of the DHTMLWindowService translation
// unit (00416e60..0041d300, dynamic initializers 007eed70..007eef20, atexit 007fa620..007fa760).
// Non-colliding name: no donor header declares this class.
#include "AppLeaves2008/DHTMLWindowService2008.h"   // first: MFC/ATL before windows.h; Marshaller, htmlMarshaller
#include "script/ThreadRef.h"                       // RBX::Lua::FunctionRef (SetCallback argument, 0x24 bytes)
#include <boost/function.hpp>
#include <boost/thread/recursive_mutex.hpp>

// The browser view the window drives. Opaque here: its class (CHtmlView-based, with the Binder) is recovered by
// another family; the bodies that use its members are built only with NATIVE_DHTMLWINDOW_PENDING.
class CLuaHtmlView;

// Class name "HtmlWindow": a non-const char array in .data at 0092c204, next to "HtmlService" (0092c1f8);
// classDescriptor 0041b8a0 pushes it.
extern char sDHTMLWindow[];

// DHTMLWindow: no vtable / complete object locator exists in the image (no constructor survives), only its type
// descriptor 0092c210 (.?AVDHTMLWindow@@, used by every dynamic_cast below). The base is fixed by the members the
// unit does have:
//   * Described<DHTMLWindow, sDHTMLWindow, ...>::classDescriptor 0041b8a0 builds ClassDescriptor 0096cf00 from
//     Described<Instance>::classDescriptor 0040ad80 and the name 0092c204 (atexit 007fa620);
//   * FuncDesc<DHTMLWindow> / SignalDesc<DHTMLWindow, void(std::string)> RTTI and the reflected members below;
//   * the members start right after Instance (sizeof 0x130): every bound worker locks the recursive_mutex at
//     +0x130 (do_lock 00563090 / do_unlock 005630e0 on esi + 0x130) and reads the view pointer at +0x13c.
// No creator, so DescribedNonCreatable (the non-creatable Roblox pattern; the bytes do not distinguish it from a
// plain Described<..., Instance>). sizeof is not provable (never allocated in the image).
class DHTMLWindow : public RBX::DescribedNonCreatable<DHTMLWindow, RBX::Instance, sDHTMLWindow>
{
public:
    // Reflected functions (BoundFuncDesc<DHTMLWindow, ...> statics, security NeedTrustedCaller (push 0)). Each one
    // posts a boost::bind of its worker with shared_from(this) to htmlMarshaller (Marshaller::post 0041a530).
    void navigate(std::string url);                       // 0041cc00 "Navigate"("url" = "about:blank"), 0096cc50
    void setBody(std::string html);                       // 0041ccd0 "SetBody"("html"), 0096cc98
    void setCallback(RBX::Lua::FunctionRef function);     // 0041cb30 "SetCallback"("function"), 0096cce0
    void resize(int x, int y);                            // 0041cac0 "Resize"("x", "y"), 0096cd28
    void show();                                          // 0041b2b0 "Show", 0096cd78 (only if showAllowed)
    void close();                                         // 00416e90 "Close", 0096cdb8: setParent(NULL)
    // 0041d0a0 "Bind"("object", "property", "htmlElementId"), 0096cdf8: throws runtime_error 0080f058 for a nil
    // object and "Instance does not have property %s" (0080f034) for an unknown property name.
    void bind(boost::shared_ptr<RBX::Instance> object, std::string property, std::string htmlElementId);
#ifdef NATIVE_DHTMLWINDOW_PENDING
    void unbind();                                        // 0041b660 "Unbind", 0096ce50 (binds &CLuaHtmlView::X)
#endif

    // 0096cc49: tested by show 0041b2b0; CMainFrame 00432331 stores the registry value
    // "OverrideLockViewGamelayout" == 1 here (and into 0096d139 / 00976cad). Name provisional.
    static bool showAllowed;

private:
    // Workers, run on the UI thread by the Marshaller (bind_t RTTI names give their signatures): each takes the
    // view lock and does nothing when the view pointer is null. Their bodies need CLuaHtmlView (pending).
    void doShow();                                        // 00417a10 GetParentFrame()->CenterWindow(0); ->ShowWindow(5)
    void doResize(int x, int y);                          // 00417aa0 GetParentFrame()->SetWindowPos(0, 0, 0, x, y, 6)
    void doSetCallback(RBX::Lua::FunctionRef function);   // 00417b40
    void doNavigate(std::string url);                     // 00417bd0 CHtmlView::Navigate(url.c_str(), 0, 0, 0, 0, 0)
    void doSetBody(std::string html);                     // 00417c70
    void doBind(boost::shared_ptr<RBX::Instance> object, const RBX::Reflection::PropertyDescriptor& property,
                std::string htmlElementId);               // 00417d10
    void doWithView(boost::function1<void, CLuaHtmlView*> function);   // 004185c0 function(view)

    friend struct DHTMLWindowLayout;                      // tests/NativeAppLeaves2008DHTMLLayout.cpp offset probes
    boost::recursive_mutex viewLock;                      // +0x130 (0xc bytes)
    CLuaHtmlView* view;                                   // +0x13c
};
