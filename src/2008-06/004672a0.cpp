// from server: 100% by king_originala
struct CSettingsDialog
{
    volatile int first;
    volatile int second;
    volatile short third;
    volatile short fourth;
    volatile short fifth;
    volatile short sixth;
    volatile int seventh;

    CSettingsDialog(int a, int b, int c);
};

CSettingsDialog::CSettingsDialog(int a, int b, int c)
{
    first = b;
    second = a;
    third = 0;
    fourth = 0;
    fifth = 0;
    sixth = 0;
    seventh = c;
}
