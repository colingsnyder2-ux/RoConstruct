// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// RakNet::RakPeer::IsBanned, standalone. The vendor unit matched except for the __LINE__ value
// passed to rakFree_Ex (0x704 = 1796 in the 2012-06 RakPeer.cpp).
#include <string.h>
extern const char rakPeerFile[]; // the build machine's __FILE__ string for RakPeer.cpp
extern void (*rakFree_Ex)(void* p, const char* file, unsigned int line);
typedef unsigned int TimeMS;
TimeMS GetTimeMS();
struct SimpleMutex { void Lock(); void Unlock(); };
template<class T> struct List {
    T* listArray; unsigned list_size; unsigned allocation_size;
    unsigned Size() const { return list_size; }
    T& operator[](unsigned i) const { return listArray[i]; }
    void RemoveFromEnd(unsigned num = 1) { list_size -= num; }
    void RemoveAtIndex(const unsigned int position);
};
template<class T> void List<T>::RemoveAtIndex(const unsigned int position)
{
    if (position < list_size) {
        for (unsigned int counter = position; counter < list_size - 1; ++counter)
            listArray[counter] = listArray[counter + 1];
        RemoveFromEnd();
    }
}
struct BanStruct { char* IP; TimeMS timeout; };
struct RakPeer {
    virtual bool IsBanned(const char* IP);
    char pad[0x2a8 - 4];
    SimpleMutex banListMutex;
    char pad2[0x2c0 - 0x2a9];
    List<BanStruct*> banList;
};
bool RakPeer::IsBanned(const char* IP)
{
    unsigned banListIndex, characterIndex;
    TimeMS time;
    BanStruct* temp;

    if (IP == 0 || IP[0] == 0 || strlen(IP) > 15)
        return false;

    banListIndex = 0;

    if (banList.Size() == 0)
        return false;

    time = GetTimeMS();

    banListMutex.Lock();

    while (banListIndex < banList.Size())
    {
        if (banList[banListIndex]->timeout > 0 && banList[banListIndex]->timeout < time)
        {
            temp = banList[banListIndex];
            banList[banListIndex] = banList[banList.Size() - 1];
            banList.RemoveAtIndex(banList.Size() - 1);
            rakFree_Ex(temp->IP, rakPeerFile, 1796);
            delete temp;
        }
        else
        {
            characterIndex = 0;
            while (true)
            {
                if (banList[banListIndex]->IP[characterIndex] == IP[characterIndex])
                {
                    if (IP[characterIndex] == 0)
                    {
                        banListMutex.Unlock();
                        return true;
                    }
                    characterIndex++;
                }
                else
                {
                    if (banList[banListIndex]->IP[characterIndex] == 0 || IP[characterIndex] == 0)
                        break;
                    if (banList[banListIndex]->IP[characterIndex] == '*')
                    {
                        banListMutex.Unlock();
                        return true;
                    }
                    break;
                }
            }
            banListIndex++;
        }
    }

    banListMutex.Unlock();
    return false;
}