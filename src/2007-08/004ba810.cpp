// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
namespace DataStructures {
template<class queue_type> class Queue {
public:
    void Push(const queue_type& input);
    void PushAtHead(const queue_type& input, unsigned index);
    queue_type* array;
    unsigned head, tail, allocation_size;
};
}
struct Packet;
class RakPeer {
public:
    virtual ~RakPeer();
    char pad[0x8e8 - 4];
    DataStructures::Queue<Packet*> packetQueue;
    void PushBackPacket(Packet* packet, bool pushAtHead);
};
void RakPeer::PushBackPacket(Packet* packet, bool pushAtHead)
{
    if (pushAtHead)
        packetQueue.PushAtHead(packet, 0);
    else
        packetQueue.Push(packet);
}
