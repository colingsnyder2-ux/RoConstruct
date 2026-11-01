// from server: 100% by king_originala
struct Peer
{
    virtual void slot00(), slot01(), slot02(), slot03(), slot04(), slot05(),
        slot06(), slot07(), slot08(), slot09(), slot10(), slot11(),
        slot12(), slot13(), slot14(), slot15(), slot16(), slot17(),
        slot18(), slot19(), slot20(), slot21(), slot22(), slot23(),
        slot24(), slot25(), slot26(), slot27(), slot28(), slot29(),
        slot30(), slot31(), slot32(), slot33(), slot34(), slot35(),
        slot36(), slot37(), slot38(), slot39(), slot40(), slot41(),
        slot42(), slot43(), slot44(), slot45(), slot46(), slot47(),
        slot48(), slot49(), slot50(), slot51(), slot52(), slot53(),
        slot54(), slot55(), slot56(), slot57();
    virtual void attach(void*);
    virtual void detach(void*);
};

struct S
{
    char padding[0x194];
    void* owner;
    char gap[0x10];
    Peer* peer;

    void setPeer(Peer*);
};

void S::setPeer(Peer* value)
{
    if (peer)
        peer->detach(owner);

    peer = value;

    if (value)
        value->attach(owner);
}
