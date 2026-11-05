// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern void (*rakFree)(void*);
namespace DataStructures {
template <class SingleProducerConsumerType>
class SingleProducerConsumer {
public:
    SingleProducerConsumerType* ReadLock(void)
    {
        if (readAheadPointer == writePointer ||
            readAheadPointer->readyToRead == false)
        {
            return 0;
        }
        volatile DataPlusPtr *last;
        last = readAheadPointer;
        readAheadPointer = readAheadPointer->next;
        return (SingleProducerConsumerType*)last;
    }
    void ReadUnlock(void)
    {
        readCount++;
        readPointer->readyToRead = false;
        readPointer = readPointer->next;
    }
    void Clear(void);
private:
    struct DataPlusPtr {
        SingleProducerConsumerType object;
        volatile bool readyToRead;
        volatile DataPlusPtr *next;
    };
    volatile DataPlusPtr *readAheadPointer;
    volatile DataPlusPtr *writeAheadPointer;
    volatile DataPlusPtr *readPointer;
    volatile DataPlusPtr *writePointer;
    unsigned readCount, writeCount;
};
}
struct BufferedCommandStruct { char pad[0x24]; char* data; char pad2[0x18]; };
class RakPeer {
    char pad[0xa0c];
    DataStructures::SingleProducerConsumer<BufferedCommandStruct> bufferedCommands;
public:
    void ClearBufferedCommands(void);
};
void RakPeer::ClearBufferedCommands(void)
{
    BufferedCommandStruct *bcs;
    while ((bcs = bufferedCommands.ReadLock()) != 0)
    {
        if (bcs->data)
            rakFree(bcs->data);
        bufferedCommands.ReadUnlock();
    }
    bufferedCommands.Clear();
}
