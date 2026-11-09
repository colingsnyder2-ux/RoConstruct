/** @page guidevideo Video and Image Processing

  \htmlonly
<TABLE BORDER=0 WIDTH=80%><TR><TD><I><FONT FACE="Arial">
<A HREF="guidefbo.html"><IMG SRC="backarrow.gif" BORDER=0 ALIGN=MIDDLE>
Framebuffer Objects</A></I></FONT></TD></TR></TABLE>
\endhtmlonly

 @section Classes
 <ul>
 <li>G3D::GImage can load several popular image file formats. It does not depend on OpenGL. 
 <li><A HREF="contrib/Image">contrib/Image</a> is designed for image processing.  It supports arbitrary element types (e.g., float, double, Color3uint8),
 as well as bilinear and bicubic interpolation.
 <li>G3D::Texture can load most of the GImage formats as well as DirectX texture format; it is stored on the graphics processor and can be rendered extremely efficiently
 <li>G3D::Draw::fullScreenImage is a slow but simple method for filling the screen with a G3D::GImage.  A faster method is shown below.
 <li>G3D::Shader can be used to execute video processing pixel shaders on graphics hardware
 <li>contrib/AVI contains code to read and write AVI files on Windows using any codec installed on the machine.  It is slow, however and not intended for real-time playback and recording
 <li>G3D::RenderDevice::screenshotPic can capture the current framebuffer to a GImage for saving.  It uses glReadPixels
 <li>G3D::Texture::copyFromScreen copies part of the current frame to a texture for future rendering
 <li>G3D::RenderBuffer and G3D::FrameBuffer can be used for extremely fast render-to-texture on newer graphics cards and drivers
 <li>G3D::Rect2D can compute useful intersections, unions, and aspect ratios for image processing
 </ul>

 @section Software
 We recommend:
 <ul>
 <li>Shareware FRAPS program for recording the output of 3D programs in real time
 <li>Open Source VirtualDub for editing and compressing videos
 </ul>

 @section GPU Video on the GPU

 Graphics cards have about 10x the memory bandwidth and processing power of CPUs and are well adapted to image sampling (texture mapping) tasks.
 It is a natural fit to execute image and video processing algorithms on the graphics processor.  A common method for doing this is to
 load an image as a texture and then render it as a rectangle with a pixel shader.  The output can be read back to a Texture or GImage, or using 
 RenderBuffers, rendered directly to a Texture.

 It important to avoid off-by-one errors when rendering such Textures.  
 
 The G3D::Texture::DIM_2D_NPOT texture dimension allows non-power of two size textures (e.g., 640 x 480).  
 The G3D::Texture::CLAMP mode ensures that reads will not wrap around to the other side.

 G3D::RenderDevice::push2D automatically applies a slight shift 

<pre>
    GImage im(1024, 768, 3);
    GImage::makeCheckerboard(im);
    TextureRef t = Texture::fromGImage("Checker", im, TextureFormat::AUTO, Texture::DIM_2D_NPOT, Texture::Parameters::video());

    ...

    void doGraphics(RenderDevice* rd) {
        rd->push2D();
            rd->setTexture(0, t);
            Draw::rect2D(t->rect2DBounds(), rd);
        rd->pop2D();
    }
</pre>

 When sampling from an image texture, it is often useful to know how large a texel is in the normalized [0, 1] texture coordinate space.
 G3D::Shader supports an extension to GLSL where the expression <code>g3d_size(sampler)</code> returns the size of

  */
