// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_workspace_family_1ff0161c2394692a.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8world/Edge.h", "../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp")
#pragma include_alias(<v8world/Edge.h>, <../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp>)
#pragma include_alias("v8world/Contact.h", "../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp")
#pragma include_alias(<v8world/Contact.h>, <../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp>)
#define _MT 1
#define _DLL 1
#pragma include_alias("v8kernel/KernelIndex.h", "../roc_espeon_aug2007_kernelindex_header_d7778b4d74bcf4c0.cpp")
#pragma include_alias("v8kernel/Body.h", "../roc_espeon_aug2007_body_header_b251c002665e01af.cpp")
#pragma include_alias("util/Extents.h", "../roc_espeon_aug2007_extents_inline_58e475d56d206314.cpp")
#pragma include_alias("reflection/object.h", "../roc_espeon_aug2007_describedbase_e64c736f24da029d.cpp")
#pragma include_alias("util/Debug.h", "../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp")
#pragma include_alias(<util/Debug.h>, <../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp>)
#pragma include_alias("util/Events.h", "../roc_espeon_aug2007_datamodel_header_e4d5a36bea2e4f16.cpp")
#pragma include_alias("reflection/reflection.h", "../roc_espeon_aug2007_described_arg_header_14221fd67bb3ca43.cpp")
#pragma include_alias("v8tree/Instance.h", "../roc_espeon_aug2007_instance_header_47f25dc9e4368119.cpp")
#pragma include_alias("v8datamodel/PartInstance.h", "../roc_espeon_aug2007_part_flags_header_a6acc69782cd7c29.cpp")
#pragma include_alias("v8world/Primitive.h", "../roc_espeon_aug2007_primitive_trivial_header_ac300ff64c6fc5e6.cpp")
#pragma include_alias("v8datamodel/DataModel.h", "../roc_espeon_aug2007_datamodel_mutex_header_321a3c67de644a82.cpp")
#pragma include_alias("v8tree/Verb.h", "../roc_espeon_aug2007_datamodel_header_c06d28d1a6b724f6.cpp")
#pragma include_alias("util/Evaluator.h", "../roc_espeon_aug2007_datamodel_header_4ba4cf67c400aa66.cpp")
#pragma include_alias(<boost/signals/signal_template.hpp>, <../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp>)
#pragma include_alias("boost/signals/signal_template.hpp", "../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp")
#include "roc_espeon_boost133_header_d432d72f8740aec3.cpp"
#include "roc_espeon_boost133_header_d9eb4711b7fc841c.cpp"
#include "roc_espeon_boost133_signals_header_be197e98651271fa.cpp"

#pragma include_alias("v8world/Joint.h", "../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp")
#pragma include_alias(<v8world/Joint.h>, <../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp>)
#pragma include_alias("v8world/IPipelined.h", "../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp")
#pragma include_alias(<v8world/IPipelined.h>, <../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp>)
#pragma include_alias("v8world/Joint.h", "../roc_espeon_aug2007_joint_accessor_header_d77e5f1c0b32672c.cpp")
#pragma include_alias(<v8world/Joint.h>, <../roc_espeon_aug2007_joint_accessor_header_d77e5f1c0b32672c.cpp>)
#pragma include_alias("util/IRenderable.h", "../roc_espeon_aug2007_bucket_header_1deff476fbc5a7ac.cpp")
#pragma include_alias(<util/IRenderable.h>, <../roc_espeon_aug2007_bucket_header_1deff476fbc5a7ac.cpp>)
#pragma include_alias("v8datamodel/JointInstance.h", "../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp")
#pragma include_alias(<v8datamodel/JointInstance.h>, <../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp>)
#pragma include_alias("v8world/IMoving.h", "../roc_espeon_aug2007_imoving_header_a7323a6be498a3c4.cpp")
#pragma include_alias(<v8world/IMoving.h>, <../roc_espeon_aug2007_imoving_header_a7323a6be498a3c4.cpp>)
#pragma include_alias("v8kernel/IStage.h", "../roc_espeon_aug2007_istage_header_b0262a91d28a95d1.cpp")
#pragma include_alias(<v8kernel/IStage.h>, <../roc_espeon_aug2007_istage_header_b0262a91d28a95d1.cpp>)
#pragma include_alias("reflection/function.h", "../roc_espeon_aug2007_abstract_header_991b5e9635f5d75d.cpp")
#pragma include_alias(<reflection/function.h>, <../roc_espeon_aug2007_abstract_header_991b5e9635f5d75d.cpp>)
#pragma include_alias("reflection/member.h", "../roc_espeon_aug2007_abstract_header_56ab3d07f46302ce.cpp")
#pragma include_alias(<reflection/member.h>, <../roc_espeon_aug2007_abstract_header_56ab3d07f46302ce.cpp>)
#pragma include_alias("reflection/property.h", "../roc_espeon_aug2007_abstract_header_4b7af236c124d7bd.cpp")
#pragma include_alias(<reflection/property.h>, <../roc_espeon_aug2007_abstract_header_4b7af236c124d7bd.cpp>)
#pragma include_alias("reflection/signal.h", "../roc_espeon_aug2007_abstract_header_35400af2df14a7cc.cpp")
#pragma include_alias(<reflection/signal.h>, <../roc_espeon_aug2007_abstract_header_35400af2df14a7cc.cpp>)
#pragma include_alias("script/Script.h", "../roc_espeon_aug2007_abstract_header_206648adc176eff8.cpp")
#pragma include_alias(<script/Script.h>, <../roc_espeon_aug2007_abstract_header_206648adc176eff8.cpp>)
#pragma include_alias("util/ICameraSubject.h", "../roc_espeon_aug2007_abstract_header_15846f007cad7f25.cpp")
#pragma include_alias(<util/ICameraSubject.h>, <../roc_espeon_aug2007_abstract_header_15846f007cad7f25.cpp>)
#pragma include_alias("util/IControllable.h", "../roc_espeon_aug2007_abstract_header_134fb1e5a9dd6b81.cpp")
#pragma include_alias(<util/IControllable.h>, <../roc_espeon_aug2007_abstract_header_134fb1e5a9dd6b81.cpp>)
#pragma include_alias("util/ILocation.h", "../roc_espeon_aug2007_abstract_header_b220b165aaf2f641.cpp")
#pragma include_alias(<util/ILocation.h>, <../roc_espeon_aug2007_abstract_header_b220b165aaf2f641.cpp>)
#pragma include_alias("v8datamodel/ICameraOwner.h", "../roc_espeon_aug2007_abstract_header_328a7f313eb894b0.cpp")
#pragma include_alias(<v8datamodel/ICameraOwner.h>, <../roc_espeon_aug2007_abstract_header_328a7f313eb894b0.cpp>)
#pragma include_alias("v8datamodel/ICharacterSubject.h", "../roc_espeon_aug2007_abstract_header_72d3fec55ed90c1f.cpp")
#pragma include_alias(<v8datamodel/ICharacterSubject.h>, <../roc_espeon_aug2007_abstract_header_72d3fec55ed90c1f.cpp>)
#pragma include_alias("v8datamodel/IPrimaryPart.h", "../roc_espeon_aug2007_abstract_header_d558c6e252d36c0e.cpp")
#pragma include_alias(<v8datamodel/IPrimaryPart.h>, <../roc_espeon_aug2007_abstract_header_d558c6e252d36c0e.cpp>)
#pragma include_alias("v8datamodel/PVInstance.h", "../roc_espeon_aug2007_abstract_header_e7c5a66547093118.cpp")
#pragma include_alias(<v8datamodel/PVInstance.h>, <../roc_espeon_aug2007_abstract_header_e7c5a66547093118.cpp>)
#pragma include_alias("v8tree/Service.h", "../roc_espeon_aug2007_abstract_header_cf6415ca14eaa52c.cpp")
#pragma include_alias(<v8tree/Service.h>, <../roc_espeon_aug2007_abstract_header_cf6415ca14eaa52c.cpp>)
#pragma include_alias("util/UIEvent.h", "../roc_espeon_aug2007_uievent_header_3f3774ebe50da7af.cpp")
#pragma include_alias(<util/UIEvent.h>, <../roc_espeon_aug2007_uievent_header_3f3774ebe50da7af.cpp>)
#pragma include_alias("v8datamodel/Workspace.h", "../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp")
#pragma include_alias(<v8datamodel/Workspace.h>, <../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp>)
#include "v8datamodel/Workspace.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/MouseCommand.h"
#include "v8datamodel/Flag.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/Selection.h"
#include "script/ScriptContext.h"
#include "humanoid/Humanoid.h"
#include "v8world/World.h"
#include "tool/NullTool.h"
#include "tool/ToolsArrow.h"
#include "Network/Players.h"

namespace RBX
{
	static void recomputeRenderable(Instance* instance)
	{
		if (IRenderable* renderable = dynamic_cast<IRenderable*>(instance))
			renderable->shouldRenderSetDirty();
	}

	void Workspace::recomputeAllShouldRender()
	{
		visitChildren(&recomputeRenderable);
	}

	static Reflection::RefPropDescriptor<Workspace, Camera> currentCameraProxyProp("CurrentCamera", "Data", &Workspace::getCamera, &Workspace::setCamera, Reflection::PropertyDescriptor::STANDARD);

	static Reflection::BoundFuncDesc<Workspace, boost::shared_ptr<const std::vector<boost::shared_ptr<Instance>>>(ContentId), 1> workspace_insertContent(&Workspace::insertContent, "InsertContent", "url", Reflection::FunctionDescriptor::NeedTrustedCaller);
	static Reflection::BoundFuncDesc<Workspace, void(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance>>>), 1> workspace_makeJoints(&Workspace::makeJoints, "MakeJoints", "objects", Reflection::FunctionDescriptor::NeedTrustedCaller);
	static Reflection::BoundFuncDesc<Workspace, void(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance>>>), 1> workspace_breakJoints(&Workspace::breakJoints, "BreakJoints", "objects", Reflection::FunctionDescriptor::NeedTrustedCaller);
	static Reflection::BoundFuncDesc<Workspace, void(bool), 1> workspace_SetThrottleEnabled(&Workspace::setThrottleEnabled, "SetPhysicsThrottleEnabled", "value", Reflection::FunctionDescriptor::NeedTrustedCaller);
	static Reflection::BoundFuncDesc<Workspace, void(void), 0> workspace_zoomToExtents(&Workspace::zoomToExtents, "ZoomToExtents", Reflection::FunctionDescriptor::NeedTrustedCaller);

	Workspace::Workspace(IDataState* dataState)
		: VerbContainer(NULL),
		  dataState(dataState),
		  profileWorkspaceStep(new Profiling::CodeProfiler("DataModel Step")),
		  profileRunServiceStepped(new Profiling::CodeProfiler("RunService Stepped")),
		  profileRunServiceHeartbeat(new Profiling::CodeProfiler("RunService Heartbeat")),
		  profileRun(new Profiling::ThreadProfiler("Run Thread")),
		  arrowCameraControls(false),
		  isSimulating(false),
		  scriptContext(NULL),
		  imageServerViewHack(0)
	{
		RBXASSERT(dataState);
		setName("Workspace");

		world->getProfileWorldStep().parent = profileWorkspaceStep.get();
		profileRunServiceStepped->parent = profileWorkspaceStep.get();
		profileRunServiceHeartbeat->parent = profileWorkspaceStep.get();
	}

	Workspace::~Workspace() {}

	bool Workspace::askAddChild(const Instance* instance) const
	{
		return dynamic_cast<const IRenderable*>(instance) != NULL;
	}

	const G3D::GCamera& Workspace::getGCamera() const
	{
		RBXASSERT(getCamera());
		return getCamera()->getGCamera();
	}

	void Workspace::zoomToExtents()
	{
		getCamera()->zoomExtents(viewPort);
	}

	void Workspace::insertItems(XmlElement* root, std::vector<boost::shared_ptr<Instance>>& instances, InsertMode insertMode, PromptMode promptMode)
	{
		RBXASSERT(instances.size() == 0);

		SerializerV2 serializer;
		serializer.loadInstances(root, instances);

		if (instances.size() != 0)
			insertInstances(instances, this, insertMode, promptMode);
	}

	void Workspace::stop()
	{
		RBXASSERT(isSimulating);
		isSimulating = false;

		getCamera()->autoMode();
		RBXASSERT(!getCurrentMouseCommand()->captured());
	}

	MouseCommand* newNullTool(Workspace* workspace)
	{
		return new NewNullTool(workspace);
	}

	void Workspace::setNullMouseCommand()
	{
		stickyCommand.reset();
		currentCommand.reset(newNullTool(this));
	}

	void Workspace::render2d(Adorn* adorn)
	{
		getCurrentMouseCommand()->render2d(adorn);
		render2dItems(adorn);
	}

	void Workspace::setThrottleEnabled(bool value)
	{
		world->setCanThrottle(value);
	}

	void Workspace::joinAllHack()
	{
		world->joinAll();
	}

	void Workspace::reset()
	{
		stop();
		world->reset();
	}

	Camera* Workspace::getCamera() const
	{
		if (!currentCamera || !currentCamera->isDescendentOf(this))
		{
			boost::shared_ptr<Camera> newCamera = Creatable::create<Camera>();
			newCamera->setParent(const_cast<Workspace*>(this));
			currentCamera = newCamera;
		}

		RBXASSERT(currentCamera->isDescendentOf(this));
		return currentCamera.get();
	}

	void Workspace::onChildChanged(Instance* instance, const PropertyChanged& event)
	{
		Instance::onChildChanged(instance, event);
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
			RBXASSERT(instance->getParent() == this);

			pvInstance->legacyTraverseState(G3D::CoordinateFrame());
			pvInstance->clearLegacyOffset();
			if (legacyOffset)
				legacyOffset.reset();
		}
	}

	void Workspace::onDescendentRemoving(const boost::shared_ptr<Instance>& instance)
	{
		IRenderable* renderable = dynamic_cast<IRenderable*>(instance.get());
		if (renderable)
			onRemoving(renderable);

		RootInstance::onDescendentRemoving(instance);
		raiseDrawChanged();
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

		RBXASSERT(newMouseCommand);

		if (newMouseCommand != currentCommand.get())
		{
			RBXASSERT(!currentCommand.get() || !currentCommand->captured());

			currentCommand.reset(newMouseCommand);

			MouseCommand* sticky = newMouseCommand->isSticky();
			if (sticky)
				stickyCommand.reset(sticky);

			Notifier<Workspace, ToolChanged>::raise(ToolChanged());
		}
	}

	float Workspace::step(float timeInterval)
	{
		RBXASSERT(isSimulating);

		timeInterval = world->step(timeInterval);
		
		G3D::Array<boost::shared_ptr<PartInstance>> touchParts;
		G3D::Array<boost::shared_ptr<PartInstance>> touchOtherParts;
		G3D::Array<Primitive*> fallen;
		G3D::Array<boost::shared_ptr<PartInstance>> fallenParts;

		PartInstance::primitivesToParts(world->getTouch(), touchParts);
		PartInstance::primitivesToParts(world->getTouchOther(), touchOtherParts);
		world->computeFallen(fallen);
		PartInstance::primitivesToParts(fallen, fallenParts);
		
		handleFallenParts(fallenParts);

		for (int i = 0; i < touchParts.size(); i++)
		{
			touchParts[i]->onTouchThisStep(touchOtherParts[i]);
		}

		raiseDrawChanged();
		return timeInterval;
	}

	void Workspace::setDefaultMouseCommand()
	{
		stickyCommand.reset();
		setMouseCommand(NULL);
	}

	void Workspace::runScript(Script* script, ScriptContext* context)
	{
		RBXASSERT(context == scriptContext);

		if (Network::Players::backendProcessing(this, true) && !isSimulating)
			pendingScripts.insert(script);
		else
			context->addScript(script);
	}

	void Workspace::releaseScript(Script* script)
	{
		pendingScripts.erase(script);
	}

	Workspace* Workspace::findWorkspace(const Instance* context)
	{
		return ServiceProvider::find<Workspace>(context);
	}

	Workspace* Workspace::getWorkspaceIfInWorkspace(const Instance* context)
	{
		Workspace* workspace = ServiceProvider::find<Workspace>(context);

		if (workspace && (context == workspace || context->isDescendentOf(workspace)))
			return workspace;
		else
			return NULL;
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

	void Workspace::setCamera(Camera* value)
	{
		if (value != currentCamera.get())
		{
			if (currentCamera)
				currentCamera->setParent(NULL);

			currentCamera = shared_from(value);
			raisePropertyChanged(currentCameraProxyProp);
		}
	}

	Workspace* Workspace::getMyWorkspaceFast(const Instance* context)
	{
		RBXASSERT(getWorldIfInWorkspace(context));

		Instance* parent = context->getParent();
		RBXASSERT(parent);

		Instance* parent2 = parent->getParent();
		RBXASSERT(parent2);

		while (parent2->getParent())
		{
			parent = parent2;
			parent2 = parent2->getParent();
		}

		return rbx_static_cast<Workspace*>(parent);
	}

	World* Workspace::getMyWorldFast(const Instance* context)
	{
		return getMyWorkspaceFast(context)->getWorld();
	}

	//94% match
	//std::set<>::clear is being inlined more aggressively
	void Workspace::start()
	{
		RBXASSERT(!isSimulating);
		isSimulating = true;

		getCamera()->alwaysMode();

		RBXASSERT(!getCurrentMouseCommand()->captured());

		if (scriptContext)
		{
			std::vector<boost::shared_ptr<Script>> startScripts;

			std::set<Script*>::const_iterator iter = pendingScripts.begin();
			std::set<Script*>::const_iterator end = pendingScripts.end();

			for (; iter != end; iter++)
			{
				startScripts.push_back(shared_from(*iter));
			}

			pendingScripts.clear();
			std::for_each(startScripts.begin(), startScripts.end(), boost::bind(&ScriptContext::addScript, scriptContext, boost::bind(&boost::shared_ptr<Script>::get, _1)));
		}
	}

	void Workspace::setImageServerView(const G3D::Rect2D& viewPortRect)
	{
		HopperBin* superHack = NULL;

		for (size_t i = 0; i < numChildren(); i++)
		{
			HopperBin* hopperBin = queryTypedChild<HopperBin>((int)i);
			ILocation* location = queryTypedChild<ILocation>((int)i);
			IRenderable* renderable = queryTypedChild<IRenderable>((int)i);

			if (location && renderable)
			{
				G3D::CoordinateFrame modelCoord = location->getLocation();
				getCamera()->setImageServerViewNoLerp(modelCoord, viewPortRect); 
			}

			if (hopperBin)
				superHack = hopperBin;
		}

		if (superHack)
		{
			StarterPackService* starterPack = ServiceProvider::create<StarterPackService>(this);
			superHack->setParent(starterPack);
		}

		imageServerViewHack = (imageServerViewHack <= 0);
	}

	static void append(const boost::shared_ptr<Instance>& item, std::vector<boost::shared_ptr<Instance>>* values)
	{
		values->push_back(item);
	}

	boost::shared_ptr<const std::vector<boost::shared_ptr<Instance>>> Workspace::insertContent(ContentId contentId)
	{
		std::vector<boost::shared_ptr<Instance>> items;
		insertContent(contentId, items, INSERT_TO_TREE, SUPPRESS_PROMPTS);

		boost::shared_ptr<std::vector<boost::shared_ptr<Instance>>> values(new std::vector<boost::shared_ptr<Instance>>);
		std::for_each(items.begin(), items.end(), boost::bind(&append, _1, values.get()));

		return values;
	}

	void Workspace::insertContent(ContentId contentId, std::vector<boost::shared_ptr<Instance>>& items, InsertMode insertMode, PromptMode promptMode)
	{
		std::auto_ptr<std::istream> stream = ContentProvider::singleton().getContent(contentId);

		TextXmlParser machine(stream->rdbuf());
		std::auto_ptr<XmlElement> root = machine.parse();

		insertItems(root.get(), items, insertMode, promptMode);
	}

	void Workspace::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		Notifier<RunService, Heartbeat>::disconnect(ServiceProvider::find<RunService>(oldProvider), this);

		if (statsItem)
		{
			statsItem->setParent(NULL);
			statsItem.reset();
		}

		Instance::onServiceProvider(oldProvider, newProvider);

		scriptContext = ServiceProvider::create<ScriptContext>(newProvider);

		if (Stats::Item* item = ServiceProvider::create<Stats::Item>(newProvider))
		{
			statsItem = Creatable::create<WorkspaceStatsItem>(this, world.get());
			statsItem->setParent(item);
		}

		Notifier<RunService, Heartbeat>::connect(ServiceProvider::find<RunService>(newProvider), this);
	}

	static void DrawAdorn(boost::shared_ptr<Instance> wsi, Adorn* adorn, SelectState selectState, Workspace* workspace)
	{
		if (IRenderable* ir = dynamic_cast<IRenderable*>(wsi.get()))
		{
			if (workspace->contains(wsi.get()))
			{
				ir->render3dSelect(adorn, selectState);
			}
		}
	}

	void Workspace::render3dAdorn(Adorn* adorn)
	{
		viewPort = adorn->getViewport();
		ServiceClient<Selection> sel(this);

		if (sel)
			std::for_each(sel->getSelection()->begin(), sel->getSelection()->end(), boost::bind(&DrawAdorn, _1, adorn, SELECT_NORMAL, this));

		render3dAdornItems(adorn);
		if (showWorldCoord)
		{
			adorn->setObjectToWorldMatrix(G3D::CoordinateFrame());
			adorn->axes(G3D::Color3::red(), G3D::Color3::green(), G3D::Color3::blue(), 50.0f);
		}

		if (showHashGrid)
		{
			adorn->setObjectToWorldMatrix(G3D::CoordinateFrame());
			adorn->box(G3D::AABox(G3D::Vector3(28, 4, 12), G3D::Vector3(32, 8, 16)), G3D::Color4(1.0, 0.2, 0.2, 0.5), G3D::Color4::clear());
		}
	}
}
