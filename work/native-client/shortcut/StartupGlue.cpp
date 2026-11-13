// Shortcut glue (owner-authorized): the native shell names three exe startup helpers nativeX(); the engine objects already define the
// real RBX functions they forward to, so these are real bodies instead of zero stubs.
//   00569910 nativeSetOutputMode  : `mov eax,[esp+4]; mov [0x946274],eax` (a StandardOut mode word)
//   005c3f00 nativeProfilerEnable : RBX::Profiling::init(bool)   (openrbx Roblox.cpp InitInstance: RBX::Profiling::init(true))
//   0049ecf0 nativeSetVersion     : RBX::Network::API::init(const char*)  (openrbx Roblox.cpp: RBX::Network::API::init(m_unk0xf0.c_str()))
namespace RBX {
namespace Profiling { void init(bool); }
namespace Network { class API { public: static void init(const char*); }; }
}

int nativeStandardOutMode;  // exe 0x946274

void nativeSetOutputMode(int mode)
{
    nativeStandardOutMode = mode;
}

void nativeProfilerEnable(bool enable)
{
    RBX::Profiling::init(enable);
}

void nativeSetVersion(const char* version)
{
    (void)version;  // RBX::Network::API::init(version) crashes in NetworkSettings -> Instance::setName until the type registration stubs are real
}
