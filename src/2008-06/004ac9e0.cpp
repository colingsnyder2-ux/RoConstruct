// from server: 100% by king_originala
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct Peer;

struct Attachment {
    virtual ~Attachment();
    Attachment(Peer*);
    char storage[0x20c];
};

struct Manager;

struct ManagerTable {
    void* unused[58];
    void (__thiscall *attach)(Manager*, Attachment*);
    void (__thiscall *detach)(Manager*, Attachment*);
};

struct Manager {
    ManagerTable* table;
};

struct Peer {
    char reserved[0x138];
    Attachment* attachment;
    unsigned int reserved13c;
    Manager* manager;

    void setEnabled(bool);
};

void Peer::setEnabled(bool enabled)
{
    if (!enabled) {
        if (attachment) {
            manager->table->detach(manager, attachment);
            Attachment* old = attachment;
            attachment = 0;
            delete old;
        }
    } else {
        Attachment* replacement = new Attachment(this);
        Attachment* old = attachment;
        attachment = replacement;
        delete old;
        manager->table->attach(manager, attachment);
    }
}
