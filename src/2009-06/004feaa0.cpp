// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
class ReliabilityLayer {
public:
	void SetSplitMessageProgressInterval(int interval);
};
struct RemoteSystemStruct {
	char pad0[0x30];
	ReliabilityLayer reliabilityLayer;
	char pad1[0x13d0 - 0x31];
};
class RakPeer {
public:
	virtual ~RakPeer();
	virtual void SetSplitMessageProgressInterval(int interval);
	volatile bool endThreads; char padEt[3];
	unsigned short maximumNumberOfPeers;
	char pad0a[0x53c - 0xa];
	RemoteSystemStruct* remoteSystemList;
	char pad540[0xb50 - 0x540];
	int splitMessageProgressInterval;
};
void RakPeer::SetSplitMessageProgressInterval(int interval)
{
	splitMessageProgressInterval=interval;
	for ( unsigned short i = 0; i < maximumNumberOfPeers; i++ )
		remoteSystemList[ i ].reliabilityLayer.SetSplitMessageProgressInterval(splitMessageProgressInterval);
}
