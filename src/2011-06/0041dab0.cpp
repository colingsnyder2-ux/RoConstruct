// from server: 85% by atomic.potato
struct DSVideoCaptureEngine {
    void stopCapture();
    void sub_41d710();
};

extern "C" int __cdecl AssertFail(const char*, const char*, unsigned int, const char*, int, int, int);

extern unsigned char g_deviceLostFlag;

void DSVideoCaptureEngine::stopCapture()
{
    if (g_deviceLostFlag)
        AssertFail(".\\DSVideoCaptureEngine.cpp", "DSVideoCaptureEngine: Device lost", 0x482, "F4SSPhe", 0, 0, 0);
    sub_41d710();
}
