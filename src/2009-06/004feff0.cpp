// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace DataStructures {
template<class T> class Queue { public: Queue(); ~Queue(); T* array; unsigned head, tail, allocation_size; };
template<class T> class List { public: List(); T* listArray; unsigned list_size, allocation_size; };
}
namespace RakNet {
class ThreadsafePacketLogger {
public:
    ThreadsafePacketLogger();
    char pad[0x30];
    DataStructures::Queue<char*> logQueue;
    char pad2[0x13a8 - 0x30 - 16];
    DataStructures::List<char*> list;
};
ThreadsafePacketLogger::ThreadsafePacketLogger() {}
}
