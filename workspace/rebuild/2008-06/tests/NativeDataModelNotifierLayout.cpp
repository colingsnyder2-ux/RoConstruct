#include "../native-headers/v8datamodel/DataModel.h"
RBX::Notifier<RBX::ServiceProvider, RBX::ServiceAdded>* modelAdded(RBX::DataModel* p) { return p; }
RBX::Notifier<RBX::ServiceProvider, RBX::ServiceRemoving>* modelRemoving(RBX::DataModel* p) { return p; }
