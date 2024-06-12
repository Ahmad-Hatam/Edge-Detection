This project implements a simple image edge detection algorithm using Gaussian blur and Sobel operators. The purpose of edge detection is to identify the boundaries of objects within an image, which can be useful in various image processing tasks.


The main components of the project are:

1. argparser.h: This header file defines a simple argument parser for command-line arguments. It allows the user to specify an input image file and a threshold value for edge detection.

2. image.h: This header file contains functions for reading and writing images from/to files, as well as functions for scaling images and applying a threshold to image pixels.

3. convolution.h: This header file contains functions for performing convolution operations on images. Convolution is a fundamental operation in image processing and is used here for blurring the image with a Gaussian kernel.

4. gaussian_kernel.h: This header file defines a Gaussian kernel matrix, which is used for blurring the image. The Gaussian blur helps to smooth out the image and reduce noise, making the subsequent edge detection more effective.

5. derivation.h: This header file contains functions for computing the derivatives of the blurred image in both the x and y directions using Sobel operators. These derivatives are used to compute the gradient magnitude, which highlights edges in the image.


The main program, main.c, orchestrates the entire image processing pipeline:

1. It parses command-line arguments using the argparser module to determine the input image file and threshold value.
2. It reads the input image from file using functions from the image module.
3. It blurs the image using convolution with the Gaussian kernel defined in gaussian_kernel.h.
4. It computes the derivatives of the blurred image in both x and y directions using Sobel operators.
5. It computes the gradient magnitude of the blurred image.
6. It applies a threshold to the gradient magnitude to identify edges in the image.
7. It writes the resulting images, including the blurred image, derivative images, gradient magnitude image, and edge-detected image, to output files.
   
This project provides a basic yet functional implementation of image edge detection using Gaussian blur and Sobel operators. It serves as a foundation for further exploration and experimentation in the field of image processing.
