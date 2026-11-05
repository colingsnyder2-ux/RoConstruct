#include "util/Handle.h"
#include "v8tree/Instance.h"

namespace RBX
{
	InstanceHandle::InstanceHandle(Instance* target)
		: target(shared_from(target))
	{
	}

	boost::shared_ptr<Instance> InstanceHandle::getTarget() const
	{
		return target;
	}

	// inlined
	bool InstanceHandle::operatorEqual(const InstanceHandle& other) const
	{
		return this->target == other.target;
	}

	bool InstanceHandle::operatorLess(const InstanceHandle& other) const
	{
		return this->target < other.target;
	}

	// inlined
	bool InstanceHandle::operatorGreater(const InstanceHandle& other) const
	{
		return other.target < this->target;
	}

	bool InstanceHandle::empty() const
	{
		return target == NULL;
	}

	void InstanceHandle::linkTo(boost::shared_ptr<Instance> target)
	{
		this->target = target;
	}
}
