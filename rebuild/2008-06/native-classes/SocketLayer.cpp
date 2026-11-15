// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /GS- /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\Network\raknet30\Source
#include "../../../tools/rbxgs/Client/Network/raknet30/Source/SocketLayer.h"
#include "../../../tools/rbxgs/Client/Network/raknet30/Source/MTUSize.h"
#include "../../../tools/rbxgs/Client/Network/raknet30/Source/ExtendedOverlappedPool.h"

extern void __stdcall ProcessNetworkPacket( const unsigned int binaryAddress, const unsigned short port, const char *data, const int length, RakPeer *rakPeer, unsigned connectionSocketIndex );
extern void __stdcall ProcessPortUnreachable( const unsigned int binaryAddress, const unsigned short port, RakPeer *rakPeer );

SOCKET SocketLayer::CreateBoundSocket( unsigned short port, bool blockingSocket, const char *forceHostAddress )
{
	SOCKET listenSocket;
	sockaddr_in listenerSocketAddress;
	int ret;

	listenSocket = socket( AF_INET, SOCK_DGRAM, 0 );

	if ( listenSocket == INVALID_SOCKET )
	{
#if defined(_WIN32) && !defined(_CONSOLE_1) && defined(_DEBUG)
		DWORD dwIOError = GetLastError();
		LPVOID messageBuffer;
		FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, dwIOError, MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ),  // Default language
			( LPTSTR ) & messageBuffer, 0, NULL );
		// something has gone wrong here...
		printf( "socket(...) failed:Error code - %d\n%s", dwIOError, messageBuffer );
		//Free the buffer.
		LocalFree( messageBuffer );
#endif

		return INVALID_SOCKET;
	}

	int sock_opt = 1;

	if ( setsockopt( listenSocket, SOL_SOCKET, SO_REUSEADDR, ( char * ) & sock_opt, sizeof ( sock_opt ) ) == -1 )
	{
#if defined(_WIN32) && !defined(_CONSOLE_1) && defined(_DEBUG)
		DWORD dwIOError = GetLastError();
		LPVOID messageBuffer;
		FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, dwIOError, MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ),  // Default language
			( LPTSTR ) & messageBuffer, 0, NULL );
		// something has gone wrong here...
		printf( "setsockopt(SO_REUSEADDR) failed:Error code - %d\n%s", dwIOError, messageBuffer );
		//Free the buffer.
		LocalFree( messageBuffer );
#endif
	}

	// This doubles the max throughput rate
	sock_opt=1024*256;
	setsockopt(listenSocket, SOL_SOCKET, SO_RCVBUF, ( char * ) & sock_opt, sizeof ( sock_opt ) );
	
#ifndef _CONSOLE_2
	// This doesn't make much difference: 10% maybe
	// Not supported on console 2
	sock_opt=1024*16;
	setsockopt(listenSocket, SOL_SOCKET, SO_SNDBUF, ( char * ) & sock_opt, sizeof ( sock_opt ) );
#endif

#ifdef _WIN32
	unsigned long nonblocking = 1;
	ioctlsocket( listenSocket, FIONBIO, &nonblocking );
#elif defined(_CONSOLE_2)
	sock_opt=1;
	setsockopt(listenSocket, SOL_SOCKET, SO_NBIO, ( char * ) & sock_opt, sizeof ( sock_opt ) );
#else
	fcntl( listenSocket, F_SETFL, O_NONBLOCK );
#endif

	#if defined(_WIN32) && !defined(_CONSOLE_1) && defined(_DEBUG)
	// If this assert hit you improperly linked against WSock32.h
	assert(IP_DONTFRAGMENT==14);
	#endif

	// TODO - I need someone on dialup to test this with :(
	// Path MTU Detection
	/*
	if ( setsockopt( listenSocket, IPPROTO_IP, IP_DONTFRAGMENT, ( char * ) & sock_opt, sizeof ( sock_opt ) ) == -1 )
	{
#if defined(_WIN32) && !defined(_CONSOLE_1) && defined(_DEBUG)
		DWORD dwIOError = GetLastError();
		LPVOID messageBuffer;
		FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, dwIOError, MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ),  // Default language
			( LPTSTR ) & messageBuffer, 0, NULL );
		// something has gone wrong here...
		printf( "setsockopt(IP_DONTFRAGMENT) failed:Error code - %d\n%s", dwIOError, messageBuffer );
		//Free the buffer.
		LocalFree( messageBuffer );
#endif
	}
	*/

	/*
	//Set non-blocking
#ifdef _WIN32
	unsigned long nonblocking = 1;
// http://linux.die.net/man/7/ip
	if ( ioctlsocket( listenSocket, FIONBIO, &nonblocking ) != 0 )
	{
		assert( 0 );
		return INVALID_SOCKET;
	}
#elif !defined(_CONSOLE_2)
	if ( fcntl( listenSocket, F_SETFL, O_NONBLOCK ) != 0 )
	{
		assert( 0 );
		return INVALID_SOCKET;
	}
#endif
	*/

	// Set broadcast capable
	sock_opt=1;
	if ( setsockopt( listenSocket, SOL_SOCKET, SO_BROADCAST, ( char * ) & sock_opt, sizeof( sock_opt ) ) == -1 )
	{
#if defined(_WIN32) && !defined(_CONSOLE_1) && defined(_DEBUG)
		DWORD dwIOError = GetLastError();
		LPVOID messageBuffer;
		FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, dwIOError, MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ),  // Default language
			( LPTSTR ) & messageBuffer, 0, NULL );
		// something has gone wrong here...
		printf( "setsockopt(SO_BROADCAST) failed:Error code - %d\n%s", dwIOError, messageBuffer );
		//Free the buffer.
		LocalFree( messageBuffer );
#endif

	}

	// Listen on our designated Port#
	listenerSocketAddress.sin_port = htons( port );

	// Fill in the rest of the address structure
	listenerSocketAddress.sin_family = AF_INET;

	if (forceHostAddress && forceHostAddress[0])
	{
		listenerSocketAddress.sin_addr.s_addr = inet_addr( forceHostAddress );
	}
	else
	{
		listenerSocketAddress.sin_addr.s_addr = INADDR_ANY;
	}	

	// bind our name to the socket
	ret = bind( listenSocket, ( struct sockaddr * ) & listenerSocketAddress, sizeof( struct sockaddr ) );

	if ( ret == SOCKET_ERROR )
	{
#if defined(_WIN32) && !defined(_CONSOLE_1) && defined(_DEBUG)
		DWORD dwIOError = GetLastError();
		LPVOID messageBuffer;
		FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, dwIOError, MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ),  // Default language
			( LPTSTR ) & messageBuffer, 0, NULL );
		// something has gone wrong here...
		printf( "bind(...) failed:Error code - %d\n%s", dwIOError, messageBuffer );
		//Free the buffer.
		LocalFree( messageBuffer );
#endif

		return INVALID_SOCKET;
	}

	return listenSocket;
}

const char* SocketLayer::DomainNameToIP( const char *domainName )
{
	struct hostent * phe = gethostbyname( domainName );

	if ( phe == 0 || phe->h_addr_list[ 0 ] == 0 )
	{
		//cerr << "Yow! Bad host lookup." << endl;
#if defined(_CONSOLE_2)
		printf("gethostbyname Error\n");
#endif
		return 0;
	}

	struct in_addr addr;

	memcpy( &addr, phe->h_addr_list[ 0 ], sizeof( struct in_addr ) );

	return inet_ntoa( addr );
}

int SocketLayer::RecvFrom( const SOCKET s, RakPeer *rakPeer, int *errorCode, unsigned connectionSocketIndex )
{
	int len;
	char data[ MAXIMUM_MTU_SIZE ];
	sockaddr_in sa;

	socklen_t len2 = sizeof( struct sockaddr_in );
	sa.sin_family = AF_INET;

#ifdef _DEBUG
	data[ 0 ] = 0;
	len = 0;
	sa.sin_addr.s_addr = 0;
#endif

	if ( s == INVALID_SOCKET )
	{
		*errorCode = SOCKET_ERROR;
		return SOCKET_ERROR;
	}

#ifdef _WIN32
	const int flag=0;
#else
	const int flag=MSG_DONTWAIT;
#endif

	len = recvfrom( s, data, MAXIMUM_MTU_SIZE, flag, ( sockaddr* ) & sa, ( socklen_t* ) & len2 );

	// if (len>0)
	//  printf("Got packet on port %i\n",ntohs(sa.sin_port));

	if ( len == 0 )
	{
#ifdef _DEBUG
		printf( "Error: recvfrom returned 0 on a connectionless blocking call\non port %i.  This is a bug with Zone Alarm.  Please turn off Zone Alarm.\n", ntohs( sa.sin_port ) );
		assert( 0 );
#endif

		*errorCode = SOCKET_ERROR;
		return SOCKET_ERROR;
	}

	if ( len > 0 )
	// if ( len != SOCKET_ERROR )
	{
		unsigned short portnum;
		portnum = ntohs( sa.sin_port );
		//strcpy(ip, inet_ntoa(sa.sin_addr));
		//if (strcmp(ip, "0.0.0.0")==0)
		// strcpy(ip, "127.0.0.1");
		ProcessNetworkPacket( sa.sin_addr.s_addr, portnum, data, len, rakPeer, connectionSocketIndex );

		return 1;
	}
	else
	{
		*errorCode = 0;


#if defined(_WIN32) && !defined(_CONSOLE_1) && defined(_DEBUG)

		DWORD dwIOError = WSAGetLastError();

		if ( dwIOError == WSAEWOULDBLOCK )
		{
			return SOCKET_ERROR;
		}
		if ( dwIOError == WSAECONNRESET )
		{
#if defined(_DEBUG)
//			printf( "A previous send operation resulted in an ICMP Port Unreachable message.\n" );
#endif


			unsigned short portnum=0;
			ProcessPortUnreachable(sa.sin_addr.s_addr, portnum, rakPeer);
			// *errorCode = dwIOError;
			return SOCKET_ERROR;
		}
		else
		{
#if defined(_DEBUG)
			if ( dwIOError != WSAEINTR )
			{
				LPVOID messageBuffer;
				FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
					NULL, dwIOError, MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ),  // Default language
					( LPTSTR ) & messageBuffer, 0, NULL );
				// something has gone wrong here...
				printf( "recvfrom failed:Error code - %d\n%s", dwIOError, messageBuffer );

				//Free the buffer.
				LocalFree( messageBuffer );
			}
#endif
		}
#endif
	}

	return 0; // no data
}

int SocketLayer::SendTo( SOCKET s, const char *data, int length, char ip[ 16 ], unsigned short port )
{
	unsigned int binaryAddress;
	binaryAddress = inet_addr( ip );
	return SendTo( s, data, length, binaryAddress, port );
}

int SocketLayer::SendTo( SOCKET s, const char *data, int length, unsigned int binaryAddress, unsigned short port )
{
	if ( s == INVALID_SOCKET )
	{
		return -1;
	}

	int len;
	sockaddr_in sa;
	sa.sin_port = htons( port );
	sa.sin_addr.s_addr = binaryAddress;
	sa.sin_family = AF_INET;

	do
	{
		// TODO - use WSASendTo which is faster.
		len = sendto( s, data, length, 0, ( const sockaddr* ) & sa, sizeof( struct sockaddr_in ) );
	}
	while ( len == 0 );

	if ( len != SOCKET_ERROR )
		return 0;

#if defined(_WIN32)

	DWORD dwIOError = WSAGetLastError();

	if ( dwIOError == WSAECONNRESET )
	{
#if defined(_DEBUG)
		printf( "A previous send operation resulted in an ICMP Port Unreachable message.\n" );
#endif

	}
	else if ( dwIOError != WSAEWOULDBLOCK )
	{
#if defined(_WIN32) && !defined(_CONSOLE_1) && defined(_DEBUG)
		LPVOID messageBuffer;
		FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, dwIOError, MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ),  // Default language
			( LPTSTR ) & messageBuffer, 0, NULL );
		// something has gone wrong here...
		printf( "sendto failed:Error code - %d\n%s", dwIOError, messageBuffer );

		//Free the buffer.
		LocalFree( messageBuffer );
#endif

	}

	return dwIOError;
#endif

	return 1; // error
}

int SocketLayer::SendToTTL1( SOCKET s, const char *data, int length, char ip[ 16 ], unsigned short port )
{
#if !defined(_CONSOLE_1)
	int oldTTL;
	socklen_t opLen=sizeof(oldTTL);
	// Get the current TTL
	if (getsockopt(s, IPPROTO_IP, IP_TTL, ( char * ) & oldTTL, &opLen ) == -1)
	{
#if defined(_WIN32) && defined(_DEBUG)
		DWORD dwIOError = GetLastError();
		LPVOID messageBuffer;
		FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, dwIOError, MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ),  // Default language
			( LPTSTR ) & messageBuffer, 0, NULL );
		// something has gone wrong here...
		printf( "getsockopt(IPPROTO_IP,IP_TTL) failed:Error code - %d\n%s", dwIOError, messageBuffer );
		//Free the buffer.
		LocalFree( messageBuffer );
#endif
	}

	// Set to TTL
	int newTTL=1;
	if (setsockopt(s, IPPROTO_IP, IP_TTL, ( char * ) & newTTL, sizeof ( newTTL ) ) == -1)
	{

#if defined(_WIN32) && defined(_DEBUG)
		DWORD dwIOError = GetLastError();
		LPVOID messageBuffer;
		FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, dwIOError, MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ),  // Default language
			( LPTSTR ) & messageBuffer, 0, NULL );
		// something has gone wrong here...
		printf( "setsockopt(IPPROTO_IP,IP_TTL) failed:Error code - %d\n%s", dwIOError, messageBuffer );
		//Free the buffer.
		LocalFree( messageBuffer );
#endif
	}

	// Send
	int res = SendTo(s,data,length,ip,port);

	// Restore the old TTL
	setsockopt(s, IPPROTO_IP, IP_TTL, ( char * ) & oldTTL, opLen );

	return res;
#else
	return 0;
#endif
}

void SocketLayer::GetMyIP( char ipList[ 10 ][ 16 ] )
{
#if !defined(_CONSOLE_2)
	char ac[ 80 ];
	if ( gethostname( ac, sizeof( ac ) ) == SOCKET_ERROR )
	{
	#if defined(_WIN32) && !defined(_CONSOLE_1) && defined(_DEBUG)
		DWORD dwIOError = GetLastError();
		LPVOID messageBuffer;
		FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, dwIOError, MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ),  // Default language
			( LPTSTR ) & messageBuffer, 0, NULL );
		// something has gone wrong here...
		printf( "gethostname failed:Error code - %d\n%s", dwIOError, messageBuffer );
		//Free the buffer.
		LocalFree( messageBuffer );
	#endif

		return ;
	}

	struct hostent *phe = gethostbyname( ac );


	if ( phe == 0 )
	{
#if defined(_WIN32) && !defined(_CONSOLE_1) && defined(_DEBUG)
		DWORD dwIOError = GetLastError();
		LPVOID messageBuffer;
		FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, dwIOError, MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ),  // Default language
			( LPTSTR ) & messageBuffer, 0, NULL );
		// something has gone wrong here...
		printf( "gethostbyname failed:Error code - %d\n%s", dwIOError, messageBuffer );

		//Free the buffer.
		LocalFree( messageBuffer );
#endif

		return ;
	}

	for ( int i = 0; phe->h_addr_list[ i ] != 0 && i < 10; ++i )
	{

		struct in_addr addr;

		memcpy( &addr, phe->h_addr_list[ i ], sizeof( struct in_addr ) );
		//cout << "Address " << i << ": " << inet_ntoa(addr) << endl;
		strcpy( ipList[ i ], inet_ntoa( addr ) );
	}
#else
	union CellNetCtlInfo info;
	int errCode;
	if((errCode=cellNetCtlGetInfo(CELL_NET_CTL_INFO_IP_ADDRESS, &info)) >= 0){
		memcpy(ipList[0], info.ip_address, sizeof(info.ip_address));
		ipList[1][0]=0;
	}
	else
	{
		sprintf(ipList[0], "Err %X", errCode);
		ipList[1][0]=0;
	}
	return;
#endif

}

unsigned short SocketLayer::GetLocalPort ( SOCKET s )
{
	sockaddr_in sa;
	socklen_t len = sizeof(sa);
	if (getsockname(s, (sockaddr*)&sa, &len)!=0)
	{
#if defined(_WIN32) && !defined(_CONSOLE_1) && defined(_DEBUG)
		DWORD dwIOError = GetLastError();
		LPVOID messageBuffer;
		FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, dwIOError, MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ),  // Default language
			( LPTSTR ) & messageBuffer, 0, NULL );
		// something has gone wrong here...
		printf( "getsockname failed:Error code - %d\n%s", dwIOError, messageBuffer );

		//Free the buffer.
		LocalFree( messageBuffer );
#endif
		return 0;
	}
	return ntohs(sa.sin_port);
}
