// from server: 57% by atomic.potato
int g_value;
int g_result;

struct GWindow
{
    int f(int value);
};

int GWindow::f(int value)
{
    g_value = value;
    int local = g_result;
    return local;
}
