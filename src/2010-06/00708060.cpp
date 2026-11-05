// from server: 48% by atomic.potato
struct PlayerHUD
{
    PlayerHUD();
    int field04;
    int field10;
    int field14;
    int field18;
    int field1c;
};

PlayerHUD::PlayerHUD()
{
    field18 = -1;
    field1c = -1;
    field10 = 3;
    field14 = 3;
    field04 = 3;
}
