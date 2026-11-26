// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// RakNet::RakPeer::IsInSecurityExceptionList, standalone with the 2012-06 member offsets
// (securityExceptionMutex at 0x408, securityExceptionList at 0x48c).
struct SimpleMutex { void Lock(); void Unlock(); };
struct RakString { void* sharedString; bool IPAddressMatch(const char* IP); };
template<class T> struct List {
    T* listArray; unsigned list_size; unsigned allocation_size;
    unsigned Size() const { return list_size; }
    T& operator[](unsigned i) const { return listArray[i]; }
};
struct RakPeer {
    virtual bool IsInSecurityExceptionList(const char* ip);
    char pad4[0x408 - 4];
    SimpleMutex securityExceptionMutex;
    char pad[0x48c - 0x409];
    List<RakString> securityExceptionList;
};
bool RakPeer::IsInSecurityExceptionList(const char* ip)
{
    if (securityExceptionList.Size() == 0)
        return false;
    unsigned i = 0;
    securityExceptionMutex.Lock();
    for (; i < securityExceptionList.Size(); i++) {
        if (securityExceptionList[i].IPAddressMatch(ip)) {
            securityExceptionMutex.Unlock();
            return true;
        }
    }
    securityExceptionMutex.Unlock();
    return false;
}