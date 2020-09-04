#include "mainwindow.h"
#include "build/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->openfolder_pushButton, SIGNAL(clicked()), this, SLOT(Button_openfolder_clicked()));
    connect(ui->printpoint_pushButton, SIGNAL(clicked()), this, SLOT(Button_printpoint_clicked()));
    connect(ui->obb_pushButton, SIGNAL(clicked()), this, SLOT(Button_obb_clicked()));
    connect(ui->aabb_pushButton, SIGNAL(clicked()), this, SLOT(Button_aabb_clicked()));
    connect(ui->files_treeWidget, SIGNAL(itemClicked(QTreeWidgetItem *, int)), this, SLOT(SelectPlyFile(QTreeWidgetItem *, int)));

    currentlyOpenedDir = QString("%1home%1nattaon%1ply").arg(QDir::separator());
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
    viewer_input->getRenderWindow()->GetRenderers()->GetFirstRenderer()->GetActiveCamera()->SetParallelProjection(1);
    //viewer_input->setRepresentationToSurfaceForAllActors();

    timerId = startTimer(100); //call timerEvent every 100 msec
    time.start();

    viewer_input->registerMouseCallback( &MainWindow::mouse_callback_viewer_input, *this );
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
    Eigen::Vector3f position(position_OBB.x, position_OBB.y, position_OBB.z);
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

    getActiveViewer(viewer_selecting)->spinOnce();

}
void MainWindow::Button_aabb_clicked()
{


}
