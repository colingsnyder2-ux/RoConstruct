#ifndef UTIL_HANDLE_H
#define UTIL_HANDLE_H

#include <boost/shared_ptr.hpp>

namespace RBX {

class Instance;

class InstanceHandle
{
private:
	boost::shared_ptr<Instance> target; // 0x00

public:
	InstanceHandle() {}
	InstanceHandle(Instance* target);
	InstanceHandle(boost::shared_ptr<Instance>);
	InstanceHandle(const InstanceHandle& other) : target(other.target) {}

	InstanceHandle& operator=(const InstanceHandle& other)
	{
		target = other.target;
		return *this;
	}

	InstanceHandle& operator=(boost::shared_ptr<Instance>);

	bool empty() const;

	boost::shared_ptr<Instance> getTarget() const { return target; }

	void linkTo(boost::shared_ptr<Instance> target);

	bool operator==(const InstanceHandle&) const;
	bool operator!=(const InstanceHandle&) const;
	bool operator<(const InstanceHandle& other) const { return operatorLess(other); }
	bool operator>(const InstanceHandle&) const;

protected:
	bool operatorEqual(const InstanceHandle&) const;
	bool operatorLess(const InstanceHandle& other) const;
	bool operatorGreater(const InstanceHandle&) const;
public:
	~InstanceHandle(void);   // INFERRED: ??1InstanceHandle@RBX@@QAE@XZ (header gap, header_gap_fill.py)
};

} // namespace RBX

#endif // UTIL_HANDLE_H
