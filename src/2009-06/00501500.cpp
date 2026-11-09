// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string.h>

extern void* (*rakMalloc)(size_t size);

struct SocketDescriptor
{
    unsigned short port;
    char hostAddress[32];
    bool flag;
};

namespace DataStructures {
template <class T>
class SingleProducerConsumer
{
public:
    T* WriteLock(void);
    void WriteUnlock(void)
    {
        writeCount++;
        writePointer->readyToRead = true;
        writePointer = writePointer->next;
    }
private:
    struct DataPlusPtr
    {
        T object;
        volatile bool readyToRead;
        volatile DataPlusPtr* next;
    };
    volatile DataPlusPtr* readAheadPointer;
    volatile DataPlusPtr* writeAheadPointer;
    volatile DataPlusPtr* readPointer;
    volatile DataPlusPtr* writePointer;
    unsigned readCount, writeCount;
};
}

class RakPeer
{
public:
    void RebindSocket(int socketIndex, const SocketDescriptor* sd);

    struct BufferedCommandStruct
    {
        char pad0[0x24];
        char* data;
        int pad28;
        int socketIndex;
        bool flag;
        char pad31[7];
        unsigned short port;
        enum { BCS_SEND, BCS_CLOSE_CONNECTION, BCS_GET_SOCKET, BCS_REBIND } command;
    };
    char pad[0xa0c];
    DataStructures::SingleProducerConsumer<BufferedCommandStruct> bufferedCommands;
};

void RakPeer::RebindSocket(int socketIndex, const SocketDescriptor* sd)
{
    BufferedCommandStruct* bcs = bufferedCommands.WriteLock();
    bcs->command = BufferedCommandStruct::BCS_REBIND;
    bcs->data = (char*)rakMalloc(32);
    memcpy(bcs->data, sd->hostAddress, 32);
    bcs->port = sd->port;
    bcs->socketIndex = socketIndex;
    bcs->flag = sd->flag;
    bufferedCommands.WriteUnlock();
}
