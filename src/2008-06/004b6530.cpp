// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct SystemAddress {
    unsigned int binaryAddress;
    unsigned short port;
};

struct RakPeerInterface {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34();
    virtual int GetAveragePing(const SystemAddress systemAddress);   // 0x8c
    virtual int GetLastPing(const SystemAddress systemAddress);      // 0x90
    virtual int GetLowestPing(const SystemAddress systemAddress);    // 0x94
};

struct RakNetStatistics {
    char pad0[0x5c];
    unsigned int messagesTotalBitsResent;   // 0x5c
    char pad1[0x18];
    unsigned int totalBitsSent;             // 0x78
};

struct Replicator {
    char pad0[0x2b70];
    unsigned int waitingRefCount;           // 0x2b70
    char pad1[0x2d50 - 0x2b74];
    RakPeerInterface* peer;                 // 0x2d50
    SystemAddress remotePlayerId;           // 0x2d54
    unsigned int numWaitingRefs() const { return waitingRefCount; }
};

template<class T> struct shared_ptr {
    T* px;
    void* pn;
    T* operator->() const { return px; }
};

namespace Stats {
struct Item {
    char pad[0x154];
    void formatValue(double value, const char* fmt, ...);
    void formatValue(const unsigned int& value);
    void formatMem(unsigned int bytes);
    virtual void update();
};
}

struct ReplicatorStatsItem : Stats::Item {
    Stats::Item* waitingRefs;       // 0x158
    Stats::Item* packetLoss;        // 0x15c
    Stats::Item* ping;              // 0x160
    Stats::Item* instanceSize;      // 0x164
    const shared_ptr<Replicator> replicator;   // 0x168
    const RakNetStatistics* statistics;        // 0x170
    unsigned instanceCount;         // 0x174
    unsigned instanceBits;          // 0x178
    virtual void update();
};

void ReplicatorStatsItem::update()
{
    if (replicator->peer)
    {
        ping->formatValue(
            replicator->peer->GetLastPing(replicator->remotePlayerId),
            "%d avg:%d best:%d",
            replicator->peer->GetLastPing(replicator->remotePlayerId),
            replicator->peer->GetAveragePing(replicator->remotePlayerId),
            replicator->peer->GetLowestPing(replicator->remotePlayerId)
        );

        waitingRefs->formatValue(replicator->numWaitingRefs());

        float ratio = (float)statistics->messagesTotalBitsResent / statistics->totalBitsSent;
        packetLoss->formatValue(ratio, "%.1g%%", ratio * 100.0);

        instanceSize->formatMem(instanceCount != 0 ? instanceBits / (instanceCount * 8) : 0);
    }
}
