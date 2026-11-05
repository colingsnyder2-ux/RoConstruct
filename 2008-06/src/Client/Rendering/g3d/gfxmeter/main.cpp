/**
  @file gfxmeter/main.cpp

  slow/shadow map (radeon)

  @author Morgan McGuire, matrix@graphics3d.com
 */

#include "../include/G3DAll.h"

#if G3D_VER < 60900
    #error Requires G3D 6.09
#endif

#include "Report.h"
#include "App.h"
#ifdef G3D_WIN32
#   include <direct.h>
#endif

#define FAST
 
static const float gfxMeterVersion = 0.9f;

int CPU_speed_in_MHz();

/**
 FPS   = frames per second
 VPS   = vertices per second

 RAM   = vertices stored in main memory
 VBO   = vertices stored in vertex buffer object
 VBO16 = using smaller indices
 VBOI  = vertices stored in VBO, interleaved

 First array element is low coherence, second is high coherence
 */
void measureVertexPerformance(
    GWindow* w,     
    int&   numTris,
    float  beginEndFPS[2],
    float  drawElementsRAMFPS[2], 
    float  drawElementsVBOFPS[2], 
    float  drawElementsVBO16FPS[2], 
    float  drawElementsVBOIFPS[2],
    float  drawElementsVBOPeakFPS[2],
    float& drawArraysVBOPeakFPS);

void shaderVersions(
    std::string& regStr,
    std::string& asmStr,
    std::string& glslStr);


void App::showSplashScreen() {
    TextureRef gfxMeterTexture = Texture::fromFile("gears.jpg", TextureFormat::AUTO, Texture::CLAMP);

    // Load the font
    if (reportFont.isNull()) {
        reportFont = GFont::fromFile(NULL, dataDir + "arial.fnt");
    }

    renderDevice->push2D();
    
        renderDevice->setColorClearValue(Color3::white());
        renderDevice->clear();

        int s = gfxMeterTexture->getTexelWidth();
        int w = 800, h = 600;
        renderDevice->setTexture(0, gfxMeterTexture);
        Draw::rect2D(Rect2D::xywh(w/2-s/2,h/2-s/2,s,s), renderDevice);

        // Second time through, render some text
        if (reportFont.notNull()) {
            reportFont->draw2D(renderDevice, "Profiling your system...", Vector2(w/2, h/2+s/2 + 10), 
                19, Color3::black(), Color4::clear(), GFont::XALIGN_CENTER);
        }

    renderDevice->pop2D();
    window()->swapGLBuffers();
}


void App::main() {
	setDebugMode(false);
	debugController.setActive(false);

    //window()->swapGLBuffers();while(true);

    // Choose a card logo
    {
        std::string filename = "";
        if (beginsWith(GLCaps::vendor(), "NVIDIA")) {
            filename = "nvidia.jpg";
        } else if (beginsWith(GLCaps::vendor(), "ATI")) {
            filename = "ati.jpg";
        }

        if (filename != "") {
            cardLogo = Texture::fromFile(filename, TextureFormat::AUTO, Texture::CLAMP);
        }
    }

    // Choose chip logo
    {
        std::string filename = "";
        if (endsWith(toLower(System::cpuVendor()), "intel")) {
            filename = "intel.jpg";
        } else if (endsWith(toLower(System::cpuVendor()), "amd")) {
            filename = "amd.jpg";
        }

        if (filename != "") {
            chipLogo = Texture::fromFile(filename, TextureFormat::AUTO, Texture::CLAMP);
        }

#       ifdef G3D_WIN32
            double speed = CPU_speed_in_MHz() * 1e6;
            if (speed > 1e9) {
                chipSpeed = format("%.1f GHz", speed / 1e9);
            } else if (speed > 10e6) {
                chipSpeed = format("%.1f MHz", speed / 1e6);
            }
            // Probably a bad result if speed is less than 1 MHz
#       endif
    }

    // Choose os logo
    {
        std::string filename = "";
        std::string os = System::operatingSystem ();

        if (beginsWith(os, "Windows 5.0")) {
            filename = "win2k.jpg";
        } else if (beginsWith(os, "Windows 5.1")) {
            filename = "winxp.jpg";
        }

        if (filename != "") {
            osLogo = Texture::fromFile(filename, TextureFormat::AUTO, Texture::CLAMP);
        }
    }

    titleFont = GFont::fromFile(NULL, dataDir + "carbon.fnt");

    shaderVersions(combineShader, asmShader, glslShader);
    computeFeatureRating();

    Log::common()->printf("Shaders:\n");
    Log::common()->printf("   Combiners: %s\n", combineShader.c_str());
    Log::common()->printf("   Assembly:  %s\n", asmShader.c_str());
    Log::common()->printf("   GLSL:      %s\n", glslShader.c_str());
    Log::common()->printf("\n\n");

#   ifndef FAST
    {
        measureVertexPerformance(
            window(),
            vertexPerformance.numTris, 
            vertexPerformance.beginEndFPS, 
            vertexPerformance.drawElementsRAMFPS,
            vertexPerformance.drawElementsVBOFPS,
            vertexPerformance.drawElementsVBO16FPS,
            vertexPerformance.drawElementsVBOIFPS,
            vertexPerformance.drawElementsVBOPeakFPS,
            vertexPerformance.drawArraysVBOPeakFPS);

        Log::common()->printf("\nDetailed Performance Tests\n\n");
        Log::common()->printf("   * Vertex Rate\n");
        Log::common()->printf("    %d tris, 2 lights, 1 texture, and 4 attributes\n\n", vertexPerformance.numTris); 
        Log::common()->printf("                             Low Coherence [ High Coherence ]\n");
        Log::common()->printf("    Method                           FPS   [  FPS  |Mverts/sec]\n");
        Log::common()->printf("   ------------------------------------------------+---------\n");
        Log::common()->printf("    glBegin/glEndFPS:                %5.1f [ %5.1f | %5.1f ]\n", vertexPerformance.beginEndFPS[0], vertexPerformance.beginEndFPS[1], vertexPerformance.beginEndFPS[1] * 3 * vertexPerformance.numTris / 1e6);
        Log::common()->printf("    glDrawElements:                  %5.1f [ %5.1f | %5.1f ]\n", vertexPerformance.drawElementsRAMFPS[0], vertexPerformance.drawElementsRAMFPS[1], vertexPerformance.drawElementsRAMFPS[1] * 3 * vertexPerformance.numTris / 1e6);
        Log::common()->printf("        + VBO                        %5.1f [ %5.1f | %5.1f ]\n", vertexPerformance.drawElementsVBOFPS[0], vertexPerformance.drawElementsVBOFPS[1], vertexPerformance.drawElementsVBOFPS[1] * 3 * vertexPerformance.numTris / 1e6);
        Log::common()->printf("        + uint16 index               %5.1f [ %5.1f | %5.1f ]\n", vertexPerformance.drawElementsVBO16FPS[0], vertexPerformance.drawElementsVBO16FPS[1], vertexPerformance.drawElementsVBO16FPS[1] * 3 * vertexPerformance.numTris / 1e6);
        Log::common()->printf("        + interleaved                %5.1f [ %5.1f | %5.1f ]\n", vertexPerformance.drawElementsVBOIFPS[0], vertexPerformance.drawElementsVBOIFPS[1], vertexPerformance.drawElementsVBOIFPS[1] * 3 * vertexPerformance.numTris / 1e6);
        Log::common()->printf("        without shading              %5.1f [ %5.1f | %5.1f ]\n", vertexPerformance.drawElementsVBOPeakFPS[0], vertexPerformance.drawElementsVBOPeakFPS[1], vertexPerformance.drawElementsVBOPeakFPS[1] * 3 * vertexPerformance.numTris / 1e6);
        Log::common()->printf("    glDrawArrays Peak:                     [ %5.1f | %5.1f ]\n", vertexPerformance.drawArraysVBOPeakFPS, vertexPerformance.drawArraysVBOPeakFPS * 3 * vertexPerformance.numTris / 1e6);
        Log::common()->printf("\n\n");
    }
#   endif

    countBugs();
    
    // Load objects here
    sky = NULL;//Sky::create(NULL, dataDir + "sky/");

    applet->run();
}


void App::countBugs() {
    bugCount = 0;

    Log::common()->printf("\n\nBugs:\n");
    if (GLCaps::hasBug_glMultiTexCoord3fvARB()) {
        ++bugCount;
        Log::common()->printf("   Detected glMultiTexCoord3fvARB bug\n\n");
    } 
    

    if (GLCaps::hasBug_normalMapTexGen()) {
        ++bugCount;
        Log::common()->printf("   Detected normalMapTexGen bug\n\n");
    } 

    if (GLCaps::hasBug_slowVBO()) {
        ++bugCount;
        Log::common()->printf("   Detected slowVBO bug\n\n");
    }

    if (GLCaps::hasBug_redBlueMipmapSwap()) {
        ++bugCount;
        Log::common()->printf("   Detected redBlueMipmapSwap bug\n\n");
    }

    if (beginsWith(GLCaps::renderer(), "RADEON") &&
        GLCaps::supports_GL_ARB_shadow() &&
        GLCaps::supports_GL_ARB_shading_language_100()) {
        // Slow shadow map and GLSL texture binding bugs.
        // TODO: add actual tests
        Log::common()->printf("   Detected slowShadowMap bug\n\n");
        Log::common()->printf("   Detected GLSL Texture Binding bug\n\n");
        bugCount += 2;
    }

    if (GLCaps::hasBug_mipmapGeneration()) {
        ++bugCount;
        Log::common()->printf("   Detected mipmapGeneration bug\n\n");
    } 
    
}


void App::computeFeatureRating() {

    if ((glslShader != "None") &&
        GLCaps::supports("GL_ARB_shadow") &&
        GLCaps::supports("GL_EXT_framebuffer_object") &&
        GLCaps::supports("GL_EXT_stencil_wrap")) {

        // NV47 w/ good drivers
        featureRating = 60;

    } else if ((glslShader != "None") &&
        GLCaps::supports("GL_ARB_shadow") &&
        GLCaps::supports("GL_EXT_stencil_wrap")) {

        // R800 w/ good drivers
        featureRating = 50;

    } else if ((asmShader != "None") &&
        GLCaps::supports("GL_ARB_shadow") &&
        GLCaps::supports("GL_EXT_stencil_wrap")) {

        // NV30
        featureRating = 40;

    } else if ((asmShader != "None") &&
        GLCaps::supports("GL_EXT_stencil_wrap")) {

        featureRating = 35;

    } else if (asmShader != "None") {

        // PS 2.0 card
        featureRating = 30;

    } else if ((combineShader != "None") &&
        GLCaps::supports_GL_ARB_multitexture() &&
        GLCaps::supports_GL_ARB_texture_cube_map()) {

        // PS 1.4 card
        featureRating = 20;

    } else if (
        GLCaps::supports_GL_ARB_multitexture() &&
        GLCaps::supports_GL_ARB_texture_cube_map()) {

        featureRating = 15;

    } else if (GLCaps::supports_GL_ARB_texture_cube_map()) {

        featureRating = 14;

    } else {

        featureRating = 10;
    }
}

App::App(const GAppSettings& settings) : GApp(settings) {

    window()->setCaption(format("gfx-meter %03.1f", gfxMeterVersion));

#   ifndef FAST
        showSplashScreen();
#   endif

    if (reportFont.isNull()) {
        reportFont = GFont::fromFile(NULL, dataDir + "arial.fnt");
    }

    applet = new Report(this);
}


App::~App() {
    delete applet;
}


int main(int argc, char** argv) {
    GAppSettings settings;
    
    settings.useNetwork = false;
    settings.window.fsaaSamples = 4;
    settings.dataDir = "./";
    settings.window.defaultIconFilename = "g3d.ico";

    if (!fileExists(settings.window.defaultIconFilename)) {
        // We are probably running in the debugger and launched from the wrong directory
#ifdef G3D_WIN32
        _chdir("build/install");
#else
        chdir("build/install");
#endif
    }

    if (!fileExists(settings.window.defaultIconFilename)) {
        msgBox("gfxmeter was run from the wrong directory and can't find its data files.", "Error");
        return -1;
    }

    App(settings).run();
    return 0;
}
