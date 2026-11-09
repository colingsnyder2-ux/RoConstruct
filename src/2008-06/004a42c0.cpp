// from server: 100% by king_originala
void* __cdecl getSettings();

struct Base {
    unsigned long words[78];
    Base();
    ~Base();
};

struct Server : Base {
    Server();
};

Server::Server() : Base()
{
    words[7] = reinterpret_cast<unsigned long>(getSettings());
    words[0] = 0x00823984;
    words[4] = 0x00823978;
    words[5] = 0x00823970;
    words[8] = 0x00823968;
    words[9] = 0x00823958;
    words[17] = 0x00823948;
    words[25] = 0x00823938;
    words[33] = 0x00823928;
    words[41] = 0x00823918;
    words[49] = 0x00823908;
    words[76] = 0x008238D8;
    words[77] = 0x008238CC;
}
