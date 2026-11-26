// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// RakNet::RakPeer::AddToBanList, standalone. The vendor unit matched except for the __LINE__ values
// (0x690 = 1680 for rakMalloc_Ex, 0x697 = 1687 for List::Insert in the 2012-06 RakPeer.cpp).
#include <string.h>
extern const char rakPeerFile[]; // the build machine's __FILE__ string for RakPeer.cpp
extern void* (*rakMalloc_Ex)(size_t size, const char* file, unsigned int line);
void* rakRealloc(void* p, unsigned n, const char* file, unsigned line);
typedef unsigned int TimeMS;
TimeMS GetTimeMS();
struct SimpleMutex { void Lock(); void Unlock(); };
template<class T> struct List {
    T* listArray; unsigned list_size; unsigned allocation_size;
    unsigned Size() const { return list_size; }
    T& operator[](unsigned i) const { return listArray[i]; }
    void Insert(const T& input, const char* file, unsigned int line);
};
// Body visible as in the vendor unit (keeps the argument object out of the escape set).
struct BanStruct { char* IP; TimeMS timeout; };
template<class T> void List<T>::Insert(const T& input, const char* file, unsigned int line)
{
    if (list_size == allocation_size) {
        T* new_array;
        if (allocation_size == 0)
            allocation_size = 16;
        else
            allocation_size *= 2;
        new_array = (T*)rakRealloc(0, allocation_size * sizeof(T), file, line);
        if (listArray) {
            for (unsigned int counter = 0; counter < list_size; ++counter)
                new_array[counter] = listArray[counter];
            rakRealloc(listArray, 0, file, line);
        }
        listArray = new_array;
    }
    listArray[list_size] = input;
    ++list_size;
}
// The vendor unit calls Insert from many places; a second call site keeps it out of line here.
template<class T> void insertTwice(List<T>& l, const T& a) { l.Insert(a, 0, 0); l.Insert(a, 0, 1); }
template void insertTwice<BanStruct*>(List<BanStruct*>&, BanStruct* const&);struct RakPeer {
    virtual void AddToBanList(const char* IP, TimeMS milliseconds);
    char pad[0x2a8 - 4];
    SimpleMutex banListMutex;
    char pad2[0x2c0 - 0x2a9];
    List<BanStruct*> banList;
};
void RakPeer::AddToBanList(const char* IP, TimeMS milliseconds)
{
    unsigned index;
    TimeMS time = GetTimeMS();

    if (IP == 0 || IP[0] == 0 || strlen(IP) > 15)
        return;

    index = 0;

    banListMutex.Lock();

    for (; index < banList.Size(); index++)
    {
        if (strcmp(IP, banList[index]->IP) == 0)
        {
            if (milliseconds == 0)
                banList[index]->timeout = 0;
            else
                banList[index]->timeout = time + milliseconds;
            banListMutex.Unlock();
            return;
        }
    }

    banListMutex.Unlock();

    BanStruct* banStruct = new BanStruct;
    banStruct->IP = (char*)rakMalloc_Ex(16, rakPeerFile, 1680);
    if (milliseconds == 0)
        banStruct->timeout = 0;
    else
        banStruct->timeout = time + milliseconds;
    strcpy(banStruct->IP, IP);
    banListMutex.Lock();
    banList.Insert(banStruct, rakPeerFile, 1687);
    banListMutex.Unlock();
}