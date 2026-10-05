# Third-party runtime dependencies

RoConstruct may use open-source runtime pieces for an offline sandbox. Keep
source, license, version, and SHA-256 recorded here. Build DLLs locally; do
not copy unknown `rg*.dll` or client-extracted binaries into this folder.

Planned runtime pieces:

- Ogre3D — renderer compatibility layer; use a version whose license/source
  matches the target sandbox.
- SDL2 — window/input layer.
- zlib — compression.
- OpenAL Soft — optional audio.

No third-party binaries are currently bundled. `package.py` reports missing
dependencies instead of silently shipping unverified DLLs.
