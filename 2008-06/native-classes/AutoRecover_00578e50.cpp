// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no headers were provided, so the types below are minimal local declarations.
// The Mark ctor/dtor and Camera::onHeartbeat link to the mangled names in the disassembly comments.
namespace RBX {
    namespace Profiling {
        class CodeProfiler;
        class Mark {
        public:
            Mark(CodeProfiler& profiler, bool enable);
            ~Mark();
        private:
            // INFERRED: the object occupies at most 0x20 bytes on the stack.
            char storage[28];
        };
    }
    class Camera {
    public:
        void onHeartbeat();
    };
}

// INFERRED: the object embedded at +0x288 has a vtable whose slot 1 returns the Camera.
struct CameraHolder {
    virtual void* slot0();
    virtual RBX::Camera* getCamera();
};

extern "C" int __fastcall fn_00578ca0(void* self, int unusedEdx, float a1);
extern "C" int __fastcall fn_005fbd80(void* self, int unusedEdx);

extern "C" void __fastcall fn_00578e50(void* self, int unusedEdx, float arg)
{
    char* p = (char*)self;
    if (*(p + 0x259) != 0) {
        char* inner = *(char**)(p + 0x204);
        RBX::Profiling::CodeProfiler* prof = *(RBX::Profiling::CodeProfiler**)(inner + 0x428);
        RBX::Profiling::Mark mark(*prof, true);

        fn_00578ca0(self, 0, arg);

        char* inner2 = *(char**)(p + 0x204);
        CameraHolder* holder = (CameraHolder*)(inner2 + 0x288);
        holder->getCamera()->onHeartbeat();

        fn_005fbd80(*(void**)(p + 0x1fc), 0);
    }
}
