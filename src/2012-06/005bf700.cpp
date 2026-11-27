// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#define _FILE_AND_LINE_ "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\Network\\raknet\\Source\\RakPeer.cpp", __LINE__
namespace DataStructures {
template <class list_type> class List {
public:
    list_type* listArray;
    unsigned int list_size;
    unsigned int allocation_size;
    void Push(const list_type& input, const char* file, unsigned int line);
    void Clear(bool doNotDeallocateSmallBlocks, const char* file, unsigned int line)
    {
        if (allocation_size == 0)
            return;
        if (allocation_size > 512 || doNotDeallocateSmallBlocks == false)
        {
            delete[] listArray;
            allocation_size = 0;
            listArray = 0;
        }
        list_size = 0;
    }
};
}
namespace RakNet {
struct SystemAddress { int data[5]; };
struct RakNetGUID { int data[4]; };
class RakPeer {
public:
    struct RemoteSystemStruct {
        enum ConnectMode { NO_ACTION, DISCONNECT_ASAP, DISCONNECT_ASAP_SILENTLY, DISCONNECT_ON_NO_ACK,
            REQUESTED_CONNECTION, HANDLING_CONNECTION_REQUEST, UNVERIFIED_SENDER, CONNECTED };
        bool isActive;
        SystemAddress systemAddress;
        char pad[0x11e0 - 0x18];
        RakNetGUID guid;
        char pad2[0x10];
        ConnectMode connectMode;
    };
    virtual void GetSystemList(DataStructures::List<SystemAddress>& addresses, DataStructures::List<RakNetGUID>& guids) const;
    volatile bool endThreads;
    char pad0[0x22c - 8];
    RemoteSystemStruct* remoteSystemList;
    RemoteSystemStruct** activeSystemList;
    unsigned int activeSystemListSize;
};
#line 1621
void RakPeer::GetSystemList(DataStructures::List<SystemAddress>& addresses, DataStructures::List<RakNetGUID>& guids) const
{
    addresses.Clear(false, _FILE_AND_LINE_);
    guids.Clear(false, _FILE_AND_LINE_);

    if (remoteSystemList == 0 || endThreads == true)
        return;

    unsigned int i;
    for (i = 0; i < activeSystemListSize; i++)
    {
        if ((activeSystemList[i])->isActive &&
            (activeSystemList[i])->connectMode == RakPeer::RemoteSystemStruct::CONNECTED)
        {
            addresses.Push((activeSystemList[i])->systemAddress, _FILE_AND_LINE_);
            guids.Push((activeSystemList[i])->guid, _FILE_AND_LINE_);
        }
    }
}
}