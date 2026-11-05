#pragma once
// Declaration-only overlay for RBX::Workspace used by tests/record_native_feature.py for the NATIVE_FEATURE_PENDING
// build (copied as out/native-feature-pending/v8datamodel/Workspace.h); not a shared header. The donor Workspace.h
// does not compile against the 2008 reflection.h. Signature from the donor; address from the call site in
// VelocityMotor::onAncestorChanged 0060a0f0 (also JointInstance::onAncestorChanged 005e3a80).
namespace RBX
{
	class Instance;
	class World;

	class Workspace
	{
	public:
		static World* getWorldIfInWorkspace(const Instance* context);  // 005a3390
	private:
		Workspace();
	};
}
