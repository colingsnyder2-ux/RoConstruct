// from server: 100% by EspClaude
// true extent: 0x51b bytes (server extent 0x19d)
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <exception>

namespace RakNet {
class BitStream {
    unsigned numberOfBitsUsed, numberOfBitsAllocated, readOffset;
    unsigned char* data;
    bool copyData;
    unsigned char stackData[256];
public:
    BitStream();
    BitStream(unsigned char* data, unsigned lengthInBytes, bool copyData);
    ~BitStream();
    void IgnoreBits(int numberOfBits);
};
}
RakNet::BitStream& __cdecl operator<<(RakNet::BitStream&, unsigned char);
RakNet::BitStream& __cdecl operator>>(RakNet::BitStream&, int&);
RakNet::BitStream& __cdecl operator>>(RakNet::BitStream&, std::string&);

struct SystemAddress {
    unsigned binaryAddress;
    unsigned short port;
    bool operator==(const SystemAddress&) const;
    const char* ToString(bool writePort = true) const;
};
struct Packet {
    unsigned short systemIndex;
    SystemAddress systemAddress;
    unsigned length;
    unsigned bitSize;
    unsigned char* data;
    bool deleteData;
};
enum PacketPriority { SYSTEM_PRIORITY, HIGH_PRIORITY, MEDIUM_PRIORITY, LOW_PRIORITY };
enum PacketReliability { UNRELIABLE, UNRELIABLE_SEQUENCED, RELIABLE, RELIABLE_ORDERED, RELIABLE_SEQUENCED };
enum PluginReceiveResult { RR_STOP_PROCESSING_AND_DEALLOCATE = 0, RR_CONTINUE_PROCESSING, RR_STOP_PROCESSING };
enum {
    ID_CONNECTION_REQUEST_ACCEPTED_ = 13,
    ID_NEW_INCOMING_CONNECTION_ = 16,
    ID_DISCONNECTION_NOTIFICATION_ = 18,
    ID_CONNECTION_LOST_ = 19,
    ID_TIMESTAMP_ = 24,
    ID_SET_GLOBALS = 75,
    ID_REQUEST_CHARACTER,
    ID_DICTIONARIES,
    ID_DATA,
    ID_REQUEST_MARKER
};

class RakPeerInterface {
public:
    virtual ~RakPeerInterface();
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12();
    virtual bool Send(RakNet::BitStream* bitStream, PacketPriority priority, PacketReliability reliability, char orderingChannel, SystemAddress systemAddress, bool broadcast);
};

class PluginInterface {
public:
    virtual ~PluginInterface();
    virtual void OnAttach(RakPeerInterface* peer);
    virtual void OnDetach(RakPeerInterface* peer);
    virtual void OnInitialize(RakPeerInterface* peer);
    virtual void Update(RakPeerInterface* peer);
    virtual PluginReceiveResult OnReceive(RakPeerInterface* peer, Packet* packet);
};

namespace RBX {
enum MessageType { MESSAGE_OUTPUT, MESSAGE_INFO, MESSAGE_WARNING, MESSAGE_ERROR };
class StandardOut {
public:
    void print(MessageType type, const char* format, ...);
};
struct StandardOutPtr {
    StandardOut* px;
    void* pn;
    ~StandardOutPtr();
    StandardOut* operator->() const { return px; }
};
StandardOutPtr __cdecl standardOut();

class Name;
inline bool operator==(const Name& a, const Name& b) { return &a == &b; }
const Name& __cdecl lookupName(const std::string&);

class Guid {
public:
    struct Data { const Name* scope; unsigned index; };
    static const Name& getLocalScope();
};

class Instance {
public:
    void setGuid(const Guid::Data&);
};
struct InstanceIterator {
    void* cont;
    Instance** ptr;
    InstanceIterator();
    Instance*& operator*() const;
    InstanceIterator& operator++();
    bool operator!=(const InstanceIterator&) const;
};
struct InstanceVector {
    void* proxy;
    Instance** first; Instance** last; Instance** end_;
    InstanceIterator begin();
    InstanceIterator end();
    Instance*& operator[](unsigned);
};

namespace Profiling {
class CodeProfiler;
class Mark {
    char storage[0x18];
public:
    Mark(CodeProfiler& section, bool frameTick);
    ~Mark();
};
}

namespace Reflection {
class DescribedBase { public: virtual ~DescribedBase(); char pad[0x2b74 - 0x18]; };
template<class C, class Sig> class SignalDesc;
template<class C> class SignalDesc<C, void(std::string, bool)> {
public:
    void fire(DescribedBase* source, std::string a, bool b) const;
};
}

__forceinline const char* safeWhat(const std::exception& e) { const char* s = e.what(); return s ? s : "empty error string"; }
class InstanceBase { public: virtual ~InstanceBase(); char pad[0x10]; };

namespace Network {
struct ClassDictionarySender { char pad[0x24]; void send(RakNet::BitStream&); };
struct ClassDictionaryReceiver { char pad[0x20]; void receive(RakNet::BitStream&); };
struct PropDictionarySender { char pad[0x24]; void send(RakNet::BitStream&); };
struct PropDictionaryReceiver { char pad[0x20]; void receive(RakNet::BitStream&); };

class Replicator;
class Item {
protected:
    Replicator& replicator;
    Item(Replicator& r) : replicator(r) {}
public:
    virtual ~Item() {}
    virtual void write(RakNet::BitStream&) = 0;
};
class MarkerItem : public Item {
    int id;
public:
    MarkerItem(Replicator& r, int id) : Item(r), id(id) {}
    virtual void write(RakNet::BitStream&);
};
struct ItemPtr {
    Item* px;
    void* pn;
    explicit ItemPtr(Item*);
    ~ItemPtr();
};
struct ItemList {
    void* proxy; void* head; unsigned size;
    void push_back(const ItemPtr&);
};

class ReplicatorBase : public PluginInterface {
public:
    ReplicatorBase& self() { return *this; }
public:
    char pad0[0x38];
    ClassDictionarySender classNamesOut;     // +0x3c
    ClassDictionaryReceiver classNamesIn;    // +0x60
    PropDictionarySender propNamesOut;       // +0x80
    PropDictionaryReceiver propNamesIn;      // +0xa4
    char pad1[0x20];
protected:
    InstanceVector replicationContainers;    // +0xe4
    char pad2[0xc];
    ItemList pendingItems;                   // +0x100
    char pad3[0x9c];
    Profiling::CodeProfiler* profileDataIn;  // +0x1a8
    char pad4[0x2c];
    bool receivedGlobals;                    // +0x1d8
public:
    bool disconnected;                       // +0x1d9
    RakPeerInterface* peer;                  // +0x1dc
    const SystemAddress remotePlayerId;      // +0x1e0
};
class Replicator : public InstanceBase, public Reflection::DescribedBase, public ReplicatorBase {
public:

    static Reflection::SignalDesc<Replicator, void(std::string, bool)> event_Disconnection;

    virtual PluginReceiveResult OnReceive(RakPeerInterface*, Packet*);
private:
    bool deserializeId(RakNet::BitStream&, Guid::Data&);
    void addInstance(Instance*, Guid::Data);
    void readInstances(RakNet::BitStream&, Instance*);
    void receiveData(Packet* packet);
    PluginReceiveResult OnReceive_ID_TIMESTAMP(Packet*);
    __forceinline void sendDictionaries(RakPeerInterface* peer)
    {
        RakNet::BitStream bitStream;
        bitStream << (unsigned char)ID_DICTIONARIES;
        classNamesOut.send(bitStream);
        propNamesOut.send(bitStream);
        peer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, remotePlayerId, false);
    }
};

PluginReceiveResult Replicator::OnReceive(RakPeerInterface* peer, Packet* packet)
{
    ReplicatorBase& base = self();
    bool same = packet->systemAddress == remotePlayerId;
    if (same)
    {
        Profiling::Mark mark(*profileDataIn, false);
        try
        {
            switch (packet->data[0])
            {
            case ID_TIMESTAMP_:
                return OnReceive_ID_TIMESTAMP(packet);

            case ID_CONNECTION_REQUEST_ACCEPTED_:
            case ID_NEW_INCOMING_CONNECTION_:
                {
                    RakNet::BitStream bitStream;
                    bitStream << (unsigned char)ID_DICTIONARIES;
                    classNamesOut.send(bitStream);
                    propNamesOut.send(bitStream);
                    peer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, remotePlayerId, false);
                }
                break;

            case ID_DICTIONARIES:
                {
                    RakNet::BitStream bitStream(packet->data, packet->length, false);
                    bitStream.IgnoreBits(8);
                    classNamesIn.receive(bitStream);
                    propNamesIn.receive(bitStream);
                }
                return RR_STOP_PROCESSING_AND_DEALLOCATE;

            case ID_CONNECTION_LOST_:
                standardOut()->print(MESSAGE_WARNING, "Lost connection to %s\n", packet->systemAddress.ToString());
                event_Disconnection.fire(this, packet->systemAddress.ToString(), true);
                disconnected = true;
                break;

            case ID_DISCONNECTION_NOTIFICATION_:
                standardOut()->print(MESSAGE_INFO, "Disconnect from %s", packet->systemAddress.ToString());
                event_Disconnection.fire(this, packet->systemAddress.ToString(), false);
                disconnected = true;
                break;

            case ID_DATA:
                receiveData(packet);
                return RR_STOP_PROCESSING_AND_DEALLOCATE;

            case ID_REQUEST_MARKER:
                {
                    RakNet::BitStream bitStream(packet->data, packet->length, false);
                    bitStream.IgnoreBits(8);
                    int id;
                    bitStream >> id;
                    pendingItems.push_back(ItemPtr(new MarkerItem(*this, id)));
                }
                return RR_STOP_PROCESSING_AND_DEALLOCATE;

            case ID_SET_GLOBALS:
                {
                    RakNet::BitStream bitStream(packet->data, packet->length, false);
                    bitStream.IgnoreBits(8);
                    std::string scope;
                    bitStream >> scope;
                    if (lookupName(scope) == Guid::getLocalScope())
                        throw std::exception("Remote peer is running in the same process");
                    InstanceIterator end = replicationContainers.end();
                    for (InstanceIterator iter = replicationContainers.begin(); iter != end; ++iter)
                    {
                        Guid::Data id;
                        deserializeId(bitStream, id);
                        (*iter)->setGuid(id);
                        addInstance(*iter, id);
                    }
                    readInstances(bitStream, replicationContainers[0]);
                }
                receivedGlobals = true;
                return RR_STOP_PROCESSING_AND_DEALLOCATE;
            }
        }
        catch (std::exception& e)
        {
            base.disconnected = true;
            const char* what = safeWhat(e);
            standardOut()->print(MESSAGE_ERROR, "Replicator::OnReceive packet %d: %s", packet->data[0], what);
            return RR_STOP_PROCESSING_AND_DEALLOCATE;
        }
    }
    return RR_CONTINUE_PROCESSING;
}
}
}
