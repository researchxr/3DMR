#include "ProjectMainWindow.h"
#include <QFileDialog>
#include <QDir>
#include <QMainWindow>
#include <QVTKWidget.h>

#include "vtkActor.h" 

#include "vtkBoundedPlanePointPlacer.h"
#include <vtkBMPReader.h>
#include "vtkBoxWidget.h"

#include "vtkCamera.h" 
#include <vtkCommand.h>
#include "vtkCellPicker.h"
#include "vtkColorTransferFunction.h" 
#include "vtkContourFilter.h"
#include "vtkCubeSource.h"
#include "vtkContourFilter.h"

#include "vtkDistanceWidget.h" 
#include "vtkDistanceRepresentation.h"
#include <vtkDICOMImageReader.h>
#include "vtkDistanceWidget.h"
#include "vtkDistanceRepresentation2D.h"

#include <vtkEventQtSlotConnect.h>

#include "vtkHandleRepresentation.h"

#include <vtkImageActor.h>
#include "vtkImageData.h"
#include "vtkImageCast.h"  
#include "vtkImageData.h"
#include <vtkImageViewer2.h>
#include "vtkImagePlaneWidget.h"
#include "vtkImageMapToWindowLevelColors.h"
#include "vtkInteractorStyleImage.h"
#include "vtkImageSlabReslice.h"
#include "vtkImageMagnify.h"
#include "vtkImageConstantPad.h"
#include <vtkImageLuminance.h>
#include "vtkImageShrink3D.h"
#include "vtkImageMapToColors.h"

#include <vtkJPEGReader.h>

#include "vtkLookupTable.h"

#include "vtkMarchingCubes.h"
#include "vtkMassProperties.h"

#include "vtkOutlineFilter.h"

#include "vtkProperty.h"
#include "vtkPlane.h"
#include "vtkPlaneSource.h"
#include "vtkPointHandleRepresentation3D.h"
#include "vtkPointHandleRepresentation2D.h"
#include "vtkProperty.h"  
#include "vtkPiecewiseFunction.h"  
#include "vtkPolyDataNormals.h"
#include "vtkPolyDataMapper.h"
#include "vtkPolyDataWriter.h"


#include "vtkResliceImageViewer.h"
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include "vtkResliceCursorLineRepresentation.h"
#include "vtkResliceCursorThickLineRepresentation.h"
#include "vtkResliceCursorLineRepresentation.h"
#include "vtkResliceImageViewerMeasurements.h"
#include "vtkResliceCursorWidget.h"
#include "vtkResliceCursorActor.h"
#include "vtkResliceCursorPolyDataAlgorithm.h"
#include "vtkResliceCursor.h"
#include "vtkResliceImageViewer.h"
#include "vtkResliceImageViewerMeasurements.h"


#include "vtkSmartPointer.h"  
#include "vtkSmoothPolyDataFilter.h"
#include "vtkStripper.h"


#include "vtkTransform.h"
#include "vtkTriangleFilter.h"
#include "vtkTextActor.h"
#include "vtkTextProperty.h"

#include "vtkVolumeProperty.h"  
#include "vtkVolumeRayCastCompositeFunction.h"  
#include "vtkVolumeRayCastMapper.h"  
#include "vtkVolume.h" 
#include "vtkVolume16Reader.h"
#include "vtkVectorText.h"

/*ProjectMainWindow::ProjectMainWindow()
{
	setupUi(this);

    vtkSmartPointer< vtkDICOMImageReader > reader =
        vtkSmartPointer< vtkDICOMImageReader >::New();
    
    reader->SetDirectoryName("F://photo//DICOM//3D");
    reader->Update();
    int imageDims[3];
    reader->GetOutput()->GetDimensions(imageDims);

	
    for(int i = 0; i < 3; i++)
    {
        riw[i] = vtkSmartPointer< vtkResliceImageViewer >::New();
    }

   

   
	vtkResliceCursorLineRepresentation *rep =
		vtkResliceCursorLineRepresentation::SafeDownCast(
		riw[2]->GetResliceCursorWidget()->GetRepresentation());
	riw[2]->SetResliceCursor(riw[0]->GetResliceCursor());

	rep->GetResliceCursorActor()->
		GetCursorAlgorithm()->SetReslicePlaneNormal(2);

	riw[2]->SetInputData(reader->GetOutput());
	riw[2]->SetSliceOrientation(2);
	riw[2]->SetResliceModeToAxisAligned();
	
   /* for(int i = 0; i < 3; i++)
    {
        // make them all share the same reslice cursor object.
        vtkResliceCursorLineRepresentation *rep =
            vtkResliceCursorLineRepresentation::SafeDownCast(
            riw[i]->GetResliceCursorWidget()->GetRepresentation());
        riw[i]->SetResliceCursor(riw[0]->GetResliceCursor());

        rep->GetResliceCursorActor()->
            GetCursorAlgorithm()->SetReslicePlaneNormal(i);

        riw[i]->SetInputData(reader->GetOutput());
        riw[i]->SetSliceOrientation(i);
        riw[i]->SetResliceModeToAxisAligned();
    }*/

    /*vtkSmartPointer<vtkCellPicker> picker =
        vtkSmartPointer<vtkCellPicker>::New();
    picker->SetTolerance(0.005);

    vtkSmartPointer<vtkProperty> ipwProp =
        vtkSmartPointer<vtkProperty>::New();

    vtkSmartPointer< vtkRenderer > ren =
        vtkSmartPointer< vtkRenderer >::New();

    this->qvtkWidget_4->GetRenderWindow()->AddRenderer(ren);
    vtkRenderWindowInteractor *iren = this->qvtkWidget_4->GetInteractor();
	planeWidget[2] = vtkSmartPointer<vtkImagePlaneWidget>::New();
	planeWidget[2]->SetInteractor(iren);
	planeWidget[2]->SetPicker(picker);
	planeWidget[2]->RestrictPlaneToVolumeOn();
	double color[3] = { 0.5, 0, 0 };
	planeWidget[2]->GetPlaneProperty()->SetColor(color);

	color[0] /= 2.0;
	color[1] /= 2.0;
	color[2] /= 2.0;
	riw[2]->GetRenderer()->SetBackground(color);

	planeWidget[2]->SetTexturePlaneProperty(ipwProp);//纹理
	planeWidget[2]->TextureInterpolateOff();
	planeWidget[2]->SetResliceInterpolateToLinear();
	planeWidget[2]->SetInputConnection(reader->GetOutputPort());
	planeWidget[2]->SetPlaneOrientation(2);
	planeWidget[2]->SetSliceIndex(imageDims[2] / 2);
	planeWidget[2]->DisplayTextOn();
	planeWidget[2]->SetDefaultRenderer(ren);
	planeWidget[2]->SetWindowLevel(1358, -27);
	planeWidget[2]->On();
	planeWidget[2]->InteractionOn();
	m_Connections = vtkEventQtSlotConnect::New();*/
    /*for(int i = 0; i < 3; i++)
    {
        planeWidget[i] = vtkSmartPointer<vtkImagePlaneWidget>::New();
        planeWidget[i]->SetInteractor(iren);
        planeWidget[i]->SetPicker(picker);
        planeWidget[i]->RestrictPlaneToVolumeOn();
        double color[3] = {0, 0, 0};
        color[i] = 1;
        planeWidget[i]->GetPlaneProperty()->SetColor(color);

        color[0] /= 2.0;
        color[1] /= 2.0;
        color[2] /= 2.0;
        riw[i]->GetRenderer()->SetBackground(color);

        planeWidget[i]->SetTexturePlaneProperty(ipwProp);//纹理
        planeWidget[i]->TextureInterpolateOff();
        planeWidget[i]->SetResliceInterpolateToLinear();
        planeWidget[i]->SetInputConnection(reader->GetOutputPort());
        planeWidget[i]->SetPlaneOrientation(i);
        planeWidget[i]->SetSliceIndex(imageDims[i] / 2);
        planeWidget[i]->DisplayTextOn();
        planeWidget[i]->SetDefaultRenderer(ren);
        planeWidget[i]->SetWindowLevel(1358, -27);
        planeWidget[i]->On();
        planeWidget[i]->InteractionOn();
    }*/

	//// 设置m_QVTKWidget的渲染器
	//m_QVTKWidget->GetRenderWindow()->AddRenderer(m_pRenderder);

	////连接打开的信号与相应的槽
	//connect( m_OpenAction, SIGNAL( triggered() ), this, SLOT( onOpenSlot() ) ); 

	
	//m_Connections->Connect(m_QVTKWidget->GetRenderWindow()->GetInteractor(),
	//	vtkCommand::MouseMoveEvent,
	//	this,
	//	SLOT(updateCoords(vtkObject*)));
//}

/*ProjectMainWindow::~ProjectMainWindow()
{
}

void ProjectMainWindow::onOpenSlot()
{
	QString filter;
	filter = "DICM image file (*.dcm)";

	QDir dir;
	QString fileName = QFileDialog::getOpenFileName( this, QString(tr("打开图像")), dir.absolutePath() , filter );
	if ( fileName.isEmpty() == true ) 
        return;

	// 支持带中文路径的读取
	QByteArray ba = fileName.toLocal8Bit();
	const char *fileName_str = ba.data();
}

void ProjectMainWindow::updateCoords(vtkObject* obj)
{
	// 获取交互器
	vtkRenderWindowInteractor* iren = vtkRenderWindowInteractor::SafeDownCast(obj);

	// 获取鼠标的当前位置
	int event_pos[2];
	iren->GetEventPosition(event_pos);
  
	QString str;
	str.sprintf("x=%d : y=%d", event_pos[0], event_pos[1]);
	//m_StatusBar->showMessage(str);
}
*/



ProjectMainWindow::ProjectMainWindow()
{
	setupUi(this);
	
	/*
	// Read all the DICOM files in the specified directory.
	vtkSmartPointer<vtkDICOMImageReader> reader = vtkSmartPointer<vtkDICOMImageReader>::New();
	reader->SetFileName(inputFilename.c_str());
	reader->Update();*/
	ren = vtkSmartPointer< vtkRenderer >::New();

	// 设置m_QVTKWidget的渲染器
	this->qvtkWidget_4->GetRenderWindow()->AddRenderer(ren);
	
	//// 设置m_QVTKWidget的渲染器
	//m_QVTKWidget->GetRenderWindow()->AddRenderer(m_pRenderder);

	////连接打开的信号与相应的槽
	connect(this->actionJPG, SIGNAL(triggered()), this, SLOT(onOpenSlotJPG()));
	connect(this->actionDICOM, SIGNAL(triggered()), this, SLOT(onOpenSlotDCM()));
	connect(this->actionBMP, SIGNAL(triggered()), this, SLOT(onOpenSlotBMP()));
	connect(this->actionDcm, SIGNAL(triggered()), this, SLOT(onOpenlistphoto()));
	connect(this->actionMain, SIGNAL(triggered()), this, SLOT(threeD_module()));
	connect(this->actionTihui, SIGNAL(triggered()), this, SLOT(area_module()));
	connect(this->actionUo, SIGNAL(triggered()), this, SLOT(Zoom()));
	connect(this->actionAmplify, SIGNAL(triggered()), this, SLOT(Amplify()));
	connect(this->actionUdo, SIGNAL(triggered()), this, SLOT(gray()));
	connect(this->pushButton_4, &QPushButton::clicked, this, &ProjectMainWindow::volumeph);
	connect(this->pushButton_3, &QPushButton::clicked, this, &ProjectMainWindow::volumeph);
	connect(this->pushButton, &QPushButton::clicked, this, &ProjectMainWindow::On_pushButton);
	connect(this->pushButton_2, &QPushButton::clicked, this, &ProjectMainWindow::On_pushButton);
	connect(this->horizontalSlider_4, &QSlider::valueChanged, this, &ProjectMainWindow::Slider);
	connect(this->horizontalSlider_3, &QSlider::valueChanged, this, &ProjectMainWindow::Slider_grey);
	connect(this->resample_action, SIGNAL(triggered()), this, SLOT(lable()));
	connect(this->actionTi, SIGNAL(triggered()), this, SLOT(three_get()));
	connect(this->pushButton_5, &QPushButton::clicked, this, &ProjectMainWindow::three_get);
	connect(this->comboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(three_gray()));
	connect(this->save_action, SIGNAL(triggered()), this, SLOT(save()));

    m_Connections = vtkEventQtSlotConnect::New();
	m_Connections->Connect(this->qvtkWidget_4->GetRenderWindow()->GetInteractor(),
		vtkCommand::MouseMoveEvent,
		this,
		SLOT(updateCoords(vtkObject*)));
}

	ProjectMainWindow::~ProjectMainWindow()
	{
	}

	void ProjectMainWindow::onOpenSlotDCM()
	{
	QString fileName = QFileDialog::getOpenFileName( this, QString(tr("打开图像")), "F:/photo/");
	this->qvtkWidget_4->GetRenderWindow()->RemoveRenderer(ren);
	ren = vtkSmartPointer< vtkRenderer >::New();
	this->qvtkWidget_4->GetRenderWindow()->AddRenderer(ren);
	if (fileName.isEmpty() == true)
	{
		return;
	}
	else
	{
		QFile file(fileName);
		//打开只读文件
		bool isOK = file.open(QIODevice::ReadOnly);
		if (isOK = true)
		{
			QByteArray ba = fileName.toLocal8Bit();
			const char *fileName_str = ba.data();
			dicomImagereader =vtkSmartPointer<vtkDICOMImageReader>::New();
			dicomImagereader->SetFileName(fileName_str);
			dicomImagereader->Update();

			if (dicomImagereader->GetPatientName())
			{
				this->label_3->setText(dicomImagereader->GetPatientName());
			}
			else
			{
				this->label_3->setText("name");
			}
			if (dicomImagereader->GetStudyUID())
			{
				this->label_11->setText(dicomImagereader->GetStudyUID());
			}
			else
			{
				this->label_11->setText("UID");
			}
			this->horizontalSlider_4->setMaximum(0);
			this->label_13->setText("0");
			this->label_14->setText("0");
			/*vtkTextActor *textActor = vtkTextActor::New();
			textActor->SetDisplayPosition(30, 750);
			textActor->SetInput("The patient name:");
			textActor->SetInput(reader->GetPatientName());
			textActor->GetTextProperty()->SetFontSize(18);
			textActor->GetTextProperty()->SetColor(1, 1, 1);
			ren->AddActor(textActor);*/
			rdImageCast = vtkSmartPointer<vtkImageConstantPad>::New();

			rdImageCast->SetInputConnection(dicomImagereader->GetOutputPort());
			rdImageCast->Update();

			vtkSmartPointer< vtkRenderWindowInteractor >  m_pInteractor = vtkSmartPointer< vtkRenderWindowInteractor >::New();
			
			vtkSmartPointer<vtkImageViewer2> imageViewer = vtkSmartPointer<vtkImageViewer2>::New();
			cout << imageViewer->GetInput();
			imageViewer->SetInputConnection(dicomImagereader->GetOutputPort());
			//this->qvtkWidget_4->GetRenderWindow()->SetInteractor(m_pInteractor);
			imageViewer->UpdateDisplayExtent();
			imageViewer->SetRenderWindow(this->qvtkWidget_4->GetRenderWindow());
			imageViewer->SetRenderer(ren);
			imageViewer->SetSliceOrientationToXY();
			imageViewer->GetImageActor()->InterpolateOff();
			
			ren->ResetCamera();
			ren->DrawOn();
			ren->InteractiveOn();
			this->qvtkWidget_4->GetRenderWindow()->Render();
		}
		file.close();

	}
	// 支持带中文路径的读取
	QByteArray ba = fileName.toLocal8Bit();
	const char *fileName_str = ba.data();
	}
	
	//打开JPG图像
	void ProjectMainWindow::onOpenSlotJPG()
	{
		QString filter;
		filter = "JPEG(*.jpg *.jpeg)";
		this->qvtkWidget_4->GetRenderWindow()->RemoveRenderer(ren);
		ren = vtkSmartPointer< vtkRenderer >::New();
		this->qvtkWidget_4->GetRenderWindow()->AddRenderer(ren);
		//QDir dir;
		//QString fileName = QFileDialog::getOpenFileName( this, QString(tr("打开图像")), dir.absolutePath() , filter );
		QString fileName = QFileDialog::getOpenFileName(this, QString(tr("打开图像")), "F:/photo/", filter);
		if (fileName.isEmpty() == true)
		{
			return;
		}
		else
		{
			QFile file(fileName);
			//打开只读文件
			bool isOK = file.open(QIODevice::ReadOnly);
			if (isOK = true)
			{
				QByteArray ba = fileName.toLocal8Bit();
				const char *fileName_str = ba.data();

				vtkSmartPointer<vtkJPEGReader>reader = vtkSmartPointer<vtkJPEGReader>::New();
				reader->SetFileName(fileName_str);
				reader->SetDataByteOrderToLittleEndian();
				reader->ReleaseDataFlagOff();

				reader->SetDataOrigin(0, 0, 0.0);
				reader->Update();

				this->label_3->setText("name");
				this->label_11->setText("UID");
				

				rdImageCast = vtkSmartPointer<vtkImageConstantPad>::New();
				rdImageCast->SetInputConnection(reader->GetOutputPort());
				rdImageCast->Update();


				vtkSmartPointer< vtkRenderWindowInteractor >  m_pInteractor = vtkSmartPointer< vtkRenderWindowInteractor >::New();
				
				vtkSmartPointer<vtkImageViewer2> imageViewer = vtkSmartPointer<vtkImageViewer2>::New();
				imageViewer->SetInputConnection(reader->GetOutputPort());
				//this->qvtkWidget_4->GetRenderWindow()->SetInteractor(m_pInteractor);
				imageViewer->UpdateDisplayExtent();
				imageViewer->SetRenderWindow(this->qvtkWidget_4->GetRenderWindow());
				imageViewer->SetSize(758, 732);
				imageViewer->SetRenderer(ren);
				//imageViewer->SetSliceOrientationToXY();
				imageViewer->GetImageActor()->InterpolateOff();
				ren->ResetCamera();
				ren->ResetCameraClippingRange();
				ren->DrawOn();
				ren->InteractiveOn();	
				this->qvtkWidget_4->GetRenderWindow()->Render();
			}
			file.close();
		}
		// 支持带中文路径的读取
		QByteArray ba = fileName.toLocal8Bit();
		const char *fileName_str = ba.data();
		
	}

	//打开BMP图像
	void ProjectMainWindow::onOpenSlotBMP()
	{
		QString filter;
		filter = "BMP(*.bmp)";
		this->qvtkWidget_4->GetRenderWindow()->RemoveRenderer(ren);
		ren = vtkSmartPointer< vtkRenderer >::New();
		this->qvtkWidget_4->GetRenderWindow()->AddRenderer(ren);
		QString fileName = QFileDialog::getOpenFileName(this, QString(tr("打开图像")), "F:/photo/", filter);
		if (fileName.isEmpty() == true)
		{
			return;
		}
		else
		{
			QFile file(fileName);
			//打开只读文件
			bool isOK = file.open(QIODevice::ReadOnly);
			if (isOK = true)
			{
				QByteArray ba = fileName.toLocal8Bit();
				const char *fileName_str = ba.data();
				vtkSmartPointer<vtkBMPReader> reader =
					vtkSmartPointer<vtkBMPReader>::New();
				reader->SetFileName(fileName_str);
				vtkTransform *t1 = vtkTransform::New();
				t1->RotateZ(0);
				reader->SetTransform(t1); //控制图像的旋转
				reader->Update();

				this->label_3->setText("name");
				this->label_11->setText("UID");

				rdImageCast = vtkSmartPointer<vtkImageConstantPad>::New();
				rdImageCast->SetInputConnection(reader->GetOutputPort());
				rdImageCast->Update();


				vtkSmartPointer< vtkRenderWindowInteractor >  m_pInteractor = vtkSmartPointer< vtkRenderWindowInteractor >::New();

				vtkSmartPointer<vtkImageViewer2> imageViewer = vtkSmartPointer<vtkImageViewer2>::New();
				imageViewer->SetInputConnection(reader->GetOutputPort());
				//this->qvtkWidget_4->GetRenderWindow()->SetInteractor(m_pInteractor);
				imageViewer->UpdateDisplayExtent();
				imageViewer->SetRenderWindow(this->qvtkWidget_4->GetRenderWindow());
				imageViewer->SetRenderer(ren);
				imageViewer->SetSliceOrientationToXY();
				imageViewer->GetImageActor()->InterpolateOff();
				ren->ResetCamera();
				ren->ResetCameraClippingRange();
				ren->DrawOn();
				ren->InteractiveOn();
				this->qvtkWidget_4->GetRenderWindow()->Render();
			}
			file.close();
		}
		// 支持带中文路径的读取
		QByteArray ba = fileName.toLocal8Bit();
		const char *fileName_str = ba.data();
	}
	void ProjectMainWindow::onOpenlistphoto()
	{
		QString fileName = QFileDialog::getExistingDirectory(this, QString(tr("打开图像")), "F:/photo/");
		this->qvtkWidget_4->GetRenderWindow()->RemoveRenderer(ren);
		ren = vtkSmartPointer< vtkRenderer >::New();
		
		this->qvtkWidget_4->GetRenderWindow()->AddRenderer(ren);
		if (fileName.isEmpty() == true)
		{
			return;
		}
		else
		{
			QFile file(fileName);
			//打开只读文件
			bool isOK = file.open(QIODevice::ReadOnly);
			if (isOK = true)
			{
				QByteArray ba = fileName.toLocal8Bit();
				const char *fileName_str = ba.data();
				dicomImagereader = vtkSmartPointer<vtkDICOMImageReader>::New();
				dicomImagereader->SetDirectoryName(fileName_str);
				dicomImagereader->SetDataByteOrderToLittleEndian();
				dicomImagereader->Update();
				//dicomImagereader->SetFileNameSliceSpacing(11);//设置分隔大小
				if (dicomImagereader->GetPatientName())
				{
					this->label_3->setText(dicomImagereader->GetPatientName());
				}
				else
				{
					this->label_3->setText("name");
				}
				if (dicomImagereader->GetStudyUID())
				{
					this->label_11->setText(dicomImagereader->GetStudyUID());
				}
				else
				{
					this->label_11->setText("UID");
				}

				readerImageCast = vtkSmartPointer<vtkImageCast>::New();

				readerImageCast->SetInputConnection(dicomImagereader->GetOutputPort());
				readerImageCast->SetOutputScalarTypeToUnsignedShort();
				readerImageCast->Update();

				vtkSmartPointer<vtkImageViewer2> imageViewer = vtkSmartPointer<vtkImageViewer2>::New();
				imageViewer->SetInputConnection(readerImageCast->GetOutputPort());
				
				this->horizontalSlider_4->setMaximum(imageViewer->GetSliceMax());
				//显示当前图片信息
				cout <<"滑动条最大值"<< this->horizontalSlider_4->maximum() << endl;
				//imageViewer->SetSlice(this->horizontalSlider_4->sliderPosition());
				//connect(this->horizontalSlider_4, &QSlider::valueChanged ,this->label_9, &QLabel::setText);
				imageViewer->UpdateDisplayExtent();
				QString str4,str5;
				str4.sprintf("min:%d", imageViewer->GetSliceMin());
				str5.sprintf("max:%d", imageViewer->GetSliceMax());
				this->label_13->setText(str4);
				this->label_14->setText(str5);
				if (imageViewer->GetSlice())
				{
					if (imageViewer->GetSlice() >= imageViewer->GetSliceMin() && imageViewer->GetSlice() <= imageViewer->GetSliceMax())
					{
						QString str3;
						str3.sprintf("%d", imageViewer->GetSlice());
						this->label_9->setText(str3);
						
						
					}
				}
				else
				{
					this->label_9->setText("0");
				}
				imageViewerButton = vtkSmartPointer<vtkImageViewer2>::New();
				imageViewerButton->SetInputConnection(readerImageCast->GetOutputPort());
				imageViewerButton->UpdateDisplayExtent();
				//显示到wighet
				imageViewer->SetRenderWindow(this->qvtkWidget_4->GetRenderWindow());
				imageViewer->SetRenderer(ren);
				imageViewer->SetSliceOrientationToXY();
				imageViewer->GetImageActor()->InterpolateOff();
				ren->ResetCamera();
				ren->DrawOn();
				ren->InteractiveOn();
				this->qvtkWidget_4->GetRenderWindow()->Render();
			}
			file.close();

		}
		// 支持带中文路径的读取
		QByteArray ba = fileName.toLocal8Bit();
		const char *fileName_str = ba.data();
		
	}
	void ProjectMainWindow::save()
	{
		vtkSmartPointer<vtkPolyDataWriter> vtkWriter = vtkSmartPointer<vtkPolyDataWriter>::New();
		vtkWriter->SetInputData(skinStripper->GetOutput());
		QString fileName = QFileDialog::getSaveFileName(this,QString::fromLocal8Bit("文件另存为"),"",tr("Config Files (*.vtk)"));
		
		vtkWriter->SetFileName("1.vtk");
		vtkWriter->Write();
	}
	void ProjectMainWindow::On_pushButton()
	{
		//ren = vtkSmartPointer< vtkRenderer >::New();
		//this->qvtkWidget_4->GetRenderWindow()->AddRenderer(ren);
		//获取信号接受者
		QObject *mySender = sender();
		//转换为按钮类型
		QPushButton *p = (QPushButton *)mySender;

			
		if (NULL != p)
		{
			//获取按钮内容
			QString str = p->text();
			if (str=="+")
			{
				
				QString current = this->label_9->text();
				int nnum = current.toInt();
				imageViewerButton->SetSlice( nnum + 1);
				this->horizontalSlider_4->setSliderPosition(nnum+1);
				
				if (imageViewerButton->GetSlice())
				{
					if (imageViewerButton->GetSlice() >= imageViewerButton->GetSliceMin() && imageViewerButton->GetSlice() <= imageViewerButton->GetSliceMax())
					{
						QString str3;
						str3.sprintf("%d", imageViewerButton->GetSlice());
						this->label_9->setText(str3);
					}
				}
				else
				{
					this->label_9->setText("0");
				}
				
			}
			else if (str == "-")
			{
				QString current = this->label_9->text();
				int nnum = current.toInt();
				if (nnum != 0)
				{
					imageViewerButton->SetSlice(nnum - 1);
					this->horizontalSlider_4->setSliderPosition(nnum - 1);
					if (imageViewerButton->GetSlice())
					{
						if (imageViewerButton->GetSlice() >= imageViewerButton->GetSliceMin() && imageViewerButton->GetSlice() <= imageViewerButton->GetSliceMax())
						{
							QString str3;
							str3.sprintf("%d", imageViewerButton->GetSlice());
							this->label_9->setText(str3);
						}
					}
					else
					{
						this->label_9->setText("0");
					}
				}
			}
			imageViewerButton->UpdateDisplayExtent();
			imageViewerButton->SetRenderWindow(this->qvtkWidget_4->GetRenderWindow());
			imageViewerButton->SetRenderer(ren);
			imageViewerButton->SetSliceOrientationToXY();
			imageViewerButton->GetImageActor()->InterpolateOff();
			ren->ResetCamera();
			ren->ResetCameraClippingRange();
			ren->DrawOn();
			ren->InteractiveOn();
			this->qvtkWidget_4->GetRenderWindow()->Render();
		}
		
	}

	void ProjectMainWindow::Slider()
	{
		//this->qvtkWidget_4->GetRenderWindow()->RemoveRenderer(ren);
		//ren = vtkSmartPointer< vtkRenderer >::New();
		//this->qvtkWidget_4->GetRenderWindow()->AddRenderer(ren);
		//获取信号接受者
		QObject *mySender = sender();
		//转换为滑块类型
		QSlider *p = (QSlider *)mySender;
		if (NULL != p)
		{
			int num;
			num = p->sliderPosition();
			imageViewerButton->SetSlice(num);
			if (imageViewerButton->GetSlice())
			{
				if (imageViewerButton->GetSlice() >= imageViewerButton->GetSliceMin() && imageViewerButton->GetSlice() <= imageViewerButton->GetSliceMax())
				{
					QString str3;
					str3.sprintf("%d", imageViewerButton->GetSlice());
					this->label_9->setText(str3);
				}
			}
			else
			{
				this->label_9->setText("0");
			}
			imageViewerButton->UpdateDisplayExtent();
			imageViewerButton->SetRenderWindow(this->qvtkWidget_4->GetRenderWindow());
			imageViewerButton->SetRenderer(ren);
			imageViewerButton->SetSliceOrientationToXY();
			imageViewerButton->GetImageActor()->InterpolateOff();
			ren->ResetCamera();
			ren->ResetCameraClippingRange();
			ren->DrawOn();
			ren->InteractiveOn();
			this->qvtkWidget_4->GetRenderWindow()->Render();
		}
		
	}
	void ProjectMainWindow::Slider_grey()
	{
		//ren = vtkSmartPointer< vtkRenderer >::New();
		//this->qvtkWidget_4->GetRenderWindow()->AddRenderer(ren);
		this->horizontalSlider_3->setMaximum(2048);
		//获取信号接受者
		QObject *mySender = sender();
		//转换为按钮类型
		QSlider *p = (QSlider *)mySender;
		if (NULL != p)
		{
			int num;
			num = p->sliderPosition();
			vtkSmartPointer<vtkImageViewer2> imageViewer = vtkSmartPointer<vtkImageViewer2>::New();
			imageViewer->SetInputConnection(dicomImagereader->GetOutputPort());
			//this->qvtkWidget_4->GetRenderWindow()->SetInteractor(m_pInteractor);
			imageViewer->SetColorLevel(num);
			imageViewer->UpdateDisplayExtent();
			imageViewer->SetRenderWindow(this->qvtkWidget_4->GetRenderWindow());
			imageViewer->SetRenderer(ren);
			imageViewer->SetSliceOrientationToXY();
			imageViewer->GetImageActor()->InterpolateOff();
			ren->ResetCamera();
			ren->ResetCameraClippingRange();
			ren->DrawOn();
			ren->InteractiveOn();
			this->qvtkWidget_4->GetRenderWindow()->Render();
		}

	}
	void ProjectMainWindow::threeD_module()
	{
		this->qvtkWidget_4->GetRenderWindow()->RemoveRenderer(ren);
		ren = vtkSmartPointer< vtkRenderer >::New();
		this->qvtkWidget_4->GetRenderWindow()->AddRenderer(ren);
		vtkSmartPointer<vtkPiecewiseFunction>opactiyTransferFunction = vtkSmartPointer<vtkPiecewiseFunction>::New();
		opactiyTransferFunction->AddPoint(120, 0.0);
		opactiyTransferFunction->AddPoint(250, 1.0);
		opactiyTransferFunction->AddPoint(520, 1.0);
		opactiyTransferFunction->AddPoint(650, 0.0);


		vtkSmartPointer<vtkColorTransferFunction>colorTransferFunction = vtkSmartPointer<vtkColorTransferFunction>::New();
		colorTransferFunction->AddRGBPoint(120, 255 / 255.0, 98 / 255.0, 98 / 255.0);
		colorTransferFunction->AddRGBPoint(250, 255 / 255.0, 255 / 255.0, 180 / 255.0);
		colorTransferFunction->AddRGBPoint(520, 1.0, 1.0, 1.0);
		colorTransferFunction->AddRGBPoint(650, 1.0, 1.0, 1.0);

		vtkSmartPointer<vtkPiecewiseFunction>gradientTransferFunction = vtkSmartPointer<vtkPiecewiseFunction>::New();
		gradientTransferFunction->AddPoint(120, 2.0);
		gradientTransferFunction->AddPoint(250, 2.0);
		gradientTransferFunction->AddPoint(520, 0.1);
		gradientTransferFunction->AddPoint(650, 0.1);

		volumeProperty = vtkSmartPointer<vtkVolumeProperty>::New();
		volumeProperty->SetColor(colorTransferFunction);
		volumeProperty->SetScalarOpacity(opactiyTransferFunction);
		volumeProperty->SetGradientOpacity(gradientTransferFunction);
		volumeProperty->ShadeOn();//阴影
		//volumeProperty->SetInterpolationTypeToLinear();//直线与样条插值之间逐发函数
		volumeProperty->SetAmbient(0.2);//环境光系数
		volumeProperty->SetDiffuse(0.9);//漫反射
		volumeProperty->SetSpecular(0.2);//高光系数
		volumeProperty->SetSpecularPower(10);//高光强度

		vtkSmartPointer<vtkVolumeRayCastCompositeFunction>compositeRaycastFunction = vtkSmartPointer<vtkVolumeRayCastCompositeFunction>::New();


		volumeMapper = vtkSmartPointer<vtkVolumeRayCastMapper>::New();
		volumeMapper->SetVolumeRayCastFunction(compositeRaycastFunction);//载入体绘制方法
		volumeMapper->SetInputConnection(readerImageCast->GetOutputPort());
		/*fixedPointVolumeMapper=vtkFixedPointVolumeRayCastMapper::New();
		fixedPointVolumeMapper->SetInput(dicomImagereader->GetOutput());*/

		vtkSmartPointer<vtkVolume>volume = vtkSmartPointer<vtkVolume>::New();
		volume->SetMapper(volumeMapper);
		volume->SetProperty(volumeProperty);//设置体属性

		vtkRenderWindowInteractor *iren = this->qvtkWidget_4->GetInteractor();
		ren->AddVolume(volume);
		this->qvtkWidget_4->GetRenderWindow()->AddRenderer(ren);
		ren->InteractiveOn();
		this->qvtkWidget_4->GetRenderWindow()->Render();

	}
	void ProjectMainWindow::area_module()
	{
		
		this->qvtkWidget_4->GetRenderWindow()->RemoveRenderer(ren);
		ren = vtkSmartPointer< vtkRenderer >::New();
		this->qvtkWidget_4->GetRenderWindow()->AddRenderer(ren);
		vtkContourFilter *skinExtractor = vtkContourFilter::New();
		skinExtractor->SetInputConnection(readerImageCast->GetOutputPort());
		skinExtractor->SetValue(0, 51);
		// skinExtractor->GenerateValues(0,49,51);

		vtkPolyDataNormals *skinNormals = vtkPolyDataNormals::New();
		skinNormals->SetInputConnection(skinExtractor->GetOutputPort());
		skinNormals->SetFeatureAngle(60.0);

		skinStripper = vtkStripper::New();
		skinStripper->SetInputConnection(skinNormals->GetOutputPort());

		vtkPolyDataMapper *skinMapper = vtkPolyDataMapper::New();
		skinMapper->SetInputConnection(skinStripper->GetOutputPort());
		skinMapper->ScalarVisibilityOff();
		vtkActor *skin = vtkActor::New();
		skin->SetMapper(skinMapper);
		skin->GetProperty()->SetColor(1, .32, .28);
		skin->GetProperty()->SetOpacity(0);

		vtkContourFilter *skin2Extractor = vtkContourFilter::New();
		skin2Extractor->SetInputConnection(readerImageCast->GetOutputPort());
		skin2Extractor->SetValue(0, 101);
		//skin2Extractor->GenerateValues(1,99,101);

		vtkPolyDataNormals *skin2Normals = vtkPolyDataNormals::New();
		skin2Normals->SetInputConnection(skin2Extractor->GetOutputPort());
		skin2Normals->SetFeatureAngle(60.0);

		vtkStripper *skin2Stripper = vtkStripper::New();
		skin2Stripper->SetInputConnection(skin2Normals->GetOutputPort());

		vtkPolyDataMapper *skin2Mapper = vtkPolyDataMapper::New();
		skin2Mapper->SetInputConnection(skin2Stripper->GetOutputPort());
		skin2Mapper->ScalarVisibilityOff();
		vtkActor *skin2 = vtkActor::New();
		skin2->SetMapper(skin2Mapper);
		skin2->GetProperty()->SetColor(1, .49, .25);
		skin2->GetProperty()->SetOpacity(0.4);


		vtkContourFilter *skin3Extractor = vtkContourFilter::New();
		skin3Extractor->SetInputConnection(readerImageCast->GetOutputPort());
		skin3Extractor->SetValue(0, 151);
		// skin3Extractor->GenerateValues(2,149,151);


		vtkPolyDataNormals *skin3Normals = vtkPolyDataNormals::New();
		skin3Normals->SetInputConnection(skin3Extractor->GetOutputPort());
		skin3Normals->SetFeatureAngle(60.0);

		vtkStripper *skin3Stripper = vtkStripper::New();
		skin3Stripper->SetInputConnection(skin3Normals->GetOutputPort());

		vtkPolyDataMapper *skin3Mapper = vtkPolyDataMapper::New();
		skin3Mapper->SetInputConnection(skin3Stripper->GetOutputPort());
		skin3Mapper->ScalarVisibilityOff();
		vtkActor *skin3 = vtkActor::New();
		skin3->SetMapper(skin3Mapper);
		skin3->GetProperty()->SetColor(1, 0.2, 0);
		skin3->GetProperty()->SetOpacity(0.5);

		//抽取骨头
		//抽取等值面为骨头的信息
		vtkMarchingCubes *boneExtractor = vtkMarchingCubes::New();
		boneExtractor->SetInputConnection(readerImageCast->GetOutputPort());
		boneExtractor->SetValue(0, 1150); //设置提取的等值信息
		vtkPolyDataNormals *boneNormals = vtkPolyDataNormals::New();
		boneNormals->SetInputConnection(boneExtractor->GetOutputPort());
		boneNormals->SetFeatureAngle(60.0);
		//剔除旧的或废除的数据单元，提高绘制速度
		vtkStripper *boneStripper = vtkStripper::New();
		//注意：vtk6.0以后的版本，管道的连接函数修改为了SetInputConnection()和GetOutputPort().
		boneStripper->SetInputConnection(boneNormals->GetOutputPort());
		//建立映射
		vtkPolyDataMapper *boneMapper = vtkPolyDataMapper::New();
		//注意：vtk6.0以后的版本，管道的连接函数修改为了SetInputConnection()和GetOutputPort().
		boneMapper->SetInputConnection(boneStripper->GetOutputPort());
		boneMapper->ScalarVisibilityOff();
		//建立角色
		vtkActor *bone = vtkActor::New();
		bone->SetMapper(boneMapper);
		bone->GetProperty()->SetDiffuseColor(1, 1, .9412);
		//
		vtkOutlineFilter *outlineData = vtkOutlineFilter::New();
		outlineData->SetInputConnection(readerImageCast->GetOutputPort());
		vtkPolyDataMapper *mapOutline = vtkPolyDataMapper::New();
		mapOutline->SetInputConnection(outlineData->GetOutputPort());
		vtkActor *outline = vtkActor::New();
		outline->SetMapper(mapOutline);
		outline->GetProperty()->SetColor(0, 1, 0); //设置显示边框的颜色

		vtkCamera *aCamera = vtkCamera::New();
		aCamera->SetViewUp(0, 0, -1);
		aCamera->SetPosition(0, 1, 0);
		aCamera->SetFocalPoint(0, 0, 0);
		aCamera->ComputeViewPlaneNormal();

		ren->AddActor(outline);
		ren->AddActor(skin);
		ren->AddActor(skin2);
		ren->AddActor(skin3);
		ren->AddActor(bone);

		ren->SetActiveCamera(aCamera);
		ren->ResetCamera();
		aCamera->Dolly(1.5);

		ren->SetBackground(1, 1, 1);
		

		ren->ResetCameraClippingRange();

		vtkRenderWindowInteractor *iren = this->qvtkWidget_4->GetInteractor();
		
		this->qvtkWidget_4->GetRenderWindow()->AddRenderer(ren);
		ren->InteractiveOn();
		this->qvtkWidget_4->GetRenderWindow()->Render();
		

	}
	void ProjectMainWindow::three_gray()
	{
		//获取信号接受者
		cout << "ni" << endl;
		if (this->comboBox->currentIndex() == 0)
		{
			cout << "hao " << endl;
			this->qvtkWidget_4->GetRenderWindow()->RemoveRenderer(ren);
			ren = vtkSmartPointer< vtkRenderer >::New();
			this->qvtkWidget_4->GetRenderWindow()->AddRenderer(ren);
			//抽取骨头
			//抽取等值面为骨头的信息
			vtkMarchingCubes *boneExtractor = vtkMarchingCubes::New();
			boneExtractor->SetInputConnection(readerImageCast->GetOutputPort());
			boneExtractor->SetValue(0, 1150); //设置提取的等值信息
			vtkPolyDataNormals *boneNormals = vtkPolyDataNormals::New();
			boneNormals->SetInputConnection(boneExtractor->GetOutputPort());
			boneNormals->SetFeatureAngle(60.0);
			//剔除旧的或废除的数据单元，提高绘制速度
			vtkStripper *boneStripper = vtkStripper::New();
			//注意：vtk6.0以后的版本，管道的连接函数修改为了SetInputConnection()和GetOutputPort().
			boneStripper->SetInputConnection(boneNormals->GetOutputPort());
			//建立映射
			vtkPolyDataMapper *boneMapper = vtkPolyDataMapper::New();
			//注意：vtk6.0以后的版本，管道的连接函数修改为了SetInputConnection()和GetOutputPort().
			boneMapper->SetInputConnection(boneStripper->GetOutputPort());
			boneMapper->ScalarVisibilityOff();
			//建立角色
			vtkActor *bone = vtkActor::New();
			bone->SetMapper(boneMapper);
			bone->GetProperty()->SetDiffuseColor(1, 1, .9412);
			//
			vtkOutlineFilter *outlineData = vtkOutlineFilter::New();
			outlineData->SetInputConnection(readerImageCast->GetOutputPort());
			vtkPolyDataMapper *mapOutline = vtkPolyDataMapper::New();
			mapOutline->SetInputConnection(outlineData->GetOutputPort());
			vtkActor *outline = vtkActor::New();
			outline->SetMapper(mapOutline);
			outline->GetProperty()->SetColor(0, 1, 0); //设置显示边框的颜色

			vtkCamera *aCamera = vtkCamera::New();
			aCamera->SetViewUp(0, 0, -1);
			aCamera->SetPosition(0, 1, 0);
			aCamera->SetFocalPoint(0, 0, 0);
			aCamera->ComputeViewPlaneNormal();

			ren->AddActor(outline);
			ren->AddActor(bone);

			ren->SetActiveCamera(aCamera);
			ren->ResetCamera();
			aCamera->Dolly(1.5);

			ren->SetBackground(1, 1, 1);


			ren->ResetCameraClippingRange();

			vtkRenderWindowInteractor *iren = this->qvtkWidget_4->GetInteractor();

			this->qvtkWidget_4->GetRenderWindow()->AddRenderer(ren);
			ren->InteractiveOn();
			this->qvtkWidget_4->GetRenderWindow()->Render();

		}
		else if (this->comboBox->currentIndex() == 1)
		{
			cout << "nihao " << endl;
			this->qvtkWidget_4->GetRenderWindow()->RemoveRenderer(ren);
			ren = vtkSmartPointer< vtkRenderer >::New();
			this->qvtkWidget_4->GetRenderWindow()->AddRenderer(ren);
			vtkContourFilter *skin2Extractor = vtkContourFilter::New();
			skin2Extractor->SetInputConnection(readerImageCast->GetOutputPort());
			skin2Extractor->SetValue(0, 101);
			//skin2Extractor->GenerateValues(1,99,101);

			vtkPolyDataNormals *skin2Normals = vtkPolyDataNormals::New();
			skin2Normals->SetInputConnection(skin2Extractor->GetOutputPort());
			skin2Normals->SetFeatureAngle(60.0);

			vtkStripper *skin2Stripper = vtkStripper::New();
			skin2Stripper->SetInputConnection(skin2Normals->GetOutputPort());

			vtkPolyDataMapper *skin2Mapper = vtkPolyDataMapper::New();
			skin2Mapper->SetInputConnection(skin2Stripper->GetOutputPort());
			skin2Mapper->ScalarVisibilityOff();
			vtkActor *skin2 = vtkActor::New();
			skin2->SetMapper(skin2Mapper);
			skin2->GetProperty()->SetColor(1, .49, .25);
			skin2->GetProperty()->SetOpacity(0.4);
			vtkOutlineFilter *outlineData = vtkOutlineFilter::New();
			outlineData->SetInputConnection(readerImageCast->GetOutputPort());
			vtkPolyDataMapper *mapOutline = vtkPolyDataMapper::New();
			mapOutline->SetInputConnection(outlineData->GetOutputPort());
			vtkActor *outline = vtkActor::New();
			outline->SetMapper(mapOutline);
			outline->GetProperty()->SetColor(0, 1, 0); //设置显示边框的颜色

			vtkCamera *aCamera = vtkCamera::New();
			aCamera->SetViewUp(0, 0, -1);
			aCamera->SetPosition(0, 1, 0);
			aCamera->SetFocalPoint(0, 0, 0);
			aCamera->ComputeViewPlaneNormal();

			ren->AddActor(outline);
			ren->AddActor(skin2);

			ren->SetActiveCamera(aCamera);
			ren->ResetCamera();
			aCamera->Dolly(1.5);

			ren->SetBackground(1, 1, 1);


			ren->ResetCameraClippingRange();

			vtkRenderWindowInteractor *iren = this->qvtkWidget_4->GetInteractor();

			this->qvtkWidget_4->GetRenderWindow()->AddRenderer(ren);
			ren->InteractiveOn();
			this->qvtkWidget_4->GetRenderWindow()->Render();


		}

	}
	void ProjectMainWindow::Zoom()
	{	
		this->qvtkWidget_4->GetRenderWindow()->RemoveRenderer(ren);
		ren = vtkSmartPointer< vtkRenderer >::New();
		this->qvtkWidget_4->GetRenderWindow()->AddRenderer(ren);

			
		vtkSmartPointer<vtkImageMagnify> scale = vtkSmartPointer<vtkImageMagnify>::New();
		scale->SetInputConnection(rdImageCast->GetOutputPort());
		scale->SetMagnificationFactors(3, 3, 1); //图像各个维度的维放
		scale->InterpolateOn();
		scale->Update();
		
		//显示缩放图像
		/*vtkImageViewer2  *viewer = vtkImageViewer2::New();
		viewer->SetInputConnection(scale->GetOutputPort());
		viewer->SetInputData(scale->GetOutput());
		viewer->Render();
		viewer->SetSize(640, 480);//设置窗口大小
		//viewer->SetColorWindow(256);
		//viewer->SetColorLevel(200);
		viewer->SetPosition(0, 0);
	    viewer->Render();
		vtkRenderWindowInteractor *viewerinter = vtkRenderWindowInteractor::New();
		viewer->SetupInteractor(viewerinter);
		
		viewerinter->Initialize();
		viewerinter->Start();

		viewer->Delete();
		viewerinter->Delete();*/

		vtkSmartPointer< vtkRenderWindowInteractor >  m_pInteractor = vtkSmartPointer< vtkRenderWindowInteractor >::New();

		vtkSmartPointer<vtkImageViewer2> imageViewer = vtkSmartPointer<vtkImageViewer2>::New();
		imageViewer->SetInputData(scale->GetOutput());
		this->qvtkWidget_4->GetRenderWindow()->SetInteractor(m_pInteractor);
		imageViewer->UpdateDisplayExtent();
		imageViewer->SetRenderWindow(this->qvtkWidget_4->GetRenderWindow());
		imageViewer->SetRenderer(ren);
		imageViewer->SetSliceOrientationToXY();
		imageViewer->GetImageActor()->InterpolateOff();
		ren->ResetCamera();
		ren->DrawOn();
		ren->InteractiveOn();
		this->qvtkWidget_4->GetRenderWindow()->Render();
		rdImageCast = vtkSmartPointer<vtkImageConstantPad>::New();
		rdImageCast->SetInputConnection(scale->GetOutputPort());
		rdImageCast->Update();
	}

	void ProjectMainWindow::Amplify()
	{
		this->qvtkWidget_4->GetRenderWindow()->RemoveRenderer(ren);
		ren = vtkSmartPointer< vtkRenderer >::New();
		this->qvtkWidget_4->GetRenderWindow()->AddRenderer(ren);
		
		//图像的放大
		vtkImageShrink3D *scale = vtkImageShrink3D::New();
		scale->SetInputConnection(rdImageCast->GetOutputPort());
		scale->SetShrinkFactors(3, 3, 1);
		scale->Update();
		rdImageCast = vtkSmartPointer<vtkImageConstantPad>::New();
		rdImageCast->SetInputConnection(scale->GetOutputPort());
		rdImageCast->Update();
		vtkSmartPointer< vtkRenderWindowInteractor >  m_pInteractor = vtkSmartPointer< vtkRenderWindowInteractor >::New();
		
		vtkSmartPointer<vtkImageViewer2> imageViewer = vtkSmartPointer<vtkImageViewer2>::New();
		imageViewer->SetInputConnection(scale->GetOutputPort());
		this->qvtkWidget_4->GetRenderWindow()->SetInteractor(m_pInteractor);
		imageViewer->UpdateDisplayExtent();
		imageViewer->SetRenderWindow(this->qvtkWidget_4->GetRenderWindow());
		imageViewer->SetRenderer(ren);
		imageViewer->SetSize(758, 732);
		imageViewer->SetSliceOrientationToXY();
		imageViewer->GetImageActor()->InterpolateOff();
		ren->ResetCamera();
		ren->DrawOn();
		ren->InteractiveOn();
		this->qvtkWidget_4->GetRenderWindow()->Render();
	}
	void ProjectMainWindow::lable()
	{
		vtkTextActor *textActor = vtkTextActor::New();
		textActor->SetDisplayPosition(30, 750);
		textActor->SetInput(dicomImagereader->GetPatientName());
		textActor->GetTextProperty()->SetFontSize(18);
		textActor->GetTextProperty()->SetColor(1,1,1);
		ren->AddActor(textActor);
		vtkTextActor *textActor1 = vtkTextActor::New();
		textActor1->SetDisplayPosition(30, 720);
		textActor1->SetInput(dicomImagereader->GetStudyUID());
		textActor1->GetTextProperty()->SetFontSize(18);
		textActor1->GetTextProperty()->SetColor(1, 1, 1);
		ren->AddActor(textActor1);

	}
	void ProjectMainWindow::gray()
	{
		this->qvtkWidget_4->GetRenderWindow()->RemoveRenderer(ren);
		ren = vtkSmartPointer< vtkRenderer >::New();
		this->qvtkWidget_4->GetRenderWindow()->AddRenderer(ren);
		vtkSmartPointer<vtkImageLuminance> luminanceFilter =
			vtkSmartPointer<vtkImageLuminance>::New();
		luminanceFilter->SetInputConnection(rdImageCast->GetOutputPort());
		luminanceFilter->Update();
		//原始演员  
		vtkSmartPointer<vtkImageActor> origActor =
			vtkSmartPointer<vtkImageActor>::New();
		origActor->SetInputData(rdImageCast->GetOutput());
		//灰度演员  
		vtkSmartPointer<vtkImageActor> shiftscaleActor =
			vtkSmartPointer<vtkImageActor>::New();
		shiftscaleActor->SetInputData(luminanceFilter->GetOutput());
		double origView[4] = { 0.0, 0.0, 0.5, 1.0 };
		double shiftscaleView[4] = { 0.5, 0.0, 1.0, 1.0 };
		//原始演员化妆  
		vtkSmartPointer<vtkRenderer> origRender =
			vtkSmartPointer<vtkRenderer>::New();
		origRender->SetViewport(origView);
		origRender->AddActor(origActor);
		origRender->ResetCamera();
		//灰度演员化妆  
		vtkSmartPointer<vtkRenderer> shiftscaleRender =
			vtkSmartPointer<vtkRenderer>::New();
		shiftscaleRender->SetViewport(shiftscaleView);
		shiftscaleRender->AddActor(shiftscaleActor);
		shiftscaleRender->ResetCamera();

		vtkSmartPointer< vtkRenderWindowInteractor >  m_pInteractor = vtkSmartPointer< vtkRenderWindowInteractor >::New();

		
		this->qvtkWidget_4->GetRenderWindow()->SetInteractor(m_pInteractor);
		this->qvtkWidget_4->GetRenderWindow()->AddRenderer(origRender);
		this->qvtkWidget_4->GetRenderWindow()->AddRenderer(shiftscaleRender);
		ren->ResetCamera();
		ren->DrawOn();
		ren->InteractiveOn();
		this->qvtkWidget_4->GetRenderWindow()->Render();

		
	}

	void ProjectMainWindow::volumeph()
	{
		vtkSmartPointer<vtkTriangleFilter> triFilter =
			vtkSmartPointer<vtkTriangleFilter>::New();
		triFilter->SetInputConnection(skinStripper->GetOutputPort());
		triFilter->Update();

		vtkSmartPointer<vtkMassProperties> massProp =
			vtkSmartPointer<vtkMassProperties>::New();
		massProp->SetInputData(triFilter->GetOutput());
		double Volume = massProp->GetVolume();
		double SurfaceArea = massProp->GetSurfaceArea();
		float maxArea = massProp->GetMaxCellArea();
		float minArea = massProp->GetMinCellArea();
		std::cout << "the Volume   : " << Volume << std::endl;
		std::cout << "Surface Area : " << SurfaceArea << std::endl;
		std::cout << "MaxAreaofCell: " << maxArea << std::endl;
		std::cout << "MinAreaofCell: " << minArea << std::endl;

		QObject *mySender = sender();
		//转换为按钮类型
		QPushButton *p = (QPushButton *)mySender;


		if (NULL != p)
		{
			//获取按钮内容
			QString str = p->text();
			if (str == "area")
			{
				QString str1;
				str1.sprintf("%lf", Volume);
				this->label_16->setText(str1);
			}
			else if (str == "volume")
			{
				QString str2;
				str2.sprintf("%lf", SurfaceArea);
				this->label_15->setText(str2);
			}
		}

	}

	void ProjectMainWindow::three_get()
	{
		class vtkMyCallback :public vtkCommand
		{
		public:
			static vtkMyCallback *New()
			{
				return new vtkMyCallback;
			}
			virtual void Execute(vtkObject *caller, unsigned long, void*)
			{
				vtkTransform *t = vtkTransform::New();
				vtkBoxWidget *widget = reinterpret_cast<vtkBoxWidget*>(caller);
				widget->GetTransform(t);
				widget->GetProp3D()->SetUserTransform(t);
				t->Delete();
			}
		};
		this->qvtkWidget_4->GetRenderWindow()->RemoveRenderer(ren);
		ren = vtkSmartPointer< vtkRenderer >::New();
		this->qvtkWidget_4->GetRenderWindow()->AddRenderer(ren);
		
		
		vtkSmartPointer<vtkVolumeRayCastCompositeFunction>compositeRaycastFunction = vtkSmartPointer<vtkVolumeRayCastCompositeFunction>::New();

		volumeMapper = vtkSmartPointer<vtkVolumeRayCastMapper>::New();
		volumeMapper->SetVolumeRayCastFunction(compositeRaycastFunction);//载入体绘制方法
		volumeMapper->SetInputConnection(readerImageCast->GetOutputPort());
		volumeMapper->SetCropping(1);//开启Cropping功能
		QString Xmin=this->lineEdit->text();
		QString Xmax = this->lineEdit_2->text();
		QString Ymin = this->lineEdit_3->text();
		QString Ymax = this->lineEdit_4->text();
		QString Zmin = this->lineEdit_5->text();
		QString Zmax = this->lineEdit_6->text();
		double xmin, xmax, ymin, ymax, zmin, zmax;
		xmin = Xmin.toDouble();
		xmax = Xmax.toDouble();
		ymin = Ymin.toDouble();
		ymax = Ymax.toDouble();
		zmin = Zmin.toDouble();
		zmax = Zmax.toDouble();
		volumeMapper->SetCroppingRegionPlanes(xmin, xmax, ymin, ymax, zmin, zmax);
		volumeMapper->SetCroppingRegionFlags(0x0002000);
		vtkSmartPointer<vtkVolume>volume = vtkSmartPointer<vtkVolume>::New();
		volume->SetMapper(volumeMapper);
		volume->SetProperty(volumeProperty);//设置体属性

		vtkRenderWindowInteractor *iren = this->qvtkWidget_4->GetInteractor();
		ren->AddVolume(volume);
		vtkBoxWidget *boxWidget = vtkBoxWidget::New();
		boxWidget->SetInteractor(iren);
		boxWidget->SetPlaceFactor(1.25);
		boxWidget->SetProp3D(volume);
		boxWidget->PlaceWidget();
		vtkMyCallback *callback = vtkMyCallback::New();
		boxWidget->AddObserver(vtkCommand::InteractionEvent, callback);
		boxWidget->On();
		this->qvtkWidget_4->GetRenderWindow()->AddRenderer(ren);
		ren->InteractiveOn();
		this->qvtkWidget_4->GetRenderWindow()->Render();
	}

	void ProjectMainWindow::updateCoords(vtkObject* obj)
	{
	// 获取交互器
	vtkRenderWindowInteractor* iren = vtkRenderWindowInteractor::SafeDownCast(obj);

	// 获取鼠标的当前位置
	int event_pos[2];
	iren->GetEventPosition(event_pos);

	QString str1,str2;
	if (event_pos[0] && event_pos[1])
	{
		str1.sprintf("x=%d", event_pos[0]);
		str2.sprintf("y=%d", event_pos[1]);
		this->label_7->setText(str1);
		this->label_8->setText(str2);
	}
	else
	{
		this->label_7->setText(" ");
		this->label_8->setText(" ");
	}
	//printf("x=%d : y=%d", event_pos[0], event_pos[1]);
	//Ui_MainWindow *Um=new Ui_MainWindow();
	//Um->statusBar->showMessage(str);

	}
	
