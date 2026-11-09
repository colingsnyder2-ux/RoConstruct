// from server: 51% by king_originala
extern "C" void* __cdecl malloc(unsigned int);
extern "C" void* __cdecl _alloca(unsigned int);
#pragma intrinsic(_alloca)

struct Address {
    unsigned int host;
    unsigned short port;
    unsigned short padding;
    bool different(const Address&);
};

extern Address unassignedAddress;

struct Sender {
    void send(const char*, int, int, int, int, bool,
              unsigned int, unsigned __int64);
};

struct Remote {
    unsigned char active;
    unsigned char pad1[3];
    Address address;
    unsigned char padC[12];
    unsigned char senderStorage[0x800];
    unsigned int nextTime;
    unsigned char pad81C[0x28];
    unsigned int identifier;
    unsigned char pad848[8];
};

struct S {
    unsigned char pad0[8];
    unsigned short count;
    unsigned char padA[0x222];
    Remote* remotes;

    bool f(const char*, int, int, int, int, Address,
           bool, bool, unsigned __int64);
};

bool S::f(const char* data, int bits, int priority, int reliability,
          int channel, Address address, bool broadcast,
          bool transfer, unsigned __int64 time)
{
    unsigned int localIndices[64];
    unsigned int* indices;
    unsigned int selected = 0;
    bool sent = false;

    if (broadcast) {
        unsigned int size = count * sizeof(unsigned int) + 8;
        if (size <= 1024) {
            indices = (unsigned int*)_alloca(size);
            if (indices)
                *indices = 0xcccc;
        } else {
            indices = (unsigned int*)malloc(size);
            if (indices)
                *indices = 0xdddd;
        }
        if (indices)
            indices += 2;

        unsigned int offset = 0;
        for (unsigned int i = 0; i < count; ++i, offset += 0x850) {
            Remote* remote = (Remote*)((char*)remotes + offset);
            if (remote->active &&
                remote->address.different(address) &&
                ((Remote*)((char*)remotes + offset))->address.different(
                    unassignedAddress))
                indices[selected++] = i;
        }

        if (!selected)
            return false;
    } else {
        indices = localIndices;
        for (unsigned int i = 0; i < count; ++i) {
            if (remotes[i].active &&
                !remotes[i].address.different(address)) {
                indices[selected++] = i;
                break;
            }
        }

        if (!selected)
            return false;
    }

    for (unsigned int i = 0; i < selected; ++i) {
        bool finalSend = transfer && !sent && i + 1 == selected;
        Remote* remote = remotes + indices[i];

        ((Sender*)remote->senderStorage)->send(
            data, bits, priority, reliability, channel,
            !finalSend, remote->identifier, time);

        if (finalSend)
            sent = true;

        if (reliability == 2 || reliability == 3 || reliability == 4)
            remotes[indices[i]].nextTime =
                (unsigned int)(time / 1000);
    }

    return sent;
}
