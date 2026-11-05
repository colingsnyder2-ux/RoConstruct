// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
#include <string.h>
typedef unsigned int RakNetTime;
unsigned int randomMT(void);
namespace RakNet { RakNetTime GetTime(void); }
#define SYN_COOKIE_OLD_RANDOM_NUMBER_DURATION 10000
class RakPeer {
public:
    char pad[0xb18];
    RakNetTime randomNumberExpirationTime;
    unsigned char newRandomNumber[20], oldRandomNumber[20];
    void GenerateSYNCookieRandomNumber(void);
};
void RakPeer::GenerateSYNCookieRandomNumber( void )
{
	unsigned int number;
	int i;
	memcpy( oldRandomNumber, newRandomNumber, sizeof( newRandomNumber ) );

	for ( i = 0; i < (int) sizeof( newRandomNumber ); i += (int) sizeof( number ) )
	{
		number = randomMT();
		memcpy( newRandomNumber + i, ( char* ) & number, sizeof( number ) );
	}

	randomNumberExpirationTime = RakNet::GetTime() + SYN_COOKIE_OLD_RANDOM_NUMBER_DURATION;
}
