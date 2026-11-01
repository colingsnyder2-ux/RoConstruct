// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
class RPCMap
{
public:
	void RemoveNode(const char *uniqueIdentifier);
};
class RakPeer
{
public:
	virtual void UnregisterAsRemoteProcedureCall( const char* uniqueID );
private:
	char exePad2009[0xa40-4];
	RPCMap rpcMap;
};
void RakPeer::UnregisterAsRemoteProcedureCall( const char* uniqueID )
{
	if ( uniqueID == 0 || uniqueID[ 0 ] == 0 )
		return;
	rpcMap.RemoveNode(uniqueID);
}
