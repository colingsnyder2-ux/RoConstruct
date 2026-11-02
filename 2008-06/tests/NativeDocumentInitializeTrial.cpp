#include <afxwin.h>
#include <boost/scoped_ptr.hpp>
#include <stdexcept>
#include "CRobloxDoc.h"
#include "CWorkspace.h"
#include "v8datamodel/DataModel.h"
#include "StandardVerbs.h"
using namespace RBX;
extern HRESULT __stdcall createNativeWorkspace(CWorkspace**) throw();
class ReportAbuseVerb : public Verb {
    CRobloxDoc* doc;
public:
    __forceinline ReportAbuseVerb(CRobloxDoc* doc,VerbContainer* container)
        : Verb(container,"ReportAbuse"),doc(doc) {}
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};
class ExitCommand : public Verb {
    CRobloxDoc* doc;
public:
    __forceinline ExitCommand(CRobloxDoc* doc,VerbContainer* container)
        : Verb(container,"Exit"),doc(doc) {}
    virtual bool isEnabled() const {return true;}
    virtual void doIt(IDataState*);
};
namespace RBX {
class Camera;
class CameraVerb : public Verb {
protected:
    Workspace* workspace;
    Camera* getCamera();
    const Camera* getCamera() const;
    ServiceClient<Selection> selection;
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
// ClipboardObject is an empty nonvirtual native base: RTTI offset is exactly
//40(Cut)/36(Copy), without increasing those allocation sizes; Paste base12.
class ClipboardObject {};
class CutVerb : public DeleteSelectionVerb,public ClipboardObject {
public:
    CutVerb(DataModel*);
    virtual void doIt(IDataState*);
};
class CopyVerb : public EditSelectionVerb,public ClipboardObject {
public:
    CopyVerb(DataModel*);
    virtual void doIt(IDataState*);
};
class PasteVerb : public Verb,public ClipboardObject {
    DataModel* dataModel;
    const bool pasteInto;
public:
    PasteVerb(DataModel*,bool);
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};
class InsertDecal : public EditSelectionVerb {
public:
    InsertDecal(DataModel*,const char*);
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
protected:
    // Native slot14 creates a Texture/Decal via genuine shared_ptr factory;
    // 0041e670 returns two words through hidden result, ret4, primary Instance0.
    // Expose that actual value ABI through the genuine common Instance base.
    virtual boost::shared_ptr<Instance> createInstance();
};
class InsertTexture : public InsertDecal {
public:
    InsertTexture(DataModel* dm) : InsertDecal(dm,"InsertTexture") {}
protected:
    virtual boost::shared_ptr<Instance> createInstance();
};
class InsertObject : public RunStateVerb {
public:
    InsertObject(DataModel*);
    virtual void doIt(IDataState*);
};
class InsertService : public RunStateVerb {
public:
    InsertService(DataModel*);
    virtual void doIt(IDataState*);
};
typedef char native_doc_DataModel_Lock_size[(sizeof(DataModel::Lock)==12)?1:-1];
typedef char native_doc_CameraVerb_size[(sizeof(CameraVerb)==28)?1:-1];
typedef char native_doc_ReportAbuseVerb_size[(sizeof(ReportAbuseVerb)==16)?1:-1];
typedef char native_doc_ExitCommand_size[(sizeof(ExitCommand)==16)?1:-1];
typedef char native_doc_CutVerb_size[(sizeof(CutVerb)==40)?1:-1];
typedef char native_doc_CopyVerb_size[(sizeof(CopyVerb)==36)?1:-1];
typedef char native_doc_PasteVerb_size[(sizeof(PasteVerb)==20)?1:-1];
typedef char native_doc_InsertDecal_size[(sizeof(InsertDecal)==36)?1:-1];
typedef char native_doc_InsertTexture_size[(sizeof(InsertTexture)==36)?1:-1];
typedef char native_doc_InsertObject_size[(sizeof(InsertObject)==28)?1:-1];
typedef char native_doc_InsertService_size[(sizeof(InsertService)==28)?1:-1];
void CRobloxDoc::initializeCommands() {
    HRESULT hr=createNativeWorkspace(&workspace);
    if(hr==S_OK) {}
    else throw std::runtime_error("Unable to create CWorkspace");
    reinterpret_cast<IUnknown*>(workspace)->AddRef();
    boost::shared_ptr<DataModel> dm=workspace->getDataModel();
    DataModel::Lock lock(dm);
    { const char* (CString::*convert)() const = &CString::operator const char*; std::string documentName((m_strTitle.*convert)()); dm->setName(documentName); }
    reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs).reset(new StandardVerbs(dm.get()));
    ownedVerbs.push_back(new ReportAbuseVerb(this,static_cast<VerbContainer*>(dm.get())));
    ownedVerbs.push_back(new ExitCommand(this,static_cast<VerbContainer*>(dm.get())));
    ownedVerbs.push_back(new FixedCameraCommand(workspace->getWorkspace()));
    ownedVerbs.push_back(new CameraPanLeftCommand(workspace->getWorkspace()));
    ownedVerbs.push_back(new CameraPanRightCommand(workspace->getWorkspace()));
    ownedVerbs.push_back(new CameraTiltUpCommand(workspace->getWorkspace()));
    ownedVerbs.push_back(new CameraTiltDownCommand(workspace->getWorkspace()));
    ownedVerbs.push_back(new CameraZoomInCommand(workspace->getWorkspace()));
    ownedVerbs.push_back(new CameraZoomOutCommand(workspace->getWorkspace()));
    ownedVerbs.push_back(new CameraCenterCommand(workspace->getWorkspace()));
    ownedVerbs.push_back(new CameraZoomExtentsCommand(workspace->getWorkspace()));
    ownedVerbs.push_back(new CameraModelViewCommand(workspace->getWorkspace()));
    bindExisting(0xe120,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->deleteSelection);
    bindExisting(0xe12a,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->selectAll);
    bindExisting(0x8005,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->duplicate);
    bindExisting(0x8011,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->allCanSelect);
    bindExisting(0x8010,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->canNotSelect);
    bindExisting(0x80d8,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->join);
    bindExisting(0x80d4,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->forceAssertion);
    bindExisting(0x80d5,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->engineStats);
    { const Name& name = Name::lookup("Group"); commandNames[0x8039] = &name; }
    { const Name& name = Name::lookup("UnGroup"); commandNames[0x803a] = &name; }
    { const Name& name = Name::lookup("WeldSelection"); commandNames[0x8061] = &name; }
    { const Name& name = Name::lookup("SnapSelection"); commandNames[0x80a5] = &name; }
    { const Name& name = Name::lookup("SelectionRotate"); commandNames[0x8043] = &name; }
    { const Name& name = Name::lookup("SelectionTilt"); commandNames[0x8044] = &name; }
    { const Name& name = Name::lookup("SelectionUpBrick"); commandNames[0x8057] = &name; }
    { const Name& name = Name::lookup("SelectionUpPlate"); commandNames[0x8059] = &name; }
    { const Name& name = Name::lookup("SelectionDown"); commandNames[0x8058] = &name; }
    bindExisting(0x80aa,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolModelSetFront);
    bindExisting(0x80ab,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolModelSetPrimaryPart);
    bindOwned(0xe123,new CutVerb(dm.get()));
    bindOwned(0xe122,new CopyVerb(dm.get()));
    bindOwned(0xe125,new PasteVerb(dm.get(),false));
    bindOwned(0x80f7,new PasteVerb(dm.get(),true));
    bindOwned(0x8062,new InsertDecal(dm.get(),"InsertDecal"));
    bindOwned(0x80ee,new InsertTexture(dm.get()));
    bindOwned(0x807f,new InsertObject(dm.get()));
    bindOwned(0x8107,new InsertService(dm.get()));
    bindExisting(0x800d,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->clearStarterpack);
    bindExisting(0x800e,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->clearBackpack);
    { const Name& name = Name::lookup("FillTool"); commandNames[0x8040] = &name; }
    { const Name& name = Name::lookup("DropperTool"); commandNames[0x8041] = &name; }
    bindExisting(0x8063,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolArrow);
    bindExisting(0x8065,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolResize);
    bindExisting(0x8067,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolAxisMove);
    bindExisting(0x8073,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolLock);
    bindExisting(0x8074,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolAnchor);
    bindExisting(0x8077,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolGlue);
    bindExisting(0x8078,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolFlat);
    bindExisting(0x8079,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolWeld);
    bindExisting(0x80a7,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolStuds);
    bindExisting(0x80a8,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolInlet);
    bindExisting(0x807b,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolRightMotor);
    bindExisting(0x807c,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolHinge);
}
