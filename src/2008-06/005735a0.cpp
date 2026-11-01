// from server: 100% by atomic.potato
extern float g_82f864;

struct UnifiedWidget {
    void f(float *value);
};

void UnifiedWidget::f(float *value)
{
    value[0] = 0.0f;
    value[1] = g_82f864;
}
