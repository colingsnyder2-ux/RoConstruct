from benchmarks.followup_pilots import declare_asm_helpers, flag_variants, literal_repair


def test_literal_repair_reads_full_target_string():
    candidates = literal_repair('return "Run";', b'Run\0', b'GetPlayers\0padding')
    assert len(candidates) == 1
    assert '"\\107\\145\\164\\120\\154\\141\\171\\145\\162\\163"' in candidates[0][1]
    assert literal_repair('extern char Run[];', b'Run\0', b'GetPlayers\0') == []


def test_integer_array_requires_exact_baseline_and_size():
    before = b'\x01\0\0\0\x02\0\0\0'
    after = b'\x03\0\0\0\x04\0\0\0'
    source = 'unsigned int values[2] = {1, 2};'
    assert literal_repair(source, before, after)[0][1] == 'unsigned int values[2] = {3, 4};'
    assert literal_repair(source, b'\0' * 8, after) == []
    assert literal_repair(source.replace('[2]', '[3]'), before, after) == []


def test_flag_variants_preserve_unrelated_settings():
    for flags in flag_variants('/O2 /GS- /EHsc /MD /GF /Oy'):
        assert '/MD' in flags and '/GF' in flags
        assert not ('/O1' in flags and '/O2' in flags)
        assert not ('/Oy ' in flags and '/Oy-' in flags)


def test_asm_helpers_become_declarations_only():
    source = 'namespace N { inline int helper() { int x; __asm { mov eax, x } return x; } int f() { return 3; } }'
    assert declare_asm_helpers(source) == 'namespace N { inline int helper() ; int f() { return 3; } }'
