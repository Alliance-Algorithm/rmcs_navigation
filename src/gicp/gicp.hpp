#pragma once

#include <Eigen/Eigen>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

class GICP final {
public:
    GICP();
    ~GICP();
    GICP(const GICP&) = delete;
    GICP& operator=(const GICP&) = delete;

    using PointT = pcl::PointXYZ;
    using PointCloudT = pcl::PointCloud<PointT>;

    void register_map(const std::shared_ptr<pcl::PointCloud<PointT>>& map);
    void register_scan(const std::shared_ptr<pcl::PointCloud<PointT>>& scan);

    void full_match(const std::shared_ptr<pcl::PointCloud<PointT>>& align);
    void single_match(const std::shared_ptr<pcl::PointCloud<PointT>>& align);

    double fitness_score();
    Eigen::Affine3d transformation();

private:
    class Impl;
    Impl* impl_;
};
