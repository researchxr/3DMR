/**********************************************************************

文件名: main.cpp
Copyright (c) 阿Bin先生. All rights reserved.
更多信息请访问: http://blog.csdn.net/webzhuce

**********************************************************************/

#include "ProjectMainWindow.h"
#include <QTextCodec>

int main( int argc, char **argv ) 
{
	QApplication *app = new QApplication(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));

	ProjectMainWindow *window = new ProjectMainWindow();
	window->show();
	return app->exec();
};

