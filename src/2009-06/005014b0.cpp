// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace DataStructures {
template <class SingleProducerConsumerType>
class SingleProducerConsumer {
public:
    SingleProducerConsumerType* WriteLock(void);
    void WriteUnlock(void)
    {
        writeCount++;
        writePointer->readyToRead = true;
        writePointer = writePointer->next;
    }
private:
    struct DataPlusPtr {
        SingleProducerConsumerType object;
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
struct BufferedCommandStruct {
    char pad[0x24];
    char* data;
    unsigned char orderingChannel;
    int priority;
    int pad2;
    int systemIndex;
    int pad3;
    enum { BCS_SEND, BCS_CLOSE_CONNECTION, BCS_OTHER } command;
};
class RakPeer {
public:
    void CloseConnectionInternal(int index, unsigned char orderingChannel, int priority);
    char pad[0xa0c];
    DataStructures::SingleProducerConsumer<BufferedCommandStruct> bufferedCommands;
};
void RakPeer::CloseConnectionInternal(int index, unsigned char orderingChannel, int priority)
{
    BufferedCommandStruct* bcs = bufferedCommands.WriteLock();
    bcs->systemIndex = index;
    bcs->command = BufferedCommandStruct::BCS_OTHER;
    bcs->data = 0;
    bcs->orderingChannel = orderingChannel;
    bcs->priority = priority;
    bufferedCommands.WriteUnlock();
}
