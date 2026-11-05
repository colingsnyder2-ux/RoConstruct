// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace DataStructures {
template <class SingleProducerConsumerType>
class SingleProducerConsumer {
public:
    ~SingleProducerConsumer();
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
template <class T>
SingleProducerConsumer<T>::~SingleProducerConsumer()
{
    volatile DataPlusPtr *next;
    readPointer = writeAheadPointer->next;
    while (readPointer != writeAheadPointer) {
        next = readPointer->next;
        delete (char*) readPointer;
        readPointer = next;
    }
    delete (char*) readPointer;
}
}
struct BufferedCommandStruct { char data[0x40]; };
template class DataStructures::SingleProducerConsumer<BufferedCommandStruct>;
