// from server: 100% by EspClaude
// from server: 50% by colin
// roc 2007-08 004b71f0  unit: Exposer  size: 283 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b71f0
//
// 004b71f0  81ec0c010000         sub esp, 0x10c
// 004b71f6  a188518b00           mov eax, dword ptr [0x8b5188]
// 004b71fb  33c4                 xor eax, esp
// 004b71fd  89842408010000       mov dword ptr [esp + 0x108], eax
// 004b7204  8b15c02a8900         mov edx, dword ptr [0x892ac0]
// 004b720a  53                   push ebx
// 004b720b  55                   push ebp
// 004b720c  56                   push esi
// 004b720d  57                   push edi
// 004b720e  8bbc2420010000       mov edi, dword ptr [esp + 0x120]
// 004b7215  52                   push edx
// 004b7216  8b15bc2a8900         mov edx, dword ptr [0x892abc]
// 004b721c  8bf1                 mov esi, ecx
// 004b721e  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b7221  8b01                 mov eax, dword ptr [ecx]
// 004b7223  8b80a0000000         mov eax, dword ptr [eax + 0xa0]
// 004b7229  52                   push edx
// 004b722a  8d542418             lea edx, [esp + 0x18]
// 004b722e  52                   push edx
// 004b722f  ffd0                 call eax
// 004b7231  807e0800             cmp byte ptr [esi + 8], 0
// 004b7235  8b18                 mov ebx, dword ptr [eax]
// 004b7237  668b6804             mov bp, word ptr [eax + 4]
// 004b723b  753f                 jne 0x4b727c
// 004b723d  0fb794242c010000     movzx edx, word ptr [esp + 0x12c]
// 004b7245  8b842428010000       mov eax, dword ptr [esp + 0x128]
// 004b724c  8d8e0a010000         lea ecx, [esi + 0x10a]
// 004b7252  51                   push ecx
// 004b7253  52                   push edx
// 004b7254  0fb7cd               movzx ecx, bp
// 004b7257  50                   push eax
// 004b7258  51                   push ecx
// 004b7259  53                   push ebx
// 004b725a  e8110d0000           call 0x4b7f70
// 004b725f  8b942438010000       mov edx, dword ptr [esp + 0x138]
// 004b7266  50                   push eax
// 004b7267  0fbe07               movsx eax, byte ptr [edi]
// 004b726a  52                   push edx
// 004b726b  50                   push eax
// 004b726c  8d4e0a               lea ecx, [esi + 0xa]
// 004b726f  51                   push ecx
// 004b7270  6800ea7900           push 0x79ea00
// 004b7275  8d542440             lea edx, [esp + 0x40]
// 004b7279  52                   push edx
// 004b727a  eb5d                 jmp 0x4b72d9
// 004b727c  8a07                 mov al, byte ptr [edi]
// 004b727e  88442410             mov byte ptr [esp + 0x10], al
// 004b7282  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004b7286  51                   push ecx
// 004b7287  e8b4faffff           call 0x4b6d40
// 004b728c  83c404               add esp, 4
// 004b728f  85c0                 test eax, eax
// 004b7291  750a                 jne 0x4b729d
// 004b7293  8b16                 mov edx, dword ptr [esi]
// 004b7295  8b4248               mov eax, dword ptr [edx + 0x48]
// 004b7298  51                   push ecx
// 004b7299  8bce                 mov ecx, esi
// 004b729b  ffd0                 call eax
// 004b729d  0fb794242c010000     movzx edx, word ptr [esp + 0x12c]
// 004b72a5  8d8e0a010000         lea ecx, [esi + 0x10a]
// 004b72ab  51                   push ecx
// 004b72ac  52                   push edx
// 004b72ad  8bf8                 mov edi, eax
// 004b72af  8b842430010000       mov eax, dword ptr [esp + 0x130]
// 004b72b6  0fb7cd               movzx ecx, bp
// 004b72b9  50                   push eax
// 004b72ba  51                   push ecx
// 004b72bb  53                   push ebx
// 004b72bc  e8af0c0000           call 0x4b7f70
// 004b72c1  8b942438010000       mov edx, dword ptr [esp + 0x138]
// 004b72c8  50                   push eax
// 004b72c9  52                   push edx
// 004b72ca  57                   push edi
// 004b72cb  8d460a               lea eax, [esi + 0xa]
// 004b72ce  50                   push eax
// 004b72cf  68d4e97900           push 0x79e9d4
// 004b72d4  8d4c2440             lea ecx, [esp + 0x40]
// 004b72d8  51                   push ecx
// 004b72d9  ff1568e97700         call dword ptr [0x77e968]
// 004b72df  8b16                 mov edx, dword ptr [esi]
// 004b72e1  8b5244               mov edx, dword ptr [edx + 0x44]
// 004b72e4  83c42c               add esp, 0x2c
// 004b72e7  8d442418             lea eax, [esp + 0x18]
// 004b72eb  50                   push eax
// 004b72ec  8bce                 mov ecx, esi
// 004b72ee  ffd2                 call edx
// 004b72f0  8b8c2418010000       mov ecx, dword ptr [esp + 0x118]
// 004b72f7  5f                   pop edi
// 004b72f8  5e                   pop esi
// 004b72f9  5d                   pop ebp
// 004b72fa  5b                   pop ebx
// 004b72fb  33cc                 xor ecx, esp
// 004b72fd  e81c971700           call 0x630a1e
// 004b7302  81c40c010000         add esp, 0x10c
// 004b7308  c21000               ret 0x10

// RakNet 3.0 PacketLogger.cpp (2007-08 build) codegen analog.
// BaseIDTOString/IDTOString are kept in this unit as in the authentic file: the target
// inlines IDTOString and relies on BaseIDTOString (0x4b6d40, 71-entry table, cmp al,0x47)
// leaving ecx intact, which the compiler only knows when that body is in the same unit.
// The table strings are read from the pointers 0x4b6d40 stores; layout offsets from the target.
extern "C" __declspec(dllimport) int __cdecl sprintf(char*, const char*, ...);

typedef unsigned int RakNetTime;
namespace RakNet { RakNetTime GetTime(void); }

struct SystemAddress {
    unsigned int binaryAddress;
    unsigned short port;
    SystemAddress& operator=(const SystemAddress& input)
    {
        binaryAddress = input.binaryAddress;
        port = input.port;
        return *this;
    }
};
extern const SystemAddress UNASSIGNED_SYSTEM_ADDRESS;

#define V(n) virtual void v##n();
class RakPeerInterface {
public:
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    virtual SystemAddress GetInternalID(const SystemAddress systemAddress = UNASSIGNED_SYSTEM_ADDRESS) const; // +0xa0
};

class PacketLogger {
public:
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16)
    virtual void AddToLog(const char* str);                 // +0x44
    virtual char* UserIDTOString(unsigned char Id);         // +0x48

    static char* BaseIDTOString(unsigned char Id);
    char* IDTOString(unsigned char Id);
    void OnDirectSocketReceive(const char* data, const unsigned bitsUsed, SystemAddress remoteSystemAddress);

protected:
    RakPeerInterface* rakPeer;   // +0x04
    bool printId;                // +0x08
    bool printAcks;              // +0x09
    char prefix[256];            // +0x0a
    char suffix[256];            // +0x10a
};

char* PacketLogger::BaseIDTOString(unsigned char Id)
{
    if (Id >= 71)
        return 0;

    const char* IDTable[71] =
    {
		"ID_INTERNAL_PING",
		"ID_PING",
		"ID_PING_OPEN_CONNECTIONS",
		"ID_CONNECTED_PONG",
		"ID_CONNECTION_REQUEST",
		"ID_SECURED_CONNECTION_RESPONSE",
		"ID_SECURED_CONNECTION_CONFIRMATION",
		"ID_RPC_MAPPING",
		"ID_DETECT_LOST_CONNECTIONS",
		"ID_OPEN_CONNECTION_REQUEST",
		"ID_OPEN_CONNECTION_REPLY",
		"ID_RPC",
		"ID_RPC_REPLY",
		"ID_CONNECTION_REQUEST_ACCEPTED",
		"ID_CONNECTION_ATTEMPT_FAILED",
		"ID_ALREADY_CONNECTED",
		"ID_NEW_INCOMING_CONNECTION",
		"ID_NO_FREE_INCOMING_CONNECTIONS",
		"ID_DISCONNECTION_NOTIFICATION",
		"ID_CONNECTION_LOST",
		"ID_RSA_PUBLIC_KEY_MISMATCH",
		"ID_CONNECTION_BANNED",
		"ID_INVALID_PASSWORD",
		"ID_MODIFIED_PACKET",
		"ID_TIMESTAMP",
		"ID_PONG",
		"ID_ADVERTISE_SYSTEM",
		"ID_REMOTE_DISCONNECTION_NOTIFICATION",
		"ID_REMOTE_CONNECTION_LOST",
		"ID_REMOTE_NEW_INCOMING_CONNECTION",
		"ID_DOWNLOAD_PROGRESS",
		"ID_FILE_LIST_TRANSFER_HEADER",
		"ID_FILE_LIST_TRANSFER_FILE",
		"ID_DDT_DOWNLOAD_REQUEST",
		"ID_TRANSPORT_STRING",
		"ID_REPLICA_MANAGER_CONSTRUCTION",
		"ID_REPLICA_MANAGER_DESTRUCTION",
		"ID_REPLICA_MANAGER_SCOPE_CHANGE",
		"ID_REPLICA_MANAGER_SERIALIZE",
		"ID_REPLICA_MANAGER_DOWNLOAD_COMPLETE",
		"ID_CONNECTION_GRAPH_REQUEST",
		"ID_CONNECTION_GRAPH_REPLY",
		"ID_CONNECTION_GRAPH_UPDATE",
		"ID_CONNECTION_GRAPH_NEW_CONNECTION",
		"ID_CONNECTION_GRAPH_CONNECTION_LOST",
		"ID_CONNECTION_GRAPH_DISCONNECTION_NOTIFICATION",
		"ID_ROUTE_AND_MULTICAST",
		"ID_RAKVOICE_OPEN_CHANNEL_REQUEST",
		"ID_RAKVOICE_OPEN_CHANNEL_REPLY",
		"ID_RAKVOICE_CLOSE_CHANNEL",
		"ID_RAKVOICE_DATA",
		"ID_AUTOPATCHER_GET_CHANGELIST_SINCE_DATE",
		"ID_AUTOPATCHER_CREATION_LIST",
		"ID_AUTOPATCHER_DELETION_LIST",
		"ID_AUTOPATCHER_GET_PATCH",
		"ID_AUTOPATCHER_PATCH_LIST",
		"ID_AUTOPATCHER_REPOSITORY_FATAL_ERROR",
		"ID_AUTOPATCHER_FINISHED_INTERNAL",
		"ID_AUTOPATCHER_FINISHED",
		"ID_AUTOPATCHER_RESTART_APPLICATION",
		"ID_NAT_PUNCHTHROUGH_REQUEST",
		"ID_NAT_TARGET_NOT_CONNECTED",
		"ID_NAT_TARGET_CONNECTION_LOST",
		"ID_NAT_CONNECT_AT_TIME",
		"ID_NAT_SEND_OFFLINE_MESSAGE_AT_TIME",
		"ID_DATABASE_QUERY_REQUEST",
		"ID_DATABASE_UPDATE_ROW",
		"ID_DATABASE_REMOVE_ROW",
		"ID_DATABASE_QUERY_REPLY",
		"ID_DATABASE_UNKNOWN_TABLE",
		"ID_DATABASE_INCORRECT_PASSWORD"
    };

    return (char*)IDTable[Id];
}

char* PacketLogger::IDTOString(unsigned char Id)
{
    char* out;
    out = BaseIDTOString(Id);
    if (out)
        return (char*)out;
    return UserIDTOString(Id);
}

void PacketLogger::OnDirectSocketReceive(const char* data, const unsigned bitsUsed, SystemAddress remoteSystemAddress)
{
    char str[256];
    SystemAddress localSystemAddress;
    localSystemAddress = rakPeer->GetInternalID();
    if (printId == false)
    {
        sprintf(str, "%sRcv,Raw,  NIL,  NIL,%5i,%5i,%i,%u:%i,%u:%i%s", prefix, data[0], bitsUsed, RakNet::GetTime(),
            localSystemAddress.binaryAddress, localSystemAddress.port, remoteSystemAddress.binaryAddress, remoteSystemAddress.port, suffix);
    }
    else
    {
        sprintf(str, "%sRcv,Raw,NIL,NIL,%s,%i,%i,%u:%i,%u:%i%s", prefix, IDTOString(data[0]), bitsUsed, RakNet::GetTime(),
            localSystemAddress.binaryAddress, localSystemAddress.port, remoteSystemAddress.binaryAddress, remoteSystemAddress.port, suffix);
    }

    AddToLog(str);
}
