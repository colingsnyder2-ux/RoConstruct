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
#include "v8xml/XmlSerializer.h"

namespace RBX
{
	bool Workspace::askAddChild(const Instance* instance) const
	{
		return dynamic_cast<const IRenderable*>(instance) != NULL;
	}

	const G3D::GCamera& Workspace::getGCamera() const
	{
		return getCamera()->getGCamera();
	}

	void Workspace::onWrapMouse(const G3D::Vector2& wrapMouseDelta)
	{
		getCamera()->onWrapMouse(wrapMouseDelta);
	}

	void Workspace::zoomToExtents()
	{
		getCamera()->zoomExtents(viewPort);
	}

	void Workspace::stop()
	{
		isSimulating = false;
		getCamera()->autoMode();
	}

	MouseCommand* newNullTool(Workspace* workspace)
	{
		return new NewNullTool(workspace);
	}

	Camera* Workspace::getCamera() const
	{
		return currentCamera ? currentCamera.get() : cameraTemplate.get();
	}

	void Workspace::setNullMouseCommand()
	{
		stickyCommand.reset();
		currentCommand.reset(newNullTool(this));
	}

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

	World* Workspace::getMyWorldFast(const Instance* context)
	{
		return getMyWorkspaceFast(context)->getWorld();
	}

	void Workspace::setDefaultMouseCommand()
	{
		stickyCommand.reset();
		setMouseCommand(NULL);
	}

	void Workspace::releaseScript(Script* script)
	{
		pendingScripts.erase(script);
	}

	Workspace* Workspace::findWorkspace(const Instance* context)
	{
		return ServiceProvider::find<Workspace>(context);
	}

	World* Workspace::getWorldIfInWorkspace(const Instance* context)
	{
		Workspace* workspace = ServiceProvider::find<Workspace>(context);
		if (workspace && (context == workspace || context->isDescendentOf(workspace)))
			return workspace->getWorld();
		else
			return NULL;
	}

	bool Workspace::contextInWorkspace(const Instance* context)
	{
		return getWorkspaceIfInWorkspace(context) != NULL;
	}

	Workspace* Workspace::getWorkspaceIfInWorkspace(const Instance* context)
	{
		Workspace* workspace = ServiceProvider::find<Workspace>(context);
		if (workspace && (context == workspace || context->isDescendentOf(workspace)))
			return workspace;
		else
			return NULL;
	}

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

	void Workspace::onChildChanged(Instance* instance, const PropertyChanged& event)
	{
		Instance::onChildChanged(instance, event);
		raiseDrawChanged();
	}

	void Workspace::onDescendentRemoving(const boost::shared_ptr<Instance>& instance)
	{
		IRenderable* renderable = dynamic_cast<IRenderable*>(instance.get());
		if (renderable)
			onRemoving(renderable);

		RootInstance::onDescendentRemoving(instance);
		raiseDrawChanged();
	}

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

	void Workspace::runScript(Script* script, ScriptContext* context)
	{
		if (Network::Players::backendProcessing(this, true) && !isSimulating)
			pendingScripts.insert(script);
		else
			context->addScript(script);
	}

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

	void Workspace::makeJoints(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance>>> instances)
	{
		std::for_each(instances->begin(), instances->end(), &wrapper2<true>);
	}

	void Workspace::breakJoints(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance>>> instances)
	{
		std::for_each(instances->begin(), instances->end(), &wrapper2<false>);
	}

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

	Workspace::~Workspace()
	{
	}

	void Workspace::insertItems(XmlElement* root, std::vector<boost::shared_ptr<Instance>>& instances, InsertMode insertMode, PromptMode promptMode)
	{
		SerializerV2 serializer;
		serializer.loadInstances(root, instances);

		if (instances.size() > 0)
			insertInstances(instances, this, insertMode, promptMode);
	}

	void Workspace::insertContent(ContentId contentId, std::vector<boost::shared_ptr<Instance>>& items, InsertMode insertMode, PromptMode promptMode)
	{
		std::auto_ptr<std::istream> stream = ServiceProvider::create<ContentProvider>(this)->getContent(contentId);

		TextXmlParser machine(stream->rdbuf());
		std::auto_ptr<XmlElement> root = machine.parse();

		SerializerV2().loadInstances(root.get(), items);
		if (items.size() > 0)
			insertInstances(items, this, insertMode, promptMode);
	}

	void Workspace::start()
	{
		isSimulating = true;
		getCamera()->alwaysMode();

		if (scriptContext)
		{
			std::vector<boost::shared_ptr<Script> > startScripts;

			std::set<Script*>::const_iterator iter = pendingScripts.begin();
			std::set<Script*>::const_iterator end = pendingScripts.end();
			while (iter != end)
			{
				startScripts.push_back(shared_from(*iter));
				++iter;
			}

			pendingScripts.clear();

			std::for_each(startScripts.begin(), startScripts.end(),
				boost::bind(&ScriptContext::addScript, scriptContext, boost::bind(&boost::shared_ptr<Script>::get, _1)));
		}
	}

	void append(const boost::shared_ptr<Instance>& item, std::vector<boost::shared_ptr<Instance> >* values);

	boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > Workspace::insertContent(ContentId contentId)
	{
		std::vector<boost::shared_ptr<Instance> > items;
		insertContent(contentId, items, INSERT_TO_TREE, SUPPRESS_PROMPTS);

		boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > values(new std::vector<boost::shared_ptr<Instance> >());

		std::for_each(items.begin(), items.end(), boost::bind(&append, _1, values.get()));
		return values;
	}

	void Workspace::render2d(Adorn* adorn)
	{
		getCurrentMouseCommand()->render2d(adorn);
		render2dItems(adorn);
	}
}

template G3D::Array<boost::shared_ptr<RBX::PartInstance> >::~Array();

template boost::shared_ptr<RBX::Flag> RBX::Creatable<RBX::Instance>::create<RBX::Flag>();

#include "v8datamodel/DataModel.h"
#include "tool/MegaDragger.h"
#include "tool/AxisMoveTool.h"
#include "tool/AxisMoveGrid.h"
#include "StandardVerbs.h"

namespace RBX {
char sAxisMoveTool[] = "AxisMove";
AxisMoveTool::AxisMoveTool(Workspace* w) : Named<ArrowToolBase, sAxisMoveTool>(w), cursor("ArrowCursor"), dragging(false) {}
template<> MouseCommand* TToolVerb<AxisMoveTool, RunStateVerb>::newMouseCommand() {
    return new AxisMoveTool(dataModel->getWorkspace());
}
template<> const Name& Named<ArrowToolBase, sAxisMoveTool>::getName() const { return NativeToolName<AxisMoveTool>::get(); }
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
