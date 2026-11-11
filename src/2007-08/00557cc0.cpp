// from server: 100% by EspClaude
// from server: 98% by EspClaude
// roc 2007-08 00557cc0  unit: RBX::DataModel  size: 781 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00557cc0
//
// 00557cc0  56                   push esi
// 00557cc1  57                   push edi
// 00557cc2  8bf9                 mov edi, ecx
// 00557cc4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00557cc8  8b01                 mov eax, dword ptr [ecx]
// 00557cca  83e807               sub eax, 7
// 00557ccd  0f8475010000         je 0x557e48
// 00557cd3  83e801               sub eax, 1
// 00557cd6  0f84b2000000         je 0x557d8e
// 00557cdc  83e801               sub eax, 1
// 00557cdf  756c                 jne 0x557d4d
// 00557ce1  8b4108               mov eax, dword ptr [ecx + 8]
// 00557ce4  83f830               cmp eax, 0x30
// 00557ce7  7e2e                 jle 0x557d17
// 00557ce9  83f839               cmp eax, 0x39
// 00557cec  7f29                 jg 0x557d17
// 00557cee  8b8f80010000         mov ecx, dword ptr [edi + 0x180]
// 00557cf4  83c0d0               add eax, -0x30
// 00557cf7  50                   push eax
// 00557cf8  e8338a0700           call 0x5d0730
// 00557cfd  84c0                 test al, al
// 00557cff  744c                 je 0x557d4d
// 00557d01  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00557d05  c70001000000         mov dword ptr [eax], 1
// 00557d0b  c7400400000000       mov dword ptr [eax + 4], 0
// 00557d12  5f                   pop edi
// 00557d13  5e                   pop esi
// 00557d14  c20800               ret 8
// 00557d17  83f82c               cmp eax, 0x2c
// 00557d1a  7f5a                 jg 0x557d76
// 00557d1c  7445                 je 0x557d63
// 00557d1e  83f808               cmp eax, 8
// 00557d21  7414                 je 0x557d37
// 00557d23  83f81b               cmp eax, 0x1b
// 00557d26  7525                 jne 0x557d4d
// 00557d28  8b8f90010000         mov ecx, dword ptr [edi + 0x190]
// 00557d2e  6a02                 push 2
// 00557d30  e84b5afdff           call 0x52d780
// 00557d35  eb16                 jmp 0x557d4d
// 00557d37  57                   push edi
// 00557d38  e803dbf3ff           call 0x495840
// 00557d3d  83c404               add esp, 4
// 00557d40  85c0                 test eax, eax
// 00557d42  7409                 je 0x557d4d
// 00557d44  50                   push eax
// 00557d45  e806a90700           call 0x5d2650
// 00557d4a  83c404               add esp, 4
// 00557d4d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00557d51  c70000000000         mov dword ptr [eax], 0
// 00557d57  c7400400000000       mov dword ptr [eax + 4], 0
// 00557d5e  5f                   pop edi
// 00557d5f  5e                   pop esi
// 00557d60  c20800               ret 8
// 00557d63  83ec1c               sub esp, 0x1c
// 00557d66  8bcc                 mov ecx, esp
// 00557d68  8964242c             mov dword ptr [esp + 0x2c], esp
// 00557d6c  68fc157900           push 0x7915fc
// 00557d71  e9e0000000           jmp 0x557e56
// 00557d76  83e82e               sub eax, 0x2e
// 00557d79  3dec000000           cmp eax, 0xec
// 00557d7e  77cd                 ja 0x557d4d
// 00557d80  0fb680e07e5500       movzx eax, byte ptr [eax + 0x557ee0]
// 00557d87  ff2485b87e5500       jmp dword ptr [eax*4 + 0x557eb8]
// 00557d8e  83ec1c               sub esp, 0x1c
// 00557d91  8bcc                 mov ecx, esp
// 00557d93  8964242c             mov dword ptr [esp + 0x2c], esp
// 00557d97  6874167900           push 0x791674
// 00557d9c  e9b5000000           jmp 0x557e56
// 00557da1  83ec1c               sub esp, 0x1c
// 00557da4  8bcc                 mov ecx, esp
// 00557da6  8964242c             mov dword ptr [esp + 0x2c], esp
// 00557daa  6824167900           push 0x791624
// 00557daf  e9a2000000           jmp 0x557e56
// 00557db4  83ec1c               sub esp, 0x1c
// 00557db7  8bcc                 mov ecx, esp
// 00557db9  8964242c             mov dword ptr [esp + 0x2c], esp
// 00557dbd  68d4157900           push 0x7915d4
// 00557dc2  e98f000000           jmp 0x557e56
// 00557dc7  83ec1c               sub esp, 0x1c
// 00557dca  8bcc                 mov ecx, esp
// 00557dcc  8964242c             mov dword ptr [esp + 0x2c], esp
// 00557dd0  68ac157900           push 0x7915ac
// 00557dd5  eb7f                 jmp 0x557e56
// 00557dd7  57                   push edi
// 00557dd8  e863daf3ff           call 0x495840
// 00557ddd  83c404               add esp, 4
// 00557de0  85c0                 test eax, eax
// 00557de2  0f8465ffffff         je 0x557d4d
// 00557de8  50                   push eax
// 00557de9  e8e29d0200           call 0x581bd0
// 00557dee  e957ffffff           jmp 0x557d4a
// 00557df3  8b8f80010000         mov ecx, dword ptr [edi + 0x180]
// 00557df9  e8224eebff           call 0x40cc20
// 00557dfe  e94affffff           jmp 0x557d4d
// 00557e03  8b8f80010000         mov ecx, dword ptr [edi + 0x180]
// 00557e09  e8124eebff           call 0x40cc20
// 00557e0e  e93affffff           jmp 0x557d4d
// 00557e13  83ec1c               sub esp, 0x1c
// 00557e16  83790c00             cmp dword ptr [ecx + 0xc], 0
// 00557e1a  8964242c             mov dword ptr [esp + 0x2c], esp
// 00557e1e  8bcc                 mov ecx, esp
// 00557e20  7513                 jne 0x557e35
// 00557e22  68686f7800           push 0x786f68
// 00557e27  ff1598e67700         call dword ptr [0x77e698]
// 00557e2d  8d8f4c010000         lea ecx, [edi + 0x14c]
// 00557e33  eb33                 jmp 0x557e68
// 00557e35  6890267900           push 0x792690
// 00557e3a  ff1598e67700         call dword ptr [0x77e698]
// 00557e40  8d8f4c010000         lea ecx, [edi + 0x14c]
// 00557e46  eb20                 jmp 0x557e68
// 00557e48  83ec1c               sub esp, 0x1c
// 00557e4b  8bcc                 mov ecx, esp
// 00557e4d  8964242c             mov dword ptr [esp + 0x2c], esp
// 00557e51  684c167900           push 0x79164c
// 00557e56  ff1598e67700         call dword ptr [0x77e698]
// 00557e5c  8b8788010000         mov eax, dword ptr [edi + 0x188]
// 00557e62  8d8884020000         lea ecx, [eax + 0x284]
// 00557e68  e8e3cc0000           call 0x564b50
// 00557e6d  8bf0                 mov esi, eax
// 00557e6f  85f6                 test esi, esi
// 00557e71  0f84d6feffff         je 0x557d4d
// 00557e77  8b16                 mov edx, dword ptr [esi]
// 00557e79  8b4208               mov eax, dword ptr [edx + 8]
// 00557e7c  8bce                 mov ecx, esi
// 00557e7e  ffd0                 call eax
// 00557e80  84c0                 test al, al
// 00557e82  0f84c5feffff         je 0x557d4d
// 00557e88  85ff                 test edi, edi
// 00557e8a  7408                 je 0x557e94
// 00557e8c  8d8760010000         lea eax, [edi + 0x160]
// 00557e92  eb02                 jmp 0x557e96
// 00557e94  33c0                 xor eax, eax
// 00557e96  8b16                 mov edx, dword ptr [esi]
// 00557e98  50                   push eax
// 00557e99  8b4210               mov eax, dword ptr [edx + 0x10]
// 00557e9c  8bce                 mov ecx, esi
// 00557e9e  ffd0                 call eax
// 00557ea0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00557ea4  5f                   pop edi
// 00557ea5  c70001000000         mov dword ptr [eax], 1
// 00557eab  c7400400000000       mov dword ptr [eax + 4], 0
// 00557eb2  5e                   pop esi
// 00557eb3  c20800               ret 8
// 00557eb6  8bff                 mov edi, edi
// 00557eb8  a17d5500d7           mov eax, dword ptr [0xd700557d]
// 00557ebd  7d55                 jge 0x557f14
// 00557ebf  0003                 add byte ptr [ebx], al
// 00557ec1  7e55                 jle 0x557f18
// 00557ec3  00f3                 add bl, dh
// 00557ec5  7d55                 jge 0x557f1c
// 00557ec7  00487e               add byte ptr [eax + 0x7e], cl
// 00557eca  55                   push ebp
// 00557ecb  008e7d5500b4         add byte ptr [esi - 0x4bffaa83], cl
// 00557ed1  7d55                 jge 0x557f28
// 00557ed3  00c7                 add bh, al
// 00557ed5  7d55                 jge 0x557f2c
// 00557ed7  0013                 add byte ptr [ebx], dl
// 00557ed9  7e55                 jle 0x557f30
// 00557edb  004d7d               add byte ptr [ebp + 0x7d], cl
// 00557ede  55                   push ebp
// 00557edf  0000                 add byte ptr [eax], al
// 00557ee1  0909                 or dword ptr [ecx], ecx
// 00557ee3  0909                 or dword ptr [ecx], ecx
// 00557ee5  0909                 or dword ptr [ecx], ecx
// 00557ee7  0909                 or dword ptr [ecx], ecx
// 00557ee9  0909                 or dword ptr [ecx], ecx
// 00557eeb  0909                 or dword ptr [ecx], ecx
// 00557eed  0909                 or dword ptr [ecx], ecx
// 00557eef  0109                 add dword ptr [ecx], ecx
// 00557ef1  0909                 or dword ptr [ecx], ecx
// 00557ef3  0909                 or dword ptr [ecx], ecx
// 00557ef5  0909                 or dword ptr [ecx], ecx
// 00557ef7  0909                 or dword ptr [ecx], ecx
// 00557ef9  0909                 or dword ptr [ecx], ecx
// 00557efb  0909                 or dword ptr [ecx], ecx
// 00557efd  0909                 or dword ptr [ecx], ecx
// 00557eff  0909                 or dword ptr [ecx], ecx
// 00557f01  0909                 or dword ptr [ecx], ecx
// 00557f03  0909                 or dword ptr [ecx], ecx
// 00557f05  0909                 or dword ptr [ecx], ecx
// 00557f07  0909                 or dword ptr [ecx], ecx
// 00557f09  0909                 or dword ptr [ecx], ecx
// 00557f0b  0909                 or dword ptr [ecx], ecx
// 00557f0d  0209                 add cl, byte ptr [ecx]
// 00557f0f  0309                 add ecx, dword ptr [ecx]
// 00557f11  0909                 or dword ptr [ecx], ecx
// 00557f13  0909                 or dword ptr [ecx], ecx
// 00557f15  0909                 or dword ptr [ecx], ecx
// 00557f17  0909                 or dword ptr [ecx], ecx
// 00557f19  0909                 or dword ptr [ecx], ecx
// 00557f1b  0409                 add al, 9
// 00557f1d  0909                 or dword ptr [ecx], ecx
// 00557f1f  0909                 or dword ptr [ecx], ecx
// 00557f21  0509090909           add eax, 0x9090909
// 00557f26  0909                 or dword ptr [ecx], ecx
// 00557f28  0909                 or dword ptr [ecx], ecx
// 00557f2a  0909                 or dword ptr [ecx], ecx
// 00557f2c  0909                 or dword ptr [ecx], ecx
// 00557f2e  0909                 or dword ptr [ecx], ecx
// 00557f30  0909                 or dword ptr [ecx], ecx
// 00557f32  0909                 or dword ptr [ecx], ecx
// 00557f34  0909                 or dword ptr [ecx], ecx
// 00557f36  0909                 or dword ptr [ecx], ecx
// 00557f38  0909                 or dword ptr [ecx], ecx
// 00557f3a  0909                 or dword ptr [ecx], ecx
// 00557f3c  0909                 or dword ptr [ecx], ecx
// 00557f3e  0909                 or dword ptr [ecx], ecx
// 00557f40  0909                 or dword ptr [ecx], ecx
// 00557f42  0909                 or dword ptr [ecx], ecx
// 00557f44  0909                 or dword ptr [ecx], ecx
// 00557f46  0909                 or dword ptr [ecx], ecx
// 00557f48  0909                 or dword ptr [ecx], ecx
// 00557f4a  0909                 or dword ptr [ecx], ecx
// 00557f4c  0909                 or dword ptr [ecx], ecx
// 00557f4e  0909                 or dword ptr [ecx], ecx
// 00557f50  0909                 or dword ptr [ecx], ecx
// 00557f52  0909                 or dword ptr [ecx], ecx
// 00557f54  0909                 or dword ptr [ecx], ecx
// 00557f56  0909                 or dword ptr [ecx], ecx
// 00557f58  0909                 or dword ptr [ecx], ecx
// 00557f5a  0909                 or dword ptr [ecx], ecx
// 00557f5c  0909                 or dword ptr [ecx], ecx
// 00557f5e  0909                 or dword ptr [ecx], ecx
// 00557f60  0909                 or dword ptr [ecx], ecx
// 00557f62  0909                 or dword ptr [ecx], ecx
// 00557f64  0909                 or dword ptr [ecx], ecx
// 00557f66  0909                 or dword ptr [ecx], ecx
// 00557f68  0909                 or dword ptr [ecx], ecx
// 00557f6a  0909                 or dword ptr [ecx], ecx
// 00557f6c  0909                 or dword ptr [ecx], ecx
// 00557f6e  0909                 or dword ptr [ecx], ecx
// 00557f70  0909                 or dword ptr [ecx], ecx
// 00557f72  0909                 or dword ptr [ecx], ecx
// 00557f74  0909                 or dword ptr [ecx], ecx
// 00557f76  0909                 or dword ptr [ecx], ecx
// 00557f78  0909                 or dword ptr [ecx], ecx
// 00557f7a  0909                 or dword ptr [ecx], ecx
// 00557f7c  0909                 or dword ptr [ecx], ecx
// 00557f7e  0909                 or dword ptr [ecx], ecx
// 00557f80  0909                 or dword ptr [ecx], ecx
// 00557f82  0909                 or dword ptr [ecx], ecx
// 00557f84  0909                 or dword ptr [ecx], ecx
// 00557f86  0909                 or dword ptr [ecx], ecx
// 00557f88  0909                 or dword ptr [ecx], ecx
// 00557f8a  0909                 or dword ptr [ecx], ecx
// 00557f8c  0909                 or dword ptr [ecx], ecx
// 00557f8e  0909                 or dword ptr [ecx], ecx
// 00557f90  0909                 or dword ptr [ecx], ecx
// 00557f92  0909                 or dword ptr [ecx], ecx
// 00557f94  0909                 or dword ptr [ecx], ecx
// 00557f96  0909                 or dword ptr [ecx], ecx
// 00557f98  0909                 or dword ptr [ecx], ecx
// 00557f9a  0909                 or dword ptr [ecx], ecx
// 00557f9c  0909                 or dword ptr [ecx], ecx
// 00557f9e  0909                 or dword ptr [ecx], ecx
// 00557fa0  0909                 or dword ptr [ecx], ecx
// 00557fa2  0909                 or dword ptr [ecx], ecx
// 00557fa4  0909                 or dword ptr [ecx], ecx
// 00557fa6  0909                 or dword ptr [ecx], ecx
// 00557fa8  0909                 or dword ptr [ecx], ecx
// 00557faa  0909                 or dword ptr [ecx], ecx
// 00557fac  0909                 or dword ptr [ecx], ecx
// 00557fae  0909                 or dword ptr [ecx], ecx
// 00557fb0  0909                 or dword ptr [ecx], ecx
// 00557fb2  0909                 or dword ptr [ecx], ecx
// 00557fb4  0909                 or dword ptr [ecx], ecx
// 00557fb6  0909                 or dword ptr [ecx], ecx
// 00557fb8  0909                 or dword ptr [ecx], ecx
// 00557fba  0909                 or dword ptr [ecx], ecx
// 00557fbc  0909                 or dword ptr [ecx], ecx
// 00557fbe  0909                 or dword ptr [ecx], ecx
// 00557fc0  0909                 or dword ptr [ecx], ecx
// 00557fc2  0909                 or dword ptr [ecx], ecx
// 00557fc4  0909                 or dword ptr [ecx], ecx
// 00557fc6  0909                 or dword ptr [ecx], ecx
// 00557fc8  0909                 or dword ptr [ecx], ecx
// 00557fca  06                   push es
// 00557fcb  07                   pop es

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
#include <string>
#define NULL 0
namespace RBX {
class IDataState { public: virtual void setDirty(bool) = 0; };
class Verb {
public:
	virtual ~Verb();
	virtual void v1();
	virtual bool isEnabled() const;
	virtual bool isChecked() const;
	virtual void doIt(IDataState*) = 0;
};
class VerbContainer {
public:
	virtual ~VerbContainer();
	Verb* getVerb(std::string name);
	char vcpad[0x10];
};
class GuiResponse {
	enum ResponseType { NOT_USED, USED, USED_AND_FINISHED };
	ResponseType response;
	void* target;
	GuiResponse(ResponseType response) : response(response), target(0) {}
public:
	static GuiResponse notUsed() { return GuiResponse(NOT_USED); }
	static GuiResponse used() { return GuiResponse(USED); }
};
class UIEvent {
public:
	enum EventType { NO_EVENT, MOUSE_RIGHT_BUTTON_DOWN, MOUSE_RIGHT_BUTTON_UP, MOUSE_LEFT_BUTTON_DOWN, MOUSE_LEFT_BUTTON_UP, MOUSE_MOVE, MOUSE_DELTA, MOUSE_WHEEL_FORWARD, MOUSE_WHEEL_BACKWARD, KEY_DOWN, KEY_UP };
	EventType eventType;
	void* userInput;
	int key;
	int mod;
};
class GuiEvent : public UIEvent { public: void* iDataState; };
namespace Network { class Player; class Players { public: static Player* findLocalPlayer(const void* context); }; }
class Tool { public: static void dropAll(Network::Player*); };
class Hat { public: static void dropAll(Network::Player*); };
class LocalBackpack { public: bool hotkey(int); void scrollLeft(); void scrollRight(); };
class RunService { public: void setRunState(int); };
class Workspace { public: char pad[0x284]; VerbContainer verbs; };
template<class T> class shared_ptr { public: T* px; void* pn; T* operator->() const { return px; } };
class DataModelBase { public: virtual ~DataModelBase(); char pad[0x14c - 4]; };
class DataModel : public DataModelBase, public VerbContainer, public IDataState {
public:
	char pad164[0x180 - 0x164];
	shared_ptr<LocalBackpack> localBackpack;
	shared_ptr<Workspace> workspace;
	shared_ptr<RunService> runService;
	GuiResponse processAccelerators(const GuiEvent&);
};
}

namespace RBX {
GuiResponse DataModel::processAccelerators(const GuiEvent& event)
{
	Verb* verb = NULL;
	switch (event.eventType)
	{
	case UIEvent::KEY_DOWN:
		if (event.key > '0' && event.key <= '9')
		{
			if (localBackpack->hotkey(event.key - '0'))
				return GuiResponse::used();
		}
		else
		{
			switch (event.key)
			{
			case 27:
				runService->setRunState(2);
				break;
			case 8:
				if (Network::Player* player = Network::Players::findLocalPlayer(this))
					Tool::dropAll(player);
				break;
			case ',':
				verb = workspace->verbs.getVerb("CameraPanLeft");
				break;
			case 'o':
				verb = workspace->verbs.getVerb("CameraZoomOut");
				break;
			case '.':
				verb = workspace->verbs.getVerb("CameraPanRight");
				break;
			case 280:
				verb = workspace->verbs.getVerb("CameraTiltDown");
				break;
			case 281:
				verb = workspace->verbs.getVerb("CameraTiltUp");
				break;
			case '=':
				if (Network::Player* player = Network::Players::findLocalPlayer(this))
					Hat::dropAll(player);
				break;
			case ']':
				localBackpack->scrollRight();
				break;
			case '[':
				localBackpack->scrollLeft();
				break;
			case 282:
				if (event.mod == 0)
					verb = getVerb("Help");
				else
					verb = getVerb("Stats");
				break;
			case 'i':
				verb = workspace->verbs.getVerb("CameraZoomIn");
				break;
			}
		}
		break;
	case UIEvent::MOUSE_WHEEL_FORWARD:
		verb = workspace->verbs.getVerb("CameraZoomIn");
		break;
	case UIEvent::MOUSE_WHEEL_BACKWARD:
		verb = workspace->verbs.getVerb("CameraZoomOut");
		break;
	}
	if (verb && verb->isEnabled())
	{
		verb->doIt(this);
		return GuiResponse::used();
	}
	return GuiResponse::notUsed();
}
}
