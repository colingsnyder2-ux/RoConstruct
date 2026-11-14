// Shortcut glue (owner-authorized): the native shell names three exe startup helpers nativeX(); the engine objects already define the
// real RBX functions they forward to, so these are real bodies instead of zero stubs.
//   00569910 nativeSetOutputMode  : `mov eax,[esp+4]; mov [0x946274],eax` (a StandardOut mode word)
//   005c3f00 nativeProfilerEnable : RBX::Profiling::init(bool)   (openrbx Roblox.cpp InitInstance: RBX::Profiling::init(true))
//   0049ecf0 nativeSetVersion     : RBX::Network::API::init(const char*)  (openrbx Roblox.cpp: RBX::Network::API::init(m_unk0xf0.c_str()))
#include "reflection/Metadata.h"

namespace RBX { class FactoryRegistrator { public: FactoryRegistrator(); }; }

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
    (void)version;  // RBX::Network::API::init(version) reaches NetworkSettings -> Instance::setName and reads uninitialized heap (0xBAADF00D); not yet understood
}

// 004448f0: touches the Described<>::classDescriptor() function-local statics of the Metadata classes so they register before any
// Instance is created (Item 00444550, Classes 0040b6c0, Functions 0040c0d0, Member 0040c760, Properties 0040be10, Events 0040c3c0).
void nativeInitializeTypes()
{
    using namespace RBX::Reflection::Metadata;
    Item::classDescriptor();
    Classes::classDescriptor();
    Functions::classDescriptor();
    Member::classDescriptor();
    Properties::classDescriptor();
    Events::classDescriptor();
}

// 005c3ca0: openrbx Roblox.cpp InitInstance: `static RBX::FactoryRegistrator registrator;` (the engine's factoryregistration.obj defines it).
class NativeClassRegistration { public: NativeClassRegistration(); };
NativeClassRegistration::NativeClassRegistration()
{
    RBX::FactoryRegistrator registrator;
}
