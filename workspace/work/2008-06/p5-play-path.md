# P5 standalone play path

With staged local Content and character assets, no-argument harness launch opens
`Places/p5-playable.rbxl`, creates the local character, starts play, and attaches
the DataModel camera and existing skybox. `--play <file>` opens an explicit XML
place; gzip-compressed `.rbxl.gz` is decoded locally. `--demo` retains the red
studded block demo. The place is authored for this rebuild: touching its red
obstacle moves a yellow block via Lua. It is not an original Roblox place.

The entry point remains P2RecoveredPlayer's harness, and its camera, input,
character and physics paths include documented donor/reconstructed pieces. The
original executable bootstrap, original-client comparison and P5 parity remain
open. Local original assets and user place contents are not committed.
