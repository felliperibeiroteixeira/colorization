# AI Image Colorization Prototype

This is a prototype based on OpenCV's colorization code, designed for the automatic colorization of black-and-white images and photographs using artificial intelligence.

The system uses deep convolutional neural network (Deep CNN) models developed by Richard Zhang and collaborators as part of the work:

"Colorful Image Colorization" – ECCV 2016 (Zhang et al.).

The code preprocesses the image, performs inference using a pre-trained network, and returns the colorized version of the original image.

---

## Academic Reference

> **"Colorful Image Colorization"**
> Richard Zhang, Phillip Isola, Alexei A. Efros – *ECCV 2016*
> [Official project page](https://richzhang.github.io/colorization/)

The original code with the official model addresses are in the official [OpenCV](https://opencv.org/) repository at `/opencv/opencv/blob/4.x/samples/dnn/colorization`.

---

## Dependencies

- [OpenCV](https://opencv.org/)
- [CMake](https://cmake.org/)
- [GTest](https://google.github.io/googletest/)
