// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RakNet {
class SimpleMutex {
public:
    void Lock();
    void Unlock();
};
class RakString {
public:
    void* sharedString;
    RakString(const char* format, ...);
    ~RakString();
};
}
namespace DataStructures {
template <class T> class List {
public:
    T* listArray;
    unsigned int list_size;
    unsigned int allocation_size;
    void Insert(const T& input, const char* file, unsigned int line);
};
}
namespace RakNet {
class RakPeer {
public:
    char pad0[0x408];
    SimpleMutex securityExceptionMutex;
    char pad1[0x48c - 0x408 - 1];
    DataStructures::List<RakString> securityExceptionList;
    void AddToSecurityExceptionList(const char* ip);
};
void RakPeer::AddToSecurityExceptionList(const char* ip)
{
    securityExceptionMutex.Lock();
    securityExceptionList.Insert(RakString(ip), "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\Network\\raknet\\Source\\RakPeer.cpp", 695);
    securityExceptionMutex.Unlock();
}
}