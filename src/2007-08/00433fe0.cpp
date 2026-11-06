// from server: 50% by Intel
struct CBrowserFrameWnd;

extern "C" void* __cdecl operator_new(unsigned int);

struct CBrowserFrameWnd {
    virtual ~CBrowserFrameWnd();
    CBrowserFrameWnd* Initialize();
    CBrowserFrameWnd* Construct();
};

CBrowserFrameWnd* CBrowserFrameWnd::Initialize() {
    __try {
        CBrowserFrameWnd* result = 0;
        void* memory = operator_new(0xD8);
        if (memory) {
            result = static_cast<CBrowserFrameWnd*>(memory)->Construct();
        }
        return result;
    }
    __finally {
    }
}
