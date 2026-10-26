// Probe (diagnostic only): which services DataModel::createDataModel leaves in place, and whether the
// factory can create each by class name.
#include <winsock2.h>
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/Lighting.h"
#include "v8datamodel/Teams.h"
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
    boost::shared_ptr<RBX::DataModel> dm = RBX::DataModel::createDataModel();
    RBX::DataModel::Lock lock(dm);
    probe<RBX::StarterPackService>(dm.get(), "StarterPack");
    probe<RBX::Lighting>(dm.get(), "Lighting");
    probe<RBX::Teams>(dm.get(), "Teams");
    std::printf("children=%u\n", dm->numChildren());
    return 0;
}
