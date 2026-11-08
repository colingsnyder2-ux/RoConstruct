#pragma once
// >>> native-status (generated) -- do not edit >>>
// DragTool | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 728b455e | roc native-status --write
#include <G3D/Vector3.h>
#include <boost/shared_ptr.hpp>
#include <vector>

namespace RBX
{
	class MouseCommand;
	class PartInstance;
	class Instance;
	class UIEvent;
	class Workspace;

	// Six parameters, from the mangled name the Grab/Clone tools call at 00660550:
	// ...ABVUIEvent@2@PAVWorkspace@2@V?$shared_ptr@VInstance@RBX@@@boost@@@Z
	class DragTool
	{
	public:
		static MouseCommand* onMouseDown(PartInstance* hitPart, const G3D::Vector3& hitWorld, const std::vector<Instance*>& dragInstances, const UIEvent& uiEvent, Workspace* workspace, boost::shared_ptr<Instance> decal);
	};
}
