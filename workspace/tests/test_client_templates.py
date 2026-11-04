import hashlib

from roc import libs


def test_generated_units_preserve_source_reference_hashes_and_vendor_scope():
    units = libs.client_template_units()
    assert units
    for filename, source in units.items():
        # RTTI units are content-named; hand-named units (roc_ndebug_*) are referenced by stored sources.
        if filename.startswith("roc_rtti_"):
            assert filename == "roc_rtti_" + hashlib.sha256(source.encode()).hexdigest()[:16] + ".cpp"
        else:
            assert filename.startswith("roc_ndebug_")
        assert "template class boost::" in source
        assert "RBX::" not in source and "G3D::" not in source
    units.clear()
    assert libs.client_template_units()
    assert libs.RECIPES["templates-2008-06"]["generate"]() == libs.client_template_units()
