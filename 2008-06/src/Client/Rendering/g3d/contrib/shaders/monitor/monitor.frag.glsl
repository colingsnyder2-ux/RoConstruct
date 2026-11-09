/**
  Makes the rendered object appear to be on a video monitor.  Great for HUD
  effects.  I recommend rendering the entire HUD to a rect2D texture (with 
  alpha channel) and then rendering over the 3D view with this pixel shader.
*/

        
        // The HUD texture
        uniform sampler2DRect texture;

        // lines.tga
        uniform sampler2DRect noiseTexture;
        uniform sampler2D palette;
        uniform float screenHeight;
        uniform float shift;

        void main(void) {
            vec2 texCoord = vec2(gl_TexCoord[0].s, screenHeight - gl_TexCoord[0].t);

            vec3 color = texture2DRect(texture, texCoord).rgb;
            // Reduce to black and white
            float c = (color.r + color.g + color.b) / 3.0;

            float n = 
                0.9 +
                0.3 * (texture2DRect(noiseTexture, vec2(mod(gl_TexCoord[0].s, 128),
                                     mod(gl_TexCoord[0].t, 128))).r - 0.5);

            gl_FragColor.rgb = texture2D(palette, vec2(c * n, 0));
            gl_FragColor.a = texture2DRect(texture, texCoord).a * 0.6;
        }