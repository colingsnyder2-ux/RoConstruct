// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs roc_unifiedwidget_metric_sum_1724d92846676ee2.cpp

// Candidate translation unit (score above; library headers required).
struct Metric
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual float sample();
};

struct MetricCollection
{
    char reserved[0x24];
    Metric** items;
    int size;
};

namespace RBX
{
    struct UnifiedWidget
    {
        char reserved[0x10];
        MetricCollection* metrics;

        float sampleMetrics();
    };
}

float RBX::UnifiedWidget::sampleMetrics()
{
    float total = 0.0f;
    int index = 0;
    MetricCollection* current = metrics;
    while (index < current->size)
    {
        total += current->items[index]->sample();
        current = metrics;
        ++index;
    }
    return total;
}
