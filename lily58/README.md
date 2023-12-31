# My Custom Lily58 Build

## Files

Coming soon

## Firmware

### Personalizing

I've flashed the boards to come with Vial which should allow you a good amount of freedom in customizing the keymaps. Download and install the Vial GUI [here](https://get.vial.today/).

Feel free to use the contents of `vial-firmware` as a base and modifying it with whichever QMK features you'd like. See the [QMK documentation](https://docs.qmk.fm/#/) on firmware features and on adding these features to your keyboard. 

### Flashing Firmware

DISCLAIMER: As Vial is a work in progress, I expect that this guide may fall out of date. In which case, please follow the latest Vial documentation on setting up a keymap.

1. Follow step 1 of Vial's [Porting to Vial guide](https://get.vial.today/docs/porting-to-vial.html#1-prepare-your-build-environment) to prepare your build environment.

2. Navigate to the newly cloned `vial-qmk` repo if not already in the repo directory.

3. Copy the contents of `vial-firmware` to `vial-qmk/keyboards/lily58/rev1/keymaps/vial/`

4. Flashing the firmware for each side of the board:
    1. Note to follow the prompt to hit the reset switch of the board located on top-inner side of the board below the TRRS connectors.
    2. Run `make lily58:vial:avrdude-split-left` to flash the left side. 
    3. Run `make lily58:vial:avrdude-split-right` to flash the right side.

5. Have fun figuring out what layout suits you.
