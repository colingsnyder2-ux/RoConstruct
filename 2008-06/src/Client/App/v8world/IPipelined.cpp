#include "v8world/IPipelined.h"
#include "v8kernel/Kernel.h"

namespace RBX
{
	IStage* IPipelined::getStage(IStage::StageType stageType) const
	{
		IStage* stage = currentStage;
		while (stage->getStageType() != stageType)
		{
			if ((int)stage->getStageType() > (int)stageType)
				stage = stage->getUpstream();
			else
				stage = stage->getDownstream();
		}
		return stage;
	}

	void IPipelined::putInPipeline(IStage* stage)
	{
		RBXASSERT(stage);
		RBXASSERT(!currentStage);

		currentStage = stage;
	}

	void IPipelined::removeFromPipeline(IStage* stage)
	{
		                ;
		                       ;
		                                ;

		currentStage = NULL;
	}

	void IPipelined::putInStage(IStage* stage)
	{
		RBXASSERT(stage);
		RBXASSERT(currentStage);
		RBXASSERT(stage->getUpstream() == currentStage);
		RBXASSERT(currentStage->getDownstream() == stage);

		currentStage = stage;
	}

	void IPipelined::removeFromStage(IStage* stage)
	{
		                       ;
		                ;
		                                ;
		                               ;

		currentStage = currentStage->getUpstream();
	}

	Kernel* IPipelined::getKernel() const
	{
		RBXASSERT(this->inKernel());

		IStage* stage = this->getStage(IStage::KERNEL_STAGE);
		return rbx_static_cast<Kernel*>(stage);
	}

	void IPipelined::putInKernel(Kernel* kernel)
	{
		this->putInStage((IStage*)kernel);
	}

	void IPipelined::removeFromKernel()
	{
	this->removeFromStage(currentStage);
}
}
