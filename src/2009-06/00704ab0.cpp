// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
struct GLUquadric;
typedef unsigned int GLenum;
extern "C" {
__declspec(dllimport) void __stdcall glPushMatrix(void);
__declspec(dllimport) void __stdcall glPopMatrix(void);
__declspec(dllimport) void __stdcall glRotatef(float angle, float x, float y, float z);
__declspec(dllimport) void __stdcall glTranslatef(float x, float y, float z);
GLUquadric* __stdcall gluNewQuadric(void);
void __stdcall gluDeleteQuadric(GLUquadric* state);
void __stdcall gluQuadricDrawStyle(GLUquadric* quadObject, GLenum drawStyle);
void __stdcall gluQuadricOrientation(GLUquadric* quadObject, GLenum orientation);
void __stdcall gluCylinder(GLUquadric* qobj, double baseRadius, double topRadius, double height, int slices, int stacks);
void __stdcall gluDisk(GLUquadric* qobj, double innerRadius, double outerRadius, int slices, int loops);
}
#define GLU_FILL 100012
#define GLU_INSIDE 100021
namespace G3D { class RenderDevice; }
namespace RBX {
class DrawPrimitives {
public:
    static void rawCylinderAlongX(float radius, float axis, G3D::RenderDevice* rd, bool capped);
};
void DrawPrimitives::rawCylinderAlongX(float radius, float axis, G3D::RenderDevice* rd, bool capped)
{
	glPushMatrix();

	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 0, -axis * 0.5);

	GLUquadric* quadric = gluNewQuadric();
	gluQuadricDrawStyle(quadric, GLU_FILL);
	gluCylinder(quadric, radius, radius, axis, 12, 1);
	if (capped)
	{
		gluQuadricOrientation(quadric, GLU_INSIDE);
		gluCylinder(quadric, radius, radius, axis, 12, 1);
	}
	gluDeleteQuadric(quadric);

	if (capped)
	{
		glTranslatef(0, 0, axis);
		quadric = gluNewQuadric();
		gluQuadricDrawStyle(quadric, GLU_FILL);
		gluDisk(quadric, 0, radius, 12, 1);
		gluDeleteQuadric(quadric);

		glRotatef(180, 0, 1, 0);
		glTranslatef(0, 0, axis);
		quadric = gluNewQuadric();
		gluQuadricDrawStyle(quadric, GLU_FILL);
		gluDisk(quadric, 0, radius, 12, 1);
		gluDeleteQuadric(quadric);
	}

	glPopMatrix();
}
}
