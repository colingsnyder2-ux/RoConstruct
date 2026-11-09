// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
struct SystemAddress
{
	unsigned int binaryAddress;
	unsigned short port;
	SystemAddress& operator = ( const SystemAddress& input )
	{
		binaryAddress = input.binaryAddress;
		port = input.port;
		return *this;
	}
	bool operator==( const SystemAddress& right ) const;
	bool operator!=( const SystemAddress& right ) const;
};
extern const SystemAddress UNASSIGNED_SYSTEM_ADDRESS;

namespace DataStructures
{
	template <class list_type>
	class List
	{
	public:
		list_type* listArray;
		unsigned int list_size;
		unsigned int allocation_size;
	};

	template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
	class OrderedList
	{
	public:
		unsigned Remove(const key_type &key, int (*cf)(const key_type&, const data_type&)=default_comparison_function);
	protected:
		DataStructures::List<data_type> orderedList;
	};

	template <class SingleProducerConsumerType>
	class SingleProducerConsumer
	{
	public:
		SingleProducerConsumerType* WriteLock(void);
		void WriteUnlock(void)
		{
			writeCount++;
			writePointer->readyToRead=true;
			writePointer=writePointer->next;
		}
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
}

struct SystemAddressAndIndex{SystemAddress systemAddress;unsigned index;};
int SystemAddressAndIndexComp( const SystemAddress &key, const SystemAddressAndIndex &data );

class ReliabilityLayer
{
public:
	void Reset( bool resetVariables );
};

class RakPeer
{
public:
	virtual ~RakPeer();
	struct RemoteSystemStruct
	{
		bool isActive;
		SystemAddress systemAddress;
		char pad[0x30-0xc];
		ReliabilityLayer reliabilityLayer;
		char pad2[0x13d0-0x31];
	};
	struct BufferedCommandStruct
	{
		int numberOfBitsToSend;
		int priority;
		int reliability;
		char orderingChannel;
		SystemAddress systemAddress;
		char pad0[0x24-0x18];
		char *data;
		char pad1[0x3c-0x28];
		enum {BCS_SEND, BCS_CLOSE_CONNECTION, BCS_DO_NOTHING} command;
	};
protected:
	void CloseConnectionInternal( const SystemAddress target, bool sendDisconnectionNotification, bool performImmediate, unsigned char orderingChannel );
	void NotifyAndFlagForShutdown( const SystemAddress systemAddress, bool performImmediate, unsigned char orderingChannel );
	volatile bool endThreads;
	char pad0[3];
	unsigned short maximumNumberOfPeers;
	char pad1[0x53c-0xa];
	RemoteSystemStruct* remoteSystemList;
	DataStructures::OrderedList<SystemAddress, SystemAddressAndIndex, SystemAddressAndIndexComp> remoteSystemLookup;
	char pad2[0xa0c-0x54c];
	DataStructures::SingleProducerConsumer<BufferedCommandStruct> bufferedCommands;
};

void RakPeer::CloseConnectionInternal( const SystemAddress target, bool sendDisconnectionNotification, bool performImmediate, unsigned char orderingChannel )
{
	unsigned i;

	if (target==UNASSIGNED_SYSTEM_ADDRESS)
		return;

	if ( remoteSystemList == 0 || endThreads == true )
		return;

	if (sendDisconnectionNotification)
	{
		NotifyAndFlagForShutdown(target, performImmediate, orderingChannel);
	}
	else
	{
		if (performImmediate)
		{
			for ( i=0; i < maximumNumberOfPeers; i++ )
			{
				if ( remoteSystemList[ i ].isActive && remoteSystemList[ i ].systemAddress == target )
				{
					remoteSystemList[ i ].isActive=false;
					remoteSystemList[ i ].reliabilityLayer.Reset(false);
					remoteSystemLookup.Remove(target);
					break;
				}
			}
		}
		else
		{
			BufferedCommandStruct *bcs;
			bcs=bufferedCommands.WriteLock();
			bcs->command=BufferedCommandStruct::BCS_CLOSE_CONNECTION;
			bcs->systemAddress=target;
			bcs->data=0;
			bcs->orderingChannel=orderingChannel;
			bufferedCommands.WriteUnlock();
		}
	}
}
