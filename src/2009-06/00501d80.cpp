// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
#include <string.h>
typedef unsigned int RakNetTime;
typedef unsigned __int64 RakNetTimeNS;
typedef unsigned int BitSize_t;
enum PacketPriority { SYSTEM_PRIORITY, HIGH_PRIORITY };
enum PacketReliability { UNRELIABLE, UNRELIABLE_SEQUENCED };
enum { ID_SECURED_CONNECTION_RESPONSE = 5 };
struct SystemAddress { unsigned int binaryAddress; unsigned short port; };
namespace RakNet {
RakNetTime GetTime(void);
RakNetTimeNS GetTimeNS(void);
class BitStream {
public:
	static bool DoEndianSwap(void);
	static void ReverseBytesInPlace(unsigned char* data, const unsigned int length);
};
}
namespace big { typedef unsigned int u32; }
#define RAKNET_RSA_FACTOR_LIMBS 16
typedef big::u32 RSA_BIT_SIZE[RAKNET_RSA_FACTOR_LIMBS];
class CSHA1 {
public:
	CSHA1();
	~CSHA1();
	void Reset();
	void Update(unsigned char* data, unsigned int len);
	void Final();
	unsigned char* GetHash(void) const;
	unsigned char m_buf[0xb4];
};
class RSACrypt {
public:
	big::u32 getPublicExponent();
	void getPublicModulus(big::u32* n);
};
class RakPeer {
public:
	void GenerateSYNCookieRandomNumber(void);
	bool SendImmediate(char* data, BitSize_t numberOfBitsToSend, PacketPriority priority, PacketReliability reliability, char orderingChannel, SystemAddress systemAddress, bool broadcast, bool useCallerDataAllocation, RakNetTimeNS currentTime);
	void SecuredConnectionResponse(const SystemAddress systemAddress);
	char pad0[0xaa4];
	RSACrypt rsacrypt;
	char pad1[0xb18 - 0xaa5];
	RakNetTime randomNumberExpirationTime;
	unsigned char newRandomNumber[20];
};
void RakPeer::SecuredConnectionResponse(const SystemAddress systemAddress)
{
	CSHA1 sha1;
	RSA_BIT_SIZE n;
	big::u32 e;
	unsigned char connectionRequestResponse[1 + sizeof(big::u32) + sizeof(RSA_BIT_SIZE) + 20];
	connectionRequestResponse[0] = ID_SECURED_CONNECTION_RESPONSE;

	if (randomNumberExpirationTime < RakNet::GetTime())
		GenerateSYNCookieRandomNumber();

	sha1.Reset();
	sha1.Update((unsigned char*)&systemAddress.binaryAddress, sizeof(systemAddress.binaryAddress));
	sha1.Update((unsigned char*)&systemAddress.port, sizeof(systemAddress.port));
	sha1.Update((unsigned char*)&(newRandomNumber), 20);
	sha1.Final();

	memcpy(connectionRequestResponse + 1, sha1.GetHash(), 20);

	e = rsacrypt.getPublicExponent();
	rsacrypt.getPublicModulus(n);
	if (RakNet::BitStream::DoEndianSwap())
	{
		RakNet::BitStream::ReverseBytesInPlace((unsigned char*)&e, sizeof(e));
		for (int i = 0; i < RAKNET_RSA_FACTOR_LIMBS; i++)
			RakNet::BitStream::ReverseBytesInPlace((unsigned char*)&n[i], sizeof(n[i]));
	}
	memcpy(connectionRequestResponse + 1 + 20, (char*)&e, sizeof(big::u32));
	memcpy(connectionRequestResponse + 1 + 20 + sizeof(big::u32), n, sizeof(RSA_BIT_SIZE));

	SendImmediate((char*)connectionRequestResponse, (1 + sizeof(big::u32) + sizeof(RSA_BIT_SIZE) + 20) * 8, SYSTEM_PRIORITY, UNRELIABLE, 0, systemAddress, false, false, RakNet::GetTimeNS());
}
