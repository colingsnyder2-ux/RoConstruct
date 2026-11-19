#include "util/MarshaledListener.h"
#include "v8tree/Instance.h"
#include "v8tree/PropertyChanged.h"
#include "util/RunStateOwner.h"

RBX::MarshaledListener<RBX::RunService, RBX::RunState>::EventData::EventData(RBX::MarshaledListener<RBX::RunService, RBX::RunState>* owner, const RBX::RunService* from, RBX::RunState value)
    : listener(owner), event(value)
{
    setSource(from);

// Explicitly instantiate the template for the binary's concrete specialisations.
// These must appear after the class members they instantiate.
template class RBX::MarshaledListener<RBX::Instance, RBX::PropertyChanged>;
template class RBX::MarshaledListener<RBX::RunService, RBX::RunState>;

} // namespace RBX

#include <map>
#include <set>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <memory>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/any.hpp>
#include "util/Object.h"

template class RBX::MarshaledListener<RBX::RunService,RBX::RunState,RBX::RunService,RBX::RunState>::EventData;
