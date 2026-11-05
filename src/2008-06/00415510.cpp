// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
#include <string>
#include <sstream>
#include <vector>
#include <memory>
#include <stddef.h>
extern "C" {
__declspec(dllimport) unsigned __stdcall RegisterClipboardFormatA(const char*);
__declspec(dllimport) int __stdcall OpenClipboard(void*);
__declspec(dllimport) int __stdcall CloseClipboard();
__declspec(dllimport) void* __stdcall GetClipboardData(unsigned);
__declspec(dllimport) void* __stdcall GlobalLock(void*);
__declspec(dllimport) int __stdcall GlobalUnlock(void*);
}
struct CRuntimeClass;struct CArchive;struct CDumpContext;struct CWnd;struct CException;struct MSG;struct IID;struct AFX_CMDHANDLERINFO;struct CTypeLibCache;struct CPtrArray;
struct CObject {virtual CRuntimeClass*GetRuntimeClass()const;virtual ~CObject();virtual void Serialize(CArchive&);virtual void AssertValid()const;virtual void Dump(CDumpContext&)const;};
struct CCmdTarget:CObject {
 virtual int OnCmdMsg(unsigned,int,void*,AFX_CMDHANDLERINFO*);virtual void OnFinalRelease();virtual int IsInvokeAllowed(long);virtual int GetDispatchIID(IID*);virtual unsigned GetTypeInfoCount();virtual CTypeLibCache*GetTypeLibCache();virtual long GetTypeLib(unsigned long,void**);
 virtual const void*GetMessageMap()const;virtual const void*GetCommandMap()const;virtual const void*GetDispatchMap()const;virtual const void*GetConnectionMap()const;virtual const void*GetInterfaceMap()const;virtual const void*GetEventSinkMap()const;
 virtual int OnCreateAggregates();virtual void*GetInterfaceHook(const void*);virtual int GetExtraConnectionPoints(CPtrArray*);virtual void*GetConnectionHook(const IID&);
 char opaque[0x20-4];
};
struct CWnd:CCmdTarget {void*handle;};
struct CWinThread:CCmdTarget {
 virtual int InitInstance();virtual int Run();virtual int PreTranslateMessage(MSG*);virtual int PumpMessage();virtual int OnIdle(long);virtual int IsIdleMessage(MSG*);virtual int ExitInstance();virtual long ProcessWndProcException(CException*,const MSG*);virtual int ProcessMessageFilter(int,MSG*);virtual CWnd*GetMainWnd();
};
CWinThread* __stdcall AfxGetThread();
inline CWnd*AfxGetMainWnd(){CWinThread*t=AfxGetThread();return t?t->GetMainWnd():0;}
namespace boost {namespace detail {
struct sp_counted_base {virtual ~sp_counted_base(){}virtual void dispose()=0;virtual void destroy(){delete this;}long use_count_,weak_count_;void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}};
struct shared_count {sp_counted_base*pi_;shared_count():pi_(0){}shared_count(const shared_count&r):pi_(r.pi_){if(pi_)_InterlockedIncrement(&pi_->use_count_);}~shared_count(){if(pi_)pi_->release();}};
}
template<class T>struct shared_ptr {T*px;detail::shared_count pn;shared_ptr():px(0),pn(){}shared_ptr(const shared_ptr&r):px(r.px),pn(r.pn){}T*get()const{return px;}};
}
class XmlElement {public:~XmlElement();};
class TextXmlParser {char opaque[72];public:TextXmlParser(std::streambuf*);~TextXmlParser();std::auto_ptr<XmlElement>parse();};
namespace RBX {
struct Instance;
typedef std::vector<boost::shared_ptr<Instance> >Instances;
struct Selection {char opaque[0x154];Instances*selection;size_t size()const{return selection->size();}boost::shared_ptr<Instance>front()const;void setSelection(Instances::const_iterator,Instances::const_iterator);};
struct Workspace {void insertInstances(const Instances&,Instance*,int,int);};
struct DataModel {char opaque[0x204];Workspace*workspace;Workspace*getWorkspace()const{return workspace;}Instance*findFirstChildByName(const std::string&);Selection*getSelection();};
struct ImportedNameString {char opaque[28];__declspec(dllimport) const char*c_str()const;};
struct Name {int dictionaryIndex;ImportedNameString name;};
struct IDataState {virtual void setDirty(bool)=0;virtual bool isDirty()const=0;};
void __cdecl requestWaypoint(const char*,const DataModel*);
}
struct SerializerV2 {int schemaVersionLoading;void loadInstances(XmlElement*,RBX::Instances&);};
struct Verb {virtual ~Verb();virtual bool isEnabled()const;virtual bool isChecked()const;virtual void doIt(RBX::IDataState*)=0;const RBX::Name&name;void*container;};
struct ClipboardObject {};
struct PasteVerb:Verb,ClipboardObject {RBX::DataModel*dataModel;const bool pasteInto;virtual void doIt(RBX::IDataState*);};
void PasteVerb::doIt(RBX::IDataState*state){
 if(dataModel->findFirstChildByName("NetworkClient"))return;
 if(!OpenClipboard(AfxGetMainWnd()->handle))return;
 static unsigned format=RegisterClipboardFormatA("Roblox");
 void*data=GetClipboardData(format);
 const char*text=(const char*)GlobalLock(data);
 RBX::Instances instances;
 {
  std::istringstream input(text,std::ios::in);
  TextXmlParser parser(input.rdbuf());
  std::auto_ptr<XmlElement>root(parser.parse());
  RBX::Selection*selection=dataModel?dataModel->getSelection():0;
  RBX::Instance*parent=pasteInto&&selection->size()==1?selection->front().get():(RBX::Instance*)dataModel->workspace;
  int insertMode=pasteInto?1:2;
  SerializerV2 serializer;serializer.loadInstances(root.get(),instances);
  dataModel->getWorkspace()->insertInstances(instances,parent,insertMode,1);
  selection->setSelection(instances.begin(),instances.end());
 }
 GlobalUnlock(data);CloseClipboard();
 const RBX::Name&verbName=name;
 _ReadWriteBarrier();
 const char*waypointName=verbName.name.c_str();
 RBX::requestWaypoint(waypointName,dataModel);state->setDirty(true);
}
typedef char parser_size[sizeof(TextXmlParser)==72?1:-1];
typedef char string_size[sizeof(std::string)==28?1:-1];
typedef char shared_size[sizeof(boost::shared_ptr<RBX::Instance>)==8?1:-1];
typedef char vector_size[sizeof(RBX::Instances)==24?1:-1];
typedef char wnd_handle[offsetof(CWnd,handle)==0x20?1:-1];
typedef char paste_model[offsetof(PasteVerb,dataModel)==0xc?1:-1];
typedef char paste_into[offsetof(PasteVerb,pasteInto)==0x10?1:-1];
