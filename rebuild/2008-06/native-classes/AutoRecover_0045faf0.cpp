// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the target starts mid-function (at "call edx"), so this is a best-effort
// reconstruction of the tail of a larger routine. The register-carried state is modelled
// as parameters: esi -> self, ebx -> parent, edi -> runView.
#include <windows.h>
#include <string>

struct SpCountedBase {
    struct VT {
        void* dtor;
        void (__fastcall *dispose)(SpCountedBase*);
        void (__fastcall *destroy)(SpCountedBase*);
    };
    VT* vt;
    volatile long useCount;
    volatile long weakCount;
};

struct SharedCount {
    SpCountedBase* pi;
};

struct SpPair {
    void* px;
    SharedCount pn;
};

struct InstanceVT {
    void* slot0;
    void (__fastcall *setName)(void* self, int unusedEdx, const std::string* name);
};

struct InstanceLike {
    InstanceVT* vt;
};

extern "C" int fn_0045f730(int a1, int a2);
extern "C" int __fastcall fn_005ca240(void* self, int unusedEdx, int a1);
// INFERRED: RBX::Instance::setParent, RunService::addRunView, DataModel::Lock::~Lock
extern "C" void __fastcall fn_00402_shared_count_assign(void* self, int unusedEdx, const void* other);
extern "C" void __fastcall fn_0055a8f0(void* self, int unusedEdx, void* parent);
extern "C" void __fastcall fn_005557c0(void* self, int unusedEdx, void* runView);
extern "C" void __fastcall fn_005773c0(void* lock);

extern "C" void fn_0045faf0(char* self, void* parent, void* runView, int arg0, int arg1)
{
    SharedCount tmp;
    char lock[8];
    SpPair* r = (SpPair*)fn_0045f730((int)&tmp, arg0);

    *(void**)(self + 0x64) = r->px;
    fn_00402_shared_count_assign(self + 0x68, 0, &r->pn);

    SpCountedBase* pi = tmp.pi;
    if (pi) {
        if (InterlockedDecrement(&pi->useCount) == 0) {
            pi->vt->dispose(pi);
            if (InterlockedDecrement(&pi->weakCount) == 0)
                pi->vt->destroy(pi);
        }
    }

    {
        std::string name("Render");
        InstanceLike* inst = *(InstanceLike**)(self + 0x64);
        inst->vt->setName(inst, 0, &name);
    }

    fn_0055a8f0(*(void**)(self + 0x64), 0, parent);
    fn_005ca240(*(void**)(self + 0x64), 0, *(int*)(self + 0x98));
    fn_005557c0(*(void**)(self + 0x78), 0, runView);
    fn_005773c0(lock);

    HWND hwnd = *(HWND*)(self + 0x20);
    if (hwnd)
        InvalidateRect(hwnd, 0, TRUE);
}
