// Runtime test for the rebuilt RakNet 3.0 library: two peers connect over loopback,
// the client sends one reliable user packet and the server must receive it intact.
#include "RakNetworkFactory.h"
#include "RakPeerInterface.h"
#include "MessageIdentifiers.h"
#include "RakNetTypes.h"
#include <windows.h>
#include <stdio.h>
#include <string.h>

int main()
{
    RakPeerInterface* server = RakNetworkFactory::GetRakPeerInterface();
    RakPeerInterface* client = RakNetworkFactory::GetRakPeerInterface();
    SocketDescriptor serverSocket(0, "127.0.0.1"), clientSocket(0, "127.0.0.1");
    if (!server->Startup(4, 0, &serverSocket, 1) || !client->Startup(1, 0, &clientSocket, 1))
        return printf("startup failed\n"), 2;
    server->SetMaximumIncomingConnections(4);
    if (!client->Connect("127.0.0.1", server->GetInternalID().port, 0, 0))
        return printf("connect call failed\n"), 3;

    const char message[] = { (char)ID_USER_PACKET_ENUM, 'r', 'o', 'c', '2', '0', '0', '8' };
    bool connected = false, received = false;
    for (int tick = 0; tick < 500 && !received; ++tick)
    {
        for (Packet* p = client->Receive(); p; client->DeallocatePacket(p), p = client->Receive())
            if (p->data[0] == ID_CONNECTION_REQUEST_ACCEPTED)
            {
                connected = true;
                client->Send(message, sizeof(message), HIGH_PRIORITY, RELIABLE_ORDERED, 0, p->systemAddress, false);
            }
        for (Packet* p = server->Receive(); p; server->DeallocatePacket(p), p = server->Receive())
            if (p->length == sizeof(message) && memcmp(p->data, message, sizeof(message)) == 0)
                received = true;
        Sleep(10);
    }
    client->Shutdown(100);
    server->Shutdown(100);
    RakNetworkFactory::DestroyRakPeerInterface(client);
    RakNetworkFactory::DestroyRakPeerInterface(server);
    printf("connected=%d received=%d\n", connected, received);
    return connected && received ? 0 : 1;
}
