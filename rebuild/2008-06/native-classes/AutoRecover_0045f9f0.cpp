// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: 0x45f9f0 is a mid-function fragment (the first bytes are a misdecoded tail).
// This is a best-effort analog of the tail of a doc/view initializer. The frame
// (ebp = ServiceProvider* slot, esi = this) is taken from the disassembly.
#include <string>

namespace RBX {
    class Instance;
    class RunService;
    class ServiceProvider;
    class Adorn;
    class UserInputBase;
    class IRunView;
    class CRenderSettings;
}

// INFERRED: Win32 declarations written locally to avoid pulling in windows.h
struct HWND__;
typedef HWND__* HWND;
typedef int BOOL;
typedef struct tagRECT RECT;
extern "C" __declspec(dllimport) BOOL __stdcall InvalidateRect(HWND hWnd, const RECT* lpRect, BOOL bErase);

// INFERRED: shared_ptr-like pair {px, pn}
struct SharedPtrRaw { void* px; void* pn; };

extern RBX::RunService* createRunService_004530f0(RBX::ServiceProvider* sp);
extern SharedPtrRaw* sharedFromRunService_00618a40(SharedPtrRaw* out, RBX::RunService* rs);
extern void sharedCountAssign_004025b0(void* dst, void* src);
extern RBX::CRenderSettings* renderSettingsSingleton_00412d50(int create);
extern void renderSettingsInit_004492d0(RBX::CRenderSettings* rs);
extern void initViewA_0045d850(void* self);
extern void initViewB_0045b3a0(void* self);
extern void userInputInit_005cea00(void* userInput, RBX::Adorn* adorn);
extern void* getWorkspaceLike_0045de20(RBX::ServiceProvider* sp);
extern RBX::Instance* getInstanceFor_00458610(RBX::ServiceProvider* sp);
extern void makeInstance_0045f730(SharedPtrRaw* out, void* arg);
extern void instanceSetParent_0055a8f0(void* inst, RBX::Instance* parent);
extern void instanceAttach_005ca240(void* inst, void* arg);
extern void runServiceAddRunView_005557c0(void* runService, void* runView);
extern void dataModelLockDtor_005773c0(void* lock);
extern void initMisc_0045c890(void* self);

struct DocFragmentThis {
    char pad0[0x20];
    void* hwnd;            // +0x20
    char pad1[0x54 - 0x24];
    void* runView;         // +0x54 (IRunView subobject, vtable slot 1 takes double)
    char pad2[0x5c - 0x58];
    int mode;              // +0x5c
    char pad3[0x64 - 0x60];
    void* renderInst_px;   // +0x64
    void* renderInst_pn;   // +0x68
    char pad4[0x78 - 0x6c];
    void* runService_px;   // +0x78
    void* runService_pn;   // +0x7c
    char pad5[0x84 - 0x80];
    void* userInput;       // +0x84
    char pad6[0x98 - 0x88];
    void* attachArg;       // +0x98
    char pad7[0xb0 - 0x9c];
    void* nameSource;      // +0xb0
    RBX::Adorn* adorn;     // +0xb4
};

void docInitTail_0045f9f0(DocFragmentThis* self, RBX::ServiceProvider* sp, char* lock)
{
    SharedPtrRaw tmp;
    RBX::RunService* rs = sp ? createRunService_004530f0(sp) : 0;
    SharedPtrRaw* p = sharedFromRunService_00618a40(&tmp, rs);
    self->runService_px = p->px;
    sharedCountAssign_004025b0(&self->runService_pn, &p->pn);

    renderSettingsInit_004492d0(renderSettingsSingleton_00412d50(0));

    if (self->mode == 0)
        initViewA_0045d850(self);
    else
        initViewB_0045b3a0(self);

    userInputInit_005cea00(self->userInput, self->adorn);

    // runView->vtbl[1](0.0)
    typedef void (__thiscall *SetTimeFn)(void*, double);
    void** vt = *(void***)&self->runView;
    ((SetTimeFn)vt[1])(&self->runView, 0.0);

    initMisc_0045c890(self);

    char* ws = sp ? (char*)getWorkspaceLike_0045de20(sp) : 0;
    *(void**)(ws + 0x130) = self->userInput;

    RBX::Instance* parent = sp ? getInstanceFor_00458610(sp) : 0;

    typedef void* (__thiscall *GetFn)(void*);
    void** nvt = *(void***)self->nameSource;
    void* arg = ((GetFn)nvt[7])(self->nameSource);
    SharedPtrRaw* q = &tmp;
    makeInstance_0045f730(q, arg);
    self->renderInst_px = q->px;
    sharedCountAssign_004025b0(&self->renderInst_pn, &q->pn);

    std::string name("Render");
    typedef void (__thiscall *SetNameFn)(void*, std::string*);
    void** ivt = *(void***)self->renderInst_px;
    ((SetNameFn)ivt[1])(self->renderInst_px, &name);

    instanceSetParent_0055a8f0(self->renderInst_px, parent);
    instanceAttach_005ca240(self->renderInst_px, self->attachArg);
    runServiceAddRunView_005557c0(self->runService_px, &self->runView);

    dataModelLockDtor_005773c0(lock);

    if (self->hwnd)
        InvalidateRect((HWND)self->hwnd, 0, 1);
}
