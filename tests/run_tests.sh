#!/bin/bash

for file in tests/simplelang_examples/*.simple; do
    base=$(basename "$file" .simple)
    ./compiler < "$file" > "tests/actual_output/$base.asm"
    diff "tests/actual_output/$base.asm" "tests/expected_output/$base.asm" && echo "$base: PASS" || echo "$base: FAIL"
done
