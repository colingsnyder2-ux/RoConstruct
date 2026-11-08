// >>> native-status (generated) -- do not edit >>>
// DataModelLock | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 81d4e6c9 | roc native-status --write
#include "../../native-headers/v8datamodel/DataModel.h"

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
