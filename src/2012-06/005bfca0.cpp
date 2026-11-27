// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RakNet {
typedef unsigned short SystemIndex;
struct SystemAddress
{
	SystemAddress();
	union
	{
		struct { short sin_family; unsigned short sin_port; unsigned long sin_addr; char sin_zero[8]; } addr4;
	} address;
	unsigned short debugPort;
	static unsigned long ToInteger( const SystemAddress &sa );
	SystemAddress& operator = ( const SystemAddress& input );
	bool operator==( const SystemAddress& right ) const;
	bool operator!=( const SystemAddress& right ) const;
	SystemIndex systemIndex;
};
extern const SystemAddress UNASSIGNED_SYSTEM_ADDRESS;
}
namespace DataStructures {
template <class T> class MemoryPool
{
public:
	T *Allocate(const char *file, unsigned int line);
	void Release(T *m, const char *file, unsigned int line);
	void *a, *b; int c, d;
};
}
namespace RakNet {
class RakPeer
{
public:
	struct RemoteSystemStruct
	{
		bool isActive;
		SystemAddress systemAddress;
		char pad[0x1208 - 0x18];
	};
	struct RemoteSystemIndex { unsigned index; RemoteSystemIndex *next; };
	virtual ~RakPeer();
	unsigned int RemoteSystemLookupHashIndex(const SystemAddress &sa) const;
	void ReferenceRemoteSystem(const SystemAddress &sa, unsigned int remoteSystemListIndex);
	void DereferenceRemoteSystem(const SystemAddress &sa);
	RemoteSystemStruct* GetRemoteSystem(const SystemAddress &sa) const;
	unsigned int GetRemoteSystemIndex(const SystemAddress &sa) const;
	char pad4[0xe - 4];
	unsigned short maximumNumberOfPeers;
	char pad10[0x22c - 0x10];
	RemoteSystemStruct* remoteSystemList;
	void *activeSystemList;
	unsigned int activeSystemListSize;
	RemoteSystemIndex **remoteSystemLookup;
	DataStructures::MemoryPool<RemoteSystemIndex> remoteSystemIndexPool;
};
#define _FILE_AND_LINE_ "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\Network\\raknet\\Source\\RakPeer.cpp",__LINE__
unsigned int RakPeer::RemoteSystemLookupHashIndex(const SystemAddress &sa) const
{
	return SystemAddress::ToInteger(sa) % ((unsigned int) maximumNumberOfPeers * 8);
}
void RakPeer::ReferenceRemoteSystem(const SystemAddress &sa, unsigned int remoteSystemListIndex)
{
	SystemAddress oldAddress = remoteSystemList[remoteSystemListIndex].systemAddress;
	if (oldAddress!=UNASSIGNED_SYSTEM_ADDRESS)
	{
		if (GetRemoteSystem(oldAddress)==&remoteSystemList[remoteSystemListIndex])
			DereferenceRemoteSystem(oldAddress);
	}
	DereferenceRemoteSystem(sa);
	remoteSystemList[remoteSystemListIndex].systemAddress=sa;
	unsigned int hashIndex = RemoteSystemLookupHashIndex(sa);
	RemoteSystemIndex *rsi;
#line 3543
	rsi = remoteSystemIndexPool.Allocate(_FILE_AND_LINE_);
	if (remoteSystemLookup[hashIndex]==0)
	{
		rsi->next=0;
		rsi->index=remoteSystemListIndex;
		remoteSystemLookup[hashIndex]=rsi;
	}
	else
	{
		RemoteSystemIndex *cur = remoteSystemLookup[hashIndex];
		while (cur->next!=0)
		{
			cur=cur->next;
		}
#line 3558
		rsi = remoteSystemIndexPool.Allocate(_FILE_AND_LINE_);
		rsi->next=0;
		rsi->index=remoteSystemListIndex;
		cur->next=rsi;
	}
}
void RakPeer::DereferenceRemoteSystem(const SystemAddress &sa)
{
	unsigned int hashIndex = RemoteSystemLookupHashIndex(sa);
	RemoteSystemIndex *cur = remoteSystemLookup[hashIndex];
	RemoteSystemIndex *last = 0;
	while (cur!=0)
	{
		if (remoteSystemList[cur->index].systemAddress==sa)
		{
			if (last==0)
			{
				remoteSystemLookup[hashIndex]=cur->next;
			}
			else
			{
				last->next=cur->next;
			}
#line 3596
			remoteSystemIndexPool.Release(cur,_FILE_AND_LINE_);
			break;
		}
		last=cur;
		cur=cur->next;
	}
}
RakPeer::RemoteSystemStruct* RakPeer::GetRemoteSystem(const SystemAddress &sa) const
{
	unsigned int remoteSystemIndex = GetRemoteSystemIndex(sa);
	if (remoteSystemIndex==(unsigned int)-1)
		return 0;
	return remoteSystemList + remoteSystemIndex;
}
}
