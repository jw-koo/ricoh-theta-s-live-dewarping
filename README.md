# ricoh-theta-s-live-dewarping
 - 2 Fisheyes to Equirectangular

# Dependencies
 - openCV
 - openMP(option)
 
# Test
 - Tested on jetson TX1 board (Ubuntu 16.04)
 - /dev/video1 (ricoh theta s live streaming mode)
 - 14 ~ 15.85fps (ricoh theta's maximum frame rate is 15.85fps)
 - 1280 x 720

## Usage

    make
    ./program

# Additional Info
 - The algorithm has a performance of 60 fps but is 15.85 fps due to limitations of live streaming mode.

# LICENSE
  - MIT
