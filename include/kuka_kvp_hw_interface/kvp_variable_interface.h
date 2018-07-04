/**
Copyright 2018 Mathias Hauan Arbo

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the
License. You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific
language governing permissions and limitations under the License.
*/

/* Author: Mathias Hauan Arbo
   Desc: Read and write from the global variables on the KRC using
   KUKAVARPROXY (KVP). Currently only supports Booleans, but can be
   expanded.
*/

#ifndef KVP_VARIABLE_INTERFACE_H
#define KVP_VARIABLE_INTERFACE_H

// C++
#include <string>
#include <vector>

// ROS
#include <std_msgs/String.h>
#include <ros/ros.h>

#include <industrial_msgs/TriState.h>
#include <industrial_msgs/ServiceReturnCode.h>
#include <kuka_kvp_hw_interface/setBool.h>
#include <kuka_kvp_hw_interface/getBool.h>

// KVP Communication
#include <BoostClientCross.h>

namespace kuka_kvp_hw_interface {
  /**
   * @brief Get or set variables on the KRC using KUKAVARPROXY
   */
  class KVPVariableInterface {
    protected:
    ros::NodeHandle nh_;

    // Variables relating to KVP configuration
    std::string ip_;

    /**
     * @brief Private method for sending boolean variable to robot
     * 
     * @param name, value
     *
     * @return True on success 
     */
    bool write(const std::string& name, bool value);
  public:
    KVPVariableInterface(ros::NodeHandle& nh);

    /** \brief Get state of boolean in KRC
     */
    bool getBool(kuka_kvp_hw_interface::getBool::Request& req,
		 kuka_kvp_hw_interface::getBool::Response& res);

    /** \brief Set state of boolean in KRC
     */
    bool setBool(kuka_kvp_hw_interface::setBool::Request& req,
		 kuka_kvp_hw_interface::setBool::Response& res);
  };
}