// Shortcut (owner-authorized): the rbxgs 2007 donor's DataModel::Lock::doLock leaves `lock` uninitialized for a null model,
// so ~Lock deletes garbage; the 2008 client initializes it (CSelectionCaption::update locks a null model at startup).
#include "v8datamodel/DataModel.h"
namespace RBX {
void DataModel::Lock::doLock(const DataModel* dataModel)
{
    lock = 0;
    if (dataModel) {
        mutex = dataModel->mutex;
        lock = new boost::recursive_mutex::scoped_lock(*mutex);
    }
}
}
