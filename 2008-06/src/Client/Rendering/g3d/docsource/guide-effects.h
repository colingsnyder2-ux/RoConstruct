/**
 @page guideeffects Effects

  \htmlonly
<TABLE BORDER=0 WIDTH=80%><TR><TD><I><FONT FACE="Arial">
<A HREF="guidecollision.html"><IMG SRC="backarrow.gif" BORDER=0 ALIGN=MIDDLE>
Collision Detection</A></I></FONT></TD><TD ALIGN=RIGHT><FONT FACE="Arial"><I>
<A HREF="guideshaders.html">
Shaders <IMG SRC="forwardarrow.gif" BORDER=0 ALIGN=MIDDLE></A></I></FONT></TD></TR></TABLE>
\endhtmlonly

  G3D has methods and helper functions for creating many common effects, such as shadows and cartoon style rendering. This guide will document some of the common functions and how to use them in your projects.<br>


  @section cartoon Cartoon Rendering
   Cartoon style rendering can be achieved with ease in G3D, using the function G3D::drawFeatureEdges. This function finds the 'cartoon' edges, which mostly compromise the outline of an object, but can include internal edges where the geometry overlaps. <br>
   To use this function, turn off lighting and render the object with this function. In order to gain the full effect, the object have to be rendered first with a negative polygon offset. This would make the edges 'stand out', and prevent them being hidden inside the model itself.<br>
   Some example code for using drawFeatureEdges is given below. drawFeatureEdges is given the renderDevice and a posed model to draw. It is this posed model that the function will act on, and draw the edges of.
   <PRE>
       app->renderDevice->pushState();
        app->renderDevice->enableDepthWrite();
        app->renderDevice->setTexture(0,NULL);
        app->renderDevice->disableLighting();
        app->renderDevice->setColor(Color3::blue());
        app->renderDevice->setLineWidth(2.0);
        G3D::drawFeatureEdges(app->renderDevice, model->pose(cframe, pose));
        app->renderDevice->enableLighting();
    app->renderDevice->popState();
    </PRE>
    For an example of this in use, insert the code into the start of the drawCharWithShadow method in the MD2Model Demo. This should then highlight all the edges of the knight character in blue, as set by the renderDevice calls in the sample code.

  @section shadows Shadows
   The easiest way to create shadows in G3D is to use a posed model.
   This code is taken from the markShadows documentation, it shows how to set up the rendering and in what order to perform operations:

   <PRE>
       renderDevice->clear(true, true, true);
       renderDevice->pushState();
           renderDevice->enableLighting()
   //Configure ambient light
           renderDevice->setAmbientLightColor(Color3::white() * .25);

           for (int m = 0; m < model.size(); ++m) {
               model[m]->render(renderDevice);
           }

           renderDevice->disableDepthWrite();
             for (int L = 0; L < light.size(); ++L) {
               beginMarkShadows(renderDevice);
                   for (int m = 0; m < model.size(); ++m) {
                       markShadows(renderDevice, model[m], light[L]);
                   }
               endMarkShadows(renderDevice);

               renderDevice->setBlendFunc(RenderDevice::BLEND_ONE, RenderDevice::BLEND_ONE);
               renderDevice->setStencilTest(RenderDevice::STENCIL_EQUAL);
               renderDevice->setStencilConstant(0);
               renderDevice->setAmbientLightColor(Color3::black());
               renderDevice->setDepthTest(RenderDevice::DEPTH_LEQUAL);

               renderDevice->setLight(0, light[L]);
               for (int m = 0; m < model.size(); ++m) {
                   model[m]->render(renderDevice);
               }
           }
       renderDevice->popState();
  </PRE>

	Shadow Maps are also supported by G3D, using the following methods:<br>
   G3D::RenderDevice::configureShadowMap
  @section reflections Reflections
   G3D provides a simple helper function for creating realistic reflections on objects.   G3D::RenderDevice::configureReflectionMap. This function will automatically create a reflection of the world around the object and project it onto the object for rendering.
   Sample code demonstrating the function's use:
   <PRE>
    app->renderDevice->pushState();
        app->renderDevice->configureReflectionMap(0,sky->getEnvironmentMap());
        Draw::sphere(Sphere(Vector3(0,0,0),1.0),app->renderDevice, Color3::white(),Color4::clear());
    app->renderDevice->popState();
   </PRE>
   This code gets the environment map from the skybox and maps it onto the sphere object which is being drawn. The result of this is a reflection of the surrounding sky on the sphere.


	CubeMap reflections can be configured using the following methods:<br>
  G3D::copyFromScreen, G3D::configureCubeMap, G3D::Texture::getCameraRotation

*/