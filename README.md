<h1 align="center">
  <br>
  3DMR
  <br>
</h1>

<h4 align="center">VTK-based Medical 3D Image Reconstruction System</h4>

<p align="center">
    <img src="https://img.shields.io/badge/npm-v1.0.0-blue.svg?style=plastic" alt="Gitter">
    <img src="https://img.shields.io/badge/license-MIT-brightgreen.svg?style=plastic" alt="Gitter">
    <img src="https://img.shields.io/badge/</>-C++-red.svg?style=plastic" alt="Gitter">
</p>

<p align="center">
  <a href="#key-features">Key Features</a> •
  <a href="#how-to-ues">How To Use</a> •
  <a href="#credits">Credits</a> •
  <a href="#license">License</a>
</p>


![screenshot](https://github.com/researchxr/3DMR/blob/main/readme/3DMR.gif)

## 🚩Key Features

* 2D Image Reading
  - Supports reading of various 2D image formats, including BMP, JPG, and DICOM formats.
* Image Information Reading and Grayscale Processing
  - For the DICOM images read, patient information can be accessed.
  - The images can be zoomed in and out, and BMP and JPG color images can be converted to grayscale.
  - For DICOM images, a slider can be used to display different grayscale value transformations.
* 2D Sequence Image Reading
  * Supports reading DICOM sequence images and extracting patient information.
  * Allows reading of sequence images page by page, with page numbers adjusted via buttons or sliders for display.  
* 3D Reconstruction Based on Sequence Images
  * For the acquired sequence images, 3D models are reconstructed using volume rendering and surface rendering methods.
  * Allows viewing and extracting the region of interest (ROI) in the reconstructed 3D model, with options to select and view the aorta and skin in different blocks.
* Volume and Surface Area Calculation of 3D Models
  * Computes the volume and surface area of the reconstructed tissue model and displays the results in a label box.

## 🔧How To Use
```shell
# Clone this repository
$ git clone https://github.com/researchxr/3DMR.git

# Unzip the file	
$ unrar x BuildFile.rar
$ 7z x data_example.7z

# Compile
$ g++ -o 3DMR main.cpp -fPIC -I/path/to/qt/include -L/path/to/qt/lib -lQt5Core -lQt5Gui -lQt5Widgets

# Run the project
$ ./Project
```



## 🌏Credits

This software uses the following open source packages:

- [VTK](https://vtk.org/)
- [Qt designer](https://www.pythonguis.com/installation/install-qt-designer-standalone/)
- [Microsoft Visual Studio](https://visualstudio.microsoft.com/zh-hans/#vs-section)


## 📜 License

This software is licensed under the [MIT](https://github.com/nhn/tui.editor/blob/master/LICENSE) © [NHN Cloud](https://github.com/nhn).
