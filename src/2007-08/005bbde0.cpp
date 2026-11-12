// from server: 88% by EspClaude
// from server: 67% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_claude_db6cfcd3c8abd78b.cpp

// Candidate translation unit (score above; library headers required).
// 2007-08 0x5bbde0 PVInstance::computeTopPVController: self-contained codegen analog.
// Target-proven: no RBXASSERT code (asserts off), Instance::parent at +0xbc, the
// TopPVController ComputeProp at +0x128 (getValue out of line), controllerType at +0x14c,
// getTypedRoot<PVInstance>() out of line, ServiceProvider::create<ControllerService>
// cdecl, ControllerService::getController(type, this) returning by hidden pointer.
#undef _RELEASEASSERT
#include "v8world/Controller.h"
#include "util/ComputeProp.h"

namespace RBX
{
	class Instance
	{
	protected:
		char pad04[0xbc - 4];
		Instance* parent;
	public:
		virtual ~Instance();

		template<typename Type>
		const Type* getTypedParent() const
		{
			return static_cast<const Type*>(parent);
		}

		template<typename Type>
		const Type* getTypedRoot() const
		{
			const Type* typedParent = dynamic_cast<const Type*>(parent);
			if (typedParent)
				return typedParent->getTypedRoot<Type>();
			else
				return static_cast<const Type*>(this);
		}

		template<typename Type>
		const Type* queryTypedParent() const
		{
			return dynamic_cast<const Type*>(parent);
		}
	};

	class ServiceProvider
	{
	public:
		template<typename Class>
		static Class* create(const Instance* context);
	};

	class PVInstance;
	class ControllerService
	{
	public:
		G3D::ReferenceCountedPointer<Controller> getController(Controller::ControllerType type, const PVInstance* controlledInstance);
	};

	class PVInstance : public Instance
	{
	protected:
		char pad0c0[0x128 - 0xc0];
		ComputeProp<G3D::ReferenceCountedPointer<Controller>, PVInstance> TopPVController;
	private:
		char pad_ctl[0x14c - 0x128 - sizeof(ComputeProp<G3D::ReferenceCountedPointer<Controller>, PVInstance>)];	// controllerType at +0x14c (target)
		Controller::ControllerType controllerType;

		G3D::ReferenceCountedPointer<Controller> computeTopPVController() const;
	public:
		bool isTopLevelPVInstance() const
		{
			return !queryTypedParent<PVInstance>() || getTypedRoot<PVInstance>() == getTypedParent<PVInstance>();
		}
	};

	G3D::ReferenceCountedPointer<Controller> PVInstance::computeTopPVController() const
	{
		if (queryTypedParent<PVInstance>() && getTypedRoot<PVInstance>() != getTypedParent<PVInstance>())
		{
			G3D::ReferenceCountedPointer<RBX::Controller> controller = getTypedParent<PVInstance>()->TopPVController;

			if (controller.notNull())
			{
				if (controller->getControllerType() != Controller::NO_CONTROLLER && !controller->isUserController())
					return controller;
			}
		}

		ControllerService* controllerService = ServiceProvider::create<ControllerService>(this);
		return controllerService ? controllerService->getController(controllerType, this) : NULL;
	}
}
