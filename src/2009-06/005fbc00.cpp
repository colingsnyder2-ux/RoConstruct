// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
struct Avg {
    unsigned int count;
    int index;
    std::vector<double> values;
    double average() const;
};
double Avg::average() const
{
    double sum = 0;
    for (unsigned int i = 0; i < count; ++i)
        sum += values[i];
    return sum * (1.0f / count);
}
