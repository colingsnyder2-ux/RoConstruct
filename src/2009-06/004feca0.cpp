// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
class ReliabilityLayer {
public:
	void ApplyNetworkSimulator(double maxSendBPS, unsigned int minExtraPing, unsigned int extraPingVariance);
};
struct RemoteSystemStruct {
	char pad0[0x30];
	ReliabilityLayer reliabilityLayer;
	char pad1[0x13d0 - 0x31];
};
class RakPeer {
public:
	virtual ~RakPeer();
	virtual void ApplyNetworkSimulator(double maxSendBPS, unsigned short minExtraPing, unsigned short extraPingVariance);
	unsigned short maximumNumberOfPeers;
	char pad0a[0x53c - 0xa];
	RemoteSystemStruct* remoteSystemList;
	char pad540[0xa98 - 0x540];
	double _maxSendBPS;
	unsigned short _minExtraPing, _extraPingVariance;
};
void RakPeer::ApplyNetworkSimulator( double maxSendBPS, unsigned short minExtraPing, unsigned short extraPingVariance)
{
	if (remoteSystemList)
	{
		unsigned short i;
		for (i=0; i < maximumNumberOfPeers; i++)
			remoteSystemList[i].reliabilityLayer.ApplyNetworkSimulator(maxSendBPS, minExtraPing, extraPingVariance);
	}
	_maxSendBPS=maxSendBPS;
	_minExtraPing=minExtraPing;
	_extraPingVariance=extraPingVariance;
}
