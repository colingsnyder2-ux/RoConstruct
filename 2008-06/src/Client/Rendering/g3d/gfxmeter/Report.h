/**
  @file gfxmeter/Report.h

  @author Morgan McGuire, matrix@graphics3d.com
 */

#ifndef REPORT_H
#define REPORT_H

#include "../include/G3DAll.h"

class MD2 {
public:
    CoordinateFrame     cframe;
    MD2ModelRef         model;
    MD2Model::Pose      pose;
    GMaterial           material;

    void load(const std::string& filename) {
        model = MD2Model::create(filename + ".md2");
        material.texture.append(Texture::fromFile(filename + ".pcx", 
            TextureFormat::AUTO, Texture::TILE, Texture::TRILINEAR_MIPMAP, Texture::DIM_2D, 2.0));
    }

    void render(RenderDevice* rd) {
        model->pose(cframe, pose, material)->render(rd);
    }

    void renderShadow(RenderDevice* rd) {
        CoordinateFrame cframe2 = cframe;
        cframe2.rotation.setColumn(1, Vector3::zero());
        cframe2.translation.y -= 1.7f;
        rd->setColor(Color3(.9f, .9f, 1));

        PosedModelRef m = model->pose(cframe2, pose);

        // Intentionally render a lot of shadows to gauge rendering performance
        for (int i = 0; i < 20; ++i) {
            m->render(rd);
        }
    }

    void doSimulation(GameTime dt) {
        pose = MD2Model::Pose(MD2Model::STAND, System::getTick());
        /*
        pose.doSimulation(dt,
            false, false, false, 
            true,  false, false, 
            false, false, false, 
            false, false, false,
            false, false, false,
            false);
            */
    }
};

/**
 Renders the summary page
 */
class Report : public GApplet {

    MD2                 knight;
    MD2                 ogre;

    enum Popup {NONE, PERFORMANCE};

    Popup               popup;

    Rect2D              performanceButton;
    Rect2D              closeButton;

    class App*          app;

    /** Draw some nice graphics */
    void doFunStuff();

    /** Draws the popup window, but not its contents.  Returns the window bounds. */
    Rect2D drawPopup(const char* title);

public:

    Report(App* app);


    virtual ~Report() {}

    virtual void init();

    virtual void doLogic();

	virtual void doNetwork();

    virtual void doSimulation(SimTime dt);

    virtual void doGraphics();

    virtual void cleanup();

};

#endif
