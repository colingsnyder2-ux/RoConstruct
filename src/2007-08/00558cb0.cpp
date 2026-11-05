// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_workspace_family_e241b90818221a1c.cpp

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
#include "v8datamodel/Lighting.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/TimeState.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/JointsService.h"
#include "v8datamodel/LocalBackpack.h"
#include "script/ScriptContext.h"
#include "gui/GUI.h"
#include "util/Log.h"
#include "util/IMetric.h"
#include "util/standardout.h"
#include "util/Http.h"
#include "util/Sound.h"

namespace RBX
{
	static Reflection::BoundFuncDesc<DataModel, boost::shared_ptr<const std::vector<boost::shared_ptr<Instance>>>(ContentId), 1> getContentFunctionOld(&DataModel::get, "get", "url", Reflection::FunctionDescriptor::AnyCaller);
	static Reflection::BoundFuncDesc<DataModel, boost::shared_ptr<const std::vector<boost::shared_ptr<Instance>>>(ContentId), 1> getContentFunction(&DataModel::get, "GetObjects", "url", Reflection::FunctionDescriptor::AnyCaller);
	static Reflection::BoundFuncDesc<DataModel, void(ContentId), 1> loadFunction(&DataModel::loadContent, "Load", "url", Reflection::FunctionDescriptor::NeedTrustedCaller);
	static Reflection::BoundFuncDesc<DataModel, void(ContentId), 1> saveFunction(&DataModel::save, "Save", "url", Reflection::FunctionDescriptor::NeedTrustedCaller);
	static Reflection::BoundFuncDesc<DataModel, std::string(std::string, bool), 2> httpGetFunction(&DataModel::httpGet, "HttpGet", "url", "synchronous", Reflection::FunctionDescriptor::AnyCaller);
	static Reflection::BoundFuncDesc<DataModel, std::string(std::string, std::string, bool), 3> httpPostFunction(&DataModel::httpPost, "HttpPost", "url", "data", "synchronous", Reflection::FunctionDescriptor::NeedTrustedCaller);
	static Reflection::BoundFuncDesc<DataModel, void(void), 0> sanitizeFunction(&DataModel::clearContents, "ClearContent", Reflection::FunctionDescriptor::NeedTrustedCaller);
	static Reflection::BoundFuncDesc<DataModel, void(void), 0> closeFunction(&DataModel::close, "Close", Reflection::FunctionDescriptor::NeedTrustedCaller);

	static Reflection::BoundFuncDesc<DataModel, void(std::string), 1> func_SetUIMessage(&DataModel::setUiMessage, "SetMessage", "message", Reflection::FunctionDescriptor::NeedTrustedCaller);
	static Reflection::BoundFuncDesc<DataModel, void(void), 0> func_ClearUIMessage(&DataModel::clearUiMessage, "ClearMessage", Reflection::FunctionDescriptor::NeedTrustedCaller);
	static Reflection::BoundFuncDesc<DataModel, void(void), 0> func_SetUIMessageBrickCount(&DataModel::setUiMessageBrickCount, "SetMessageBrickCount", Reflection::FunctionDescriptor::NeedTrustedCaller);
	
	static Reflection::SignalDesc<DataModel, void(void)> event_Closing("Close");

#pragma warning (push)
#pragma warning (disable : 4355) // warning C4355: 'this' : used in base member initializer list

	DataModel::DataModel()
		: VerbContainer(NULL),
		  workspace(Creatable::create<Workspace>(this)),
		  guiRoot(Creatable::create<GuiRoot>()),
		  guiHooks(Creatable::create<GuiRoot>()),
		  timeState(new TimeState),
		  mutex(new boost::mutex),
		  guiTarget(NULL),
		  forceArrowCursor(true),
		  dirty(false),
		  closed(false)
	{
		setName("Level");
	}

#pragma warning (pop)

	DataModel::~DataModel()
	{
		Notifier<RunService, RunTransition>::disconnect(runService, this);
		StandardOut::singleton()->print(MESSAGE_INFO, "~DataModel");
	}

	bool DataModel::askAddChild(const Instance* instance) const
	{
		return dynamic_cast<const Service*>(instance) != NULL;
	}

	boost::shared_ptr<DataModel> DataModel::createDataModel()
	{
		ContentProvider::singleton().clearContentCache();
		
		boost::shared_ptr<DataModel> dataModel = Creatable::create<DataModel>();

		{
			Lock lock(dataModel);
			dataModel->initializeContents();
		}

		return dataModel;
	}
	
	void DataModel::onChildAdded(Instance* child)
	{
		ServiceProvider::onChildAdded(child);

		if (child->getClassName() == "NetworkClient")
		{
			Verb* lockPlayMode = getVerb("LockPlayMode");
			if (lockPlayMode)
				lockPlayMode->doIt(NULL);

			workspace->setNullMouseCommand();
		}
	}

	void DataModel::onEvent(const RunService* source, RunTransition event)
	{
		switch (event.newState)
		{
		case RS_NORMAL:
			if (event.oldState == RS_RUNNING)
				workspace->reset();

			timeState->clear();
			break;
		case RS_RUNNING:
			workspace->start();
			break;
		case RS_PAUSED:
			workspace->stop();
			break;
		}
	}

	std::string DataModel::doHttpGet(std::string url)
	{
		std::string result;
		Http(url.c_str()).get(result);

		return result;
	}

	std::string DataModel::doHttpPost(std::string url, std::string data)
	{
		std::string result;
		Http(url).post(std::istringstream(data), true, result);

		return result;
	}

	void DataModel::close()
	{
		Verb* exitVerb = getVerb("Exit");
		if (!exitVerb)
			throw std::runtime_error("Couldn\'t find Exit Verb");

		exitVerb->doIt(NULL);
	}

	std::string DataModel::httpGet(std::string url, bool synchronous)
	{
		if (synchronous)
		{
			return doHttpGet(url);
		}
		else
		{
			if (url.size() > 0)
			{
				boost::function0<void> f = boost::bind(&DataModel::doHttpGet, url);
				boost::function0<void> g = boost::bind(&StandardOut::print_exception, f, MESSAGE_ERROR, false);

				boost::thread(background_function(g, "rbx_httpGet"));
			}

			return "";
		}
	}

	std::string DataModel::httpPost(std::string url, std::string data, bool synchronous)
	{
		if (synchronous)
		{
			return doHttpPost(url, data);
		}
		else
		{
			boost::function0<void> f = boost::bind(&DataModel::doHttpPost, url, data);
			boost::function0<void> g = boost::bind(&StandardOut::print_exception, f, MESSAGE_ERROR, false);

			boost::thread(background_function(g, "rbx_httpPost"));

			return "";
		}
	}

	void DataModel::clearContents()
	{
		workspace->setMouseCommand(NULL);
		workspace->removeAllChildren();
		workspace->setCamera(NULL);
		
		starterPackService->removeAllChildren();

		Teams* teams = ServiceProvider::find<Teams>(this);
		if (teams)
			teams->removeAllChildren();

		Lighting* lighting = ServiceProvider::find<Lighting>(this);
		if (lighting)
			lighting->removeAllChildren();

		ScriptContext* script = ServiceProvider::find<ScriptContext>(this);
		if (script)
		{
			script->closeState();
			ScriptContext::propScriptsDisabled.setValue(script, false);
		}
	}

	void DataModel::loadContent(ContentId contentId)
	{
		std::auto_ptr<std::istream> stream = ContentProvider::singleton().getContent(contentId);
		StandardOut::singleton()->print(MESSAGE_INFO, "DataModel Loading %s", contentId.c_str());

		SerializerV2 serializer;
		serializer.load(*stream, this);

		workspace->joinAllHack();
	}

	void DataModel::save(ContentId contentId)
	{
		std::stringstream stream;

		{
			boost::scoped_ptr<XmlElement> root(SerializerV2::newRootElement());
			writeChildren(root.get());

			TextXmlWriterWithEmbeddedContent machine(stream);
			machine.serialize(root.get());

			stream.flush();
		}
		
		std::string response;
		Http(contentId.toString()).post(stream, true, response);
	}

	boost::shared_ptr<const std::vector<boost::shared_ptr<Instance>>> DataModel::get(ContentId contentId)
	{
		std::auto_ptr<std::istream> stream = ContentProvider::singleton().getContent(contentId);

		TextXmlParser machine(stream->rdbuf());
		std::auto_ptr<XmlElement> root = machine.parse();

		boost::shared_ptr<std::vector<boost::shared_ptr<Instance>>> result(new std::vector<boost::shared_ptr<Instance>>);

		SerializerV2 serializer;
		serializer.loadInstances(root.get(), *result);

		return result;
	}

	static std::string report(const G3D::Stopwatch& timer)
	{
		if (timer.smoothElapsedTime() > 0.0f)
		{
			std::string t = Log::formatTime(timer.smoothElapsedTime());
			char buffer[256];
			sprintf(buffer, "%s (%.3gfps)", t.c_str(), 1.0f / timer.smoothElapsedTime());

			return std::string(buffer);
		}
		else
		{
			return Log::formatTime(timer.smoothElapsedTime());
		}
	}


	void DataModel::Lock::doLock(const DataModel* dataModel)
	{
		if (dataModel)
		{
			mutex = dataModel->mutex;
			lock = new boost::mutex::scoped_lock(*mutex);
		}
	}

	DataModel::Lock::~Lock()
	{
		delete lock;
	}
}
