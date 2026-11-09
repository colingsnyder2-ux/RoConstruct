// from server: 100% by tajop
namespace RBX {

struct CameraState {
    char pad[0x18c];
    int cameraType;
};

struct ICameraOwner {
    virtual void unused0();
    virtual CameraState* getCamera();
};

struct Workspace {
    char pad[0x228];
    ICameraOwner owner;
};

struct TrackCameraCommand {
    char pad[0xc];
    Workspace* workspace;
    bool isChecked();
};

bool TrackCameraCommand::isChecked()
{
    return workspace->owner.getCamera()->cameraType == 3;
}

}
