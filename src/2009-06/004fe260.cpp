// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
struct RemoteSystemStruct { bool isActive; char pad[0x13d0 - 1]; };
class RakPeer {
public:
    virtual unsigned short NumberOfConnections(void) const;
    int pad4;
    unsigned short maximumNumberOfPeers;
    char pad[0x53c - 0xa];
    RemoteSystemStruct* remoteSystemList;
};
unsigned short RakPeer::NumberOfConnections(void) const
{
	unsigned short i, count=0;
	for (i=0; i < maximumNumberOfPeers; i++)
		if (remoteSystemList[i].isActive)
			count++;
	return count;
}
