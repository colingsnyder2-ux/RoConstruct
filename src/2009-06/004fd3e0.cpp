// from server: 100% by EspClaude
// roc 2009-06 004fd3e0  RakNet SocketLayer::SendTo (2009: extra bool arg skips the send)
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
typedef unsigned int SOCKET;
typedef unsigned long DWORD;
#define INVALID_SOCKET (SOCKET)(~0)
#define SOCKET_ERROR (-1)
#define AF_INET 2
struct sockaddr { unsigned short sa_family; char sa_data[14]; };
struct in_addr { unsigned long s_addr; };
struct sockaddr_in { short sin_family; unsigned short sin_port; in_addr sin_addr; char sin_zero[8]; };
extern "C" __declspec(dllimport) unsigned short __stdcall htons(unsigned short);
extern "C" __declspec(dllimport) int __stdcall sendto(SOCKET, const char*, int, int, const sockaddr*, int);
extern "C" __declspec(dllimport) int __stdcall WSAGetLastError(void);

class SocketLayer
{
public:
	int SendTo( SOCKET s, const char *data, int length, unsigned int binaryAddress, unsigned short port, bool skip );
};

#pragma warning( disable : 4702 )
int SocketLayer::SendTo( SOCKET s, const char *data, int length, unsigned int binaryAddress, unsigned short port, bool skip )
{
	if ( s == INVALID_SOCKET )
	{
		return -1;
	}
	int len = 0;
	if ( !skip )
	{
		sockaddr_in sa;
		sa.sin_port = htons( port );
		sa.sin_addr.s_addr = binaryAddress;
		sa.sin_family = AF_INET;
		do
		{
			len = sendto( s, data, length, 0, ( const sockaddr* ) & sa, sizeof( struct sockaddr_in ) );
		}
		while ( len == 0 );
	}
	if ( len != SOCKET_ERROR )
		return 0;
	DWORD dwIOError = WSAGetLastError();
	return dwIOError;
}
