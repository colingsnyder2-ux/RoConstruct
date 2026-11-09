#include <G3DAll.h>

class Editor : public GApplet {
private:

    class Quad {
    public:
        Vector3         vertex[4];
        Vector3         normal[4];
    };


    static int          ignore0, ignore1;

    /** In the pixel coordinate system.  The first and last three points are duplicates */
    Array<Vector2>      control;

    /** When true, connect the last point to the first point */
    bool                cyclic;

    /** GUI region corresponding to check box */
    Rect2D              cyclicCheckRect;

    /** Control point currently being dragged, -1 if none */
    int                 dragControl;

    /** Currently selected control point, -1 if none */
    int                 selectedControl;

    /** Number of segments to distribute over the whole curve */
    int                 numSegments;

    std::string         message;
    RealTime            messageTime;

    class App*          app;

    /** Given a number between 0 and 1, returns a point on the curve
        and the indices of the two control points that most directly
        affect it.*/
    Vector2 evalCurve(double a, int& t0 = ignore0, int& t1 = ignore1) const;

    /** Constructs the 3D surface surrounding the curve*/
    void compute3DCurve(Array<Quad>& quadArray);

    /** Insert a point at the given location */
    void addPoint(const Vector2& mouse);

    /** Begin dragging the point at the mouse */
    void selectPoint(const Vector2& mouse);

    void drawGrid();
    void drawControlPoints();
    void draw2DCurve();
    void draw3DCurve();
    void drawUI();

    void showMessage(const std::string&);

    /** Filename is hardcoded for the moment */
    void save();
    void load();

public:

    Editor(App* app);    

    virtual void init();

    virtual void doLogic();

	virtual void doNetwork();

    virtual void doSimulation(SimTime dt);

    virtual void doGraphics();

    virtual void cleanup();

};