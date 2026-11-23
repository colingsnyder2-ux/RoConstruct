#undef _RELEASEASSERT
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Camera.h"

namespace RBX
{
	static Reflection::BoundFuncDesc<Workspace, boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >(ContentId), 1> func_insertContent(&Workspace::insertContent, "InsertContent", "url", Reflection::FunctionDescriptor::AnyCaller);
	static Reflection::BoundFuncDesc<Workspace, void(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >), 1> func_makeJoints(&Workspace::makeJoints, "MakeJoints", "objects", Reflection::FunctionDescriptor::AnyCaller);
	static Reflection::BoundFuncDesc<Workspace, void(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >), 1> func_breakJoints(&Workspace::breakJoints, "BreakJoints", "objects", Reflection::FunctionDescriptor::AnyCaller);
	static Reflection::BoundFuncDesc<Workspace, void(bool), 1> func_setPhysicsThrottleEnabled(&Workspace::setThrottleEnabled, "SetPhysicsThrottleEnabled", "value", Reflection::FunctionDescriptor::AnyCaller);
	static Reflection::BoundFuncDesc<Workspace, void(), 0> func_zoomToExtents(&Workspace::zoomToExtents, "ZoomToExtents", Reflection::FunctionDescriptor::AnyCaller);

	static Reflection::RefPropDescriptor<Workspace, Camera> currentCameraProxyProp("CurrentCamera", "Data", &Workspace::getCamera, &Workspace::setCamera, Reflection::PropertyDescriptor::STANDARD);

	void Workspace::setCamera(Camera* value)
	{
		if (value != currentCamera.get())
		{
			currentCamera = shared_from(value);
			raisePropertyChanged(currentCameraProxyProp);
		}
	}
}

#include "tool/FlatTool.h"
#include "v8datamodel/Surface.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/DataModel.h"
#include "StandardVerbs.h"

namespace RBX {
char sFlatTool[] = "FlatTool";
const std::string FlatTool::getCursorName() const { return "FlatCursor"; }
MouseCommand* FlatTool::isSticky() const { return new FlatTool(workspace); }
void FlatTool::applyToSurface(Surface* surface) {
    surface->getPartInstance()->destroyJoints();
    surface->flat();
    surface->getPartInstance()->join();
}
template<> MouseCommand* TToolVerb<FlatTool, RunStateVerb>::newMouseCommand() {
    return new FlatTool(dataModel->getWorkspace());
}
template<> const Name& Named<SurfaceTool, sFlatTool>::getName() const {
    return NativeToolName<FlatTool>::get();
}
}

#include "tool/ModelTools.h"

namespace RBX {
template<> MouseCommand* TToolVerb<AnchorTool, RunStateVerb>::newMouseCommand()
{
    return new AnchorTool(dataModel->getWorkspace());
}

template<> MouseCommand* TToolVerb<LockTool, RunStateVerb>::newMouseCommand()
{
    return new LockTool(dataModel->getWorkspace());
}
}

#include "v8datamodel/ToolsPart.h"

namespace RBX {
template<> MouseCommand* TToolVerb<FillTool, RunStateVerb>::newMouseCommand() { return new FillTool(dataModel->getWorkspace()); }
template<> MouseCommand* TToolVerb<DropperTool, RunStateVerb>::newMouseCommand() { return new DropperTool(dataModel->getWorkspace()); }
template<> MouseCommand* TToolVerb<ModelSetPrimaryPartTool, RunStateVerb>::newMouseCommand() { return new ModelSetPrimaryPartTool(dataModel->getWorkspace()); }
}

#undef _RELEASEASSERT
#include "tool/SurfaceTools.h"

namespace RBX {
#define RBX_SURFACE_FACTORY(T) \
template<> MouseCommand* TToolVerb<T, RunStateVerb>::newMouseCommand() { return new T(dataModel->getWorkspace()); } \
template<> const Name& Named<SurfaceTool, s##T>::getName() const { return NativeToolName<T>::get(); }
RBX_SURFACE_FACTORY(GlueTool)
RBX_SURFACE_FACTORY(WeldTool)
RBX_SURFACE_FACTORY(StudsTool)
RBX_SURFACE_FACTORY(InletTool)
RBX_SURFACE_FACTORY(HingeTool)
RBX_SURFACE_FACTORY(RightMotorTool)
RBX_SURFACE_FACTORY(LeftMotorTool)
RBX_SURFACE_FACTORY(OscillateMotorTool)
#undef RBX_SURFACE_FACTORY
}

#include "v8datamodel/ModelInstance.h"

namespace RBX {

extern template boost::shared_ptr<ModelInstance> Creatable<Instance>::create<ModelInstance>();

boost::shared_ptr<ModelInstance> Workspace::group(std::vector<boost::shared_ptr<Instance> >::const_iterator first,
                                                   std::vector<boost::shared_ptr<Instance> >::const_iterator last) {
    boost::shared_ptr<ModelInstance> result = Creatable<Instance>::create<ModelInstance>();
    result->setParent(this);
    for (; first != last; ++first) (*first)->setParent(result.get());
    return result;
}

}

#include "v8datamodel/Selection.h"

namespace RBX {

void Workspace::selectAll()
{
    ServiceClient<Selection> selection(this);
    selection->clearSelection();
    for (unsigned int i = 0; i < numChildren(); ++i) {
        Instance* child = getChild(i);
        if (dynamic_cast<IRenderable*>(child) && !PartInstance::getLocked(child))
            selection->addToSelection(child);
    }
}

}
