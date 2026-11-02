// from server: 100% by tajop
struct uint24_t {
    unsigned val;
    uint24_t& operator=(const unsigned& a) { val = a; val &= 0x00FFFFFF; return *this; }
};

struct S {
    unsigned mtu;
    double estimatedRTT;
    double cwnd;
    double ssThresh;
    unsigned __int64 oldestUnsentAck;
    uint24_t nextDatagramSequenceNumber;
    uint24_t nextCongestionControlBlock;
    bool backoffThisBlock;
    bool speedUpThisBlock;
    uint24_t expectedNextSequenceNumber;
    bool isContinuousSend;
    void Init(unsigned __int64 curTime, unsigned maxPayload);
};

void S::Init(unsigned __int64 curTime, unsigned maxPayload) {
    estimatedRTT = -1.0;
    mtu = maxPayload;
    cwnd = maxPayload;
    ssThresh = 0.0;
    oldestUnsentAck = 0;
    nextDatagramSequenceNumber = 0;
    nextCongestionControlBlock = 0;
    backoffThisBlock = speedUpThisBlock = false;
    expectedNextSequenceNumber = 0;
    isContinuousSend = false;
}
