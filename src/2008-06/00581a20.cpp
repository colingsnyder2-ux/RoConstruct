// from server: 100% by king_originala
namespace RBX {
class Instance {
public:
    virtual ~Instance();
    char pad[0x100];
    Instance* next;
};

class ServiceProvider : public Instance {
public:
    void apply(int);
};
}

struct Camera {
    void panRight();
};

struct CameraAccess {
    virtual void slot0();
    virtual Camera* get(int);
};

struct Parent : RBX::Instance {
    char pad[0x180];
    CameraAccess access;
};

struct Callback {
    virtual void invoke(int);
};

RBX::ServiceProvider* __cdecl func_005807b0(RBX::Instance*);

struct CameraPanRightCommand {
    char pad[12];
    Parent* parent;
    void execute(Callback*);
};

void CameraPanRightCommand::execute(Callback* callback)
{
    parent->access.get(1)->panRight();
    func_005807b0(parent)->apply(11);
    callback->invoke(1);
}
