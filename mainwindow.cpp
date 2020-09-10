#include "mainwindow.h"
#include "build/ui_mainwindow.h"

#include "JetColormap.cpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->openfolder_pushButton, SIGNAL(clicked()), this, SLOT(Button_openfolder_clicked()));
    connect(ui->printpoint_pushButton, SIGNAL(clicked()), this, SLOT(Button_printpoint_clicked()));
    connect(ui->histogram_pushButton, SIGNAL(clicked()), this, SLOT(Button_histogram_clicked()));
    connect(ui->save_histimg_pushButton, SIGNAL(clicked()), this, SLOT(Button_saveimg_clicked()));
    connect(ui->obb_pushButton, SIGNAL(clicked()), this, SLOT(Button_obb_clicked()));
    connect(ui->aabb_pushButton, SIGNAL(clicked()), this, SLOT(Button_aabb_clicked()));
    connect(ui->files_treeWidget, SIGNAL(itemClicked(QTreeWidgetItem *, int)), this, SLOT(SelectPlyFile(QTreeWidgetItem *, int)));


    //currentlyOpenedDir ="/home/okuboali/nattaon_ws/_0room_dataset/nattaon_edited_sceneNN/rotated";
    currentlyOpenedDir = QString("%1home%1nattaon%1ply%1rotated").arg(QDir::separator());
    ui->foldername_lineEdit->setText(currentlyOpenedDir);
    currentSelectingImageIndex=-1;

    //pointcloud
    pointcloud.reset(new PointCloudXYZRGB);

    //pcl viewer
    viewer_input.reset(new pcl::visualization::PCLVisualizer("pointcloud input"));
    viewer_input->setPosition(50,0);//window position
    viewer_input->setBackgroundColor(0, 0, 0);
    viewer_input->initCameraParameters();
    viewer_input->addCoordinateSystem();
    viewer_input->getRenderWindow()->GetRenderers()->GetFirstRenderer()->GetActiveCamera()->SetParallelProjection(0);
    //0=perspective (wider view), 1=orthogonal with clippping (narrow view..)

    //viewer_input->setRepresentationToSurfaceForAllActors();

    timerId = startTimer(100); //call timerEvent every 100 msec
    time.start();

    //viewer_input->registerMouseCallback( &MainWindow::mouse_callback_viewer_input, *this );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    viewer_input->spinOnce(100);
}
void MainWindow::mouse_callback_viewer_input( const pcl::visualization::MouseEvent& event, void* )
{
    if( event.getType() == pcl::visualization::MouseEvent::MouseButtonPress && event.getButton() == pcl::visualization::MouseEvent::LeftButton ){
        std::cout << "viewer 0 Mouse : " << event.getX() << ", " << event.getY() << std::endl;
        //viewer_selecting = 0;
    }
}


void MainWindow::Button_openfolder_clicked()
{
    ListPlyInFolder();
    currentSelectingImageIndex=-1;
}

void MainWindow::ListPlyInFolder()
{

    currentlyOpenedDir=ui->foldername_lineEdit->text();
    qDebug() << " tcurrentlyOpenedDir =  " << currentlyOpenedDir;
    QDir directory(currentlyOpenedDir);

    QStringList nameFilters;
    nameFilters << "*.ply" << "*.pcd";

    QStringList images = directory.entryList(nameFilters, QDir::Files);

    qDebug() << " total img in folder =  " << images.size();
    if (images.size() <= 0)
        return;

    ui->files_treeWidget->clear();
    for (int i = 0; i < images.size(); i++)
    {
        QTreeWidgetItem *currentFile = new QTreeWidgetItem(ui->files_treeWidget);
        currentFile->setText(0, images[i]);
    }

    //currentSelectingImageIndex=-1;
    //Button_nextimg_clicked();

}

void MainWindow::SelectPlyFile(QTreeWidgetItem *item, int col)
{
    if(currentSelectingImageIndex == ui->files_treeWidget->currentIndex().row()) //select the current one (same one)
    {
        return;
    }
    currentSelectingImageIndex = ui->files_treeWidget->currentIndex().row(); // current index
    QString filename = currentlyOpenedDir + QDir::separator() + item->text(0);


    loadPLY(filename, pointcloud); // load to "pointcloud"
    viewer_input->removeAllPointClouds();
    viewer_input->addPointCloud(pointcloud, "cloud_filtered 0.01");
}
void MainWindow::loadPLY(QString filename, PointCloudXYZRGB::Ptr cloud)
{
    if (filename.isEmpty ())
      return;

    //cloud.reset(new PointCloudXYZRGB); //should not be resetted, otherwise nothing be shown.
    int return_status = pcl::io::loadPLYFile (filename.toStdString (), *cloud);
    if (return_status != 0)
      {
        PCL_ERROR("Error reading point cloud %s\n", filename.toStdString ().c_str ());
        return;
      }
    //ui->label_w->setText(QString::number(cloud->width));
    //ui->label_h->setText(QString::number(cloud->height));
    qDebug() << "load " << filename;
    qDebug() << "cloud size = " <<cloud->width <<"*" <<cloud->height;

}
void MainWindow::Button_printpoint_clicked()
{
    PrintPoints(pointcloud);
}
void MainWindow::PrintPoints(PointCloudXYZRGB::Ptr cloud)
{
    //for (size_t i = 0; i < cloud->points.size (); ++i)
    //  std::cerr << "    " << cloud->points[i].x << " " << cloud->points[i].y << " " << cloud->points[i].z << std::endl;

}

void MainWindow::Button_obb_clicked()
{
 /*  Eigen::Vector3f position(position_OBB.x, position_OBB.y, position_OBB.z);
    Eigen::Quaternionf quat(rotational_matrix_OBB);

    cout << "ButtonBoundingBoxPressed "<< position << endl;

    double bb_xsize = max_point_OBB.x - min_point_OBB.x;
    double bb_ysize = max_point_OBB.y - min_point_OBB.y;
    double bb_zsize = max_point_OBB.z - min_point_OBB.z;
    ui->label_bb_xsize->setText(QString::number(bb_xsize));
    ui->label_bb_ysize->setText(QString::number(bb_ysize));
    ui->label_bb_zsize->setText(QString::number(bb_zsize));

    getActiveViewer(viewer_selecting)->removeShape("bounding box");
    getActiveViewer(viewer_selecting)->addCube(position, quat,
        max_point_OBB.x - min_point_OBB.x,
        max_point_OBB.y - min_point_OBB.y,
        max_point_OBB.z - min_point_OBB.z, "bounding box");
    //getActiveViewer(viewer_selecting)->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR, 1.0, 1.0, 0.0, "bounding box"); //cannotset on polygonmesh
    getActiveViewer(viewer_selecting)->setRepresentationToWireframeForAllActors(); // apply wireframe for all geometry
    //Viewer.setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_REPRESENTATION, pcl::visualization::PCL_VISUALIZER_REPRESENTATION_WIREFRAME, "AABB");

    getActiveViewer(viewer_selecting)->spinOnce();*/

}
void MainWindow::Button_aabb_clicked()
{


}

void MainWindow::Button_histogram_clicked()
{
    if(pointcloud->width ==0)
    {
        qDebug() << "no pointcloud load";
    }

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloudxyz (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_norm (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_scale (new pcl::PointCloud<pcl::PointXYZ>);

    pcl::copyPointCloud(*pointcloud, *cloudxyz);

    pcl::PointXYZ minpoint, maxpoint, boundingsize;
    pcl::getMinMax3D(*cloudxyz, minpoint, maxpoint);

    std::cout << "minpoint "
              << minpoint << std::endl;

    std::cout << "maxpoint "
              << maxpoint << std::endl;

    boundingsize.x = maxpoint.x - minpoint.x;
    boundingsize.y = maxpoint.y - minpoint.y;
    boundingsize.z = maxpoint.z - minpoint.z;

    std::cout << "boundingsize "
              << boundingsize << std::endl;

    int img_width = (int)round(boundingsize.x *100);
    int img_height = (int)round(boundingsize.z *100);

    std::cout << "Image size "
              << img_width << "*" << img_height << std::endl;

    pcl::copyPointCloud(*cloudxyz, *cloud_norm);
    for (size_t i = 0; i < cloud_norm->points.size (); ++i)
    {
      cloud_norm->points[i].x = (cloud_norm->points[i].x - minpoint.x )/ boundingsize.x;
      cloud_norm->points[i].y = (cloud_norm->points[i].y - minpoint.y )/ boundingsize.y;
      cloud_norm->points[i].z = (cloud_norm->points[i].z - minpoint.z )/ boundingsize.z;

    }

    pcl::copyPointCloud(*cloud_norm, *cloud_scale);
    for (size_t i = 0; i < cloud_scale->points.size (); ++i)
    {
      cloud_scale->points[i].x = round(cloud_scale->points[i].x * img_width);
      cloud_scale->points[i].y = round(cloud_scale->points[i].y * 255); // hist_img using CV_8UC1 which range (0,255)
      cloud_scale->points[i].z = round(cloud_scale->points[i].z * img_height);

    }

    cv::Mat histimg(img_width, img_height, CV_8UC1, cv::Scalar(0));
    cv::Mat histimg_color(img_width, img_height, CV_8UC3, cv::Scalar(0,0,0));

    std::cout << "histimg(0, 0) = " << (int)histimg.at<uchar>(0, 0)<< std::endl;
    std::cout <<  img_width << "," << img_height << " = " << (int)histimg.at<uchar>(img_width, img_height)<< std::endl;

    std::cout <<  "histimg.rows = " << histimg.rows << std::endl;
    std::cout <<  "histimg.cols = " << histimg.cols << std::endl;

    int max_density=0;

    int hist_x, hist_y, hist_val;
    int histogram_arr[img_width+1][img_height+1]; //histogram_arr[0][0] will not be used
    //initialize histogram_arr
    for(int i= 0; i< img_width+1; i++)
      for(int j= 0; j< img_height+1; j++)
      {
        histogram_arr[i][j]=0;
      }

    for (size_t i = 0; i < cloud_scale->points.size () ; ++i) //
    {
      hist_x = (int)cloud_scale->points[i].x;
      hist_y = (int)cloud_scale->points[i].z;

      if(hist_x == 0 || hist_y==0 || hist_x == img_width || hist_y==img_height)
          std::cout <<hist_x <<"," << hist_y<<  std::endl;

      hist_val = (int)cloud_scale->points[i].y; //don't care the value of the current pixel
      histimg.at<uchar>(hist_x, hist_y)++; // but count the number of points fall into the current pixel
      //histimg.at<uchar> would be max at 255 ...

      histogram_arr[hist_x][hist_y]++;

      if ( histogram_arr[hist_x][hist_y] > max_density)
      {
        max_density = histogram_arr[hist_x][hist_y];
        //std::cout <<hist_x <<"," << hist_y<< ": max_density=" << max_density << std::endl;
      }
    }
    std::cout << "max_density=" << (int)max_density << std::endl;

    JetColormap color;
    std::cout << "color[0]=" << color.colormap[0][0] << std::endl;

    int c_index = 0;


    for(int i= 0; i< histimg.rows; i++)
      for(int j= 0; j< histimg.cols; j++)
      {
        //c_index=(int)histimg.at<uchar>(i, j);
          c_index = (int)(255*histogram_arr[i][j]/max_density);

        //std::cout<< i <<"," << j << " : c_index=" << c_index << std::endl;
        histimg_color.at<cv::Vec3b>(i, j)[0]= color.colormap[c_index][0]*255;
        histimg_color.at<cv::Vec3b>(i, j)[1]= color.colormap[c_index][1]*255;
        histimg_color.at<cv::Vec3b>(i, j)[2]= color.colormap[c_index][2]*255;
      }
    cv::cvtColor(histimg_color, histimg_color, cv::COLOR_BGR2RGB);

    cv::namedWindow( "Histogram image", cv::WINDOW_AUTOSIZE );// Create a window for display.
    cv::imshow( "Histogram image", histimg_color );

    shownimage = histimg_color.clone();


}
void MainWindow::Button_saveimg_clicked()
{
    QTreeWidgetItem *item = ui->files_treeWidget->topLevelItem(currentSelectingImageIndex);
    //ui->prefiximg_lineEdit->text();
    QString filename = ui->prefiximg_lineEdit->text() + item->text(0).section('.',0,0) + ".jpg";
    std::cout << "filename " << filename.toStdString() << std::endl;


    cv::imwrite( filename.toStdString(), shownimage );
    cv::destroyWindow("Histogram image");

}
