python3 scripts/gen_keymap.py  --keymap teuf | clang-format | tee keyboards/planck/rev7/keymaps/daedric/keymap.c
python3 scripts/gen_keymap.py --keymap teuf --host fr | clang-format | tee keyboards/planck/rev7/keymaps/daedricfr/keymap.c
#python3 scripts/gen_keymap.py  --keymap daedric_34 | clang-format | tee keyboards/zsa/moonlander/keymaps/daedric_34/keymap.c
#python3 scripts/gen_keymap.py  --keymap daedric --autoshift  | clang-format | tee keyboards/zsa/moonlander/keymaps/daedric/keymap.c
#python3 scripts/gen_keymap.py  | clang-format | tee keyboards/zsa/moonlander/keymaps/ergol/keymap.c
#python3 scripts/gen_keymap.py --host fr | clang-format | tee keyboards/zsa/moonlander/keymaps/ergolfr/keymap.c
