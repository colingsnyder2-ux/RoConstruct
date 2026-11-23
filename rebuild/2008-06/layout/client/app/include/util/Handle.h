// =============================================================================
// Handle.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/util/Handle.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#ifndef UTIL_HANDLE_H
#define UTIL_HANDLE_H

#include <boost/shared_ptr.hpp>

namespace RBX
{

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
	// ~InstanceHandle is compiler-generated; the binary has it out of line only as an emitted COMDAT (core header fix 2026-11-22).
};

} // namespace RBX

#endif // UTIL_HANDLE_H
