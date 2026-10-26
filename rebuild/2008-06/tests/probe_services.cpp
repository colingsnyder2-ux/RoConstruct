// Probe (diagnostic only): which services DataModel::createDataModel leaves in place, whether the factory can
// create each by class name, and whether global settings items resolve.
#include <winsock2.h>
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/Lighting.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/GlobalSettings.h"
#include "v8datamodel/DebugSettings.h"
#include <cstdio>
#undef main

template<class T> void probe(RBX::DataModel* dm, const char* label)
{
    T* found = RBX::ServiceProvider::find<T>(dm);
    boost::shared_ptr<RBX::Instance> made = RBX::AbstractFactoryProduct<RBX::Instance>::create(T::className());
    std::printf("%-14s class=%-12s found=%d factory=%d\n", label, T::className().toString().c_str(), found != 0, made != 0);
}

int main()
{
    boost::shared_ptr<RBX::GlobalSettings> settings = RBX::GlobalSettings::singleton();
    boost::shared_ptr<RBX::Instance> made = RBX::AbstractFactoryProduct<RBX::Instance>::create(RBX::DebugSettings::className());
    std::printf("global settings=%p debug factory=%d\n", (void*)settings.get(), made != 0);
    RBX::DebugSettings* debug = RBX::ServiceProvider::create<RBX::DebugSettings>(settings.get());
    std::printf("debug settings created=%p\n", (void*)debug);

    boost::shared_ptr<RBX::DataModel> dm = RBX::DataModel::createDataModel();
    RBX::DataModel::Lock lock(dm);
    probe<RBX::StarterPackService>(dm.get(), "StarterPack");
    probe<RBX::Lighting>(dm.get(), "Lighting");
    probe<RBX::Teams>(dm.get(), "Teams");
    std::printf("children=%u\n", dm->numChildren());
    std::fflush(stdout);
    return 0;
}
