// from server: 100% by EspClaude
// from server: 47% by colin
// roc 2007-08 004b70d0  unit: Exposer  size: 283 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b70d0
// 004b70d0  81ec0c010000         sub esp, 0x10c
// 004b70d6  a188518b00           mov eax, dword ptr [0x8b5188]
// 004b70db  33c4                 xor eax, esp
// 004b70dd  89842408010000       mov dword ptr [esp + 0x108], eax
// 004b70e4  8b15c02a8900         mov edx, dword ptr [0x892ac0]
// 004b70ea  53                   push ebx
// 004b70eb  55                   push ebp
// 004b70ec  56                   push esi
// 004b70ed  57                   push edi
// 004b70ee  8bbc2420010000       mov edi, dword ptr [esp + 0x120]
// 004b70f5  52                   push edx
// 004b70f6  8b15bc2a8900         mov edx, dword ptr [0x892abc]
// 004b70fc  8bf1                 mov esi, ecx
// 004b70fe  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b7101  8b01                 mov eax, dword ptr [ecx]
// 004b7103  8b80a0000000         mov eax, dword ptr [eax + 0xa0]
// 004b7109  52                   push edx
// 004b710a  8d542418             lea edx, [esp + 0x18]
// 004b710e  52                   push edx
// 004b710f  ffd0                 call eax
// 004b7111  807e0800             cmp byte ptr [esi + 8], 0
// 004b7115  8b18                 mov ebx, dword ptr [eax]
// 004b7117  668b6804             mov bp, word ptr [eax + 4]
// 004b711b  753f                 jne 0x4b715c
// 004b711d  0fb794242c010000     movzx edx, word ptr [esp + 0x12c]
// 004b7125  8b842428010000       mov eax, dword ptr [esp + 0x128]
// 004b712c  8d8e0a010000         lea ecx, [esi + 0x10a]
// 004b7132  51                   push ecx
// 004b7133  52                   push edx
// 004b7134  0fb7cd               movzx ecx, bp
// 004b7137  50                   push eax
// 004b7138  51                   push ecx
// 004b7139  53                   push ebx
// 004b713a  e8310e0000           call 0x4b7f70
// 004b713f  8b942438010000       mov edx, dword ptr [esp + 0x138]
// 004b7146  50                   push eax
// 004b7147  0fbe07               movsx eax, byte ptr [edi]
// 004b714a  52                   push edx
// 004b714b  50                   push eax
// 004b714c  8d4e0a               lea ecx, [esi + 0xa]
// 004b714f  51                   push ecx
// 004b7150  68a4e97900           push 0x79e9a4
// 004b7155  8d542440             lea edx, [esp + 0x40]
// 004b7159  52                   push edx
// 004b715a  eb5d                 jmp 0x4b71b9
// 004b715c  8a07                 mov al, byte ptr [edi]
// 004b715e  88442410             mov byte ptr [esp + 0x10], al
// 004b7162  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004b7166  51                   push ecx
// 004b7167  e8d4fbffff           call 0x4b6d40
// 004b716c  83c404               add esp, 4
// 004b716f  85c0                 test eax, eax
// 004b7171  750a                 jne 0x4b717d
// 004b7173  8b16                 mov edx, dword ptr [esi]
// 004b7175  8b4248               mov eax, dword ptr [edx + 0x48]
// 004b7178  51                   push ecx
// 004b7179  8bce                 mov ecx, esi
// 004b717b  ffd0                 call eax
// 004b717d  0fb794242c010000     movzx edx, word ptr [esp + 0x12c]
// 004b7185  8d8e0a010000         lea ecx, [esi + 0x10a]
// 004b718b  51                   push ecx
// 004b718c  52                   push edx
// 004b718d  8bf8                 mov edi, eax
// 004b718f  8b842430010000       mov eax, dword ptr [esp + 0x130]
// 004b7196  0fb7cd               movzx ecx, bp
// 004b7199  50                   push eax
// 004b719a  51                   push ecx
// 004b719b  53                   push ebx
// 004b719c  e8cf0d0000           call 0x4b7f70
// 004b71a1  8b942438010000       mov edx, dword ptr [esp + 0x138]
// 004b71a8  50                   push eax
// 004b71a9  52                   push edx
// 004b71aa  57                   push edi
// 004b71ab  8d460a               lea eax, [esi + 0xa]
// 004b71ae  50                   push eax
// 004b71af  6878e97900           push 0x79e978
// 004b71b4  8d4c2440             lea ecx, [esp + 0x40]
// 004b71b8  51                   push ecx
// 004b71b9  ff1568e97700         call dword ptr [0x77e968]
// 004b71bf  8b16                 mov edx, dword ptr [esi]
// 004b71c1  8b5244               mov edx, dword ptr [edx + 0x44]
// 004b71c4  83c42c               add esp, 0x2c
// 004b71c7  8d442418             lea eax, [esp + 0x18]
// 004b71cb  50                   push eax
// 004b71cc  8bce                 mov ecx, esi
// 004b71ce  ffd2                 call edx
// 004b71d0  8b8c2418010000       mov ecx, dword ptr [esp + 0x118]
// 004b71d7  5f                   pop edi
// 004b71d8  5e                   pop esi
// 004b71d9  5d                   pop ebp
// 004b71da  5b                   pop ebx
// 004b71db  33cc                 xor ecx, esp
// 004b71dd  e83c981700           call 0x630a1e
// 004b71e2  81c40c010000         add esp, 0x10c
// 004b71e8  c21000               ret 0x10

extern "C" __declspec(dllimport) int __cdecl sprintf(char*, const char*, ...);

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

namespace RakNet { unsigned int GetTime(); }

struct RakPeerInterface {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual SystemAddress GetExternalID(const SystemAddress target) const; // +0xa0
};

class PacketLogger {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16();
    virtual void AddToLog(const char* str);                 // +0x44
    virtual const char* UserIDTOString(unsigned char Id);   // +0x48

    void OnDirectSocketSend(const char* data, const unsigned bitsUsed, SystemAddress remoteSystemAddress);
    const char* IDTOString(unsigned char Id)
    {
        const char* defaultIdString = BaseIDTOString(Id);
        if (defaultIdString == 0)
            return UserIDTOString(Id);
        return defaultIdString;
    }
    static const char* BaseIDTOString(unsigned char Id);

protected:
    RakPeerInterface* rakPeerInterface; // +4
    bool printId, printAcks;            // +8, +9
    char prefix[256];                   // +0xa
    char suffix[256];                   // +0x10a
};

void PacketLogger::OnDirectSocketSend(const char* data, const unsigned bitsUsed, SystemAddress remoteSystemAddress)
{
    char str[256];
    SystemAddress localSystemAddress;
    localSystemAddress = rakPeerInterface->GetExternalID(UNASSIGNED_SYSTEM_ADDRESS);

    if (printId == false)
    {
        sprintf(str, "%sSnd,Raw,  NIL,  NIL,%5i,%5i,%i,%u:%i,%u:%i%s", prefix, data[0], bitsUsed, RakNet::GetTime(),
            localSystemAddress.binaryAddress, localSystemAddress.port,
            remoteSystemAddress.binaryAddress, remoteSystemAddress.port, suffix);
    }
    else
    {
        sprintf(str, "%sSnd,Raw,NIL,NIL,%s,%i,%i,%u:%i,%u:%i%s", prefix, IDTOString(data[0]), bitsUsed, RakNet::GetTime(),
            localSystemAddress.binaryAddress, localSystemAddress.port,
            remoteSystemAddress.binaryAddress, remoteSystemAddress.port, suffix);
    }

    AddToLog(str);
}

const char* PacketLogger::BaseIDTOString(unsigned char Id)
{
	if (Id >= 71)
        return 0;

	const char *IDTable[(int)71]=
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
			"ID_DATABASE_INCORRECT_PASSWORD",
	};

	return (char*)IDTable[Id];
}
