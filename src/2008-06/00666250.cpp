// from server: 100% by tester
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
namespace RBX {
class Filter
{
    float alpha;
    float value;
public:
    float update(float input);
};

float Filter::update(float input)
{
    return value = (input - value) * alpha + value;
}
}
