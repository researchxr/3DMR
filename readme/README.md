<h1 align="center">
  <br>
  <a href="http://www.amitmerchant.com/electron-markdownify"><img src="https://raw.githubusercontent.com/amitmerchant1990/electron-markdownify/master/app/img/markdownify.png" alt="Markdownify" width="200"></a>
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
  <a href="#pull-request-steps">Pull Request Steps</a> •
  <a href="#how-to-ues">How To Use</a> •
  <a href="#credits">Credits</a> •
  <a href="#license">License</a>
</p>


![screenshot](https://raw.githubusercontent.com/amitmerchant1990/electron-markdownify/master/app/img/markdownify.gif)



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


## 🔧Pull Request Steps

TOAST UI products are open source, so you can create a pull request(PR) after you fix issues. Run npm scripts and develop yourself with the following process.

### Setup

Fork `main` branch into your personal repository. Clone it to local computer. Install node modules. Before starting development, you should check if there are any errors.

```sh
$ git clone https://github.com/{your-personal-repo}/tui.editor.git
$ npm install
$ npm run build toastmark
$ npm run test editor
```

> TOAST UI Editor uses [npm workspace](https://docs.npmjs.com/cli/v7/using-npm/workspaces/), so you need to set the environment based on [npm7](https://github.blog/2021-02-02-npm-7-is-now-generally-available/). If subversion is used, dependencies must be installed by moving direct paths per package.

### Develop

You can see your code reflected as soon as you save the code by running a server. Don't miss adding test cases and then make green rights.

#### Run snowpack-dev-server

[snowpack](https://www.snowpack.dev/) allows you to run a development server without bundling.

``` sh
$ npm run serve editor
```

#### Run webpack-dev-server

If testing of legacy browsers is required, the development server can still be run using a [webpack](https://webpack.js.org/).

``` sh
$ npm run serve:ie editor
```

#### Run test

``` sh
$ npm test editor
```

### Pull Request

Before uploading your PR, run test one last time to check if there are any errors. If it has no errors, commit and then push it!

For more information on PR's steps, please see links in the Contributing section.

## 🚀How To Use

To clone and run this application, you'll need [Git](https://git-scm.com) and [Node.js](https://nodejs.org/en/download/) (which comes with [npm](http://npmjs.com)) installed on your computer. From your command line:

```bash
# Clone this repository
$ git clone https://github.com/amitmerchant1990/electron-markdownify

# Go into the repository
$ cd electron-markdownify

# Install dependencies
$ npm install

# Run the app
$ npm start
```

## 🌏Credits

This software uses the following open source packages:

- [VTK](https://vtk.org/)
- [Qt designer](https://www.pythonguis.com/installation/install-qt-designer-standalone/)
- [Microsoft Visual Studio](https://visualstudio.microsoft.com/zh-hans/#vs-section)

## 📜 License

This software is licensed under the [MIT](https://github.com/nhn/tui.editor/blob/master/LICENSE) © [NHN Cloud](https://github.com/nhn).
