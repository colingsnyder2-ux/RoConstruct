// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
struct SystemAddress {
    unsigned int binaryAddress;
    unsigned short port;
    bool operator==(const SystemAddress& right) const;
};
extern const SystemAddress UNASSIGNED_SYSTEM_ADDRESS;
struct SystemIndexEntry { SystemAddress systemAddress; unsigned index; };
int SystemAddressAndIndexComparison(const SystemAddress& key, const SystemIndexEntry& data);
namespace DataStructures {
template <class list_type> class List {
public:
    list_type* listArray;
    unsigned int list_size;
    unsigned int allocation_size;
    list_type& operator[](const unsigned int position) const { return listArray[position]; }
};
template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
class OrderedList {
public:
    unsigned GetIndexFromKey(const key_type& key, bool* objectExists, int (*cf)(const key_type&, const data_type&) = default_comparison_function) const;
    data_type& operator[](const unsigned int position) const { return orderedList[position]; }
protected:
    List<data_type> orderedList;
};
}
class RakPeer {
public:
    struct RemoteSystemStruct {
        bool isActive;
        SystemAddress systemAddress;
        char pad[0x13d0 - 12];
    };
    int GetIndexFromSystemAddress(const SystemAddress systemAddress, bool calledFromNetworkThread);
    void* vptr;
    char pad0[4];
    unsigned short maximumNumberOfPeers;
    char pad1[0x53c - 0xa];
    RemoteSystemStruct* remoteSystemList;
    DataStructures::OrderedList<SystemAddress, SystemIndexEntry, SystemAddressAndIndexComparison> remoteSystemLookup;
};
int RakPeer::GetIndexFromSystemAddress(const SystemAddress systemAddress, bool calledFromNetworkThread)
{
    unsigned i;

    if (systemAddress == UNASSIGNED_SYSTEM_ADDRESS)
        return -1;

    if (calledFromNetworkThread)
    {
        bool objectExists;
        unsigned index;
        index = remoteSystemLookup.GetIndexFromKey(systemAddress, &objectExists);
        if (objectExists)
            return remoteSystemLookup[index].index;
        else
            return -1;
    }
    else
    {
        for (i = 0; i < maximumNumberOfPeers; i++)
            if (remoteSystemList[i].isActive && remoteSystemList[i].systemAddress == systemAddress)
                return i;
        for (i = 0; i < maximumNumberOfPeers; i++)
            if (remoteSystemList[i].systemAddress == systemAddress)
                return i;
    }

    return -1;
}
