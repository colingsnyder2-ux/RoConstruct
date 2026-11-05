// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Packet;
namespace DataStructures {
template <class SingleProducerConsumerType>
class SingleProducerConsumer
{
public:
	SingleProducerConsumerType* WriteLock(void);
	void WriteUnlock(void);
private:
	struct DataPlusPtr
	{
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
inline void SingleProducerConsumer<T>::WriteUnlock(void)
{
	writeCount++;
	writePointer->readyToRead=true;
	writePointer=writePointer->next;
}
}
class RakPeer {
public:
	char pad[0xb58];
	DataStructures::SingleProducerConsumer<Packet*> packetSingleProducerConsumer;
	void AddPacketToProducer(Packet* p);
};
void RakPeer::AddPacketToProducer(Packet* p)
{
	Packet** packetPtr = packetSingleProducerConsumer.WriteLock();
	*packetPtr = p;
	packetSingleProducerConsumer.WriteUnlock();
}
