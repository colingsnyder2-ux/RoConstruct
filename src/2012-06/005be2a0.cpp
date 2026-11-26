// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// RakNet::RakPeer::AttachPlugin, standalone. The vendor unit matched except for the
// __LINE__ values passed to List::Insert (0x9a2 = 2466 and 0x9ab = 2475 in the 2012-06 RakPeer.cpp).
extern const char rakPeerFile[]; // the build machine's __FILE__ string for RakPeer.cpp
struct RakPeerInterface;
struct PluginInterface2 {
    virtual ~PluginInterface2();
    virtual void OnAttach();
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual bool UsesReliabilityLayer() const;
    void SetRakPeerInterface(RakPeerInterface* ptr);
};
template<class T> struct List {
    T* listArray; unsigned list_size; unsigned allocation_size;
    void Insert(const T& input, const char* file, unsigned int line);
    unsigned GetIndexOf(const T& input) const {
        for (unsigned i = 0; i < list_size; ++i)
            if (listArray[i] == input)
                return i;
        return 0xFFFFFFFF;
    }
};
void* rakRealloc(void* p, unsigned n, const char* file, unsigned line);
template<class T> void List<T>::Insert(const T& input, const char* file, unsigned int line)
{
    if (list_size == allocation_size) {
        if (allocation_size == 0) allocation_size = 16; else allocation_size *= 2;
        listArray = (T*)rakRealloc(listArray, allocation_size * sizeof(T), file, line);
    }
    listArray[list_size] = input;
    ++list_size;
}struct RakPeerInterface { virtual void AttachPlugin(PluginInterface2* plugin) = 0; };
struct RakPeer : RakPeerInterface {
    char pad[0x2cc - 4];
    List<PluginInterface2*> pluginListTS, pluginListNTS;
    virtual void AttachPlugin(PluginInterface2* plugin);
};
void RakPeer::AttachPlugin(PluginInterface2* plugin)
{
    bool isNotThreadsafe = plugin->UsesReliabilityLayer();
    if (isNotThreadsafe)
    {
        if (pluginListNTS.GetIndexOf(plugin) == 0xFFFFFFFF)
        {
            plugin->SetRakPeerInterface(this);
            plugin->OnAttach();
            pluginListNTS.Insert(plugin, rakPeerFile, 2466);
        }
    }
    else
    {
        if (pluginListTS.GetIndexOf(plugin) == 0xFFFFFFFF)
        {
            plugin->SetRakPeerInterface(this);
            plugin->OnAttach();
            pluginListTS.Insert(plugin, rakPeerFile, 2475);
        }
    }
}