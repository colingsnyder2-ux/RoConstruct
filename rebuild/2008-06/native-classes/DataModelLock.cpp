// >>> native-status (generated) -- do not edit >>>
// DataModelLock | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src fb27b514 | roc native-status --write
#include "../native-headers/v8datamodel/DataModel.h"

namespace RBX {
DataModel::Lock::Lock(const DataModel* dataModel) : lock(0) { doLock(dataModel); }
DataModel::Lock::Lock(boost::shared_ptr<const DataModel> dataModel) : lock(0) { doLock(dataModel.get()); }
void DataModel::Lock::doLock(const DataModel* dataModel) {
    if (dataModel) {
        mutex = dataModel->mutex;
        lock = new boost::recursive_mutex::scoped_lock(*mutex);
    }
}
DataModel::Lock::~Lock() { delete lock; }
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<boost::recursive_mutex>;
