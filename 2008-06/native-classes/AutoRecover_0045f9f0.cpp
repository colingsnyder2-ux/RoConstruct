// native-flags: /O2 /Oy /Ob2 /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <intrin.h>
#include <windows.h>

// INFERRED: The listing starts in the middle of an instruction, so this is the
// tail of a larger function (the CRobloxWnd/view init path). The real frame
// (esi = this, ebp = &dataModel, ebx = parent instance, a Lock at esp+0x1c) is
// reconstructed with opaque pointers and raw offsets because no headers were given.

extern "C" {
void* __fastcall fn_004530f0(void* serviceProvider, int unusedEdx);          // ServiceProvider::create<RunService>
void* fn_00618a40(void* outSharedPtr, void* partInstance);                   // shared_from<PartInstance>
void* __fastcall fn_004025b0(void* sharedCountDst, int unusedEdx, void* src);// shared_count::operator=
void* fn_00412d50(int a1);                                                   // GlobalSettingsItem<CRenderSettings>::singleton
int __fastcall fn_004492d0(void* self, int unusedEdx, int a1);
int __fastcall fn_0045d850(void* self, int unusedEdx);
int fn_0045b3a0(void);
int __fastcall fn_0045c890(void* self, int unusedEdx);
int __fastcall fn_0045de20(void* self, int unusedEdx);
int __fastcall fn_00458610(void* self, int unusedEdx);
int fn_0045f730(int a1, int a2);
int __fastcall fn_005ca240(void* self, int unusedEdx, int a1);
void __fastcall fn_005cea00(void* userInput, int unusedEdx, void* adorn);    // UserInputBase::init
void __fastcall fn_0055a8f0(void* instance, int unusedEdx, void* parent);    // Instance::setParent
void __fastcall fn_005557c0(void* runService, int unusedEdx, void* runView); // RunService::addRunView
void __fastcall fn_005773c0(void* lock, int unusedEdx);                      // DataModel::Lock::~Lock
}

namespace {
struct CountBase {
    void** vtbl;
    long use;
    long weak;
};

struct SpTmp {
    void* px;
    CountBase* pn;
    ~SpTmp()
    {
        if (pn) {
            if (_InterlockedDecrement(&pn->use) == 0) {
                ((void(__fastcall*)(CountBase*))pn->vtbl[1])(pn);
                if (_InterlockedDecrement(&pn->weak) == 0)
                    ((void(__fastcall*)(CountBase*))pn->vtbl[2])(pn);
            }
        }
    }
};

template <class T> inline T& at(void* base, int off)
{
    return *reinterpret_cast<T*>(static_cast<char*>(base) + off);
}
}

extern "C" void fn_0045f9f0(void* self, void** dataModelRef, void* parentInstance, void* partInstance, void* lockObj)
{
    // INFERRED: parameters stand in for registers/locals live at entry of this fragment.
    void* dm = *dataModelRef;
    void* runService = dm ? fn_004530f0(dm, 0) : 0;

    {
        SpTmp tmp;
        SpTmp* r = (SpTmp*)fn_00618a40(&tmp, runService);
        at<void*>(self, 0x78) = r->px;
        fn_004025b0((char*)self + 0x7c, 0, &r->pn);
    }

    fn_004492d0(fn_00412d50(0), 0, 0);

    if (at<int>(self, 0x5c) == (int)(INT_PTR)parentInstance)
        fn_0045d850(self, 0);
    else
        fn_0045b3a0();

    fn_005cea00(at<void*>(self, 0x84), 0, at<void*>(self, 0xb4));

    void* obj54 = (char*)self + 0x54;
    {
        void** vt = *(void***)obj54;
        ((void(__fastcall*)(void*, int, double))vt[1])(obj54, 0, 0.0);
    }
    fn_0045c890(self, 0);

    dm = *dataModelRef;
    void* p = dm ? (void*)(INT_PTR)fn_0045de20(dm, 0) : 0;
    at<void*>(p, 0x130) = at<void*>(self, 0x84);

    dm = *dataModelRef;
    void* workspace = dm ? (void*)(INT_PTR)fn_00458610(dm, 0) : 0;

    void* o = at<void*>(self, 0xb0);
    int v = ((int(__fastcall*)(void*))(*(void***)o)[7])(o);
    {
        SpTmp tmp2;
        SpTmp* r = (SpTmp*)(INT_PTR)fn_0045f730((int)(INT_PTR)&tmp2, v);
        at<void*>(self, 0x64) = r->px;
        fn_004025b0((char*)self + 0x68, 0, &r->pn);
    }

    {
        std::string name("Render");
        void* inst = at<void*>(self, 0x64);
        void** vt = *(void***)inst;
        std::string tmpName;
        ((void(__fastcall*)(void*, int, std::string*))vt[1])(inst, 0, &tmpName);
    }

    fn_0055a8f0(at<void*>(self, 0x64), 0, workspace);
    fn_005ca240(at<void*>(self, 0x64), 0, at<int>(self, 0x98));
    fn_005557c0(at<void*>(self, 0x78), 0, obj54);
    fn_005773c0(lockObj, 0);

    HWND hwnd = at<HWND>(self, 0x20);
    if (hwnd)
        InvalidateRect(hwnd, 0, TRUE);
}
