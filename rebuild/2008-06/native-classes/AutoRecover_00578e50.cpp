// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
namespace RBX {
class Camera { public: void onHeartbeat(); };
namespace Profiling {
class CodeProfiler;
// INFERRED: layout/size from stack slots; only ctor/dtor are used.
class Mark {
public:
    Mark(CodeProfiler& p, bool enable);
    ~Mark();
private:
    int data[4];
};
}
}

// INFERRED: object at +0x288 is an interface whose vtable slot 1 returns the Camera.
struct CameraProvider {
    virtual void slot0();
    virtual RBX::Camera* getCamera();
};

extern "C" int __fastcall fn_00578ca0(void* self, int unusedEdx, float a1);
extern "C" int __fastcall fn_005fbd80(void* self, int unusedEdx);

extern "C" void __fastcall fn_00578e50(char* self, int unusedEdx, float dt)
{
    if (self[0x259]) {
        char* owner = *(char**)(self + 0x204);
        RBX::Profiling::Mark mark(*(RBX::Profiling::CodeProfiler**)(owner + 0x428)[0] ? *(RBX::Profiling::CodeProfiler*)*(void**)(owner + 0x428) : *(RBX::Profiling::CodeProfiler*)*(void**)(owner + 0x428), true);
        fn_00578ca0(self, 0, dt);
        CameraProvider* prov = (CameraProvider*)(*(char**)(self + 0x204) + 0x288);
        prov->getCamera()->onHeartbeat();
        fn_005fbd80(*(void**)(self + 0x1fc), 0);
    }
}
