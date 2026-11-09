/**
 @file BumpMapViewer/bump.frag
 @maintainer Morgan McGuire, matrix@graphics3d.com
 @created 2004-06-26
 @edited  2004-06-26
 */

/** Reflectivity of the surface */
uniform float reflectivity;

/** Specularity of the surface */
uniform float specularity;

/** Color texture (with alpha) */
uniform sampler2D texture;

uniform vec3 wsEyePos;

/** xyz = normal, w = bump height */
uniform sampler2D normalBumpMap;

/** Multiplier for bump map.  Typically on the range [0, 0.05]
  This increases with texture scale and bump height. */
uniform float bumpScale;

uniform samplerCube environmentMap;

/** Assumed to be normalized.  Position of the light */
uniform vec4 wsLightPos;

varying vec3 wsPosition;
varying vec3 _tsE;
varying vec2 texCoord;
varying vec4 tan_X, tan_Y, tan_Z, tan_W;

void main(void) {

    // Convert bumps to a world space distance
    vec4 NB = texture2D(normalBumpMap, texCoord);
    float  bump = (NB.w - 0.5) * bumpScale;

    // We should divide by tsE.z, but that creates texture swim at shallow angles,
    // so we use Terry Walsh's solution and just normalize.
	vec3 tsE = normalize(_tsE);

    // Offset the texture coord.  Note that texture coordinates are inverted (in the y direction)
	// from TBN space, so we must flip the y-axis.

    vec2 offsetCoord = texCoord.xy + vec2(tsE.x, -tsE.y) * bump;

    vec4 surfColor = texture2D(texture, offsetCoord);

	// note that the columns might be slightly not orthogonal due to interpolation
	mat4 tangentToWorld = mat4(tan_X, tan_Y, tan_Z, tan_W);
	
    vec3 wsE = normalize(wsEyePos - wsPosition);

	vec3 wsL = normalize(wsLightPos.xyz - wsPosition.xyz * wsLightPos.w);

    // Take the normal map values back to (-1, 1) range to compute a tangent space normal
    vec3 tsN = ((texture2D(normalBumpMap, offsetCoord).xyz - vec3(0.5, 0.5, 0.5)) * 2.0);

	// Take the normal to world space 
	vec3 wsN = (tangentToWorld * vec4(tsN, 0.0)).xyz;

	// Reflection vector
	vec3 wsR = (wsN * 2.0 * dot(wsN, wsE)) - wsE;
	vec3 reflected  = textureCube(environmentMap, wsR).rgb;

    vec3 lightColor = vec3(0.9, 0.9, 0.75);
    vec3 ambient    = vec3(0.1, 0.1, 0.25);

    vec3 diffuse  = lightColor * max(dot(wsN, wsL), 0.0);
	vec3 specular = lightColor * pow(max(dot(wsL, wsR), 0.0), 4.0);

    gl_FragColor.rgb =
	        (diffuse + ambient) * surfColor.rgb +
			specular * specularity +
			reflected * reflectivity;

	gl_FragColor.a   = surfColor.a;
}
