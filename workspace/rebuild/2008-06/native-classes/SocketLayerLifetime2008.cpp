// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
/**
* @file
* @brief SocketLayer class implementation 
*
 * This file is part of RakNet Copyright 2003 Rakkarsoft LLC and Kevin Jenkins.
 *
 * Usage of Raknet is subject to the appropriate licence agreement.
 * "Shareware" Licensees with Rakkarsoft LLC are subject to the
 * shareware license found at
 * http://www.rakkarsoft.com/shareWareLicense.html which you agreed to
 * upon purchase of a "Shareware license" "Commercial" Licensees with
 * Rakkarsoft LLC are subject to the commercial license found at
 * http://www.rakkarsoft.com/sourceCodeLicense.html which you agreed
 * to upon purchase of a "Commercial license"
 * Custom license users are subject to the terms therein.
 * All other users are
 * subject to the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * Refer to the appropriate license agreement for distribution,
 * modification, and warranty rights.
*/
#include "SocketLayer.h"
bool SocketLayer::socketLayerStarted = false;
WSADATA SocketLayer::winsockInfo;
SocketLayer SocketLayer::I;
SocketLayer::SocketLayer()
{
	if ( socketLayerStarted == false )
	{
#ifdef _WIN32

		if ( WSAStartup( MAKEWORD( 2, 2 ), &winsockInfo ) != 0 )
		{
#if defined(_WIN32) && !defined(_COMPATIBILITY_1) && defined(_DEBUG)
			DWORD dwIOError = GetLastError();
			LPVOID messageBuffer;
			FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
				NULL, dwIOError, MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ),  // Default language
				( LPTSTR ) & messageBuffer, 0, NULL );
			// something has gone wrong here...
			printf( "WSAStartup failed:Error code - %d\n%s", dwIOError, messageBuffer );
			//Free the buffer.
			LocalFree( messageBuffer );
#endif
		}

#endif
		socketLayerStarted = true;
	}
}

SocketLayer::~SocketLayer()
{
	if ( socketLayerStarted == true )
	{
#ifdef _WIN32
		WSACleanup();
#endif

		socketLayerStarted = false;
	}
}



