// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
typedef unsigned int RakNetTime;
struct SystemAddress
{
	unsigned int binaryAddress;
	unsigned short port;
};
struct PingAndClockDifferential
{
	unsigned short pingTime;
	RakNetTime clockDifferential;
};
#define PING_TIMES_ARRAY_SIZE 5

class RakPeer
{
public:
	virtual ~RakPeer();
	struct RemoteSystemStruct
	{
		char pad[0x1354];
		PingAndClockDifferential pingAndClockDifferential[ PING_TIMES_ARRAY_SIZE ];
	};
	RakNetTime GetBestClockDifferential( const SystemAddress systemAddress ) const;
protected:
	RemoteSystemStruct *GetRemoteSystemFromSystemAddress( const SystemAddress systemAddress, bool calledFromNetworkThread, bool onlyActive ) const;
};

RakNetTime RakPeer::GetBestClockDifferential( const SystemAddress systemAddress ) const
{
	int counter, lowestPingSoFar;
	RakNetTime clockDifferential;
	RemoteSystemStruct *remoteSystem = GetRemoteSystemFromSystemAddress( systemAddress, true, true );

	if ( remoteSystem == 0 )
		return 0;

	lowestPingSoFar = 65535;

	clockDifferential = 0;

	for ( counter = 0; counter < PING_TIMES_ARRAY_SIZE; counter++ )
	{
		if ( remoteSystem->pingAndClockDifferential[ counter ].pingTime == 65535 )
			break;

		if ( remoteSystem->pingAndClockDifferential[ counter ].pingTime < lowestPingSoFar )
		{
			clockDifferential = remoteSystem->pingAndClockDifferential[ counter ].clockDifferential;
			lowestPingSoFar = remoteSystem->pingAndClockDifferential[ counter ].pingTime;
		}
	}

	return clockDifferential;
}
