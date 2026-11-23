// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "CRobloxView.h"
#include "v8datamodel/DataModel.h"

extern "C" int __fastcall fn_0057a6c0(void* self, int unusedEdx, int a1);
// INFERRED: RunService::runViewValid(IRunView*) at 005555e0, declared via fn_ naming to avoid a missing header.
extern "C" void __fastcall fn_005555e0(void* self, int unusedEdx, void* view);

// INFERRED: opaque StandardOut; singleton() at 00569620 (cdecl, hidden return slot), print at 00416e10.
struct StandardOutOpaque;
extern "C" boost::shared_ptr<StandardOutOpaque>* fn_00569620(boost::shared_ptr<StandardOutOpaque>* out);
extern "C" void __fastcall fn_00416e10(StandardOutOpaque* self, int unusedEdx, int type, const std::exception& e);

// INFERRED: slot_b0 is an object whose vtable +4 takes the RenderDevice and +0x1c returns the Stopwatch.
struct RunRenderer_b0 {
    virtual void v0();
    virtual void v1(G3D::RenderDevice*);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual G3D::Stopwatch* getStopwatch0();
    virtual G3D::Stopwatch* getStopwatch();
};

void CRobloxWnd::run(bool render2d)
{
    renderDevice->pushState();
    try {
        boost::shared_ptr<RBX::DataModel> dm = dataModelPtr;
        RBX::DataModel::Lock lock(dm);
        RunRenderer_b0* r = static_cast<RunRenderer_b0*>(slot_b0);
        r->v1(renderDevice);
        G3D::Stopwatch* sw = r->getStopwatch();
        sw->tick();
        fn_0057a6c0(dataModelPtr.get(), 0, (int)slot_b4);
        if (render2d) {
            renderDevice->push2D();
            dataModelPtr->renderPass2d((RBX::Adorn*)slot_b4, static_cast<RBX::IMetric*>(this));
            renderDevice->popState();
        }
        sw->tock();
    } catch (std::exception& e) {
        boost::shared_ptr<StandardOutOpaque> so;
        fn_00569620(&so);
        fn_00416e10(so.get(), 0, 3, e);
    }
    if (slot_78)
        fn_005555e0(slot_78, 0, static_cast<RBX::IRunView*>(this));
    renderDevice->popState();
}
