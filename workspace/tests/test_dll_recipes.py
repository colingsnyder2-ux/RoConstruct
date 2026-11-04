from roc import libs


def test_md_recipes_get_dll_variant_that_defines_dll():
    r = libs.RECIPES["atl-9.0-dll"]
    assert "_DLL" in r["defines"].split()
    assert r["grid"] and all("/MD" in g.split() for g in r["grid"])
    assert "_DLL" not in libs.RECIPES["atl-9.0"].get("defines", "").split()  # originals unchanged
    assert "mfc-9.0-dll" not in libs.RECIPES  # static MFC rejects _DLL
    assert "openrbx-raknet-dll" not in libs.RECIPES  # already defines _DLL
