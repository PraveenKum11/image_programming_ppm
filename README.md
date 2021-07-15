# Image Programming Using PPM(portable pixmap) Image Format

In this project I have tried to create:
1. Random Pattern which are fun to look at and
2. Image filters (RGB filter, blur filter, threshold and inverted threshold filter)

## Results:
### Filters
![Result Preview](https://github.com/PraveenKum11/cpp_projects/blob/main/misc/itachi_out.png)
![Result Preview](https://github.com/PraveenKum11/cpp_projects/blob/main/misc/mikasa.png)

### Patterns
![Result Preview](https://github.com/PraveenKum11/cpp_projects/blob/main/misc/pattern.png)

## Installation:
1. `git clone` the project.
2. `cd image_programming_ppm`
3. You will need to add your input files on which you want to apply filters in the input directory. For patterns you don't need any preperations.
4. After that add the name of the input and output files in the main.cpp file, I have left some test input files in the input directory if you don't want to make your own input file.If you want to create your own ppm files see below.
5. Compile the files with `g++ main.cpp Filter.cpp Patterns.cpp`
6. Then run the output file with `./a.out`
7. You will get filter applied images in the output directory and the generated patterns in the data directory.

**To create your own ppm (p3) images:**
You can use [ImageMagick](https://imagemagick.org/script/download.php)
or use any online website.

Commands for Linux Users (ImageMagick):
1. First resize the image to lower resolution else the ppm image will be huge (>300mb) `magick file-you-want-convert.jpg -resize 500x500 output.jpg`
2. Then convert into ppm using `convert input-image.jpg -compress none final-output.ppm`
3. Now the Image is ready to be used.

**Same commands can be used for windows and mac.(I haven't tried it)**

## Resources
* [Ferrabacus](https://youtu.be/HGHbcRscFsg?list=PLwUV0WxQzx_JG2g8_Od5-T_HFTcqGYN4d) - YouTube
* [Wikipedia](https://en.wikipedia.org/wiki/Netpbm#File_formats) - PPM
