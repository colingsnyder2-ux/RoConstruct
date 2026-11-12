// from server: 100% by EspClaude
// roc 2007-08 00562bd0  unit: RBX::AttachCameraCommand  size: 178 bytes
#include <vector>

namespace RBX {

class Instance;

class Camera
{
public:
    void setCameraType(int type);          // 0x59b6c0, thiscall, ret 4
    void setCameraSubject(Instance* s);    // 0x59b700, thiscall, ret 4
};

class CameraOwner                          // subobject at +0x228, getCamera is vtable slot 1
{
public:
    virtual void slot0();
    virtual Camera* getCamera();
};

class Workspace
{
    char pad00[0x228];
public:
    CameraOwner cameraOwner;               // +0x228
};

class Selection
{
    char pad00[0xf4];
public:
    std::vector<Instance*> items;          // _Myfirst +0xf8, _Mylast +0xfc
};

class Tool
{
public:
    Selection* getSelection();             // 0x5618e0, thiscall, no args
};

class Verb                                 // arg: thiscall 0x4108b0(int), field +4, vtable slot 1(int)
{
public:
    virtual void slot0();
    virtual void release(int flags);
    int state;                             // +4
    void update(int v);                    // 0x4108b0
};

class AttachCameraCommand
{
    char pad00[0xc];
    Workspace* workspace;                  // +0xc
    char pad10[0x10];
    Tool* tool;                            // +0x20
public:
    void execute(Verb* verb);
};

void AttachCameraCommand::execute(Verb* verb)
{
    Selection* sel = tool ? tool->getSelection() : 0;
    Instance* subject = sel->items.size() != 0 ? sel->items.front() : 0;

    workspace->cameraOwner.getCamera()->setCameraType(1);
    workspace->cameraOwner.getCamera()->setCameraSubject(subject);

    verb->update(-1);
    verb->state = -1;
    verb->release(1);
}

}
