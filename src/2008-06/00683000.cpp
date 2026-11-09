// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: ogre-1.4.5 roc_espeon_renderprimitive6529969e3c0e9a10.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <OgreRoot.h>
#include <OgreRenderSystem.h>
#include <OgreColourValue.h>
#include <list>
struct Color {float r,g,b,a;};
struct DrawCommand {float left,top,right,bottom;float textureCoordinates[4];Ogre::RGBA color;int texture;int primitive;int mode;};
struct Renderer {char prefix[0x3c];std::list<DrawCommand> commands;void rectangle(int,float,float,float,float,const Color&);};
void Renderer::rectangle(int primitive,float left,float top,float right,float bottom,const Color&color){DrawCommand command;command.left=left;command.top=top;command.right=right;command.bottom=bottom;Ogre::RenderSystem* rs=Ogre::Root::getSingleton().getRenderSystem();rs->convertColourValue(Ogre::ColourValue(color.r,color.g,color.b,color.a),&command.color);command.texture=0;command.primitive=primitive;command.mode=0;commands.push_back(command);}
