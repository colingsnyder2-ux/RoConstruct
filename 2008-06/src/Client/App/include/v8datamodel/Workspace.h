#pragma once
#include "v8datamodel/RootInstance.h"
#include "v8datamodel/Stats.h"
#include "v8tree/Verb.h"
#include "script/Script.h"
#include "v8world/IMoving.h"
#include "gui/GuiEvent.h"
#include "util/RunStateOwner.h"
#include "util/ContentProvider.h"
#include "util/Profiling.h"
#include "util/UIEvent.h"

namespace RBX
{
	class MouseCommand;
	class Camera;

	class DrawChanged
	{
	};

	class ToolChanged
	{
	};

	extern char* sWorkspace;
	class Workspace : public DescribedNonCreatable<Workspace, RootInstance, &sWorkspace>,
					  public Service,
					  public GuiTarget,
					  public VerbContainer,
					  public IRenderableBucket,
					  public IMovingManager,
					  public IScriptOwner,
					  public Notifier<Workspace, DrawChanged>,
					  public Notifier<Workspace, ToolChanged>,
					  public Listener<RunService, Heartbeat>
	{
	private:
		boost::shared_ptr<Instance> statsItem;
		IDataState* dataState;
		bool arrowCameraControls;
		std::auto_ptr<MouseCommand> currentCommand;
		std::auto_ptr<MouseCommand> stickyCommand;
		UIEvent idleMouseEvent;
		void* unknown0x3cc; // 0x3cc = 0; name and type unknown
		bool isSimulating;
		std::set<Script*> pendingScripts;
		ScriptContext* scriptContext;
		bool inMouselookMode;
		mutable boost::shared_ptr<Camera> currentCamera;
		boost::shared_ptr<Camera> cameraTemplate;
		double unknown0x410[3]; // 0x410..0x428, zeroed by the constructor; names unknown
	public:
		boost::scoped_ptr<Profiling::CodeProfiler> profileWorkspaceStep; // "DataModel Step"
		boost::scoped_ptr<Profiling::CodeProfiler> profileWorkspaceStepInner; // "Workspace Step"
		boost::scoped_ptr<Profiling::CodeProfiler> profileWorkspaceAssemble; // "Workspace Assemble"
		boost::scoped_ptr<Profiling::CodeProfiler> profileRunServiceStepped;
		boost::scoped_ptr<Profiling::CodeProfiler> profileRunServiceHeartbeat;
		int imageServerViewHack;

	public:
		static bool showWorldCoord;
		static bool showHashGrid;
	  
	private:
		virtual bool askAddChild(const Instance* instance) const;
		virtual void onChildChanged(Instance* instance, const PropertyChanged& event);
		virtual void onDescendentAdded(Instance* instance);
		virtual void onDescendentRemoving(const boost::shared_ptr<Instance>& instance);
		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);
	public:
		void setCursor(Adorn*);
		virtual void render2d(Adorn* adorn);
		virtual void render3dAdorn(Adorn* adorn);
		virtual void render3dSelect(Adorn* adorn, SelectState selectState)
		{
			return;
		}
	private:
		virtual IScriptOwner* scriptShouldRun(Script* script);
		virtual void runScript(Script* script, ScriptContext* context);
		virtual void releaseScript(Script* script);
		virtual Extents computeCameraOwnerExtents()
		{
			return getExtentsWorld();
		}
		virtual void cameraMoved()
		{
			raiseDrawChanged();
		}
		virtual void onExtentsChanged() const
		{
			ModelInstance::onExtentsChanged();
			raiseDrawChanged();
		}
		virtual void onEvent(const RunService* source, Heartbeat event);
	public:
		Workspace(IDataState* dataState);
		virtual ~Workspace();
	public:
		World* getWorld() const
		{
			return world.get();
		}
		IDataState& getDataState() const
		{
			return *dataState;
		}
		MouseCommand* getCurrentMouseCommand()
		{
			RBXASSERT(currentCommand.get());
			return currentCommand.get();
		}
		void cancelMouseCommand();
		void setMouseCommand(MouseCommand* newMouseCommand);
		void setDefaultMouseCommand();
		void setNullMouseCommand();
		bool getInMouselookMode()
		{
			return inMouselookMode;
		}
		void setInMouselookMode(bool);
		virtual const G3D::GCamera& getGCamera() const;
		virtual Camera* getCamera() const;
		void setCamera(Camera* value);
	private:
		void checkCamera();
	public:
		void setImageServerView(const G3D::Rect2D& viewPortRect);
		void zoomToExtents();
		void onWrapMouse(const G3D::Vector2&);
		virtual GuiResponse process(const GuiEvent& event);
		void selectAll();
	private:
		void handleFallenParts(const G3D::Array<boost::shared_ptr<PartInstance>>& fallenParts);
	public:
		void start();
		void stop();
		void reset();
		float step(float timeInterval);
		void setThrottleEnabled(bool value);
		void joinAllHack();
		void insertItems(XmlElement* root, std::vector<boost::shared_ptr<Instance>>& instances, InsertMode insertMode, PromptMode promptMode);
		boost::shared_ptr<const std::vector<boost::shared_ptr<Instance>>> insertContent(ContentId contentId);
		void insertContent(ContentId contentId, std::vector<boost::shared_ptr<Instance>>& items, InsertMode insertMode, PromptMode promptMode);
		void makeJoints(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance>>> instances);
		void breakJoints(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance>>> instances);
		void raiseDrawChanged() const
		{
			Notifier<Workspace, DrawChanged>::raise(DrawChanged());
		}

	public:
		static Instance* findTopInstance(Instance*);
		static Workspace* findWorkspace(const Instance* context);
		static Workspace* getMyWorkspaceFast(const Instance* context);
		static World* getWorldIfInWorkspace(const Instance* context);
		static Workspace* getWorkspaceIfInWorkspace(const Instance* context);
		static bool contextInWorkspace(const Instance* context);
		static World* getMyWorldFast(const Instance* context);
	};
	
	class WorkspaceStatsItem : public Stats::Item
	{
	public:
		WorkspaceStatsItem(const Workspace*, const World*, const RunService*);
	};
}
