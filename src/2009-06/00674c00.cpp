// from server: 100% by tester
struct Teams {
    char pad[0x94];
    int field120;
    char field124;
};

int __stdcall getTeamFromPlayer(Teams* p);

int __stdcall tail(int);

int __stdcall getTeamFromPlayer(Teams* p)
{
    if (p->field124 != 0)
        return 0;
    return tail(p->field120);
}
