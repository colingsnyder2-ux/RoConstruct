// 2008-06 native RBX::Workspace members (inactive), original unit v8datamodel/Workspace.cpp, 005a01e0..005a66af in
// the application range 005a0000..005ac000. Built against the committed native v8datamodel/Workspace.h (read-only).
// Verified by tests/record_native_app_unit5a0_2008.py (receipt app-unit5a0-2008-working.json).
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/MouseCommand.h"
#include "tool/NullTool.h"
#include "tool/ToolsArrow.h"
#include "v8datamodel/PVInstance.h"
#include "v8datamodel/PartInstance.h"
#include "Network/Players.h"
#include "script/Script.h"
#include "script/ScriptContext.h"
#include "v8datamodel/Flag.h"
#include "humanoid/Humanoid.h"
#include "v8world/World.h"
#include "v8xml/SerializerV2.h"

namespace RBX
{
	// @005a01e0 ?askAddChild@Workspace
	bool Workspace::askAddChild(const Instance* instance) const
	{
		return dynamic_cast<const IRenderable*>(instance) != NULL;
	}

	// @005a0210 ?getGCamera@Workspace
	const G3D::GCamera& Workspace::getGCamera() const
	{
		return getCamera()->getGCamera();
	}

	// @005a0220 ?onWrapMouse@Workspace
	void Workspace::onWrapMouse(const G3D::Vector2& wrapMouseDelta)
	{
		getCamera()->onWrapMouse(wrapMouseDelta);
	}

	// @005a0240 ?zoomToExtents@Workspace
	void Workspace::zoomToExtents()
	{
		getCamera()->zoomExtents(viewPort);
	}

	// @005a0260 ?stop@Workspace
	void Workspace::stop()
	{
		isSimulating = false;
		getCamera()->autoMode();
	}

	// @005a0280 ?newNullTool@RBX
	MouseCommand* newNullTool(Workspace* workspace)
	{
		return new NewNullTool(workspace);
	}

	// @005a05a0 ?getCamera@Workspace
	Camera* Workspace::getCamera() const
	{
		return currentCamera ? currentCamera.get() : cameraTemplate.get();
	}

	// @005a0610 ?setNullMouseCommand@Workspace
	void Workspace::setNullMouseCommand()
	{
		stickyCommand.reset();
		currentCommand.reset(newNullTool(this));
	}

	// @005a0530 ?getMyWorkspaceFast@Workspace
	Workspace* Workspace::getMyWorkspaceFast(const Instance* context)
	{
		Instance* parent = context->getParent();
		Instance* parent2 = parent->getParent();
		while (parent2->getParent())
		{
			parent = parent2;
			parent2 = parent2->getParent();
		}
		return static_cast<Workspace*>(parent);
	}

	// @005a0560 ?getMyWorldFast@Workspace
	World* Workspace::getMyWorldFast(const Instance* context)
	{
		return getMyWorkspaceFast(context)->getWorld();
	}

	// @005a2730 ?setDefaultMouseCommand@Workspace
	void Workspace::setDefaultMouseCommand()
	{
		stickyCommand.reset();
		setMouseCommand(NULL);
	}

	// @005a27c0 ?releaseScript@Workspace
	void Workspace::releaseScript(Script* script)
	{
		pendingScripts.erase(script);
	}

	// @005a3380 ?findWorkspace@Workspace
	Workspace* Workspace::findWorkspace(const Instance* context)
	{
		return ServiceProvider::find<Workspace>(context);
	}

	// @005a3390 ?getWorldIfInWorkspace@Workspace
	World* Workspace::getWorldIfInWorkspace(const Instance* context)
	{
		Workspace* workspace = ServiceProvider::find<Workspace>(context);
		if (workspace && (context == workspace || context->isDescendentOf(workspace)))
			return workspace->getWorld();
		else
			return NULL;
	}

	// @005a33d0 ?contextInWorkspace@Workspace
	bool Workspace::contextInWorkspace(const Instance* context)
	{
		return getWorkspaceIfInWorkspace(context) != NULL;
	}

	// @005a3410 ?getWorkspaceIfInWorkspace@Workspace
	Workspace* Workspace::getWorkspaceIfInWorkspace(const Instance* context)
	{
		Workspace* workspace = ServiceProvider::find<Workspace>(context);
		if (workspace && (context == workspace || context->isDescendentOf(workspace)))
			return workspace;
		else
			return NULL;
	}

	// @005a0740 ?scriptShouldRun@Workspace
	IScriptOwner* Workspace::scriptShouldRun(Script* script)
	{
		bool shouldRun;
		if (dynamic_cast<LocalScript*>(script) == NULL)
		{
			shouldRun = Network::Players::backendProcessing(this, true);
		}
		else
		{
			ModelInstance* character = Network::Players::findLocalCharacter(this);
			shouldRun = character && script->isDescendentOf(character);
		}
		return shouldRun ? this : NULL;
	}

	// @005a1b90 ?onChildChanged@Workspace
	void Workspace::onChildChanged(Instance* instance, const PropertyChanged& event)
	{
		Instance::onChildChanged(instance, event);
		raiseDrawChanged();
	}

	// @005a1bc0 ?onDescendentRemoving@Workspace
	void Workspace::onDescendentRemoving(const boost::shared_ptr<Instance>& instance)
	{
		IRenderable* renderable = dynamic_cast<IRenderable*>(instance.get());
		if (renderable)
			onRemoving(renderable);

		RootInstance::onDescendentRemoving(instance);
		raiseDrawChanged();
	}

	// @005a1c20 ?onDescendentAdded@Workspace
	void Workspace::onDescendentAdded(Instance* instance)
	{
		RootInstance::onDescendentAdded(instance);
		raiseDrawChanged();

		IRenderable* renderable = dynamic_cast<IRenderable*>(instance);
		if (renderable)
			onAdded(renderable);

		PVInstance* pvInstance = dynamic_cast<PVInstance*>(instance);
		if (pvInstance && pvInstance->getLegacyOffset())
		{
			pvInstance->legacyTraverseState(G3D::CoordinateFrame());
			pvInstance->clearLegacyOffset();
			if (legacyOffset)
				legacyOffset.reset();
		}
	}

	// @005a1fc0 ?setMouseCommand@Workspace
	void Workspace::setMouseCommand(MouseCommand* newMouseCommand)
	{
		if (!newMouseCommand)
		{
			if (!stickyCommand.get() || (newMouseCommand = stickyCommand->isSticky(), !newMouseCommand))
			{
				if (!Network::Players::findLocalPlayer(this))
					newMouseCommand = new ArrowTool(this);
				else
					newMouseCommand = newNullTool(this);
			}
		}

		if (newMouseCommand != currentCommand.get())
		{
			currentCommand.reset(newMouseCommand);

			MouseCommand* sticky = newMouseCommand->isSticky();
			if (sticky)
				stickyCommand.reset(sticky);

			Notifier<Workspace, ToolChanged>::raise(ToolChanged());
		}
	}
	// @005a1ce0 ?clearEmptiedModels@RBX
	void clearEmptiedModels(boost::shared_ptr<Instance> test, Instance* parent)
	{
		if (test.get() != parent)
		{
			ModelInstance* model = dynamic_cast<ModelInstance*>(test.get());
			if (model && !Humanoid::modelIsCharacter(model) && !model->findFirstChildOfType<PartInstance>() && !model->findFirstChildOfType<ModelInstance>())
			{
				boost::shared_ptr<Instance> oldParent = shared_from(model->getParent());
				model->setParent(NULL);
				clearEmptiedModels(oldParent, parent);
			}

			Flag* flag = dynamic_cast<Flag*>(test.get());
			if (flag && !flag->findFirstChildOfType<PartInstance>())
			{
				boost::shared_ptr<Instance> oldParent = shared_from(flag->getParent());
				flag->setParent(NULL);
				clearEmptiedModels(oldParent, parent);
			}
		}
	}

	// @005a1e80 ?handleFallenParts@Workspace
	void Workspace::handleFallenParts(const G3D::Array<boost::shared_ptr<PartInstance>>& fallenParts)
	{
		for (int i = 0; i < fallenParts.size(); i++)
		{
			boost::shared_ptr<PartInstance> part = fallenParts[i];

			boost::shared_ptr<Instance> oldParent = shared_from(part->getParent());
			part->setParent(NULL);
			clearEmptiedModels(oldParent, this);
		}
	}

	// @005a2760 ?runScript@Workspace
	void Workspace::runScript(Script* script, ScriptContext* context)
	{
		if (Network::Players::backendProcessing(this, true) && !isSimulating)
			pendingScripts.insert(script);
		else
			context->addScript(script);
	}

	// @005a0d90 ?findTopInstance@Workspace
	Instance* Workspace::findTopInstance(Instance* instance)
	{
		Instance* workspace = instance->getParent();
		Instance* data = workspace->getParent();
		while (data->getParent())
		{
			workspace = data;
			data = data->getParent();
		}
		while (instance->getParent() != workspace)
			instance = instance->getParent();
		return instance;
	}

	// @005a0de0 ?joinAllHack@Workspace
	void Workspace::joinAllHack()
	{
		world->joinAll();
	}

	template<bool isJoin>
	static void wrapper(Instance* instance)
	{
		PartInstance* part = dynamic_cast<PartInstance*>(instance);
		if (part)
		{
			if (isJoin)
				part->join();
			else
				part->destroyJoints();
		}
		else
		{
			instance->for_eachChild(&wrapper<isJoin>);
		}
	}

	template<bool isJoin>
	static void wrapper2(boost::shared_ptr<Instance> instance)
	{
		wrapper<isJoin>(instance.get());
	}

	// @005a2420 ?makeJoints@Workspace
	void Workspace::makeJoints(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance>>> instances)
	{
		std::for_each(instances->begin(), instances->end(), &wrapper2<true>);
	}

	// @005a24d0 ?breakJoints@Workspace
	void Workspace::breakJoints(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance>>> instances)
	{
		std::for_each(instances->begin(), instances->end(), &wrapper2<false>);
	}

	// @005a4d90 ??0Workspace@RBX@@QAE@PAVIDataState@1@@Z: not a row of this unit (counted by
	// workspace-lifetime-profiler-notifier-variant.json). Defined here so that the unit emits the Workspace vtables,
	// their inline virtuals and adjustor thunks and the NonFactoryProduct / DescribedNonCreatable constructors, as the
	// original unit does. Same body as native-classes/WorkspaceLifetime.cpp.
	Workspace::Workspace(IDataState* dataState)
		: VerbContainer(NULL),
		  dataState(dataState),
		  unknown0x3cc(NULL),
		  cameraTemplate(Creatable::create<Camera>()),
		  unknown0x410(0.0), unknown0x418(0.0), unknown0x420(0.0),
		  profileWorkspaceStep(new Profiling::CodeProfiler("DataModel Step")),
		  profileWorkspaceStepInner(new Profiling::CodeProfiler("Workspace Step")),
		  profileWorkspaceAssemble(new Profiling::CodeProfiler("Workspace Assemble")),
		  profileRunServiceStepped(new Profiling::CodeProfiler("RunService Stepped")),
		  profileRunServiceHeartbeat(new Profiling::CodeProfiler("RunService Heartbeat")),
		  arrowCameraControls(false),
		  inMouselookMode(false),
		  isSimulating(false),
		  scriptContext(NULL),
		  imageServerViewHack(0)
	{
		RBXASSERT(dataState);

		setName("Workspace");

		profileWorkspaceStepInner->parent = profileWorkspaceStep.get();
		world->getProfileWorldStep().parent = profileWorkspaceStepInner.get();
		profileWorkspaceAssemble->parent = profileWorkspaceStep.get();
		profileRunServiceStepped->parent = profileWorkspaceStep.get();
		profileRunServiceHeartbeat->parent = profileWorkspaceStep.get();
	}

	// @005a28c0 ??1Workspace@RBX@@UAE@XZ (support row here; counted by workspace-lifetime-profiler-notifier-variant.json)
	Workspace::~Workspace()
	{
	}

	// @005a05d0 ?insertItems@Workspace
	void Workspace::insertItems(XmlElement* root, std::vector<boost::shared_ptr<Instance>>& instances, InsertMode insertMode, PromptMode promptMode)
	{
		SerializerV2 serializer;
		serializer.loadInstances(root, instances);

		if (instances.size() > 0)
			insertInstances(instances, this, insertMode, promptMode);
	}

	// @005a0660 ?render2d@Workspace
	void Workspace::render2d(Adorn* adorn)
	{
		getCurrentMouseCommand()->render2d(adorn);
		render2dItems(adorn);
	}
}
// template rows emitted in this unit (address hints for the probe):
// @005a1530 ?raise@?$Notifier@VWorkspace@RBX@@VToolChanged@2@@RBX@@IBEXVToolChanged@2@@Z
// @005a16b0 ??$findFirstChildOfType@VPartInstance@RBX@@@Instance@RBX@@QBEPAVPartInstance@1@XZ
// @005a1750 ??$findFirstChildOfType@VModelInstance@RBX@@@Instance@RBX@@QBEPAVModelInstance@1@XZ
// @005a1910 ??$wrapper@$00@RBX
// @005a1950 ??$wrapper@$0A@@RBX
// @005a2290 ??$wrapper2@$00@RBX
// @005a2330 ??$wrapper2@$0A@@RBX
// @005a4280 ??0?$DescribedNonCreatable@VWorkspace@RBX
// @005a3b70 ?classDescriptor@?$Described@VWorkspace@RBX
// @005a07b0 ??0?$NonFactoryProduct@VRootInstance@RBX
// @005a17f0 ?getClassName@?$NonFactoryProduct@VRootInstance@RBX

#include "v8datamodel/DataModel.h"
#include "StandardVerbs.h"

namespace RBX {
char sArrowTool[] = "Arrow";
template<> MouseCommand* TToolVerb<ArrowTool, RunStateVerb>::newMouseCommand()
{
    return new ArrowTool(dataModel->getWorkspace());
}
template<> const Name& Named<ArrowToolBase, sArrowTool>::getName() const
{
    return NativeToolName<ArrowTool>::get();
}
}

#include "tool/MegaDragger.h"
#include "tool/AxisMoveTool.h"
#include "tool/AxisMoveGrid.h"

namespace RBX {
char sAxisMoveTool[] = "AxisMove";
AxisMoveTool::AxisMoveTool(Workspace* w) : Named<ArrowToolBase, sAxisMoveTool>(w), cursor("ArrowCursor"), dragging(false) {}
template<> MouseCommand* TToolVerb<AxisMoveTool, RunStateVerb>::newMouseCommand() {
    return new AxisMoveTool(dataModel->getWorkspace());
}
template<> const Name& Named<ArrowToolBase, sAxisMoveTool>::getName() const { return NativeToolName<AxisMoveTool>::get(); }
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

#undef _RELEASEASSERT
#include "tool/BasicMouseTools.h"
#include "tool/FlatTool.h"

namespace RBX {
template<> MouseCommand* TToolVerb<CloneTool, RunStateVerb>::newMouseCommand() { return new CloneTool(dataModel->getWorkspace()); }
template<> MouseCommand* TToolVerb<FlatTool, RunStateVerb>::newMouseCommand() { return new FlatTool(dataModel->getWorkspace()); }
template<> MouseCommand* TToolVerb<GameTool, RunStateVerb>::newMouseCommand() { return new GameTool(dataModel->getWorkspace()); }
template<> MouseCommand* TToolVerb<GrabTool, RunStateVerb>::newMouseCommand() { return new GrabTool(dataModel->getWorkspace()); }
template<> MouseCommand* TToolVerb<HammerTool, RunStateVerb>::newMouseCommand() { return new HammerTool(dataModel->getWorkspace()); }
template<> MouseCommand* TToolVerb<LaserTool, RunStateVerb>::newMouseCommand() { return new LaserTool(dataModel->getWorkspace()); }
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
