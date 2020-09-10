#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTreeWidgetItem>
#include <QDebug>
#include <QTime>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/ply_io.h>

#include <pcl/common/common_headers.h>
#include <pcl/common/common.h>
#include <pcl/common/io.h>
#include <pcl/common/transforms.h>

#include <pcl/console/parse.h>
#include <pcl/correspondence.h>

#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/features/moment_of_inertia_estimation.h>
#include <vtkRenderWindow.h>
#include <vtkRendererCollection.h>
#include <vtkCamera.h>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>

typedef pcl::PointXYZ PointTypeXYZ;
typedef pcl::PointXYZRGB PointTypeXYZRGB;
typedef pcl::PointCloud<PointTypeXYZRGB> PointCloudXYZRGB;
typedef pcl::PointCloud<pcl::PointXYZ> PointCloudXYZ;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_input;
    PointCloudXYZRGB::Ptr pointcloud;
    QTime time;
    int timerId;
    double r,g,b;
    cv::Mat shownimage;


    QString currentlyOpenedDir;
    int currentSelectingImageIndex;


    void timerEvent(QTimerEvent *event);
    void mouse_callback_viewer_input( const pcl::visualization::MouseEvent& event, void* );
    void loadPLY(QString filename, PointCloudXYZRGB::Ptr cloud);
    void PrintPoints(PointCloudXYZRGB::Ptr cloud);
    void ListPlyInFolder();

private slots:
    void Button_openfolder_clicked();
    void Button_printpoint_clicked();
    void Button_histogram_clicked();
    void Button_saveimg_clicked();

    void Button_obb_clicked();
    void Button_aabb_clicked();
    void SelectPlyFile(QTreeWidgetItem *item, int col);

};

#endif // MAINWINDOW_H
