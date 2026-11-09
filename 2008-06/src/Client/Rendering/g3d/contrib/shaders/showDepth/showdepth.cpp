class ShowDepth {
private:

    ShaderRef           shader;

    TextureRef          depth;

    void allocateTextures(const Rect2D& screenRect) {
        if (depth.isNull() || 
            (depth->vector2Bounds() != screenRect.wh())) {
        
            Texture::Parameters parameters;
            parameters.autoMipMap = false;
            parameters.maxAnisotropy = 1;
            parameters.wrapMode = Texture::CLAMP;
            parameters.interpolateMode = Texture::NO_INTERPOLATION;

            depth = Texture::createEmpty("Depth Buffer", screenRect.width(), screenRect.height(),
                TextureFormat::depth(), Texture::DIM_2D_NPOT, parameters);

            shader->args.set("depth", depth);
        }
    }

public:

    ShowDepth() {
        shader = Shader::fromStrings("", 
            STR(
                uniform sampler2D depth;

                void main(void) {
	                float d = texture2D(depth, gl_TexCoord[0].xy);
	                d = d * d * d * d;
	                gl_FragColor.rgba = vec4(d,d,d,1.0);
                }
                ));
    }

    void apply(RenderDevice* rd) {
        rd->push2D();
            Rect2D screenRect = rd->getViewport();
            allocateTextures(screenRect);
            
            // Read back the depth buffer
            depth->copyFromScreen(screenRect, true);

            rd->setShader(shader);
            Draw::rect2D(screenRect, rd);
        rd->pop2D();
    }

};