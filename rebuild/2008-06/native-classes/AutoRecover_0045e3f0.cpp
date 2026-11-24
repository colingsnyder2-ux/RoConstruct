// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "CRobloxView.h"
#include "OgreRbx/VisualEngine2008.h"
#include <string>

// INFERRED: the callee helpers below have no recovered headers here, so they use the fn_ naming convention.
extern "C" char* fn_00412d50(void);   // GlobalSettingsItem<CRenderSettings>::singleton
extern "C" void __fastcall fn_00511cf0(void* stopwatch, int unusedEdx);   // G3D::Stopwatch::tick
extern "C" void __fastcall fn_00511df0(void* stopwatch, int unusedEdx);   // G3D::Stopwatch::tock
extern "C" int __fastcall fn_0057a6c0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_0045dce0(void* self, int unusedEdx);
extern "C" std::string fn_0045af20(int csidl);
extern "C" void* fn_0049aca0(void* dataModel);   // Players::findLocalCharacter
extern "C" void __fastcall fn_0045c470(void* instance, int unusedEdx, void (*fn)(void*));   // Instance::for_eachChild
extern "C" void __fastcall fn_0057a1b0(void* dataModel, int unusedEdx, void* adorn, void* metric);   // DataModel::renderPass2d
extern "C" void __fastcall fn_005555e0(void* runService, int unusedEdx, void* runView);   // RunService::runViewValid
extern "C" int __fastcall fn_0071f210(void* bitStream, int unusedEdx);   // BitStream::GetWriteOffset
extern "C" bool __fastcall fn_0045aec0(void* userInput, int unusedEdx);   // UserInputBase::ctrlKeyDown
extern "C" void fn_0045c600(void*);

extern "C" bool g_0096de64;   // INFERRED: global
extern "C" bool g_00962f64;   // INFERRED: global

typedef void* (__fastcall *VFn0)(void* self, int edx);

static inline void** vt(void* p) { return *(void***)p; }

void CRobloxWnd::doRender(int)
{
    char* rs = fn_00412d50();
    if (*(int*)(rs + 0x13c) == 2)
        g_0096de64 = false;

    Ogre::Timer timer;
    void* sw = ((VFn0)vt(slot_b0)[0x1c / 4])(slot_b0, 0);
    char* stopwatch = (char*)sw + 0x108;
    fn_00511cf0(stopwatch, 0);
    timer.reset();

    {
        RBX::DataModel::Lock lock(dataModelPtr);
        void* character = fn_0049aca0(dataModelPtr.get());
        if (!character) {
            g_00962f64 = false;
        } else {
            g_00962f64 = *(int*)(fn_00412d50() + 0x140) != 2;
            fn_0045c470(character, 0, (void (*)(void*))fn_0045c600);
        }

        fn_0057a1b0(dataModelPtr.get(), 0, slot_b4, (RBX::IMetric*)this);
        fn_0057a6c0(dataModelPtr.get(), 0, (int)slot_b4);
        ((void (__fastcall *)(void*, int))vt(slot_b4)[2])(slot_b4, 0);
        ((void (__fastcall *)(void*, int, void*))vt(slot_b0)[1])(slot_b0, 0, visualEngine);
        ((void (__fastcall *)(void*, int))vt(slot_b4)[3])(slot_b4, 0);

        float ms = (float)timer.getMilliseconds();
    }
    fn_00511df0(stopwatch, 0);

    if (g_00962f64 && fn_0071f210((char*)visualEngine + 0x18, 0) != 0) {
        // INFERRED: FrameHistory lives at VisualEngine+0x18; first float of the frame is the render time.
        FrameHistory* fh = (FrameHistory*)((char*)visualEngine + 0x18);
        *(float*)fh->get(0) = ms;
    }
}
