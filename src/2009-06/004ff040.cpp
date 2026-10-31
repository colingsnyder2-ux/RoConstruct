// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace DataStructures {
template<class T> class Queue { public: Queue(); ~Queue(); T* array; unsigned head, tail, allocation_size; };
}
class RPCMap { public: RPCMap(); ~RPCMap(); void* a; unsigned b, c; };
namespace RakNet {
class ThreadsafePacketLogger {
public:
    ~ThreadsafePacketLogger();
    char pad[0x30];
    DataStructures::Queue<char*> logQueue;
    char pad2[0x13a8 - 0x30 - 16];
    RPCMap rpcMap;
};
ThreadsafePacketLogger::~ThreadsafePacketLogger() {}
}
