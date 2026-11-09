// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
class Instance { public: virtual ~Instance(); char pad[0x12c]; };
class Humanoid;
class ModelInstance : public Instance { public: template<class T> T* findFirstChildOfType() const; };
class ICameraSubject { public: virtual ~ICameraSubject(); };
class Camera
{
public:
	enum CameraType { FIXED, ATTACH, WATCH, TRACK, FOLLOW, CUSTOM_CAMERA };
	char pad[0x1d4];
	CameraType cameraType;
	CameraType getCameraType() const { return cameraType; }
	ICameraSubject* getCameraSubject() const;
	void setCameraSubject(Instance* subject);
};
class ICameraOwner { public: virtual ~ICameraOwner(); virtual Camera* getCamera() const = 0; };
class WorkspaceBase { public: virtual ~WorkspaceBase(); char pad[0x284]; };
class Workspace : public WorkspaceBase, public ICameraOwner {};
class HumanoidBase : public Instance { public: char hpad[0x1c]; };
class Humanoid : public HumanoidBase, public ICameraSubject
{
public:
	static Humanoid* modelIsCharacter(const ModelInstance* testModel)
	{
		return testModel ? testModel->findFirstChildOfType<Humanoid>() : 0;
	}
	void onLocalHumanoidEnteringWorkspace();
};
class ServiceProvider { public: template<class T> static T* find(const Instance* context); };
namespace Network { class Players { public: static Instance* findLocalCharacter(const Instance* context); }; }

void Humanoid::onLocalHumanoidEnteringWorkspace()
{
	Workspace* workspace = ServiceProvider::find<Workspace>(this);
	Instance* character = Network::Players::findLocalCharacter(this);
	ModelInstance* model = character ? dynamic_cast<ModelInstance*>(character) : 0;
	if (this == modelIsCharacter(model))
	{
		if (workspace->getCamera()->getCameraType() == Camera::CUSTOM_CAMERA && workspace->getCamera()->getCameraSubject() != this)
		{
			workspace->getCamera()->setCameraSubject(this);
		}
	}
}
}
