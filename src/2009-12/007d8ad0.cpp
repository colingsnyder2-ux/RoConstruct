// from server: 42% by atomic.potato
struct RBX_HUMAN_Jumping {
    void construct(int, int);
    char pad[8];
    float field_c;
};

extern float g_9af2dc;
extern int g_9ef86c;
extern int g_9ef864;

void RBX_HUMAN_Jumping::construct(int a, int b)
{
    g_9ef86c = 0;
    g_9ef864 = 0;
    field_c = g_9af2dc;
}
