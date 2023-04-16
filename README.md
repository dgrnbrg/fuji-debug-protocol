There's 3 images:

- The schematic
- The front side of the board (with the 3 touchpads)
- The detail of the plug w/ pins labeled

One of the touch buttons doesn't work. Otherwise, you have 2 buttons and an RGB LED for local IO with humans.

The extra GPIO are also available on a header. There are other various test-points and defaulted jumpers, but it looks like I forgot to expose power/ground in this v1, so you'll need to tap them from the UEXT connector on the esp-poe-iso if you want 3.3v, and 5V would require tapping an existing pin.
