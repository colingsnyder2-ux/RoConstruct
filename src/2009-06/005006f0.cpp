// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
struct SystemAddress
{
	unsigned int binaryAddress;
	unsigned short port;
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
		list_type& operator[] ( const unsigned int position ) const { return listArray[ position ]; }
		list_type* listArray;
		unsigned int list_size;
		unsigned int allocation_size;
	};

	template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
	class OrderedList
	{
	public:
		unsigned GetIndexFromKey(const key_type &key, bool *objectExists, int (*cf)(const key_type&, const data_type&)=default_comparison_function) const;
		data_type& operator[]( const unsigned int position ) const { return orderedList[position]; }
	protected:
		DataStructures::List<data_type> orderedList;
	};
}

struct SystemAddressAndIndex{SystemAddress systemAddress;unsigned index;};
int SystemAddressAndIndexComp( const SystemAddress &key, const SystemAddressAndIndex &data );

class RakPeer
{
public:
	virtual ~RakPeer();
	struct RemoteSystemStruct
	{
		bool isActive;
		SystemAddress systemAddress;
		char pad[0x13d0-0xc];
	};
protected:
	RemoteSystemStruct *GetRemoteSystemFromSystemAddress( const SystemAddress systemAddress, bool calledFromNetworkThread, bool onlyActive ) const;
	char pad0[4];
	unsigned short maximumNumberOfPeers;
	char pad1[0x53c-0xa];
	RemoteSystemStruct* remoteSystemList;
	DataStructures::OrderedList<SystemAddress, SystemAddressAndIndex, SystemAddressAndIndexComp> remoteSystemLookup;
};

RakPeer::RemoteSystemStruct *RakPeer::GetRemoteSystemFromSystemAddress( const SystemAddress systemAddress, bool calledFromNetworkThread, bool onlyActive ) const
{
	unsigned i;

	if ( systemAddress == UNASSIGNED_SYSTEM_ADDRESS )
		return 0;

	if (calledFromNetworkThread)
	{
		bool objectExists;
		unsigned index;
		index = remoteSystemLookup.GetIndexFromKey(systemAddress, &objectExists);
		if (objectExists)
		{
			return remoteSystemList + remoteSystemLookup[index].index;
		}
	}
	else
	{
		int deadConnectionIndex=-1;

		for ( i = 0; i < maximumNumberOfPeers; i++ )
		{
			if (remoteSystemList[ i ].systemAddress == systemAddress)
			{
				if ( remoteSystemList[ i ].isActive )
					return remoteSystemList + i;
				else if (deadConnectionIndex==-1)
					deadConnectionIndex=i;
			}
		}

		if (deadConnectionIndex!=-1 && onlyActive==false)
			return remoteSystemList + deadConnectionIndex;
	}

	return 0;
}
