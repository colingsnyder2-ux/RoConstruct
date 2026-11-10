# Original lighting prerequisite

`roc rebuild 2008-06 module p2-lighting --no-notify` compiles the recovered
007aacc0 preset and007a9d30 Ogre light setup with genuine G3D/Ogre types.
P2LightingTest needs no GL context, render window or input asset. It checks
ambient, sun/fill point lights, cast-shadow flags, bounds-derived placement,
brightness clamps, tint, specular multipliers and removal of surplus sun lights.
The original leaves rbxfl when the sun count differs from one; the test retains
that behavior instead of inventing cleanup.

The native field writer004dab50 copies Lighting+270..2d0 to Scene+338..398.
Constructor005e1a40 proves both zero tints, brightness1, ambient(.5,.5,.5),
main diffuse/specular and fill diffuse/scale(1,1,1), fill specular(0,0,0).
PlayerLighting::Settings is the real contiguous value group, not a padded
declaration of either enclosing object. Compile assertions check its size64
and relative offsets (hexadecimal). The older donor Lighting header lacks these
extra fields; default recovery does not claim its complete native layout.

Important source-analog correction: native007aa1a6 computes a stack address,
007aa1b0 computes Scene+36c and007aa1c0 compares those addresses. It does not
test whether specular RGB equals zero. The mined source's comparison against
default Color3 concealed this distinction. The extracted helper retains the
pointer comparison; distinct live input/local objects cannot alias. Zero main
specular therefore multiplies by zero. An initial normalization expectation
failed test8; the binary disproved that expectation. No new exact credit claimed.

The preset creates a sun from skyParameters.lightDirection and lightColor*.9,
copies top/bottom ambient, and uses the real G3D Lighting/GLight providers.
Environment-map assignment from a nonnull sky remains outside this block path.
The helper takes actual owner bounds as a parameter, without adopting the
mined fake BoundsOwner/RenderScene padding. Source/target hashes and full
disassembly live under work/2008-06/p2-flat-producer/native-lighting-*.

This verifies light state, not rendered player pixels. Next connect native
material/proxy/backend and these lights to the preserved isolated player.
Full original View/RenderScene ownership and later roadmap gates remain open.
