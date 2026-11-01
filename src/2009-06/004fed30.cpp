// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
class RakPeer {
public:
	virtual ~RakPeer();
	virtual bool IsNetworkSimulatorActive( void );
	char pad04[0xa98 - 0x8];
	double _maxSendBPS;
	unsigned short _minExtraPing, _extraPingVariance;
};
bool RakPeer::IsNetworkSimulatorActive( void )
{
	return _maxSendBPS>0 || _minExtraPing>0 || _extraPingVariance>0;
}
