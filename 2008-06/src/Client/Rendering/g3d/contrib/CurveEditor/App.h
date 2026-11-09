#include <G3DAll.h>
class App : public GApp {
protected:
    void main();
public:

    GFontRef    font;

    App(const GAppSettings& settings);
};