// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_equationrtti_32dcacc030ec45f0.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
typedef std::string String;
namespace RBX {
class Instance
{
public:
    virtual String evaluate(const String&) = 0;
    char padding[0x100];
    Instance* parent;

    Instance* getRootAncestor();
};

class Evaluator : public Instance
{
public:
    virtual String evaluate(const String&) = 0;
};

class EquationDisplay : public Instance
{
public:
    char padding2[0x3c];
    String text;
    char padding3[0x28];
    String expression;

    String display();
};

String EquationDisplay::display()
{
    Instance* root;
    if (this)
    {
        root = parent;
        if (root)
        {
            if (root->parent)
                root = root->parent->getRootAncestor();
        }
        else
            root = this;
    }
    else
        root = 0;

    Evaluator* evaluator = dynamic_cast<Evaluator*>(root);
    if (evaluator)
    {
        String value = evaluator->evaluate(expression);
        return text + " " + value;
    }
    return text;
}

}
