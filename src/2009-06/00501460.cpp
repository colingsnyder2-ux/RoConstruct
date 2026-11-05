// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT

struct SystemAddress
{
    unsigned int binaryAddress;
    unsigned short port;
    bool operator!=(const SystemAddress& right) const;
};

extern const SystemAddress UNASSIGNED_SYSTEM_ADDRESS;

class RakPeer
{
public:
    struct RemoteSystemStruct
    {
        char pad[0x13c4];
        int MTUSize;
    };
    virtual int GetMTUSize(const SystemAddress target) const;
    RemoteSystemStruct* GetRemoteSystemFromSystemAddress(const SystemAddress systemAddress, bool calledFromNetworkThread, bool onlyActive) const;
    char pad[0xa48];
    int defaultMTUSize;
};

int RakPeer::GetMTUSize( const SystemAddress target ) const
{
	if (target!=UNASSIGNED_SYSTEM_ADDRESS)
	{
		RemoteSystemStruct *rss=GetRemoteSystemFromSystemAddress(target, false, true);
		if (rss)
			return rss->MTUSize;
	}
	return defaultMTUSize;
}
