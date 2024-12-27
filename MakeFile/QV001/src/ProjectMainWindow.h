#ifndef Project_MainWindow_H
#define Project_MainWindow_H

#include <QMainWindow>
#include "ui_CTViewer.h"
#include <vtkSmartPointer.h>



class vtkImageViewer2;
class vtkRenderer;
class vtkEventQtSlotConnect;
class vtkObject;
class vtkCommand;
class vtkResliceImageViewer;
class vtkImagePlaneWidget;
class vtkDistanceWidget;
class vtkResliceImageViewerMeasurements;
class vtkImageCast;
class vtkImageMagnify;
class vtkImageConstantPad;
class vtkStripper;
class vtkDICOMImageReader;
class vtkVolumeRayCastMapper;
class vtkVolumeProperty;
class vtkContourFilter;

class ProjectMainWindow : public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT

public:
	ProjectMainWindow();
	~ProjectMainWindow();

private slots:
	//响应打开图像文件的槽函数
	void onOpenSlotDCM();//打开dcm图像
	void onOpenSlotJPG();//打开jpg图像
	void onOpenSlotBMP();//打开bmp图像
	void onOpenlistphoto();//读取序列图像

	void threeD_module();//三维建模（体绘制）
	void area_module();//面绘制

	void Zoom();//图像缩小
	void Amplify();//图像放大

	void gray();//图像灰度

	void volumeph();//体积
	//void areaph();//面积

	void On_pushButton();//按下按钮
	void Slider();//滑动序列滑块
	void Slider_grey();//滑动灰度滑块

	void lable();//标注

	//响应鼠标移动的消息，实时输出鼠标的当前位置
	void updateCoords(vtkObject* obj);

	void three_get();//提取三维立体区域
	void three_gray();//滑动立体灰度变化

	void save();//保存文档

protected:
    vtkSmartPointer< vtkResliceImageViewer > riw[3];
    vtkSmartPointer< vtkImagePlaneWidget > planeWidget[3];
    vtkSmartPointer< vtkDistanceWidget > DistanceWidget[3];
    vtkSmartPointer< vtkResliceImageViewerMeasurements > ResliceMeasurements;
	vtkSmartPointer< vtkRenderer > ren;
	vtkSmartPointer<vtkImageCast> readerImageCast;
	vtkSmartPointer<vtkImageConstantPad> rdImageCast;
	vtkSmartPointer<vtkImageViewer2> imageViewerButton;
	vtkSmartPointer<vtkDICOMImageReader>dicomImagereader;
	vtkSmartPointer<vtkVolumeRayCastMapper>volumeMapper;
	vtkSmartPointer<vtkVolumeProperty>volumeProperty;
	
private:
	vtkSmartPointer< vtkImageViewer2 >           m_pImageViewer;
	vtkSmartPointer< vtkRenderer >                   m_pRenderder;

	vtkEventQtSlotConnect* m_Connections;
	vtkStripper* skinStripper;
};

#endif
