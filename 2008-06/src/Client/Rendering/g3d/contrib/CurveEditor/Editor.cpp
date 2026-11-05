#include "Editor.h"
#include "App.h"

Editor::Editor(App* _app) : GApplet(_app), app(_app) {
    for (int i= 0; i < 12; ++i) {
        control.append(Vector2(random(40, 760), random(40, 540)));
    }

    cyclic = true;
    cyclicCheckRect = Rect2D::xywh(580, 5, 20, 20);
    selectedControl = dragControl = -1;
    messageTime = 0;

    showMessage("Welcome to Curve Editor");
}


void Editor::init()  {
    // Called before Editor::run() beings
    app->debugCamera.setPosition(Vector3(0, 2, 10));
    app->debugCamera.lookAt(Vector3(0, 2, 0));
}


void Editor::cleanup() {
    // Called when Editor::run() exits
}


void Editor::doNetwork() {
	// Poll net messages here
}


void Editor::doSimulation(SimTime dt) {
	// Add physical simulation here
}


void Editor::addPoint(const Vector2& mouse) {
    // Add a point
    Vector2 target = 
        min(max(Vector2(0,0), mouse), 
            Vector2(app->renderDevice->getWidth(), app->renderDevice->getHeight()));

    // Find the curve location nearest the point and insert it between the
    // control points on either side.
    double dist = inf();
    const int N = 300;
    int c0, c1;
    for (int a = 0; a < N; ++a) {
        int t0, t1;
        Vector2 x = evalCurve((double)a/N, t0, t1);
        double d = (x - target).squaredLength();
        if ((d < dist) && (d < 400)) {
            dist = d;
            c0 = t0;
            c1 = t1;
        }
    }

    if (dist < inf()) {
        control.insert(c1, target);
    }
}

// The initial offet between the mouse and control point
static Vector2 offset;

void Editor::selectPoint(const Vector2& mouse) {
    // Find the closest control point
    double dist = inf();
    selectedControl = -1;
    for (int c = 3; c < control.size() - 3; ++c) {
        double d = (mouse - control[c]).length();

        if ((d < 8) && (d < dist)) {
            dist = d;
            selectedControl = c;
            offset = control[c] - mouse;
        }
    }
}


void Editor::showMessage(const std::string& msg) {
    message = msg;
    messageTime = System::time();
}

void Editor::doLogic() {
    if (app->userInput->keyPressed(SDLK_ESCAPE)) {
        // Even when we aren't in debug mode, quit on escape.
        endApplet = true;
        app->endProgram = true;
    }

    Vector2 mouse = app->userInput->mouseXY();

    if (app->userInput->keyPressed(SDL_LEFT_MOUSE_KEY)) {
         if (app->userInput->keyDown(SDLK_RCTRL) ||
            app->userInput->keyDown(SDLK_LCTRL)) {

            addPoint(mouse);
         } else {
     
             // Must allow check box and dragging at the same
             // time or points can get stuck behind the check box.
             if (cyclicCheckRect.contains(mouse)) {
                cyclic = ! cyclic;
             }

             selectPoint(mouse);
             dragControl = selectedControl;
         }
    }

    if (app->userInput->keyPressed(SDL_RIGHT_MOUSE_KEY)) {
        // Right mouse button
    }

    if (app->userInput->keyReleased(SDL_LEFT_MOUSE_KEY)) {
        // Stop drag
        dragControl = -1;
    }

    if (app->userInput->keyDown(SDL_LEFT_MOUSE_KEY) && (dragControl != -1)) {
        // Drag the control point, clamping it to the screen
        control[dragControl] = 
            min(max(Vector2(0,0), mouse + offset), 
                Vector2(app->renderDevice->getWidth(), app->renderDevice->getHeight()));
    }

    if (app->userInput->keyPressed(SDLK_DELETE) && (selectedControl != -1)) {
        control.remove(selectedControl);
        selectedControl = -1;
        dragControl = -1;
    }

    /*
        OPENFILENAME ofn;

        char filename[255];

        ZeroMemory(&ofn, sizeof(ofn));

        SDL_SysWMinfo info;
        SDL_VERSION(&info.version);
        SDL_GetWMInfo(&info);

        //ofn.lStructSize = sizeof(ofn); // SEE NOTE BELOW
        //ofn.hwndOwner = info.window;
        //ofn.lpstrFilter = "Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
        //ofn.lpstrFile = filename;
       // ofn.nMaxFile = 255;
       // ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
       // ofn.lpstrDefExt = "txt";

  
    if (app->userInput->keyPressed(' ')) {
        OPENFILENAME ofn;

        char filename[255];
        char title[255];
        char filetitle[255];

        ZeroMemory(&ofn, sizeof(ofn));

        SDL_SysWMinfo info;
        SDL_VERSION(&info.version);
        SDL_GetWMInfo(&info);
        HWND hWnd = info.window;

        ofn.lStructSize = sizeof(OPENFILENAME);
        ofn.hwndOwner = NULL;
        ofn.hInstance = NULL;
        ofn.lpstrFilter = NULL;
        ofn.lpstrCustomFilter = NULL; 
        ofn.nMaxCustFilter = 0;  
        ofn.nFilterIndex = 0; 
        ofn.lpstrFile = filename; 
        ofn.nMaxFile = 255; 
        ofn.lpstrFileTitle = NULL; 
        ofn.nMaxFileTitle = 0; 
        ofn.lpstrInitialDir = NULL;
        ofn.lpstrTitle = "Save"; 
        ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST; 
        ofn.nFileOffset = 0; 
        ofn.nFileExtension = 0; 
        ofn.lpstrDefExt = NULL; 
        ofn.lCustData = NULL; 
        ofn.lpfnHook = NULL; 
        ofn.lpTemplateName = NULL;
        
        BOOL success = GetOpenFileName(&ofn);
        DWORD e =  CommDlgExtendedError();
        debugAssert(success);
    }
       */

    if (app->userInput->keyPressed('s')) {
        save();
    }

    if (app->userInput->keyPressed('l')) {
        load();
    }
}


void Editor::save() {
    
    // Write out text data
    TextOutput to("curve.txt");
    to.writeNumber(control.size() - 6);
    serialize(cyclic, to);
    for (int c = 3; c < control.size() - 3; ++c) {
        control[c].serialize(to);
    }
    to.commit(false);

    // Write out IFS data
    Array<Quad> quadArray;
    compute3DCurve(quadArray);
    MeshBuilder builder;

    for (int q = 0; q < quadArray.size(); ++q) {
        Quad& quad = quadArray[q];
        builder.addQuad(quad.vertex[0],quad.vertex[1],quad.vertex[2],quad.vertex[3]);
    }

    Array<int> index;
    Array<Vector3> vertex;
    std::string name;
    builder.commit(name, index, vertex);
    IFSModel::save("curve.ifs", "Curve", index, vertex);

    showMessage("Saved curve.txt and curve.ifs");
}



void Editor::load() {
    TextInput ti("curve.txt");
    control.resize(ti.readNumber() + 6);
    deserialize(cyclic, ti);
    for (int c = 3; c < control.size() - 3; ++c) {
        control[c].deserialize(ti);
    }

    showMessage("Loaded curve.txt");
}


static void drawRectLines(const Rect2D& rect, RenderDevice* rd, const Color3& color) {
    rd->setColor(color);
    rd->beginPrimitive(RenderDevice::LINE_STRIP);
        for (int v = 0; v <= 4; ++v) {
            rd->sendVertex(rect.corner(v % 4));
        }
    rd->endPrimitive();
}


void Editor::drawControlPoints() {
    RenderDevice* rd = app->renderDevice;
    rd->pushState();
        
        rd->setLineWidth(1.0);
        rd->setBlendFunc(RenderDevice::BLEND_SRC_ALPHA, RenderDevice::BLEND_ONE_MINUS_SRC_ALPHA);

        for (int c = 3; c < control.size() - 3; ++c) {
            double r = (c == selectedControl) ? 4 : 3;
            
            Rect2D rect = Rect2D::xywh(control[c].x - r, control[c].y - r, 2 * r + 1, 2 * r + 1);

            Draw::rect2D(rect, rd, (c == selectedControl) ? Color3::RED : Color3::YELLOW);
            drawRectLines(rect, rd, Color3::BLACK);
        }
    rd->popState();
}


Vector2 Editor::evalCurve(double a, int& t0, int& t1) const {
    double t;

    if (cyclic) {
        t = (control.size() - 6) * a;
        t0 = iFloor(t) + 3;
        t1 = iCeil(t) + 3;
        return cyclicCatmullRomSpline(t, control.getCArray() + 3, control.size() - 6);
    } else {
        t = 3 + (control.size() - 7) * a;
        t0 = iFloor(t);
        t1 = iCeil(t);
        return cyclicCatmullRomSpline(t, control);
    }
}


void Editor::draw2DCurve() {
    RenderDevice* rd = app->renderDevice;
    rd->pushState();
        rd->setLineWidth(0.5);
        rd->setBlendFunc(RenderDevice::BLEND_SRC_ALPHA, RenderDevice::BLEND_ONE_MINUS_SRC_ALPHA);

        rd->beginPrimitive(RenderDevice::LINE_STRIP);
        rd->setColor(Color3::BLACK);
        int N = 200;

        for (int a = 0; a <= N; ++a) {            
            rd->sendVertex(evalCurve((double)a / N));
        }

        rd->endPrimitive();

    rd->popState();
}


void Editor::drawGrid() {
    RenderDevice* rd = app->renderDevice;
    rd->pushState();
        rd->setLineWidth(0.5);

        rd->setBlendFunc(RenderDevice::BLEND_SRC_ALPHA, RenderDevice::BLEND_ONE_MINUS_SRC_ALPHA);
        int w = rd->getWidth();
        int h = rd->getHeight();

        double s = rd->getHeight() % 40;

        rd->beginPrimitive(RenderDevice::LINES);
            rd->setColor(Color3(.8, 1, 1));
            rd->sendVertex(Vector2(0, 320));
            rd->sendVertex(Vector2(800, 320));
            rd->sendVertex(Vector2(400, 0));
            rd->sendVertex(Vector2(400, 600));

            rd->setColor(Color3(.5, .9, 1));
            for (int x = 0; x < w; x += 40) {
                rd->sendVertex(Vector2(x, 0));
                rd->sendVertex(Vector2(x, h));
            }
            for (int y = 0; y < h; y += 40) {
                rd->sendVertex(Vector2(0, y));
                rd->sendVertex(Vector2(w, y));
            }
        rd->endPrimitive();

        rd->beginPrimitive(RenderDevice::LINE_STRIP);
            for (int a = 0; a <= 40; ++a) {
                double A = G3D_TWO_PI * a / 40;
                rd->sendVertex(Vector2(w, h + 40)/2 + Vector2(cos(A), sin(A)) * 160);
            }
        rd->endPrimitive();

        rd->beginPrimitive(RenderDevice::LINE_STRIP);
            for (int a = 0; a <= 60; ++a) {
                double A = G3D_TWO_PI * a / 60;
                rd->sendVertex(Vector2(w, h + 40)/2 + Vector2(cos(A), sin(A)) * 280);
            }
        rd->endPrimitive();
    rd->popState();
}


void Editor::drawUI() {
    app->font->draw2D("Close Curve", Vector2(605, 0), 20, Color3::WHITE);
    drawRectLines(cyclicCheckRect, app->renderDevice, Color3::WHITE);

    if (cyclic) {
        // Check the box
        app->font->draw2D("X", Vector2(584, 3), 16, Color3::WHITE);
    }

    app->font->draw2D("CTRL + Click to Add", Vector2(10, 0), 15, Color3(.8, 1, 1));
    app->font->draw2D("Delete to Remove", Vector2(10, 20), 15, Color3(.8, 1, 1));
    app->font->draw2D("S to Save", Vector2(10, 40), 15, Color3(.8, 1, 1));
    app->font->draw2D("L to Load", Vector2(10, 60), 15, Color3(.8, 1, 1));

    // Show messages for a while
    double t = messageTime + 4 - System::time();
    if (t > 0) {
        app->font->draw2D(message, Vector2(400, 300), 20, Color4(1,1,1,t), Color4::clear(), 
            GFont::XALIGN_CENTER, GFont::YALIGN_CENTER);
    }
}


void Editor::compute3DCurve(Array<Quad>& quadArray) {
    // Number of strips
    int N = 100;

    // Number of quads per strip (ring)
    int M = 12;

    // Radius of rings
    double r = .1;

    for (int a = 0; a < N; ++a) {
        // 'a' is this ring, 'b' is the next one

        double ta = (double)a / N;
        double tb = (double)(a + 1) / N;

        Vector2 p0a = evalCurve(ta - 0.001);
        Vector2 p1a = evalCurve(ta);
        Vector2 p2a = evalCurve(ta + 0.001);

        Vector2 p0b = evalCurve(tb - 0.001);
        Vector2 p1b = evalCurve(tb);
        Vector2 p2b = evalCurve(tb + 0.001);

        // Scale to -1..1 range
        Vector3 P0a(p0a.x / 400 - 1, 1 - p0a.y / 300, 0);
        Vector3 P1a(p1a.x / 400 - 1, 1 - p1a.y / 300, 0);
        Vector3 P2a(p2a.x / 400 - 1, 1 - p2a.y / 300, 0);

        Vector3 P0b(p0b.x / 400 - 1, 1 - p0b.y / 300, 0);
        Vector3 P1b(p1b.x / 400 - 1, 1 - p1b.y / 300, 0);
        Vector3 P2b(p2b.x / 400 - 1, 1 - p2b.y / 300, 0);

        // Direction of the curve
        Vector3 dPa = (P2a - P0a).direction();
        Vector3 Ua = Vector3::unitZ();
        Vector3 Va = Ua.cross(dPa).direction();
        Ua = -dPa.cross(Va);

        Vector3 dPb = (P2b - P0b).direction();
        Vector3 Ub = Vector3::unitZ();
        Vector3 Vb = Ub.cross(dPb).direction();
        Ub = -dPb.cross(Vb);

        for (int m = 0; m < M; ++m) {
            // Angle
            double q0 = G3D_TWO_PI * m / M; 
            double q1 = G3D_TWO_PI * (m + 1) / M;

            Quad& quad = quadArray.next();

            // Unit vertices relative to curve center
            Vector3 v[4];
            v[0] = Ua * cos(q0) + Va * sin(q0);
            v[1] = Ua * cos(q1) + Va * sin(q1);
            v[2] = Ub * cos(q1) + Vb * sin(q1);
            v[3] = Ub * cos(q0) + Vb * sin(q0);

            quad.vertex[0] = P1a + v[0] * r;
            quad.normal[0] = v[0];

            quad.vertex[1] = P1a + v[1] * r;
            quad.normal[1] = v[1];

            quad.vertex[2] = P1b + v[2] * r;
            quad.normal[2] = v[2];

            quad.vertex[3] = P1b + v[3] * r;
            quad.normal[3] = v[3];
        }

        if (! cyclic) {
            // Number of strips on cap
            int I = 5;

            // Put hemisphere caps on
            if (a == 0) {
                // Begin cap
                Vector3 W = -dPa;
                for (int i = 0; i < I; ++i) {

                    // angle from tip to cap base
                    double aa = G3D_HALF_PI * (double)i / I;
                    double ab = G3D_HALF_PI * (i + 1.0) / I;

                    for (int m = 0; m < M; ++m) {
                        // Angle
                        double q0 = G3D_TWO_PI * m / M; 
                        double q1 = G3D_TWO_PI * (m + 1) / M;
                        Quad& quad = quadArray.next();

                        // Unit vertices relative to curve center
                        Vector3 v[4];
                        v[0] = (Ua * cos(q0) + Va * sin(q0)) * cos(aa) + W * sin(aa);
                        v[1] = (Ua * cos(q1) + Va * sin(q1)) * cos(aa) + W * sin(aa);
                        v[2] = (Ua * cos(q1) + Va * sin(q1)) * cos(ab) + W * sin(ab);
                        v[3] = (Ua * cos(q0) + Va * sin(q0)) * cos(ab) + W * sin(ab);

                        for (int j = 0; j < 4; ++j) {
                            quad.vertex[j] = P1a + v[3 - j] * r;
                            quad.normal[j] = v[3 - j];
                        }
                    }
                }

            } else if (a == N - 1) {
                // End cap
                Vector3 W = dPa;
                for (int i = 0; i < I; ++i) {
                    // angle from tip to cap base
                    double aa = G3D_HALF_PI * (double)i / I;
                    double ab = G3D_HALF_PI * (i + 1.0) / I;

                    for (int m = 0; m < M; ++m) {
                        // Angle
                        double q0 = G3D_TWO_PI * m / M; 
                        double q1 = G3D_TWO_PI * (m + 1) / M;
                        Quad& quad = quadArray.next();

                        // Unit vertices relative to curve center
                        Vector3 v[4];
                        v[0] = (Ub * cos(q0) + Vb * sin(q0)) * cos(aa) + W * sin(aa);
                        v[1] = (Ub * cos(q1) + Vb * sin(q1)) * cos(aa) + W * sin(aa);
                        v[2] = (Ub * cos(q1) + Vb * sin(q1)) * cos(ab) + W * sin(ab);
                        v[3] = (Ub * cos(q0) + Vb * sin(q0)) * cos(ab) + W * sin(ab);

                        for (int j = 0; j < 4; ++j) {
                            quad.vertex[j] = P1b + v[j] * r;
                            quad.normal[j] = v[j];
                        }
                    }
                }
            }

        }
    }

}


void Editor::draw3DCurve() {
    GCamera camera;
    camera.setPosition(Vector3(0,0,5));
    camera.lookAt(Vector3::zero());

    static double q = 0;
    q += 0.001;
    CoordinateFrame cframe;
    cframe.rotation = Matrix3::fromAxisAngle(Vector3::unitY(), q);

    RenderDevice* rd = app->renderDevice;

    rd->setProjectionAndCameraMatrix(camera);
    rd->setObjectToWorldMatrix(cframe);

    int N = 200;

    Array<Quad> quadArray;
    compute3DCurve(quadArray);

    rd->pushState();
    rd->setCullFace(RenderDevice::CULL_BACK);
    rd->enableLighting();
    rd->setShadeMode(RenderDevice::SHADE_SMOOTH);
    rd->setAmbientLightColor(Color3::black());
    rd->setLight(0, GLight::directional(Vector3(1,1,1), Color3::white()));
    rd->setLight(1, GLight::directional(Vector3(-.5,-1,-.2), Color3::blue()));
    rd->setLight(2, GLight::directional(Vector3(-1,0,0), Color3::yellow() * 0.5));
    rd->setLight(3, GLight::directional(Vector3(1,0,0), Color3::yellow() * 0.25));
    rd->setSpecularCoefficient(0.7);
    rd->beginPrimitive(RenderDevice::QUADS);
        rd->setColor(Color3::fromARGB(0xFFF09621));
        for (int q = 0; q < quadArray.size(); ++q) {
            for (int v = 0; v < 4; ++v) {
                rd->setNormal(quadArray[q].normal[v]);
                rd->sendVertex(quadArray[q].vertex[v] * 2);
            }
        }
    rd->endPrimitive();
    rd->popState();

    /*
    // Show normals
    rd->beginPrimitive(RenderDevice::LINES);
        for (int q = 0; q < quadArray.size(); ++q) {
            for (int v = 0; v < 4; ++v) {
                rd->sendVertex(quadArray[q].vertex[v] + quadArray[q].normal[v] * .1);
                rd->sendVertex(quadArray[q].vertex[v]);
            }
        }
    rd->endPrimitive();
    */
}


void Editor::doGraphics() {
    // The first and last points are duplicated in the non-cyclic case 
    // in order to terminate the curve cleanly.
    for (int i = 0; i < 3; ++i) {
        control[i] = control[3];
        control[control.size() - i - 1] = control[control.size() - 4];
    }

    // Cyan background
    app->renderDevice->setColorClearValue(Color3(.3, .7, 1));

    app->renderDevice->clear(true, true, true);


    app->renderDevice->push2D();
        drawGrid();
    app->renderDevice->pop2D();

    app->renderDevice->pushState();
//        Rect2D view = Rect2D::xywh(500, 400, 300, 200);
//        app->renderDevice->setViewport(view);
        draw3DCurve();
    app->renderDevice->popState();

    app->renderDevice->push2D();
        draw2DCurve();
        drawControlPoints();
        drawUI();
    app->renderDevice->pop2D();

    /*
    LightingParameters lighting(G3D::toSeconds(11, 00, 00, AM));
    app->renderDevice->setProjectionAndCameraMatrix(app->debugCamera);
    app->renderDevice->enableLighting();
		app->renderDevice->setLight(0, GLight::directional(lighting.lightDirection, lighting.lightColor));
		app->renderDevice->setAmbientLightColor(lighting.ambient);

  */
//		Draw::axes(CoordinateFrame(Vector3(0, 4, 0)), app->renderDevice);
 //   app->renderDevice->disableLighting();

}

int Editor::ignore0, Editor::ignore1;
