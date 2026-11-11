import unittest

from roc.native_promotion import plan


def provider(symbol, address, identity):
    return {"symbol": symbol, "address": address, "identity": identity}


def family(name, status="inactive_exact", requires=(), providers=(), needs=(), blockers=()):
    return {"name": name, "status": status, "requires": list(requires),
            "providers": list(providers), "needs": list(needs), "blockers": list(blockers)}


class NativePromotionTests(unittest.TestCase):
    def test_unique_native_replaces_baseline_and_identical_aliases_coalesce(self):
        rows = [family("Zulu", providers=[provider("?P", "0040", "body-a")]),
                family("Alpha", providers=[provider("?P", "0040", "body-a")]),
                family("UseP", requires=["?P"])]
        result = plan(rows, {"?P": {"address": "old", "identity": "old", "origin": "original"}})
        self.assertEqual(result["selected_providers"]["?P"]["owner"], "Alpha")
        self.assertEqual(result["selected_providers"]["?P"]["aliases"], ["Alpha", "Zulu"])
        self.assertEqual(result["retained_baseline"], [])
        use_batch = next(batch for batch in result["batches"] if batch["families"] == ["UseP"])
        self.assertTrue(use_batch["ready_for_preflight"])
        self.assertIn(["Alpha"], use_batch["depends_on"])

    def test_conflicting_native_candidates_keep_baseline_and_block_provider_and_user(self):
        rows = [family("One", providers=[provider("?P", "0040", "body-a")]),
                family("Two", providers=[provider("?P", "0041", "body-b")]),
                family("UseP", requires=["?P"])]
        result = plan(rows, {"?P": {"address": "orig", "identity": "original"}})
        self.assertEqual(result["selected_providers"]["?P"]["origin"], "baseline")
        self.assertEqual(result["retained_baseline"], ["?P"])
        self.assertEqual(len(result["conflicts"]), 1)
        for batch in result["batches"]:
            self.assertFalse(batch["ready_for_preflight"])

    def test_baseline_fallback_and_missing_symbol(self):
        result = plan([family("Use", requires=["?Old", "?Missing"])],
                      {"?Old": {"address": "original", "identity": "id"}})
        self.assertEqual(result["retained_baseline"], ["?Old"])
        self.assertEqual(result["selected_providers"]["?Old"]["owner"], "original")
        self.assertIn("missing provider: ?Missing", result["batches"][0]["blockers"])

    def test_nonexact_provider_cannot_replace_baseline(self):
        rows = [family("Draft", "compiled", providers=[provider("?P", "0040", "body")]),
                family("UseP", requires=["?P"])]
        result = plan(rows, {"?P": {"address": "original", "identity": "old"}})
        self.assertEqual(result["selected_providers"]["?P"]["origin"], "baseline")
        use_batch = next(batch for batch in result["batches"] if batch["families"] == ["UseP"])
        self.assertTrue(use_batch["ready_for_preflight"])

    def test_nonexact_conflicting_candidate_blocks_exact_provider(self):
        rows = [family("Exact", providers=[provider("?P", "0040", "body-a")]),
                family("Draft", "compiled", providers=[provider("?P", "0041", "body-b")]),
                family("UseP", requires=["?P"])]
        result = plan(rows, {"?P": {"address": "original", "identity": "old"}})
        self.assertEqual(result["selected_providers"]["?P"]["origin"], "baseline")
        self.assertEqual(len(result["conflicts"]), 1)
        self.assertTrue(all(not batch["ready_for_preflight"] for batch in result["batches"]))

    def test_failed_dependency_blocks_transitively(self):
        rows = [family("Base", "failed"), family("Middle", needs=["Base"]),
                family("Top", needs=["Middle"])]
        result = plan(rows)
        by_family = {tuple(batch["families"]): batch for batch in result["batches"]}
        self.assertFalse(by_family[("Base",)]["ready_for_preflight"])
        self.assertFalse(by_family[("Middle",)]["ready_for_preflight"])
        self.assertFalse(by_family[("Top",)]["ready_for_preflight"])
        self.assertTrue(any("dependency batch [Middle] blocked:" in x for x in by_family[("Top",)]["blockers"]))
        self.assertTrue(any("status is not inactive_exact" in x for x in by_family[("Top",)]["blockers"]))

    def test_cycle_is_one_scc_batch_and_self_dependency_is_allowed(self):
        rows = [family("A", needs=["B"]), family("B", needs=["A", "B"])]
        result = plan(rows)
        self.assertEqual(len(result["batches"]), 1)
        self.assertEqual(result["batches"][0]["families"], ["A", "B"])
        self.assertTrue(result["batches"][0]["ready_for_preflight"])

    def test_missing_family_dependency_blocks(self):
        result = plan([family("A", needs=["Unknown"])])
        self.assertIn("missing family dependency: Unknown", result["batches"][0]["blockers"])

    def test_order_is_stable_for_input_permutations(self):
        rows = [family("C", needs=["A"]), family("B"), family("A")]
        first = plan(rows)
        second = plan(list(reversed(rows)))
        self.assertEqual(first["batches"], second["batches"])


if __name__ == "__main__":
    unittest.main()
