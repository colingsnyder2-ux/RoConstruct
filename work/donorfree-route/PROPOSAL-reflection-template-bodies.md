# Header proposal: reflection template members missing from native sources (2026-11-22)

Source: donor-free all-native trial (`rebuild/2008-06/out/donorfree/report-all-native.json`). These members are
referenced (vtables) but defined by no native unit. In 2008 they are template bodies in `reflection/*.h`, implicitly
instantiated; adding the bodies to the header closes every type at once. Owner of `reflection/property.h` decides.
Total: 440 symbols.

## TypedPropertyDescriptor (219 symbols)
- `getStringValue`: 35 types, e.g. PAVHole, PAVInstance, PAVModelInstance, PAVPartInstance
- `readValue`: 34 types, e.g. H, PAVHole, PAVInstance, PAVModelInstance
- `writeValue`: 33 types, e.g. PAVHole, PAVInstance, PAVModelInstance, PAVPartInstance
- `setStringValue`: 33 types, e.g. M, PAVHole, PAVInstance, PAVModelInstance
- `isWriteOnly`: 28 types, e.g. PAVHole, PAVInstance, PAVModelInstance, PAVPartInstance
- `getVariant`: 28 types, e.g. PAVHole, PAVInstance, PAVModelInstance, PAVPartInstance
- `setVariant`: 28 types, e.g. PAVHole, PAVInstance, PAVModelInstance, PAVPartInstance

## RefPropDescriptor (76 symbols)
- `isReadOnly`: 12 types, e.g. VAutoJoint, VCamera, VHumanoid, VInstance
- `equalValues`: 12 types, e.g. VAutoJoint, VCamera, VHumanoid, VInstance
- `writeValue`: 12 types, e.g. VAutoJoint, VCamera, VHumanoid, VInstance
- `readValue`: 11 types, e.g. VAutoJoint, VCamera, VHumanoid, VModelInstance
- `getRefValue`: 11 types, e.g. VAutoJoint, VCamera, VHumanoid, VModelInstance
- `assignIDREF`: 11 types, e.g. VAutoJoint, VCamera, VHumanoid, VModelInstance
- `setRefValue`: 7 types, e.g. VAutoJoint, VObjectValue, VPlayer@Network, VPlayers@Network

## SurfaceEnumPropDescriptor (130 symbols)
- `equalValues`: 12 types, e.g. $00W4InputType@Controller, $00W4SurfaceType, $01W4InputType@Controller, $01W4SurfaceType
- `hasStringValue`: 12 types, e.g. $00W4InputType@Controller, $00W4SurfaceType, $01W4InputType@Controller, $01W4SurfaceType
- `getStringValue`: 12 types, e.g. $00W4InputType@Controller, $00W4SurfaceType, $01W4InputType@Controller, $01W4SurfaceType
- `setStringValue`: 12 types, e.g. $00W4InputType@Controller, $00W4SurfaceType, $01W4InputType@Controller, $01W4SurfaceType
- `writeValue`: 12 types, e.g. $00W4InputType@Controller, $00W4SurfaceType, $01W4InputType@Controller, $01W4SurfaceType
- `readValue`: 12 types, e.g. $00W4InputType@Controller, $00W4SurfaceType, $01W4InputType@Controller, $01W4SurfaceType
- `getIndexValue`: 12 types, e.g. $00W4InputType@Controller, $00W4SurfaceType, $01W4InputType@Controller, $01W4SurfaceType
- `getEnumValue`: 12 types, e.g. $00W4InputType@Controller, $00W4SurfaceType, $01W4InputType@Controller, $01W4SurfaceType
- `setEnumValue`: 12 types, e.g. $00W4InputType@Controller, $00W4SurfaceType, $01W4InputType@Controller, $01W4SurfaceType
- `setVariant`: 12 types, e.g. $00W4InputType@Controller, $00W4SurfaceType, $01W4InputType@Controller, $01W4SurfaceType
- `setIndexValue`: 10 types, e.g. $01W4InputType@Controller, $01W4SurfaceType, $02W4InputType@Controller, $02W4SurfaceType

## EnumPropDescriptor (15 symbols)
- `hasStringValue`: 15 types, e.g. VCRenderSettings@@W4AASamples@1@, VCRenderSettings@@W4AntialiasingMode@1@, VCRenderSettings@@W4BevelMode@1@, VCRenderSettings@@W4FrameRateManagerMode@1@
