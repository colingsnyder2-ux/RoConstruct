// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "CRobloxView.h"
#include "v8datamodel/DataModel.h"

// INFERRED: the disassembly is truncated at 0045fb25, so everything after the
// 0x64/0x68 shared_ptr assignment is not recovered. Unnamed and cross-class
// callees are declared as fn_ externs below.
extern "C" int __fastcall fn_0045dce0(void* self, int unusedEdx);
extern "C" int fn_006a0920(int a1);
extern "C" int __fastcall fn_004690f0(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_004492d0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_0045d850(void* self, int unusedEdx);
extern "C" int __fastcall fn_0045b3a0(void* self, int unusedEdx);
extern "C" int __fastcall fn_0045c890(void* self, int unusedEdx);
extern "C" int __fastcall fn_0045de20(void* self, int unusedEdx);
extern "C" int __fastcall fn_00458610(void* self, int unusedEdx);
extern "C" boost::shared_ptr<RBX::Instance>* fn_0045f730(boost::shared_ptr<RBX::Instance>* out, int a2);

// INFERRED: named callees without visible headers, called through address-named stubs.
extern "C" void __fastcall fn_0055a8f0(void* self, int unusedEdx, void* parent);       // Instance::setParent
extern "C" void __fastcall fn_00555830(void* self, int unusedEdx, void* runView);      // RunService::removeRunView
extern "C" void* __fastcall fn_004530f0(void* self, int unusedEdx);                    // ServiceProvider::create<RunService>
extern "C" boost::shared_ptr<RBX::Instance>* fn_00618a40(boost::shared_ptr<RBX::Instance>* out, void* p);
extern "C" void* fn_00412d50(int a);                                                   // GlobalSettingsItem<CRenderSettings>::singleton
extern "C" void __fastcall fn_005cea00(void* self, int unusedEdx, void* adorn);        // UserInputBase::init
extern "C" boost::shared_ptr<RBX::DataModel>* __fastcall fn_0046a940(void* self, int unusedEdx, boost::shared_ptr<RBX::DataModel>* out); // CWorkspace::getDataModel

extern void* g_currentWindow_0096eff4;   // INFERRED: global at 0x96eff4 (last made-current window)

#define RAW(T, off) (*reinterpret_cast<T*>(reinterpret_cast<char*>(this) + (off)))

typedef void (__thiscall *VFn1)(void*, int);
typedef void (__thiscall *VFn0)(void*);

void CRobloxWnd::setDataModel(void* dm)
{
    if (dm == dataModel)
        return;

    boost::shared_ptr<RBX::DataModel>& gptr = dataModelPtr;   // 0x70
    boost::shared_ptr<RBX::Instance>& slot64 = RAW(boost::shared_ptr<RBX::Instance>, 0x64);
    boost::shared_ptr<RBX::Instance>& slot78 = RAW(boost::shared_ptr<RBX::Instance>, 0x78);

    if (gptr)
    {
        {
            boost::shared_ptr<const RBX::DataModel> hold(gptr);
            RBX::DataModel::Lock lock(hold);

            if (slot64.get())
            {
                fn_0055a8f0(slot64.get(), 0, 0);
                slot64.reset();
            }

            int ws = fn_0045dce0(gptr.get(), 0);
            if (ws)
                *reinterpret_cast<int*>(ws + 0x130) = 0;

            void* a = adorn;
            if (g_currentWindow_0096eff4 != a)
            {
                // makeCurrent: vtable +0x98
                void** vt = *reinterpret_cast<void***>(a);
                reinterpret_cast<VFn0>(vt[0x98 / 4])(a);
                g_currentWindow_0096eff4 = a;
            }

            void* b0 = RAW(void*, 0xb0);
            if (b0)
            {
                void** vt = *reinterpret_cast<void***>(b0);
                reinterpret_cast<VFn1>(vt[0])(b0, 1);
            }
            RAW(void*, 0xb0) = 0;

            fn_00555830(slot78.get(), 0, static_cast<RBX::IRunView*>(this));

            char* ui = reinterpret_cast<char*>(userInput);
            userInput = 0;
            if (ui)
            {
                void* sub = ui + 0x28;
                void** vt = *reinterpret_cast<void***>(sub);
                reinterpret_cast<VFn1>(vt[1])(sub, 1);
            }
            slot78.reset();
        }
    }

    if (dataModel != dm)
    {
        if (dm)
        {
            void** vt = *reinterpret_cast<void***>(dm);
            reinterpret_cast<VFn1>(vt[1])(dm, (int)dm);
        }
        if (dataModel)
        {
            void** vt = *reinterpret_cast<void***>(dataModel);
            reinterpret_cast<VFn1>(vt[2])(dataModel, (int)dataModel);
        }
        dataModel = dm;
    }

    if (dm)
    {
        boost::shared_ptr<RBX::DataModel> tmp;
        gptr = *fn_0046a940(dm, 0, &tmp);
    }
    else
    {
        gptr.reset();
    }

    if (!gptr)
        return;

    {
        boost::shared_ptr<const RBX::DataModel> hold(gptr);
        RBX::DataModel::Lock lock(hold);

        if (!flag_9c)
        {
            int mem = fn_006a0920(0x194);
            int obj = 0;
            if (mem)
                obj = fn_004690f0(reinterpret_cast<void*>(mem), 0, (int)this, (int)gptr.get());
            char* old = reinterpret_cast<char*>(userInput);
            userInput = reinterpret_cast<RBX::DxUserInput*>(obj);
            if (old)
            {
                void* sub = old + 0x28;
                void** vt = *reinterpret_cast<void***>(sub);
                reinterpret_cast<VFn1>(vt[1])(sub, 1);
            }
        }

        void* rs = gptr.get() ? fn_004530f0(gptr.get(), 0) : 0;
        boost::shared_ptr<RBX::Instance> tmpRun;
        slot78 = *fn_00618a40(&tmpRun, rs);
        tmpRun.reset();

        fn_004492d0(fn_00412d50(0), 0, 0);

        if (mode_5c == 2)
            fn_0045d850(this, 0);
        else
            fn_0045b3a0(this, 0);

        fn_005cea00(userInput, 0, RAW(void*, 0xb4));

        {
            // IRunView subobject at +0x54, virtual slot 1 with a double argument 0.0
            void* rv = static_cast<RBX::IRunView*>(this);
            void** vt = *reinterpret_cast<void***>(rv);
            typedef void (__thiscall *VFnD)(void*, double);
            reinterpret_cast<VFnD>(vt[1])(rv, 0.0);
        }

        fn_0045c890(this, 0);

        int inst = gptr.get() ? fn_0045de20(gptr.get(), 0) : 0;
        *reinterpret_cast<void**>(inst + 0x130) = userInput;

        int svc = gptr.get() ? fn_00458610(gptr.get(), 0) : 0;
        (void)svc;

        // INFERRED: slot_b0 virtual slot 7 (+0x1c) result feeds fn_0045f730, which fills the 0x64/0x68 pair.
        void* b0 = RAW(void*, 0xb0);
        void** vt = *reinterpret_cast<void***>(b0);
        typedef int (__thiscall *VFnR)(void*);
        int r = reinterpret_cast<VFnR>(vt[0x1c / 4])(b0);
        boost::shared_ptr<RBX::Instance> tmp;
        slot64 = *fn_0045f730(&tmp, r);
        tmp.reset();

        // INFERRED: the remainder of the function (after 0045fb25) was truncated and is not recovered.
    }
}
