// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
namespace DataStructures {
template<class list_type> class List {
public:
    void Insert(const list_type input, const unsigned int position);
    void Insert(const list_type input);
    unsigned int Size(void) const { return list_size; }
private:
    list_type* listArray;
    unsigned int list_size;
    unsigned int allocation_size;
};
template<class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
class OrderedList {
public:
    unsigned GetIndexFromKey(const key_type& key, bool* objectExists) const;
    unsigned Insert(const key_type& key, const data_type& data);
protected:
    DataStructures::List<data_type> orderedList;
};
template<class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
unsigned OrderedList<key_type, data_type, default_comparison_function>::Insert(const key_type& key, const data_type& data)
{
    bool objectExists;
    unsigned index;
    index = GetIndexFromKey(key, &objectExists);
    if (objectExists)
        return (unsigned)-1;
    if (index >= orderedList.Size())
    {
        orderedList.Insert(data);
        return orderedList.Size() - 1;
    }
    else
    {
        orderedList.Insert(data, index);
        return index;
    }
}
}
class Replica;
typedef unsigned int RakNetTime;
class ReplicaManager {
public:
    struct RemoteObject
    {
        Replica* replica;
        bool inScope;
        RakNetTime lastSendTime;
    };
    static int RemoteObjectComp(Replica* const& key, const ReplicaManager::RemoteObject& data);
};
template class DataStructures::OrderedList<Replica*, ReplicaManager::RemoteObject, ReplicaManager::RemoteObjectComp>;
