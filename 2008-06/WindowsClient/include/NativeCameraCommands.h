#pragma once
// >>> native-status (generated) -- do not edit >>>
// NativeCameraCommands | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 34d1ba9b | roc native-status --write
namespace RBX {
class Camera;
template<class T> class FilteredSelection;
class CameraVerb : public Verb {
protected:
    Workspace* workspace;
    Camera* getCamera();
    const Camera* getCamera() const;
    ServiceClient<FilteredSelection<PVInstance> > selection;
public:
    CameraVerb(std::string,Workspace*);
    virtual bool isEnabled() const {return true;}
    virtual void doIt(IDataState*);
};
class FixedCameraCommand : public CameraVerb {
public:
    FixedCameraCommand(Workspace* ws) : CameraVerb("FixedCamera",ws) {}
    virtual bool isChecked() const;
    virtual void doIt(IDataState*);
};
class CameraPanLeftCommand : public CameraVerb {
public:
    CameraPanLeftCommand(Workspace* ws) : CameraVerb("CameraPanLeft",ws) {}
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};
class CameraPanRightCommand : public CameraVerb {
public:
    CameraPanRightCommand(Workspace* ws) : CameraVerb("CameraPanRight",ws) {}
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};
class CameraTiltUpCommand : public CameraVerb {
public:
    CameraTiltUpCommand(Workspace* ws) : CameraVerb("CameraTiltUp",ws) {}
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};
class CameraTiltDownCommand : public CameraVerb {
public:
    CameraTiltDownCommand(Workspace* ws) : CameraVerb("CameraTiltDown",ws) {}
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};
class CameraZoomInCommand : public CameraVerb {
public:
    CameraZoomInCommand(Workspace* ws) : CameraVerb("CameraZoomIn",ws) {}
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};
class CameraZoomOutCommand : public CameraVerb {
public:
    CameraZoomOutCommand(Workspace* ws) : CameraVerb("CameraZoomOut",ws) {}
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};
class CameraCenterCommand : public CameraVerb {
public:
    CameraCenterCommand(Workspace* ws) : CameraVerb("CameraCenter",ws) {}
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};
class CameraZoomExtentsCommand : public CameraVerb {
public:
    CameraZoomExtentsCommand(Workspace* ws) : CameraVerb("CameraZoomExtents",ws) {}
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};
class CameraModelViewCommand : public CameraVerb {
public:
    CameraModelViewCommand(Workspace* ws) : CameraVerb("CameraModelView",ws) {}
    virtual void doIt(IDataState*);
};
}
