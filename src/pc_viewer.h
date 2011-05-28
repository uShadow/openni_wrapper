/*
 * pc_viewer.h
 *
 *  Created on: May 26, 2011
 *      Author: yingyin
 */

#ifndef PC_VIEWER_H_
#define PC_VIEWER_H_

#include <string>

#include <XnCppWrapper.h>
#include <pcl/visualization/cloud_viewer.h>

class HandProcessor;

class PCViewer {
public:
  PCViewer(HandProcessor* hand_processor);
  void run();
private:
  pcl::visualization::CloudViewer viewer_;
  XnUInt32 depth_xres_, depth_yres_;
  float bad_point_;
  float z_scale_, center_x_, center_y_;
  HandProcessor* hand_processor_;

  void display_cb_(pcl::visualization::PCLVisualizer& viewer);
  pcl::PointCloud<pcl::PointXYZ>::Ptr convertToXYZPointCloud (
      const xn::DepthMetaData& depth_md);
};

#endif /* PC_VIEWER_H_ */
