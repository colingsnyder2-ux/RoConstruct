// from server: 100% by ivan-grebe
struct Event
{
    char padding0[0x0c];
    int field0c;
    int field10;
    int field14;
    char padding1[0x20];
    int field38;
    int field3c;
};

struct CRobloxTreeCtrl
{
    char padding0[0xb8];
    unsigned char fieldb8;
    char padding1[0x30];
    unsigned char fielde9;
    char padding2[0x42];
    int field12c;

    void func_0041d420(void *, int);
    void func_0041d540(Event *, int *);
};

void CRobloxTreeCtrl::func_0041d540(Event *event, int *result)
{
    *result = 0;
    if (fielde9 == 0 && fieldb8 == 0 && field12c != 0)
    {
        if (event->field3c != 0)
            func_0041d420(&event->field38, 1);

        if (event->field14 != 0 && event->field0c != 0)
            func_0041d420(&event->field10, 0);
    }
}
