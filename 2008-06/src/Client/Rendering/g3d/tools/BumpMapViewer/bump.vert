/**
 @file BumpMapViewer/bump.vert
 @maintainer Morgan McGuire, matrix@graphics3d.com
 @created 2004-06-26
 @edited  2004-06-26
 */

/** Must be an RT matrix; no scale factor 
    (thus for the upper 3x3, transpose(inverse(M)) == M
	 and vectors and normals can be transformed using the
	 same matrix)*/
uniform mat4 objectToWorld;
uniform vec3 wsEyePos;
uniform vec3 osEyePos;

/** Texture coordinate */
varying vec2 texCoord;

/** World space point */
varying vec3 wsPosition;

/** Vector to the eye in tangent space (needed for parallax) */
varying vec3 _tsE;

/** Tangent space to world space.
    Note that this will be linearly interpolated across the polygon.

	NVIDIA drivers do not properly interpolate mat4, so we must pass
	the columns along a separate vectors. */
varying vec4 tan_X, tan_Y, tan_Z, tan_W;

void main(void) {
	texCoord	= gl_MultiTexCoord0.st;

	vec3 T = gl_MultiTexCoord1.xyz;
	vec3 B = gl_MultiTexCoord2.xyz;
	vec3 N = gl_Normal;

	// Compute the columns of the tangent space to world space matrix
	tan_X = objectToWorld * vec4(T, 0);
	tan_Y = objectToWorld * vec4(B, 0);
	tan_Z = objectToWorld * vec4(N, 0);
	tan_W = objectToWorld * gl_Vertex;

	wsPosition      = tan_W.xyz;

	// Compute the tangent space eye vector
    mat3 objectToTangent = transpose(mat3(T, B, N));
	vec3 osPosition = gl_Vertex.xyz;
	_tsE             = objectToTangent * (osEyePos - osPosition);

    gl_Position     = ftransform();
}

