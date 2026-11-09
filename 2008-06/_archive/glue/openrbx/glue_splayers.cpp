// Native sPlayers definition for rbx-app link.
// Defined in native-classes/NetworkPlayers.cpp but that unit is not part of rbx-app.
// Provided here as native-only glue so the linker can resolve RBX::Network::sPlayers.
namespace RBX
{
	namespace Network
	{
		char sPlayers[] = "Players"; // 0093784c (.data; classDescriptor 0049a8a0)
	}
}
