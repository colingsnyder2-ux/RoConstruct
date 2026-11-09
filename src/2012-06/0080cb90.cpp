// from server: 68% by atomic.potato
typedef unsigned int DWORD;

struct S
{
    DWORD v0;
    DWORD v4;
    DWORD pad[4];
    DWORD v18;
    DWORD v1c;
    DWORD pad2[24];
    DWORD v80;
    DWORD v84;

    S();
};

S::S()
{
    v0 = 0x00bc501c;
    v4 = 0x00bc5010;
    v18 = 0x00bc5004;
    v1c = 0x00bc4ff8;
    v80 = 0x00bc4fe8;
    v84 = 0x00bc4fbc;
}
