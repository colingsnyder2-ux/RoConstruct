// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string.h>

typedef unsigned short SystemIndex;

struct SystemAddress
{
    unsigned int binaryAddress;
    unsigned short port;
    SystemAddress& operator=(const SystemAddress& input)
    {
        binaryAddress = input.binaryAddress;
        port = input.port;
        return *this;
    }
};

struct RakNetGUID
{
    unsigned int g[4];
};

struct Packet
{
    SystemIndex systemIndex;
    SystemAddress systemAddress;
    RakNetGUID guid;
    unsigned int length;
    unsigned int bitSize;
    unsigned char* data;
    bool deleteData;
};

extern const SystemAddress UNASSIGNED_SYSTEM_ADDRESS;
Packet* AllocPacket(unsigned dataSize);

class RakPeer
{
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    void SendLoopback(const char* data, const int length);
    virtual void PushBackPacket(Packet* packet, bool pushAtHead);
private:
    char pad[0xa80 - 4];
    RakNetGUID myGuid;
};

void RakPeer::SendLoopback(const char* data, const int length)
{
    if (data == 0 || length < 0)
        return;

    Packet* packet = AllocPacket(length);
    memcpy(packet->data, data, length);
    packet->systemAddress = UNASSIGNED_SYSTEM_ADDRESS;
    packet->systemIndex = (SystemIndex)-1;
    packet->guid = myGuid;
    PushBackPacket(packet, false);
}
