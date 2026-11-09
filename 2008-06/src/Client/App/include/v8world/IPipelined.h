#pragma once
#include "v8kernel/Kernel.h"
#include "v8kernel/IStage.h"
#include "v8world/IWorldStage.h"

namespace RBX
{
	class World;

	class __declspec(novtable) IPipelined
	{
	private:
		RBX::IStage* currentStage;
  
	public:
		void removeFromStage(IStage* stage);
	private:
		void removeFromStage(IStage::StageType);
		IStage* getStage(IStage::StageType stageType) const;
	public:
		//IPipelined(const IPipelined&);
		IPipelined() : currentStage(NULL) {}
		virtual ~IPipelined()
		{
		}
		void putInPipeline(IStage* stage);
		void removeFromPipeline(IStage* stage);
		void putInStage(IStage* stage);
		bool inPipeline() const
		{
			return currentStage != NULL;
		}
		bool inStage(IStage* iStage) const
		{
			RBXASSERT(iStage);
			RBXASSERT(currentStage);

			return currentStage == iStage;
		}
		bool inStage(IStage::StageType stageType) const
		{
			RBXASSERT(currentStage);

			return currentStage->getStageType() == stageType;
		}
		bool inOrDownstreamOfStage(IStage* iStage) const
		{
			RBXASSERT(iStage);
			RBXASSERT(currentStage);

			return (int)currentStage->getStageType() >= (int)iStage->getStageType();
		}
		bool downstreamOfStage(IStage* iStage) const
		{
			return (int)currentStage->getStageType() > (int)iStage->getStageType();
		}
		bool inKernel() const
		{
			return this->inStage(IStage::KERNEL_STAGE);
		}
		Kernel* getKernel() const;
		virtual void putInKernel(Kernel* kernel);
		virtual void removeFromKernel();
		World* getWorld2008()
		{
			if (!currentStage)
				return NULL;

			IStage* upstream;
			if (currentStage->getStageType() != (IStage::StageType)7)
				upstream = currentStage;
			else
				upstream = currentStage->getUpstream();

			return rbx_static_cast<IWorldStage*>(upstream)->getWorld();
		}

		World* getWorld()
		{
			if (!currentStage)
				return NULL;

			IStage* upstream;
			if (currentStage->getStageType() != IStage::KERNEL_STAGE)
				upstream = currentStage;
			else
				upstream = currentStage->getUpstream();

			return rbx_static_cast<IWorldStage*>(upstream)->getWorld();
		}
		//IPipelined& operator=(const IPipelined&);
	};
}
