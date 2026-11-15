// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
#include "../native-headers/v8kernel/IPipelined2008.h"

namespace RBX {
RBX::IStage* IPipelined::getStage(RBX::IStage::StageType stageType) const
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
}
