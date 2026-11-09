// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-atl90-dll roc_espclaude_2746ccdb51e44a7f.cpp

// Candidate translation unit (score above; library headers required).
// Native0045a4a0 full1915B. Binary-backed codegen analogue.
#define _AFXDLL
#include "roc_doc_native_afx_h_e1e961746d00a41c.cpp"
#include <afxwin.h>
#include <atlbase.h>
#include <boost/scoped_ptr.hpp>
#include "v8datamodel/DataModel.h"
#include <exception>
using namespace RBX;

template<class T> static inline T& viewField(void* p,unsigned offset) {
    return *reinterpret_cast<T*>(static_cast<char*>(p)+offset);
}
class CRobloxViewNative;
class NativeWorkspace : public IUnknown {
public:
    boost::shared_ptr<DataModel> getDataModel(); //0046a940
};
class NativeRenderBinding {
public:
    void setWorkspace(NativeWorkspace*); //0045f7b0
    void activate(); //0045ead0
};
class NativeBaseService {
public:
    void initializeBase(); //0058c5e0
};
class NativeDataModelServices {
public:
    NativeBaseService* ensureBaseService(); //00452a00
};
void __cdecl reportViewException(const std::exception&); //0044aa70
static __forceinline VerbContainer* viewDataVerbs(DataModel* dm) {
    return dm ? reinterpret_cast<VerbContainer*>(reinterpret_cast<char*>(dm)+0x1c8) : 0;
}
static __forceinline VerbContainer* viewWorkspaceVerbs(DataModel* dm) {
    Workspace* ws=viewField<Workspace*>(dm,0x204);
    return ws ? reinterpret_cast<VerbContainer*>(reinterpret_cast<char*>(ws)+0x2ec) : 0;
}
// Native binding paths dereference the workspace receiver; no nullable base cast.
struct NativeWorkspacePad { virtual ~NativeWorkspacePad(); char pad[0x2e8]; };
struct NativeWorkspaceVerbsView : NativeWorkspacePad, VerbContainer {};
typedef char NativeWsVerbsOff[sizeof(NativeWorkspacePad)==0x2ec?1:-1];
static __forceinline NativeWorkspaceVerbsView* viewWorkspaceVerbReceiver(DataModel* dm) {
    return viewField<NativeWorkspaceVerbsView*>(dm,0x204);
}
// Genuine getter body within original class scope: native Verb::name at4.
// Genuine getter body within original class scope: native Verb::name at4.
inline const Name& Verb::getName() const { return name; }
class InsertModelFromRobloxVerb : public Verb {
    CRobloxViewNative* view;
    DataModel* dataModel;
    double lastAction;
public:
    InsertModelFromRobloxVerb(CRobloxViewNative*,DataModel*);
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};
class HelpCommand : public Verb {
    CRobloxViewNative* view;
public:
    __forceinline HelpCommand(CRobloxViewNative* v,VerbContainer* verbs):Verb(verbs,"Help"),view(v) {}
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};
class ToggleFullscreenVerb : public Verb {
public:
    __forceinline ToggleFullscreenVerb(VerbContainer* verbs):Verb(verbs,"ToggleFullScreen") {}
    virtual bool isEnabled() const;
    virtual bool isChecked() const;
    virtual void doIt(IDataState*);
};
class ToggleIDEModeVerb : public Verb {
    double lastAction;
public:
    ToggleIDEModeVerb(VerbContainer*);
    virtual bool isEnabled() const;
    virtual bool isChecked() const;
    virtual void doIt(IDataState*);
};
class LockPlayModeVerb : public Verb {
public:
    __forceinline LockPlayModeVerb(VerbContainer* verbs):Verb(verbs,"LockPlayMode") {}
    virtual bool isEnabled() const;
    virtual bool isChecked() const;
    virtual void doIt(IDataState*);
};
struct NativeDocView { char pad[0x94]; NativeWorkspace& workspaceRef; };
class CRobloxViewNative : public CView {
public:
    std::map<unsigned,const Name*> commands;
    char pad58[0xb0-0x58-sizeof(std::map<unsigned,const Name*>)];
    NativeRenderBinding renderBinding;
    char padb1[0x170-0xb1];
    boost::shared_ptr<DataModel> dataModel;
    char pad178[0x1d8-0x178];
    void* x1d8;
    boost::scoped_ptr<Verb> helpVerb;
    boost::scoped_ptr<Verb> insertModelVerb;
    boost::scoped_ptr<Verb> fullscreenVerb;
    boost::scoped_ptr<Verb> ideVerb;
    boost::scoped_ptr<Verb> lockVerb;
    __forceinline void setCommand(unsigned id,const Name& name) { commands[id]=&name; }
    void detachDataModel(); //0045a2f0
    virtual void OnInitialUpdate();
    NativeWorkspace* workspace() { return &reinterpret_cast<NativeDocView*>(GetDocument())->workspaceRef; }
};
typedef char NativeCViewSize[sizeof(CView)==0x58?1:-1];
typedef char NativeDataModelLockSize[sizeof(DataModel::Lock)==12?1:-1];
typedef char NativeInsertModelVerbSize[sizeof(InsertModelFromRobloxVerb)==32?1:-1];
typedef char NativeHelpVerbSize[sizeof(HelpCommand)==16?1:-1];
typedef char NativeFullScreenVerbSize[sizeof(ToggleFullscreenVerb)==12?1:-1];
typedef char NativeToggleIDEVerbSize[sizeof(ToggleIDEModeVerb)==24?1:-1];
typedef char NativeLockPlayModeVerbSize[sizeof(LockPlayModeVerb)==12?1:-1];

void CRobloxViewNative::OnInitialUpdate() {
    try {
        detachDataModel();
        renderBinding.setWorkspace(0);
        dataModel.reset();
        CView::OnInitialUpdate();
        renderBinding.setWorkspace(workspace());
        dataModel=reinterpret_cast<NativeDocView*>(GetDocument())->workspaceRef.getDataModel();
        DataModel::Lock lock(dataModel);
        if(x1d8)
            viewField<ATL::CComPtr<IUnknown> >(x1d8,0xfc)=workspace();
        {
            Listener<Instance,DescendentAdded>* l=reinterpret_cast<Listener<Instance,DescendentAdded>*>(reinterpret_cast<char*>(this)+0xa0);
            DataModel* dm=dataModel.get();
            if(dm) reinterpret_cast<Notifier<Instance,DescendentAdded>*>(reinterpret_cast<char*>(dm)+0x150)->addListener(l);
        }
        {
            Listener<Instance,DescendentRemoving>* l=reinterpret_cast<Listener<Instance,DescendentRemoving>*>(reinterpret_cast<char*>(this)+0xa4);
            DataModel* dm=dataModel.get();
            if(dm) reinterpret_cast<Notifier<Instance,DescendentRemoving>*>(reinterpret_cast<char*>(dm)+0x170)->addListener(l);
        }
        viewField<VerbContainer>(this,0x78).setVerbParent(viewWorkspaceVerbs(dataModel.get()));
        insertModelVerb.reset(new InsertModelFromRobloxVerb(this,dataModel.get()));
        helpVerb.reset(new HelpCommand(this,viewDataVerbs(dataModel.get())));
        fullscreenVerb.reset(new ToggleFullscreenVerb(viewDataVerbs(dataModel.get())));
        ideVerb.reset(new ToggleIDEModeVerb(viewDataVerbs(dataModel.get())));
        lockVerb.reset(new LockPlayModeVerb(viewDataVerbs(dataModel.get())));
        {
            Verb* verb=viewWorkspaceVerbReceiver(dataModel.get())->getVerb("CameraPanLeft");
            if(verb) setCommand(0x8027,verb->getName()); else setCommand(0x8027,Name::getNullName());
        }
        {
            Verb* verb=viewWorkspaceVerbReceiver(dataModel.get())->getVerb("CameraPanRight");
            if(verb) setCommand(0x8028,verb->getName()); else setCommand(0x8028,Name::getNullName());
        }
        {
            Verb* verb=viewWorkspaceVerbReceiver(dataModel.get())->getVerb("CameraTiltUp");
            if(verb) setCommand(0x8029,verb->getName()); else setCommand(0x8029,Name::getNullName());
        }
        {
            Verb* verb=viewWorkspaceVerbReceiver(dataModel.get())->getVerb("CameraTiltDown");
            if(verb) setCommand(0x802a,verb->getName()); else setCommand(0x802a,Name::getNullName());
        }
        {
            Verb* verb=viewWorkspaceVerbReceiver(dataModel.get())->getVerb("CameraZoomIn");
            if(verb) setCommand(0x802b,verb->getName()); else setCommand(0x802b,Name::getNullName());
        }
        {
            Verb* verb=viewWorkspaceVerbReceiver(dataModel.get())->getVerb("CameraZoomOut");
            if(verb) setCommand(0x802c,verb->getName()); else setCommand(0x802c,Name::getNullName());
        }
        {
            Verb* verb=viewWorkspaceVerbReceiver(dataModel.get())->getVerb("CameraCenter");
            if(verb) setCommand(0x80a6,verb->getName()); else setCommand(0x80a6,Name::getNullName());
        }
        {
            Verb* verb=viewWorkspaceVerbReceiver(dataModel.get())->getVerb("CameraZoomExtents");
            if(verb) setCommand(0x802d,verb->getName()); else setCommand(0x802d,Name::getNullName());
        }
        {
            Verb* verb=viewWorkspaceVerbReceiver(dataModel.get())->getVerb("CameraModelView");
            if(verb) setCommand(0x80d7,verb->getName()); else setCommand(0x80d7,Name::getNullName());
        }
        setCommand(0x802f,Name::lookup("FixedCamera"));
        setCommand(0x8030,Name::lookup("AttachCamera"));
        setCommand(0x80a3,Name::lookup("TrackCamera"));
        setCommand(0x8032,Name::lookup("FollowCamera"));
        setCommand(0x80a2,Name::lookup("WatchCamera"));
        setCommand(0x8043,Name::lookup("SelectionRotate"));
        setCommand(0x8044,Name::lookup("SelectionTilt"));
        renderBinding.activate();
        NativeBaseService* service=reinterpret_cast<NativeDataModelServices*>(dataModel.get())->ensureBaseService();
        if(service) service->initializeBase();
    } catch(const std::exception& e) { reportViewException(e); }
}
