// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// RakNet::RakPeer buffered-list clear, standalone; the only server diff was the __LINE__ (0x6d1 = 1745)
// passed to rakFree_Ex.
struct SimpleMutex { void Lock(); void Unlock(); };
extern void (*rakFree_Ex)(void* p, const char* file, unsigned int line);
struct Item { char* data; };
extern const char rakPeerFile[]; // the build machine's __FILE__ string for RakPeer.cpp
template<class T> struct List {
    T* listArray; unsigned list_size; unsigned allocation_size;
    unsigned Size() const { return list_size; }
    T& operator[](unsigned i) const { return listArray[i]; }
    void Clear(bool doNotDeallocateSmallBlocks) {
        if (allocation_size == 0) return;
        if (allocation_size > 512 || doNotDeallocateSmallBlocks == false) {
            delete[] listArray;
            allocation_size = 0;
            listArray = 0;
        }
        list_size = 0;
    }
};
struct RakPeer {
    char pad[0x2a8];
    SimpleMutex mutex;
    char pad2[0x2c0 - 0x2a9];
    List<Item*> list;
    void Clear();
};
void RakPeer::Clear()
{
    unsigned i = 0;
    mutex.Lock();
    for (; i < list.Size(); i++) {
#line 1745
        rakFree_Ex(list[i]->data, rakPeerFile, __LINE__);
        delete list[i];
    }
    list.Clear(false);
    mutex.Unlock();
}