// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Native openrbx GuidItem/Instance virtual hierarchy and target RTTI establish these ABI views.
// Native Events, CopyOnWrite, Boost and STL operations preserve notification/ownership lifetimes.
// Unused native APIs are omitted; all accessed member offsets are compile-asserted.
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <intrin.h>
#include <utility>
#include <stddef.h>
#include <ostream>
namespace boost {
namespace detail {
struct sp_counted_base {
    sp_counted_base():use_count_(1),weak_count_(1){}
    virtual ~sp_counted_base() {}
    virtual void dispose()=0;
    virtual void destroy(){delete this;}
    long use_count_,weak_count_;
    void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
    void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
template<class Y>struct sp_counted_impl_p:sp_counted_base {Y*pointer;explicit sp_counted_impl_p(Y*p):pointer(p){}void dispose(){delete pointer;}};
struct shared_count {
    sp_counted_base* pi_;
    shared_count():pi_(0){}
    
    shared_count& operator=(const shared_count& r){sp_counted_base* tmp=r.pi_;if(tmp!=pi_){if(tmp)_InterlockedIncrement(&tmp->use_count_);if(pi_)pi_->release();pi_=tmp;}return *this;}
    void swap(shared_count& r){sp_counted_base* tmp=r.pi_;r.pi_=pi_;pi_=tmp;}
    shared_count(const shared_count& r):pi_(r.pi_){if(pi_)_InterlockedIncrement(&pi_->use_count_);}
    ~shared_count(){if(pi_)pi_->release();}
};
}
namespace detail {inline void sp_enable_shared_from_this(const shared_count&,...) {}}
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    shared_ptr():px(0),pn(){}
    
    shared_ptr& operator=(const shared_ptr& r){px=r.px;pn=r.pn;return *this;}
    void swap(shared_ptr& r){std::swap(px,r.px);pn.swap(r.pn);}
    void reset(){shared_ptr().swap(*this);}
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type()const{return px==0?0:&shared_ptr::px;}
    __declspec(noinline) shared_ptr(const shared_ptr& r):px(r.px),pn(r.pn){}
    template<class Y> __declspec(noinline) shared_ptr(const shared_ptr<Y>& r):px(r.px),pn(r.pn){}
    T* get()const{return px;}
    T* operator->()const{return px;}
};
template<class T,class U> bool operator==(const shared_ptr<T>& a,const shared_ptr<U>& b){return a.get()==b.get();}
}




namespace boost {
struct noncopyable{};
template<class T>struct weak_ptr {T*px;void*count;};
template<class T>struct enable_shared_from_this {weak_ptr<T>weak_this;shared_ptr<T>shared_from_this();};
}
namespace G3D {std::string __cdecl format(const char*,...);}
namespace RBX {
struct Name;struct Instance;struct XmlElement;struct IReferenceBinder;struct ServiceProvider;
struct Guid:boost::noncopyable {const Name*scope;int index;};
template<class T>struct GuidItem {virtual ~GuidItem();bool registeredGuid;Guid guid;};
struct Object {virtual ~Object();};template<class T>struct Creatable:Object{};
template<class T>struct AbstractFactoryProduct:Creatable<T> {virtual const Name&getClassName()const=0;};
namespace Reflection {
struct PropertyDescriptor;struct SignalSource {virtual ~SignalSource();void*signals;};
struct DescribedBase:SignalSource {void*descriptor;};
struct ChildSignal {void fire(SignalSource*,boost::shared_ptr<Instance>)const;};
}
struct Debugable {virtual void dump(std::ostream&);};
struct RaiseRange;
template<class T,class Event>struct Listener;
template<class T,class Event>struct Notifier {
 virtual ~Notifier();std::vector<Listener<T,Event>*>listeners;RaiseRange*range;
 virtual void onAddListener(Listener<T,Event>*)const;virtual void onRemoveListener(Listener<T,Event>*)const;
 __declspec(nothrow) void raise(Event)const;
};
template<class T>boost::shared_ptr<T> __cdecl shared_from(T*);
struct ChildAdded {const boost::shared_ptr<Instance>child;ChildAdded(Instance*p):child(shared_from(p)){}};
struct ChildRemoved {const boost::shared_ptr<Instance>child;ChildRemoved(Instance*p):child(shared_from(p)){}};
struct DescendentAdded;struct DescendentRemoving;struct PropertyChanged;
struct AncestorChanged {Instance*const child;Instance*const oldParent;Instance*const newParent;AncestorChanged(Instance*c,Instance*o,Instance*n):child(c),oldParent(o),newParent(n){}};
template<class T>struct Association {struct Item;std::vector<Item*>items;};
template<class T>struct CopyOnWrite:boost::noncopyable {
 boost::shared_ptr<T>object;
 operator typename boost::shared_ptr<T>::unspecified_bool_type()const{return object;}
 const T*operator->()const{return object.get();}boost::shared_ptr<T>&write();void reset();
};
struct Instance:GuidItem<Instance>,AbstractFactoryProduct<Instance>,Reflection::DescribedBase,Debugable,
 Notifier<Instance,ChildAdded>,Notifier<Instance,ChildRemoved>,Notifier<Instance,DescendentAdded>,Notifier<Instance,DescendentRemoving>,Notifier<Instance,AncestorChanged>,Notifier<Instance,PropertyChanged>,boost::enable_shared_from_this<Instance>,boost::noncopyable {
 virtual ~Instance();virtual void setName(const std::string&);
 virtual bool askAddChild(const Instance*)const;virtual bool askSetParent(const Instance*)const;
 virtual void onAncestorChanged(const AncestorChanged&);virtual void onDescendentAdded(Instance*);virtual void onDescendentRemoving(const boost::shared_ptr<Instance>&);
 virtual void onChildAdded(Instance*);virtual void onChildRemoving(Instance*);virtual void onChildRemoved(Instance*);virtual void onLastChildRemoved();
 virtual void readProperty(const XmlElement*,IReferenceBinder&);virtual void onServiceProvider(const ServiceProvider*,const ServiceProvider*);virtual boost::shared_ptr<Instance>createChild(const Name&);virtual XmlElement*write();virtual void onChildChanged(Instance*,const PropertyChanged&);
 Association<Instance>assoc;Instance*parent;CopyOnWrite<std::vector<boost::shared_ptr<Instance> > >children;std::string name;bool archivable;
 static Reflection::ChildSignal event_childAdded,event_childRemoved;static const Reflection::PropertyDescriptor propParent;
 std::string getFullName()const;bool isAncestorOf(const Instance*)const;bool contains(const Instance*child)const;
 unsigned numChildren()const{return children?children->size():0;}
 static void signalDescendentRemoving(const boost::shared_ptr<Instance>&,Instance*,Instance*);static void signalDescendentAdded(Instance*,Instance*,Instance*);
 void raisePropertyChanged(const Reflection::PropertyDescriptor&);void setParent(Instance*);
};
}

#include <map>
#include <set>
#include <list>
#include <queue>
namespace RakNet {class BitStream;}
struct SocketDescriptor;struct Packet;struct RPCParameters;struct NetworkID;class NetworkIDManager;struct InternalPacket;
typedef unsigned int RakNetTime;
struct SystemAddress {unsigned int binaryAddress;unsigned short port;char* ToString(bool)const;};
enum PacketPriority {SYSTEM_PRIORITY,HIGH_PRIORITY,MEDIUM_PRIORITY,LOW_PRIORITY,NUMBER_OF_PRIORITIES};
enum PacketReliability {UNRELIABLE,UNRELIABLE_SEQUENCED,RELIABLE,RELIABLE_ORDERED,RELIABLE_SEQUENCED};
enum PluginReceiveResult {RR_STOP_PROCESSING_AND_DEALLOCATE,RR_CONTINUE_PROCESSING,RR_STOP_PROCESSING};
class RakPeerInterface;
struct PluginInterface {
 PluginInterface();virtual ~PluginInterface();
 virtual void OnAttach(RakPeerInterface*);virtual void OnDetach(RakPeerInterface*);virtual void OnStartup(RakPeerInterface*);
 virtual void Update(RakPeerInterface*);virtual PluginReceiveResult OnReceive(RakPeerInterface*,Packet*);
 virtual void OnShutdown(RakPeerInterface*);virtual void OnCloseConnection(RakPeerInterface*,SystemAddress);
 virtual void OnDirectSocketSend(const char*,unsigned int,SystemAddress);virtual void OnDirectSocketReceive(const char*,unsigned int,SystemAddress);
 virtual void OnInternalPacket(InternalPacket*,unsigned int,SystemAddress,RakNetTime,bool);
};
class RakPeerInterface {public:
virtual ~RakPeerInterface();
virtual bool Startup( unsigned short maxConnections, int _threadSleepTimer, SocketDescriptor *socketDescriptors, unsigned socketDescriptorCount )=0;
virtual void InitializeSecurity(const char *pubKeyE, const char *pubKeyN, const char *privKeyP, const char *privKeyQ )=0;
virtual void DisableSecurity( void )=0;
virtual void SetMaximumIncomingConnections( unsigned short numberAllowed )=0;
virtual unsigned short GetMaximumIncomingConnections( void ) const=0;
virtual unsigned short NumberOfConnections(void) const=0;
virtual void SetIncomingPassword( const char* passwordData, int passwordDataLength )=0;
virtual void GetIncomingPassword( char* passwordData, int *passwordDataLength  )=0;
virtual bool Connect( const char* host, unsigned short remotePort, const char *passwordData, int passwordDataLength, unsigned connectionSocketIndex )=0;
virtual void Shutdown( unsigned int blockDuration, unsigned char orderingChannel )=0;
virtual bool IsActive( void ) const=0;
virtual bool GetConnectionList( SystemAddress *remoteSystems, unsigned short *numberOfSystems ) const=0;
virtual bool Send( const char *data, const int length, PacketPriority priority, PacketReliability reliability, char orderingChannel, SystemAddress systemAddress, bool broadcast )=0;
virtual bool Send( const RakNet::BitStream * bitStream, PacketPriority priority, PacketReliability reliability, char orderingChannel, SystemAddress systemAddress, bool broadcast )=0;
virtual Packet* Receive( void )=0;
virtual void DeallocatePacket( Packet *packet )=0;
virtual unsigned short GetMaximumNumberOfPeers( void ) const=0;
virtual void RegisterAsRemoteProcedureCall( const char* uniqueID, void ( *functionPointer ) ( RPCParameters *rpcParms ) )=0;
virtual void RegisterClassMemberRPC( const char* uniqueID, void *functionPointer )=0;
virtual void UnregisterAsRemoteProcedureCall( const char* uniqueID )=0;
virtual void SetNetworkIDManager( NetworkIDManager *manager )=0;
virtual NetworkIDManager *GetNetworkIDManager(void) const=0;
virtual bool RPC( const char* uniqueID, const char *data, unsigned int bitLength, PacketPriority priority, PacketReliability reliability, char orderingChannel, SystemAddress systemAddress, bool broadcast, RakNetTime *includedTimestamp, NetworkID networkID, RakNet::BitStream *replyFromTarget )=0;
virtual bool RPC( const char* uniqueID, const RakNet::BitStream *bitStream, PacketPriority priority, PacketReliability reliability, char orderingChannel, SystemAddress systemAddress, bool broadcast, RakNetTime *includedTimestamp, NetworkID networkID, RakNet::BitStream *replyFromTarget )=0;
virtual void CloseConnection( const SystemAddress target, bool sendDisconnectionNotification, unsigned char orderingChannel )=0;
virtual bool IsConnected(const SystemAddress systemAddress)=0;
virtual int GetIndexFromSystemAddress( const SystemAddress systemAddress )=0;
virtual SystemAddress GetSystemAddressFromIndex( int index )=0;
virtual void AddToBanList( const char *IP, RakNetTime milliseconds )=0;
virtual void RemoveFromBanList( const char *IP )=0;
virtual void ClearBanList( void )=0;
virtual bool IsBanned( const char *IP )=0;
virtual void Ping( const SystemAddress target )=0;
virtual void Ping( const char* host, unsigned short remotePort, bool onlyReplyOnAcceptingConnections, unsigned connectionSocketIndex )=0;
virtual int GetAveragePing( const SystemAddress systemAddress )=0;
virtual int GetLastPing( const SystemAddress systemAddress ) const=0;
virtual int GetLowestPing( const SystemAddress systemAddress ) const=0;
virtual void SetOccasionalPing( bool doPing )=0;
virtual void SetOfflinePingResponse( const char *data, const unsigned int length )=0;
virtual SystemAddress GetInternalID( const SystemAddress systemAddress ) const=0;
virtual SystemAddress GetExternalID( const SystemAddress target ) const=0;
virtual void SetTimeoutTime( RakNetTime timeMS, const SystemAddress target )=0;
virtual bool SetMTUSize( int size )=0;
virtual int GetMTUSize( const SystemAddress target ) const=0;
virtual unsigned GetNumberOfAddresses( void )=0;
virtual const char* GetLocalIP( unsigned int index )=0;
virtual void AllowConnectionResponseIPMigration( bool allow )=0;
virtual void AdvertiseSystem( const char *host, unsigned short remotePort, const char *data, int dataLength, unsigned connectionSocketIndex )=0;
virtual void SetSplitMessageProgressInterval(int interval)=0;
virtual void SetUnreliableTimeout(RakNetTime timeoutMS)=0;
virtual void SendTTL1( const char* host, unsigned short remotePort, unsigned connectionSocketIndex )=0;
virtual void SetCompileFrequencyTable( bool doCompile )=0;
virtual bool GetOutgoingFrequencyTable( unsigned int outputFrequencyTable[ 256 ] )=0;
virtual bool GenerateCompressionLayer( unsigned int inputFrequencyTable[ 256 ], bool inputLayer )=0;
virtual bool DeleteCompressionLayer( bool inputLayer )=0;
virtual float GetCompressionRatio( void ) const=0;
virtual float GetDecompressionRatio( void ) const=0;
virtual void AttachPlugin( PluginInterface *plugin )=0;
};
namespace boost {
template<class T>struct scoped_ptr {
 T*px;explicit scoped_ptr(T*p=0):px(p){}~scoped_ptr(){delete px;}
 T*get()const{return px;}T*operator->()const{return px;}
 void swap(scoped_ptr&r){T*t=r.px;r.px=px;px=t;}
 void reset(T*p=0){scoped_ptr(p).swap(*this);}
};
namespace signals {struct connection {char unused[16];~connection();};}
}
namespace G3D {struct System {static double getLocalTime();};}
namespace RBX {
namespace Reflection {struct Property;}
namespace Profiling {
struct Profiler {const double bucketTimeSpan;char unused[0xc040-8];};
struct CodeProfiler:Profiler {CodeProfiler*parent;CodeProfiler(const char*);~CodeProfiler();};
struct ThreadProfiler:Profiler {bool initialized;ThreadProfiler(const char*);~ThreadProfiler();};
}
namespace Network {
struct Replicator;struct Player;struct Players;struct Marker;
struct IdSerializer:Instance {char unused[0x2b74-sizeof(Instance)];IdSerializer();virtual ~IdSerializer();};
template<class T,class Base>struct DescribedNonCreatable:Base {DescribedNonCreatable();virtual ~DescribedNonCreatable();virtual const Name&getClassName()const;};
struct SharedStringDictionary {char unused[68];SharedStringDictionary();~SharedStringDictionary();};
struct PhysicsSender {virtual ~PhysicsSender();char unused[20];PhysicsSender(Replicator*);};
struct RoundRobinPhysicsSender:PhysicsSender {char unused[0x74-sizeof(PhysicsSender)];RoundRobinPhysicsSender(Replicator*);virtual ~RoundRobinPhysicsSender();};
struct PhysicsReceiver {virtual ~PhysicsReceiver();Replicator*owner;};
struct DirectPhysicsReceiver:PhysicsReceiver {explicit DirectPhysicsReceiver(Replicator*p){owner=p;}virtual ~DirectPhysicsReceiver();};
struct InterpolatingPhysicsReceiver:PhysicsReceiver {char unused[0x3c-sizeof(PhysicsReceiver)];InterpolatingPhysicsReceiver(Replicator*);virtual ~InterpolatingPhysicsReceiver();};
struct NetworkSettings {char unused[0x134];int sendMode;int receiveMode;static NetworkSettings&singleton();};
struct Replicator:DescribedNonCreatable<Replicator,IdSerializer>,PluginInterface {
 struct Item;struct ReplicatorStatsItem;
 double lastSendTime;
 boost::scoped_ptr<PhysicsSender>physicsSender;
 boost::scoped_ptr<PhysicsReceiver>physicsReceiver;
 boost::shared_ptr<ReplicatorStatsItem>statsItem;
 std::map<const Reflection::PropertyDescriptor*,boost::shared_ptr<SharedStringDictionary> >strings;
 SharedStringDictionary classNames,propNames;
 std::set<Instance*>replicationContainers;
 std::vector<boost::signals::connection>replicationContainerConnections;
 Players*players;
 std::list<boost::shared_ptr<Item> >pendingItems;
 std::set<const Instance*>pendingNewInstances,pendingDeleteInstances;
 bool sendPhysicsEnabled;
 const Reflection::Property*deserializeProperty;
 Instance*removingInstance;
 std::queue<boost::shared_ptr<Marker> >incomingMarkers;
 std::map<const Name*,boost::shared_ptr<Instance> >defaultObjects;
 boost::scoped_ptr<Profiling::CodeProfiler>profileReplication,profileDataListening,profileDataIn,profileDataOut,profilePhysicsIn,profilePhysicsOut,profileStep,profileWrite;
 boost::scoped_ptr<Profiling::ThreadProfiler>profileBitsReceived,profileBitsSent,profileUnsplit,profileSplit;
 bool receivedGlobals,disconnected;
 RakPeerInterface*peer;const SystemAddress remotePlayerId;
 unsigned int reservedWords[2];
 Replicator(SystemAddress remoteAddress,RakPeerInterface*peer);
 virtual Player*findTargetPlayer();virtual ~Replicator();virtual void Update(RakPeerInterface*);virtual PluginReceiveResult OnReceive(RakPeerInterface*,Packet*);
 virtual const Name&getClassName()const;virtual XmlElement*write();virtual void onServiceProvider(const ServiceProvider*,const ServiceProvider*);
 virtual bool wantReplicate(const Instance*)const;virtual void onSentMarker(long);virtual bool remoteDeleteOnDisconnect(const Instance*)const;
};
Replicator::Replicator(SystemAddress remoteAddress,RakPeerInterface*p)
:lastSendTime(G3D::System::getLocalTime()),physicsSender(),physicsReceiver(),statsItem(),players(0),sendPhysicsEnabled(false),deserializeProperty(0),removingInstance(0),
 profileReplication(new Profiling::CodeProfiler("Replication")),profileDataListening(new Profiling::CodeProfiler("Data Listening")),
 profileDataIn(new Profiling::CodeProfiler("Data In")),profileDataOut(new Profiling::CodeProfiler("Data Out")),
 profilePhysicsIn(new Profiling::CodeProfiler("Physics In")),profilePhysicsOut(new Profiling::CodeProfiler("Physics Out")),
 profileStep(new Profiling::CodeProfiler("Step")),profileWrite(new Profiling::CodeProfiler("Write")),
 profileBitsReceived(new Profiling::ThreadProfiler("Bits Received")),profileBitsSent(new Profiling::ThreadProfiler("Bits Sent")),
 profileUnsplit(new Profiling::ThreadProfiler("Unsplit Messages Sent")),profileSplit(new Profiling::ThreadProfiler("Split Messages Sent")),
 receivedGlobals(false),disconnected(false),peer(p),remotePlayerId(remoteAddress)
{
 reservedWords[0]=0;reservedWords[1]=0;
 switch(NetworkSettings::singleton().sendMode){case 0:physicsSender.reset(new RoundRobinPhysicsSender(this));break;case 1:physicsSender.reset(new PhysicsSender(this));break;}
 switch(NetworkSettings::singleton().receiveMode){case 0:physicsReceiver.reset(new DirectPhysicsReceiver(this));break;case 1:physicsReceiver.reset(new InterpolatingPhysicsReceiver(this));break;}
 if(p)p->AttachPlugin(this);
 {std::string name(remoteAddress.ToString(true));Instance::setName(name);}
 profileDataListening->parent=profileReplication.get();profileDataIn->parent=profileReplication.get();profileDataOut->parent=profileReplication.get();
 profilePhysicsIn->parent=profileReplication.get();profilePhysicsOut->parent=profileReplication.get();profileStep->parent=profilePhysicsOut.get();profileWrite->parent=profilePhysicsOut.get();
}
typedef char assert_instance[sizeof(Instance)==0x130?1:-1];
typedef char assert_base[sizeof(IdSerializer)==0x2b74?1:-1];
typedef char assert_time[offsetof(Replicator,lastSendTime)==0x2b78?1:-1];
typedef char assert_strings[offsetof(Replicator,strings)==0x2b90?1:-1];
typedef char assert_connections[offsetof(Replicator,replicationContainerConnections)==0x2c58?1:-1];
typedef char assert_marker[offsetof(Replicator,incomingMarkers)==0x2cdc?1:-1];
typedef char assert_profile[offsetof(Replicator,profileReplication)==0x2d1c?1:-1];
typedef char assert_flags[offsetof(Replicator,receivedGlobals)==0x2d4c?1:-1];
typedef char assert_address[offsetof(Replicator,remotePlayerId)==0x2d54?1:-1];
typedef char assert_profiler[sizeof(Profiling::CodeProfiler)==0xc048?1:-1];
typedef char assert_thread_profiler[sizeof(Profiling::ThreadProfiler)==0xc048?1:-1];
}}
