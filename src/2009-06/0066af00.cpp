// from server: 100% by EspClaude
// from server: 96% by EspClaude
// roc 2009-06 0066af00  unit: RBX::Humanoid  size: 151 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0066af00
//
// 0066af00  56                   push esi
// 0066af01  57                   push edi
// 0066af02  8bf9                 mov edi, ecx
// 0066af04  57                   push edi
// 0066af05  e86642e5ff           call 0x4bf170
// 0066af0a  57                   push edi
// 0066af0b  8bf0                 mov esi, eax
// 0066af0d  e89e19e6ff           call 0x4cc8b0
// 0066af12  83c408               add esp, 8
// 0066af15  85c0                 test eax, eax
// 0066af17  7424                 je 0x66af3d
// 0066af19  6a00                 push 0
// 0066af1b  6888619e00           push 0x9e6188
// 0066af20  6840be9d00           push 0x9dbe40
// 0066af25  6a00                 push 0
// 0066af27  50                   push eax
// 0066af28  e84ded0a00           call 0x719c7a
// 0066af2d  83c414               add esp, 0x14
// 0066af30  85c0                 test eax, eax
// 0066af32  7409                 je 0x66af3d
// 0066af34  8bc8                 mov ecx, eax
// 0066af36  e805d3ffff           call 0x668240
// 0066af3b  eb02                 jmp 0x66af3f
// 0066af3d  33c0                 xor eax, eax
// 0066af3f  3bf8                 cmp edi, eax
// 0066af41  7551                 jne 0x66af94
// 0066af43  8b8618010000         mov eax, dword ptr [esi + 0x118]
// 0066af49  8b5004               mov edx, dword ptr [eax + 4]
// 0066af4c  81c618010000         add esi, 0x118
// 0066af52  8bce                 mov ecx, esi
// 0066af54  ffd2                 call edx
// 0066af56  83b83c01000005       cmp dword ptr [eax + 0x13c], 5
// 0066af5d  7535                 jne 0x66af94
// 0066af5f  53                   push ebx
// 0066af60  85ff                 test edi, edi
// 0066af62  7408                 je 0x66af6c
// 0066af64  8d9f3c010000         lea ebx, [edi + 0x13c]
// 0066af6a  eb02                 jmp 0x66af6e
// 0066af6c  33db                 xor ebx, ebx
// 0066af6e  8b06                 mov eax, dword ptr [esi]
// 0066af70  8b5004               mov edx, dword ptr [eax + 4]
// 0066af73  8bce                 mov ecx, esi
// 0066af75  ffd2                 call edx
// 0066af77  8bc8                 mov ecx, eax
// 0066af79  e8e2e8feff           call 0x659860
// 0066af7e  3bc3                 cmp eax, ebx
// 0066af80  5b                   pop ebx
// 0066af81  7411                 je 0x66af94
// 0066af83  8b06                 mov eax, dword ptr [esi]
// 0066af85  8b5004               mov edx, dword ptr [eax + 4]
// 0066af88  57                   push edi
// 0066af89  8bce                 mov ecx, esi
// 0066af8b  ffd2                 call edx
// 0066af8d  8bc8                 mov ecx, eax
// 0066af8f  e83cfefeff           call 0x65add0
// 0066af94  5f                   pop edi
// 0066af95  5e                   pop esi
// 0066af96  c3                   ret 

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
	char pad[0x13c];
	CameraType cameraType;
	CameraType getCameraType() const { return cameraType; }
	ICameraSubject* getCameraSubject() const;
	void setCameraSubject(Instance* subject);
};
class ICameraOwner { public: virtual ~ICameraOwner(); virtual Camera* getCamera() const = 0; };
class WorkspaceBase { public: virtual ~WorkspaceBase(); char pad[0x114]; };
class Workspace : public WorkspaceBase, public ICameraOwner {};
class HumanoidBase : public Instance { public: char hpad[0xc]; };
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
