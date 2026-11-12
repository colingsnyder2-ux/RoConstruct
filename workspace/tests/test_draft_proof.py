import unittest

from roc.draft_proof import ACTIVATION_CHECKS, BASE_CHECKS, SOURCE_CHECKS, rank_receipts, validate_receipt, validate_adapter

HASH_A = "a" * 64
HASH_B = "b" * 64


def receipt(**updates):
    value = {
        "schema": 1,
        "kind": "independent-draft-proof",
        "candidate_sha256": HASH_A,
        "input_key": "c" * 64,
        "client": "2008-06",
        "verifier_sha256": HASH_B,
        "before_methods": ["old"],
        "after_methods": ["old", "new"],
        "checks": {name: True for name in BASE_CHECKS},
    }
    value.update(updates)
    return value


EXPECTED = {"candidate_sha256": HASH_A, "input_key": "c" * 64, "client": "2008-06", "verifier_sha256": HASH_B}


class DraftProofTests(unittest.TestCase):
    def test_reviewed_improvement_accepts_inferred_names_and_partial_class(self):
        value = receipt(kind='reviewed-source-improvement', inactive=True,
                        checks={name: True for name in SOURCE_CHECKS}, reviewer='coordinator',
                        rationale='Adds missing useful method while preserving existing implementation',
                        scope='Inactive source method only', inferences=['Method name inferred'],
                        open_questions=['Unrelated class virtual identities remain unknown'])
        self.assertEqual(validate_adapter('reviewed-inactive-methods-v1', value, EXPECTED), [])
        self.assertTrue(validate_receipt(value, EXPECTED))
        self.assertTrue(validate_adapter('reviewed-inactive-methods-v1', value, dict(EXPECTED, activate=True)))
        value['checks']['compile'] = 1
        self.assertTrue(validate_adapter('reviewed-inactive-methods-v1', value, EXPECTED))

    def test_accepts_fully_bound_gain(self):
        self.assertEqual(validate_receipt(receipt(), EXPECTED), [])

    def test_rejects_identity_or_check_tampering(self):
        value = receipt(candidate_sha256="other")
        value["checks"]["abi"] = 1
        blockers = validate_receipt(value, EXPECTED)
        self.assertTrue(any("candidate_sha256" in item for item in blockers))
        self.assertTrue(any("abi" in item for item in blockers))

    def test_rejects_gainless_loss_and_bad_method_ids(self):
        value = receipt(before_methods=["old"], after_methods=["different"])
        blockers = validate_receipt(value, EXPECTED)
        self.assertTrue(any("losses" in item for item in blockers))
        value["after_methods"] = [None]
        self.assertTrue(any("stable method IDs" in item for item in validate_receipt(value, EXPECTED)))

    def test_activation_requires_extra_checks(self):
        expected = dict(EXPECTED, activate=True)
        self.assertTrue(any("provider_selection" in item for item in validate_receipt(receipt(), expected)))
        value = receipt(checks={**receipt()["checks"], **{name: True for name in ACTIVATION_CHECKS}})
        self.assertEqual(validate_receipt(value, expected), [])

    def test_rejects_nonfinite_numbers_and_truthy_flags(self):
        value = receipt()
        value["evidence"] = float("nan")
        value["checks"]["compile"] = "yes"
        blockers = validate_receipt(value, EXPECTED)
        self.assertTrue(any("non-finite" in item for item in blockers))
        self.assertTrue(any("compile" in item for item in blockers))

    def test_requires_complete_identity_and_valid_hashes(self):
        self.assertTrue(any("missing" in item for item in validate_receipt(receipt(), {})))
        self.assertTrue(any("64 lowercase hex" in item for item in validate_receipt(receipt(), dict(EXPECTED, candidate_sha256="short"))))

    def test_rejects_boolean_schema_and_non_json_objects(self):
        value = receipt(schema=True)
        self.assertTrue(any("schema" in item for item in validate_receipt(value, EXPECTED)))
        value = receipt()
        value["metadata"] = object()
        self.assertTrue(any("non-finite" in item for item in validate_receipt(value, EXPECTED)))

    def test_activation_flag_must_be_boolean(self):
        self.assertTrue(any("activate" in item for item in validate_receipt(receipt(), dict(EXPECTED, activate=1))))

    def test_all_identity_hashes_are_validated_and_finite_float_is_json_data(self):
        value = receipt(duration_seconds=1.25)
        self.assertEqual(validate_receipt(value, EXPECTED), [])
        self.assertTrue(any("input_key" in item for item in validate_receipt(value, dict(EXPECTED, input_key="short"))))

    def test_ranks_eligible_first_and_deterministically(self):
        bad = receipt(checks={"compile": False})
        good = receipt(candidate_sha256="c" * 64)
        self.assertEqual(rank_receipts([bad, good], dict(EXPECTED, candidate_sha256="c" * 64))[0], good)


if __name__ == "__main__":
    unittest.main()
